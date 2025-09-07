import { Logging } from "./logging"

export class ErrorLogging extends Logging { 
    constructor(nextLogger: Logging | null) {
        super(nextLogger);
    }

    log(logLevel: string, message: string) { 
        if (logLevel === 'error') {
            console.error(message);
        } else {
            super.log(logLevel, message);
        }
    }
}