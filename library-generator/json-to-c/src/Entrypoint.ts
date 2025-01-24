import { JsonToCConverter } from "./JsonToCConverter.js";
import Io from "@specs-feup/lara/api/lara/Io.js";

const json = Io.readJson("../intermediate-data/libc-annotated.json");
const existingHeaders = ["../intermediate-data/types.h"];
const existingSources = ["../intermediate-data/reimplementations.c"];
const outputDirs = ["./output", "../../libc-hls"];

const converter = new JsonToCConverter();
const success = converter.convert(json, "libc-hls", existingHeaders, existingSources, outputDirs);
console.log(success ? "Conversion successful" : "Conversion failed");