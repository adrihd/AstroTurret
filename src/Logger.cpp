#include "Logger.h"

static void SetupLogger() {
    Logger.registerSerial(LOGGER_SERVICE_ID, ELOG_LEVEL_DEBUG, LOGGER_SERVICE_NAME); // We want messages with DEBUG level and lower
}