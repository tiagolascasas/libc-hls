import { Decl, FunctionJp, Statement } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class AsyncKernelHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async-kernel", libraryPrefix);
    }

    protected applyHeaderPrologue(): void {
        this.header.addInclude(`${this.libName}-types.h`, false);
        return;
    }

    protected buildSignature(name: string, returnType: string, parameters: Record<string, string>[]): FunctionJp {
        const newParams: Decl[] = [
            ClavaJoinPoints.param("buf", ClavaJoinPoints.type("char*")),
            ClavaJoinPoints.param("info", ClavaJoinPoints.type("async_kernel_info*")),
            ClavaJoinPoints.param("is_last", ClavaJoinPoints.type("bool"))
        ];

        for (const param of parameters) {
            newParams.push(ClavaJoinPoints.param(param["name"], ClavaJoinPoints.type(param["type"])));
        }

        const newFun = ClavaJoinPoints.functionDecl(name, ClavaJoinPoints.type(returnType), ...newParams);
        return newFun;
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;
        const info = newFun.params[1].name;
        const isLast = newFun.params[2].name;

        const ifCond = ClavaJoinPoints.exprLiteral(`${info}->idx == -1`);
        const ifBody = ClavaJoinPoints.stmtLiteral(`${info}->idx = 0;`);
        const ifStmt = ClavaJoinPoints.ifStmt(ifCond, ifBody);

        // push to buffer
        const pushStmts: Statement[] = [];
        for (let i = 3; i < newFun.params.length; i++) {
            const param = newFun.params[i];
            const paramName = param.name;
            const type = param.type.code;

            const memOp = `*((${type} *)(buf + info->idx)) = (${type})${paramName};`;
            const memStmt = ClavaJoinPoints.stmtLiteral(memOp);
            const increment = `info->idx += sizeof(${type});`;
            const incrementStmt = ClavaJoinPoints.stmtLiteral(increment);

            pushStmts.push(memStmt);
            pushStmts.push(incrementStmt);
        }

        const closeIfCond = ClavaJoinPoints.exprLiteral(isLast);
        const closeIfBody = ClavaJoinPoints.stmtLiteral(`${info}->is_closed = true;`);
        const closeIfStmt = ClavaJoinPoints.ifStmt(closeIfCond, closeIfBody);

        const bodyStmts = [
            ifStmt,
            ...pushStmts,
            closeIfStmt
        ];
        const body = ClavaJoinPoints.scope(...bodyStmts);
        newFun.setBody(body);
        return newFun;
    }
}