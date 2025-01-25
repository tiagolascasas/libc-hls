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
            ClavaJoinPoints.param("info", ClavaJoinPoints.type("hls_async_info*"))
        ];
        for (const param of parameters) {
            newParams.push(ClavaJoinPoints.param(param["name"], ClavaJoinPoints.type(param["type"])));
        }

        const newFun = ClavaJoinPoints.functionDecl(newName, ClavaJoinPoints.type("bool"), ...newParams);
        return newFun;
    }

    protected buildFunctionImpl(signature: Record<string, any>, mapping: Record<string, any>, newSig: FunctionJp): FunctionJp {
        const newFun = newSig.copy() as FunctionJp;



        return newFun;
    }
}