export abstract class Logging {  

    private nextLogger: Logging | null = null;

    constructor(logger: Logging | null) {
        if (logger != null) this.nextLogger = logger;
    }

    public log(logLevel: string, message: string) { 
        if (this.nextLogger != null) this.nextLogger.log(logLevel, message);
    }
}
