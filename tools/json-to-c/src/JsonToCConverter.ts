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

    public convert(json: Record<string, any>, libName: string, additionalHeaders: string[] = []): boolean {
        const synthHandler = new SynthesizableHandler(libName);
        const reimpHandler = new ReimplementableHandler(libName);
        const asyncKernelHandler = new AsyncKernelHandler(libName);

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

        const headerNames: string[] = [];
        for (const header of additionalHeaders) {
            const file = ClavaJoinPoints.file(header);
            const headerName = `${libName}-${file.name}`;
            file.setName(headerName);

            Clava.addFile(file);
            headerNames.push(headerName);
        }
        headerNames.push(synthHandler.getHeaderName());
        headerNames.push(reimpHandler.getHeaderName());
        headerNames.push(asyncKernelHandler.getHeaderName());
        this.createMasterHeader(headerNames, libName);

        Io.deleteFolderContents("output");
        Clava.writeCode("output");
        return true;
    }

    private createMasterHeader(headerNames: string[], libName: string): void {
        const masterHeader = ClavaJoinPoints.file(libName + ".h");
        for (const headerName of headerNames) {
            masterHeader.addInclude(headerName, false);
        }
        Clava.addFile(masterHeader);
    }
}
