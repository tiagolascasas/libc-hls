import Clava from "@specs-feup/clava/api/clava/Clava.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Io from "@specs-feup/lara/api/lara/Io.js";
import { SynthesizableHandler } from "./SynthesizableHandler.js";
import { ReimplementableHandler } from "./ReimplementableHandler.js";
import { AsyncKernelHandler } from "./AsyncKernelHandler.js";

export class JsonToCConverter {
    constructor() {
        Clava.pushAst(ClavaJoinPoints.program());
    }

    public convert(json: Record<string, any>, libraryPrefix: string, additionalHeaders: string[] = []): boolean {
        const synthHandler = new SynthesizableHandler(libraryPrefix);
        const reimpHandler = new ReimplementableHandler(libraryPrefix);
        const asyncKernelHandler = new AsyncKernelHandler(libraryPrefix);

        for (const [key, value] of Object.entries(json)) {
            const type = value["type"];
            if (type == "passthrough" || type == "host") {
                console.log(`Function ${key} is of type ${type}, skipping`);
            }
            if (type == "synthesizable") {
                synthHandler.handle(value);
            }
            if (type == "reimplementable") {
                reimpHandler.handle(value);
            }
            if (type == "async") {
                asyncKernelHandler.handle(value);
            }
        }

        for (const header of additionalHeaders) {
            const file = ClavaJoinPoints.file(header);
            file.setName(libraryPrefix + file.name);
            Clava.addFile(file);
        }

        Io.deleteFolderContents("output");
        Clava.writeCode("output");
        return true;
    }
}
