import { Logging } from "./logging"

export class DebugLogging extends Logging { 
    constructor(nextLogger: Logging | null) {
        super(nextLogger);
    }
    
    log(logLevel: string, message: string) { 
        if (logLevel === 'debug') {
            console.debug(message);
        } else {
            super.log(logLevel, message);
        }
    }
}