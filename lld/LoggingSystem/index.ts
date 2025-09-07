import { DebugLogging } from "./debugLogging";
import { ErrorLogging } from "./errorLogging";
import { InfoLogging } from "./infoLogging";

function mainFunction() {
    const logging = new DebugLogging(
        new InfoLogging(
            new ErrorLogging(null)
        )
    )

    logging.log('info', 'Info message');
    logging.log('debug', 'Debug message');
    logging.log('error', 'Error message');
}

mainFunction();