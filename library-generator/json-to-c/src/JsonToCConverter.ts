import Clava from "@specs-feup/clava/api/clava/Clava.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import Io from "@specs-feup/lara/api/lara/Io.js";
import Query from "@specs-feup/lara/api/weaver/Query.js";
import { SynthesizableHandler } from "./SynthesizableHandler.js";
import { ReimplementableHandler } from "./ReimplementableHandler.js";
import { AsyncKernelHandler } from "./AsyncKernelHandler.js";
import { FileJp } from "@specs-feup/clava/api/Joinpoints.js";

export class JsonToCConverter {
    constructor() {
        Clava.pushAst(ClavaJoinPoints.program());
    }

    public convert(json: Record<string, any>, libName: string, additionalHeaders: string[] = [], additionalSources: string[] = [], outputFolders: string[] = ["./output"]): boolean {
        for (const source of additionalSources) {
            const file = ClavaJoinPoints.file(source);
            Clava.addFile(file);
            Clava.rebuild();
        }

        const synthHandler = new SynthesizableHandler(libName);
        const reimpHandler = new ReimplementableHandler(libName);
        const asyncKernelHandler = new AsyncKernelHandler(libName);

        for (const [key, value] of Object.entries(json)) {
            const type = value["type"];
            if (type == "passthrough" || type == "host") {
                //console.log(`Function ${key} is of type ${type}, skipping`);
                continue;
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
            const oldHeader = ClavaJoinPoints.file(header);
            Clava.addFile(oldHeader);

            const headerName = `${libName}_${oldHeader.name}`;
            headerNames.push(headerName);

            const newHeader = ClavaJoinPoints.file(headerName, ".");
            this.copyHeader(oldHeader, newHeader);

            oldHeader.detach();
            Clava.addFile(newHeader);

        }
        headerNames.push(synthHandler.getHeaderName());
        headerNames.push(reimpHandler.getHeaderName());
        headerNames.push(asyncKernelHandler.getHeaderName());
        this.createMasterHeader(headerNames, libName);

        this.deleteAdditionalFiles(additionalSources);

        for (const outputFolder of outputFolders) {
            Io.deleteFolderContents(outputFolder);
            Clava.writeCode(outputFolder);
        }
        return true;
    }

    private copyHeader(oldHeader: FileJp, newHeader: FileJp): void {
        const blob = ClavaJoinPoints.stmtLiteral(oldHeader.code);
        newHeader.insertEnd(blob);
    }

    private deleteAdditionalFiles(additionalSources: string[]): void {
        const toDelete = [];
        for (const file of Query.search(FileJp)) {
            for (const source of additionalSources) {
                if (source.includes(file.name)) {
                    toDelete.push(file);
                }
            }
        }
        for (const file of toDelete) {
            file.detach();
        }
    }

    private createMasterHeader(headerNames: string[], libName: string): void {
        const masterHeader = ClavaJoinPoints.file(libName + ".h", ".");
        for (const headerName of headerNames) {
            masterHeader.addInclude(headerName, false);
        }
        Clava.addFile(masterHeader);
    }
}
