import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Clava from "@specs-feup/clava/api/clava/Clava.js";
import { Decl, FileJp, FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";

export abstract class AHandler {
    protected header: FileJp;
    protected source: FileJp;
    protected name: string;
    protected libraryPrefix: string;

    constructor(name: string, libraryPrefix: string) {
        const fileName = libraryPrefix + name;

        this.header = ClavaJoinPoints.file(fileName + ".h", ".");
        this.source = ClavaJoinPoints.file(fileName + ".c", ".");
        this.name = name;
        this.libraryPrefix = libraryPrefix;

        Clava.addFile(this.header);
        Clava.addFile(this.source);

        this.source.addInclude(fileName + ".h", false);
        const defaultIncludes = [
            "features-time64.h",
            "nl_types.h",
            "regex.h",
            "setjmp.h",
            "signal.h",
            "stdarg.h",
            "stdbool.h",
            "stddef.h",
            "stdio.h",
            "stdlib.h",
            "sys/types.h",
            "time.h",
            "wchar.h",
            "wctype.h"
        ]
        for (const include of defaultIncludes) {
            this.header.addInclude(include, true);
        }
        this.applyHeaderPrologue();
    }

    public handle(signature: Record<string, any>): void {
        const mappings = signature["mappings"];
        for (const mapping of mappings) {
            const name = mapping["name"];
            const returnType = mapping["returnType"];
            const parameters = mapping["parameters"];

            const newSig = this.buildSignature(name, returnType, parameters);
            this.header.insertEnd(newSig);

            const newImpl = this.buildFunctionImpl(signature, newSig);
            this.source.insertEnd(newImpl);
        }
    }

    protected buildSignature(name: string, returnType: string, parameters: Record<string, string>[]): FunctionJp {
        const newParams: Decl[] = [];
        for (const param of parameters) {
            newParams.push(ClavaJoinPoints.param(param["name"], ClavaJoinPoints.type(param["type"])));
        }
        const newFun = ClavaJoinPoints.functionDecl(name, ClavaJoinPoints.type(returnType), ...newParams);
        return newFun;
    }

    protected applyHeaderPrologue(): void {
        return;
    }

    protected abstract buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp;
}