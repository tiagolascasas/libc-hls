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
            const baseType = param["type"] as string;
            if (baseType.includes("[")) {
                const type = baseType.split("[")[0] + "*";
                const typeJp = ClavaJoinPoints.type(type);

                newParams.push(ClavaJoinPoints.param(param["name"], typeJp));
                newParams.push(ClavaJoinPoints.param(`${param["name"]}_size`, ClavaJoinPoints.type("size_t")));
            }
            else {
                const typeJp = ClavaJoinPoints.type(baseType);
                newParams.push(ClavaJoinPoints.param(param["name"], typeJp));
            }
        }

        const newFun = ClavaJoinPoints.functionDecl(name, ClavaJoinPoints.type(returnType), ...newParams);
        return newFun;
    }

    protected buildFunctionImpl(signature: Record<string, any>, mapping: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;
        const info = newFun.params[1].name;
        const isLast = newFun.params[2].name;

        const ifCond = ClavaJoinPoints.exprLiteral(`${info}->idx == -1`);
        const ifBody = ClavaJoinPoints.stmtLiteral(`${info}->idx = 0;`);
        const ifStmt = ClavaJoinPoints.ifStmt(ifCond, ifBody);

        const args = mapping.parameters.length > 0 ? mapping.parameters : [{ name: "true", type: "int8_t" }];
        const pushStmts: Statement[] = [];

        for (const arg of args) {
            const argName = arg.name;
            const argType = arg.type;

            if (argType.includes("[")) {
                const forLoop = `
int ${argName}_idx;
for (${argName}_idx = 0; ${argName}_idx < ${argName}_size; ${argName}_idx++) {
    *((${argType.split("[")[0]} *)(buf + info->idx)) = (${argType.split("[")[0]})${argName}[${argName}_idx];
    info->idx += sizeof(${argType.split("[")[0]});
}`;
                const forStmt = ClavaJoinPoints.stmtLiteral(forLoop);
                pushStmts.push(forStmt);
            }
            else {
                const memOp = `*((${argType} *)(buf + info->idx)) = (${argType})${argName};`;
                const memStmt = ClavaJoinPoints.stmtLiteral(memOp);
                const increment = `info->idx += sizeof(${argType});`;
                const incrementStmt = ClavaJoinPoints.stmtLiteral(increment);

                pushStmts.push(memStmt);
                pushStmts.push(incrementStmt);
            }
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