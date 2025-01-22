import { Include } from "@specs-feup/clava/api/Joinpoints.js";
import Query from "@specs-feup/lara/api/weaver/Query.js";

export class HeaderToJsonConverter {
    private prefix: string;

    constructor(prefix: string = '') {
        this.prefix = prefix;
    }

    public convertAll() {
        for (const include of Query.search(Include)) {
            console.log(include.code);
        }
    }

    // convert(include: Include): JSON {

    // }
}