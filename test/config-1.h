
/**
 *  Copyright (C) 2025 Dorian N. Nihil (starstarnull@starstarnull.net)
 *
 *  This program is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the Free
 *  Software Foundation, either version 3 of the License, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 *
 *  ====================
 *  Clog C Header Config
 *  ====================
 *
 *  Version: 0.0.1-1 beta
 *
 *  Clog C Header is a C header library of functions that can be included in a
 *  C project to provide colored printing and console and file logging macros.
 *  These functions can be configured to allow versatility of compile-time
 *  logging function inclusion. This file is a configuration header that must
 *  be included BEFORE each inclusion of "clog.h" if configuration is needed.
 *  The default configuration of Clog does not require a configuration header,
 *  but if you want to adjust the logging levels or other options, you need a
 *  configuration header (such as this one).
 *
 *
 *  Logging
 *  =======
 *
 *  Logging is also provided and there are some configuration options. There
 *  are three different main types of logging provided:
 *
 *      - The "clog" functions provide console logging to standard error.
 *
 *      - The "flog" functions provide file logging to the file set in the
 *      configuration header or to the default which is the '<file.c>.log'
 *      where `<file.c>` is the name of the C file using the logger.
 *
 *      - The "log" functions provide console and file logging if it is enabled
 *      in the configuration.
 *
 *
 *  Default Configuration
 *  ---------------------
 *
 *  Logs include a header with an ISO 8601 local time timestamp and a string
 *  "symbol" indicating the level of the log. Trace and debug logs also include
 *  the filename the call was logged from, the function name it was called
 *  from, and the line number the log call was made. For example:
 *
 *  `CLOGLN_INFO("This is an info message.");`
 *
 *  Output: "2025-04-29T06:49:16Z [*] This is an info message." (in blue)
 *
 *  `FLOGLN_DEBUG("This is a debug message.");`
 *
 *  File output:
 *
 *  "2025-04-29T06:49:16Z [DEBUG] file:function:114: This is a debug message."
 *
 *  `LOGLN_ERROR("This is an error.");`
 *
 *  Output: "2025-04-29T06:49:16Z [-] This is an error." (in red)
 *
 *
 *  Logging Options
 *  ===============
 *
 *  There are several configuration options available to customize the behavior
 *  of the "clog", "flog", and "log" functions. These options can be configured
 *  by including a configuration header (.h) file before the "clog.h" file.
 *
 *      * Timestamp format can be customized.
 *      * Line header separator can be customized.
 *      * Log level symbols can be customized.
 *      * Tracing info separators can be customized.
 *      * Tracing can be disabled.
 *      * Log message can be in color in console logs.
 *      * Log message colors can be customized.
 *      * Log message colors for console logs can be disabled.
 *
 *          - **Note** This only applies to level functions. Other colors
 *          manually inserted or using "cclog" functions will remain.
 *
 *      * What file gets written to for file logging.
 *      * Whether "log" logs to console, or a file, or both.
 *
 *  All of these options have defaults that work out of the box with just the
 *  "clog.h" header file.
 *
 *
 *  Configuring Console Color Mode
 *  ------------------------------
 *
 *  `CLOG_CONSOLE_MODE` which may be colored or uncolored by setting it to one
 *  of two options:
 *
 *      - `CLOG_CONSOLE_MODE_NOCOLOR` disables color console logging.
 *
 *      - `CLOG_CONSOLE_MODE_COLOR` enables color console logging (default).
 *
 *      **Note**: File logging never has colored logs.
 *
 *
 *  Log Mode
 *  --------
 *
 *  `CLOG_MODE` may be no logging, log to console only, log to file only, or
 *  log to console and file and may be set to one of the following options:
 *
 *      - `CLOG_MODE_NONE` disables all logging.
 *
 *      - `CLOG_MODE_CONSOLE` enables logging to the console only.
 *
 *      - `CLOG_MODE_FILE` enables logging to a file only.
 *
 *      - `CLOG_MODE_CONSOLE_AND_FILE` enables logging to the console and a
 *        file (default).
 *
 *      **Note**: All disabled logging calls are removed from the
 *      compilation (preprocessed out) through undefine or empty redefine
 *      macros. String declarations outside of logging calls may not
 *      be preprocessed out.
 *
 *
 *  Log Level Setting
 *  -----------------
 *
 *  `CLOG_LEVEL` is the level of logging that will occur. Options include:
 *
 *      - `CLOG_LEVEL_NONE` disables all logging.
 *
 *      - `CLOG_LEVEL_CRITICAL` enables critical and fatal logs only.
 *
 *      - `CLOG_LEVEL_ERROR` enables error, critical, and fatal logs.
 *
 *      - `CLOG_LEVEL_WARNING` enables warning, error, critical, and fatal
 *        logs.
 *
 *      - `CLOG_LEVEL_INFO` enables info (including header, success, money,
 *        and input logs), warning, error, critical, and fatal logs.
 *
 *      - `CLOG_LEVEL_EXTRA` enables extra, info, warning, error, critical,
 *        and fatal logs.
 *
 *      - `CLOG_LEVEL_DEBUG` enables debug, extra, info, warning, error,
 *        critical, and fatal logs.
 *
 *      - `CLOG_LEVEL_ALL` enables all logging including trace level logs
 *        (default).
 *
 *
 *  Log File
 *  --------
 *
 *  The log file for "log" and "flog" functions defaults to the C file name if
 *  not set. Some programs have multiple C files and each may have its own log.
 *  But if the developer would like to specify a single log file, the developer
 *  can specify a relative or absolute path in the CLOG_FILE macro definition
 *  via the Clog Configuration Header.
 *
 *  Defaults to "file.c.log" where the C source file name is "file.c".
 *
 *
 *  Log Time Format
 *  ---------------
 *
 *  The time format for timestamps defaults to ANZI ISO 8601 localtime time
 *  format. But it can be customized to be any time format via a strftime
 *  format string. For example, the default is "%FT%T%z", but it can be set to
 *  be a different format such as 2025-05-01 12:23 with a format string like
 *  "%Y-%m-%d %H:%M".
 *
 *  UTC mode can be enabled as well which will change times to UTC and the
 *  default time format specifier to "%FT%TZ".
 *
 *  Timestamps are enabled by default but can be disabled by uncommenting the
 *  disable timestamps macro.
 *
 *
 *  Tracing Separator
 *  -----------------
 *
 *  The tracing separator separates tracing elements. Defaults to a colon.
 *  For example, "file.c:function:22" where "file.c" is the file,
 *  "function" is the function that called the log function, and "22" is
 *  the line number of the log call. This can be configured to be a different
 *  string.
 *
 *
 *  Aliases
 *  -------
 *
 *  Aliases (short and shorter) may be enabled via a configuration as well. If
 *  "short"" aliases are enabled, function aliases with shorter (2 to 4
 *  character level abbreviations) names will be available. If "shorter"
 *  aliases are enabled, functions with even shorter names (2 character level
 *  abbreviations) will be available.
 *
 *
 *  Colors
 *  ------
 *
 *  Log level colors can be customized via configuration. Use of the Clog color
 *  library will require the "clog-colors.h" header file. Colors for console
 *  logging for different levels may be customized to any color.
 *
 *
 *  Symbols
 *  -------
 *
 *  Log level symbols my be configured to one of the preset options or to a
 *  customized set of symbols. They can have any length and each level may be
 *  customized individually. You can leave the default for other levels and
 *  change one specific level if desired.
 *
 *
 *  Line Header Separator
 *  ---------------------
 *
 *  The log line header separator may be specified in the configuration.
 *
 *
 *  Configuring
 *  ===========
 *
 *  To configure options, simply add a copy of the `clog-config.h` to project
 *  and uncomment macro definitions per instructions in the file as desired.
 *  Some options require new defintions that have templates provided. Then
 *  include the configuration BEFORE `clog.h`. For example:
 *
 *      #include "clog-config.h"        // BEFORE clog.h
 *      #include <clog.h>
 */

// Include guard.
#pragma once


/**
 * Uncomment this to enable short aliases for log level functions. Defaults to
 * disabled.
 */

#define CLOG_ENABLE_SHORT_ALIASES


/**
 * Uncomment this to enable even shorter aliases for log level functions.
 * Defaults to disabled.
 */

#define CLOG_ENABLE_SHORTER_ALIASES


/**
 * Uncomment this to enable "name" alias for "log" log level functions.
 * Defaults to disabled.
 */

#define CLOG_ENABLE_NAME_ALIASES


/**
 * Customize log level colors if desired. Uncomment log level colors you want
 * to customize (defaults to colors shown).
 *
 * Uncomment color library if you want to use its colors.
 */

#include <clog-colors.h>

#define C_TRACE     C_B_DARK_GRAY C_YELLOW
#define C_DEBUG     C_B_DARK_GRAY C_ORANGE
#define C_EXTRA     C_B_DARK_GRAY C_BR_BLUE
#define C_INFO      C_B_DARK_GRAY C_BLACK
#define C_HEADER    C_B_DARK_GRAY C_BLACK
#define C_SUCCESS   C_B_DARK_GRAY C_MAGENTA
#define C_MONEY     C_B_DARK_GRAY C_CYAN
#define C_INPUT     C_B_DARK_GRAY C_GRAY
#define C_WARNING   C_B_ORANGE C_BLACK
#define C_ERROR     C_B_DARK_GRAY C_BOLD C_BR_GREEN
#define C_CRITICAL  C_B_DARK_GRAY C_BR_BLACK
#define C_FATAL     C_B_DARK_GRAY C_BOLD


/**
 * Uncomment this to customize the line header separator (defaults to space).
 */

#define CLOG_LINE_HEADER_SEP      " %%HEADERSEP%% "


/**
 * Uncomment this to customize the tracing separator (defaults to colon).
 */

#define CLOG_TRACING_SEP            "-|%%TRACINGSEP%%|-"


/* Logging level line header symbol options */

#define CLOG_LEVEL_SYMS_NONE        0   // Disable log level symbols.
#define CLOG_LEVEL_SYMS_WORDS       1   // Use words as log level headers.
#define CLOG_LEVEL_SYMS_LETTERS     2   // Use letters as log level headers.
#define CLOG_LEVEL_SYMS_ONE_CHAR    3   // Use one-char symbols as log level
                                        // headers.
#define CLOG_LEVEL_SYMS_THREE_CHAR  4   // Use three-character symbols as log
                                        // level headers.
#define CLOG_LEVEL_SYMS_EMOJIS      5   // Use emojis as log level headers.
#define CLOG_LEVEL_SYMS_DEFAULT     6   // Use default log level symbols
                                        // (default).

/**
 * Adjust this to change log level line header symbols by selecting on of the
 * options. Defaults to `CLOG_LEVEL_SYMS_DEFAULT`.
 */

#define CLOG_LEVEL_SYMS             CLOG_LEVEL_SYMS_WORDS


/**
 * Or customize line headers symbols by uncommentting and editing symbols. If
 * these are defined, they will override the symbol regardless of the
 * `CLOG_LEVEL_SYMS` setting.
 */

//#define CLOG_SYM_TRACE     "<MY SYM>"
//#define CLOG_SYM_DEBUG     "<MY SYM>"
//#define CLOG_SYM_EXTRA     "<MY SYM>"
//#define CLOG_SYM_INFO      "<MY SYM>"
//#define CLOG_SYM_HEADER    "<MY SYM>"
//#define CLOG_SYM_SUCCESS   "<MY SYM>"
//#define CLOG_SYM_MONEY     "<MY SYM>"
//#define CLOG_SYM_INPUT     "<MY SYM>"
//#define CLOG_SYM_WARNING   "<MY SYM>"
//#define CLOG_SYM_ERROR     "<MY SYM>"
//#define CLOG_SYM_CRITICAL  "<MY SYM>"
//#define CLOG_SYM_FATAL     "<MY SYM>"


/* Console Color Logging Mode options */

#define CLOG_CONSOLE_MODE_NOCOLOR   0   // Disables color in console logging.
#define CLOG_CONSOLE_MODE_COLOR     1   // Enables color in console logging
                                        // (default).

/**
 * Adjust this to one of the options to change console color logging mode.
 * Defaults to `LOG_CONSOLE_MODE_COLOR`.
 */

//#define CLOG_CONSOLE_MODE           CLOG_CONSOLE_MODE_COLOR


/* Logging Mode for where to log options */

#define CLOG_MODE_NONE              0  // Disables `log`, `clog`, and `flog`
                                       // functions.
#define CLOG_MODE_CONSOLE           1  // `log` only logs to console.
#define CLOG_MODE_FILE              2  // `log` only logs to file.
#define CLOG_MODE_CONSOLE_AND_FILE  3  // `log` logs to console and file
                                       // (default).

/**
 * Adjust this to change log mode. Defaults to `CLOG_MODE_CONSOLE_AND_FILE`.
 */

#define CLOG_MODE                   CLOG_MODE_CONSOLE


/* Logging level for what logs statements are compiled options */

#define CLOG_LEVEL_NONE             0  // Disable all log levels.
#define CLOG_LEVEL_CRITICAL         1  // Only log CRITICAL and FATAL level
                                       // logs.
#define CLOG_LEVEL_ERROR            2  // Only log ERROR, CRITICAL, and FATAL
                                       // level logs.
#define CLOG_LEVEL_WARNING          3  // Only log WARNING, ERROR, CRITICAL,
                                       // and FATAL level logs.
#define CLOG_LEVEL_INFO             4  // Only logs INFO, HEADER, SUCCESS,
                                       // MONEY, INPUT, WARNING, ERROR,
                                       // CRITICAL, and FATAL level logs.
#define CLOG_LEVEL_EXTRA            5  // Only log EXTRA, INFO, HEADER,
                                       // SUCCESS, MONEY, INPUT, WARNING,
                                       // ERROR, CRITICAL, AND FATAL level
                                       // logs.
#define CLOG_LEVEL_DEBUG            6  // Only log DEBUG, EXTRA, INFO, HEADER,
                                       // SUCCESS, MONEY, INPUT, WARNING,
                                       // ERROR, CRITICAL, AND FATAL level
                                       // logs.
#define CLOG_LEVEL_ALL              7  // Enable all log levels including
                                       // TRACE level logs.

/**
 * Adjust this to change log level. Defaults to `CLOG_LEVEL_ALL`.
 */

//#define CLOG_LEVEL                  CLOG_LEVEL_ALL


/**
 * Adjust this to define the log filepath. Defaults to source code filename if
 * not defined.
 */

//#define CLOG_FILE                   "clog.log"


/**
 * Adjust this to define a timestamp format. Defaults to ANZI ISO 8601 time
 * format.
 */

#define CLOG_TIME_FORMAT            "%x %x %z %W FORMATTEST"


/**
 * Uncomment this to disable timestamps. Defaults to timestamps enabled.
 */

//#define CLOG_DISABLE_TIMESTAMPS


/**
 * Uncomment this to change default time format to UTC time. Defaults to
 * local time.
 */

//#define CLOG_USE_UTC_TIME


/**
 * Uncomment this to disable tracing statements (printing of
 * <file>:<function>:<line number>). By default, tracing is enabled for TRACE,
 * DEBUG, ERROR, CRITICAL, and FATAL level logs.
 */

//#define CLOG_DISABLE_TRACING


