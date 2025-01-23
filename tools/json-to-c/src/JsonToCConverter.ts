import Clava from "@specs-feup/clava/api/clava/Clava.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import { SynthesizableHandler } from "./SignatureTypeHandlers.js";

export class JsonToCConverter {
    private prefix: string;

    constructor(prefix: string = '') {
        this.prefix = prefix;
        Clava.pushAst(ClavaJoinPoints.program());
    }

    public convert(json: Record<string, any>): boolean {
        const synthHandler = new SynthesizableHandler();

        for (const [key, value] of Object.entries(json)) {
            const type = value["type"];
            if (type == "passthrough" || type == "host") {
                console.log(`Function ${key} is of type ${type}, skipping`);
            }
            if (type == "synthesizable") {
                synthHandler.handle(value);
            }
        }
        Clava.writeCode("output");
        return true;
    }
}
