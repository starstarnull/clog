
#include "demo-1.h"


int demo_1() {

    CPRINTLN(C_BOLD C_YELLOW, "--- Levels (emoji mode) ---");
    PRINTLN("\n");
    LOGLN_TRACE("This is a trace log.");
    LOGLN_DEBUG("This is a debug log.");
    LOGLN_EXTRA("This is an extra log.");
    LOGLN_INFO("This is an info log.");
    LOGLN_HEADER("This is a header log.");
    LOGLN_SUCCESS("This is a success log.");
    LOGLN_MONEY("This is a money log.");
    LOGLN_INPUT("This is an input log.");
    LOGLN_WARNING("This is a warning log.");
    LOGLN_ERROR("This is an error log.");
    LOGLN_CRITICAL("This is a critical log.");
    LOGLN_FATAL("This is a fatal log.");
    PRINTLN("\n\n");

    CPRINTLN(C_BOLD C_YELLOW, "--- Makeshift demo logs (emoji mode) ---");
    PRINTLN("\n");
    LOGLN_TRACE("Enter demo.");
    LOGLN_HEADER("Starting server...");
    LOGLN_INFO("Creating socket...");
    LOGLN_SUCCESS("Socket created.");
    LOGLN_INFO("Binding and listening...");
    LOGLN_DEBUG("PORT: 3443");
    LOGLN_DEBUG("HOST: bobobaba");
    LOGFLN_INFO("Listening on port: %d", 3443);
    LOGLN_INFO("Waiting for connections...");
    LOGLN_EXTRA("Received connection from: 111.153.142.2 on port 56445.");
    LOGLN_INFO("Received request for 'index.html'.");
    LOGLN_DEBUG("Receiving 26 bytes...");
    LOGLN_EXTRA("Opening '/server/www/index.html'...");
    errno = ENOENT;
    LOG_PERROR_WARNING("`open` failed");
    LOGLN_ERROR("Sending 404...");
    LOGLN_DEBUG("Sending 404 bytes...");
    LOGLN_SUCCESS("Response sent.");
    LOGLN_EXTRA("Received connection from: 111.153.101.23 on port 55221.");
    LOGLN_DEBUG("Receiving 19 bytes...");
    LOGLN_INFO("Received request for 'file'.");
    LOGLN_EXTRA("Opening '/server/www/file'...");
    LOGLN_MONEY("Special file opened.");
    LOGLN_DEBUG("Sending 9999 bytes...");
    LOGLN_SUCCESS("Response sent.");
    LOGLN_WARNING("Signal received.");
    LOGLN_HEADER("Shutting down...");
    LOGLN_INFO("Closing database...");
    LOGLN_CRITICAL("Database failure.");
    LOGLN_INFO("Trying backup.");
    LOGLN_FATAL("There is a problem!");
    LOGLN_INFO("Trying backup.");
    LOGLN_FATAL("She can't take much more of this, Captain!");
    LOGLN_FATAL("Exiting...");
    PRINTLN("\n\n");

    return 0;
}
