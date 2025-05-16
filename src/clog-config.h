
/**
 * Copyright (C) 2025 Dorian N. Nihil (starstarnull@starstarnull.net)
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * ====================
 * Clog C Header Config
 * ====================
 *
 * Version: 0.0.1-1 beta
 *
 * Provides macros for color console and file logging.
 *
 * Clog C Header is a C header library of functions that can be included in a C
 * project to provide colored printing and console and file logging macros.
 * These functions can be configured to allow versatility of compile-time
 * logging function inclusion.
 *
 * Logging
 * =======
 *
 * Logging is also provided and there are some configuration options. There are
 * three different main types of logging provided:
 *
 *      - The "clog" functions provide console logging to standard error.
 *
 *      - The "flog" functions provide file logging to the file initialized with
 *      the `CLOG_INIT` macro or defaults to the '<file.c>.log' where
 *      `<file.c>` is the name of the C file using the logger.
 *
 *      - The "log" functions provide console and file logging if it is enabled
 *      in the configuration.
 *
 * Logging Options
 * ---------------
 *
 * Log options include the following:
 *
 *      `LOG_CONSOLE_MODE` which may be colored or uncolored by setting it to
 *      one of two options:
 *
 *          - `LOG_CONSOLE_MODE_COLOR` (default) enables color console logging.
 *
 *          - `LOG_CONSOLE_NOCOLOR` disables color console logging.
 *
 *          ** Note **: File logging never has colored logs.
 *
 *      `LOG_MODE` which may be no logging, log to console only, log to file
 *      only, or log to console and file and may be set to one of the following
 *      options:
 *
 *          - `LOG_MODE_NONE` disables all logging.
 *
 *          - `LOG_MODE_CONSOLE` enables logging to the console only.
 *
 *          - `LOG_MODE_FILE` enables logging to a file only.
 *
 *          - `LOG_MODE_CONSOLE_AND_FILE` (default) enables logging to the
 *          console and a file.
 *
 *          ** Note **: All disabled logging calls are removed from the
 *          compilation (preprocessed out) through undefine or empty redefine
 *          macros. String declarations outside of logging calls are not
 *          guaranteed to be preprocessed out.
 *
 *      `LOG_LEVEL` is the level of logging that will occur. Options include:
 *
 *          - `LOG_LEVEL_NONE` disables all logging.
 *
 *          - `LOG_LEVEL_ERROR` enables fatal and error level logging.
 *
 *          - `LOG_LEVEL_WARNING` enables fatal, error, and warning logging.
 *
 *          - `LOG_LEVEL_INFO` enables info level logging in addition to fatal,
 *          error, and warning logs(`<log>_INFO`, `<log>_HEADER`, 
 *          `<log>_SUCCESS`, and `<log>_INPUT`).
 *
 *          - `LOG_LEVEL_EXTRA` enables logging of previous levels and the 
 *          extra level.
 *
 *          - `LOG_LEVEL_DEBUG` enables logging of previous levels and the 
 *          debug level.
 *
 *          - `LOG_LEVEL_ALL` enables all logging including trace level logs.
 *
 * Logging Headers
 * ---------------
 *
 * Logs include a header with an ISO 8601 UTC timestamp and a string "symbol" 
 * indicating the level of the log. Trace and debug logs also include the
 * filename the call was logged from, the function name it was called from, and
 * the line number the log call was made. For example:
 *
 *      `CLOGLN_INFO("This is an info message.");`
 *
 *          Output: "2025-04-29T06:49:16Z [*] This is an info message." 
 *                  (in blue)
 *
 *      `FLOGLN_DEBUG("This is a debug message.");`
 *
 *          File output: "2025-04-29T06:49:16Z [DEBUG] file:function:114: This is a debug message." 
 *
 *      `LOGLN_ERROR("This is an error.");`
 *
 *          Output: "2025-04-29T06:49:16Z [-] This is an error." (in red)
 */


/* Console Color Logging Mode options */

#define LOG_CONSOLE_MODE_NOCOLOR    0   // Disables color in console logging.
#define LOG_CONSOLE_MODE_COLOR      1   // Enables color in console logging
                                        // (default).

/* Adjust this to change console color logging mode. */
#define LOG_CONSOLE_MODE            LOG_CONSOLE_MODE_NOCOLOR



/* Logging Mode for where to log options */

#define LOG_MODE_NONE               0   // Disables `log`, `clog`, and 
                                        // `flog` functions.
#define LOG_MODE_CONSOLE            1   // `log` only logs to console and
                                        // disables `flog` functions.
#define LOG_MODE_FILE               2   // `log` only logs to file.
#define LOG_MODE_CONSOLE_AND_FILE   3   // All `log` functions enabled 
                                        // (default).

/** 
 * Adjust this to change log mode. 
 **/
#define LOG_MODE                    LOG_MODE_CONSOLE_AND_FILE



/* Logging level for what logs statements are compiled options */

#define LOG_LEVEL_NONE              0   // Disable all log levels.
#define LOG_LEVEL_ERR               1   // Only log FATAL and ERROR level logs.
#define LOG_LEVEL_WARN              2   // Log WARNING, FATAL, and ERROR
                                        // level logs.
#define LOG_LEVEL_INFO              3   // Logs WARNING, FATAL, ERROR, and INFO
                                        // level logs (including HEADER, 
                                        // INPUT, and SUCCESS logs).
#define LOG_LEVEL_EXTRA             4   // Enables all log levels except TRACE
                                        // and DEBUG logs.
#define LOG_LEVEL_DEBUG             5   // Enables all log levels except for
                                        // TRACE logs.
#define LOG_LEVEL_ALL               6   // Enable all log levels.

/**
 * Adjust this to change log level. 
 **/
#define LOG_LEVEL                   LOG_LEVEL_WARN


/** 
 * Adjust this to define the log filepath. Defaults to filename if not defined.
 **/
//#define CLOG_FILE "clog-test.log"


