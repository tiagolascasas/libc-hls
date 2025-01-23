import { JsonToCConverter } from "./JsonToCConverter.js";
import Io from "@specs-feup/lara/api/lara/Io.js";

const json = Io.readJson("../intermediate-data/all_signatures.json");
const existingHeaders = ["../intermediate-data/types.h"];

const converter = new JsonToCConverter();
const success = converter.convert(json, "libc-hls", existingHeaders);
console.log(success ? "Conversion successful" : "Conversion failed");