import Clava from "@specs-feup/clava/api/clava/Clava.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import { ReimplementableHandler, SynthesizableHandler } from "./SignatureTypeHandlers.js";
import Io from "@specs-feup/lara/api/lara/Io.js";

export class JsonToCConverter {
    constructor() {
        Clava.pushAst(ClavaJoinPoints.program());
    }

    public convert(json: Record<string, any>, libraryPrefix: string): boolean {
        const synthHandler = new SynthesizableHandler(libraryPrefix);
        const reimpHandler = new ReimplementableHandler(libraryPrefix);

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
        }
        Io.deleteFolderContents("output");
        Clava.writeCode("output");
        return true;
    }
}
