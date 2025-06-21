#ifndef LOGGER_H
#define LOGGER_H
#include <Arduino.h>
#include "astroturret_config.h"
#include <Elog.h>

#define LOGGER_SERVICE_ID   CFG_LOGGER_SERVICE_ID
#define LOGGER_SERVICE_NAME CFG_LOGGER_SERVICE_NAME

#if defined(MEOW)
#define lol 1
#else
#define lol 2
#endif

// See platformio.ini -DDEBUG_LOG build flag
#ifdef DEBUG_LOG
    #define LOGGER_DEFAULT_LOG_LEVEL    ELOG_LEVEL_DEBUG
#else
    #define LOGGER_DEFAULT_LOG_LEVEL    ELOG_LEVEL_NOTICE
#endif

static void SetupLogger();


#endif