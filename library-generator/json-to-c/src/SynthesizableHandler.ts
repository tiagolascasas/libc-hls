import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class SynthesizableHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("synthesizable", libraryPrefix);
    }

    protected buildFunctionImpl(signature: Record<string, any>, mapping: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        const args = newFun.params.map(param => param.varref());
        const call = ClavaJoinPoints.callFromName(signature["name"], newFun.returnType, ...args);
        const retExpr = ClavaJoinPoints.returnStmt(call);

        const scope = ClavaJoinPoints.scope(retExpr);
        newFun.setBody(scope);
        return newFun;
    }
}
