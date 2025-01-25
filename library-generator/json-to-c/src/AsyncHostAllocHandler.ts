import { Decl, FunctionJp, Joinpoint, Statement } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Query from "@specs-feup/lara/api/weaver/Query.js";

export class AsyncHostHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async_host", libraryPrefix);
    }

    protected applyHeaderPrologue(): void {
        this.header.addInclude(`${this.libName}_types.h`, false);
        return;
    }

    protected buildSignature(name: string, returnType: string, parameters: Record<string, string>[]): FunctionJp {
        const newParams: Decl[] = [];
        for (const param of parameters) {
            newParams.push(ClavaJoinPoints.param(param["name"], ClavaJoinPoints.type(param["type"])));
        }
        const newFun = ClavaJoinPoints.functionDecl(name, ClavaJoinPoints.type(returnType), ...newParams);
        return newFun;
    }


    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;


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