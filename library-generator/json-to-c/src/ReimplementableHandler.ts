import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Clava from "@specs-feup/clava/api/clava/Clava.js";

export class ReimplementableHandler extends AHandler {
    constructor(libraryPrefix: string, additionalSources: string[]) {
        super("reimplemented", libraryPrefix);

        for (const source of additionalSources) {
            const file = ClavaJoinPoints.file(source);
            Clava.addFile(file);
        }
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        const comment = ClavaJoinPoints.comment("TODO: Implement this function");

        const scope = ClavaJoinPoints.scope(comment);
        newFun.setBody(scope);
        return newFun;
    }
}