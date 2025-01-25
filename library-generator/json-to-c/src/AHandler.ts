import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Clava from "@specs-feup/clava/api/clava/Clava.js";
import { Decl, FileJp, FunctionJp } from "@specs-feup/clava/api/Joinpoints.js";

export abstract class AHandler {
    protected header: FileJp;
    protected source: FileJp;
    protected name: string;
    protected libName: string;
    protected fileName: string;

    constructor(name: string, libName: string) {
        this.fileName = `${libName}_${name}`;

        this.header = ClavaJoinPoints.file(this.fileName + ".h", ".");
        this.source = ClavaJoinPoints.file(this.fileName + ".c", ".");
        this.name = name;
        this.libName = libName;

        Clava.addFile(this.header);
        Clava.addFile(this.source);

        this.source.addInclude(this.fileName + ".h", false);
        const defaultIncludes = [
            "math.h",
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
            const newSig = this.buildSignature(signature, mapping);
            this.header.insertEnd(newSig);

            const newImpl = this.buildFunctionImpl(signature, newSig);
            this.source.insertEnd(newImpl);
        }
    }

    public getHeaderName(): string {
        return this.fileName + ".h";
    }

    protected buildSignature(original: Record<string, any>, mapping: Record<string, any>): FunctionJp {
        const name = mapping["name"] as string;
        const returnType = mapping["returnType"] as string;
        const parameters = mapping["parameters"] as [];
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

    public applyHeaderEpilogue(): void {
        return;
    }

    protected abstract buildFunctionImpl(signature: Record<string, any>, newSig: FunctionJp): FunctionJp;
}