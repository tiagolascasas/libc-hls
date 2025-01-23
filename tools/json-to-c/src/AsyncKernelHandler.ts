import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";

export class AsyncKernelHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async", libraryPrefix);
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        return newFun;
    }
}