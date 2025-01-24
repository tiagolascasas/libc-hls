import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";

export class ReimplementableHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("reimplemented", libraryPrefix);
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        const comment = ClavaJoinPoints.comment("TODO: Implement this function");

        const scope = ClavaJoinPoints.scope(comment);
        newFun.setBody(scope);
        return newFun;
    }
}