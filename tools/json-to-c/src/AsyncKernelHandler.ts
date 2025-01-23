import { FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";
import { AHandler } from "./AHandler.js";

export class AsyncKernelHandler extends AHandler {
    constructor(libraryPrefix: string) {
        super("async-kernel", libraryPrefix);
    }

    protected applyHeaderPrologue(): void {
        this.header.addInclude(this.libraryPrefix + "types.h", false);
        return;
    }

    protected buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;

        return newFun;
    }
}