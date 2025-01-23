import { FileJp, FunctionJp, Include } from "@specs-feup/clava/api/Joinpoints.js";
import Query from "@specs-feup/lara/api/weaver/Query.js";
import Io from "@specs-feup/lara/api/lara/Io.js";

export class HeaderToJsonConverter {
    private prefix: string;

    constructor(prefix: string = '') {
        this.prefix = prefix;
    }

    public convertAll(): number {
        let n = 0;

        for (const include of Query.search(Include)) {
            if (!include.isAngled) {
                n = this.convert(include) ? n + 1 : n;
            }
        }
        return n;
    }

    convert(include: Include): boolean {
        console.log(`Converting ${include.name}`);

        const file = Query.search(FileJp, { name: include.name }).first();
        if (file === undefined) {
            console.error(`File ${include.name} not found`);
            return false;
        }
        const json: Record<string, any> = {};

        for (const fun of Query.searchFromInclusive(file, FunctionJp)) {
            const name = fun.name.replace(this.prefix, '');

            json[name] = {
                type: "passthrough",
                name: name,
                returnType: fun.returnType.code,
                parameters: fun.params.map(p => ({
                    name: p.name,
                    type: p.type.code
                })),
                mappings: [
                    {
                        name: name,
                        returnType: fun.returnType.code,
                        parameters: fun.params.map(p => ({
                            name: p.name,
                            type: p.type.code
                        })),
                    }
                ]
            };
        }
        this.saveJson(json, `output/${include.name.replace(".h", ".json")}`);

        return true;
    }

    private saveJson(json: Record<string, any>, filename: string): void {
        const jsonStr = JSON.stringify(json, null, 4);
        Io.writeFile(filename, jsonStr);
    }
}