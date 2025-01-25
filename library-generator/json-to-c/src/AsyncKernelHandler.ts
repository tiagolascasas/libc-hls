import { Decl, FunctionJp, Statement } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class AsyncKernelHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async_kernel", libraryPrefix);
    }

    protected applyHeaderPrologue(): void {
        this.header.addInclude(`${this.libName}_types.h`, false);
        return;
    }

    protected buildSignature(original: Record<string, any>, mapping: Record<string, any>): FunctionJp {
        const name = mapping["name"] as string;
        const returnType = mapping["returnType"] as string;
        const parameters = mapping["parameters"] as [];

        const newParams: Decl[] = [
            ClavaJoinPoints.param("buf", ClavaJoinPoints.type("char*")),
            ClavaJoinPoints.param("info", ClavaJoinPoints.type("hls_async_info*")),
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

    public applyHeaderEpilogue(): void {
        const closeFun = ClavaJoinPoints.functionDecl("hls_close_async", ClavaJoinPoints.type("void"), ClavaJoinPoints.param("info", ClavaJoinPoints.type("hls_async_info*")));
        this.header.insertEnd(closeFun);

        const closeFunImpl = closeFun.copy() as FunctionJp;

        const closeStmt = ClavaJoinPoints.stmtLiteral("info->is_closed = true;");
        const closeBody = ClavaJoinPoints.scope(closeStmt);
        closeFunImpl.setBody(closeBody);

        this.source.insertEnd(closeFunImpl);
        return;
    }
}