import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class PassthroughHandler extends AHandler {
    constructor(libraryPrefix: string, headerName: string) {
        super(headerName, libraryPrefix);
    }

    protected buildSignature(original: Record<string, any>, mapping: Record<string, any>): FunctionJp {
        const name = mapping["name"] as string;
        const newName = "hls_" + name;
        mapping["name"] = newName;

        return super.buildSignature(original, mapping);
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
