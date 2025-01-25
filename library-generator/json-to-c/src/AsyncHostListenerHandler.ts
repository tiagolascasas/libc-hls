import { Decl, FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class AsyncHostListenerHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async_host_listener", libraryPrefix);
    }

    protected applyHeaderPrologue(): void {
        this.header.addInclude(`${this.libName}_types.h`, false);
        return;
    }

    protected buildSignature(original: Record<string, any>, mapping: Record<string, any>): FunctionJp {
        const name = mapping["name"] as string;
        const newName = `${name}_listen`;

        const mapParams = mapping["parameters"] as [];
        const oriParams = original["parameters"] as [];

        const sliceN = oriParams.length - mapParams.length;
        const parameters = oriParams.slice(0, sliceN);

        const newParams: Decl[] = [
            ClavaJoinPoints.param("call", ClavaJoinPoints.type("hls_async_call*"))
        ];
        for (const param of parameters) {
            newParams.push(ClavaJoinPoints.param(param["name"], ClavaJoinPoints.type(param["type"])));
        }

        const newFun = ClavaJoinPoints.functionDecl(newName, ClavaJoinPoints.type("bool"), ...newParams);
        return newFun;
    }

    protected buildFunctionImpl(signature: Record<string, any>, mapping: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        const cond1 = "call->host_idx >= call->kernel_info->idx";
        const ret1 = "return !call->kernel_info->is_closed;";
        const cond1Expr = ClavaJoinPoints.exprLiteral(cond1);
        const ret1Stmt = ClavaJoinPoints.stmtLiteral(ret1);
        const if1 = ClavaJoinPoints.ifStmt(cond1Expr, ret1Stmt);

        const cond2 = "call->host_idx == -1";
        const assign1 = "call->host_idx = 0;";
        const cond2Expr = ClavaJoinPoints.exprLiteral(cond2);
        const assign1Stmt = ClavaJoinPoints.stmtLiteral(assign1);
        const if2 = ClavaJoinPoints.ifStmt(cond2Expr, assign1Stmt);

        const ptr = "int8_t *curr_ptr ;";
        const ptrStmt = ClavaJoinPoints.stmtLiteral(ptr);

        const stmts = [if1, if2, ptrStmt];
        const argNames = [];
        for (const param of newSig.params) {
            if (param.name !== "call") {
                argNames.push(param.name);
            }
        }

        for (const param of mapping.parameters) {
            const argName = param.name;
            const argType = param.type;
            argNames.push(argName);

            const ptrInc = `int8_t *curr_ptr = call->buffer + sizeof(${argType});`;
            const ptrIncStmt = ClavaJoinPoints.stmtLiteral(ptrInc);
            stmts.push(ptrIncStmt);

            const arg = `${argType} ${argName} = *((${argType} *)curr_ptr);`;
            const argStmt = ClavaJoinPoints.stmtLiteral(arg);
            stmts.push(argStmt);

            const increment = `call->host_idx += sizeof(${argType});`;
            const incrementStmt = ClavaJoinPoints.stmtLiteral(increment);
            stmts.push(incrementStmt);
        }

        const callName = signature["name"];
        const callArgs = argNames.join(", ");
        const call = `${callName}(${callArgs});`;
        const callStmt = ClavaJoinPoints.stmtLiteral(call);
        stmts.push(callStmt);

        const ret = "return true;";
        const retStmt = ClavaJoinPoints.stmtLiteral(ret);
        stmts.push(retStmt);

        const scope = ClavaJoinPoints.scope(...stmts);
        newFun.setBody(scope);

        return newFun;
    }
}