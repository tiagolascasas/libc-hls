import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Clava from "@specs-feup/clava/api/clava/Clava.js";
import { FileJp } from "@specs-feup/clava/api/Joinpoints.js";

abstract class AHandler {
    protected header: FileJp;
    protected source: FileJp;
    protected name: string;
    protected prefix: string;

    constructor(name: string, prefix: string) {
        this.header = ClavaJoinPoints.file(name + ".h", ".");
        this.source = ClavaJoinPoints.file(name + ".c", ".");
        this.name = name;
        this.prefix = prefix;

        Clava.addFile(this.header);
        Clava.addFile(this.source);

        this.source.addInclude(name + ".h", false);
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
    }

    public handle(signature: Record<string, any>): void {

    }
}

export class PassthroughHandler extends AHandler {
    constructor(prefix: string) {
        super("passthrough", prefix);
    }

    public handle(signature: Record<string, any>): void {
        return;
    }
}