import { FunctionJp, Joinpoint, Statement } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Query from "@specs-feup/lara/api/weaver/Query.js";

export class ReimplementableHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("reimplemented", libraryPrefix);
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        const stmts: Joinpoint[] = [];
        const impl = this.findExitstingImpl(signature);

        if (impl.length > 0) {
            stmts.push(...impl);
        }
        else {
            const comment = ClavaJoinPoints.comment("TODO: Implement this function");
            stmts.push(comment);
        }

        const scope = ClavaJoinPoints.scope(...stmts);
        newFun.setBody(scope);
        return newFun;
    }

    private findExitstingImpl(signature: Record<string, any>): Joinpoint[] {
        const jps: Joinpoint[] = [];

        for (const fun of Query.search(FunctionJp, { name: signature.name })) {
            console.log(fun);
            if (!fun.isImplementation) {
                continue;
            }
            if (fun.params.length !== signature.parameters.length) {
                continue;
            }
            if (fun.returnType.code !== signature.returnType) {
                continue;
            }
            for (const child of fun.body.children) {
                const stmt = ClavaJoinPoints.stmtLiteral(child.code);
                jps.push(stmt);
            }
            return jps;
        }
        return jps;
    }
}