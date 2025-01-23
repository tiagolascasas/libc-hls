import Clava from "@specs-feup/clava/api/clava/Clava.js";
import ClavaJoinPoints from "@specs-feup/clava/api/clava/ClavaJoinPoints.js";
import { PassthroughHandler } from "./SignatureTypeHandlers.js";

export class JsonToCConverter {
    private prefix: string;

    constructor(prefix: string = '') {
        this.prefix = prefix;
        Clava.pushAst(ClavaJoinPoints.program());
    }

    public convert(json: Record<string, any>): boolean {
        const passthroughHandler = new PassthroughHandler();

        for (const [key, value] of Object.entries(json)) {
            const type = value["type"];
            if (type == "passthrough") {
                passthroughHandler.handle(value);
            }
        }
        Clava.writeCode("output");
        return true;
    }
}
