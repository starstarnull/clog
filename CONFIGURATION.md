
Clog C Header Config
====================

Clog C Header is a C header library of functions that can be included in a
C project to provide colored printing and console and file logging macros.
These functions can be configured to allow versatility of compile-time
logging function inclusion. This file is a configuration header that must
be included BEFORE each inclusion of "clog.h" if configuration is needed.
The default configuration of Clog does not require a configuration header,
but if you want to adjust the logging levels or other options, you need a
configuration header (such as this one).


Logging
=======

Logging is also provided and there are some configuration options. There
are three different main types of logging provided:

- The "clog" functions provide console logging to standard error.

- The "flog" functions provide file logging to the file set in the configuration
header or to the default which is the '<file.c>.log' where `<file.c>` is the
name of the C file using the logger.

- The "log" functions provide console and file logging if it is enabled in the
configuration.

Logs are typically one line (but may be more) and are composed of a line
header (with several elements) and a log message. Log elements may include
a timestamp followed by a line header separator, a log level symbol
followed by a line header separator, and, if enabled, a tracing group
(which may be composed by a filename, function name, and line number
separated by a tracing separator), followed by a line header separator. For
example:

     "2025-04-29T06:49:16-04:00 [-] This is an error."
             ^                 ^ ^ ^ ^
             |                 | | | |
         timestamp            sep|sep'------ message
                                 |
                               level symbol (error log)

     "2025-04-29:06:49=[DEBUG]=file.c:function:22=This is an error."
           ^          ^     ^ ^'----------------'^     ^
           |          |     | |       |          |     |
 custom timestamp custom sep| sep  tracing info  sep   message
                            |
                          level symbol (debug log)



Default Configuration
---------------------

Logs include a header with an ISO 8601 local time timestamp and a string
"symbol" indicating the level of the log. Trace and debug logs also include
the filename the call was logged from, the function name it was called
from, and the line number the log call was made. For example:

`CLOGLN_INFO("This is an info message.");`

Output: "2025-04-29T06:49:16Z [*] This is an info message." (in blue)

`FLOGLN_DEBUG("This is a debug message.");`

File output:

"2025-04-29T06:49:16Z [DEBUG] file:function:114: This is a debug message."

`LOGLN_ERROR("This is an error.");`

Output: "2025-04-29T06:49:16Z [-] This is an error." (in red)


Logging Options
===============

There are several configuration options available to customize the behavior
of the "clog", "flog", and "log" functions. These options can be configured
by including a configuration header (.h) file before the "clog.h" file.

* Timestamp format can be customized.
* Line header separator can be customized.
* Log level symbols can be customized.
* Tracing info separators can be customized.
* Tracing can be disabled.
* Log message can be in color in console logs.
* Log message colors can be customized.
* Log message colors for console logs can be disabled.

    - **Note** This only applies to level functions. Other colors
    manually inserted or using "cclog" functions will remain.

* What file gets written to for file logging.
* Whether "log" logs to console, or a file, or both.

All of these options have defaults that work out of the box with just the
"clog.h" header file.


Configuring Console Color Mode
------------------------------

`CLOG_CONSOLE_MODE` which may be colored or uncolored by setting it to one
of two options:

- `CLOG_CONSOLE_MODE_NOCOLOR` disables color console logging.

- `CLOG_CONSOLE_MODE_COLOR` enables color console logging (default).

**Note**: File logging never has colored logs.


Log Mode
--------

`CLOG_MODE` may be no logging, log to console only, log to file only, or
log to console and file and may be set to one of the following options:

- `CLOG_MODE_NONE` disables all logging.

- `CLOG_MODE_CONSOLE` enables logging to the console only.

- `CLOG_MODE_FILE` enables logging to a file only.

- `CLOG_MODE_CONSOLE_AND_FILE` enables logging to the console and a
file (default).

**Note**: All disabled logging calls are removed from the
compilation (preprocessed out) through undefine or empty redefine
macros. String declarations outside of logging calls may not
be preprocessed out.


Log Level Setting
-----------------

`CLOG_LEVEL` is the level of logging that will occur. Options include:

- `CLOG_LEVEL_NONE` disables all logging.

- `CLOG_LEVEL_CRITICAL` enables critical and fatal logs only.

- `CLOG_LEVEL_ERROR` enables error, critical, and fatal logs.

- `CLOG_LEVEL_WARNING` enables warning, error, critical, and fatal
logs.

- `CLOG_LEVEL_INFO` enables info (including header, success, money,
and input logs), warning, error, critical, and fatal logs.

- `CLOG_LEVEL_EXTRA` enables extra, info, warning, error, critical,
and fatal logs.

- `CLOG_LEVEL_DEBUG` enables debug, extra, info, warning, error,
critical, and fatal logs.

- `CLOG_LEVEL_ALL` enables all logging including trace level logs
(default).


Log File
--------

The log file for "log" and "flog" functions defaults to the C file name if
not set. Some programs have multiple C files and each may have its own log.
But if the developer would like to specify a single log file, the developer
can specify a relative or absolute path in the CLOG_FILE macro definition
via the Clog Configuration Header.

Defaults to "file.c.log" where the C source file name is "file.c".


Log Time Format
---------------

The time format for timestamps defaults to ANZI ISO 8601 localtime time
format. But it can be customized to be any time format via a strftime
format string. For example, the default is "%FT%T%z", but it can be set to
be a different format such as 2025-05-01 12:23 with a format string like
"%Y-%m-%d %H:%M".

UTC mode can be enabled as well which will change times to UTC and the
default time format specifier to "%FT%TZ".

Timestamps are enabled by default but can be disabled by uncommenting the
disable timestamps macro.


Tracing Separator
-----------------

The tracing separator separates tracing elements. Defaults to a colon.
For example, "file.c:function:22" where "file.c" is the file,
"function" is the function that called the log function, and "22" is
the line number of the log call. This can be configured to be a different
string.


Aliases
-------

Aliases (short and shorter) may be enabled via a configuration as well. If
"short"" aliases are enabled, function aliases with shorter (2 to 4
character level abbreviations) names will be available. If "shorter"
aliases are enabled, functions with even shorter names (2 character level
abbreviations) will be available.


Colors
------

Log level colors can be customized via configuration. Use of the Clog color
library will require the "clog-colors.h" header file. Colors for console
logging for different levels may be customized to any color.


Symbols
-------

Log level symbols my be configured to one of the preset options or to a
customized set of symbols. They can have any length and each level may be
customized individually. You can leave the default for other levels and
change one specific level if desired.


Line Header Separator
---------------------

The log line header separator may be specified in the configuration.


Configuring
===========

To configure options, simply add a copy of the
[`clog-config.h`](src/clog-config.h) to project and uncomment macro definitions
per instructions in the file as desired. Some options require new defintions
that have templates provided.

    #include "clog-config.h"        // BEFORE clog.h
    #include <clog.h>


