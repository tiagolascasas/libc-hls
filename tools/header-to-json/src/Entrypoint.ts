import { HeaderToJsonConverter } from "./HeaderToJsonConverter.js";

const converter = new HeaderToJsonConverter("hls_");
converter.convertAll();