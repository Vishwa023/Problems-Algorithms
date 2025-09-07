import { Logging } from "./logging"

export class InfoLogging extends Logging { 
    constructor(nextLogger: Logging | null) {
        super(nextLogger);
    }

    log(logLevel: string, message: string) { 
        if (logLevel === 'info') {
            console.info(message);
        } else {
            super.log(logLevel, message);
        }
    }
}
