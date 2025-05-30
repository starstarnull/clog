
// Includes.

#include "clog-config.h"
#include "clog.h"

static void test_levels() {
    LOGLN_FATAL("FATAL test.");
    LOGLN_ERROR("ERROR test.");
    LOGLN_WARNING("WARNING test.");
    LOGLN_INFO("INFO test.");
    LOGLN_HEADER("HEADER test.");
    LOGLN_SUCCESS("SUCCESS test.");
    LOGLN_INPUT("INPUT test.");
    LOGLN_EXTRA("EXTRA test.");
    LOGLN_DEBUG("DEBUG test.");
    LOGLN_TRACE("TRACE test.");
}


