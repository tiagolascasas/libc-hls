import { JsonToCConverter } from "./JsonToCConverter.js";
import Io from "@specs-feup/lara/api/lara/Io.js";

const json = Io.readJson("../intermediate-data/all_signatures.json");

const converter = new JsonToCConverter();
const success = converter.convert(json, "libc-hls-");
console.log(success ? "Conversion successful" : "Conversion failed");