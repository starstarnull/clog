
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
 *  =============
 *  Clog C Header
 *  =============
 *
 *  Version: 1.0.1
 *
 *  Provides macros for color console and file logging.
 *
 *  Clog C Header is a C header library of functions that can be included in a
 *  C project to provide colored printing and console and file logging macros.
 *  These functions can be configured to allow versatility of compile-time
 *  logging function inclusion.
 *
 *
 *  Features
 *  ========
 *
 *      * Terminal color macros.
 *      * Terminal color function macros.
 *      * Normal file print function macros.
 *      * File print line function macros.
 *      * Colored file print function macros.
 *      * Normal print function macros.
 *      * Print line function macros
 *      * Log level header print function macros.
 *      * Colored print function macros.
 *      * Colored print with line header function macros.
 *      * Colored log level header print function macros.
 *      * Console logging function macros.
 *      * File logging function macros.
 *      * Dual (console and file) logging function macros.
 *      * Colored logging function macros.
 *      * Logging with tracing function macros.
 *      * Colored logging with tracing function macros.
 *      * Logging with log level function macros.
 *      * Colored logging with log level function macros.
 *      * Logging with tracing and log level function macros.
 *      * Colored Logging with tracing and log level function macros.
 *      * Log level function alias macros.
 *      * Timestamps in logging.
 *      * Logging configuration options.
 *      * Turn logging off and set level at compile time (can remove logging
 *      from releases).
 *
 *
 *  Philosophy
 *  ==========
 *
 *  This logging library provides functions that are grouped by letters that
 *  indicate variations to the function behavior. The logs can be used during
 *  development and then deactivated for release. Or they can be customized and
 *  controlled by the developer.
 *
 *  The intent is to have a simple c header file that can be dropped into a
 *  project or added to an include path that enables logging and colored
 *  printing without configuration or additional setup unless specific
 *  configuration is required.
 *
 *  This allows the developer to decide whether to compile logging into the
 *  project or not by having the option to disable logging at compile time
 *  using a configuration header or a simple preprocessor definition. The
 *  developer can log all messages she or he wants and then disable logging for
 *  a release they do not want logging enabled in). So a logging version of the
 *  program will print and/or log all messages and a non-logging version will
 *  have a smaller file size and no logging, but no changes to the source code
 *  are needed.
 *
 *
 *  Requirements
 *  ============
 *
 *      * Currently uses standard C library.
 *
 *      * Currently developed and tested in Linux environment with the gcc
 *      compiler.
 *
 *      * (There are plans to extend functionality to support Windows and to
 *      allow for a version that is not dependent on standard C library in the
 *      future.)
 *
 *
 *  Usage
 *  =====
 *
 *  Simply include the header file in your project and start calling the print
 *  and logging functions. To customize the filename, define `CLOG_FILE` before
 *  the include statement for clog or edit it in the configuration example and
 *  include the configuration before including the clog header.
 *
 *  To configure logging, use a separate configuration header file and include
 *  BEFORE the clog header or make macro definitions before the include for the
 *  log header file.
 *
 *  There are several "groups" of functions.
 *
 *  * "fprint" functions print to the given file pointer. The "f" stands for
 *  "file" and indicates that the first argument is a C standard library file
 *  pointer.
 *
 *  * "cfprint" functions print to the given file pointer in the given color.
 *  The "c" stands for "color" and indicates that the first argument is a ANZI
 *  color string (provided via constant macros) and the second argument is a C
 *  standard library file pointer. The output has a color reset appended to the
 *  end.
 *
 *  * "print" functions print to standard out. This group also includes a set
 *  of "print_<level>" functions for printing with a leading level symbol
 *  (called a line header in this documentation).
 *
 *  * "cprint" functions print to standard out in the given color. The "c"
 *  stands for "color" and indicates that the first argument is a ANZI color
 *  string (provided via constant macros). The output has a color reset
 *  appended to the end. This group also has a set of "cprint_<level>"
 *  functions that print a leading symbol before the message.
 *
 *  * "clog" functions print to standard error using predefined colors,
 *  timestamps, and line headers and respond to log level and log color option
 *  configurations. The "c" here stands for "console" (yeah, I know it breaks
 *  the regular function rules -- it also stands for "color", but no color
 *  argument is required). The output has a color reset appended to the
 *  end. There are a series of "cclog" functions that allow for passing of a
 *  color for the line if desired.
 *
 *  * "flog" functions print to a predefined file timestamps and line headers
 *  and respond to log level configurations (colors are not used in file logs).
 *  The "f" stands for "file", but no file argument is needed.
 *
 *  * "log" functions log to standard error and a file using predefined colors,
 *  timestamps, and line headers (unless configured to do otherwise) and
 *  respond to log level and log color configurations.
 *
 *  Each group has suffixes that determine the specific behavior of the
 *  function.
 *
 *  * `<function>(s)` just outputs the given string `s`.
 *
 *  * `<function>LN(s)` outputs the given string `s` followed by a newline.
 *
 *  * `<function>F(s, ...)` outputs the given format string (just like
 *  `printf`).
 *
 *  * `<function>FLN(s, ...)` outputs the given format string (just like
 *  `printf`) followed by a newline.
 *
 *  * `<function><LN | F | FLN>_<level>(s)` follow the same rules described
 *  above, but print a symbolic line header representing the level.
 *
 *  Macros with leading underscores (like `_<macro`) are not intended to be
 *  used by the user.
 *
 *  Macro function definitions are all wrapped with brackets so they can be
 *  used without brackets. For example, the following works:
 *
 *      if (err)
 *          PERROR_ERROR("This is an error");
 *
 *  Since bracketing is used, if you use single line non-bracketed if else
 *  statements, you will have to omit the semicolon. For example:
 *
 *      if (err)
 *          LOGLN_ERROR("Oops.")  <---- notice missing semicolon for compiler.
 *
 *      else
 *          LOGLN_SUCCESS("Yay!");
 *
 *  Since the macro functions are bracketed, the semicolon is not required. But
 *  you can still use it, and it is recommended. For example, these statements
 *  both work and are equivalent:
 *
 *      PRINT("hello");
 *      PRINT("hello")
 *
 *  Additionally, since the functions are bracketed, you cannot use them as
 *  rvalues. They do not have a return type. For example, you CANNOT:
 *
 *      int x = PRINT("hello");
 *
 *  or:
 *
 *      printf("%d", PRINT("hello"));
 *
 *
 *  Configuration
 *  =============
 *
 *  See configuration header.
 *
 *
 *  Examples
 *  ========
 *
 *  `PRINTFLN("Your number is %d.", 22);`
 *
 *  Output: "Your number is 22.\n"
 *
 *  `CPRINTLN(C_RED, "I am a red line.");`
 *
 *  Output: "I am a red line.\n" (in red text)
 *
 *  `PRINTF_INFO("Your number is %d.", 22);`
 *
 *  Output: "[*] Your number is 22" (no newline)
 *
 *  `CLOGLN("I am a console log.");`
 *
 *  Output: "2025-04-29T06:49:16-04:00 I am a console log\n"
 *
 *  `CLOGFLN_SUCCESS("Your number is %d.", 22);`
 *
 *  Output: "2025-04-29T06:49:16-04:00 [+] Your number is 22.\n"
 *
 *  `CLOGLN_DEBUG("Your number is %d.", 22);`
 *
 *  Output: "2025-04-29T06:49:16-04:00 [DEBUG] file.c:func:4: Your number is 22.\n"
 *
 *  `LOGFLN("Your number is %d.", 22);`
 *
 *  Output: "2025-04-29T06:49:16-04:00 Your number is 22.\n"
 *  (In both console and file log)
 *
 *
 *  Future Plans
 *  ============
 *
 *  * Add support for multi-threading.
 *  * Add print verbosity functionality.
 *  * Add namespace mode (with defines in more limited namespace).
 *  * Add color hex and string hex (#ffffff) conversion functions.
 *  * Expand terminal color library to include italic, etc.
 *  * Add option to set new log file instead of appending to file.
 *  * Add exported symbols.
 *  * Add python library.
 *  * Add cpp library.
 *  * Port to Windows.
 *  * Need to consider backward compatability.
 *  * Add automated testing.
 *  * Consider reducing binary size with functions.
 *  * Add optimizations for space or speed (need to benchmark functions).
 *  * Add option for version that does not use libc.
 *  * Consider adding dynamic functions version (rather than pure macros).
 *
 *
 *  Exposed Constant Macros
 *  =======================
 *
 *  ANZI Terminal Control Codes
 *  ---------------------------
 *
 *      Modifiers
 *      ---------
 *
 *      C_RESET         Reset terminal color and modifier state.
 *      C_BOLD          Make text bold font.
 *
 *
 *      3-bit Foreground Colors
 *      -----------------------
 *
 *      C_BLACK         Make text foreground black.
 *      C_RED           Make text foreground red.
 *      C_GREEN         Make text foreground green.
 *      C_YELLOW        Make text foreground yellow.
 *      C_BLUE          Make text foreground blue.
 *      C_MAGENTA       Make text foreground magenta.
 *      C_CYAN          Make text foreground cyan.
 *      C_WHITE         Make text foreground white.
 *
 *
 *      3-bit Background Colors
 *      -----------------------
 *
 *      C_B_BLACK       Make text background black.
 *      C_B_RED         Make text background red.
 *      C_B_GREEN       Make text background green.
 *      C_B_YELLOW      Make text background yellow.
 *      C_B_BLUE        Make text background blue.
 *      C_B_MAGENTA     Make text background magenta.
 *      C_B_CYAN        Make text background cyan.
 *      C_B_WHITE       Make text background white.
 *
 *
 *      4-bit Bright Foreground Colors
 *      ------------------------------
 *
 *      C_BR_BLACK      Make text foreground bright black.
 *      C_BR_RED        Make text foreground bright red.
 *      C_BR_GREEN      Make text foreground bright green.
 *      C_BR_YELLOW     Make text foreground bright yellow.
 *      C_BR_BLUE       Make text foreground bright blue.
 *      C_BR_MAGENTA    Make text foreground bright magenta.
 *      C_BR_CYAN       Make text foreground bright cyan.
 *      C_BR_WHITE      Make text foreground bright white.
 *
 *
 *      4-bit Bright Background Colors
 *      ------------------------------
 *
 *      C_B_BR_BLACK    Make text background bright black.
 *      C_B_BR_RED      Make text background bright red.
 *      C_B_BR_GREEN    Make text background bright green.
 *      C_B_BR_YELLOW   Make text background bright yellow.
 *      C_B_BR_BLUE     Make text background bright blue.
 *      C_B_BR_MAGENTA  Make text background bright magenta.
 *      C_B_BR_CYAN     Make text background bright cyan.
 *      C_B_BR_WHITE    Make text background bright white.
 *
 *
 *      Other Colors
 *      ------------
 *
 *      C_ORANGE        Maket text foreground an orange color.
 *      C_B_ORANGE      Maket text background an orange color.
 *      C_GRAY          Maket text foreground an gray color.
 *      C_B_GRAY        Maket text background an gray color.
 *      C_DARK_GRAY     Maket text foreground an dark gray color.
 *      C_B_DARK_GRAY   Maket text background an dark gray color.
 *
 *
 *      Log Level Color Palette
 *      -----------------------
 *
 *      C_TRACE         Defaults to dark gray.
 *      C_DEBUG         Defaults to cyan.
 *      C_EXTRA         Defaults to dark gray.
 *      C_INFO          Defaults to bright blue.
 *      C_HEADER        Defaults to bold bright yellow.
 *      C_SUCCESS       Defaults to green.
 *      C_MONEY         Defaults to bold green.
 *      C_INPUT         Defaults to bright magenta.
 *      C_WARNING       Defaults to orange.
 *      C_ERROR         Defaults to bright red.
 *      C_CRITICAL      Defaults to bold bright red.
 *      C_FATAL         Defaults to bold bright red.
 *
 *
 *      Log Level Color Short Aliases (if enabled)
 *      ------------------------------------------
 *
 *      C_TRC           Defaults to C_TRACE.
 *      C_DBG           Defaults to C_DEBUG.
 *      C_EXT           Defaults to C_EXTRA.
 *      C_INF           Defaults to C_INFO.
 *      C_HEAD          Defaults to C_HEADER.
 *      C_SUC           Defaults to C_SUCCESS.
 *      C_MON           Defaults to C_MONEY.
 *      C_MNY           Defaults to C_MONEY.
 *      C_IN            Defaults to C_INPUT.
 *      C_WARN          Defaults to C_WARNING.
 *      C_ERR           Defaults to C_ERROR.
 *      C_CRIT          Defaults to C_CRITICAL.
 *      C_FAT           Defaults to C_FATAL.
 *
 *
 *      Log Level Color Shorter Aliases (if enabled)
 *      --------------------------------------------
 *
 *      C_TR            Defaults to C_TRACE.
 *      C_DB            Defaults to C_DEBUG.
 *      C_EX            Defaults to C_EXTRA.
 *      C_IF            Defaults to C_INFO.
 *      C_HD            Defaults to C_HEADER.
 *      C_SC            Defaults to C_SUCCESS.
 *      C_MN            Defaults to C_MONEY.
 *      C_MY            Defaults to C_MONEY.
 *      C_IN            Defaults to C_INPUT.
 *      C_WN            Defaults to C_WARNING.
 *      C_ER            Defaults to C_ERROR.
 *      C_CR            Defaults to C_CRITICAL.
 *      C_FT            Defaults to C_FATAL.
 *
 *
 *  Logging Strings
 *  ---------------
 *
 *      Log Level Header Symbols
 *      ------------------------
 *
 *      CLOG_SYM_TRACE      Defaults to "[TRACE]"
 *      CLOG_SYM_DEBUG      Defaults to "[DEBUG]"
 *      CLOG_SYM_EXTRA      Defaults to "[.]"
 *      CLOG_SYM_INFO       Defaults to "[*]"
 *      CLOG_SYM_HEADER     Defaults to "[***]"
 *      CLOG_SYM_SUCCESS    Defaults to "[+]"
 *      CLOG_SYM_MONEY      Defaults to "[$]"
 *      CLOG_SYM_INPUT      Defaults to "[?]"
 *      CLOG_SYM_WARNING    Defaults to "[!]"
 *      CLOG_SYM_ERROR      Defaults to "[-]"
 *      CLOG_SYM_CRITICAL   Defaults to "[!!!]"
 *      CLOG_SYM_FATAL      Defaults to "[FATAL]"
 *
 *
 *      Log Level Header Symbol Short Aliases (if enabled)
 *      --------------------------------------------------
 *
 *      CSYM_TRC        Defaults to CLOG_SYM_TRACE.
 *      CSYM_DBG        Defaults to CLOG_SYM_DEBUG.
 *      CSYM_EXT        Defaults to CLOG_SYM_EXTRA.
 *      CSYM_INF        Defaults to CLOG_SYM_INFO.
 *      CSYM_HEAD       Defaults to CLOG_SYM_HEADER.
 *      CSYM_SUC        Defaults to CLOG_SYM_SUCCESS.
 *      CSYM_MON        Defaults to CLOG_SYM_MONEY.
 *      CSYM_MNY        Defaults to CLOG_SYM_MONEY.
 *      CSYM_IN         Defaults to CLOG_SYM_INPUT.
 *      CSYM_WARN       Defaults to CLOG_SYM_WARNING.
 *      CSYM_ERR        Defaults to CLOG_SYM_ERROR.
 *      CSYM_CRIT       Defaults to CLOG_SYM_CRITICAL.
 *      CSYM_FAT        Defaults to CLOG_SYM_FATAL.
 *
 *
 *      Log Level Color Shorter Aliases (if enabled)
 *      --------------------------------------------
 *
 *      CSYM_TR         Defaults to CLOG_SYM_TRACE.
 *      CSYM_DB         Defaults to CLOG_SYM_DEBUG.
 *      CSYM_EX         Defaults to CLOG_SYM_EXTRA.
 *      CSYM_IF         Defaults to CLOG_SYM_INFO.
 *      CSYM_HD         Defaults to CLOG_SYM_HEADER.
 *      CSYM_SC         Defaults to CLOG_SYM_SUCCESS.
 *      CSYM_MN         Defaults to CLOG_SYM_MONEY.
 *      CSYM_MY         Defaults to CLOG_SYM_MONEY.
 *      CSYM_IN         Defaults to CLOG_SYM_INPUT.
 *      CSYM_WN         Defaults to CLOG_SYM_WARNING.
 *      CSYM_ER         Defaults to CLOG_SYM_ERROR.
 *      CSYM_CR         Defaults to CLOG_SYM_CRITICAL.
 *      CSYM_FT         Defaults to CLOG_SYM_FATAL.
 *
 *
 *  Options Constants
 *  -----------------
 *
 *      CLOG_ENABLE_SHORT_ALIASES       Defaults to not defined.
 *      CLOG_ENABLE_SHORTER_ALIASES     Defaults to not defined.
 *      CLOG_ENABLE_NAME_ALIASES        Defaults to not defined.
 *
 *      CLOG_LINE_HEADER_SEP            Defaults to space.
 *      CLOG_TRACING_SEP                Defaults to colon.
 *
 *      CLOG_LEVEL_SYMS_NONE            Symbol option 0.
 *      CLOG_LEVEL_SYMS_WORDS           Symbol option 1.
 *      CLOG_LEVEL_SYMS_LETTERS         Symbol option 2.
 *      CLOG_LEVEL_SYMS_ONE_CHAR        Symbol option 3.
 *      CLOG_LEVEL_SYMS_THREE_CHAR      Symbol option 4.
 *      CLOG_LEVEL_SYMS_EMOJIS          Symbol option 5.
 *      CLOG_LEVEL_SYMS_DEFAULT         Symbol option 6.
 *      CLOG_LEVEL_SYMS                 Defaults to CLOG_LEVEL_DEFAULT.
 *
 *      CLOG_CONSOLE_MODE_NOCOLOR       Console mode option 0.
 *      CLOG_CONSOLE_MODE_COLOR         Console mode option 1.
 *      CLOG_CONSOLE_MODE               Defaults to CLOG_CONSOLE_MODE_COLOR.
 *
 *      CLOG_MODE_NONE                  Log mode option 0.
 *      CLOG_MODE_CONSOLE               Log mode option 1.
 *      CLOG_MODE_FILE                  Log mode option 2.
 *      CLOG_MODE_CONSOLE_AND_FILE      Log mode option 3.
 *      CLOG_MODE                       Defaults to CLOG_MODE_CONSOLE_AND_FILE.
 *
 *      CLOG_LEVEL_NONE                 Log level option 0.
 *      CLOG_LEVEL_CRITICAL             Log level option 1.
 *      CLOG_LEVEL_ERROR                Log level option 2.
 *      CLOG_LEVEL_WARNING              Log level option 3.
 *      CLOG_LEVEL_INFO                 Log level option 4.
 *      CLOG_LEVEL_EXTRA                Log level option 5.
 *      CLOG_LEVEL_DEBUG                Log level option 6.
 *      CLOG_LEVEL_ALL                  Log level option 7.
 *      CLOG_LEVEL                      Defaults to CLOG_LEVEL_ALL.
 *
 *      CLOG_FILE                       Defaults to "<c_source_file>.log".
 *      CLOG_TIME_FORMAT                Defaults to "%FT%T%z"
 *
 *      CLOG_DISABLE_TIMESTAMPS         Defaults to not defined.
 *      CLOG_USE_UTC_TIME               Defaults to not defined.
 *      CLOG_DISABLE_TRACING            Defaults to not defined.
 *
 *
 *  Exposed Function Macros
 *  =======================
 *
 *  Color Functions
 *  ---------------
 *
 *      8-Bit Colors
 *      ------------
 *
 *      C_8BIT(n)       Make text foreground `n` color where `n` is a ANZI
 *                      8-bit color code. Argument must be in decimal.
 *
 *      C_B_8BIT(n)     Make text background `n` color where `n` is a ANZI
 *                      8-bit color code. Argument must be in decimal.
 *
 *
 *      24-Bit Colors
 *      -------------
 *
 *      C_24BIT(red, green, blue)   Make text foreground a RGB color with `red`
 *                                  amount of red, `green` amount of green, and
 *                                  `blue` amount of blue. Arguments must be in
 *                                  decimal.
 *
 *      C_RGB(red, green, blue)     Alias of `C_24BIT()`.
 *
 *      C_B_24BIT(red, green, blue) Make text background a RGB color with `red`
 *                                  amount of red, `green` amount of green, and
 *                                  `blue` amount of blue. Arguments must be in
 *                                  decimal.
 *
 *      C_B_RGB(red, green, blue)   Alias of `C_B_24BIT()`.
 *
 *
 *  Fundamental Functions
 *  ---------------------
 *
 *      "fprint" Functions
 *      ------------------
 *
 *      FPRINT(FILE* stream, const char* str)
 *
 *          Print the given string to the given stream.
 *
 *      FPRINTLN(FILE* stream, const char* str)
 *
 *          Print the given string to the given stream followed by a newline.
 *
 *      FPRINTF(FILE* stream, const char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream.
 *
 *      FPRINTFLN(FILE* stream, const char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream followed by a newline.
 *
 *      FPRINT_HEX(FILE* stream, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string.
 *
 *      FPRINTLN_HEX(FILE* stream, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string followed by a
 *          newline.
 *
 *      FPRINT_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces.
 *
 *      FPRINTLN_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces followed by a
 *          newline.
 *
 *      FPERROR(FILE* stream, char* str)
 *
 *          Print given string to the given file stream and then print the C
 *          error message.
 *
 *      FPERRORF(FILE* stream, char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream followed by a C error message.
 *
 *
 *      "cfprint" Functions
 *      -------------------
 *
 *      CFPRINT(const char* color, FILE* stream, const char* str)
 *
 *          Print given string to the given file stream in the given color.
 *
 *      CFPRINTLN(const char* color, FILE* stream, const char* str)
 *
 *          Print given string to the given file stream followed by a newline
 *          in the given color.
 *
 *      CFPRINTF(const char* color, FILE* stream, const char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream in the given color.
 *
 *      CFPRINTFLN(const char* color, FILE* stream, const char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream followed by a newline in the given color.
 *
 *      CFPRINT_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string in the given
 *          color.
 *
 *      CFPRINTLN_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string followed by a
 *          newline in the given color.
 *
 *      CFPRINT_WIDE_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces in the given color.
 *
 *      CFPRINTLN_WIDE_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces followed by a newline
 *          in the given color.
 *
 *      CFPERROR(const char* color, FILE* stream, const char* str)
 *
 *          Print given string to the given file stream and then print the C
 *          error message in the given color.
 *
 *      CFPERRORF(const char* color, FILE* stream, const char* format, ...)
 *
 *          Print given format string and format arguments to the given file
 *          stream followed by a C error message in the given color.
 *
 *
 *  Printing Functions
 *  ------------------
 *
 *      "print" Functions
 *      -----------------
 *
 *      PRINT(const char* str)
 *
 *          Print given string to standard output.
 *
 *      PRINTLN(const char* str)
 *
 *          Print given string to standard output followed by a newline.
 *
 *      PRINTF(const char* format, ...)
 *
 *          Print given format string and format arguments to standard output.
 *
 *      PRINTFLN(const char* format, ...)
 *
 *          Print given format string and format arguments to standard output
 *          followed by a newline.
 *
 *      PRINT_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          output.
 *
 *      PRINTLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          output followed by a newline.
 *
 *      PRINT_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard output.
 *
 *      PRINTLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard output
 *          followed by a newline.
 *
 *      PERROR(const char* str)
 *
 *          Print given string to standard output and then print the C error
 *          message.
 *
 *      PERRORF(const char* format, ...)
 *
 *          Print given format string and format arguments to standard output
 *          followed by a C error message.
 *
 *
 *      "print_level" Functions
 *      -----------------------
 *
 *      PRINT_TRACE(const char* str)
 *
 *          Print trace line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_TRACE(const char* str)
 *
 *          Print trace line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_TRACE(const char* format, ...)
 *
 *          Print trace line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_TRACE(const char* format, ...)
 *
 *          Print trace line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_DEBUG(const char* str)
 *
 *          Print debug line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_DEBUG(const char* str)
 *
 *          Print debug line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_DEBUG(const char* format, ...)
 *
 *          Print debug line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_DEBUG(const char* format, ...)
 *
 *          Print debug line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_EXTRA(const char* str)
 *
 *          Print extra line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_EXTRA(const char* str)
 *
 *          Print extra line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_EXTRA(const char* format, ...)
 *
 *          Print extra line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_EXTRA(const char* format, ...)
 *
 *          Print extra line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_INFO(const char* str)
 *
 *          Print info line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_INFO(const char* str)
 *
 *          Print info line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_INFO(const char* format, ...)
 *
 *          Print info line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_INFO(const char* format, ...)
 *
 *          Print info line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_HEADER(const char* str)
 *
 *          Print header line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_HEADER(const char* str)
 *
 *          Print header line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_HEADER(const char* format, ...)
 *
 *          Print header line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_HEADER(const char* format, ...)
 *
 *          Print header line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_SUCCESS(const char* str)
 *
 *          Print success line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_SUCCESS(const char* str)
 *
 *          Print success line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_SUCCESS(const char* format, ...)
 *
 *          Print success line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_SUCCESS(const char* format, ...)
 *
 *          Print success line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_MONEY(const char* str)
 *
 *          Print money line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_MONEY(const char* str)
 *
 *          Print money line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_MONEY(const char* format, ...)
 *
 *          Print money line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_MONEY(const char* format, ...)
 *
 *          Print money line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_INPUT(const char* str)
 *
 *          Print input line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_INPUT(const char* str)
 *
 *          Print input line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_INPUT(const char* format, ...)
 *
 *          Print input line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_INPUT(const char* format, ...)
 *
 *          Print input line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *
 *      PRINT_WARNING(const char* str)
 *
 *          Print warning line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_WARNING(const char* str)
 *
 *          Print warning line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_WARNING(const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_WARNING(const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *      PERROR_WARNING(const char* str)
 *
 *          Print warning line header followed by given string to standard
 *          output and then print the C error message.
 *
 *      PERRORF_WARNING(const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output followed by a C error message.
 *
 *
 *      PRINT_ERROR(const char* str)
 *
 *          Print error line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_ERROR(const char* str)
 *
 *          Print error line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_ERROR(const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_ERROR(const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *      PERROR_ERROR(const char* str)
 *
 *          Print error line header followed by given string to standard
 *          output and then print the C error message.
 *
 *      PERRORF_ERROR(const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output followed by a C error message.
 *
 *
 *      PRINT_CRITICAL(const char* str)
 *
 *          Print critical line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_CRITICAL(const char* str)
 *
 *          Print critical line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_CRITICAL(const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_CRITICAL(const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *      PERROR_CRITICAL(const char* str)
 *
 *          Print critical line header followed by given string to standard
 *          output and then print the C error message.
 *
 *      PERRORF_CRITICAL(const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output followed by a C error message.
 *
 *
 *      PRINT_FATAL(const char* str)
 *
 *          Print fatal line header followed by the given string to standard
 *          output.
 *
 *      PRINTLN_FATAL(const char* str)
 *
 *          Print fatal line header followed by given string to standard
 *          output followed by a newline.
 *
 *      PRINTF_FATAL(const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output.
 *
 *      PRINTFLN_FATAL(const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output followed by a newline.
 *
 *      PERROR_FATAL(const char* str)
 *
 *          Print fatal line header followed by given string to standard
 *          output and then print the C error message.
 *
 *      PERRORF_FATAL(const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output followed by a C error message.
 *
 *
 *      "print_level" Functions Short Aliases (if enabled)
 *      --------------------------------------------------
 *
 *      PRINT_TRC(const char* str)              Alias of PRINT_TRACE.
 *      PRINTLN_TRC(const char* str)            Alias of PRINTLN_TRACE.
 *      PRINTF_TRC(const char* format, ...)     Alias of PRINTF_TRACE.
 *      PRINTFLN_TRC(const char* format, ...)   Alias of PRINTFLN_TRACE.
 *
 *      PRINT_DBG(const char* str)              Alias of PRINT_DEBUG.
 *      PRINTLN_DBG(const char* str)            Alias of PRINTLN_DEBUG.
 *      PRINTF_DBG(const char* format, ...)     Alias of PRINTF_DEBUG.
 *      PRINTFLN_DBG(const char* format, ...)   Alias of PRINTFLN_DEBUG.
 *
 *      PRINT_EXT(const char* str)              Alias of PRINT_EXTRA.
 *      PRINTLN_EXT(const char* str)            Alias of PRINTLN_EXTRA.
 *      PRINTF_EXT(const char* format, ...)     Alias of PRINTF_EXTRA.
 *      PRINTFLN_EXT(const char* format, ...)   Alias of PRINTFLN_EXTRA.
 *
 *      PRINT_INF(const char* str)              Alias of PRINT_INFO.
 *      PRINTLN_INF(const char* str)            Alias of PRINTLN_INFO.
 *      PRINTF_INF(const char* format, ...)     Alias of PRINTF_INFO.
 *      PRINTFLN_INF(const char* format, ...)   Alias of PRINTFLN_INFO.
 *
 *      PRINT_HEAD(const char* str)             Alias of PRINT_HEADER.
 *      PRINTLN_HEAD(const char* str)           Alias of PRINTLN_HEADER.
 *      PRINTF_HEAD(const char* format, ...)    Alias of PRINTF_HEADER.
 *      PRINTFLN_HEAD(const char* format, ...)  Alias of PRINTFLN_HEADER.
 *
 *      PRINT_SUC(const char* str)              Alias of PRINT_SUCCESS.
 *      PRINTLN_SUC(const char* str)            Alias of PRINTLN_SUCCESS.
 *      PRINTF_SUC(const char* format, ...)     Alias of PRINTF_SUCCESS.
 *      PRINTFLN_SUC(const char* format, ...)   Alias of PRINTFLN_SUCCESS.
 *
 *      PRINT_MON(const char* str)              Alias of PRINT_MONEY.
 *      PRINTLN_MON(const char* str)            Alias of PRINTLN_MONEY.
 *      PRINTF_MON(const char* format, ...)     Alias of PRINTF_MONEY.
 *      PRINTFLN_MON(const char* format, ...)   Alias of PRINTFLN_MONEY.
 *
 *      PRINT_MNY(const char* str)              Alias of PRINT_MONEY.
 *      PRINTLN_MNY(const char* str)            Alias of PRINTLN_MONEY.
 *      PRINTF_MNY(const char* format, ...)     Alias of PRINTF_MONEY.
 *      PRINTFLN_MNY(const char* format, ...)   Alias of PRINTFLN_MONEY.
 *
 *      PRINT_IN(const char* str)               Alias of PRINT_INPUT.
 *      PRINTLN_IN(const char* str)             Alias of PRINTLN_INPUT.
 *      PRINTF_IN(const char* format, ...)      Alias of PRINTF_INPUT.
 *      PRINTFLN_IN(const char* format, ...)    Alias of PRINTFLN_INPUT.
 *
 *      PRINT_WARN(const char* str)             Alias of PRINT_WARNING.
 *      PRINTLN_WARN(const char* str)           Alias of PRINTLN_WARNING.
 *      PRINTF_WARN(const char* format, ...)    Alias of PRINTF_WARNING.
 *      PRINTFLN_WARN(const char* format, ...)  Alias of PRINTFLN_WARNING.
 *
 *      PERROR_WARN(const char* str)            Alias of PERROR_WARNING.
 *      PERRORF_WARN(const char* format, ...)   Alias of PERRORF_WARNING.
 *
 *      PRINT_ERR(const char* str)              Alias of PRINT_ERROR.
 *      PRINTLN_ERR(const char* str)            Alias of PRINTLN_ERROR.
 *      PRINTF_ERR(const char* format, ...)     Alias of PRINTF_ERROR.
 *      PRINTFLN_ERR(const char* format, ...)   Alias of PRINTFLN_ERROR.
 *
 *      PERROR_ERR(const char* str)             Alias of PERROR_ERROR.
 *      PERRORF_ERR(const char* format, ...)    Alias of PERRORF_ERROR.
 *
 *      PRINT_CRIT(const char* str)             Alias of PRINT_CRITICAL.
 *      PRINTLN_CRIT(const char* str)           Alias of PRINTLN_CRITICAL.
 *      PRINTF_CRIT(const char* format, ...)    Alias of PRINTF_CRITICAL.
 *      PRINTFLN_CRIT(const char* format, ...)  Alias of PRINTFLN_CRITICAL.
 *
 *      PERROR_CRIT(const char* str)            Alias of PERROR_CRITICAL.
 *      PERRORF_CRIT(const char* format, ...)   Alias of PERRORF_CRITICAL.
 *
 *      PRINT_FAT(const char* str)              Alias of PRINT_FATAL.
 *      PRINTLN_FAT(const char* str)            Alias of PRINTLN_FATAL.
 *      PRINTF_FAT(const char* format, ...)     Alias of PRINTF_FATAL.
 *      PRINTFLN_FAT(const char* format, ...)   Alias of PRINTFLN_FATAL.
 *
 *      PERROR_FAT(const char* str)             Alias of PERROR_FATAL.
 *      PERRORF_FAT(const char* format, ...)    Alias of PERRORF_FATAL.
 *
 *
 *      "print_level" Functions Shorter Aliases (if enabled)
 *      ----------------------------------------------------
 *
 *      PRINT_TR(const char* str)               Alias of PRINT_TRACE.
 *      PRINTLN_TR(const char* str)             Alias of PRINTLN_TRACE.
 *      PRINTF_TR(const char* format, ...)      Alias of PRINTF_TRACE.
 *      PRINTFLN_TR(const char* format, ...)    Alias of PRINTFLN_TRACE.
 *
 *      PRINT_DB(const char* str)               Alias of PRINT_DEBUG.
 *      PRINTLN_DB(const char* str)             Alias of PRINTLN_DEBUG.
 *      PRINTF_DB(const char* format, ...)      Alias of PRINTF_DEBUG.
 *      PRINTFLN_DB(const char* format, ...)    Alias of PRINTFLN_DEBUG.
 *
 *      PRINT_EX(const char* str)               Alias of PRINT_EXTRA.
 *      PRINTLN_EX(const char* str)             Alias of PRINTLN_EXTRA.
 *      PRINTF_EX(const char* format, ...)      Alias of PRINTF_EXTRA.
 *      PRINTFLN_EX(const char* format, ...)    Alias of PRINTFLN_EXTRA.
 *
 *      PRINT_IF(const char* str)               Alias of PRINT_INFO.
 *      PRINTLN_IF(const char* str)             Alias of PRINTLN_INFO.
 *      PRINTF_IF(const char* format, ...)      Alias of PRINTF_INFO.
 *      PRINTFLN_IF(const char* format, ...)    Alias of PRINTFLN_INFO.
 *
 *      PRINT_HD(const char* str)               Alias of PRINT_HEADER.
 *      PRINTLN_HD(const char* str)             Alias of PRINTLN_HEADER.
 *      PRINTF_HD(const char* format, ...)      Alias of PRINTF_HEADER.
 *      PRINTFLN_HD(const char* format, ...)    Alias of PRINTFLN_HEADER.
 *
 *      PRINT_SC(const char* str)               Alias of PRINT_SUCCESS.
 *      PRINTLN_SC(const char* str)             Alias of PRINTLN_SUCCESS.
 *      PRINTF_SC(const char* format, ...)      Alias of PRINTF_SUCCESS.
 *      PRINTFLN_SC(const char* format, ...)    Alias of PRINTFLN_SUCCESS.
 *
 *      PRINT_MN(const char* str)               Alias of PRINT_MONEY.
 *      PRINTLN_MN(const char* str)             Alias of PRINTLN_MONEY.
 *      PRINTF_MN(const char* format, ...)      Alias of PRINTF_MONEY.
 *      PRINTFLN_MN(const char* format, ...)    Alias of PRINTFLN_MONEY.
 *
 *      PRINT_MY(const char* str)               Alias of PRINT_MONEY.
 *      PRINTLN_MY(const char* str)             Alias of PRINTLN_MONEY.
 *      PRINTF_MY(const char* format, ...)      Alias of PRINTF_MONEY.
 *      PRINTFLN_MY(const char* format, ...)    Alias of PRINTFLN_MONEY.
 *
 *      PRINT_IN(const char* str)               Alias of PRINT_INPUT.
 *      PRINTLN_IN(const char* str)             Alias of PRINTLN_INPUT.
 *      PRINTF_IN(const char* format, ...)      Alias of PRINTF_INPUT.
 *      PRINTFLN_IN(const char* format, ...)    Alias of PRINTFLN_INPUT.
 *
 *      PRINT_WN(const char* str)               Alias of PRINT_WARNING.
 *      PRINTLN_WN(const char* str)             Alias of PRINTLN_WARNING.
 *      PRINTF_WN(const char* format, ...)      Alias of PRINTF_WARNING.
 *      PRINTFLN_WN(const char* format, ...)    Alias of PRINTFLN_WARNING.
 *
 *      PERROR_WN(const char* str)              Alias of PERROR_WARNING.
 *      PERRORF_WN(const char* format, ...)     Alias of PERRORF_WARNING.
 *
 *      PRINT_ER(const char* str)               Alias of PRINT_ERROR.
 *      PRINTLN_ER(const char* str)             Alias of PRINTLN_ERROR.
 *      PRINTF_ER(const char* format, ...)      Alias of PRINTF_ERROR.
 *      PRINTFLN_ER(const char* format, ...)    Alias of PRINTFLN_ERROR.
 *
 *      PERROR_ER(const char* str)              Alias of PERROR_ERROR.
 *      PERRORF_ER(const char* format, ...)     Alias of PERRORF_ERROR.
 *
 *      PRINT_CR(const char* str)               Alias of PRINT_CRITICAL.
 *      PRINTLN_CR(const char* str)             Alias of PRINTLN_CRITICAL.
 *      PRINTF_CR(const char* format, ...)      Alias of PRINTF_CRITICAL.
 *      PRINTFLN_CR(const char* format, ...)    Alias of PRINTFLN_CRITICAL.
 *
 *      PERROR_CR(const char* str)              Alias of PERROR_CRITICAL.
 *      PERRORF_CR(const char* format, ...)     Alias of PERRORF_CRITICAL.
 *
 *      PRINT_FT(const char* str)               Alias of PRINT_FATAL.
 *      PRINTLN_FT(const char* str)             Alias of PRINTLN_FATAL.
 *      PRINTF_FT(const char* format, ...)      Alias of PRINTF_FATAL.
 *      PRINTFLN_FT(const char* format, ...)    Alias of PRINTFLN_FATAL.
 *
 *      PERROR_FT(const char* str)              Alias of PERROR_FATAL.
 *      PERRORF_FT(const char* format, ...)     Alias of PERRORF_FATAL.
 *
 *
 *      "cprint" Functions
 *      -----------------
 *
 *      CPRINT(const char* color, const char* str)
 *
 *          Print given string to standard output in the given color.
 *
 *      CPRINTLN(const char* color, const char* str)
 *
 *          Print given string to standard output followed by a newline in the
 *          given color.
 *
 *      CPRINTF(const char* color, const char* format, ...)
 *
 *          Print given format string and format arguments to standard output
 *          in the given color.
 *
 *      CPRINTFLN(const char* color, const char* format, ...)
 *
 *          Print given format string and format arguments to standard output
 *          followed by a newline in the given color.
 *
 *      CPRINT_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          output in the given color.
 *
 *      CPRINTLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINT_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard output in
 *          the given color.
 *
 *      CPRINTLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard output
 *          followed by a newline in the given color.
 *
 *      CPERROR(const char* color, const char* str)
 *
 *          Print given string to standard output and then print the C error
 *          message in the given color.
 *
 *      CPERRORF(const char* color, const char* format, ...)
 *
 *          Print given format string and format arguments to standard output
 *          followed by a C error message in the given color.
 *
 *
 *      "cprint_level" Functions
 *      ------------------------
 *
 *      CPRINT_TRACE(const char* color, const char* str)
 *
 *          Print trace line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_TRACE(const char* color, const char* str)
 *
 *          Print trace line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_TRACE(const char* color, const char* format, ...)
 *
 *          Print trace line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_TRACE(const char* color, const char* format, ...)
 *
 *          Print trace line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_DEBUG(const char* color, const char* str)
 *
 *          Print debug line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_DEBUG(const char* color, const char* str)
 *
 *          Print debug line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_DEBUG(const char* color, const char* format, ...)
 *
 *          Print debug line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_DEBUG(const char* color, const char* format, ...)
 *
 *          Print debug line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_EXTRA(const char* color, const char* str)
 *
 *          Print extra line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_EXTRA(const char* color, const char* str)
 *
 *          Print extra line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_EXTRA(const char* color, const char* format, ...)
 *
 *          Print extra line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_EXTRA(const char* color, const char* format, ...)
 *
 *          Print extra line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_INFO(const char* color, const char* str)
 *
 *          Print info line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_INFO(const char* color, const char* str)
 *
 *          Print info line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_INFO(const char* color, const char* format, ...)
 *
 *          Print info line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_INFO(const char* color, const char* format, ...)
 *
 *          Print info line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_HEADER(const char* color, const char* str)
 *
 *          Print header line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_HEADER(const char* color, const char* str)
 *
 *          Print header line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_HEADER(const char* color, const char* format, ...)
 *
 *          Print header line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_HEADER(const char* color, const char* format, ...)
 *
 *          Print header line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_SUCCESS(const char* color, const char* str)
 *
 *          Print success line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_SUCCESS(const char* color, const char* str)
 *
 *          Print success line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_SUCCESS(const char* color, const char* format, ...)
 *
 *          Print success line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_SUCCESS(const char* color, const char* format, ...)
 *
 *          Print success line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_MONEY(const char* color, const char* str)
 *
 *          Print money line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_MONEY(const char* color, const char* str)
 *
 *          Print money line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_MONEY(const char* color, const char* format, ...)
 *
 *          Print money line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_MONEY(const char* color, const char* format, ...)
 *
 *          Print money line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_INPUT(const char* color, const char* str)
 *
 *          Print input line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_INPUT(const char* color, const char* str)
 *
 *          Print input line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_INPUT(const char* color, const char* format, ...)
 *
 *          Print input line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_INPUT(const char* color, const char* format, ...)
 *
 *          Print input line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *
 *      CPRINT_WARNING(const char* color, const char* str)
 *
 *          Print warning line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_WARNING(const char* color, const char* str)
 *
 *          Print warning line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_WARNING(const char* color, const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_WARNING(const char* color, const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *      CPERROR_WARNING(const char* color, const char* str)
 *
 *          Print warning line header followed by given string to standard
 *          output and then print the C error message in the given color.
 *
 *      CPERRORF_WARNING(const char* color, const char* format, ...)
 *
 *          Print warning line header followed by given format string and
 *          format arguments to standard output followed by a C error message
 *          in the given color.
 *
 *
 *      CPRINT_ERROR(const char* color, const char* str)
 *
 *          Print error line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_ERROR(const char* color, const char* str)
 *
 *          Print error line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_ERROR(const char* color, const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_ERROR(const char* color, const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *      CPERROR_ERROR(const char* color, const char* str)
 *
 *          Print error line header followed by given string to standard
 *          output and then print the C error message in the given color.
 *
 *      CPERRORF_ERROR(const char* color, const char* format, ...)
 *
 *          Print error line header followed by given format string and
 *          format arguments to standard output followed by a C error message
 *          in the given color.
 *
 *
 *      CPRINT_CRITICAL(const char* color, const char* str)
 *
 *          Print critical line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_CRITICAL(const char* color, const char* str)
 *
 *          Print critical line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_CRITICAL(const char* color, const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_CRITICAL(const char* color, const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *      CPERROR_CRITICAL(const char* color, const char* str)
 *
 *          Print critical line header followed by given string to standard
 *          output and then print the C error message in the given color.
 *
 *      CPERRORF_CRITICAL(const char* color, const char* format, ...)
 *
 *          Print critical line header followed by given format string and
 *          format arguments to standard output followed by a C error message
 *          in the given color.
 *
 *
 *      CPRINT_FATAL(const char* color, const char* str)
 *
 *          Print fatal line header followed by the given string to standard
 *          output in the given color.
 *
 *      CPRINTLN_FATAL(const char* color, const char* str)
 *
 *          Print fatal line header followed by given string to standard
 *          output followed by a newline in the given color.
 *
 *      CPRINTF_FATAL(const char* color, const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output in the given color.
 *
 *      CPRINTFLN_FATAL(const char* color, const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output followed by a newline in the
 *          given color.
 *
 *      CPERROR_FATAL(const char* color, const char* str)
 *
 *          Print fatal line header followed by given string to standard
 *          output and then print the C error message in the given color.
 *
 *      CPERRORF_FATAL(const char* color, const char* format, ...)
 *
 *          Print fatal line header followed by given format string and
 *          format arguments to standard output followed by a C error message
 *          in the given color.
 *
 *
 *      "cprint_level" Functions Short Aliases (if enabled)
 *      ---------------------------------------------------
 *
 *      CPRINT_TRC(const char* color, const char* str)
 *
 *          Alias of CPRINT_TRACE.
 *
 *      CPRINTLN_TRC(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_TRACE.
 *
 *      CPRINTF_TRC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_TRACE.
 *
 *      CPRINTFLN_TRC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_TRACE.
 *
 *
 *      CPRINT_DBG(const char* color, const char* str)
 *
 *          Alias of CPRINT_DEBUG.
 *
 *      CPRINTLN_DBG(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_DEBUG.
 *
 *      CPRINTF_DBG(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_DEBUG.
 *
 *      CPRINTFLN_DBG(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_DEBUG.
 *
 *
 *      CPRINT_EXT(const char* color, const char* str)
 *
 *          Alias of CPRINT_EXTRA.
 *
 *      CPRINTLN_EXT(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_EXTRA.
 *
 *      CPRINTF_EXT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_EXTRA.
 *
 *      CPRINTFLN_EXT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_EXTRA.
 *
 *
 *      CPRINT_INF(const char* color, const char* str)
 *
 *          Alias of CPRINT_INFO.
 *
 *      CPRINTLN_INF(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_INFO.
 *
 *      CPRINTF_INF(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_INFO.
 *
 *      CPRINTFLN_INF(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_INFO.
 *
 *
 *      CPRINT_HEAD(const char* color, const char* str)
 *
 *          Alias of CPRINT_HEADER.
 *
 *      CPRINTLN_HEAD(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_HEADER.
 *
 *      CPRINTF_HEAD(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_HEADER.
 *
 *      CPRINTFLN_HEAD(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_HEADER.
 *
 *
 *      CPRINT_SUC(const char* color, const char* str)
 *
 *          Alias of CPRINT_SUCCESS.
 *
 *      CPRINTLN_SUC(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_SUCCESS.
 *
 *      CPRINTF_SUC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_SUCCESS.
 *
 *      CPRINTFLN_SUC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_SUCCESS.
 *
 *
 *      CPRINT_MON(const char* color, const char* str)
 *
 *          Alias of CPRINT_MONEY.
 *
 *      CPRINTLN_MON(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_MONEY.
 *
 *      CPRINTF_MON(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_MONEY.
 *
 *      CPRINTFLN_MON(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_MONEY.
 *
 *
 *      CPRINT_MNY(const char* color, const char* str)
 *
 *          Alias of CPRINT_MONEY.
 *
 *      CPRINTLN_MNY(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_MONEY.
 *
 *      CPRINTF_MNY(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_MONEY.
 *
 *      CPRINTFLN_MNY(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_MONEY.
 *
 *
 *      CPRINT_IN(const char* color, const char* str)
 *
 *          Alias of CPRINT_INPUT.
 *
 *      CPRINTLN_IN(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_INPUT.
 *
 *      CPRINTF_IN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_INPUT.
 *
 *      CPRINTFLN_IN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_INPUT.
 *
 *
 *      CPRINT_WARN(const char* color, const char* str)
 *
 *          Alias of CPRINT_WARNING.
 *
 *      CPRINTLN_WARN(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_WARNING.
 *
 *      CPRINTF_WARN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_WARNING.
 *
 *      CPRINTFLN_WARN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_WARNING.
 *
 *
 *      CPERROR_WARN(const char* color, const char* str)
 *
 *          Alias of CPERROR_WARNING.
 *
 *      CPERRORF_WARN(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_WARNING.
 *
 *
 *      CPRINT_ERR(const char* color, const char* str)
 *
 *          Alias of CPRINT_ERROR.
 *
 *      CPRINTLN_ERR(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_ERROR.
 *
 *      CPRINTF_ERR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_ERROR.
 *
 *      CPRINTFLN_ERR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_ERROR.
 *
 *
 *      CPERROR_ERR(const char* color, const char* str)
 *
 *          Alias of CPERROR_ERROR.
 *
 *      CPERRORF_ERR(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_ERROR.
 *
 *
 *      CPRINT_CRIT(const char* color, const char* str)
 *
 *          Alias of CPRINT_CRITICAL.
 *
 *      CPRINTLN_CRIT(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_CRITICAL.
 *
 *      CPRINTF_CRIT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_CRITICAL.
 *
 *      CPRINTFLN_CRIT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_CRITICAL.
 *
 *
 *      CPERROR_CRIT(const char* color, const char* str)
 *
 *          Alias of CPERROR_CRITICAL.
 *
 *      CPERRORF_CRIT(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_CRITICAL.
 *
 *
 *      CPRINT_FAT(const char* color, const char* str)
 *
 *          Alias of CPRINT_FATAL.
 *
 *      CPRINTLN_FAT(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_FATAL.
 *
 *      CPRINTF_FAT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_FATAL.
 *
 *      CPRINTFLN_FAT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_FATAL.
 *
 *
 *      CPERROR_FAT(const char* color, const char* str)
 *
 *          Alias of CPERROR_FATAL.
 *
 *      CPERRORF_FAT(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_FATAL.
 *
 *
 *      "cprint_level" Functions Shorter Aliases (if enabled)
 *      -----------------------------------------------------
 *
 *      CPRINT_TR(const char* color, const char* str)
 *
 *          Alias of CPRINT_TRACE.
 *
 *      CPRINTLN_TR(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_TRACE.
 *
 *      CPRINTF_TR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_TRACE.
 *
 *      CPRINTFLN_TR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_TRACE.
 *
 *
 *      CPRINT_DB(const char* color, const char* str)
 *
 *          Alias of CPRINT_DEBUG.
 *
 *      CPRINTLN_DB(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_DEBUG.
 *
 *      CPRINTF_DB(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_DEBUG.
 *
 *      CPRINTFLN_DB(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_DEBUG.
 *
 *
 *      CPRINT_EX(const char* color, const char* str)
 *
 *          Alias of CPRINT_EXTRA.
 *
 *      CPRINTLN_EX(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_EXTRA.
 *
 *      CPRINTF_EX(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_EXTRA.
 *
 *      CPRINTFLN_EX(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_EXTRA.
 *
 *
 *      CPRINT_IF(const char* color, const char* str)
 *
 *          Alias of CPRINT_INFO.
 *
 *      CPRINTLN_IF(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_INFO.
 *
 *      CPRINTF_IF(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_INFO.
 *
 *      CPRINTFLN_IF(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_INFO.
 *
 *
 *      CPRINT_HD(const char* color, const char* str)
 *
 *          Alias of CPRINT_HEADER.
 *
 *      CPRINTLN_HD(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_HEADER.
 *
 *      CPRINTF_HD(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_HEADER.
 *
 *      CPRINTFLN_HD(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_HEADER.
 *
 *
 *      CPRINT_SC(const char* color, const char* str)
 *
 *          Alias of CPRINT_SUCCESS.
 *
 *      CPRINTLN_SC(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_SUCCESS.
 *
 *      CPRINTF_SC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_SUCCESS.
 *
 *      CPRINTFLN_SC(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_SUCCESS.
 *
 *
 *      CPRINT_MN(const char* color, const char* str)
 *
 *          Alias of CPRINT_MONEY.
 *
 *      CPRINTLN_MN(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_MONEY.
 *
 *      CPRINTF_MN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_MONEY.
 *
 *      CPRINTFLN_MN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_MONEY.
 *
 *
 *      CPRINT_MY(const char* color, const char* str)
 *
 *          Alias of CPRINT_MONEY.
 *
 *      CPRINTLN_MY(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_MONEY.
 *
 *      CPRINTF_MY(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_MONEY.
 *
 *      CPRINTFLN_MY(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_MONEY.
 *
 *
 *      CPRINT_IN(const char* color, const char* str)
 *
 *          Alias of CPRINT_INPUT.
 *
 *      CPRINTLN_IN(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_INPUT.
 *
 *      CPRINTF_IN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_INPUT.
 *
 *      CPRINTFLN_IN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_INPUT.
 *
 *
 *      CPRINT_WN(const char* color, const char* str)
 *
 *          Alias of CPRINT_WARNING.
 *
 *      CPRINTLN_WN(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_WARNING.
 *
 *      CPRINTF_WN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_WARNING.
 *
 *      CPRINTFLN_WN(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_WARNING.
 *
 *
 *      CPERROR_WN(const char* color, const char* str)
 *
 *          Alias of CPERROR_WARNING.
 *
 *      CPERRORF_WN(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_WARNING.
 *
 *
 *      CPRINT_ER(const char* color, const char* str)
 *
 *          Alias of CPRINT_ERROR.
 *
 *      CPRINTLN_ER(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_ERROR.
 *
 *      CPRINTF_ER(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_ERROR.
 *
 *      CPRINTFLN_ER(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_ERROR.
 *
 *
 *      CPERROR_ER(const char* color, const char* str)
 *
 *          Alias of CPERROR_ERROR.
 *
 *      CPERRORF_ER(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_ERROR.
 *
 *
 *      CPRINT_CR(const char* color, const char* str)
 *
 *          Alias of CPRINT_CRITICAL.
 *
 *      CPRINTLN_CR(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_CRITICAL.
 *
 *      CPRINTF_CR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_CRITICAL.
 *
 *      CPRINTFLN_CR(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_CRITICAL.
 *
 *
 *      CPERROR_CR(const char* color, const char* str)
 *
 *          Alias of CPERROR_CRITICAL.
 *
 *      CPERRORF_CR(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_CRITICAL.
 *
 *
 *      CPRINT_FT(const char* color, const char* str)
 *
 *          Alias of CPRINT_FATAL.
 *
 *      CPRINTLN_FT(const char* color, const char* str)
 *
 *          Alias of CPRINTLN_FATAL.
 *
 *      CPRINTF_FT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTF_FATAL.
 *
 *      CPRINTFLN_FT(const char* color, const char* format, ...)
 *
 *          Alias of CPRINTFLN_FATAL.
 *
 *
 *      CPERROR_FT(const char* color, const char* str)
 *
 *          Alias of CPERROR_FATAL.
 *
 *      CPERRORF_FT(const char* color, const char* format, ...)
 *
 *          Alias of CPERRORF_FATAL.
 *
 *
 *  Logging Functions
 *  -----------------
 *
 *      "clog" Functions
 *      ----------------
 *
 *      CLOG(const char* str)
 *
 *          Print timestamp and the given string to standard error.
 *
 *      CLOGLN(const char* str)
 *
 *          Print timestamp and the given string to standard error followed by
 *          a newline.
 *
 *      CLOGF(const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error.
 *
 *      CLOGFLN(const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error followed by a newline.
 *
 *      CLOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          to standard error.
 *
 *      CLOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          to standard error followed by a newline.
 *
 *      CLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error.
 *
 *      CLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error followed by a newline.
 *
 *      CLOG_PERROR(const char* str)
 *
 *          Print timestamp and the given string to standard error and then
 *          print the C error message.
 *
 *      CLOG_PERRORF(const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error followed by a C error message.
 *
 *
 *      "clog_stream" Functions
 *      -----------------------
 *
 *      CLOG_STREAM(const char* str)
 *
 *          Print the given string to standard error.
 *
 *      CLOGLN_STREAM(const char* str)
 *
 *          Print the given string to standard error followed by a newline.
 *
 *      CLOGF_STREAM(const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error.
 *
 *      CLOGFLN_STREAM(const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error followed by a newline.
 *
 *      CLOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          error.
 *
 *      CLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          error followed by a newline.
 *
 *      CLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error.
 *
 *      CLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          followed by a newline.
 *
 *      CLOG_PERROR_STREAM(const char* str)
 *
 *          Print the given string to standard error and then print the C error
 *          message.
 *
 *      CLOG_PERRORF_STREAM(const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error followed by a C error message.
 *
 *
 *      "ctlog" Functions
 *      -----------------
 *
 *      CTLOG(const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error.
 *
 *      CTLOGLN(const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error followed by a newline.
 *
 *      CTLOGF(const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error.
 *
 *      CTLOGFLN(const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error followed by a newline.
 *
 *      CTLOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error.
 *
 *      CTLOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error followed by a newline.
 *
 *      CTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error.
 *
 *      CTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error followed by a newline.
 *
 *      CTLOG_PERROR(const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error and then print the C error message.
 *
 *      CTLOG_PERRORF(const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error followed by a C error
 *          message.
 *
 *
 *      "cclog" Functions
 *      -----------------
 *
 *      CCLOG(const char* color, const char* str)
 *
 *          Print timestamp and the given string to standard error in the given
 *          color.
 *
 *      CCLOGLN(const char* color, const char* str)
 *
 *          Print timestamp and the given string to standard error followed by
 *          a newline in the given color.
 *
 *      CCLOGF(const char* color, const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error in the given color.
 *
 *      CCLOGFLN(const char* color, const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error followed by a newline in the given color.
 *
 *      CCLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          to standard error in the given color.
 *
 *      CCLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          to standard error followed by a newline in the given color.
 *
 *      CCLOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error in the given color.
 *
 *      CCLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error followed by a newline in the given color.
 *
 *      CCLOG_PERROR(const char* color, const char* str)
 *
 *          Print timestamp and the given string to standard error and then
 *          print the C error message in the given color.
 *
 *      CCLOG_PERRORF(const char* color, const char* format, ...)
 *
 *          Print timestamp and the given format string and format arguments to
 *          standard error followed by a C error message in the given color.
 *
 *
 *      "cclog_stream" Functions
 *      ------------------------
 *
 *      CCLOG_STREAM(const char* color, const char* str)
 *
 *          Print the given string to standard error in the given color.
 *
 *      CCLOGLN_STREAM(const char* color, const char* str)
 *
 *          Print the given string to standard error followed by a newline in
 *          the given color.
 *
 *      CCLOGF_STREAM(const char* color, const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error in the given color.
 *
 *      CCLOGFLN_STREAM(const char* color, const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error followed by a newline in the given color.
 *
 *      CCLOG_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          error in the given color.
 *
 *      CCLOGLN_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string to standard
 *          error followed by a newline in the given color.
 *
 *      CCLOG_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error in
 *          the given color.
 *
 *      CCLOGLN_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          followed by a newline in the given color.
 *
 *      CCLOG_PERROR_STREAM(const char* color, const char* str)
 *
 *          Print the given string to standard error and then print the C error
 *          message in the given color.
 *
 *      CCLOG_PERRORF_STREAM(const char* color, const char* format, ...)
 *
 *          Print the given format string and format arguments to standard
 *          error followed by a C error message in the given color.
 *
 *
 *      "cctlog" Functions
 *      ------------------
 *
 *      CCTLOG(const char* color, const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error in the given color.
 *
 *      CCTLOGLN(const char* color, const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error followed by a newline in the given color.
 *
 *      CCTLOGF(const char* color, const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error in the given color.
 *
 *      CCTLOGFLN(const char* color, const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error followed by a newline in the
 *          given color.
 *
 *      CCTLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error in the given color.
 *
 *      CCTLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error followed by a newline in
 *          the given color.
 *
 *      CCTLOG_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error in the given color.
 *
 *      CCTLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Print timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error followed by a newline in the
 *          given color.
 *
 *      CCTLOG_PERROR(const char* color, const char* str)
 *
 *          Print timestamp, tracing information, and the given string to
 *          standard error and then print the C error message in the given
 *          color.
 *
 *      CCTLOG_PERRORF(const char* color, const char* format, ...)
 *
 *          Print timestamp, tracing information, and the given format string
 *          and format arguments to standard error followed by a C error
 *          message in the given color.
 *
 *
 *      "clog_level" Functions
 *      ----------------------
 *
 *      CLOG_TRACE(const char* str)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given string to standard error in the appropriate log color.
 *
 *      CLOGLN_TRACE(const char* str)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given string to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOGF_TRACE(const char* format, ...)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given format string and format arguments to standard error in the
 *          appropriate log color.
 *
 *      CLOGFLN_TRACE(const char* format, ...)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given format string and format arguments to standard error followed
 *          by a newline in the appropriate log color.
 *
 *
 *      CLOG_DEBUG(const char* str)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given string to standard error in the appropriate log color.
 *
 *      CLOGLN_DEBUG(const char* str)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given string to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOGF_DEBUG(const char* format, ...)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given format string and format arguments to standard error in the
 *          appropriate log color.
 *
 *      CLOGFLN_DEBUG(const char* format, ...)
 *
 *          Print timestamp, tracing information, log level symbol, and the
 *          given format string and format arguments to standard error followed
 *          by a newline in the appropriate log color.
 *
 *
 *      CLOG_EXTRA(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_EXTRA(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_EXTRA(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_EXTRA(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_INFO(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_INFO(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_INFO(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_INFO(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_HEADER(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_HEADER(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_HEADER(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_HEADER(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_SUCCESS(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_SUCCESS(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_SUCCESS(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_SUCCESS(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_MONEY(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_MONEY(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_MONEY(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_MONEY(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_INPUT(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_INPUT(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_INPUT(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_INPUT(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *
 *      CLOG_WARNING(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_WARNING(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_WARNING(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_WARNING(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOG_PERROR_WARNING(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error and then print the C error message in the appropriate log
 *          color.
 *
 *      CLOG_PERRORF_WARNING(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a C error message in
 *          the appropriate log color.
 *
 *
 *      CLOG_ERROR(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_ERROR(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_ERROR(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_ERROR(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOG_PERROR_ERROR(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error and then print the C error message in the appropriate log
 *          color.
 *
 *      CLOG_PERRORF_ERROR(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a C error message in
 *          the appropriate log color.
 *
 *
 *      CLOG_CRITICAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_CRITICAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_CRITICAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_CRITICAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOG_PERROR_CRITICAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error and then print the C error message in the appropriate log
 *          color.
 *
 *      CLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a C error message in
 *          the appropriate log color.
 *
 *
 *      CLOG_FATAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error in the appropriate log color.
 *
 *      CLOGLN_FATAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error followed by a newline in the appropriate log color.
 *
 *      CLOGF_FATAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error in the appropriate log color.
 *
 *      CLOGFLN_FATAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a newline in the
 *          appropriate log color.
 *
 *      CLOG_PERROR_FATAL(const char* str)
 *
 *          Print timestamp, log level symbol, and the given string to standard
 *          error and then print the C error message in the appropriate log
 *          color.
 *
 *      CLOG_PERRORF_FATAL(const char* format, ...)
 *
 *          Print timestamp, log level symbol, and the given format string and
 *          format arguments to standard error followed by a C error message in
 *          the appropriate log color.
 *
 *
 *      "clog_level" Functions Short Aliases (if enabled)
 *      -------------------------------------------------
 *
 *      CLOG_TRC(const char* str);
 *
 *          Alias of `CLOG_TRACE` function.
 *
 *      CLOGLN_TRC(const char* str);
 *
 *          Alias of `CLOGLN_TRACE` function.
 *
 *      CLOGF_TRC(const char* format, ...);
 *
 *          Alias of `CLOGF_TRACE` function.
 *
 *      CLOGFLN_TRC(const char* format, ...);
 *
 *          Alias of `CLOGFLN_TRACE` function.
 *
 *
 *      CLOG_DBG(const char* str);
 *
 *          Alias of `CLOG_DEBUG` function.
 *
 *      CLOGLN_DBG(const char* str);
 *
 *          Alias of `CLOGLN_DEBUG` function.
 *
 *      CLOGF_DBG(const char* format, ...);
 *
 *          Alias of `CLOGF_DEBUG` function.
 *
 *      CLOGFLN_DBG(const char* format, ...);
 *
 *          Alias of `CLOGFLN_DEBUG` function.
 *
 *
 *      CLOG_EXT(const char* str);
 *
 *          Alias of `CLOG_EXTRA` function.
 *
 *      CLOGLN_EXT(const char* str);
 *
 *          Alias of `CLOGLN_EXTRA` function.
 *
 *      CLOGF_EXT(const char* format, ...);
 *
 *          Alias of `CLOGF_EXTRA` function.
 *
 *      CLOGFLN_EXT(const char* format, ...);
 *
 *          Alias of `CLOGFLN_EXTRA` function.
 *
 *
 *      CLOG_INF(const char* str);
 *
 *          Alias of `CLOG_INFO` function.
 *
 *      CLOGLN_INF(const char* str);
 *
 *          Alias of `CLOGLN_INFO` function.
 *
 *      CLOGF_INF(const char* format, ...);
 *
 *          Alias of `CLOGF_INFO` function.
 *
 *      CLOGFLN_INF(const char* format, ...);
 *
 *          Alias of `CLOGFLN_INFO` function.
 *
 *
 *      CLOG_HEAD(const char* str);
 *
 *          Alias of `CLOG_HEADER` function.
 *
 *      CLOGLN_HEAD(const char* str);
 *
 *          Alias of `CLOG_TRACE` function.
 *
 *      CLOGF_HEAD(const char* format, ...);
 *
 *          Alias of `CLOGF_HEADER` function.
 *
 *      CLOGFLN_HEAD(const char* format, ...);
 *
 *          Alias of `CLOGFLN_HEADER` function.
 *
 *
 *      CLOG_SUC(const char* str);
 *
 *          Alias of `CLOG_SUCCESS` function.
 *
 *      CLOGLN_SUC(const char* str);
 *
 *          Alias of `CLOGLN_SUCCESS` function.
 *
 *      CLOGF_SUC(const char* format, ...);
 *
 *          Alias of `CLOGF_SUCCESS` function.
 *
 *      CLOGFLN_SUC(const char* format, ...);
 *
 *          Alias of `CLOGFLN_SUCCESS` function.
 *
 *
 *      CLOG_MON(const char* str);
 *
 *          Alias of `CLOG_MONEY` function.
 *
 *      CLOGLN_MON(const char* str);
 *
 *          Alias of `CLOGLN_MONEY` function.
 *
 *      CLOGF_MON(const char* format, ...);
 *
 *          Alias of `CLOGF_MONEY` function.
 *
 *      CLOGFLN_MON(const char* format, ...);
 *
 *          Alias of `CLOGFLN_MONEY` function.
 *
 *
 *      CLOG_MNY(const char* str);
 *
 *          Alias of `CLOG_MONEY` function.
 *
 *      CLOGLN_MNY(const char* str);
 *
 *          Alias of `CLOGLN_MONEY` function.
 *
 *      CLOGF_MNY(const char* format, ...);
 *
 *          Alias of `CLOGF_MONEY` function.
 *
 *      CLOGFLN_MNY(const char* format, ...);
 *
 *          Alias of `CLOGFLN_MONEY` function.
 *
 *
 *      CLOG_IN(const char* str);
 *
 *          Alias of `CLOG_INPUT` function.
 *
 *      CLOGLN_IN(const char* str);
 *
 *          Alias of `CLOGLN_INPUT` function.
 *
 *      CLOGF_IN(const char* format, ...);
 *
 *          Alias of `CLOGF_INPUT` function.
 *
 *      CLOGFLN_IN(const char* format, ...);
 *
 *          Alias of `CLOGFLN_INPUT` function.
 *
 *
 *      CLOG_WARN(const char* str);
 *
 *          Alias of `CLOG_WARNING` function.
 *
 *      CLOGLN_WARN(const char* str);
 *
 *          Alias of `CLOGLN_WARNING` function.
 *
 *      CLOGF_WARN(const char* format, ...);
 *
 *          Alias of `CLOGF_WARNING` function.
 *
 *      CLOGFLN_WARN(const char* format, ...);
 *
 *          Alias of `CLOGFLN_WARNING` function.
 *
 *      CLOG_PERROR_WARN(const char* str);
 *
 *          Alias of `CLOG_PERROR_WARNING` function.
 *
 *      CLOG_PERRORF_WARN(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_WARNING` function.
 *
 *
 *      CLOG_ERR(const char* str);
 *
 *          Alias of `CLOG_ERROR` function.
 *
 *      CLOGLN_ERR(const char* str);
 *
 *          Alias of `CLOGLN_ERROR` function.
 *
 *      CLOGF_ERR(const char* format, ...);
 *
 *          Alias of `CLOGF_ERROR` function.
 *
 *      CLOGFLN_ERR(const char* format, ...);
 *
 *          Alias of `CLOGFLN_ERROR` function.
 *
 *      CLOG_PERROR_ERR(const char* str);
 *
 *          Alias of `CLOG_PERROR_ERROR` function.
 *
 *      CLOG_PERRORF_ERR(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_ERROR` function.
 *
 *
 *      CLOG_CRIT(const char* str);
 *
 *          Alias of `CLOG_CRITICAL` function.
 *
 *      CLOGLN_CRIT(const char* str);
 *
 *          Alias of `CLOGLN_CRITICAL` function.
 *
 *      CLOGF_CRIT(const char* format, ...);
 *
 *          Alias of `CLOGF_CRITICAL` function.
 *
 *      CLOGFLN_CRIT(const char* format, ...);
 *
 *          Alias of `CLOGFLN_CRITICAL` function.
 *
 *      CLOG_PERROR_CRIT(const char* str);
 *
 *          Alias of `CLOG_PERROR_CRITICAL` function.
 *
 *      CLOG_PERRORF_CRIT(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_CRITICAL` function.
 *
 *
 *      CLOG_FAT(const char* str);
 *
 *          Alias of `CLOG_FATAL` function.
 *
 *      CLOGLN_FAT(const char* str);
 *
 *          Alias of `CLOGLN_FATAL` function.
 *
 *      CLOGF_FAT(const char* format, ...);
 *
 *          Alias of `CLOGF_FATAL` function.
 *
 *      CLOGFLN_FAT(const char* format, ...);
 *
 *          Alias of `CLOGFLN_FATAL` function.
 *
 *      CLOG_PERROR_FAT(const char* str);
 *
 *          Alias of `CLOG_PERROR_FATAL` function.
 *
 *      CLOG_PERRORF_FAT(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_FATAL` function.
 *
 *
 *      "clog_level" Functions Shorter Aliases (if enabled)
 *      ---------------------------------------------------
 *
 *      CLOG_TR(const char* str);
 *
 *          Alias of `CLOG_TRACE` function.
 *
 *      CLOGLN_TR(const char* str);
 *
 *          Alias of `CLOGLN_TRACE` function.
 *
 *      CLOGF_TR(const char* format, ...);
 *
 *          Alias of `CLOGF_TRACE` function.
 *
 *      CLOGFLN_TR(const char* format, ...);
 *
 *          Alias of `CLOGFLN_TRACE` function.
 *
 *
 *      CLOG_DB(const char* str);
 *
 *          Alias of `CLOG_DEBUG` function.
 *
 *      CLOGLN_DB(const char* str);
 *
 *          Alias of `CLOGLN_DEBUG` function.
 *
 *      CLOGF_DB(const char* format, ...);
 *
 *          Alias of `CLOGF_DEBUG` function.
 *
 *      CLOGFLN_DB(const char* format, ...);
 *
 *          Alias of `CLOGFLN_DEBUG` function.
 *
 *
 *      CLOG_EX(const char* str);
 *
 *          Alias of `CLOG_EXTRA` function.
 *
 *      CLOGLN_EX(const char* str);
 *
 *          Alias of `CLOGLN_EXTRA` function.
 *
 *      CLOGF_EX(const char* format, ...);
 *
 *          Alias of `CLOGF_EXTRA` function.
 *
 *      CLOGFLN_EX(const char* format, ...);
 *
 *          Alias of `CLOGFLN_EXTRA` function.
 *
 *
 *      CLOG_IF(const char* str);
 *
 *          Alias of `CLOG_INFO` function.
 *
 *      CLOGLN_IF(const char* str);
 *
 *          Alias of `CLOGLN_INFO` function.
 *
 *      CLOGF_IF(const char* format, ...);
 *
 *          Alias of `CLOGF_INFO` function.
 *
 *      CLOGFLN_IF(const char* format, ...);
 *
 *          Alias of `CLOGFLN_INFO` function.
 *
 *
 *      CLOG_HD(const char* str);
 *
 *          Alias of `CLOG_HEADER` function.
 *
 *      CLOGLN_HD(const char* str);
 *
 *          Alias of `CLOG_TRACE` function.
 *
 *      CLOGF_HD(const char* format, ...);
 *
 *          Alias of `CLOGF_HEADER` function.
 *
 *      CLOGFLN_HD(const char* format, ...);
 *
 *          Alias of `CLOGFLN_HEADER` function.
 *
 *
 *      CLOG_SC(const char* str);
 *
 *          Alias of `CLOG_SUCCESS` function.
 *
 *      CLOGLN_SC(const char* str);
 *
 *          Alias of `CLOGLN_SUCCESS` function.
 *
 *      CLOGF_SC(const char* format, ...);
 *
 *          Alias of `CLOGF_SUCCESS` function.
 *
 *      CLOGFLN_SC(const char* format, ...);
 *
 *          Alias of `CLOGFLN_SUCCESS` function.
 *
 *
 *      CLOG_MN(const char* str);
 *
 *          Alias of `CLOG_MONEY` function.
 *
 *      CLOGLN_MN(const char* str);
 *
 *          Alias of `CLOGLN_MONEY` function.
 *
 *      CLOGF_MN(const char* format, ...);
 *
 *          Alias of `CLOGF_MONEY` function.
 *
 *      CLOGFLN_MN(const char* format, ...);
 *
 *          Alias of `CLOGFLN_MONEY` function.
 *
 *
 *      CLOG_MY(const char* str);
 *
 *          Alias of `CLOG_MONEY` function.
 *
 *      CLOGLN_MY(const char* str);
 *
 *          Alias of `CLOGLN_MONEY` function.
 *
 *      CLOGF_MY(const char* format, ...);
 *
 *          Alias of `CLOGF_MONEY` function.
 *
 *      CLOGFLN_MY(const char* format, ...);
 *
 *          Alias of `CLOGFLN_MONEY` function.
 *
 *
 *      CLOG_IN(const char* str);
 *
 *          Alias of `CLOG_INPUT` function.
 *
 *      CLOGLN_IN(const char* str);
 *
 *          Alias of `CLOGLN_INPUT` function.
 *
 *      CLOGF_IN(const char* format, ...);
 *
 *          Alias of `CLOGF_INPUT` function.
 *
 *      CLOGFLN_IN(const char* format, ...);
 *
 *          Alias of `CLOGFLN_INPUT` function.
 *
 *
 *      CLOG_WN(const char* str);
 *
 *          Alias of `CLOG_WARNING` function.
 *
 *      CLOGLN_WN(const char* str);
 *
 *          Alias of `CLOGLN_WARNING` function.
 *
 *      CLOGF_WN(const char* format, ...);
 *
 *          Alias of `CLOGF_WARNING` function.
 *
 *      CLOGFLN_WN(const char* format, ...);
 *
 *          Alias of `CLOGFLN_WARNING` function.
 *
 *      CLOG_PERROR_WN(const char* str);
 *
 *          Alias of `CLOG_PERROR_WARNING` function.
 *
 *      CLOG_PERRORF_WN(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_WARNING` function.
 *
 *
 *      CLOG_ER(const char* str);
 *
 *          Alias of `CLOG_ERROR` function.
 *
 *      CLOGLN_ER(const char* str);
 *
 *          Alias of `CLOGLN_ERROR` function.
 *
 *      CLOGF_ER(const char* format, ...);
 *
 *          Alias of `CLOGF_ERROR` function.
 *
 *      CLOGFLN_ER(const char* format, ...);
 *
 *          Alias of `CLOGFLN_ERROR` function.
 *
 *      CLOG_PERROR_ER(const char* str);
 *
 *          Alias of `CLOG_PERROR_ERROR` function.
 *
 *      CLOG_PERRORF_ER(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_ERROR` function.
 *
 *
 *      CLOG_CR(const char* str);
 *
 *          Alias of `CLOG_CRITICAL` function.
 *
 *      CLOGLN_CR(const char* str);
 *
 *          Alias of `CLOGLN_CRITICAL` function.
 *
 *      CLOGF_CR(const char* format, ...);
 *
 *          Alias of `CLOGF_CRITICAL` function.
 *
 *      CLOGFLN_CR(const char* format, ...);
 *
 *          Alias of `CLOGFLN_CRITICAL` function.
 *
 *      CLOG_PERROR_CR(const char* str);
 *
 *          Alias of `CLOG_PERROR_CRITICAL` function.
 *
 *      CLOG_PERRORF_CR(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_CRITICAL` function.
 *
 *
 *      CLOG_FT(const char* str);
 *
 *          Alias of `CLOG_FATAL` function.
 *
 *      CLOGLN_FT(const char* str);
 *
 *          Alias of `CLOGLN_FATAL` function.
 *
 *      CLOGF_FT(const char* format, ...);
 *
 *          Alias of `CLOGF_FATAL` function.
 *
 *      CLOGFLN_FT(const char* format, ...);
 *
 *          Alias of `CLOGFLN_FATAL` function.
 *
 *      CLOG_PERROR_FT(const char* str);
 *
 *          Alias of `CLOG_PERROR_FATAL` function.
 *
 *      CLOG_PERRORF_FT(const char* format, ...);
 *
 *          Alias of `CLOG_PERRORF_FATAL` function.
 *
 *
 *      "flog" Functions
 *      ----------------
 *
 *      FLOG(const char* str)
 *
 *          Log timestamp and the given string to a log file.
 *
 *      FLOGLN(const char* str)
 *
 *          Log timestamp and the given string to a log file followed by a
 *          newline.
 *
 *      FLOGF(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to a
 *          log file.
 *
 *      FLOGFLN(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to a
 *          log file followed by a newline.
 *
 *      FLOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          a log file.
 *
 *      FLOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          a log file followed by a newline.
 *
 *      FLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to a
 *          log file.
 *
 *      FLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to a
 *          log file followed by a newline.
 *
 *      FLOG_PERROR(const char* str)
 *
 *          Log timestamp and the given string to a log file and then print the
 *          C error message.
 *
 *      FLOG_PERRORF(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to a
 *          log file followed by a C error message.
 *
 *
 *      "flog_stream" Functions
 *      -----------------------
 *
 *      FLOG_STREAM(const char* str)
 *
 *          Log the given string to a log file.
 *
 *      FLOGLN_STREAM(const char* str)
 *
 *          Log the given string to a log file followed by a newline.
 *
 *      FLOGF_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to a log file.
 *
 *      FLOGFLN_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to a log file
 *          followed by a newline.
 *
 *      FLOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string to a log file.
 *
 *      FLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string to a log file
 *          followed by a newline.
 *
 *      FLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to a log file.
 *
 *      FLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to a log file
 *          followed by a newline.
 *
 *      FLOG_PERROR_STREAM(const char* str)
 *
 *          Log the given string to a log file and then print the C error
 *          message.
 *
 *      FLOG_PERRORF_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to a log file
 *          followed by a C error message.
 *
 *
 *      "ftlog" Functions
 *      -----------------
 *
 *      FTLOG(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error.
 *
 *      FTLOGLN(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error.
 *
 *      FTLOGF(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to a log file.
 *
 *      FTLOGFLN(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *      FTLOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to a log file.
 *
 *      FTLOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to a log file followed by a newline.
 *
 *      FTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to a log file.
 *
 *      FTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to a log file followed by a newline.
 *
 *      FTLOG_PERROR(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and then print the C error message.
 *
 *      FTLOG_PERRORF(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to a log file followed by a C error message.
 *
 *
 *      "flog_level" Functions
 *      ----------------------
 *
 *      FLOG_TRACE(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to a log file.
 *
 *      FLOGLN_TRACE(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to a log file followed by a newline.
 *
 *      FLOGF_TRACE(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to a log file.
 *
 *      FLOGFLN_TRACE(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to a log file followed by a
 *          newline.
 *
 *      FLOG_DEBUG(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to a log file.
 *
 *      FLOGLN_DEBUG(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to a log file followed by a newline.
 *
 *      FLOGF_DEBUG(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to a log file.
 *
 *      FLOGFLN_DEBUG(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to a log file followed by a
 *          newline.
 *
 *
 *      FLOG_EXTRA(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_EXTRA(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_EXTRA(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_EXTRA(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_INFO(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_INFO(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_INFO(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_INFO(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_HEADER(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_HEADER(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_HEADER(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_HEADER(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_SUCCESS(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_SUCCESS(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_SUCCESS(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_SUCCESS(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_MONEY(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_MONEY(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_MONEY(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_MONEY(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_INPUT(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_INPUT(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_INPUT(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_INPUT(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *
 *      FLOG_WARNING(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_WARNING(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_WARNING(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_WARNING(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *      FLOG_PERROR_WARNING(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          and then print the C error message.
 *
 *      FLOG_PERRORF_WARNING(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a C error message.
 *
 *
 *      FLOG_ERROR(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_ERROR(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_ERROR(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_ERROR(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *      FLOG_PERROR_ERROR(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          and then print the C error message.
 *
 *      FLOG_PERRORF_ERROR(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a C error message.
 *
 *
 *      FLOG_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *      FLOG_PERROR_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          and then print the C error message.
 *
 *      FLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a C error message.
 *
 *
 *      FLOG_FATAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log
 *          file.
 *
 *      FLOGLN_FATAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          followed by a newline.
 *
 *      FLOGF_FATAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file.
 *
 *      FLOGFLN_FATAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a newline.
 *
 *      FLOG_PERROR_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to a log file
 *          and then print the C error message.
 *
 *      FLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to a log file followed by a C error message.
 *
 *
 *      "flog_level" Functions Short Aliases (if enabled)
 *      -------------------------------------------------
 *
 *      FLOG_TRC(const char* str);
 *
 *          Alias of `FLOG_TRACE` function.
 *
 *      FLOGLN_TRC(const char* str);
 *
 *          Alias of `FLOGLN_TRACE` function.
 *
 *      FLOGF_TRC(const char* format, ...);
 *
 *          Alias of `FLOGF_TRACE` function.
 *
 *      FLOGFLN_TRC(const char* format, ...);
 *
 *          Alias of `FLOGFLN_TRACE` function.
 *
 *
 *      FLOG_DBG(const char* str);
 *
 *          Alias of `FLOG_DEBUG` function.
 *
 *      FLOGLN_DBG(const char* str);
 *
 *          Alias of `FLOGLN_DEBUG` function.
 *
 *      FLOGF_DBG(const char* format, ...);
 *
 *          Alias of `FLOGF_DEBUG` function.
 *
 *      FLOGFLN_DBG(const char* format, ...);
 *
 *          Alias of `FLOGFLN_DEBUG` function.
 *
 *
 *      FLOG_EXT(const char* str);
 *
 *          Alias of `FLOG_EXTRA` function.
 *
 *      FLOGLN_EXT(const char* str);
 *
 *          Alias of `FLOGLN_EXTRA` function.
 *
 *      FLOGF_EXT(const char* format, ...);
 *
 *          Alias of `FLOGF_EXTRA` function.
 *
 *      FLOGFLN_EXT(const char* format, ...);
 *
 *          Alias of `FLOGFLN_EXTRA` function.
 *
 *
 *      FLOG_INF(const char* str);
 *
 *          Alias of `FLOG_INFO` function.
 *
 *      FLOGLN_INF(const char* str);
 *
 *          Alias of `FLOGLN_INFO` function.
 *
 *      FLOGF_INF(const char* format, ...);
 *
 *          Alias of `FLOGF_INFO` function.
 *
 *      FLOGFLN_INF(const char* format, ...);
 *
 *          Alias of `FLOGFLN_INFO` function.
 *
 *
 *      FLOG_HEAD(const char* str);
 *
 *          Alias of `FLOG_HEADER` function.
 *
 *      FLOGLN_HEAD(const char* str);
 *
 *          Alias of `FLOG_TRACE` function.
 *
 *      FLOGF_HEAD(const char* format, ...);
 *
 *          Alias of `FLOGF_HEADER` function.
 *
 *      FLOGFLN_HEAD(const char* format, ...);
 *
 *          Alias of `FLOGFLN_HEADER` function.
 *
 *
 *      FLOG_SUC(const char* str);
 *
 *          Alias of `FLOG_SUCCESS` function.
 *
 *      FLOGLN_SUC(const char* str);
 *
 *          Alias of `FLOGLN_SUCCESS` function.
 *
 *      FLOGF_SUC(const char* format, ...);
 *
 *          Alias of `FLOGF_SUCCESS` function.
 *
 *      FLOGFLN_SUC(const char* format, ...);
 *
 *          Alias of `FLOGFLN_SUCCESS` function.
 *
 *
 *      FLOG_MON(const char* str);
 *
 *          Alias of `FLOG_MONEY` function.
 *
 *      FLOGLN_MON(const char* str);
 *
 *          Alias of `FLOGLN_MONEY` function.
 *
 *      FLOGF_MON(const char* format, ...);
 *
 *          Alias of `FLOGF_MONEY` function.
 *
 *      FLOGFLN_MON(const char* format, ...);
 *
 *          Alias of `FLOGFLN_MONEY` function.
 *
 *
 *      FLOG_MNY(const char* str);
 *
 *          Alias of `FLOG_MONEY` function.
 *
 *      FLOGLN_MNY(const char* str);
 *
 *          Alias of `FLOGLN_MONEY` function.
 *
 *      FLOGF_MNY(const char* format, ...);
 *
 *          Alias of `FLOGF_MONEY` function.
 *
 *      FLOGFLN_MNY(const char* format, ...);
 *
 *          Alias of `FLOGFLN_MONEY` function.
 *
 *
 *      FLOG_IN(const char* str);
 *
 *          Alias of `FLOG_INPUT` function.
 *
 *      FLOGLN_IN(const char* str);
 *
 *          Alias of `FLOGLN_INPUT` function.
 *
 *      FLOGF_IN(const char* format, ...);
 *
 *          Alias of `FLOGF_INPUT` function.
 *
 *      FLOGFLN_IN(const char* format, ...);
 *
 *          Alias of `FLOGFLN_INPUT` function.
 *
 *
 *      FLOG_WARN(const char* str);
 *
 *          Alias of `FLOG_WARNING` function.
 *
 *      FLOGLN_WARN(const char* str);
 *
 *          Alias of `FLOGLN_WARNING` function.
 *
 *      FLOGF_WARN(const char* format, ...);
 *
 *          Alias of `FLOGF_WARNING` function.
 *
 *      FLOGFLN_WARN(const char* format, ...);
 *
 *          Alias of `FLOGFLN_WARNING` function.
 *
 *      FLOG_PERROR_WARN(const char* str);
 *
 *          Alias of `FLOG_PERROR_WARNING` function.
 *
 *      FLOG_PERRORF_WARN(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_WARNING` function.
 *
 *
 *      FLOG_ERR(const char* str);
 *
 *          Alias of `FLOG_ERROR` function.
 *
 *      FLOGLN_ERR(const char* str);
 *
 *          Alias of `FLOGLN_ERROR` function.
 *
 *      FLOGF_ERR(const char* format, ...);
 *
 *          Alias of `FLOGF_ERROR` function.
 *
 *      FLOGFLN_ERR(const char* format, ...);
 *
 *          Alias of `FLOGFLN_ERROR` function.
 *
 *      FLOG_PERROR_ERR(const char* str);
 *
 *          Alias of `FLOG_PERROR_ERROR` function.
 *
 *      FLOG_PERRORF_ERR(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_ERROR` function.
 *
 *
 *      FLOG_CRIT(const char* str);
 *
 *          Alias of `FLOG_CRITICAL` function.
 *
 *      FLOGLN_CRIT(const char* str);
 *
 *          Alias of `FLOGLN_CRITICAL` function.
 *
 *      FLOGF_CRIT(const char* format, ...);
 *
 *          Alias of `FLOGF_CRITICAL` function.
 *
 *      FLOGFLN_CRIT(const char* format, ...);
 *
 *          Alias of `FLOGFLN_CRITICAL` function.
 *
 *      FLOG_PERROR_CRIT(const char* str);
 *
 *          Alias of `FLOG_PERROR_CRITICAL` function.
 *
 *      FLOG_PERRORF_CRIT(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_CRITICAL` function.
 *
 *
 *      FLOG_FAT(const char* str);
 *
 *          Alias of `FLOG_FATAL` function.
 *
 *      FLOGLN_FAT(const char* str);
 *
 *          Alias of `FLOGLN_FATAL` function.
 *
 *      FLOGF_FAT(const char* format, ...);
 *
 *          Alias of `FLOGF_FATAL` function.
 *
 *      FLOGFLN_FAT(const char* format, ...);
 *
 *          Alias of `FLOGFLN_FATAL` function.
 *
 *      FLOG_PERROR_FAT(const char* str);
 *
 *          Alias of `FLOG_PERROR_FATAL` function.
 *
 *      FLOG_PERRORF_FAT(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_FATAL` function.
 *
 *
 *      "flog_level" Functions Shorter Aliases (if enabled)
 *      ---------------------------------------------------
 *
 *      FLOG_TR(const char* str);
 *
 *          Alias of `FLOG_TRACE` function.
 *
 *      FLOGLN_TR(const char* str);
 *
 *          Alias of `FLOGLN_TRACE` function.
 *
 *      FLOGF_TR(const char* format, ...);
 *
 *          Alias of `FLOGF_TRACE` function.
 *
 *      FLOGFLN_TR(const char* format, ...);
 *
 *          Alias of `FLOGFLN_TRACE` function.
 *
 *
 *      FLOG_DB(const char* str);
 *
 *          Alias of `FLOG_DEBUG` function.
 *
 *      FLOGLN_DB(const char* str);
 *
 *          Alias of `FLOGLN_DEBUG` function.
 *
 *      FLOGF_DB(const char* format, ...);
 *
 *          Alias of `FLOGF_DEBUG` function.
 *
 *      FLOGFLN_DB(const char* format, ...);
 *
 *          Alias of `FLOGFLN_DEBUG` function.
 *
 *
 *      FLOG_EX(const char* str);
 *
 *          Alias of `FLOG_EXTRA` function.
 *
 *      FLOGLN_EX(const char* str);
 *
 *          Alias of `FLOGLN_EXTRA` function.
 *
 *      FLOGF_EX(const char* format, ...);
 *
 *          Alias of `FLOGF_EXTRA` function.
 *
 *      FLOGFLN_EX(const char* format, ...);
 *
 *          Alias of `FLOGFLN_EXTRA` function.
 *
 *
 *      FLOG_IF(const char* str);
 *
 *          Alias of `FLOG_INFO` function.
 *
 *      FLOGLN_IF(const char* str);
 *
 *          Alias of `FLOGLN_INFO` function.
 *
 *      FLOGF_IF(const char* format, ...);
 *
 *          Alias of `FLOGF_INFO` function.
 *
 *      FLOGFLN_IF(const char* format, ...);
 *
 *          Alias of `FLOGFLN_INFO` function.
 *
 *
 *      FLOG_HD(const char* str);
 *
 *          Alias of `FLOG_HEADER` function.
 *
 *      FLOGLN_HD(const char* str);
 *
 *          Alias of `FLOG_TRACE` function.
 *
 *      FLOGF_HD(const char* format, ...);
 *
 *          Alias of `FLOGF_HEADER` function.
 *
 *      FLOGFLN_HD(const char* format, ...);
 *
 *          Alias of `FLOGFLN_HEADER` function.
 *
 *
 *      FLOG_SC(const char* str);
 *
 *          Alias of `FLOG_SUCCESS` function.
 *
 *      FLOGLN_SC(const char* str);
 *
 *          Alias of `FLOGLN_SUCCESS` function.
 *
 *      FLOGF_SC(const char* format, ...);
 *
 *          Alias of `FLOGF_SUCCESS` function.
 *
 *      FLOGFLN_SC(const char* format, ...);
 *
 *          Alias of `FLOGFLN_SUCCESS` function.
 *
 *
 *      FLOG_MN(const char* str);
 *
 *          Alias of `FLOG_MONEY` function.
 *
 *      FLOGLN_MN(const char* str);
 *
 *          Alias of `FLOGLN_MONEY` function.
 *
 *      FLOGF_MN(const char* format, ...);
 *
 *          Alias of `FLOGF_MONEY` function.
 *
 *      FLOGFLN_MN(const char* format, ...);
 *
 *          Alias of `FLOGFLN_MONEY` function.
 *
 *
 *      FLOG_MY(const char* str);
 *
 *          Alias of `FLOG_MONEY` function.
 *
 *      FLOGLN_MY(const char* str);
 *
 *          Alias of `FLOGLN_MONEY` function.
 *
 *      FLOGF_MY(const char* format, ...);
 *
 *          Alias of `FLOGF_MONEY` function.
 *
 *      FLOGFLN_MY(const char* format, ...);
 *
 *          Alias of `FLOGFLN_MONEY` function.
 *
 *
 *      FLOG_IN(const char* str);
 *
 *          Alias of `FLOG_INPUT` function.
 *
 *      FLOGLN_IN(const char* str);
 *
 *          Alias of `FLOGLN_INPUT` function.
 *
 *      FLOGF_IN(const char* format, ...);
 *
 *          Alias of `FLOGF_INPUT` function.
 *
 *      FLOGFLN_IN(const char* format, ...);
 *
 *          Alias of `FLOGFLN_INPUT` function.
 *
 *
 *      FLOG_WN(const char* str);
 *
 *          Alias of `FLOG_WARNING` function.
 *
 *      FLOGLN_WN(const char* str);
 *
 *          Alias of `FLOGLN_WARNING` function.
 *
 *      FLOGF_WN(const char* format, ...);
 *
 *          Alias of `FLOGF_WARNING` function.
 *
 *      FLOGFLN_WN(const char* format, ...);
 *
 *          Alias of `FLOGFLN_WARNING` function.
 *
 *      FLOG_PERROR_WN(const char* str);
 *
 *          Alias of `FLOG_PERROR_WARNING` function.
 *
 *      FLOG_PERRORF_WN(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_WARNING` function.
 *
 *
 *      FLOG_ER(const char* str);
 *
 *          Alias of `FLOG_ERROR` function.
 *
 *      FLOGLN_ER(const char* str);
 *
 *          Alias of `FLOGLN_ERROR` function.
 *
 *      FLOGF_ER(const char* format, ...);
 *
 *          Alias of `FLOGF_ERROR` function.
 *
 *      FLOGFLN_ER(const char* format, ...);
 *
 *          Alias of `FLOGFLN_ERROR` function.
 *
 *      FLOG_PERROR_ER(const char* str);
 *
 *          Alias of `FLOG_PERROR_ERROR` function.
 *
 *      FLOG_PERRORF_ER(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_ERROR` function.
 *
 *
 *      FLOG_CR(const char* str);
 *
 *          Alias of `FLOG_CRITICAL` function.
 *
 *      FLOGLN_CR(const char* str);
 *
 *          Alias of `FLOGLN_CRITICAL` function.
 *
 *      FLOGF_CR(const char* format, ...);
 *
 *          Alias of `FLOGF_CRITICAL` function.
 *
 *      FLOGFLN_CR(const char* format, ...);
 *
 *          Alias of `FLOGFLN_CRITICAL` function.
 *
 *      FLOG_PERROR_CR(const char* str);
 *
 *          Alias of `FLOG_PERROR_CRITICAL` function.
 *
 *      FLOG_PERRORF_CR(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_CRITICAL` function.
 *
 *
 *      FLOG_FT(const char* str);
 *
 *          Alias of `FLOG_FATAL` function.
 *
 *      FLOGLN_FT(const char* str);
 *
 *          Alias of `FLOGLN_FATAL` function.
 *
 *      FLOGF_FT(const char* format, ...);
 *
 *          Alias of `FLOGF_FATAL` function.
 *
 *      FLOGFLN_FT(const char* format, ...);
 *
 *          Alias of `FLOGFLN_FATAL` function.
 *
 *      FLOG_PERROR_FT(const char* str);
 *
 *          Alias of `FLOG_PERROR_FATAL` function.
 *
 *      FLOG_PERRORF_FT(const char* format, ...);
 *
 *          Alias of `FLOG_PERRORF_FATAL` function.
 *
 *
 *      "log" Functions
 *      ----------------
 *
 *      LOG(const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file.
 *
 *      LOGLN(const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file
 *          followed by a newline.
 *
 *      LOGF(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file.
 *
 *      LOGFLN(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file followed by a newline.
 *
 *      LOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          standard error and/or a file.
 *
 *      LOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          standard error and/or a file followed by a newline.
 *
 *      LOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error and/or a file.
 *
 *      LOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error and/or a file followed by a newline.
 *
 *      LOG_PERROR(const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file
 *          and then print the C error message.
 *
 *      LOG_PERRORF(const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file followed by a C error message.
 *
 *
 *      "log_stream" Functions
 *      -----------------------
 *
 *      LOG_STREAM(const char* str)
 *
 *          Log the given string to standard error and/or a file.
 *
 *      LOGLN_STREAM(const char* str)
 *
 *          Log the given string to standard error and/or a file followed by a
 *          newline.
 *
 *      LOGF_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file.
 *
 *      LOGFLN_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file followed by a newline.
 *
 *      LOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string to standard error
 *          and/or a file.
 *
 *      LOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string to standard error
 *          and/or a file followed by a newline.
 *
 *      LOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          and/or a file.
 *
 *      LOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          and/or a file followed by a newline.
 *
 *      LOG_PERROR_STREAM(const char* str)
 *
 *          Log the given string to standard error and/or a file and then print
 *          the C error message.
 *
 *      LOG_PERRORF_STREAM(const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file followed by a C error message.
 *
 *
 *      "tlog" Functions
 *      -----------------
 *
 *      TLOG(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file.
 *
 *      TLOGLN(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file followed by a newline.
 *
 *      TLOGF(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file.
 *
 *      TLOGFLN(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file followed by a
 *          newline.
 *
 *      TLOG_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error and/or a file.
 *
 *      TLOGLN_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error and/or a file followed by
 *          a newline.
 *
 *      TLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error and/or a file.
 *
 *      TLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error and/or a file followed by a
 *          newline.
 *
 *      TLOG_PERROR(const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file and then print the C error message.
 *
 *      TLOG_PERRORF(const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message.
 *
 *
 *      "c_log" Functions
 *      -----------------
 *
 *      C_LOG(const char* color, const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file
 *          in the given color (for console logs).
 *
 *      C_LOGLN(const char* color, const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file
 *          followed by a newline in the given color (for console logs).
 *
 *      C_LOGF(const char* color, const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file in the given color (for console logs).
 *
 *      C_LOGFLN(const char* color, const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file followed by a newline in the given
 *          color (for console logs).
 *
 *      C_LOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          standard error and/or a file in the given color (for console logs).
 *
 *      C_LOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string to
 *          standard error and/or a file followed by a newline in the given
 *          color (for console logs).
 *
 *      C_LOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error and/or a file in the given color (for console logs).
 *
 *      C_LOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log timestamp and the bytes of the given buffer as a hex string
 *          with preceding "0x" before each byte and delimited by spaces to
 *          standard error and/or a file followed by a newline in the given
 *          color (for console logs).
 *
 *      C_LOG_PERROR(const char* color, const char* str)
 *
 *          Log timestamp and the given string to standard error and/or a file
 *          and then print the C error message in the given color (for console
 *          logs).
 *
 *      C_LOG_PERRORF(const char* color, const char* format, ...)
 *
 *          Log timestamp and the given format string and format arguments to
 *          standard error and/or a file followed by a C error message in the
 *          given color (for console logs).
 *
 *
 *      "c_log_stream" Functions
 *      ------------------------
 *
 *      C_LOG_STREAM(const char* color, const char* str)
 *
 *          Log the given string to standard error and/or a file in the given
 *          color (for console logs).
 *
 *      C_LOGLN_STREAM(const char* color, const char* str)
 *
 *          Log the given string to standard error and/or a file followed by a
 *          newline in the given color (for console logs).
 *
 *      C_LOGF_STREAM(const char* color, const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file in the given color (for console logs).
 *
 *      C_LOGFLN_STREAM(const char* color, const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file followed by a newline in the given color (for console
 *          logs).
 *
 *      C_LOG_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log the bytes of the given buffer as a hex string to standard error
 *          and/or a file in the given color (for console logs).
 *
 *      C_LOGLN_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log the bytes of the given buffer as a hex string to standard error
 *          and/or a file followed by a newline in the given color (for console
 *          logs).
 *
 *      C_LOG_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          and/or a file in the given color (for console logs).
 *
 *      C_LOGLN_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log the bytes of the given buffer as a hex string with preceding
 *          "0x" before each byte and delimited by spaces to standard error
 *          and/or a file followed by a newline in the given color (for console
 *          logs).
 *
 *      C_LOG_PERROR_STREAM(const char* color, const char* str)
 *
 *          Log the given string to standard error and/or a file and then print
 *          the C error message in the given color (for console logs).
 *
 *      C_LOG_PERRORF_STREAM(const char* color, const char* format, ...)
 *
 *          Log the given format string and format arguments to standard error
 *          and/or a file followed by a C error message in the given color (for
 *          console logs).
 *
 *
 *      "c_tlog" Functions
 *      ------------------
 *
 *      C_TLOG(const char* color, const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file in the given color (for console logs).
 *
 *      C_TLOGLN(const char* color, const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file followed by a newline in the given
 *          color (for console logs).
 *
 *      C_TLOGF(const char* color, const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file in the given color
 *          (for console logs).
 *
 *      C_TLOGFLN(const char* color, const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file followed by a
 *          newline in the given color (for console logs).
 *
 *      C_TLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error and/or a file in the given
 *          color (for console logs).
 *
 *      C_TLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string to standard error and/or a file followed by
 *          a newline in the given color (for console logs).
 *
 *      C_TLOG_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error and/or a file in the given
 *          color (for console logs).
 *
 *      C_TLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *
 *          Log timestamp, tracing information, and the bytes of the given
 *          buffer as a hex string with preceding "0x" before each byte and
 *          delimited by spaces to standard error and/or a file followed by a
 *          newline in the given color (for console logs).
 *
 *      C_TLOG_PERROR(const char* color, const char* str)
 *
 *          Log timestamp, tracing information, and the given string to
 *          standard error and/or a file and then print the C error message in
 *          the given color (for console logs).
 *
 *      C_TLOG_PERRORF(const char* color, const char* format, ...)
 *
 *          Log timestamp, tracing information, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message in the given color (for console logs).
 *
 *
 *      "log_level" Functions
 *      ----------------------
 *
 *      LOG_TRACE(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_TRACE(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_TRACE(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_TRACE(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_DEBUG(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_DEBUG(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_DEBUG(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_DEBUG(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_EXTRA(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_EXTRA(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_EXTRA(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_EXTRA(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_INFO(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_INFO(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_INFO(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_INFO(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_HEADER(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_HEADER(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_HEADER(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_HEADER(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_SUCCESS(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_SUCCESS(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_SUCCESS(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_SUCCESS(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_MONEY(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_MONEY(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_MONEY(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_MONEY(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_INPUT(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_INPUT(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_INPUT(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_INPUT(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *
 *      LOG_WARNING(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_WARNING(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_WARNING(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_WARNING(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *      LOG_PERROR_WARNING(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to standard
 *          error and/or a file and then print the C error message in the
 *          appropriate log color.
 *
 *      LOG_PERRORF_WARNING(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message in the appropriate log color.
 *
 *
 *      LOG_ERROR(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_ERROR(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_ERROR(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_ERROR(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *      LOG_PERROR_ERROR(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to standard
 *          error and/or a file and then print the C error message in the
 *          appropriate log color.
 *
 *      LOG_PERRORF_ERROR(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message in the appropriate log color.
 *
 *
 *      LOG_CRITICAL(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_CRITICAL(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *      LOG_PERROR_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to standard
 *          error and/or a file and then print the C error message in the
 *          appropriate log color.
 *
 *      LOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message in the appropriate log color.
 *
 *
 *      LOG_FATAL(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file in the appropriate log
 *          color.
 *
 *      LOGLN_FATAL(const char* str)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          string to standard error and/or a file followed by a newline in the
 *          appropriate log color.
 *
 *      LOGF_FATAL(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          in the appropriate log color.
 *
 *      LOGFLN_FATAL(const char* format, ...)
 *
 *          Log timestamp, tracing information, log level symbol, and the given
 *          format string and format arguments to standard error and/or a file
 *          followed by a newline in the appropriate log color.
 *
 *      LOG_PERROR_CRITICAL(const char* str)
 *
 *          Log timestamp, log level symbol, and the given string to standard
 *          error and/or a file and then print the C error message in the
 *          appropriate log color.
 *
 *      LOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *          Log timestamp, log level symbol, and the given format string and
 *          format arguments to standard error and/or a file followed by a C
 *          error message in the appropriate log color.
 *
 *
 *      "log_level" Functions Short Aliases (if enabled)
 *      ------------------------------------------------
 *
 *      LOG_TRC(const char* str);
 *
 *          Alias of `LOG_TRACE` function.
 *
 *      LOGLN_TRC(const char* str);
 *
 *          Alias of `LOGLN_TRACE` function.
 *
 *      LOGF_TRC(const char* format, ...);
 *
 *          Alias of `LOGF_TRACE` function.
 *
 *      LOGFLN_TRC(const char* format, ...);
 *
 *          Alias of `LOGFLN_TRACE` function.
 *
 *
 *      LOG_DBG(const char* str);
 *
 *          Alias of `LOG_DEBUG` function.
 *
 *      LOGLN_DBG(const char* str);
 *
 *          Alias of `LOGLN_DEBUG` function.
 *
 *      LOGF_DBG(const char* format, ...);
 *
 *          Alias of `LOGF_DEBUG` function.
 *
 *      LOGFLN_DBG(const char* format, ...);
 *
 *          Alias of `LOGFLN_DEBUG` function.
 *
 *
 *      LOG_EXT(const char* str);
 *
 *          Alias of `LOG_EXTRA` function.
 *
 *      LOGLN_EXT(const char* str);
 *
 *          Alias of `LOGLN_EXTRA` function.
 *
 *      LOGF_EXT(const char* format, ...);
 *
 *          Alias of `LOGF_EXTRA` function.
 *
 *      LOGFLN_EXT(const char* format, ...);
 *
 *          Alias of `LOGFLN_EXTRA` function.
 *
 *
 *      LOG_INF(const char* str);
 *
 *          Alias of `LOG_INFO` function.
 *
 *      LOGLN_INF(const char* str);
 *
 *          Alias of `LOGLN_INFO` function.
 *
 *      LOGF_INF(const char* format, ...);
 *
 *          Alias of `LOGF_INFO` function.
 *
 *      LOGFLN_INF(const char* format, ...);
 *
 *          Alias of `LOGFLN_INFO` function.
 *
 *
 *      LOG_HEAD(const char* str);
 *
 *          Alias of `LOG_HEADER` function.
 *
 *      LOGLN_HEAD(const char* str);
 *
 *          Alias of `LOG_TRACE` function.
 *
 *      LOGF_HEAD(const char* format, ...);
 *
 *          Alias of `LOGF_HEADER` function.
 *
 *      LOGFLN_HEAD(const char* format, ...);
 *
 *          Alias of `LOGFLN_HEADER` function.
 *
 *
 *      LOG_SUC(const char* str);
 *
 *          Alias of `LOG_SUCCESS` function.
 *
 *      LOGLN_SUC(const char* str);
 *
 *          Alias of `LOGLN_SUCCESS` function.
 *
 *      LOGF_SUC(const char* format, ...);
 *
 *          Alias of `LOGF_SUCCESS` function.
 *
 *      LOGFLN_SUC(const char* format, ...);
 *
 *          Alias of `LOGFLN_SUCCESS` function.
 *
 *
 *      LOG_MON(const char* str);
 *
 *          Alias of `LOG_MONEY` function.
 *
 *      LOGLN_MON(const char* str);
 *
 *          Alias of `LOGLN_MONEY` function.
 *
 *      LOGF_MON(const char* format, ...);
 *
 *          Alias of `LOGF_MONEY` function.
 *
 *      LOGFLN_MON(const char* format, ...);
 *
 *          Alias of `LOGFLN_MONEY` function.
 *
 *
 *      LOG_MNY(const char* str);
 *
 *          Alias of `LOG_MONEY` function.
 *
 *      LOGLN_MNY(const char* str);
 *
 *          Alias of `LOGLN_MONEY` function.
 *
 *      LOGF_MNY(const char* format, ...);
 *
 *          Alias of `LOGF_MONEY` function.
 *
 *      LOGFLN_MNY(const char* format, ...);
 *
 *          Alias of `LOGFLN_MONEY` function.
 *
 *
 *      LOG_IN(const char* str);
 *
 *          Alias of `LOG_INPUT` function.
 *
 *      LOGLN_IN(const char* str);
 *
 *          Alias of `LOGLN_INPUT` function.
 *
 *      LOGF_IN(const char* format, ...);
 *
 *          Alias of `LOGF_INPUT` function.
 *
 *      LOGFLN_IN(const char* format, ...);
 *
 *          Alias of `LOGFLN_INPUT` function.
 *
 *
 *      LOG_WARN(const char* str);
 *
 *          Alias of `LOG_WARNING` function.
 *
 *      LOGLN_WARN(const char* str);
 *
 *          Alias of `LOGLN_WARNING` function.
 *
 *      LOGF_WARN(const char* format, ...);
 *
 *          Alias of `LOGF_WARNING` function.
 *
 *      LOGFLN_WARN(const char* format, ...);
 *
 *          Alias of `LOGFLN_WARNING` function.
 *
 *      LOG_PERROR_WARN(const char* str);
 *
 *          Alias of `LOG_PERROR_WARNING` function.
 *
 *      LOG_PERRORF_WARN(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_WARNING` function.
 *
 *
 *      LOG_ERR(const char* str);
 *
 *          Alias of `LOG_ERROR` function.
 *
 *      LOGLN_ERR(const char* str);
 *
 *          Alias of `LOGLN_ERROR` function.
 *
 *      LOGF_ERR(const char* format, ...);
 *
 *          Alias of `LOGF_ERROR` function.
 *
 *      LOGFLN_ERR(const char* format, ...);
 *
 *          Alias of `LOGFLN_ERROR` function.
 *
 *      LOG_PERROR_ERR(const char* str);
 *
 *          Alias of `LOG_PERROR_ERROR` function.
 *
 *      LOG_PERRORF_ERR(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_ERROR` function.
 *
 *
 *      LOG_CRIT(const char* str);
 *
 *          Alias of `LOG_CRITICAL` function.
 *
 *      LOGLN_CRIT(const char* str);
 *
 *          Alias of `LOGLN_CRITICAL` function.
 *
 *      LOGF_CRIT(const char* format, ...);
 *
 *          Alias of `LOGF_CRITICAL` function.
 *
 *      LOGFLN_CRIT(const char* format, ...);
 *
 *          Alias of `LOGFLN_CRITICAL` function.
 *
 *      LOG_PERROR_CRIT(const char* str);
 *
 *          Alias of `LOG_PERROR_CRITICAL` function.
 *
 *      LOG_PERRORF_CRIT(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_CRITICAL` function.
 *
 *
 *      LOG_FAT(const char* str);
 *
 *          Alias of `LOG_FATAL` function.
 *
 *      LOGLN_FAT(const char* str);
 *
 *          Alias of `LOGLN_FATAL` function.
 *
 *      LOGF_FAT(const char* format, ...);
 *
 *          Alias of `LOGF_FATAL` function.
 *
 *      LOGFLN_FAT(const char* format, ...);
 *
 *          Alias of `LOGFLN_FATAL` function.
 *
 *      LOG_PERROR_FAT(const char* str);
 *
 *          Alias of `LOG_PERROR_FATAL` function.
 *
 *      LOG_PERRORF_FAT(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_FATAL` function.
 *
 *
 *      "log_level" Functions Shorter Aliases (if enabled)
 *      --------------------------------------------------
 *
 *      LOG_TR(const char* str);
 *
 *          Alias of `LOG_TRACE` function.
 *
 *      LOGLN_TR(const char* str);
 *
 *          Alias of `LOGLN_TRACE` function.
 *
 *      LOGF_TR(const char* format, ...);
 *
 *          Alias of `LOGF_TRACE` function.
 *
 *      LOGFLN_TR(const char* format, ...);
 *
 *          Alias of `LOGFLN_TRACE` function.
 *
 *
 *      LOG_DB(const char* str);
 *
 *          Alias of `LOG_DEBUG` function.
 *
 *      LOGLN_DB(const char* str);
 *
 *          Alias of `LOGLN_DEBUG` function.
 *
 *      LOGF_DB(const char* format, ...);
 *
 *          Alias of `LOGF_DEBUG` function.
 *
 *      LOGFLN_DB(const char* format, ...);
 *
 *          Alias of `LOGFLN_DEBUG` function.
 *
 *
 *      LOG_EX(const char* str);
 *
 *          Alias of `LOG_EXTRA` function.
 *
 *      LOGLN_EX(const char* str);
 *
 *          Alias of `LOGLN_EXTRA` function.
 *
 *      LOGF_EX(const char* format, ...);
 *
 *          Alias of `LOGF_EXTRA` function.
 *
 *      LOGFLN_EX(const char* format, ...);
 *
 *          Alias of `LOGFLN_EXTRA` function.
 *
 *
 *      LOG_IF(const char* str);
 *
 *          Alias of `LOG_INFO` function.
 *
 *      LOGLN_IF(const char* str);
 *
 *          Alias of `LOGLN_INFO` function.
 *
 *      LOGF_IF(const char* format, ...);
 *
 *          Alias of `LOGF_INFO` function.
 *
 *      LOGFLN_IF(const char* format, ...);
 *
 *          Alias of `LOGFLN_INFO` function.
 *
 *
 *      LOG_HD(const char* str);
 *
 *          Alias of `LOG_HEADER` function.
 *
 *      LOGLN_HD(const char* str);
 *
 *          Alias of `LOG_TRACE` function.
 *
 *      LOGF_HD(const char* format, ...);
 *
 *          Alias of `LOGF_HEADER` function.
 *
 *      LOGFLN_HD(const char* format, ...);
 *
 *          Alias of `LOGFLN_HEADER` function.
 *
 *
 *      LOG_SC(const char* str);
 *
 *          Alias of `LOG_SUCCESS` function.
 *
 *      LOGLN_SC(const char* str);
 *
 *          Alias of `LOGLN_SUCCESS` function.
 *
 *      LOGF_SC(const char* format, ...);
 *
 *          Alias of `LOGF_SUCCESS` function.
 *
 *      LOGFLN_SC(const char* format, ...);
 *
 *          Alias of `LOGFLN_SUCCESS` function.
 *
 *
 *      LOG_MN(const char* str);
 *
 *          Alias of `LOG_MONEY` function.
 *
 *      LOGLN_MN(const char* str);
 *
 *          Alias of `LOGLN_MONEY` function.
 *
 *      LOGF_MN(const char* format, ...);
 *
 *          Alias of `LOGF_MONEY` function.
 *
 *      LOGFLN_MN(const char* format, ...);
 *
 *          Alias of `LOGFLN_MONEY` function.
 *
 *
 *      LOG_MY(const char* str);
 *
 *          Alias of `LOG_MONEY` function.
 *
 *      LOGLN_MY(const char* str);
 *
 *          Alias of `LOGLN_MONEY` function.
 *
 *      LOGF_MY(const char* format, ...);
 *
 *          Alias of `LOGF_MONEY` function.
 *
 *      LOGFLN_MY(const char* format, ...);
 *
 *          Alias of `LOGFLN_MONEY` function.
 *
 *
 *      LOG_IN(const char* str);
 *
 *          Alias of `LOG_INPUT` function.
 *
 *      LOGLN_IN(const char* str);
 *
 *          Alias of `LOGLN_INPUT` function.
 *
 *      LOGF_IN(const char* format, ...);
 *
 *          Alias of `LOGF_INPUT` function.
 *
 *      LOGFLN_IN(const char* format, ...);
 *
 *          Alias of `LOGFLN_INPUT` function.
 *
 *
 *      LOG_WN(const char* str);
 *
 *          Alias of `LOG_WARNING` function.
 *
 *      LOGLN_WN(const char* str);
 *
 *          Alias of `LOGLN_WARNING` function.
 *
 *      LOGF_WN(const char* format, ...);
 *
 *          Alias of `LOGF_WARNING` function.
 *
 *      LOGFLN_WN(const char* format, ...);
 *
 *          Alias of `LOGFLN_WARNING` function.
 *
 *      LOG_PERROR_WN(const char* str);
 *
 *          Alias of `LOG_PERROR_WARNING` function.
 *
 *      LOG_PERRORF_WN(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_WARNING` function.
 *
 *
 *      LOG_ER(const char* str);
 *
 *          Alias of `LOG_ERROR` function.
 *
 *      LOGLN_ER(const char* str);
 *
 *          Alias of `LOGLN_ERROR` function.
 *
 *      LOGF_ER(const char* format, ...);
 *
 *          Alias of `LOGF_ERROR` function.
 *
 *      LOGFLN_ER(const char* format, ...);
 *
 *          Alias of `LOGFLN_ERROR` function.
 *
 *      LOG_PERROR_ER(const char* str);
 *
 *          Alias of `LOG_PERROR_ERROR` function.
 *
 *      LOG_PERRORF_ER(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_ERROR` function.
 *
 *
 *      LOG_CR(const char* str);
 *
 *          Alias of `LOG_CRITICAL` function.
 *
 *      LOGLN_CR(const char* str);
 *
 *          Alias of `LOGLN_CRITICAL` function.
 *
 *      LOGF_CR(const char* format, ...);
 *
 *          Alias of `LOGF_CRITICAL` function.
 *
 *      LOGFLN_CR(const char* format, ...);
 *
 *          Alias of `LOGFLN_CRITICAL` function.
 *
 *      LOG_PERROR_CR(const char* str);
 *
 *          Alias of `LOG_PERROR_CRITICAL` function.
 *
 *      LOG_PERRORF_CR(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_CRITICAL` function.
 *
 *
 *      LOG_FT(const char* str);
 *
 *          Alias of `LOG_FATAL` function.
 *
 *      LOGLN_FT(const char* str);
 *
 *          Alias of `LOGLN_FATAL` function.
 *
 *      LOGF_FT(const char* format, ...);
 *
 *          Alias of `LOGF_FATAL` function.
 *
 *      LOGFLN_FT(const char* format, ...);
 *
 *          Alias of `LOGFLN_FATAL` function.
 *
 *      LOG_PERROR_FT(const char* str);
 *
 *          Alias of `LOG_PERROR_FATAL` function.
 *
 *      LOG_PERRORF_FT(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_FATAL` function.
 *
 *
 *      "log_level" Functions Names Aliases (if enabled)
 *      ------------------------------------------------
 *
 *      TRACE(const char* str);
 *
 *          Alias of `LOG_TRACE` function.
 *
 *      TRACELN(const char* str);
 *
 *          Alias of `LOGLN_TRACE` function.
 *
 *      TRACEF(const char* format, ...);
 *
 *          Alias of `LOGF_TRACE` function.
 *
 *      TRACEFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_TRACE` function.
 *
 *
 *      DEBUG(const char* str);
 *
 *          Alias of `LOG_DEBUG` function.
 *
 *      DEBUGLN(const char* str);
 *
 *          Alias of `LOGLN_DEBUG` function.
 *
 *      DEBUGF(const char* format, ...);
 *
 *          Alias of `LOGF_DEBUG` function.
 *
 *      DEBUGFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_DEBUG` function.
 *
 *
 *      EXTRA(const char* str);
 *
 *          Alias of `LOG_EXTRA` function.
 *
 *      EXTRALN(const char* str);
 *
 *          Alias of `LOGLN_EXTRA` function.
 *
 *      EXTRAF(const char* format, ...);
 *
 *          Alias of `LOGF_EXTRA` function.
 *
 *      EXTRAFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_EXTRA` function.
 *
 *
 *      INFO(const char* str);
 *
 *          Alias of `LOG_INFO` function.
 *
 *      INFOLN(const char* str);
 *
 *          Alias of `LOGLN_INFO` function.
 *
 *      INFOF(const char* format, ...);
 *
 *          Alias of `LOGF_INFO` function.
 *
 *      INFOFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_INFO` function.
 *
 *
 *      HEADER(const char* str);
 *
 *          Alias of `LOG_HEADER` function.
 *
 *      HEADERLN(const char* str);
 *
 *          Alias of `LOG_HEADER` function.
 *
 *      HEADERF(const char* format, ...);
 *
 *          Alias of `LOGF_HEADER` function.
 *
 *      HEADERFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_HEADER` function.
 *
 *
 *      SUCCESS(const char* str);
 *
 *          Alias of `LOG_SUCCESS` function.
 *
 *      SUCCESSLN(const char* str);
 *
 *          Alias of `LOGLN_SUCCESS` function.
 *
 *      SUCCESSF(const char* format, ...);
 *
 *          Alias of `LOGF_SUCCESS` function.
 *
 *      SUCCESSFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_SUCCESS` function.
 *
 *
 *      MONEY(const char* str);
 *
 *          Alias of `LOG_MONEY` function.
 *
 *      MONEYLN(const char* str);
 *
 *          Alias of `LOGLN_MONEY` function.
 *
 *      MONEYF(const char* format, ...);
 *
 *          Alias of `LOGF_MONEY` function.
 *
 *      MONEYFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_MONEY` function.
 *
 *
 *      INPUT(const char* str);
 *
 *          Alias of `LOG_INPUT` function.
 *
 *      INPUTLN(const char* str);
 *
 *          Alias of `LOGLN_INPUT` function.
 *
 *      INPUTF(const char* format, ...);
 *
 *          Alias of `LOGF_INPUT` function.
 *
 *      INPUTFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_INPUT` function.
 *
 *
 *      WARNING(const char* str);
 *
 *          Alias of `LOG_WARNING` function.
 *
 *      WARNINGLN(const char* str);
 *
 *          Alias of `LOGLN_WARNING` function.
 *
 *      WARNINGF(const char* format, ...);
 *
 *          Alias of `LOGF_WARNING` function.
 *
 *      WARNINGFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_WARNING` function.
 *
 *      WARNING_PERROR(const char* str);
 *
 *          Alias of `LOG_PERROR_WARNING` function.
 *
 *      WARNING_PERRORF(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_WARNING` function.
 *
 *
 *      ERROR(const char* str);
 *
 *          Alias of `LOG_ERROR` function.
 *
 *      ERRORLN(const char* str);
 *
 *          Alias of `LOGLN_ERROR` function.
 *
 *      ERRORF(const char* format, ...);
 *
 *          Alias of `LOGF_ERROR` function.
 *
 *      ERRORFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_ERROR` function.
 *
 *      ERROR_PERROR(const char* str);
 *
 *          Alias of `LOG_PERROR_ERROR` function.
 *
 *      ERROR_PERRORF(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_ERROR` function.
 *
 *
 *      CRITICAL(const char* str);
 *
 *          Alias of `LOG_CRITICAL` function.
 *
 *      CRITICALLN(const char* str);
 *
 *          Alias of `LOGLN_CRITICAL` function.
 *
 *      CRITICALF(const char* format, ...);
 *
 *          Alias of `LOGF_CRITICAL` function.
 *
 *      CRITICALFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_CRITICAL` function.
 *
 *      CRITICAL_PERROR(const char* str);
 *
 *          Alias of `LOG_PERROR_CRITICAL` function.
 *
 *      CRITICAL_PERRORF(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_CRITICAL` function.
 *
 *
 *      FATAL(const char* str);
 *
 *          Alias of `LOG_FATAL` function.
 *
 *      FATALLN(const char* str);
 *
 *          Alias of `LOGLN_FATAL` function.
 *
 *      FATALF(const char* format, ...);
 *
 *          Alias of `LOGF_FATAL` function.
 *
 *      FATALFLN(const char* format, ...);
 *
 *          Alias of `LOGFLN_FATAL` function.
 *
 *      FATAL_PERROR(const char* str);
 *
 *          Alias of `LOG_PERROR_FATAL` function.
 *
 *      FATAL_PERRORF(const char* format, ...);
 *
 *          Alias of `LOG_PERRORF_FATAL` function.
 */

// Include guard.
#pragma once


// Standard libraries.

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

#ifdef WIN32
    #define NEWLINE "\r\n"
#else
    #define NEWLINE "\n"
#endif


// Macros.

/**
 *  ANZI Terminal Control Codes
 *  ===========================
 *
 *  Modifiers
 *  ---------
 *
 *  `C_RESET` resets the terminal colors back to normal.
 *  `C_BOLD` makes text bold.
 */

#ifndef C_RESET
    /**
     *  ANZI terminal code for "reset". Resets the terminal back to default
     *  setttings.
     */
    #define C_RESET             "\x1b[0m"
#endif

#ifndef C_BOLD
    /**
     *  ANZI terminal code for "bold". Uses bold font.
     */
    #define C_BOLD              "\x1b[1m"
#endif


/**
 *  3-Bit Colors
 *  ------------
 *
 *  `C_<color>` sets the terminal foreground color to <color>.
 *  `C_B_<color>` sets the terminal background color to <color>.
 */

#ifndef C_BLACK
    /**
     *  ANZI terminal code for black foreground color.
     */
    #define C_BLACK            "\x1b[30m"
#endif

#ifndef C_RED
    /**
     *  ANZI terminal code for red foreground color.
     */
    #define C_RED              "\x1b[31m"
#endif

#ifndef C_GREEN
    /**
     *  ANZI terminal code for green foreground color.
     */
    #define C_GREEN            "\x1b[32m"
#endif

#ifndef C_YELLOW
    /**
     *  ANZI terminal code for yellow foreground color.
     */
    #define C_YELLOW           "\x1b[33m"
#endif

#ifndef C_BLUE
    /**
     *  ANZI terminal code for blue foreground color.
     */
    #define C_BLUE             "\x1b[34m"
#endif

#ifndef C_MAGENTA
    /**
     *  ANZI terminal code for magenta foreground color.
     */
    #define C_MAGENTA          "\x1b[35m"
#endif

#ifndef C_CYAN
    /**
     *  ANZI terminal code for cyan foreground color.
     */
    #define C_CYAN             "\x1b[36m"
#endif

#ifndef C_WHITE
    /**
     *  ANZI terminal code for white foreground color.
     */
    #define C_WHITE            "\x1b[37m"
#endif

#ifndef C_B_BLACK
    /**
     *  ANZI terminal code for black background color.
     */
    #define C_B_BLACK          "\x1b[40m"
#endif

#ifndef C_B_RED
    /**
     *  ANZI terminal code for red background color.
     */
    #define C_B_RED            "\x1b[41m"
#endif

#ifndef C_B_GREEN
    /**
     *  ANZI terminal code for green background color.
     */
    #define C_B_GREEN          "\x1b[42m"
#endif

#ifndef C_B_YELLOW
    /**
     *  ANZI terminal code for yellow background color.
     */
    #define C_B_YELLOW         "\x1b[43m"
#endif

#ifndef C_B_BLUE
    /**
     *  ANZI terminal code for blue background color.
     */
    #define C_B_BLUE           "\x1b[44m"
#endif

#ifndef C_B_MAGENTA
    /**
     *  ANZI terminal code for magenta background color.
     */
    #define C_B_MAGENTA        "\x1b[45m"
#endif

#ifndef C_B_CYAN
    /**
     *  ANZI terminal code for cyan background color.
     */
    #define C_B_CYAN           "\x1b[46m"
#endif

#ifndef C_B_WHITE
    /**
     *  ANZI terminal code for white background color.
     */
    #define C_B_WHITE          "\x1b[47m"
#endif


/**
 *  4-Bit Colors
 *  ------------
 *
 *  `C_BR_<color>` sets the terminal foreground color to bright <color>.
 *  `C_B_BR_<color>` sets the terminal background color to bright <color>.
 */

#ifndef C_BR_BLACK
    /**
     *  ANZI terminal code for bright black foreground color.
     */
    #define C_BR_BLACK         "\x1b[90m"
#endif

#ifndef C_BR_RED
    /**
     *  ANZI terminal code for bright red foreground color.
     */
    #define C_BR_RED           "\x1b[91m"
#endif

#ifndef C_BR_GREEN
    /**
     *  ANZI terminal code for bright green foreground color.
     */
    #define C_BR_GREEN         "\x1b[92m"
#endif

#ifndef C_BR_YELLOW
    /**
     *  ANZI terminal code for bright yellow foreground color.
     */
    #define C_BR_YELLOW        "\x1b[93m"
#endif

#ifndef C_BR_BLUE
    /**
     *  ANZI terminal code for bright blue foreground color.
     */
    #define C_BR_BLUE          "\x1b[94m"
#endif

#ifndef C_BR_MAGENTA
    /**
     *  ANZI terminal code for bright magenta foreground color.
     */
    #define C_BR_MAGENTA       "\x1b[95m"
#endif

#ifndef C_BR_CYAN
    /**
     *  ANZI terminal code for bright cyan foreground color.
     */
    #define C_BR_CYAN          "\x1b[96m"
#endif

#ifndef C_BR_WHITE
    /**
     *  ANZI terminal code for bright white foreground color.
     */
    #define C_BR_WHITE         "\x1b[97m"
#endif

#ifndef C_B_BR_BLACK
    /**
     *  ANZI terminal code for bright black background color.
     */
    #define C_B_BR_BLACK       "\x1b[100m"
#endif

#ifndef C_B_BR_RED
    /**
     *  ANZI terminal code for bright red background color.
     */
    #define C_B_BR_RED         "\x1b[101m"
#endif

#ifndef C_B_BR_GREEN
    /**
     *  ANZI terminal code for bright green background color.
     */
    #define C_B_BR_GREEN       "\x1b[102m"
#endif

#ifndef C_B_BR_YELLOW
    /**
     *  ANZI terminal code for bright yellow background color.
     */
    #define C_B_BR_YELLOW      "\x1b[103m"
#endif

#ifndef C_B_BR_BLUE
    /**
     *  ANZI terminal code for bright blue background color.
     */
    #define C_B_BR_BLUE        "\x1b[104m"
#endif

#ifndef C_B_BR_MAGENTA
    /**
     *  ANZI terminal code for bright magenta background color.
     */
    #define C_B_BR_MAGENTA     "\x1b[105m"
#endif

#ifndef C_B_BR_CYAN
    /**
     *  ANZI terminal code for bright cyan background color.
     */
    #define C_B_BR_CYAN        "\x1b[106m"
#endif

#ifndef C_B_BR_WHITE
    /**
     *  ANZI terminal code for bright white background color.
     */
    #define C_B_BR_WHITE       "\x1b[107m"
#endif


/**
 *  8-bit Color Codes
 *  -----------------
 *
 *  `C_8BIT(<n>)` is used for foreground colors.
 *  `C_B_8BIT(<n>)` is used for background colors.
 *
 *  `C_8BIT(<n>)` accepts a decimal number between 0 and 255.
 *  `C_B_8BIT(<n>)` accepts a decimal number between 0 and 255.
 *
 *  0 - 7 represent standard 3-bit colors.
 *  8 - 15 represent standard 4-bit bright colors.
 *  16 - 51 represent extended colors.
 *  <extended color number> + 36 will lighten color.
 *  232 - 255 represent grayscale colors. 
 *
 *  Argument must be in decimal.
 */

#ifndef C_8BIT
    /**
     *  const char* C_8BIT(uint_8 n);
     *
     *  Convert given integer to a ANZI 8-bit color code for foreground color.
     *
     *  0 -7 represent standard 3-bit colors.
     *
     *  8-15 represent standard 4-bit colors.
     *
     *  16 - 51 represent extended colors.
     *
     *  <extended-color> + 36 will lighten color.
     *
     *  232 - 255 represent grayscale colors.
     *
     *  This function is a macro and does not validate that the input parameter
     *  is an integer or that it is between 0 and 255. Argument must be in
     *  decimal.
     *
     *  @param  n       Positive integer between 0 and 255 representing ANZI
     *                  color code.
     *  @return char*   ANZI color code string.
     */
    #define C_8BIT(n)           "\x1b[38;5;" #n "m"
#endif

#ifndef C_B_8BIT
    /**
     *  const char* C_B_8BIT(uint_8 n);
     *
     *  Convert given integer to a ANZI 8-bit color code for background color.
     *
     *  0 -7 represent standard 3-bit colors.
     *
     *  8-15 represent standard 4-bit colors.
     *
     *  16 - 51 represent extended colors.
     *
     *  <extended-color> + 36 will lighten color.
     *
     *  232 - 255 represent grayscale colors.
     *
     *  This function is a macro and does not validate that the input parameter
     *  is an integer or that it is between 0 and 255. Argument must be in
     *  decimal.
     *
     *  @param  n       Positive integer between 0 and 255 representing ANZI
     *                  color code.
     *  @return char*   ANZI color code string.
     */
    #define C_B_8BIT(n) "\x1b[48;5;" #n "m"
#endif


/**
 *  24-bit Color Codes
 *  ------------------
 *
 *  24-bit color codes use the traditional `red, green, blue` color model.
 *
 *  `C_24BIT(<r>, <g>, <b>)` is used for foreground colors.
 *
 *  `C_B_24BIT(<r>, <g>, <b>)` is used for background colors.
 *
 *  `C_RBG(<r>, <g>, <b>)` is an alias of `C_24BIT(<r>, <g>, <b>)`.
 *
 *  `C_B_RBG(<r>, <g>, <b>)` is an alias of `C_B_24BIT(<r>, <g>, <b>)`.
 *
 *  `C_24BIT(<r>, <g>, <b>)` accepts a decimal number between 0 and 255 for
 *  <r>, <g>, and <b> parameters.
 *
 *  `C_B_24BIT(<r>, <g>, <b>)` accepts a decimal number between 0 and 255 for
 *  <r>, <g>, and <b> parameters.
 *
 *  0 represents no color (i.e. black) and 255 represents the most of that
 *  color (i.e., most the red for the <r> parameter, the most green for the <g>
 *  parameter, and the most blue for the <b> parameter).
 *
 *  Arguments must be in decimal.
 */

#ifndef C_24BIT
    /**
     *  const char* C_24BIT(uint_8 red, uint_8 green, uint_8 blue);
     *
     *  Convert given red, green, blue color values to a ANZI foreground color.
     *
     *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
     *  amount of blue.
     *
     *  This function is a macro and does not validate that the input
     *  parameters are integers or that their values are between 0 and 255.
     *  Arguments must be in decimal.
     *
     *  @param  red     Positive integer between 0 and 255 representing amount
     *                  of red.
     *  @param  green   Positive integer between 0 and 255 representing amount
     *                  of green.
     *  @param  blue    Positive integer between 0 and 255 representing amount
     *                  of blue.
     *  @return char*   ANZI color code string.
     */
    #define C_24BIT(red, green, blue)    "\x1b[38;2;" #red ";" #green ";" #blue "m"
#endif

#ifndef C_RGB
    /**
     *  const char* C_24BIT(uint_8 red, uint_8 green, uint_8 blue);
     *
     *  Alias of `C_24BIT()`.
     *
     *  Convert given red, green, blue color values to a ANZI foreground color.
     *
     *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
     *  amount of blue.
     *
     *  This function is a macro and does not validate that the input
     *  parameters are integers or that their values are between 0 and 255.
     *  Arguments must be in decimal.
     *
     *  @param  red     Positive integer between 0 and 255 representing amount
     *                  of red.
     *  @param  green   Positive integer between 0 and 255 representing amount
     *                  of green.
     *  @param  blue    Positive integer between 0 and 255 representing amount
     *                  of blue.
     *  @return char*   ANZI color code string.
     */
    #define C_RGB(red, green, blue)      C_24BIT(red, green, blue)
#endif

#ifndef C_B_24BIT
    /**
     *  const char* C_B_24BIT(uint_8 red, uint_8 green, uint_8 blue);
     *
     *  Convert given red, green, blue color values to a ANZI background color.
     *
     *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
     *  amount of blue.
     *
     *  This function is a macro and does not validate that the input
     *  parameters are integers or that their values are between 0 and 255.
     *  Arguments must be in decimal.
     *
     *  @param  red     Positive integer between 0 and 255 representing amount
     *                  of red.
     *  @param  green   Positive integer between 0 and 255 representing amount
     *                  of green.
     *  @param  blue    Positive integer between 0 and 255 representing amount
     *                  of blue.
     *  @return char*   ANZI color code string.
     */
    #define C_B_24BIT(red, green, blue)  "\x1b[48;2;" #red ";" #green ";" #blue "m"
#endif

#ifndef C_B_RGB
    /**
     *  const char* C_B_RGB(uint_8 red, uint_8 green, uint_8 blue);
     *
     *  Alias of `C_B_24BIT()`.
     *
     *  Convert given red, green, blue color values to a ANZI background color.
     *
     *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
     *  amount of blue.
     *
     *  This function is a macro and does not validate that the input
     *  parameters are integers or that their values are between 0 and 255.
     *  Arguments must be in decimal.
     *
     *  @param  red     Positive integer between 0 and 255 representing amount
     *                  of red.
     *  @param  green   Positive integer between 0 and 255 representing amount
     *                  of green.
     *  @param  blue    Positive integer between 0 and 255 representing amount
     *                  of blue.
     *  @return char*   ANZI color code string.
     */
    #define C_B_RGB(red, green, blue)    C_B_24BIT(red, green, blue)
#endif


/**
 *  Other Colors
 *  ------------
 *
 *  These colors are just extra predefined colors.
 */

#ifndef C_ORANGE
    /**
     *  ANZI terminal code for orange foreground color.
     */
    #define C_ORANGE            C_24BIT(253, 198, 21)
#endif

#ifndef C_B_ORANGE
    /**
     *  ANZI terminal code for orange background color.
     */
    #define C_B_ORANGE          C_B_24BIT(253, 198, 21)
#endif

#ifndef C_GRAY
    /**
     *  ANZI terminal code for gray foreground color.
     */
    #define C_GRAY              C_24BIT(128, 128, 128)
#endif

#ifndef C_B_GRAY
    /**
     *  ANZI terminal code for gray background color.
     */
    #define C_B_GRAY            C_B_24BIT(128, 128, 128)
#endif

#ifndef C_DARK_GRAY
    /**
     *  ANZI terminal code for dark gray foreground color.
     */
    #define C_DARK_GRAY         C_24BIT(64, 64, 64)
#endif

#ifndef C_B_DARK_GRAY
    /**
     *  ANZI terminal code for dark gray background color.
     */
    #define C_B_DARK_GRAY       C_B_24BIT(64, 64, 64)
#endif


/**
 *  Color Palettes
 *  ==============
 *
 *  Color palettes are the colors assigned to program elements. Users can
 *  create their own palettes by defining MACROS that use other colors.
 *  For example:
 *
 *      #define MY_UI_COLOR C_RGB(128, 228, 288)
 *
 *  These colors are for the logging headers and logging elements.
 */

#ifndef C_TRACE
    /**
     *  ANZI color code for "trace" logging elements. Defaults to bright black.
     */
    #define C_TRACE     C_DARK_GRAY
#endif

#ifndef C_DEBUG
    /**
     *  ANZI color code for "debug" logging elements. Defaults to cyan.
     */
    #define C_DEBUG     C_CYAN
#endif

#ifndef C_EXTRA
    /**
     *  ANZI color code for "extra" logging elements. Defaults to bright black.
     */
    #define C_EXTRA     C_DARK_GRAY
#endif

#ifndef C_INFO
    /**
     *  ANZI color code for "info" logging elements. Defaults to bright blue.
     */
    #define C_INFO      C_BR_BLUE
#endif

#ifndef C_HEADER
    /**
     *  ANZI color code for "header" logging elements. Defaults to bold bright
     *  yellow.
     */
    #define C_HEADER    C_BOLD C_BR_YELLOW
#endif

#ifndef C_SUCCESS
    /**
     *  ANZI color code for "success" logging elements. Defaults to green.
     */
    #define C_SUCCESS   C_GREEN
#endif

#ifndef C_MONEY
    /**
     *  ANZI color code for "money" logging elements. Defaults to bold green.
     */
    #define C_MONEY     C_BOLD C_GREEN
#endif

#ifndef C_INPUT
    /**
     *  ANZI color code for "input" logging elements. Defaults to bright
     *  magenta.
     */
    #define C_INPUT     C_BR_MAGENTA
#endif

#ifndef C_WARNING
    /**
     *  ANZI color code for "warning" logging elements. Defaults to orange.
     */
    #define C_WARNING   C_ORANGE
#endif

#ifndef C_ERROR
    /**
     *  ANZI color code for "error" logging elements. Defaults to bright red.
     */
    #define C_ERROR     C_BR_RED
#endif

#ifndef C_CRITICAL
    /**
     *  ANZI color code for "critical" logging elements. Defaults to bold
     *  bright red.
     */
    #define C_CRITICAL  C_BOLD C_BR_RED
#endif

#ifndef C_FATAL
    /**
     *  ANZI color code for "fatal" logging elements. Defaults to bold bright
     *  red.
     */
    #define C_FATAL     C_BOLD C_BR_RED
#endif


/**
 *  Color Palette Short Aliases
 *  ---------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  Alias of `C_TRACE`.
     *
     *  ANZI color code for "trace" logging elements. Defaults to bright black.
     */
    #define C_TRC       C_TRACE

    /**
     *  Alias of `C_DEBUG`.
     *
     *  ANZI color code for "debug" logging elements. Defaults to cyan.
     */
    #define C_DBG       C_DEBUG

    /**
     *  Alias of `C_EXTRA`.
     *
     *  ANZI color code for "extra" logging elements. Defaults to bright black.
     */
    #define C_EXT       C_EXTRA

    /**
     *  Alias of `C_INFO`.
     *
     *  ANZI color code for "info" logging elements. Defaults to blue.
     */
    #define C_INF       C_INFO

    /**
     *  Alias of `C_HEADER`.
     *
     *  ANZI color code for "header" logging elements. Defaults to bold yellow.
     */
    #define C_HEAD      C_HEADER

    /**
     *  Alias of `C_SUCCESS`.
     *
     *  ANZI color code for "success" logging elements. Defaults to green.
     */
    #define C_SUC       C_SUCCESS

    /**
     *  Alias of `C_MONEY`.
     *
     *  ANZI color code for "money" logging elements. Defaults to bold green.
     */
    #define C_MON       C_MONEY

    /**
     *  Alias of `C_MONEY`.
     *
     *  ANZI color code for "money" logging elements. Defaults to bold green.
     */
    #define C_MNY       C_MONEY

    /**
     *  Alias of `C_INPUT`.
     *
     *  ANZI color code for "input" logging elements. Defaults to magenta.
     */
    #define C_IN        C_INPUT

    /**
     *  Alias of `C_WARNING`.
     *
     *  ANZI color code for "warning" logging elements. Defaults to orange.
     */
    #define C_WARN      C_WARNING

    /**
     *  Alias of `C_ERROR`.
     *
     *  ANZI color code for "error" logging elements. Defaults to red.
     */
    #define C_ERR       C_ERROR

    /**
     *  Alias of `C_CRITICAL`.
     *
     *  ANZI color code for "critical" logging elements. Defaults to bold red.
     */
    #define C_CRIT      C_CRITICAL

    /**
     *  Alias of `C_FATAL`.
     *
     *  ANZI color code for "fatal" logging elements. Defaults to bold red.
     */
    #define C_FAT       C_FATAL
#endif


/**
 *  Color Palette Shorter Aliases
 *  -----------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  Alias of `C_TRACE`.
     *
     *  ANZI color code for "trace" logging elements. Defaults to bright black.
     */
    #define C_TR        C_TRACE

    /**
     *  Alias of `C_DEBUG`.
     *
     *  ANZI color code for "debug" logging elements. Defaults to cyan.
     */
    #define C_DB        C_DEBUG

    /**
     *  Alias of `C_EXTRA`.
     *
     *  ANZI color code for "extra" logging elements. Defaults to bright black.
     */
    #define C_EX        C_EXTRA

    /**
     *  Alias of `C_INFO`.
     *
     *  ANZI color code for "info" logging elements. Defaults to blue.
     */
    #define C_IF        C_INFO

    /**
     *  Alias of `C_HEADER`.
     *
     *  ANZI color code for "header" logging elements. Defaults to bold yellow.
     */
    #define C_HD        C_HEADER

    /**
     *  Alias of `C_SUCCESS`.
     *
     *  ANZI color code for "success" logging elements. Defaults to green.
     */
    #define C_SC        C_SUCCESS

    /**
     *  Alias of `C_MONEY`.
     *
     *  ANZI color code for "money" logging elements. Defaults to bold green.
     */
    #define C_MN        C_MONEY

    /**
     *  Alias of `C_MONEY`.
     *
     *  ANZI color code for "money" logging elements. Defaults to bold green.
     */
    #define C_MY        C_MONEY

    /**
     *  Alias of `C_INPUT`.
     *
     *  ANZI color code for "input" logging elements. Defaults to magenta.
     */
    #define C_IN        C_INPUT

    /**
     *  Alias of `C_WARNING`.
     *
     *  ANZI color code for "warning" logging elements. Defaults to orange.
     */
    #define C_WN        C_WARNING

    /**
     *  Alias of `C_ERROR`.
     *
     *  ANZI color code for "error" logging elements. Defaults to red.
     */
    #define C_ER        C_ERROR

    /**
     *  Alias of `C_CRITICAL`.
     *
     *  ANZI color code for "critical" logging elements. Defaults to bold red.
     */
    #define C_CR        C_CRITICAL

    /**
     *  Alias of `C_FATAL`.
     *
     *  ANZI color code for "fatal" logging elements. Defaults to bold red.
     */
    #define C_FT        C_FATAL
#endif


/**
 *  Logging Line Headers Separator
 *  ==============================
 *
 *  The separator will be used to separate elements of the log line header. It
 *  defaults to a space, but can be changed using the Clog Configuration
 *  header. For example:
 *
 *      Default output: "2025-04-29T06:49:16Z [DEBUG] file:function:114: This is a debug message."
 *
 *  If you change the separator to ";":
 *
 *      Output: "2025-04-29T06:49:16Z;[DEBUG];file:function:114:;This is a debug message."
 *
 *  Or you can change the separator to " -- ":
 *
 *      Output: "2025-04-29T06:49:16Z -- [DEBUG] -- file:function:114: -- This is a debug message."
 */

#ifndef CLOG_LINE_HEADER_SEP
    /**
     *  Separator for log line header elements including separator between
     *  timestamp, log level symbol, trace information, and log message.
     *  Defaults to a single space.
     */
    #define CLOG_LINE_HEADER_SEP            " "
#endif


/**
 *  Logging Level Symbols
 *  =====================
 *
 *  These are the line headers for log-like printing and logging and are
 *  prepended to user strings when the appropriate function is used.
 *
 *  Options for use in the Clog Configuration header include:
 *
 *      CLOG_LEVEL_SYMS_NONE            Disable log level symbols.
 *
 *          Output: "2025-04-29T06:49:16Z This is an info message."
 *
 *      CLOG_LEVEL_SYMS_WORDS           Use log level names (in all CAPS) as
 *                                      symbols surrounded by brackets.
 *
 *          Output: "2025-04-29T06:49:16Z [INFO] This is an info message."
 *
 *      CLOG_LEVEL_SYMS_LETTERS         Use single letter log level symbols
 *                                      surrounded by brackets.
 *
 *          Output: "2025-04-29T06:49:16Z [I] This is an info message."
 *
 *      CLOG_LEVEL_SYMS_ONE_CHAR        Use single character symbols surrounded
 *                                      by brackets.
 *
 *          Output: "2025-04-29T06:49:16Z [*] This is an info message."
 *
 *      CLOG_LEVEL_SYMS_THREE_CHAR      Use three-charactor symbols surrounded
 *                                      by brackets.
 *
 *          Output: "2025-04-29T06:49:16Z [***] This is an info message."
 *
 *      CLOG_LEVEL_SYMS_DEFAULT         Use the default symbols.
 *
 *          Output: "2025-04-29T06:49:16Z [*] This is an info message."
 *
 */

#ifndef CLOG_LEVEL_SYMS_NONE
    /**
     *  Clog line header log level symbol option "none". Disable log level
     *  symbols.
     */
    #define CLOG_LEVEL_SYMS_NONE        0
#endif

#ifndef CLOG_LEVEL_SYMS_WORDS
    /**
     *  Clog line header log level symbol option "words". Use words in all-caps
     *  surrounded by brackets as log level symbols. E.g., `[DEBUG]` or
     *  `[INFO]`.
     */
    #define CLOG_LEVEL_SYMS_WORDS       1
#endif

#ifndef CLOG_LEVEL_SYMS_LETTERS
    /**
     *  Clog line header log level symbol option "letters". Use single
     *  character letters surrounded by brackets as log level symbols. E.g.,
     *  `[D]` or `[I]`.
     */
    #define CLOG_LEVEL_SYMS_LETTERS     2
#endif

#ifndef CLOG_LEVEL_SYMS_ONE_CHAR
    /**
     *  Clog line header log level symbol option "one-char". Use single
     *  character ASCII symbols surrounded by brackets as log level symbols.
     *  E.g., `[*]` or `[+]`.
     */
    #define CLOG_LEVEL_SYMS_ONE_CHAR    3
#endif

#ifndef CLOG_LEVEL_SYMS_THREE_CHAR
    /**
     *  Clog line header log level symbol option "three-char". Use three-
     *  character ASCII symbols surrounded by brackets as log level symbols.
     *  E.g., `[***]` or `[-!-]`.
     */
    #define CLOG_LEVEL_SYMS_THREE_CHAR  4
#endif

#ifndef CLOG_LEVEL_SYMS_EMOJIS
    /**
     *  Clog line header log level symbol option "emojis". Uses emojis
     *  surrounded by brackets as log level symbols. E.g., `[ 🪲 ] or `[ ⚡ ]`.
     */
    #define CLOG_LEVEL_SYMS_EMOJIS      5
#endif

#ifndef CLOG_LEVEL_SYMS_DEFAULT
    /**
     *  Clog line header log level symbol option "default". Uses a combination
     *  of one-character ASCII symbols and words surrounded by brackets as log
     *  level symbols. E.g., `[DEBUG] or `[*]`. Default option.
     */
    #define CLOG_LEVEL_SYMS_DEFAULT     6
#endif

#ifndef CLOG_LEVEL_SYMS
    /**
     *  Clog line header log level symbol option selection. May be one of the
     *  following values:
     *
     *      CLOG_LEVEL_SYMS_NONE
     *      CLOG_LEVEL_SYMS_WORDS
     *      CLOG_LEVEL_SYMS_LETTERS
     *      CLOG_LEVEL_SYMS_ONE_CHAR
     *      CLOG_LEVEL_SYMS_THREE_CHAR
     *      CLOG_LEVEL_SYMS_EMOJIS
     *      CLOG_LEVEL_SYMS_DEFAULT         (default)
     */
    #define CLOG_LEVEL_SYMS             CLOG_LEVEL_SYMS_DEFAULT
#endif

#if CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_NONE

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              ""
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              ""
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              ""
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               ""
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             ""
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            ""
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              ""
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              ""
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            ""
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              ""
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           ""
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              ""
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_WORDS

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              "[TRACE]"
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              "[DEBUG]"
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              "[EXTRA]"
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               "[INFO]"
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             "[HEADER]"
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            "[SUCCESS]"
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              "[MONEY]"
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              "[INPUT]"
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            "[WARNING]"
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              "[ERROR]"
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           "[CRITICAL]"
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              "[FATAL]"
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_LETTERS

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              "[T]"
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              "[D]"
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              "[X]"
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               "[I]"
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             "[H]"
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            "[S]"
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              "[M]"
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              "[N]"
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            "[W]"
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              "[E]"
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           "[C]"
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              "[F]"
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_ONE_CHAR

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              "[&]"
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              "[%]"
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              "[.]"
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               "[*]"
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             "[#]"
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            "[+]"
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              "[$]"
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              "[?]"
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            "[~]"
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              "[-]"
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           "[!]"
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              "[x]"
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_THREE_CHAR

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              "[ / ]"
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              "[>0<]"
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              "[...]"
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               "[ * ]"
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             "[***]"
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            "[ + ]"
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              "[$$$]"
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              "[ ? ]"
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            "[ ! ]"
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              "[-!-]"
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           "[!!!]"
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              "[x x]"
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_EMOJIS

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              " 📋 "
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              " 🪲 "
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              " 🔍 "
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               " ℹ️ "
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             " 😀 "
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            " ✅ "
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              " 🤑 "
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              " ❓ "
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            " ⚠️ "
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              " ⛔ "
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           " ⚡ "
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              " 💀 "
    #endif


#elif CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_DEFAULT

    #ifndef CLOG_SYM_TRACE
        /**
         *  Symbol for line header for "trace" logs.
         */
        #define CLOG_SYM_TRACE              "[TRACE]"
    #endif

    #ifndef CLOG_SYM_DEBUG
        /**
         *  Symbol for line header for "debug" logs.
         */
        #define CLOG_SYM_DEBUG              "[DEBUG]"
    #endif

    #ifndef CLOG_SYM_EXTRA
        /**
         *  Symbol for line header for "extra" logs.
         */
        #define CLOG_SYM_EXTRA              "[.]"
    #endif

    #ifndef CLOG_SYM_INFO
        /**
         *  Symbol for line header for "info" logs.
         */
        #define CLOG_SYM_INFO               "[*]"
    #endif

    #ifndef CLOG_SYM_HEADER
        /**
         *  Symbol for line header for "header" logs.
         */
        #define CLOG_SYM_HEADER             "[***]"
    #endif

    #ifndef CLOG_SYM_SUCCESS
        /**
         *  Symbol for line header for "success" logs.
         */
        #define CLOG_SYM_SUCCESS            "[+]"
    #endif

    #ifndef CLOG_SYM_MONEY
        /**
         *  Symbol for line header for "money" logs.
         */
        #define CLOG_SYM_MONEY              "[$]"
    #endif

    #ifndef CLOG_SYM_INPUT
        /**
         *  Symbol for line header for "input" logs.
         */
        #define CLOG_SYM_INPUT              "[?]"
    #endif

    #ifndef CLOG_SYM_WARNING
        /**
         *  Symbol for line header for "warning" logs.
         */
        #define CLOG_SYM_WARNING            "[!]"
    #endif

    #ifndef CLOG_SYM_ERROR
        /**
         *  Symbol for line header for "error" logs.
         */
        #define CLOG_SYM_ERROR              "[-]"
    #endif

    #ifndef CLOG_SYM_CRITICAL
        /**
         *  Symbol for line header for "critical" logs.
         */
        #define CLOG_SYM_CRITICAL           "[!!!]"
    #endif

    #ifndef CLOG_SYM_FATAL
        /**
         *  Symbol for line header for "fatal" logs.
         */
        #define CLOG_SYM_FATAL              "[FATAL]"
    #endif
#endif


/**
 *  Log Level Symbol Short Aliases
 *  ------------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  Alias of `CLOG_SYM_TRACE`.
     *
     *  Symbol for line header for "trace" logs.
     */
    #define CSYM_TRC       CLOG_SYM_TRACE

    /**
     *  Alias of `CLOG_SYM_DEBUG`.
     *
     *  Symbol for line header for "debug" logs.
     */
    #define CSYM_DBG       CLOG_SYM_DEBUG

    /**
     *  Alias of `CLOG_SYM_EXTRA`.
     *
     *  Symbol for line header for "extra" logs.
     */
    #define CSYM_EXT       CLOG_SYM_EXTRA

    /**
     *  Alias of `CLOG_SYM_INFO`.
     *
     *  Symbol for line header for "info" logs.
     */
    #define CSYM_INF       CLOG_SYM_INFO

    /**
     *  Alias of `CLOG_SYM_HEADER`.
     *
     *  Symbol for line header for "header" logs.
     */
    #define CSYM_HEAD      CLOG_SYM_HEADER

    /**
     *  Alias of `CLOG_SYM_SUCCESS`.
     *
     *  Symbol for line header for "success" logs.
     */
    #define CSYM_SUC       CLOG_SYM_SUCCESS

    /**
     *  Alias of `CLOG_SYM_MONEY`.
     *
     *  Symbol for line header for "money" logs.
     */
    #define CSYM_MON       CLOG_SYM_MONEY

    /**
     *  Alias of `CLOG_SYM_MONEY`.
     *
     *  Symbol for line header for "money" logs.
     */
    #define CSYM_MNY       CLOG_SYM_MONEY

    /**
     *  Alias of `CLOG_SYM_INPUT`.
     *
     *  Symbol for line header for "input" logs.
     */
    #define CSYM_IN        CLOG_SYM_INPUT

    /**
     *  Alias of `CLOG_SYM_WARNING`.
     *
     *  Symbol for line header for "warning" logs.
     */
    #define CSYM_WARN      CLOG_SYM_WARNING

    /**
     *  Alias of `CLOG_SYM_ERROR`.
     *
     *  Symbol for line header for "error" logs.
     */
    #define CSYM_ERR       CLOG_SYM_ERROR

    /**
     *  Alias of `CLOG_SYM_CRITICAL`.
     *
     *  Symbol for line header for "critical" logs.
     */
    #define CSYM_CRIT      CLOG_SYM_CRITICAL

    /**
     *  Alias of `CLOG_SYM_FATAL`.
     *
     *  Symbol for line header for "fatal" logs.
     */
    #define CSYM_FAT       CLOG_SYM_FATAL
#endif


/**
 *  Log Level Symbol Shorter Aliases
 *  --------------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  Alias of `CLOG_SYM_TRACE`.
     *
     *  Symbol for line header for "trace" logs.
     */
    #define CSYM_TR       CLOG_SYM_TRACE

    /**
     *  Alias of `CLOG_SYM_DEBUG`.
     *
     *  Symbol for line header for "debug" logs.
     */
    #define CSYM_DB       CLOG_SYM_DEBUG

    /**
     *  Alias of `CLOG_SYM_EXTRA`.
     *
     *  Symbol for line header for "extra" logs.
     */
    #define CSYM_EX       CLOG_SYM_EXTRA

    /**
     *  Alias of `CLOG_SYM_INFO`.
     *
     *  Symbol for line header for "info" logs.
     */
    #define CSYM_IF       CLOG_SYM_INFO

    /**
     *  Alias of `CLOG_SYM_HEADER`.
     *
     *  Symbol for line header for "header" logs.
     */
    #define CSYM_HD       CLOG_SYM_HEADER

    /**
     *  Alias of `CLOG_SYM_SUCCESS`.
     *
     *  Symbol for line header for "success" logs.
     */
    #define CSYM_SC       CLOG_SYM_SUCCESS

    /**
     *  Alias of `CLOG_SYM_MONEY`.
     *
     *  Symbol for line header for "money" logs.
     */
    #define CSYM_MN       CLOG_SYM_MONEY

    /**
     *  Alias of `CLOG_SYM_MONEY`.
     *
     *  Symbol for line header for "money" logs.
     */
    #define CSYM_MY       CLOG_SYM_MONEY

    /**
     *  Alias of `CLOG_SYM_INPUT`.
     *
     *  Symbol for line header for "input" logs.
     */
    #define CSYM_IN       CLOG_SYM_INPUT

    /**
     *  Alias of `CLOG_SYM_WARNING`.
     *
     *  Symbol for line header for "warning" logs.
     */
    #define CSYM_WN       CLOG_SYM_WARNING

    /**
     *  Alias of `CLOG_SYM_ERROR`.
     *
     *  Symbol for line header for "error" logs.
     */
    #define CSYM_ER       CLOG_SYM_ERROR

    /**
     *  Alias of `CLOG_SYM_CRITICAL`.
     *
     *  Symbol for line header for "critical" logs.
     */
    #define CSYM_CR       CLOG_SYM_CRITICAL

    /**
     *  Alias of `CLOG_SYM_FATAL`.
     *
     *  Symbol for line header for "fatal" logs.
     */
    #define CSYM_FT       CLOG_SYM_FATAL
#endif

#define _CSYM_TRACE     CLOG_SYM_TRACE CLOG_LINE_HEADER_SEP
#define _CSYM_DEBUG     CLOG_SYM_DEBUG CLOG_LINE_HEADER_SEP
#define _CSYM_EXTRA     CLOG_SYM_EXTRA CLOG_LINE_HEADER_SEP
#define _CSYM_INFO      CLOG_SYM_INFO CLOG_LINE_HEADER_SEP
#define _CSYM_HEADER    CLOG_SYM_HEADER CLOG_LINE_HEADER_SEP
#define _CSYM_SUCCESS   CLOG_SYM_SUCCESS CLOG_LINE_HEADER_SEP
#define _CSYM_MONEY     CLOG_SYM_MONEY CLOG_LINE_HEADER_SEP
#define _CSYM_INPUT     CLOG_SYM_INPUT CLOG_LINE_HEADER_SEP
#define _CSYM_WARNING   CLOG_SYM_WARNING CLOG_LINE_HEADER_SEP
#define _CSYM_ERROR     CLOG_SYM_ERROR CLOG_LINE_HEADER_SEP
#define _CSYM_CRITICAL  CLOG_SYM_CRITICAL CLOG_LINE_HEADER_SEP
#define _CSYM_FATAL     CLOG_SYM_FATAL CLOG_LINE_HEADER_SEP


/**
 *  "fprint" Functions
 *  ==================
 *
 *  The "fprint" series of macros are the base functions used in the other
 *  macro functions. They are for printing to a given file pointer. For this
 *  implementation, they use the `fprintf` function.
 *
 *  The first parameter of all these functions is the `FILE*` pointer (which \
 *  may be `stdout` or `stderr` or a `FILE*` to a file`) to write to.
 *
 *  There are several function-like macros available:
 *
 *      FPRINT(FILE* stream, const char* str)
 *      FPRINTLN(FILE* stream, const char* str)
 *      FPRINTF(FILE* stream, const char* format, ...)
 *      FPRINTFLN(FILE* stream, const char* format, ...)
 *      FPRINT_HEX(FILE* stream, uint8_t* buffer, size_t length)
 *      FPRINTLN_HEX(FILE* stream, uint8_t* buffer, size_t length)
 *      FPRINT_WIDE_HEX(FILE* stream, uint8_t* buffer, size_t length)
 *      FPRINTLN_WIDE_HEX(FILE* stream, uint8_t* buffer, size_t length)
 *      FPERROR(FILE* stream, char* str)
 *      FPERRORF(FILE* stream, char* format, ...)
 *
 *
 *  Examples
 *  --------
 *
 *      `FPRINT(stdout, "Hello"); printf("you");`
 *
 *          Output: `Helloyou`
 *
 *      `FPRINTLN(stdout, "Hello"); printf("you");`
 *
 *          Output: `Hello
 *                   you`.
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void FPRINT(FILE* stream, const char* str);
 *
 *  Print given string to the given file stream.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define FPRINT(stream, str) { \
    fprintf(stream, "%s", str); \
}

/**
 *  void FPRINTLN(FILE* stream, const char* str);
 *
 *  Print given string to the given file stream followed by a newline.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define FPRINTLN(stream, str) { \
    fprintf(stream, "%s\n", str); \
}

/**
 *  void FPRINTF(FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FPRINTF(stream, ...) { \
    fprintf(stream, __VA_ARGS__); \
}

/**
 *  void FPRINTFLN(FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream
 *  followed by a newline.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FPRINTFLN(stream, ...) { \
    fprintf(stream, __VA_ARGS__); \
    fprintf(stream, "\n"); \
}

/**
 *  void FPRINT_HEX(FILE* stream, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FPRINT_HEX(stream, buffer, length) { \
    for (size_t _clog_i = 0;  _clog_i < length;  ++_clog_i ) \
        fprintf(stream, "%02x", ((unsigned char*) buffer)[_clog_i]); \
}

/**
 *  void FPRINTLN_HEX(FILE* stream, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string followed by a newline.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FPRINTLN_HEX(stream, buffer, length) { \
    FPRINT_HEX(stream, buffer, length); \
    fprintf(stream, "\n"); \
}

/**
 *  void FPRINT_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FPRINT_WIDE_HEX(stream, buffer, length) { \
    for (size_t _clog_i = 0;  _clog_i < length;  ++_clog_i ) \
        fprintf(stream, "0x%02x ", ((unsigned char*) buffer)[_clog_i]); \
}

/**
 *  void FPRINTLN_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces followed by a newline.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FPRINTLN_WIDE_HEX(stream, buffer, length)  { \
    FPRINT_WIDE_HEX(stream, buffer, length); \
    fprintf(stream, "\n"); \
}

/**
 *  void FPERROR(FILE* stream, const char* str);
 *
 *  Print given string to the given file stream and then print the C error
 *  message.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define FPERROR(stream, str) { \
    FPRINT(stream, str); \
    FPRINTFLN(stream, ": %s", strerror(errno)); \
}

/**
 *  void FPERRORF(FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream
 *  followed by a C error message.
 *
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FPERRORF(stream, ...) { \
    FPRINTF(stream, __VA_ARGS__); \
    FPRINTFLN(stream, ": %s", strerror(errno)); \
}


/**
 *  "cfprint" Functions
 *  ===================
 *
 *  The "cfprint" series of macros are the base functions used in the other
 *  macro functions and are for colored printing to the given file pointer.
 *
 *  The first parameter of all these functions is the color to print the text as
 *  by prepending the string argument with the ANZI terminal color code and by
 *  resetting the color output at the end.  The second parameter is the `FILE*`
 *  pointer (which may be `stdout` or `stderr` or a `FILE*` to a file`) to
 *  write to.
 *
 *  There are several function-like macros available:
 *
 *      CFPRINT(const char* color, FILE* stream, const char* str)
 *      CFPRINTLN(const char* color, FILE* stream, const char* str)
 *      CFPRINTF(const char* color, FILE* stream, const char* format, ...)
 *      CFPRINTFLN(const char* color, FILE* stream, const char* format, ...)
 *      CFPRINT_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *      CFPRINTLN_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *      CFPRINT_WIDE_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *      CFPRINTLN_WIDE_HEX(
 *          const char* color,
 *          FILE* stream,
 *          const uint8_t* buffer,
 *          size_t length
 *      )
 *      CFPERROR(const char* color, FILE* stream, const char* str)
 *      CFPERRORF(const char* color, FILE* stream, const char* format, ...)
 *
 *
 *  Examples
 *  --------
 *
 *      `CFPRINT(C_RED, stdout, "Hello"); printf("you");`
 *
 *          Output: `\033[31mHelloyou\033[0m` (Red "Helloyou")
 *
 *      `int i = 15; CFPRINT_HEX(C_RED, stdout, &i, sizeof(int));`
 *
 *          Output: `\033[31m0f000000\033[0m`. (Red "0f000000")
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CFPRINT(const char* color, FILE* stream, const char* str);
 *
 *  Print given string to the given file stream in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define CFPRINT(color, stream, str)     FPRINT(stream, color str C_RESET);

/**
 *  void CFPRINTLN(const char* color, FILE* stream, const char* str);
 *
 *  Print given string to the given file stream followed by a newline in the
 *  given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define CFPRINTLN(color, stream, str)   FPRINT(stream, color str C_RESET "\n");

/**
 *  void CFPRINTF(const char* color, FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream in
 *  the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CFPRINTF(color, stream, ...) { \
    FPRINTF(stream, color __VA_ARGS__); \
    FPRINT(stream, C_RESET); \
}

/**
 *  void CFPRINTFLN(const char* color, FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream
 *  followed by a newline in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CFPRINTFLN(color, stream, ...) { \
    FPRINTF(stream, color __VA_ARGS__); \
    FPRINT(stream, C_RESET "\n"); \
}

/**
 *  void CFPRINT_HEX(
 *      const char* color, FILE* stream, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CFPRINT_HEX(color, stream, buffer, length) { \
    FPRINT(stream, color); \
    FPRINT_HEX(stream, buffer, length); \
    FPRINT(stream, C_RESET); \
}

/**
 *  void CFPRINTLN_HEX(
 *      const char* color, FILE* stream, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string followed by a newline
 *  in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CFPRINTLN_HEX(color, stream, buffer, length) { \
    FPRINT(stream, color); \
    FPRINT_HEX(stream, buffer, length); \
    FPRINT(stream, C_RESET "\n"); \
}

/**
 *  void CFPRINT_WIDE_HEX(
 *      const char* color, FILE* stream, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CFPRINT_WIDE_HEX(color, stream, buffer, length) { \
    FPRINT(stream, color); \
    FPRINT_WIDE_HEX(stream, buffer, length); \
    FPRINT(stream, C_RESET); \
}

/**
 *  void CFPRINTLN_WIDE_HEX(
 *      const char* color, FILE* stream, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces followed by a newline in the
 *  given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CFPRINTLN_WIDE_HEX(color, stream, buffer, length) { \
    FPRINT(stream, color); \
    FPRINT_WIDE_HEX(stream, buffer, length); \
    FPRINT(stream, C_RESET "\n"); \
}

/**
 *  void CFPERROR(const char* color, FILE* stream, const char* str);
 *
 *  Print given string to the given file stream and then print the C error
 *  message in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at then end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  str         String to print.
 */
#define CFPERROR(color, stream, str) { \
    FPRINT(stream, color str); \
    FPRINTF(stream, ": %s" C_RESET "\n", strerror(errno)); \
}

/**
 *  void CFPERRORF(const char* color, FILE* stream, const char* format, ...);
 *
 *  Print given format string and format arguments to the given file stream
 *  followed by a C error message in the given color.
 *
 *  Print the ANZI terminal codes given first, then the string and then the
 *  ANZI terminal code for reset at the end.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  stream      Pointer to file stream.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CFPERRORF(color, stream, ...) { \
    FPRINTF(stream, color __VA_ARGS__); \
    FPRINTF(stream, ": %s" C_RESET "\n", strerror(errno)); \
}


/**
 *  "print" Functions
 *  =================
 *
 *  The "print" series are for printing to standard out.
 *
 *  There are several function-like macros available:
 *
 *      PRINT(const char* str)
 *      PRINTLN(const char* str)
 *      PRINTF(const char* format, ...)
 *      PRINTFLN(const char* format, ...)
 *      PRINT_HEX(const uint8_t* buffer, size_t length)
 *      PRINTLN_HEX(const uint8_t* buffer, size_t length)
 *      PRINT_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      PRINTLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      PERROR(const char* str)
 *      PERRORF(const char* format, ...)
 *
 *
 *  Examples
 *  --------
 *
 *      `PRINT("Hello"); printf("you");`
 *
 *          Output: `Helloyou`
 *
 *      `int i = 15; PRINT_HEX(&i, sizeof(int));`
 *
 *          Output: `0f000000`.
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void PRINT(const char* str);
 *
 *  Print given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT(str)                      FPRINT(stdout, str)

/**
 *  void PRINTLN(const char* str);
 *
 *  Print given string to standard output followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN(str)                    FPRINTLN(stdout, str)

/**
 *  void PRINTF(const char* format, ...);
 *
 *  Print given format string and format arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF(...)                     FPRINTF(stdout, __VA_ARGS__)

/**
 *  void PRINTFLN(const char* format, ...);
 *
 *  Print given format string and format arguments to standard output
 *  followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN(...)                   FPRINTFLN(stdout, __VA_ARGS__)

/**
 *  void PRINT_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard output.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define PRINT_HEX(buffer, length)       FPRINT_HEX(stdout, buffer, length)

/**
 *  void PRINTLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard output
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define PRINTLN_HEX(buffer, length)     FPRINTLN_HEX(stdout, buffer, length)

/**
 *  void PRINT_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard output.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define PRINT_WIDE_HEX(buffer, length)  FPRINT_WIDE_HEX(stdout, buffer, length)

/**
 *  void PRINTLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard output followed by a
 *  newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define PRINTLN_WIDE_HEX(buffer, length) \
    FPRINTLN_WIDE_HEX(stdout, buffer, length)

/**
 *  void PERROR(const char* str);
 *
 *  Print given string to standard output and then print the C error
 *  message.
 *
 *  @param  str         String to print.
 */
#define PERROR(str)                     FPERROR(stdout, str)

/**
 *  void PERRORF(const char* format, ...);
 *
 *  Print given format string and format arguments to standard output
 *  followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PERRORF(...)                    FPERRORF(stdout, __VA_ARGS__)


/**
 *  "print_level" Functions
 *  -----------------------
 *
 *  Additionally, there are "print_level" functions which add a symbol header
 *  to each line based on the level selected.
 *
 *  ** Note: These will ALWAYS print regardless of logging level. For
 *  controlling prints using levels, see "CLOG" and "LOG" functions.
 *
 *  There are several of these function-like macros available:
 *
 *      PRINT_TRACE(const char* str)
 *      PRINTLN_TRACE(const char* str)
 *      PRINTF_TRACE(const char* format, ...)
 *      PRINTFLN_TRACE(const char* format, ...)
 *
 *      PRINT_DEBUG(const char* str)
 *      PRINTLN_DEBUG(const char* str)
 *      PRINTF_DEBUG(const char* format, ...)
 *      PRINTFLN_DEBUG(const char* format, ...)
 *
 *      PRINT_EXTRA(const char* str)
 *      PRINTLN_EXTRA(const char* str)
 *      PRINTF_EXTRA(const char* format, ...)
 *      PRINTFLN_EXTRA(const char* format, ...)
 *
 *      PRINT_INFO(const char* str)
 *      PRINTLN_INFO(const char* str)
 *      PRINTF_INFO(const char* format, ...)
 *      PRINTFLN_INFO(const char* format, ...)
 *
 *      PRINT_HEADER(const char* str)
 *      PRINTLN_HEADER(const char* str)
 *      PRINTF_HEADER(const char* format, ...)
 *      PRINTFLN_HEADER(const char* format, ...)
 *
 *      PRINT_SUCCESS(const char* str)
 *      PRINTLN_SUCCESS(const char* str)
 *      PRINTF_SUCCESS(const char* format, ...)
 *      PRINTFLN_SUCCESS(const char* format, ...)
 *
 *      PRINT_MONEY(const char* str)
 *      PRINTLN_MONEY(const char* str)
 *      PRINTF_MONEY(const char* format, ...)
 *      PRINTFLN_MONEY(const char* format, ...)
 *
 *      PRINT_INPUT(const char* str)
 *      PRINTLN_INPUT(const char* str)
 *      PRINTF_INPUT(const char* format, ...)
 *      PRINTFLN_INPUT(const char* format, ...)
 *
 *      PRINT_WARNING(const char* str)
 *      PRINTLN_WARNING(const char* str)
 *      PRINTF_WARNING(const char* format, ...)
 *      PRINTFLN_WARNING(const char* format, ...)
 *
 *      PERROR_WARNING(const char* str)
 *      PERRORF_WARNING(const char* format, ...)
 *
 *      PRINT_ERROR(const char* str)
 *      PRINTLN_ERROR(const char* str)
 *      PRINTF_ERROR(const char* format, ...)
 *      PRINTFLN_ERROR(const char* format, ...)
 *
 *      PERROR_ERROR(const char* str)
 *      PERRORF_ERROR(const char* format, ...)
 *
 *      PRINT_CRITICAL(const char* str)
 *      PRINTLN_CRITICAL(const char* str)
 *      PRINTF_CRITICAL(const char* format, ...)
 *      PRINTFLN_CRITICAL(const char* format, ...)
 *
 *      PERROR_CRITICAL(const char* str)
 *      PERRORF_CRITICAL(const char* format, ...)
 *
 *      PRINT_FATAL(const char* str)
 *      PRINTLN_FATAL(const char* str)
 *      PRINTF_FATAL(const char* format, ...)
 *      PRINTFLN_FATAL(const char* format, ...)
 *
 *      PERROR_FATAL(const char* str)
 *      PERRORF_FATAL(const char* format, ...)
 *
 *
 *  Examples
 *  --------
 *
 *      `PRINT_INFO("Hello"); printf("you");`
 *
 *          Output: `[*] Helloyou`
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void PRINT_TRACE(const char* str);
 *
 *  Print trace line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_TRACE(str)        PRINT(_CSYM_TRACE str)

/**
 *  void PRINTLN_TRACE(const char* str);
 *
 *  Print trace line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_TRACE(str)      PRINTLN(_CSYM_TRACE str)

/**
 *  void PRINTF_TRACE(const char* format, ...);
 *
 *  Print trace line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_TRACE(...)       PRINTF(_CSYM_TRACE __VA_ARGS__)

/**
 *  void PRINTFLN_TRACE(const char* format, ...);
 *
 *  Print trace line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_TRACE(...)     PRINTFLN(_CSYM_TRACE __VA_ARGS__)


/**
 *  void PRINT_DEBUG(const char* str);
 *
 *  Print debug line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_DEBUG(str)        PRINT(_CSYM_DEBUG str)

/**
 *  void PRINTLN_DEBUG(const char* str);
 *
 *  Print debug line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_DEBUG(str)      PRINTLN(_CSYM_DEBUG str)

/**
 *  void PRINTF_DEBUG(const char* format, ...);
 *
 *  Print debug line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_DEBUG(...)       PRINTF(_CSYM_DEBUG __VA_ARGS__)

/**
 *  void PRINTFLN_DEBUG(const char* format, ...);
 *
 *  Print debug line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_DEBUG(...)     PRINTFLN(_CSYM_DEBUG __VA_ARGS__)


/**
 *  void PRINT_EXTRA(const char* str);
 *
 *  Print extra line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_EXTRA(str)        PRINT(_CSYM_EXTRA str)

/**
 *  void PRINTLN_EXTRA(const char* str);
 *
 *  Print extra line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_EXTRA(str)      PRINTLN(_CSYM_EXTRA str)

/**
 *  void PRINTF_EXTRA(const char* format, ...);
 *
 *  Print extra line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_EXTRA(...)       PRINTF(_CSYM_EXTRA __VA_ARGS__)

/**
 *  void PRINTFLN_EXTRA(const char* format, ...);
 *
 *  Print extra line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_EXTRA(...)     PRINTFLN(_CSYM_EXTRA __VA_ARGS__)


/**
 *  void PRINT_INFO(const char* str);
 *
 *  Print info line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_INFO(str)         PRINT(_CSYM_INFO str)

/**
 *  void PRINTLN_INFO(const char* str);
 *
 *  Print info line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_INFO(str)       PRINTLN(_CSYM_INFO str)

/**
 *  void PRINTF_INFO(const char* format, ...);
 *
 *  Print info line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_INFO(...)        PRINTF(_CSYM_INFO __VA_ARGS__)

/**
 *  void PRINTFLN_INFO(const char* format, ...);
 *
 *  Print info line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_INFO(...)      PRINTFLN(_CSYM_INFO __VA_ARGS__)


/**
 *  void PRINT_HEADER(const char* str);
 *
 *  Print header line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_HEADER(str)       PRINT(_CSYM_HEADER str)

/**
 *  void PRINTLN_HEADER(const char* str);
 *
 *  Print header line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_HEADER(str)     PRINTLN(_CSYM_HEADER str)

/**
 *  void PRINTF_HEADER(const char* format, ...);
 *
 *  Print header line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_HEADER(...)      PRINTF(_CSYM_HEADER __VA_ARGS__)

/**
 *  void PRINTFLN_HEADER(const char* format, ...);
 *
 *  Print header line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_HEADER(...)    PRINTFLN(_CSYM_HEADER __VA_ARGS__)


/**
 *  void PRINT_SUCCESS(const char* str);
 *
 *  Print success line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_SUCCESS(str)      PRINT(_CSYM_SUCCESS str)

/**
 *  void PRINTLN_SUCCESS(const char* str);
 *
 *  Print success line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_SUCCESS(str)    PRINTLN(_CSYM_SUCCESS str)

/**
 *  void PRINTF_SUCCESS(const char* format, ...);
 *
 *  Print success line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_SUCCESS(...)     PRINTF(_CSYM_SUCCESS __VA_ARGS__)

/**
 *  void PRINTFLN_SUCCESS(const char* format, ...);
 *
 *  Print success line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_SUCCESS(...)   PRINTFLN(_CSYM_SUCCESS __VA_ARGS__)


/**
 *  void PRINT_MONEY(const char* str);
 *
 *  Print money line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_MONEY(str)        PRINT(_CSYM_MONEY str)

/**
 *  void PRINTLN_MONEY(const char* str);
 *
 *  Print money line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_MONEY(str)      PRINTLN(_CSYM_MONEY str)

/**
 *  void PRINTF_MONEY(const char* format, ...);
 *
 *  Print money line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_MONEY(...)       PRINTF(_CSYM_MONEY __VA_ARGS__)

/**
 *  void PRINTFLN_MONEY(const char* format, ...);
 *
 *  Print money line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_MONEY(...)     PRINTFLN(_CSYM_MONEY __VA_ARGS__)


/**
 *  void PRINT_INPUT(const char* str);
 *
 *  Print input line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_INPUT(str)        PRINT(_CSYM_INPUT str)

/**
 *  void PRINTLN_INPUT(const char* str);
 *
 *  Print input line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_INPUT(str)      PRINTLN(_CSYM_INPUT str)

/**
 *  void PRINTF_INPUT(const char* format, ...);
 *
 *  Print input line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_INPUT(...)       PRINTF(_CSYM_INPUT __VA_ARGS__)

/**
 *  void PRINTFLN_INPUT(const char* format, ...);
 *
 *  Print input line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_INPUT(...)     PRINTFLN(_CSYM_INPUT __VA_ARGS__)


/**
 *  void PRINT_WARNING(const char* str);
 *
 *  Print warning line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_WARNING(str)      PRINT(_CSYM_WARNING str)

/**
 *  void PRINTLN_WARNING(const char* str);
 *
 *  Print warning line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_WARNING(str)    PRINTLN(_CSYM_WARNING str)

/**
 *  void PRINTF_WARNING(const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_WARNING(...)     PRINTF(_CSYM_WARNING __VA_ARGS__)

/**
 *  void PRINTFLN_WARNING(const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_WARNING(...)   PRINTFLN(_CSYM_WARNING __VA_ARGS__)


/**
 *  void PERROR_WARNING(const char* str);
 *
 *  Print warning line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  str         String to print.
 */
#define PERROR_WARNING(str)     PERROR(_CSYM_WARNING str)

/**
 *  void PERRORF_WARNING(const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PERRORF_WARNING(...)    PERRORF(_CSYM_WARNING __VA_ARGS__)


/**
 *  void PRINT_ERROR(const char* str);
 *
 *  Print error line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_ERROR(str)        PRINT(_CSYM_ERROR str)

/**
 *  void PRINTLN_ERROR(const char* str);
 *
 *  Print error line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_ERROR(str)      PRINTLN(_CSYM_ERROR str)

/**
 *  void PRINTF_ERROR(const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_ERROR(...)       PRINTF(_CSYM_ERROR __VA_ARGS__)

/**
 *  void PRINTFLN_ERROR(const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_ERROR(...)     PRINTFLN(_CSYM_ERROR __VA_ARGS__)


/**
 *  void PERROR_ERROR(const char* str);
 *
 *  Print error line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  str         String to print.
 */
#define PERROR_ERROR(str)       PERROR(_CSYM_ERROR str)

/**
 *  void PERRORF_ERROR(const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PERRORF_ERROR(...)      PERRORF(_CSYM_ERROR __VA_ARGS__)


/**
 *  void PRINT_CRITICAL(const char* str);
 *
 *  Print critical line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_CRITICAL(str)     PRINT(_CSYM_CRITICAL str)

/**
 *  void PRINTLN_CRITICAL(const char* str);
 *
 *  Print critical line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_CRITICAL(str)   PRINTLN(_CSYM_CRITICAL str)

/**
 *  void PRINTF_CRITICAL(const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_CRITICAL(...)    PRINTF(_CSYM_CRITICAL __VA_ARGS__)

/**
 *  void PRINTFLN_CRITICAL(const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_CRITICAL(...)  PRINTFLN(_CSYM_CRITICAL __VA_ARGS__)


/**
 *  void PERROR_CRITICAL(const char* str);
 *
 *  Print critical line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  str         String to print.
 */
#define PERROR_CRITICAL(str)    PERROR(_CSYM_CRITICAL str)

/**
 *  void PERRORF_CRITICAL(const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PERRORF_CRITICAL(...)   PERRORF(_CSYM_CRITICAL __VA_ARGS__)


/**
 *  void PRINT_FATAL(const char* str);
 *
 *  Print fatal line header followed by the given string to standard output.
 *
 *  @param  str         String to print.
 */
#define PRINT_FATAL(str)        PRINT(_CSYM_FATAL str)

/**
 *  void PRINTLN_FATAL(const char* str);
 *
 *  Print fatal line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define PRINTLN_FATAL(str)      PRINTLN(_CSYM_FATAL str)

/**
 *  void PRINTF_FATAL(const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTF_FATAL(...)       PRINTF(_CSYM_FATAL __VA_ARGS__)

/**
 *  void PRINTFLN_FATAL(const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PRINTFLN_FATAL(...)     PRINTFLN(_CSYM_FATAL __VA_ARGS__)


/**
 *  void PERROR_FATAL(const char* str);
 *
 *  Print fatal line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  str         String to print.
 */
#define PERROR_FATAL(str)       PERROR(_CSYM_FATAL str)

/**
 *  void PERRORF_FATAL(const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define PERRORF_FATAL(...)      PERRORF(_CSYM_FATAL __VA_ARGS__)


/**
 *  "print_level" Short Aliases
 *  ---------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  void PRINT_TRC(const char* str);
     *
     *  Alias of `PRINT_TRACE` function.
     *
     *  Print trace line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_TRC(str)      PRINT_TRACE(str)

    /**
     *  void PRINTLN_TRC(const char* str);
     *
     *  Alias of `PRINTLN_TRACE` function.
     *
     *  Print trace line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_TRC(str)    PRINTLN_TRACE(str)

    /**
     *  void PRINTF_TRC(const char* format, ...);
     *
     *  Alias of `PRINTF_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_TRC(...)     PRINTF_TRACE(__VA_ARGS__)

    /**
     *  void PRINTFLN_TRC(const char* format, ...);
     *
     *  Alias of `PRINTFLN_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_TRC(...)   PRINTFLN_TRACE(__VA_ARGS__)


    /**
     *  void PRINT_DBG(const char* str);
     *
     *  Alias of `PRINT_DEBUG` function.
     *
     *  Print debug line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_DBG(str)      PRINT_DEBUG(str)

    /**
     *  void PRINTLN_DBG(const char* str);
     *
     *  Alias of `PRINTLN_DEBUG` function.
     *
     *  Print debug line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_DBG(str)    PRINTLN_DEBUG(str)

    /**
     *  void PRINTF_DBG(const char* format, ...);
     *
     *  Alias of `PRINTF_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_DBG(...)     PRINTF_DEBUG(__VA_ARGS__)

    /**
     *  void PRINTFLN_DBG(const char* format, ...);
     *
     *  Alias of `PRINTFLN_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_DBG(...)   PRINTFLN_DEBUG(__VA_ARGS__)


    /**
     *  void PRINT_EXT(const char* str);
     *
     *  Alias of `PRINT_EXTRA` function.
     *
     *  Print extra line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_EXT(str)      PRINT_EXTRA(str)

    /**
     *  void PRINTLN_EXT(const char* str);
     *
     *  Alias of `PRINTLN_EXTRA` function.
     *
     *  Print extra line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_EXT(str)    PRINTLN_EXTRA(str)

    /**
     *  void PRINTF_EXT(const char* format, ...);
     *
     *  Alias of `PRINTF_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_EXT(...)     PRINTF_EXTRA(__VA_ARGS__)

    /**
     *  void PRINTFLN_EXT(const char* format, ...);
     *
     *  Alias of `PRINTFLN_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_EXT(...)   PRINTFLN_EXTRA(__VA_ARGS__)


    /**
     *  void PRINT_INF(const char* str);
     *
     *  Alias of `PRINT_INFO` function.
     *
     *  Print info line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_INF(str)      PRINT_INFO(str)

    /**
     *  void PRINTLN_INF(const char* str);
     *
     *  Alias of `PRINTLN_INFO` function.
     *
     *  Print info line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_INF(str)    PRINTLN_INFO(str)

    /**
     *  void PRINTF_INF(const char* format, ...);
     *
     *  Alias of `PRINTF_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_INF(...)     PRINTF_INFO(__VA_ARGS__)

    /**
     *  void PRINTFLN_INF(const char* format, ...);
     *
     *  Alias of `PRINTFLN_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_INF(...)   PRINTFLN_INFO(__VA_ARGS__)


    /**
     *  void PRINT_HEAD(const char* str);
     *
     *  Alias of `PRINT_HEADER` function.
     *
     *  Print header line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_HEAD(str)      PRINT_HEADER(str)

    /**
     *  void PRINTLN_HEAD(const char* str);
     *
     *  Alias of `PRINTLN_HEADER` function.
     *
     *  Print header line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_HEAD(str)    PRINTLN_HEADER(str)

    /**
     *  void PRINTF_HEAD(const char* format, ...);
     *
     *  Alias of `PRINTF_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_HEAD(...)     PRINTF_HEADER(__VA_ARGS__)

    /**
     *  void PRINTFLN_HEAD(const char* format, ...);
     *
     *  Alias of `PRINTFLN_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_HEAD(...)   PRINTFLN_HEADER(__VA_ARGS__)


    /**
     *  void PRINT_SUC(const char* str);
     *
     *  Alias of `PRINT_SUCCESS` function.
     *
     *  Print success line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_SUC(str)      PRINT_SUCCESS(str)

    /**
     *  void PRINTLN_SUC(const char* str);
     *
     *  Alias of `PRINTLN_SUCCESS` function.
     *
     *  Print success line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_SUC(str)    PRINTLN_SUCCESS(str)

    /**
     *  void PRINTF_SUC(const char* format, ...);
     *
     *  Alias of `PRINTF_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_SUC(...)     PRINTF_SUCCESS(__VA_ARGS__)

    /**
     *  void PRINTFLN_SUC(const char* format, ...);
     *
     *  Alias of `PRINTFLN_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_SUC(...)   PRINTFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void PRINT_MON(const char* str);
     *
     *  Alias of `PRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_MON(str)      PRINT_MONEY(str)

    /**
     *  void PRINTLN_MON(const char* str);
     *
     *  Alias of `PRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_MON(str)    PRINTLN_MONEY(str)

    /**
     *  void PRINTF_MON(const char* format, ...);
     *
     *  Alias of `PRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_MON(...)     PRINTF_MONEY(__VA_ARGS__)

    /**
     *  void PRINTFLN_MON(const char* format, ...);
     *
     *  Alias of `PRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_MON(...)   PRINTFLN_MONEY(__VA_ARGS__)


    /**
     *  void PRINT_MNY(const char* str);
     *
     *  Alias of `PRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_MNY(str)      PRINT_MONEY(str)

    /**
     *  void PRINTLN_MNY(const char* str);
     *
     *  Alias of `PRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_MNY(str)    PRINTLN_MONEY(str)

    /**
     *  void PRINTF_MNY(const char* format, ...);
     *
     *  Alias of `PRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_MNY(...)     PRINTF_MONEY(__VA_ARGS__)

    /**
     *  void PRINTFLN_MNY(const char* format, ...);
     *
     *  Alias of `PRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_MNY(...)   PRINTFLN_MONEY(__VA_ARGS__)


    /**
     *  void PRINT_IN(const char* str);
     *
     *  Alias of `PRINT_INPUT` function.
     *
     *  Print input line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_IN(str)      PRINT_INPUT(str)

    /**
     *  void PRINTLN_IN(const char* str);
     *
     *  Alias of `PRINTLN_INPUT` function.
     *
     *  Print input line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_IN(str)    PRINTLN_INPUT(str)

    /**
     *  void PRINTF_IN(const char* format, ...);
     *
     *  Alias of `PRINTF_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_IN(...)     PRINTF_INPUT(__VA_ARGS__)

    /**
     *  void PRINTFLN_IN(const char* format, ...);
     *
     *  Alias of `PRINTFLN_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_IN(...)   PRINTFLN_INPUT(__VA_ARGS__)


    /**
     *  void PRINT_WARN(const char* str);
     *
     *  Alias of `PRINT_WARNING` function.
     *
     *  Print warning line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_WARN(str)      PRINT_WARNING(str)

    /**
     *  void PRINTLN_WARN(const char* str);
     *
     *  Alias of `PRINTLN_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_WARN(str)    PRINTLN_WARNING(str)

    /**
     *  void PRINTF_WARN(const char* format, ...);
     *
     *  Alias of `PRINTF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_WARN(...)     PRINTF_WARNING(__VA_ARGS__)

    /**
     *  void PRINTFLN_WARN(const char* format, ...);
     *
     *  Alias of `PRINTFLN_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_WARN(...)   PRINTFLN_WARNING(__VA_ARGS__)


    /**
     *  void PERROR_WARN(const char* str);
     *
     *  Alias of `PERROR_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_WARN(str)    PERROR_WARNING(str)

    /**
     *  void PERRORF_WARN(const char* format, ...);
     *
     *  Alias of `PERRORF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_WARN(...)   PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void PRINT_ERR(const char* str);
     *
     *  Alias of `PRINT_ERROR` function.
     *
     *  Print error line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_ERR(str)      PRINT_ERROR(str)

    /**
     *  void PRINTLN_ERR(const char* str);
     *
     *  Alias of `PRINTLN_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_ERR(str)    PRINTLN_ERROR(str)

    /**
     *  void PRINTF_ERR(const char* format, ...);
     *
     *  Alias of `PRINTF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_ERR(...)     PRINTF_ERROR(__VA_ARGS__)

    /**
     *  void PRINTFLN_ERR(const char* format, ...);
     *
     *  Alias of `PRINTFLN_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_ERR(...)   PRINTFLN_ERROR(__VA_ARGS__)


    /**
     *  void PERROR_ERR(const char* str);
     *
     *  Alias of `PERROR_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_ERR(str)     PERROR_ERROR(str)

    /**
     *  void PERRORF_ERR(const char* format, ...);
     *
     *  Alias of `PERRORF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_ERR(...)    PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void PRINT_CRIT(const char* str);
     *
     *  Alias of `PRINT_CRITICAL` function.
     *
     *  Print critical line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_CRIT(str)      PRINT_CRITICAL(str)

    /**
     *  void PRINTLN_CRIT(const char* str);
     *
     *  Alias of `PRINTLN_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_CRIT(str)    PRINTLN_CRITICAL(str)

    /**
     *  void PRINTF_CRIT(const char* format, ...);
     *
     *  Alias of `PRINTF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_CRIT(...)     PRINTF_CRITICAL(__VA_ARGS__)

    /**
     *  void PRINTFLN_CRIT(const char* format, ...);
     *
     *  Alias of `PRINTFLN_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_CRIT(...)   PRINTFLN_CRITICAL(__VA_ARGS__)


    /**
     *  void PERROR_CRIT(const char* str);
     *
     *  Alias of `PERROR_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_CRIT(str)     PERROR_CRITICAL(str)

    /**
     *  void PERRORF_CRIT(const char* format, ...);
     *
     *  Alias of `PERRORF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_CRIT(...)    PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void PRINT_FAT(const char* str);
     *
     *  Alias of `PRINT_FATAL` function.
     *
     *  Print fatal line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_FAT(str)      PRINT_FATAL(str)

    /**
     *  void PRINTLN_FAT(const char* str);
     *
     *  Alias of `PRINTLN_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_FAT(str)    PRINTLN_FATAL(str)

    /**
     *  void PRINTF_FAT(const char* format, ...);
     *
     *  Alias of `PRINTF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_FAT(...)     PRINTF_FATAL(__VA_ARGS__)

    /**
     *  void PRINTFLN_FAT(const char* format, ...);
     *
     *  Alias of `PRINTFLN_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_FAT(...)   PRINTFLN_FATAL(__VA_ARGS__)


    /**
     *  void PERROR_FAT(const char* str);
     *
     *  Alias of `PERROR_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_FAT(str)     PERROR_FATAL(str)

    /**
     *  void PERRORF_FAT(const char* format, ...);
     *
     *  Alias of `PERRORF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_FAT(...)    PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  PRINT_level Shorter Aliases
 *  ---------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  void PRINT_TR(const char* str);
     *
     *  Alias of `PRINT_TRACE` function.
     *
     *  Print trace line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_TR(str)       PRINT_TRACE(str)

    /**
     *  void PRINTLN_TR(const char* str);
     *
     *  Alias of `PRINTLN_TRACE` function.
     *
     *  Print trace line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_TR(str)     PRINTLN_TRACE(str)

    /**
     *  void PRINTF_TR(const char* format, ...);
     *
     *  Alias of `PRINTF_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_TR(...)      PRINTF_TRACE(__VA_ARGS__)

    /**
     *  void PRINTFLN_TR(const char* format, ...);
     *
     *  Alias of `PRINTFLN_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_TR(...)    PRINTFLN_TRACE(__VA_ARGS__)


    /**
     *  void PRINT_DB(const char* str);
     *
     *  Alias of `PRINT_DEBUG` function.
     *
     *  Print debug line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_DB(str)       PRINT_DEBUG(str)

    /**
     *  void PRINTLN_DB(const char* str);
     *
     *  Alias of `PRINTLN_DEBUG` function.
     *
     *  Print debug line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_DB(str)     PRINTLN_DEBUG(str)

    /**
     *  void PRINTF_DB(const char* format, ...);
     *
     *  Alias of `PRINTF_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_DB(...)      PRINTF_DEBUG(__VA_ARGS__)

    /**
     *  void PRINTFLN_DB(const char* format, ...);
     *
     *  Alias of `PRINTFLN_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_DB(...)    PRINTFLN_DEBUG(__VA_ARGS__)


    /**
     *  void PRINT_EX(const char* str);
     *
     *  Alias of `PRINT_EXTRA` function.
     *
     *  Print extra line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_EX(str)       PRINT_EXTRA(str)

    /**
     *  void PRINTLN_EX(const char* str);
     *
     *  Alias of `PRINTLN_EXTRA` function.
     *
     *  Print extra line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_EX(str)     PRINTLN_EXTRA(str)

    /**
     *  void PRINTF_EX(const char* format, ...);
     *
     *  Alias of `PRINTF_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_EX(...)      PRINTF_EXTRA(__VA_ARGS__)

    /**
     *  void PRINTFLN_EX(const char* format, ...);
     *
     *  Alias of `PRINTFLN_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_EX(...)    PRINTFLN_EXTRA(__VA_ARGS__)


    /**
     *  void PRINT_IF(const char* str);
     *
     *  Alias of `PRINT_INFO` function.
     *
     *  Print info line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_IF(str)       PRINT_INFO(str)

    /**
     *  void PRINTLN_IF(const char* str);
     *
     *  Alias of `PRINTLN_INFO` function.
     *
     *  Print info line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_IF(str)     PRINTLN_INFO(str)

    /**
     *  void PRINTF_IF(const char* format, ...);
     *
     *  Alias of `PRINTF_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_IF(...)      PRINTF_INFO(__VA_ARGS__)

    /**
     *  void PRINTFLN_IF(const char* format, ...);
     *
     *  Alias of `PRINTFLN_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_IF(...)    PRINTFLN_INFO(__VA_ARGS__)


    /**
     *  void PRINT_HD(const char* str);
     *
     *  Alias of `PRINT_HEADER` function.
     *
     *  Print header line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_HD(str)        PRINT_HEADER(str)

    /**
     *  void PRINTLN_HD(const char* str);
     *
     *  Alias of `PRINTLN_HEADER` function.
     *
     *  Print header line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_HD(str)      PRINTLN_HEADER(str)

    /**
     *  void PRINTF_HD(const char* format, ...);
     *
     *  Alias of `PRINTF_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_HD(...)       PRINTF_HEADER(__VA_ARGS__)

    /**
     *  void PRINTFLN_HD(const char* format, ...);
     *
     *  Alias of `PRINTFLN_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_HD(...)     PRINTFLN_HEADER(__VA_ARGS__)


    /**
     *  void PRINT_SC(const char* str);
     *
     *  Alias of `PRINT_SUCCESS` function.
     *
     *  Print success line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_SC(str)        PRINT_SUCCESS(str)

    /**
     *  void PRINTLN_SC(const char* str);
     *
     *  Alias of `PRINTLN_SUCCESS` function.
     *
     *  Print success line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_SC(str)     PRINTLN_SUCCESS(str)

    /**
     *  void PRINTF_SC(const char* format, ...);
     *
     *  Alias of `PRINTF_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_SC(...)      PRINTF_SUCCESS(__VA_ARGS__)

    /**
     *  void PRINTFLN_SC(const char* format, ...);
     *
     *  Alias of `PRINTFLN_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_SC(...)    PRINTFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void PRINT_MN(const char* str);
     *
     *  Alias of `PRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_MN(str)       PRINT_MONEY(str)

    /**
     *  void PRINTLN_MN(const char* str);
     *
     *  Alias of `PRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_MN(str)     PRINTLN_MONEY(str)

    /**
     *  void PRINTF_MN(const char* format, ...);
     *
     *  Alias of `PRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_MN(...)      PRINTF_MONEY(__VA_ARGS__)

    /**
     *  void PRINTFLN_MN(const char* format, ...);
     *
     *  Alias of `PRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_MN(...)    PRINTFLN_MONEY(__VA_ARGS__)


    /**
     *  void PRINT_MY(const char* str);
     *
     *  Alias of `PRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_MY(str)       PRINT_MONEY(str)

    /**
     *  void PRINTLN_MY(const char* str);
     *
     *  Alias of `PRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_MY(str)     PRINTLN_MONEY(str)

    /**
     *  void PRINTF_MY(const char* format, ...);
     *
     *  Alias of `PRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_MY(...)      PRINTF_MONEY(__VA_ARGS__)

    /**
     *  void PRINTFLN_MY(const char* format, ...);
     *
     *  Alias of `PRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_MY(...)    PRINTFLN_MONEY(__VA_ARGS__)


    /**
     *  void PRINT_IN(const char* str);
     *
     *  Alias of `PRINT_INPUT` function.
     *
     *  Print input line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_IN(str)      PRINT_INPUT(str)

    /**
     *  void PRINTLN_IN(const char* str);
     *
     *  Alias of `PRINTLN_INPUT` function.
     *
     *  Print input line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_IN(str)    PRINTLN_INPUT(str)

    /**
     *  void PRINTF_IN(const char* format, ...);
     *
     *  Alias of `PRINTF_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_IN(...)     PRINTF_INPUT(__VA_ARGS__)

    /**
     *  void PRINTFLN_IN(const char* format, ...);
     *
     *  Alias of `PRINTFLN_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_IN(...)   PRINTFLN_INPUT(__VA_ARGS__)


    /**
     *  void PRINT_WN(const char* str);
     *
     *  Alias of `PRINT_WARNING` function.
     *
     *  Print warning line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_WN(str)        PRINT_WARNING(str)

    /**
     *  void PRINTLN_WN(const char* str);
     *
     *  Alias of `PRINTLN_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_WN(str)      PRINTLN_WARNING(str)

    /**
     *  void PRINTF_WN(const char* format, ...);
     *
     *  Alias of `PRINTF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_WN(...)       PRINTF_WARNING(__VA_ARGS__)

    /**
     *  void PRINTFLN_WN(const char* format, ...);
     *
     *  Alias of `PRINTFLN_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_WN(...)     PRINTFLN_WARNING(__VA_ARGS__)


    /**
     *  void PERROR_WN(const char* str);
     *
     *  Alias of `PERROR_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_WN(str)      PERROR_WARNING(str)

    /**
     *  void PERRORF_WN(const char* format, ...);
     *
     *  Alias of `PERRORF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_WN(...)     PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void PRINT_ER(const char* str);
     *
     *  Alias of `PRINT_ERROR` function.
     *
     *  Print error line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_ER(str)       PRINT_ERROR(str)

    /**
     *  void PRINTLN_ER(const char* str);
     *
     *  Alias of `PRINTLN_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_ER(str)     PRINTLN_ERROR(str)

    /**
     *  void PRINTF_ER(const char* format, ...);
     *
     *  Alias of `PRINTF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_ER(...)      PRINTF_ERROR(__VA_ARGS__)

    /**
     *  void PRINTFLN_ER(const char* format, ...);
     *
     *  Alias of `PRINTFLN_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_ER(...)    PRINTFLN_ERROR(__VA_ARGS__)


    /**
     *  void PERROR_ER(const char* str);
     *
     *  Alias of `PERROR_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_ER(str)      PERROR_ERROR(str)

    /**
     *  void PERRORF_ER(const char* format, ...);
     *
     *  Alias of `PERRORF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_ER(...)     PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void PRINT_CR(const char* str);
     *
     *  Alias of `PRINT_CRITICAL` function.
     *
     *  Print critical line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_CR(str)        PRINT_CRITICAL(str)

    /**
     *  void PRINTLN_CR(const char* str);
     *
     *  Alias of `PRINTLN_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_CR(str)      PRINTLN_CRITICAL(str)

    /**
     *  void PRINTF_CR(const char* format, ...);
     *
     *  Alias of `PRINTF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_CR(...)       PRINTF_CRITICAL(__VA_ARGS__)

    /**
     *  void PRINTFLN_CR(const char* format, ...);
     *
     *  Alias of `PRINTFLN_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_CR(...)     PRINTFLN_CRITICAL(__VA_ARGS__)


    /**
     *  void PERROR_CR(const char* str);
     *
     *  Alias of `PERROR_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_CR(str)       PERROR_CRITICAL(str)

    /**
     *  void PERRORF_CR(const char* format, ...);
     *
     *  Alias of `PERRORF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_CR(...)      PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void PRINT_FT(const char* str);
     *
     *  Alias of `PRINT_FATAL` function.
     *
     *  Print fatal line header followed by the given string to standard
     *  output.
     *
     *  @param  str         String to print.
     */
    #define PRINT_FT(str)       PRINT_FATAL(str)

    /**
     *  void PRINTLN_FT(const char* str);
     *
     *  Alias of `PRINTLN_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define PRINTLN_FT(str)     PRINTLN_FATAL(str)

    /**
     *  void PRINTF_FT(const char* format, ...);
     *
     *  Alias of `PRINTF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTF_FT(...)      PRINTF_FATAL(__VA_ARGS__)

    /**
     *  void PRINTFLN_FT(const char* format, ...);
     *
     *  Alias of `PRINTFLN_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PRINTFLN_FT(...)    PRINTFLN_FATAL(__VA_ARGS__)


    /**
     *  void PERROR_FT(const char* str);
     *
     *  Alias of `PERROR_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define PERROR_FT(str)      PERROR_FATAL(str)

    /**
     *  void PERRORF_FT(const char* format, ...);
     *
     *  Alias of `PERRORF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define PERRORF_FT(...)     PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "cprint" Functions
 *  ==================
 *
 *  The "cprint" series of function macros are for colored printing to standard
 *  out.
 *
 *  The first parameter of all these functions is the color to print the text
 *  as by prepending the string argument with the ANZI terminal color code and
 *  by resetting the color output at the end.
 *
 *  There are several function-like macros available:
 *
 *      CPRINT(const char* color, const char* str)
 *      CPRINTLN(const char* color, const char* str)
 *      CPRINTF(const char* color, const char* format, ...)
 *      CPRINTFLN(const char* color, const char* format, ...)
 *      CPRINT_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CPRINTLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CPRINT_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CPRINTLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CPERROR(const char* color, const char* str)
 *      CPERRORF(const char* color, const char* format, ...)
 *
 *  Examples
 *  --------
 *
 *      `CFPRINT(C_RED, "Hello"); printf("you");`
 *
 *          Output: `\033[31mHelloyou\033[0m` (Red "Helloyou")
 *
 *      `int i = 15; CFPRINT_HEX(C_RED, &i, sizeof(int));`
 *
 *          Output: `\033[31m0f000000\033[0m`. (Red "0f000000")
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CPRINT(const char* color, const char* str);
 *
 *  Print given string to standard output in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT(color, str)      CFPRINT(color, stdout, str)

/**
 *  void CPRINTLN(const char* color, const char* str);
 *
 *  Print given string to standard output followed by a newline in the given
 *  color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN(color, str)    CFPRINTLN(color, stdout, str)

/**
 *  void CPRINTF(const char* color, const char* format, ...);
 *
 *  Print given format string and format arguments to standard output in the
 *  given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF(color, ...)     CFPRINTF(color, stdout, __VA_ARGS__)

/**
 *  void CPRINTFLN(const char* color, const char* format, ...);
 *
 *  Print given format string and format arguments to standard output
 *  followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN(color, ...)   CFPRINTFLN(color, stdout, __VA_ARGS__)

/**
 *  void CPRINT_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard output in
 *  the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CPRINT_HEX(color, buffer, length) \
    CFPRINT_HEX(color, stdout, buffer, length)

/**
 *  void CPRINTLN_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard output
 *  followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CPRINTLN_HEX(color, buffer, length) \
    CFPRINTLN_HEX(color, stdout, buffer, length)

/**
 *  void CPRINT_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard output in the given
 *  color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CPRINT_WIDE_HEX(color, buffer, length) \
    CFPRINT_WIDE_HEX(color, stdout, buffer, length)

/**
 *  void CPRINTLN_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard output followed by a
 *  newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CPRINTLN_WIDE_HEX(color, buffer, length) \
    CFPRINTLN_WIDE_HEX(color, stdout, buffer, length)

/**
 *  void CPERROR(const char* color, const char* str);
 *
 *  Print given string to standard output and then print the C error
 *  message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPERROR(color, str)     CFPERROR(color, stdout, str)

/**
 *  void CPERRORF(const char* color, const char* format, ...);
 *
 *  Print given format string and format arguments to standard output
 *  followed by a C error message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPERRORF(color, ...)    CFPERRORF(color, stdout, __VA_ARGS__)


/**
 *  "cprint_level" Functions
 *  ------------------------
 *
 *  Additionally, there are "cprint_level" functions which add a symbol header
 *  to each line based on the level selected and print in the given color.
 *
 *  ** Note: These will ALWAYS print regardless of logging level. For
 *  controlling prints using levels, see "CLOG" and "LOG" functions.
 *
 *  There are several of these function-like macros available:
 *
 *      CPRINT_TRACE(const char* color, const char* str)
 *      CPRINTLN_TRACE(const char* color, const char* str)
 *      CPRINTF_TRACE(const char* color, const char* format, ...)
 *      CPRINTFLN_TRACE(const char* color, const char* format, ...)
 *
 *      CPRINT_DEBUG(const char* color, const char* str)
 *      CPRINTLN_DEBUG(const char* color, const char* str)
 *      CPRINTF_DEBUG(const char* color, const char* format, ...)
 *      CPRINTFLN_DEBUG(const char* color, const char* format, ...)
 *
 *      CPRINT_EXTRA(const char* color, const char* str)
 *      CPRINTLN_EXTRA(const char* color, const char* str)
 *      CPRINTF_EXTRA(const char* color, const char* format, ...)
 *      CPRINTFLN_EXTRA(const char* color, const char* format, ...)
 *
 *      CPRINT_INFO(const char* color, const char* str)
 *      CPRINTLN_INFO(const char* color, const char* str)
 *      CPRINTF_INFO(const char* color, const char* format, ...)
 *      CPRINTFLN_INFO(const char* color, const char* format, ...)
 *
 *      CPRINT_HEADER(const char* color, const char* str)
 *      CPRINTLN_HEADER(const char* color, const char* str)
 *      CPRINTF_HEADER(const char* color, const char* format, ...)
 *      CPRINTFLN_HEADER(const char* color, const char* format, ...)
 *
 *      CPRINT_SUCCESS(const char* color, const char* str)
 *      CPRINTLN_SUCCESS(const char* color, const char* str)
 *      CPRINTF_SUCCESS(const char* color, const char* format, ...)
 *      CPRINTFLN_SUCCESS(const char* color, const char* format, ...)
 *
 *      CPRINT_MONEY(const char* color, const char* str)
 *      CPRINTLN_MONEY(const char* color, const char* str)
 *      CPRINTF_MONEY(const char* color, const char* format, ...)
 *      CPRINTFLN_MONEY(const char* color, const char* format, ...)
 *
 *      CPRINT_INPUT(const char* color, const char* str)
 *      CPRINTLN_INPUT(const char* color, const char* str)
 *      CPRINTF_INPUT(const char* color, const char* format, ...)
 *      CPRINTFLN_INPUT(const char* color, const char* format, ...)
 *
 *      CPRINT_WARNING(const char* color, const char* str)
 *      CPRINTLN_WARNING(const char* color, const char* str)
 *      CPRINTF_WARNING(const char* color, const char* format, ...)
 *      CPRINTFLN_WARNING(const char* color, const char* format, ...)
 *      CPERROR_WARNING(const char* color, const char* str)
 *      CPERRORF_WARNING(const char* color, const char* format, ...)
 *
 *      CPRINT_ERROR(const char* color, const char* str)
 *      CPRINTLN_ERROR(const char* color, const char* str)
 *      CPRINTF_ERROR(const char* color, const char* format, ...)
 *      CPRINTFLN_ERROR(const char* color, const char* format, ...)
 *      CPERROR_ERROR(const char* color, const char* str)
 *      CPERRORF_ERROR(const char* color, const char* format, ...)
 *
 *      CPRINT_CRITICAL(const char* color, const char* str)
 *      CPRINTLN_CRITICAL(const char* color, const char* str)
 *      CPRINTF_CRITICAL(const char* color, const char* format, ...)
 *      CPRINTFLN_CRITICAL(const char* color, const char* format, ...)
 *      CPERROR_CRITICAL(const char* color, const char* str)
 *      CPERRORF_CRITICAL(const char* color, const char* format, ...)
 *
 *      CPRINT_FATAL(const char* color, const char* str)
 *      CPRINTLN_FATAL(const char* color, const char* str)
 *      CPRINTF_FATAL(const char* color, const char* format, ...)
 *      CPRINTFLN_FATAL(const char* color, const char* format, ...)
 *      CPERROR_CRITICAL(const char* color, const char* str)
 *      CPERRORF_CRITICAL(const char* color, const char* format, ...)
 *
 *
 *  Examples
 *  --------
 *
 *      `CPRINT_INFO(C_RED, "Hello"); printf("you");`
 *
 *          Output: `\033[31m[*] Helloyou\033[0m` (Red "[*] Helloyou")
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CPRINT_TRACE(const char* color, const char* str);
 *
 *  Print trace line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_TRACE(color, str)        CPRINT(color, _CSYM_TRACE str)

/**
 *  void CPRINTLN_TRACE(const char* color, const char* str);
 *
 *  Print trace line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_TRACE(color, str)      CPRINTLN(color, _CSYM_TRACE str)

/**
 *  void CPRINTF_TRACE(const char* color, const char* format, ...);
 *
 *  Print trace line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_TRACE(color, ...)       CPRINTF(color, _CSYM_TRACE __VA_ARGS__)

/**
 *  void CPRINTFLN_TRACE(const char* color, const char* format, ...);
 *
 *  Print trace line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_TRACE(color, ...) \
    CPRINTFLN(color, _CSYM_TRACE __VA_ARGS__)


/**
 *  void CPRINT_DEBUG(const char* color, const char* str);
 *
 *  Print debug line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_DEBUG(color, str)        CPRINT(color, _CSYM_DEBUG str)

/**
 *  void CPRINTLN_DEBUG(const char* color, const char* str);
 *
 *  Print debug line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_DEBUG(color, str)      CPRINTLN(color, _CSYM_DEBUG str)

/**
 *  void CPRINTF_DEBUG(const char* color, const char* format, ...);
 *
 *  Print debug line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_DEBUG(color, ...)       CPRINTF(color, _CSYM_DEBUG __VA_ARGS__)

/**
 *  void CPRINTFLN_DEBUG(const char* color, const char* format, ...);
 *
 *  Print debug line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_DEBUG(color, ...) \
    CPRINTFLN(color, _CSYM_DEBUG __VA_ARGS__)


/**
 *  void CPRINT_EXTRA(const char* color, const char* str);
 *
 *  Print extra line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_EXTRA(color, str)        CPRINT(color, _CSYM_EXTRA str)

/**
 *  void CPRINTLN_EXTRA(const char* color, const char* str);
 *
 *  Print extra line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_EXTRA(color, str)      CPRINTLN(color, _CSYM_EXTRA str)

/**
 *  void CPRINTF_EXTRA(const char* color, const char* format, ...);
 *
 *  Print extra line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_EXTRA(color, ...) \
    CPRINTF(color, _CSYM_EXTRA __VA_ARGS__)

/**
 *  void CPRINTFLN_EXTRA(const char* color, const char* format, ...);
 *
 *  Print extra line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_EXTRA(color, ...) \
    CPRINTFLN(color, _CSYM_EXTRA __VA_ARGS__)


/**
 *  void CPRINT_INFO(const char* color, const char* str);
 *
 *  Print info line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_INFO(color, str)         CPRINT(color, _CSYM_INFO str)

/**
 *  void CPRINTLN_INFO(const char* color, const char* str);
 *
 *  Print info line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_INFO(color, str)       CPRINTLN(color, _CSYM_INFO str)

/**
 *  void CPRINTF_INFO(const char* color, const char* format, ...);
 *
 *  Print info line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_INFO(color, ...)        CPRINTF(color, _CSYM_INFO __VA_ARGS__)

/**
 *  void CPRINTFLN_INFO(const char* color, const char* format, ...);
 *
 *  Print info line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_INFO(color, ...) \
    CPRINTFLN(color, _CSYM_INFO __VA_ARGS__)


/**
 *  void CPRINT_HEADER(const char* color, const char* str);
 *
 *  Print header line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_HEADER(color, str)       CPRINT(color, _CSYM_HEADER str)

/**
 *  void CPRINTLN_HEADER(const char* color, const char* str);
 *
 *  Print header line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_HEADER(color, str)     CPRINTLN(color, _CSYM_HEADER str)

/**
 *  void CPRINTF_HEADER(const char* color, const char* format, ...);
 *
 *  Print header line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_HEADER(color, ...) \
    CPRINTF(color, _CSYM_HEADER __VA_ARGS__)

/**
 *  void CPRINTFLN_HEADER(const char* color, const char* format, ...);
 *
 *  Print header line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_HEADER(color, ...) \
    CPRINTFLN(color, _CSYM_HEADER __VA_ARGS__)


/**
 *  void CPRINT_SUCCESS(const char* color, const char* str);
 *
 *  Print success line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_SUCCESS(color, str)      CPRINT(color, _CSYM_SUCCESS str)

/**
 *  void CPRINTLN_SUCCESS(const char* color, const char* str);
 *
 *  Print success line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_SUCCESS(color, str)    CPRINTLN(color, _CSYM_SUCCESS str)

/**
 *  void CPRINTF_SUCCESS(const char* color, const char* format, ...);
 *
 *  Print success line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_SUCCESS(color, ...) \
    CPRINTF(color, _CSYM_SUCCESS __VA_ARGS__)

/**
 *  void CPRINTFLN_SUCCESS(const char* color, const char* format, ...);
 *
 *  Print success line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_SUCCESS(color, ...) \
    CPRINTFLN(color, _CSYM_SUCCESS __VA_ARGS__)


/**
 *  void CPRINT_MONEY(const char* color, const char* str);
 *
 *  Print money line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_MONEY(color, str)        CPRINT(color, _CSYM_MONEY str)

/**
 *  void CPRINTLN_MONEY(const char* color, const char* str);
 *
 *  Print money line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_MONEY(color, str)      CPRINTLN(color, _CSYM_MONEY str)

/**
 *  void CPRINTF_MONEY(const char* color, const char* format, ...);
 *
 *  Print money line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_MONEY(color, ...)       CPRINTF(color, _CSYM_MONEY __VA_ARGS__)

/**
 *  void CPRINTFLN_MONEY(const char* color, const char* format, ...);
 *
 *  Print money line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_MONEY(color, ...) \
    CPRINTFLN(color, _CSYM_MONEY __VA_ARGS__)


/**
 *  void CPRINT_INPUT(const char* color, const char* str);
 *
 *  Print input line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_INPUT(color, str)        CPRINT(color, _CSYM_INPUT str)

/**
 *  void CPRINTLN_INPUT(const char* color, const char* str);
 *
 *  Print input line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_INPUT(color, str)      CPRINTLN(color, _CSYM_INPUT str)

/**
 *  void CPRINTF_INPUT(const char* color, const char* format, ...);
 *
 *  Print input line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_INPUT(color, ...)       CPRINTF(color, _CSYM_INPUT __VA_ARGS__)

/**
 *  void CPRINTFLN_INPUT(const char* color, const char* format, ...);
 *
 *  Print input line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_INPUT(color, ...) \
    CPRINTFLN(color, _CSYM_INPUT __VA_ARGS__)


/**
 *  void CPRINT_WARNING(const char* color, const char* str);
 *
 *  Print warning line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_WARNING(color, str)      CPRINT(color, _CSYM_WARNING str)

/**
 *  void CPRINTLN_WARNING(const char* color, const char* str);
 *
 *  Print warning line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_WARNING(color, str)    CPRINTLN(color, _CSYM_WARNING str)

/**
 *  void CPRINTF_WARNING(const char* color, const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_WARNING(color, ...) \
    CPRINTF(color, _CSYM_WARNING __VA_ARGS__)

/**
 *  void CPRINTFLN_WARNING(const char* color, const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_WARNING(color, ...) \
    CPRINTFLN(color, _CSYM_WARNING __VA_ARGS__)


/**
 *  void CPERROR_WARNING(const char* color, const char* str);
 *
 *  Print warning line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPERROR_WARNING(color, str)     CPERROR(color, _CSYM_WARNING str)

/**
 *  void CPERRORF_WARNING(const char* color, const char* format, ...);
 *
 *  Print warning line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPERRORF_WARNING(color, ...) \
    CPERRORF(color, _CSYM_WARNING __VA_ARGS__)


/**
 *  void CPRINT_ERROR(const char* color, const char* str);
 *
 *  Print error line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_ERROR(color, str)        CPRINT(color, _CSYM_ERROR str)

/**
 *  void CPRINTLN_ERROR(const char* color, const char* str);
 *
 *  Print error line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_ERROR(color, str)      CPRINTLN(color, _CSYM_ERROR str)

/**
 *  void CPRINTF_ERROR(const char* color, const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_ERROR(color, ...)       CPRINTF(color, _CSYM_ERROR __VA_ARGS__)

/**
 *  void CPRINTFLN_ERROR(const char* color, const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_ERROR(color, ...) \
    CPRINTFLN(color, _CSYM_ERROR __VA_ARGS__)


/**
 *  void CPERROR_ERROR(const char* color, const char* str);
 *
 *  Print error line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPERROR_ERROR(color, str)       CPERROR(color, _CSYM_ERROR str)

/**
 *  void CPERRORF_ERROR(const char* color, const char* format, ...);
 *
 *  Print error line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPERRORF_ERROR(color, ...) \
    CPERRORF(color, _CSYM_ERROR __VA_ARGS__)


/**
 *  void CPRINT_CRITICAL(const char* color, const char* str);
 *
 *  Print critical line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_CRITICAL(color, str)     CPRINT(color, _CSYM_CRITICAL str)

/**
 *  void CPRINTLN_CRITICAL(const char* color, const char* str);
 *
 *  Print critical line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_CRITICAL(color, str)   CPRINTLN(color, _CSYM_CRITICAL str)

/**
 *  void CPRINTF_CRITICAL(const char* color, const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_CRITICAL(color, ...) \
    CPRINTF(color, _CSYM_CRITICAL __VA_ARGS__)

/**
 *  void CPRINTFLN_CRITICAL(const char* color, const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_CRITICAL(color, ...) \
    CPRINTFLN(color, _CSYM_CRITICAL __VA_ARGS__)


/**
 *  void CPERROR_CRITICAL(const char* color, const char* str);
 *
 *  Print critical line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPERROR_CRITICAL(color, str)    CPERROR(color, _CSYM_CRITICAL str)

/**
 *  void CPERRORF_CRITICAL(const char* color, const char* format, ...);
 *
 *  Print critical line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPERRORF_CRITICAL(color, ...) \
    CPERRORF(color, _CSYM_CRITICAL __VA_ARGS__)


/**
 *  void CPRINT_FATAL(const char* color, const char* str);
 *
 *  Print fatal line header followed by the given string to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINT_FATAL(color, str)        CPRINT(color, _CSYM_FATAL str)

/**
 *  void CPRINTLN_FATAL(const char* color, const char* str);
 *
 *  Print fatal line header followed by given string to standard output
 *  followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPRINTLN_FATAL(color, str)      CPRINTLN(color, _CSYM_FATAL str)

/**
 *  void CPRINTF_FATAL(const char* color, const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTF_FATAL(color, ...) \
    CPRINTF(color, _CSYM_FATAL __VA_ARGS__)

/**
 *  void CPRINTFLN_FATAL(const char* color, const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output followed by a newline.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPRINTFLN_FATAL(color, ...) \
    CPRINTFLN(color, _CSYM_FATAL __VA_ARGS__)


/**
 *  void CPERROR_FATAL(const char* color, const char* str);
 *
 *  Print fatal line header followed by given string to standard output and
 *  then print the C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CPERROR_FATAL(color, str)       CPERROR(color, _CSYM_FATAL str)

/**
 *  void CPERRORF_FATAL(const char* color, const char* format, ...);
 *
 *  Print fatal line header followed by given format string and format
 *  arguments to standard output followed by a C error message.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CPERRORF_FATAL(color, ...) \
    CPERRORF(color, _CSYM_FATAL __VA_ARGS__)


/**
 *  "print_level" Short Aliases
 *  ---------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  void CPRINT_TRC(const char* color, const char* str);
     *
     *  Alias of `CPRINT_TRACE` function.
     *
     *  Print trace line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_TRC(color, str)      CPRINT_TRACE(color, str)

    /**
     *  void CPRINTLN_TRC(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_TRACE` function.
     *
     *  Print trace line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_TRC(color, str)    CPRINTLN_TRACE(color, str)

    /**
     *  void CPRINTF_TRC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_TRC(color, ...)     CPRINTF_TRACE(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_TRC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_TRC(color, ...)   CPRINTFLN_TRACE(color, __VA_ARGS__)


    /**
     *  void CPRINT_DBG(const char* color, const char* str);
     *
     *  Alias of `CPRINT_DEBUG` function.
     *
     *  Print debug line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_DBG(color, str)      CPRINT_DEBUG(color, str)

    /**
     *  void CPRINTLN_DBG(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_DEBUG` function.
     *
     *  Print debug line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_DBG(color, str)    CPRINTLN_DEBUG(color, str)

    /**
     *  void CPRINTF_DBG(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_DBG(color, ...)     CPRINTF_DEBUG(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_DBG(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_DBG(color, ...)   CPRINTFLN_DEBUG(color, __VA_ARGS__)


    /**
     *  void CPRINT_EXT(const char* color, const char* str);
     *
     *  Alias of `CPRINT_EXTRA` function.
     *
     *  Print extra line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_EXT(color, str)      CPRINT_EXTRA(color, str)

    /**
     *  void CPRINTLN_EXT(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_EXTRA` function.
     *
     *  Print extra line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_EXT(color, str)    CPRINTLN_EXTRA(color, str)

    /**
     *  void CPRINTF_EXT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_EXT(color, ...)     CPRINTF_EXTRA(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_EXT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_EXT(color, ...)   CPRINTFLN_EXTRA(color, __VA_ARGS__)


    /**
     *  void CPRINT_INF(const char* color, const char* str);
     *
     *  Alias of `CPRINT_INFO` function.
     *
     *  Print info line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_INF(color, str)      CPRINT_INFO(color, str)

    /**
     *  void CPRINTLN_INF(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_INFO` function.
     *
     *  Print info line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_INF(color, str)    CPRINTLN_INFO(color, str)

    /**
     *  void CPRINTF_INF(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_INF(color, ...)     CPRINTF_INFO(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_INF(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_INF(color, ...)   CPRINTFLN_INFO(color, __VA_ARGS__)


    /**
     *  void CPRINT_HEAD(const char* color, const char* str);
     *
     *  Alias of `CPRINT_HEADER` function.
     *
     *  Print header line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_HEAD(color, str)      CPRINT_HEADER(color, str)

    /**
     *  void CPRINTLN_HEAD(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_HEADER` function.
     *
     *  Print header line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_HEAD(color, str)    CPRINTLN_HEADER(color, str)

    /**
     *  void CPRINTF_HEAD(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_HEAD(color, ...)     CPRINTF_HEADER(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_HEAD(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_HEAD(color, ...)   CPRINTFLN_HEADER(color, __VA_ARGS__)


    /**
     *  void CPRINT_SUC(const char* color, const char* str);
     *
     *  Alias of `CPRINT_SUCCESS` function.
     *
     *  Print success line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_SUC(color, str)      CPRINT_SUCCESS(color, str)

    /**
     *  void CPRINTLN_SUC(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_SUCCESS` function.
     *
     *  Print success line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_SUC(color, str)    CPRINTLN_SUCCESS(color, str)

    /**
     *  void CPRINTF_SUC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_SUC(color, ...)     CPRINTF_SUCCESS(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_SUC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_SUC(color, ...)   CPRINTFLN_SUCCESS(color, __VA_ARGS__)


    /**
     *  void CPRINT_MON(const char* color, const char* str);
     *
     *  Alias of `CPRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_MON(color, str)      CPRINT_MONEY(color, str)

    /**
     *  void CPRINTLN_MON(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_MON(color, str)    CPRINTLN_MONEY(color, str)

    /**
     *  void CPRINTF_MON(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_MON(color, ...)     CPRINTF_MONEY(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_MON(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_MON(color, ...)   CPRINTFLN_MONEY(color, __VA_ARGS__)


    /**
     *  void CPRINT_MNY(const char* color, const char* str);
     *
     *  Alias of `CPRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_MNY(color, str)      CPRINT_MONEY(color, str)

    /**
     *  void CPRINTLN_MNY(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_MNY(color, str)    CPRINTLN_MONEY(color, str)

    /**
     *  void CPRINTF_MNY(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_MNY(color, ...)     CPRINTF_MONEY(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_MNY(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_MNY(color, ...)   CPRINTFLN_MONEY(color, __VA_ARGS__)


    /**
     *  void CPRINT_IN(const char* color, const char* str);
     *
     *  Alias of `CPRINT_INPUT` function.
     *
     *  Print input line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_IN(color, str)       CPRINT_INPUT(color, str)

    /**
     *  void CPRINTLN_IN(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_INPUT` function.
     *
     *  Print input line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_IN(color, str)     CPRINTLN_INPUT(color, str)

    /**
     *  void CPRINTF_IN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_IN(color, ...)      CPRINTF_INPUT(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_IN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_IN(color, ...)    CPRINTFLN_INPUT(color, __VA_ARGS__)


    /**
     *  void CPRINT_WARN(const char* color, const char* str);
     *
     *  Alias of `CPRINT_WARNING` function.
     *
     *  Print warning line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_WARN(color, str)     CPRINT_WARNING(color, str)

    /**
     *  void CPRINTLN_WARN(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_WARN(color, str)   CPRINTLN_WARNING(color, str)

    /**
     *  void CPRINTF_WARN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_WARN(color, ...)    CPRINTF_WARNING(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_WARN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_WARN(color, ...)  CPRINTFLN_WARNING(color, __VA_ARGS__)


    /**
     *  void CPERROR_WARN(const char* color, const char* str);
     *
     *  Alias of `CPERROR_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_WARN(color, str)    CPERROR_WARNING(color, str)

    /**
     *  void CPERRORF_WARN(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_WARN(color, ...)   CPERRORF_WARNING(color, __VA_ARGS__)


    /**
     *  void CPRINT_ERR(const char* color, const char* str);
     *
     *  Alias of `CPRINT_ERROR` function.
     *
     *  Print error line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_ERR(color, str)      CPRINT_ERROR(color, str)

    /**
     *  void CPRINTLN_ERR(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_ERR(color, str)    CPRINTLN_ERROR(color, str)

    /**
     *  void CPRINTF_ERR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_ERR(color, ...)     CPRINTF_ERROR(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_ERR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_ERR(color, ...)   CPRINTFLN_ERROR(color, __VA_ARGS__)


    /**
     *  void CPERROR_ERR(const char* color, const char* str);
     *
     *  Alias of `CPERROR_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_ERR(color, str)     CPERROR_ERROR(color, str)

    /**
     *  void CPERRORF_ERR(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_ERR(color, ...)    CPERRORF_ERROR(color, __VA_ARGS__)


    /**
     *  void CPRINT_CRIT(const char* color, const char* str);
     *
     *  Alias of `CPRINT_CRITICAL` function.
     *
     *  Print critical line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_CRIT(color, str)     CPRINT_CRITICAL(color, str)

    /**
     *  void CPRINTLN_CRIT(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_CRIT(color, str)   CPRINTLN_CRITICAL(color, str)

    /**
     *  void CPRINTF_CRIT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_CRIT(color, ...)    CPRINTF_CRITICAL(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_CRIT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_CRIT(color, ...)  CPRINTFLN_CRITICAL(color, __VA_ARGS__)


    /**
     *  void CPERROR_CRIT(const char* color, const char* str);
     *
     *  Alias of `CPERROR_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_CRIT(color, str)    CPERROR_CRITICAL(color, str)

    /**
     *  void CPERRORF_CRIT(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_CRIT(color, ...)   CPERRORF_CRITICAL(color, __VA_ARGS__)


    /**
     *  void CPRINT_FAT(const char* color, const char* str);
     *
     *  Alias of `CPRINT_FATAL` function.
     *
     *  Print fatal line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_FAT(color, str)      CPRINT_FATAL(color, str)

    /**
     *  void CPRINTLN_FAT(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_FAT(color, str)    CPRINTLN_FATAL(color, str)

    /**
     *  void CPRINTF_FAT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_FAT(color, ...)     CPRINTF_FATAL(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_FAT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_FAT(color, ...)   CPRINTFLN_FATAL(color, __VA_ARGS__)


    /**
     *  void CPERROR_FAT(const char* color, const char* str);
     *
     *  Alias of `CPERROR_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_FAT(color, str)     CPERROR_FATAL(color, str)

    /**
     *  void CPERRORF_FAT(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_FAT(color, ...)    CPERRORF_FATAL(color, __VA_ARGS__)

#endif


/**
 *  "cprint_level" Shorter Aliases
 *  ------------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  void CPRINT_TR(const char* color, const char* str);
     *
     *  Alias of `CPRINT_TRACE` function.
     *
     *  Print trace line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_TR(color, str)       CPRINT_TRACE(color, str)

    /**
     *  void CPRINTLN_TR(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_TRACE` function.
     *
     *  Print trace line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_TR(color, str)     CPRINTLN_TRACE(color, str)

    /**
     *  void CPRINTF_TR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_TR(color, ...)      CPRINTF_TRACE(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_TR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_TRACE` function.
     *
     *  Print trace line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_TR(color, ...)    CPRINTFLN_TRACE(color, __VA_ARGS__)


    /**
     *  void CPRINT_DB(const char* color, const char* str);
     *
     *  Alias of `CPRINT_DEBUG` function.
     *
     *  Print debug line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_DB(color, str)       CPRINT_DEBUG(color, str)

    /**
     *  void CPRINTLN_DB(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_DEBUG` function.
     *
     *  Print debug line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_DB(color, str)     CPRINTLN_DEBUG(color, str)

    /**
     *  void CPRINTF_DB(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_DB(color, ...)      CPRINTF_DEBUG(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_DB(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_DEBUG` function.
     *
     *  Print debug line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_DB(color, ...)    CPRINTFLN_DEBUG(color, __VA_ARGS__)


    /**
     *  void CPRINT_EX(const char* color, const char* str);
     *
     *  Alias of `CPRINT_EXTRA` function.
     *
     *  Print extra line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_EX(color, str)       CPRINT_EXTRA(color, str)

    /**
     *  void CPRINTLN_EX(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_EXTRA` function.
     *
     *  Print extra line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_EX(color, str)     CPRINTLN_EXTRA(color, str)

    /**
     *  void CPRINTF_EX(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_EX(color, ...)      CPRINTF_EXTRA(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_EX(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_EXTRA` function.
     *
     *  Print extra line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_EX(color, ...)    CPRINTFLN_EXTRA(color, __VA_ARGS__)


    /**
     *  void CPRINT_IF(const char* color, const char* str);
     *
     *  Alias of `CPRINT_INFO` function.
     *
     *  Print info line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_IF(color, str)       CPRINT_INFO(color, str)

    /**
     *  void CPRINTLN_IF(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_INFO` function.
     *
     *  Print info line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_IF(color, str)     CPRINTLN_INFO(color, str)

    /**
     *  void CPRINTF_IF(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_IF(color, ...)      CPRINTF_INFO(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_IF(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_INFO` function.
     *
     *  Print info line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_IF(color, ...)    CPRINTFLN_INFO(color, __VA_ARGS__)


    /**
     *  void CPRINT_HD(const char* color, const char* str);
     *
     *  Alias of `CPRINT_HEADER` function.
     *
     *  Print header line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_HD(color, str)       CPRINT_HEADER(color, str)

    /**
     *  void CPRINTLN_HD(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_HEADER` function.
     *
     *  Print header line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_HD(color, str)     CPRINTLN_HEADER(color, str)

    /**
     *  void CPRINTF_HD(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_HD(color, ...)      CPRINTF_HEADER(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_HD(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_HEADER` function.
     *
     *  Print header line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_HD(color, ...)    CPRINTFLN_HEADER(color, __VA_ARGS__)


    /**
     *  void CPRINT_SC(const char* color, const char* str);
     *
     *  Alias of `CPRINT_SUCCESS` function.
     *
     *  Print success line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_SC(color, str)       CPRINT_SUCCESS(color, str)

    /**
     *  void CPRINTLN_SC(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_SUCCESS` function.
     *
     *  Print success line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_SC(color, str)     CPRINTLN_SUCCESS(color, str)

    /**
     *  void CPRINTF_SC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_SC(color, ...)      CPRINTF_SUCCESS(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_SC(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_SUCCESS` function.
     *
     *  Print success line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_SC(color, ...)    CPRINTFLN_SUCCESS(color, __VA_ARGS__)


    /**
     *  void CPRINT_MN(const char* color, const char* str);
     *
     *  Alias of `CPRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_MN(color, str)       CPRINT_MONEY(color, str)

    /**
     *  void CPRINTLN_MN(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_MN(color, str)     CPRINTLN_MONEY(color, str)

    /**
     *  void CPRINTF_MN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_MN(color, ...)      CPRINTF_MONEY(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_MN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_MN(color, ...)    CPRINTFLN_MONEY(color, __VA_ARGS__)


    /**
     *  void CPRINT_MY(const char* color, const char* str);
     *
     *  Alias of `CPRINT_MONEY` function.
     *
     *  Print money line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_MY(color, str)       CPRINT_MONEY(color, str)

    /**
     *  void CPRINTLN_MY(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_MONEY` function.
     *
     *  Print money line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_MY(color, str)     CPRINTLN_MONEY(color, str)

    /**
     *  void CPRINTF_MY(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_MY(color, ...)      CPRINTF_MONEY(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_MY(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_MONEY` function.
     *
     *  Print money line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_MY(color, ...)    CPRINTFLN_MONEY(color, __VA_ARGS__)


    /**
     *  void CPRINT_IN(const char* color, const char* str);
     *
     *  Alias of `CPRINT_INPUT` function.
     *
     *  Print input line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_IN(color, str)       CPRINT_INPUT(color, str)

    /**
     *  void CPRINTLN_IN(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_INPUT` function.
     *
     *  Print input line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_IN(color, str)     CPRINTLN_INPUT(color, str)

    /**
     *  void CPRINTF_IN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_IN(color, ...)      CPRINTF_INPUT(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_IN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_INPUT` function.
     *
     *  Print input line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_IN(color, ...)    CPRINTFLN_INPUT(color, __VA_ARGS__)


    /**
     *  void CPRINT_WN(const char* color, const char* str);
     *
     *  Alias of `CPRINT_WARNING` function.
     *
     *  Print warning line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_WN(color, str)       CPRINT_WARNING(color, str)

    /**
     *  void CPRINTLN_WN(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_WN(color, str)     CPRINTLN_WARNING(color, str)

    /**
     *  void CPRINTF_WN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_WN(color, ...)      CPRINTF_WARNING(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_WN(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_WN(color, ...)    CPRINTFLN_WARNING(color, __VA_ARGS__)


    /**
     *  void CPERROR_WN(const char* color, const char* str);
     *
     *  Alias of `CPERROR_WARNING` function.
     *
     *  Print warning line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_WN(color, str)      CPERROR_WARNING(color, str)

    /**
     *  void CPERRORF_WN(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_WARNING` function.
     *
     *  Print warning line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_WN(color, ...)     CPERRORF_WARNING(color, __VA_ARGS__)


    /**
     *  void CPRINT_ER(const char* color, const char* str);
     *
     *  Alias of `CPRINT_ERROR` function.
     *
     *  Print error line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_ER(color, str)       CPRINT_ERROR(color, str)

    /**
     *  void CPRINTLN_ER(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_ER(color, str)     CPRINTLN_ERROR(color, str)

    /**
     *  void CPRINTF_ER(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_ER(color, ...)      CPRINTF_ERROR(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_ER(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_ER(color, ...)    CPRINTFLN_ERROR(color, __VA_ARGS__)


    /**
     *  void CPERROR_ER(const char* color, const char* str);
     *
     *  Alias of `CPERROR_ERROR` function.
     *
     *  Print error line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_ER(color, str)      CPERROR_ERROR(color, str)

    /**
     *  void CPERRORF_ER(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_ERROR` function.
     *
     *  Print error line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_ER(color, ...)     CPERRORF_ERROR(color, __VA_ARGS__)


    /**
     *  void CPRINT_CR(const char* color, const char* str);
     *
     *  Alias of `CPRINT_CRITICAL` function.
     *
     *  Print critical line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_CR(color, str)       CPRINT_CRITICAL(color, str)

    /**
     *  void CPRINTLN_CR(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_CR(color, str)     CPRINTLN_CRITICAL(color, str)

    /**
     *  void CPRINTF_CR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_CR(color, ...)      CPRINTF_CRITICAL(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_CR(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_CR(color, ...)    CPRINTFLN_CRITICAL(color, __VA_ARGS__)


    /**
     *  void CPERROR_CR(const char* color, const char* str);
     *
     *  Alias of `CPERROR_CRITICAL` function.
     *
     *  Print critical line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_CR(color, str)      CPERROR_CRITICAL(color, str)

    /**
     *  void CPERRORF_CR(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_CRITICAL` function.
     *
     *  Print critical line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_CR(color, ...)     CPERRORF_CRITICAL(color, __VA_ARGS__)


    /**
     *  void CPRINT_FT(const char* color, const char* str);
     *
     *  Alias of `CPRINT_FATAL` function.
     *
     *  Print fatal line header followed by the given string to standard
     *  output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINT_FT(color, str)       CPRINT_FATAL(color, str)

    /**
     *  void CPRINTLN_FT(const char* color, const char* str);
     *
     *  Alias of `CPRINTLN_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPRINTLN_FT(color, str)     CPRINTLN_FATAL(color, str)

    /**
     *  void CPRINTF_FT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTF_FT(color, ...)      CPRINTF_FATAL(color, __VA_ARGS__)

    /**
     *  void CPRINTFLN_FT(const char* color, const char* format, ...);
     *
     *  Alias of `CPRINTFLN_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a newline.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPRINTFLN_FT(color, ...)    CPRINTFLN_FATAL(color, __VA_ARGS__)


    /**
     *  void CPERROR_FT(const char* color, const char* str);
     *
     *  Alias of `CPERROR_FATAL` function.
     *
     *  Print fatal line header followed by given string to standard output
     *  and then print the C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  str         String to print.
     */
    #define CPERROR_FT(color, str)      CPERROR_FATAL(color, str)

    /**
     *  void CPERRORF_FT(const char* color, const char* format, ...);
     *
     *  Alias of `CPERRORF_FATAL` function.
     *
     *  Print fatal line header followed by given format string and format
     *  arguments to standard output followed by a C error message.
     *
     *  @param  color       ANZI terminal code to prefix string with.
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CPERRORF_FT(color, ...)     CPERRORF_FATAL(color, __VA_ARGS__)

#endif


/**
 *  Logging
 *  =======
 *
 *  Logging is also provided and there are some configuration options. There
 *  are three different main types of logging provided:
 *
 *       - The "clog" functions provide console logging to standard error.
 *
 *       - The "flog" functions provide file logging to the file set in the
 *       configuration header or to the default which is the '<file.c>.log'
 *       where `<file.c>` is the name of the C file using the logger.
 *
 *       - The "log" functions provide console and file logging if it is
 *       enabled in the configuration.
 *
 *  Logs are typically one line (but may be more) and are composed of a line
 *  header (with several elements) and a log message. Log elements may include
 *  a timestamp followed by a line header separator, a log level symbol
 *  followed by a line header separator, and, if enabled, a tracing group
 *  (which may be composed by a filename, function name, and line number
 *  separated by a tracing separator), followed by a line header separator. For
 *  example:
 *
 *      "2025-04-29T06:49:16-04:00 [-] This is an error."
 *              ^                 ^ ^ ^ ^
 *              |                 | | | |
 *          timestamp            sep|sep'------ message
 *                                  |
 *                                level symbol (error log)
 *
 *      "2025-04-29:06:49=[DEBUG]=file.c:function:22=This is an error."
 *            ^          ^     ^ ^'----------------'^     ^
 *            |          |     | |       |          |     |
 *  custom timestamp custom sep| sep  tracing info  sep   message
 *                             |
 *                           level symbol (debug log)
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
 *      ** Note **: File logging never has colored logs.
 */

#ifndef CLOG_CONSOLE_MODE_NOCOLOR
/**
 *  Console logging mode option to disable log level color printing in
 *  console logging functions ("clog" and "log" functions).
 */
#define CLOG_CONSOLE_MODE_NOCOLOR 0
#endif

#ifndef CLOG_CONSOLE_MODE_COLOR
/**
 *  Console logging mode option to enable log level color printing in
 *  console logging functions ("clog" and "log" functions).
 */
#define CLOG_CONSOLE_MODE_COLOR 1
#endif

#ifndef CLOG_CONSOLE_MODE
/**
 *  Console logging mode which may be color mode or no-color mode. Colored
 *  mode will print console logs in predetermined colors based on log
 *  level colors. May be one of the following values:
 *
 *      CLOG_CONSOLE_MODE_NOCOLOR
 *      CLOG_CONSOLE_MODE_COLOR
 */
#define CLOG_CONSOLE_MODE CLOG_CONSOLE_MODE_COLOR
#endif


/**
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
 *      ** Note **: All disabled logging calls are removed from the
 *      compilation (preprocessed out) through undefine or empty redefine
 *      macros. String declarations outside of logging calls may not
 *      be preprocessed out.
 */

#ifndef CLOG_MODE_NONE
    /**
     *  Clog logging mode option "none". Disable all "clog", "flog", and
     *  "log" functions.
     */
    #define CLOG_MODE_NONE              0
#endif

#ifndef CLOG_MODE_CONSOLE
    /**
     *  Clog logging mode option "console". Set "log" functions to log to
     *  console only.
     */
    #define CLOG_MODE_CONSOLE           1
#endif

#ifndef CLOG_MODE_FILE
    /**
     *  Clog logging mode option "file". Set "log" functions to log to file
     *  only.
     */
    #define CLOG_MODE_FILE              2
#endif

#ifndef CLOG_MODE_CONSOLE_AND_FILE
    /**
     *  Clog logging mode option "console and file". Set "log" functions to log
     *  to console and file.
     */
    #define CLOG_MODE_CONSOLE_AND_FILE  3
#endif

#ifndef CLOG_MODE
    /**
     *  Clog logging mode. Controls "log" function behavior to log to the
     *  console, a file, or both. If set to "none", also disables other logging
     *  functions like "clog" and "flog". Defaults to
     *  `CLOG_MODE_CONSOLE_AND_FILE`. May be set to one of the following
     *  values:
     *
     *      CLOG_MODE_NONE
     *      CLOG_MODE_CONSOLE
     *      CLOG_MODE_FILE
     *      CLOG_MODE_CONSOLE_AND_FILE  (default)
     */
    #define CLOG_MODE                   CLOG_MODE_CONSOLE_AND_FILE
#endif


/**
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
 */

#ifndef CLOG_LEVEL_NONE
    /**
     *  Clog level option "none". Disable all logs with a level.
     */
    #define CLOG_LEVEL_NONE     0
#endif

#ifndef CLOG_LEVEL_CRITICAL
    /**
     *  Clog level option "critical". Disable all logs with a level except for
     *  logs with a CRITICAL or FATAL level.
     */
    #define CLOG_LEVEL_CRITICAL 1
#endif

#ifndef CLOG_LEVEL_ERROR
    /**
     *  Clog level option "error". Disable all logs with a level except for
     *  logs with an ERROR, CRITICAL, or FATAL level.
     */
    #define CLOG_LEVEL_ERROR    2
#endif

#ifndef CLOG_LEVEL_WARNING
    /**
     *  Clog level option "warning". Disable all logs with a level except for
     *  logs with a WARNING, ERROR, CRITICAL, or FATAL level.
     */
    #define CLOG_LEVEL_WARNING  3
#endif

#ifndef CLOG_LEVEL_INFO
    /**
     *  Clog level option "info". Disable all logs with a level except for
     *  logs with a INFO (include HEADER, SUCCESS, MONEY, and INPUT), WARNING,
     *  ERROR, CRITICAL, or FATAL level.
     */
    #define CLOG_LEVEL_INFO     4
#endif

#ifndef CLOG_LEVEL_EXTRA
    /**
     *  Clog level option "extra". Disable all logs with a level except for
     *  logs with an EXTRA, INFO (include HEADER, SUCCESS, MONEY, and INPUT),
     *  WARNING, ERROR, CRITICAL, or FATAL level.
     */
    #define CLOG_LEVEL_EXTRA    5
#endif

#ifndef CLOG_LEVEL_DEBUG
    /**
     *  Clog level option "debug". Disable all logs with a level except for
     *  logs with a DEBUG, EXTRA, INFO (include HEADER, SUCCESS, MONEY, and
     *  INPUT), WARNING, ERROR, CRITICAL, or FATAL level.
     */
    #define CLOG_LEVEL_DEBUG    6
#endif

#ifndef CLOG_LEVEL_ALL
    /**
     *  Clog level option "all". Enables all log levels include TRACE logs.
     */
    #define CLOG_LEVEL_ALL      7
#endif


#ifndef CLOG_LEVEL
    /**
     *  Clog log level to enable logging for. May be adjusted to limit logging
     *  to different levels (and levels lower than the level selected).
     *  Defaults to `CLOG_LEVEL_ALL`. May be set to one of the following
     *  values:
     *
     *      CLOG_LEVEL_NONE
     *      CLOG_LEVEL_CRITICAL
     *      CLOG_LEVEL_ERROR
     *      CLOG_LEVEL_WARNING
     *      CLOG_LEVEL_INFO
     *      CLOG_LEVEL_EXTRA
     *      CLOG_LEVEL_DEBUG
     *      CLOG_LEVEL_ALL
     */
    #define CLOG_LEVEL          CLOG_LEVEL_ALL
#endif


/**
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
 */

#ifndef CLOG_FILE
    /**
     *  File path of the file to use for file logging functions. Defaults to C
     *  source filename with the appended extension ".log". This may be
     *  adjusted via the Clog Configuration Header.
*/
    #define CLOG_FILE \
        (strchr(__FILE__, '/') \
            ? strrchr(__FILE__ ".log", '/') + 1 : __FILE__ ".log")
#endif


/**
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
 */

#ifndef CLOG_TIME_FORMAT
    #ifdef CLOG_USE_UTC_TIME
        /**
         *  The time format used for timestamping. Defaults to ANZI ISO 8601
         *  localtime format. But it may configured to C time format string via
         *  the configuration header. If CLOG_USE_UTC_TIME is defined, defaults
         *  to UTC timestamp.
         */
        #define CLOG_TIME_FORMAT    "%FT%TZ"

    #else
        /**
         *  The time format used for timestamping. Defaults to ANZI ISO 8601
         *  localtime format. But it may configured to C time format string via
         *  the configuration header.
         */
        #define CLOG_TIME_FORMAT    "%FT%T%z"
    #endif
#endif


/**
 *  Tracing Separator
 *  -----------------
 *
 *  The tracing separator separates tracing elements. Defaults to a colon.
 *  For example, "file.c:function:22" where "file.c" is the file,
 *  "function" is the function that called the log function, and "22" is
 *  the line number of the log call. This can be configured to be a different
 *  string.
 */

#ifndef CLOG_TRACING_SEP
    /**
     *  The tracing separator separates tracing elements. Defaults to a colon.
     *  For example, "file.c:function:22" where "file.c" is the file,
     *  "function" is the function that called the log function, and "22" is
     *  the line number of the log call.
     */
    #define CLOG_TRACING_SEP    ":"
#endif


/* Logging Initialization and internal macros. */

#define _CLOG_TM_BUFSZ          256
#define _CLOG_TM_FMT            CLOG_TIME_FORMAT

#define _CLOG_DECLARE \
    static FILE* __attribute__((__unused__)) _clog_glog = NULL; \
    static char  __attribute__((__unused__)) _clog_gtime_buf[_CLOG_TM_BUFSZ] = {0}; \
    static time_t __attribute__((__unused__)) _clog_gtime = 0;


#ifdef CLOG_DISABLE_TIMESTAMPS
    #define _CLOG_TIME(...)

#else
    #ifdef CLOG_USE_UTC_TIME
        #define _CLOG_TIME(f) \
            time(&_clog_gtime); \
            strftime( \
                _clog_gtime_buf, \
                _CLOG_TM_BUFSZ, \
                _CLOG_TM_FMT, \
                gmtime(&_clog_gtime) \
            ); \
            FPRINTF(f, "%s" CLOG_LINE_HEADER_SEP, _clog_gtime_buf);

    #else
        #define _CLOG_TIME(f) \
            time(&_clog_gtime); \
            strftime( \
                _clog_gtime_buf, \
                _CLOG_TM_BUFSZ, \
                _CLOG_TM_FMT, \
                localtime(&_clog_gtime) \
            ); \
            FPRINTF(f, "%s" CLOG_LINE_HEADER_SEP, _clog_gtime_buf);
    #endif
#endif


#ifdef CLOG_DISABLE_TRACING
    #define _CLOG_TRACING(...)
    #define _CLOG_CTRACING(...)

#else
    #define _CLOG_TRACING(f) \
        FPRINTF( \
            f, \
            "%s" CLOG_TRACING_SEP\
            "%s" CLOG_TRACING_SEP\
            "%u" CLOG_LINE_HEADER_SEP, \
            strchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__, \
            __FUNCTION__, \
            __LINE__ \
        );

    #define _CLOG_CTRACING(f) \
        FPRINTF( \
            f, \
            C_BR_BLUE "%s" CLOG_TRACING_SEP C_RESET \
            C_ORANGE "%s" CLOG_TRACING_SEP C_RESET \
            C_BR_MAGENTA "%u" CLOG_LINE_HEADER_SEP C_RESET, \
            strchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__, \
            __FUNCTION__, \
            __LINE__ \
        );
#endif


/**
 *  Console Logging
 *  ===============
 *
 *  Console logging obeys log level and log console color mode configuration
 *  options and prints to standard error. Console logging also includes a
 *  timestamp and log level symbol string line header if enabled and using the
 *  log level functions.
 *
 *
 *  "clog" Functions
 *  =================
 *
 *  The "clog" series are for printing to standard err and prepend the log with
 *  a timestamp.
 *
 *  There are several function-like macros available:
 *
 *      CLOG(const char* str)
 *      CLOGLN(const char* str)
 *      CLOGF(const char* format, ...)
 *      CLOGFLN(const char* format, ...)
 *      CLOG_HEX(const uint8_t* buffer, size_t length)
 *      CLOGLN_HEX(const uint8_t* buffer, size_t length)
 *      CLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      CLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      CLOG_PERROR(const char* str)
 *      CLOG_PERRORF(const char* format, ...)
 *
 *  Examples
 *  --------
 *
 *      `CLOG("Hello"); printf("you");`
 *
 *          Output: `2025-04-29T06:49:16-04:00 Helloyou`
 *
 *      `int i = 15; CLOG_HEX(&i, sizeof(int));`
 *
 *          Output: `2025-04-29T06:49:16-04:00 0f000000`.
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CLOG(const char* str);
 *
 *  Print timestamp and the given string to standard error.
 *
 *  @param  str         String to print.
 */
#define CLOG(str) { \
    _CLOG_TIME(stderr); \
    FPRINT(stderr, str); \
}

/**
 *  void CLOGLN(const char* str);
 *
 *  Print timestamp and the given string to standard error followed by a
 *  newline.
 *
 *  @param  str         String to print.
 */
#define CLOGLN(str) { \
    _CLOG_TIME(stderr); \
    FPRINTLN(stderr, str); \
}

/**
 *  void CLOGF(const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF(...) { \
    _CLOG_TIME(stderr); \
    FPRINTF(stderr, __VA_ARGS__); \
}

/**
 *  void CLOGFLN(const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN(...) { \
    _CLOG_TIME(stderr); \
    FPRINTFLN(stderr, __VA_ARGS__); \
}

/**
 *  void CLOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string to
 *  standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOG_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    FPRINT_HEX(stderr, buffer, length); \
}

/**
 *  void CLOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string to
 *  standard error followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOGLN_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    FPRINTLN_HEX(stderr, buffer, length); \
}

/**
 *  void CLOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOG_WIDE_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    FPRINT_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOGLN_WIDE_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    FPRINTLN_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CLOG_PERROR(const char* str);
 *
 *  Print timestamp and the given string to standard error and then print the C
 *  error message.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR(str) { \
    _CLOG_TIME(stderr); \
    FPERROR(stderr, str); \
}

/**
 *  void CLOG_PERRORF(const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF(...) { \
    _CLOG_TIME(stderr); \
    FPERRORF(stderr, __VA_ARGS__); \
}


/**
 *  "clog_stream" Functions
 *  -----------------------
 *
 *  The "clog_stream" series are for printing to standard err just like the
 *  "clog" functions, but these ones do NOT prepend the log with a timestamp,
 *  so they can be used to continue lines without a line break or for logging
 *  data without having a timestamp.
 *
 *  There are several function-like macros available:
 *
 *      CLOG_STREAM(const char* str)
 *      CLOGLN_STREAM(const char* str)
 *      CLOGF_STREAM(const char* format, ...)
 *      CLOGFLN_STREAM(const char* format, ...)
 *      CLOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      CLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      CLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      CLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      CLOG_PERROR_STREAM(const char* str)
 *      CLOG_PERRORF_STREAM(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CLOG_STREAM(const char* str);
 *
 *  Print the given string to standard error.
 *
 *  @param  str         String to print.
 */
#define CLOG_STREAM(str) { \
    FPRINT(stderr, str); \
}

/**
 *  void CLOGLN_STREAM(const char* str);
 *
 *  Print the given string to standard error followed by a newline.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_STREAM(str) { \
    FPRINTLN(stderr, str); \
}

/**
 *  void CLOGF_STREAM(const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_STREAM(...) { \
    FPRINTF(stderr, __VA_ARGS__); \
}

/**
 *  void CLOGFLN_STREAM(const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error
 *  followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_STREAM(...) { \
    FPRINTFLN(stderr, __VA_ARGS__); \
}

/**
 *  void CLOG_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOG_HEX_STREAM(buffer, length) { \
    FPRINT_HEX(stderr, buffer, length); \
}

/**
 *  void CLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string to standard error
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOGLN_HEX_STREAM(buffer, length) { \
    FPRINTLN_HEX(stderr, buffer, length); \
}

/**
 *  void CLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOG_WIDE_HEX_STREAM(buffer, length) { \
    FPRINT_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error followed by a
 *  newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CLOGLN_WIDE_HEX_STREAM(buffer, length) { \
    FPRINTLN_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CLOG_PERROR_STREAM(const char* str);
 *
 *  Print the given string to standard error and then print the C error
 *  message.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR_STREAM(str) { \
    FPERROR(stderr, str); \
}

/**
 *  void CLOG_PERRORF_STREAM(const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error
 *  followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF_STREAM(...) { \
    FPERRORF(stderr, __VA_ARGS__); \
}


/**
 *  "ctlog" Functions
 *  -----------------
 *
 *  The "ctlog" series also print to standard error with a timestamp just like
 *  the "clog" functions. But these functions also add a tracing element to the
 *  log for the case where you specifically want tracing information.
 *
 *  There are several function-like macros available:
 *
 *      CTLOG(const char* str)
 *      CTLOGLN(const char* str)
 *      CTLOGF(const char* format, ...)
 *      CTLOGFLN(const char* format, ...)
 *      CTLOG_HEX(const uint8_t* buffer, size_t length)
 *      CTLOGLN_HEX(const uint8_t* buffer, size_t length)
 *      CTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      CTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      CTLOG_PERROR(const char* str)
 *      CTLOG_PERRORF(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CTLOG(const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error.
 *
 *  @param  str         String to print.
 */
#define CTLOG(str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINT(stderr, str); \
}

/**
 *  void CTLOGLN(const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error followed by a newline.
 *
 *  @param  str         String to print.
 */
#define CTLOGLN(str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINTLN(stderr, str); \
}

/**
 *  void CTLOGF(const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CTLOGF(...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINTF(stderr, __VA_ARGS__); \
}

/**
 *  void CTLOGFLN(const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CTLOGFLN(...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINTFLN(stderr, __VA_ARGS__); \
}

/**
 *  void CTLOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CTLOG_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINT_HEX(stderr, buffer, length); \
}

/**
 *  void CTLOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to standard error followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CTLOGLN_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINTLN_HEX(stderr, buffer, length); \
}

/**
 *  void CTLOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to standard error.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CTLOG_WIDE_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINT_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to standard error followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CTLOGLN_WIDE_HEX(buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr); \
    FPRINTLN_WIDE_HEX(stderr, buffer, length); \
}

/**
 *  void CTLOG_PERROR(const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define CTLOG_PERROR(str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    FPERROR(stderr, str); \
}

/**
 *  void CTLOG_PERRORF(const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CTLOG_PERRORF(...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    FPERRORF(stderr, __VA_ARGS__); \
}


/**
 *  "cclog" Functions
 *  -----------------
 *
 *  The "cclog" series also print to standard error with a timestamp just like
 *  the "clog" functions. But these functions have a color parameter and output
 *  colored text.
 *
 *  There are several function-like macros available:
 *
 *      CCLOG(const char* color, const char* str)
 *      CCLOGLN(const char* color, const char* str)
 *      CCLOGF(const char* color, const char* format, ...)
 *      CCLOGFLN(const char* color, const char* format, ...)
 *      CCLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CCLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CCLOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CCLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCLOG_PERROR(const char* color, const char* str)
 *      CCLOG_PERRORF(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CCLOG(const char* color, const char* str);
 *
 *  Print timestamp and the given string to standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOG(color, str) { \
    _CLOG_TIME(stderr); \
    CFPRINT(color, stderr, str); \
}

/**
 *  void CCLOGLN(const char* color, const char* str);
 *
 *  Print timestamp and the given string to standard error followed by a
 *  newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOGLN(color, str) { \
    _CLOG_TIME(stderr); \
    CFPRINTLN(color, stderr, str); \
}

/**
 *  void CCLOGF(const char* color, const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOGF(color, ...) { \
    _CLOG_TIME(stderr); \
    CFPRINTF(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCLOGFLN(const char* color, const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOGFLN(color, ...) { \
    _CLOG_TIME(stderr); \
    CFPRINTFLN(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCLOG_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string to
 *  standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOG_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    CFPRINT_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print timestamp and the bytes of the given buffer as a hex string to
 *  standard error followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOGLN_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    CFPRINTLN_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOG_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOG_WIDE_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    CFPRINT_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOGLN_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOGLN_WIDE_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    CFPRINTLN_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOG_PERROR(const char* color, const char* str);
 *
 *  Print timestamp and the given string to standard error and then print the C
 *  error message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOG_PERROR(color, str) { \
    _CLOG_TIME(stderr); \
    CFPERROR(color, stderr, str); \
}

/**
 *  void CCLOG_PERRORF(const char* color, const char* format, ...);
 *
 *  Print timestamp and the given format string and format arguments to
 *  standard error followed by a C error message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOG_PERRORF(color, ...) { \
    _CLOG_TIME(stderr); \
    CFPERRORF(color, stderr, __VA_ARGS__); \
}


/**
 *  "cclog_stream" Functions
 *  ------------------------
 *
 *  The "clog_stream" series are for printing to standard err just like the
 *  "clog" functions, but these ones do NOT prepend the log with a timestamp,
 *  so they can be used to continue lines without a line break or for logging
 *  data without having a timestamp in the given color. And
 *  these function allow you to specify color for the log message.
 *
 *  There are several function-like macros available:
 *
 *      CCLOG_STREAM(const char* color, const char* str)
 *      CCLOGLN_STREAM(const char* color, const char* str)
 *      CCLOGF_STREAM(const char* color, const char* format, ...)
 *      CCLOGFLN_STREAM(const char* color, const char* format, ...)
 *      CCLOG_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCLOGLN_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCLOG_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCLOGLN_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCLOG_PERROR_STREAM(const char* color, const char* str)
 *      CCLOG_PERRORF_STREAM(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CCLOG_STREAM(const char* color, const char* str);
 *
 *  Print the given string to standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOG_STREAM(color, str) { \
    CFPRINT(color, stderr, str); \
}

/**
 *  void CCLOGLN_STREAM(const char* color, const char* str);
 *
 *  Print the given string to standard error followed by a newline in the given
 *  color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOGLN_STREAM(color, str) { \
    CFPRINTLN(color, stderr, str); \
}

/**
 *  void CCLOGF_STREAM(const char* color, const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error in the
 *  given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOGF_STREAM(color, ...) { \
    CFPRINTF(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCLOGFLN_STREAM(const char* color, const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error
 *  followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOGFLN_STREAM(color, ...) { \
    CFPRINTFLN(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCLOG_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string to standard error in
 *  the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOG_HEX_STREAM(color, buffer, length) { \
    CFPRINT_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOGLN_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string to standard error
 *  followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOGLN_HEX_STREAM(color, buffer, length) { \
    CFPRINTLN_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOG_WIDE_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error in the given
 *  color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOG_WIDE_HEX_STREAM(color, buffer, length) { \
    CFPRINT_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOGLN_WIDE_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error followed by a
 *  newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCLOGLN_WIDE_HEX_STREAM(color, buffer, length) { \
    CFPRINTLN_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOG_PERROR_STREAM(const char* color, const char* str);
 *
 *  Print the given string to standard error and then print the C error
 *  message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCLOG_PERROR_STREAM(color, str) { \
    CFPERROR(color, stderr, str); \
}

/**
 *  void CCLOG_PERRORF_STREAM(const char* color, const char* format, ...);
 *
 *  Print the given format string and format arguments to standard error
 *  followed by a C error message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCLOG_PERRORF_STREAM(color, ...) { \
    CFPERRORF(color, stderr, __VA_ARGS__); \
}


/**
 *  "cctlog" Functions
 *  ------------------
 *
 *  The "cctlog" series also print to standard error with a timestamp just like
 *  the "cclog" functions. But these functions also add a tracing element to
 *  the log for the case where you specifically want tracing information. And
 *  these function allow you to specify color for the log message.
 *
 *  There are several function-like macros available:
 *
 *      CCTLOG(const char* color, const char* str)
 *      CCTLOGLN(const char* color, const char* str)
 *      CCTLOGF(const char* color, const char* format, ...)
 *      CCTLOGFLN(const char* color, const char* format, ...)
 *      CCTLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CCTLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      CCTLOG_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCTLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      CCTLOG_PERROR(const char* color, const char* str)
 *      CCTLOG_PERRORF(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CCTLOG(const char* color, const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCTLOG(color, str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINT(color, stderr, str); \
}

/**
 *  void CCTLOGLN(const char* color, const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCTLOGLN(color, str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINTLN(color, stderr, str); \
}

/**
 *  void CCTLOGF(const char* color, const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCTLOGF(color, ...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINTF(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCTLOGFLN(const char* color, const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error followed by a newline in the given
 *  color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCTLOGFLN(color, ...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINTFLN(color, stderr, __VA_ARGS__); \
}

/**
 *  void CCTLOG_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCTLOG_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINT_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCTLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to standard error followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCTLOGLN_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINTLN_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCTLOG_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to standard error in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCTLOG_WIDE_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINT_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCLOGLN_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Print timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to standard error followed by a newline in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define CCTLOGLN_WIDE_HEX(color, buffer, length) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPRINTLN_WIDE_HEX(color, stderr, buffer, length); \
}

/**
 *  void CCTLOG_PERROR(const char* color, const char* str);
 *
 *  Print timestamp, tracing information, and the given string to standard
 *  error and then print the C error message in the given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define CCTLOG_PERROR(color, str) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPERROR(color, stderr, str); \
}

/**
 *  void CCTLOG_PERRORF(const char* color, const char* format, ...);
 *
 *  Print timestamp, tracing information, and the given format string and
 *  format arguments to standard error followed by a C error message in the
 *  given color.
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CCTLOG_PERRORF(color, ...) { \
    _CLOG_TIME(stderr); \
    _CLOG_CTRACING(stderr) \
    CFPERRORF(color, stderr, __VA_ARGS__); \
}


#if CLOG_CONSOLE_MODE == CLOG_CONSOLE_MODE_NOCOLOR

    #define _CLOG(color, str) \
        CLOG(str)

    #define _CLOGLN(color, str) \
        CLOGLN(str)

    #define _CLOGF(color, ...) \
        CLOGF(__VA_ARGS__)

    #define _CLOGFLN(color, ...) \
        CLOGFLN(__VA_ARGS__)

    #define _CLOG_HEX(color, buffer, length) \
        CLOG_HEX(buffer, length)

    #define _CLOGLN_HEX(color, buffer, length) \
        CLOGLN_HEX(buffer, length)

    #define _CLOG_WIDE_HEX(color, buffer, length) \
        CLOG_WIDE_HEX(buffer, length)

    #define _CLOGLN_WIDE_HEX(color, buffer, length) \
        CLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_PERROR(color, str) \
        CLOG_PERROR(str)

    #define _CLOG_PERRORF(color, ...) \
        CLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_STREAM(color, str) \
        CLOG_STREAM(str)

    #define _CLOGLN_STREAM(color, str) \
        CLOGLN_STREAM(str)

    #define _CLOGF_STREAM(color, ...) \
        CLOGF_STREAM(__VA_ARGS__)

    #define _CLOGFLN_STREAM(color, ...) \
        CLOGFLN_STREAM(__VA_ARGS__)

    #define _CLOG_HEX_STREAM(color, buffer, length) \
        CLOG_HEX_STREAM(buffer, length)

    #define _CLOGLN_HEX_STREAM(color, buffer, length) \
        CLOGLN_HEX_STREAM(buffer, length)

    #define _CLOG_WIDE_HEX_STREAM(color, buffer, length) \
        CLOG_WIDE_HEX_STREAM(buffer, length)

    #define _CLOGLN_WIDE_HEX_STREAM(color, buffer, length) \
        CLOGLN_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_PERROR_STREAM(color, str) \
        CLOG_PERROR_STREAM(str)

    #define _CLOG_PERRORF_STREAM(color, ...) \
        CLOG_PERRORF_STREAM(__VA_ARGS__)


    #define _CTLOG(color, str) \
        CTLOG(str)

    #define _CTLOGLN(color, str) \
        CTLOGLN(str)

    #define _CTLOGF(color, ...) \
        CTLOGF(__VA_ARGS__)

    #define _CTLOGFLN(color, ...) \
        CTLOGFLN(__VA_ARGS__)

    #define _CTLOG_HEX(color, buffer, length) \
        CTLOG_HEX(buffer, length)

    #define _CTLOGLN_HEX(color, buffer, length) \
        CTLOGLN_HEX(buffer, length)

    #define _CTLOG_WIDE_HEX(color, buffer, length) \
        CTLOG_WIDE_HEX(buffer, length)

    #define _CTLOGLN_WIDE_HEX(color, buffer, length) \
        CTLOGLN_WIDE_HEX(buffer, length)

    #define _CTLOG_PERROR(color, str) \
        CTLOG_PERROR(str)

    #define _CTLOG_PERRORF(color, ...) \
        CTLOG_PERRORF(__VA_ARGS__)

#else

    #define _CLOG(color, str) \
        CCLOG(color, str)

    #define _CLOGLN(color, str) \
        CCLOGLN(color, str)

    #define _CLOGF(color, ...) \
        CCLOGF(color, __VA_ARGS__)

    #define _CLOGFLN(color, ...) \
        CCLOGFLN(color, __VA_ARGS__)

    #define _CLOG_HEX(color, buffer, length) \
        CCLOG_HEX(color, buffer, length)

    #define _CLOGLN_HEX(color, buffer, length) \
        CCLOGLN_HEX(color, buffer, length)

    #define _CLOG_WIDE_HEX(color, buffer, length) \
        CCLOG_WIDE_HEX(color, buffer, length)

    #define _CLOGLN_WIDE_HEX(color, buffer, length) \
        CCLOGLN_WIDE_HEX(color, buffer, length)

    #define _CLOG_PERROR(color, str) \
        CCLOG_PERROR(color, str)

    #define _CLOG_PERRORF(color, ...) \
        CCLOG_PERRORF(color, __VA_ARGS__)


    #define _CLOG_STREAM(color, str) \
        CCLOG_STREAM(color, str)

    #define _CLOGLN_STREAM(color, str) \
        CCLOGLN_STREAM(color, str)

    #define _CLOGF_STREAM(color, ...) \
        CCLOGF_STREAM(color, __VA_ARGS__)

    #define _CLOGFLN_STREAM(color, ...) \
        CCLOGFLN_STREAM(color, __VA_ARGS__)

    #define _CLOG_HEX_STREAM(color, buffer, length) \
        CCLOG_HEX_STREAM(color, buffer, length)

    #define _CLOGLN_HEX_STREAM(color, buffer, length) \
        CCLOGLN_HEX_STREAM(color, buffer, length)

    #define _CLOG_WIDE_HEX_STREAM(color, buffer, length) \
        CCLOG_WIDE_HEX_STREAM(color, buffer, length)

    #define _CLOGLN_WIDE_HEX_STREAM(color, buffer, length) \
        CCLOGLN_WIDE_HEX_STREAM(color, buffer, length)

    #define _CLOG_PERROR_STREAM(color, str) \
        CCLOG_PERROR_STREAM(color, str)

    #define _CLOG_PERRORF_STREAM(color, ...) \
        CCLOG_PERRORF_STREAM(color, __VA_ARGS__)


    #define _CTLOG(color, str) \
        CCTLOG(color, str)

    #define _CTLOGLN(color, str) \
        CCTLOGLN(color, str)

    #define _CTLOGF(color, ...) \
        CCTLOGF(color, __VA_ARGS__)

    #define _CTLOGFLN(color, ...) \
        CCTLOGFLN(color, __VA_ARGS__)

    #define _CTLOG_HEX(color, buffer, length) \
        CCTLOG_HEX(color, buffer, length)

    #define _CTLOGLN_HEX(color, buffer, length) \
        CCTLOGLN_HEX(color, buffer, length)

    #define _CTLOG_WIDE_HEX(color, buffer, length) \
        CCTLOG_WIDE_HEX(color, buffer, length)

    #define _CTLOGLN_WIDE_HEX(color, buffer, length) \
        CCTLOGLN_WIDE_HEX(color, buffer, length)

    #define _CTLOG_PERROR(color, str) \
        CCTLOG_PERROR(color, str)

    #define _CTLOG_PERRORF(color, ...) \
        CCTLOG_PERRORF(color, __VA_ARGS__)

#endif


/**
 *  "clog_level" Functions
 *  ------------------------
 *
 *  Additionally, there are "clog_level" functions which add a symbol header
 *  to each line based on the level selected and print in the given color in
 *  addition to the timestamp for clog functions. These functions print to
 *  standard error. Trace and debug level logs also print tracing information.
 *
 *  There are several of these function-like macros available:
 *
 *      CLOG_TRACE(const char* str)
 *      CLOGLN_TRACE(const char* str)
 *      CLOGF_TRACE(const char* format, ...)
 *      CLOGFLN_TRACE(const char* format, ...)
 *
 *      CLOG_DEBUG(const char* str)
 *      CLOGLN_DEBUG(const char* str)
 *      CLOGF_DEBUG(const char* format, ...)
 *      CLOGFLN_DEBUG(const char* format, ...)
 *
 *      CLOG_EXTRA(const char* str)
 *      CLOGLN_EXTRA(const char* str)
 *      CLOGF_EXTRA(const char* format, ...)
 *      CLOGFLN_EXTRA(const char* format, ...)
 *
 *      CLOG_INFO(const char* str)
 *      CLOGLN_INFO(const char* str)
 *      CLOGF_INFO(const char* format, ...)
 *      CLOGFLN_INFO(const char* format, ...)
 *
 *      CLOG_HEADER(const char* str)
 *      CLOGLN_HEADER(const char* str)
 *      CLOGF_HEADER(const char* format, ...)
 *      CLOGFLN_HEADER(const char* format, ...)
 *
 *      CLOG_SUCCESS(const char* str)
 *      CLOGLN_SUCCESS(const char* str)
 *      CLOGF_SUCCESS(const char* format, ...)
 *      CLOGFLN_SUCCESS(const char* format, ...)
 *
 *      CLOG_MONEY(const char* str)
 *      CLOGLN_MONEY(const char* str)
 *      CLOGF_MONEY(const char* format, ...)
 *      CLOGFLN_MONEY(const char* format, ...)
 *      CLOG_PERROR_WARNING(const char* str)
 *      CLOG_PERRORF_WARNING(const char* format, ...)
 *
 *      CLOG_INPUT(const char* str)
 *      CLOGLN_INPUT(const char* str)
 *      CLOGF_INPUT(const char* format, ...)
 *      CLOGFLN_INPUT(const char* format, ...)
 *      CLOG_PERROR_WARNING(const char* str)
 *      CLOG_PERRORF_WARNING(const char* format, ...)
 *
 *      CLOG_WARNING(const char* str)
 *      CLOGLN_WARNING(const char* str)
 *      CLOGF_WARNING(const char* format, ...)
 *      CLOGFLN_WARNING(const char* format, ...)
 *      CLOG_PERROR_WARNING(const char* str)
 *      CLOG_PERRORF_WARNING(const char* format, ...)
 *
 *      CLOG_ERROR(const char* str)
 *      CLOGLN_ERROR(const char* str)
 *      CLOGF_ERROR(const char* format, ...)
 *      CLOGFLN_ERROR(const char* format, ...)
 *      CLOG_PERROR_ERROR(const char* str)
 *      CLOG_PERRORF_ERROR(const char* format, ...)
 *
 *      CLOG_CRITICAL(const char* str)
 *      CLOGLN_CRITICAL(const char* str)
 *      CLOGF_CRITICAL(const char* format, ...)
 *      CLOGFLN_CRITICAL(const char* format, ...)
 *      CLOG_PERROR_CRITICAL(const char* str)
 *      CLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *      CLOG_FATAL(const char* str)
 *      CLOGLN_FATAL(const char* str)
 *      CLOGF_FATAL(const char* format, ...)
 *      CLOGFLN_FATAL(const char* format, ...)
 *      CLOG_PERROR_FATAL(const char* str)
 *      CLOG_PERRORF_FATAL(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void CLOG_TRACE(const char* str);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  string to standard error in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_TRACE(str) \
    _CTLOG(C_TRACE, _CSYM_TRACE str)

/**
 *  void CLOGLN_TRACE(const char* str);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  string to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_TRACE(str) \
    _CTLOGLN(C_TRACE, _CSYM_TRACE str)

/**
 *  void CLOGF_TRACE(const char* format, ...);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_TRACE(...) \
    _CTLOGF(C_TRACE, _CSYM_TRACE __VA_ARGS__)

/**
 *  void CLOGFLN_TRACE(const char* format, ...);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error followed by a newline
 *  in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_TRACE(...) \
    _CTLOGFLN(C_TRACE, _CSYM_TRACE __VA_ARGS__)

/**
 *  void CLOG_DEBUG(const char* str);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  string to standard error in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_DEBUG(str) \
    _CTLOG(C_DEBUG, _CSYM_DEBUG str)

/**
 *  void CLOGLN_DEBUG(const char* str);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  string to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_DEBUG(str) \
    _CTLOGLN(C_DEBUG, _CSYM_DEBUG str)

/**
 *  void CLOGF_DEBUG(const char* format, ...);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_DEBUG(...) \
    _CTLOGF(C_DEBUG, _CSYM_DEBUG __VA_ARGS__)

/**
 *  void CLOGFLN_DEBUG(const char* format, ...);
 *
 *  Print timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error followed by a newline
 *  in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_DEBUG(...) \
    _CTLOGFLN(C_DEBUG, _CSYM_DEBUG __VA_ARGS__)

/**
 *  void CLOG_EXTRA(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_EXTRA(str) \
    _CLOG(C_EXTRA, _CSYM_EXTRA str)

/**
 *  void CLOGLN_EXTRA(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_EXTRA(str) \
    _CLOGLN(C_EXTRA, _CSYM_EXTRA str)

/**
 *  void CLOGF_EXTRA(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_EXTRA(...) \
    _CLOGF(C_EXTRA, _CSYM_EXTRA __VA_ARGS__)

/**
 *  void CLOGFLN_EXTRA(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_EXTRA(...) \
    _CLOGFLN(C_EXTRA, _CSYM_EXTRA __VA_ARGS__)

/**
 *  void CLOG_INFO(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_INFO(str) \
    _CLOG(C_INFO, _CSYM_INFO str)

/**
 *  void CLOGLN_INFO(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_INFO(str) \
    _CLOGLN(C_INFO, _CSYM_INFO str)

/**
 *  void CLOGF_INFO(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_INFO(...) \
    _CLOGF(C_INFO, _CSYM_INFO __VA_ARGS__)

/**
 *  void CLOGFLN_INFO(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_INFO(...) \
    _CLOGFLN(C_INFO, _CSYM_INFO __VA_ARGS__)

/**
 *  void CLOG_HEADER(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_HEADER(str) \
    _CLOG(C_HEADER, _CSYM_HEADER str)

/**
 *  void CLOGLN_HEADER(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_HEADER(str) \
    _CLOGLN(C_HEADER, _CSYM_HEADER str)

/**
 *  void CLOGF_HEADER(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_HEADER(...) \
    _CLOGF(C_HEADER, _CSYM_HEADER __VA_ARGS__)

/**
 *  void CLOGFLN_HEADER(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_HEADER(...) \
    _CLOGFLN(C_HEADER, _CSYM_HEADER __VA_ARGS__)

/**
 *  void CLOG_SUCCESS(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_SUCCESS(str) \
    _CLOG(C_SUCCESS, _CSYM_SUCCESS str)

/**
 *  void CLOGLN_SUCCESS(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_SUCCESS(str) \
    _CLOGLN(C_SUCCESS, _CSYM_SUCCESS str)

/**
 *  void CLOGF_SUCCESS(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_SUCCESS(...) \
    _CLOGF(C_SUCCESS, _CSYM_SUCCESS __VA_ARGS__)

/**
 *  void CLOGFLN_SUCCESS(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_SUCCESS(...) \
    _CLOGFLN(C_SUCCESS, _CSYM_SUCCESS __VA_ARGS__)

/**
 *  void CLOG_MONEY(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_MONEY(str) \
    _CLOG(C_MONEY, _CSYM_MONEY str)

/**
 *  void CLOGLN_MONEY(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_MONEY(str) \
    _CLOGLN(C_MONEY, _CSYM_MONEY str)

/**
 *  void CLOGF_MONEY(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_MONEY(...) \
    _CLOGF(C_MONEY, _CSYM_MONEY __VA_ARGS__)

/**
 *  void CLOGFLN_MONEY(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_MONEY(...) \
    _CLOGFLN(C_MONEY, _CSYM_MONEY __VA_ARGS__)

/**
 *  void CLOG_INPUT(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_INPUT(str) \
    _CLOG(C_INPUT, _CSYM_INPUT str)

/**
 *  void CLOGLN_INPUT(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_INPUT(str) \
    _CLOGLN(C_INPUT, _CSYM_INPUT str)

/**
 *  void CLOGF_INPUT(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_INPUT(...) \
    _CLOGF(C_INPUT, _CSYM_INPUT __VA_ARGS__)

/**
 *  void CLOGFLN_INPUT(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_INPUT(...) \
    _CLOGFLN(C_INPUT, _CSYM_INPUT __VA_ARGS__)

/**
 *  void CLOG_WARNING(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_WARNING(str) \
    _CLOG(C_WARNING, _CSYM_WARNING str)

/**
 *  void CLOGLN_WARNING(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_WARNING(str) \
    _CLOGLN(C_WARNING, _CSYM_WARNING str)

/**
 *  void CLOGF_WARNING(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_WARNING(...) \
    _CLOGF(C_WARNING, _CSYM_WARNING __VA_ARGS__)

/**
 *  void CLOGFLN_WARNING(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_WARNING(...) \
    _CLOGFLN(C_WARNING, _CSYM_WARNING __VA_ARGS__)

/**
 *  void CLOG_PERROR_WARNING(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  and then print the C error message in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR_WARNING(str)  \
    _CLOG_PERROR(C_WARNING, _CSYM_WARNING str)

/**
 *  void CLOG_PERRORF_WARNING(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a C error message in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF_WARNING(...) \
    _CLOG_PERRORF(C_WARNING, _CSYM_WARNING __VA_ARGS__)


/**
 *  void CLOG_ERROR(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_ERROR(str) \
    _CTLOG(C_ERROR, _CSYM_ERROR str)

/**
 *  void CLOGLN_ERROR(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_ERROR(str) \
    _CTLOGLN(C_ERROR, _CSYM_ERROR str)

/**
 *  void CLOGF_ERROR(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_ERROR(...) \
    _CTLOGF(C_ERROR, _CSYM_ERROR __VA_ARGS__)

/**
 *  void CLOGFLN_ERROR(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_ERROR(...) \
    _CTLOGFLN(C_ERROR, _CSYM_ERROR __VA_ARGS__)

/**
 *  void CLOG_PERROR_ERROR(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  and then print the C error message in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR_ERROR(str)  \
    _CTLOG_PERROR(C_ERROR, _CSYM_ERROR str)

/**
 *  void CLOG_PERRORF_ERROR(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a C error message in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF_ERROR(...) \
    _CTLOG_PERRORF(C_ERROR, _CSYM_ERROR __VA_ARGS__)


/**
 *  void CLOG_CRITICAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_CRITICAL(str) \
    _CTLOG(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void CLOGLN_CRITICAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_CRITICAL(str) \
    _CTLOGLN(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void CLOGF_CRITICAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_CRITICAL(...) \
    _CTLOGF(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)

/**
 *  void CLOGFLN_CRITICAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_CRITICAL(...) \
    _CTLOGFLN(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)

/**
 *  void CLOG_PERROR_CRITICAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  and then print the C error message in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR_CRITICAL(str)  \
    _CTLOG_PERROR(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void CLOG_PERRORF_CRITICAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a C error message in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF_CRITICAL(...) \
    _CTLOG_PERRORF(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)


/**
 *  void CLOG_FATAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_FATAL(str) \
    _CTLOG(C_FATAL, _CSYM_FATAL str)

/**
 *  void CLOGLN_FATAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOGLN_FATAL(str) \
    _CTLOGLN(C_FATAL, _CSYM_FATAL str)

/**
 *  void CLOGF_FATAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGF_FATAL(...) \
    _CTLOGF(C_FATAL, _CSYM_FATAL __VA_ARGS__)

/**
 *  void CLOGFLN_FATAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a newline in the appropriate log
 *  color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOGFLN_FATAL(...) \
    _CTLOGFLN(C_FATAL, _CSYM_FATAL __VA_ARGS__)

/**
 *  void CLOG_PERROR_FATAL(const char* str);
 *
 *  Print timestamp, log level symbol, and the given string to standard error
 *  and then print the C error message in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define CLOG_PERROR_FATAL(str)  \
    _CTLOG_PERROR(C_FATAL, _CSYM_FATAL str)

/**
 *  void CLOG_PERRORF_FATAL(const char* format, ...);
 *
 *  Print timestamp, log level symbol, and the given format string and format
 *  arguments to standard error followed by a C error message in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define CLOG_PERRORF_FATAL(...) \
    _CTLOG_PERRORF(C_FATAL, _CSYM_FATAL __VA_ARGS__)


/**
 *  "clog_level" Short Aliases
 *  --------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  void CLOG_TRC(const char* str);
     *
     *  Alias of `CLOG_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_TRC(str) CLOG_TRACE(str)

    /**
     *  void CLOGLN_TRC(const char* str);
     *
     *  Alias of `CLOGLN_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error followed by a newline in the appropriate log
     *  color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_TRC(str) CLOGLN_TRACE(str)

    /**
     *  void CLOGF_TRC(const char* format, ...);
     *
     *  Alias of `CLOGF_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error in the appropriate
     *  log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_TRC(...) CLOGF_TRACE(__VA_ARGS__)

    /**
     *  void CLOGFLN_TRC(const char* format, ...);
     *
     *  Alias of `CLOGFLN_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error followed by a
     *  newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_TRC(...) CLOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void CLOG_DBG(const char* str);
     *
     *  Alias of `CLOG_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_DBG(str) CLOG_DEBUG(str)

    /**
     *  void CLOGLN_DBG(const char* str);
     *
     *  Alias of `CLOGLN_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error followed by a newline in the appropriate log
     *  color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_DBG(str) CLOGLN_DEBUG(str)

    /**
     *  void CLOGF_DBG(const char* format, ...);
     *
     *  Alias of `CLOGF_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error in the appropriate
     *  log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_DBG(...) CLOGF_DEBUG(__VA_ARGS__)

    /**
     *  void CLOGFLN_DBG(const char* format, ...);
     *
     *  Alias of `CLOGFLN_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error followed by a
     *  newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_DBG(...) CLOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void CLOG_EXT(const char* str);
     *
     *  Alias of `CLOG_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_EXT(str) CLOG_EXTRA(str)

    /**
     *  void CLOGLN_EXT(const char* str);
     *
     *  Alias of `CLOGLN_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_EXT(str) CLOGLN_EXTRA(str)

    /**
     *  void CLOGF_EXT(const char* format, ...);
     *
     *  Alias of `CLOGF_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_EXT(...) CLOGF_EXTRA(__VA_ARGS__)

    /**
     *  void CLOGFLN_EXT(const char* format, ...);
     *
     *  Alias of `CLOGFLN_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_EXT(...) CLOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void CLOG_INF(const char* str);
     *
     *  Alias of `CLOG_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_INF(str) CLOG_INFO(str)

    /**
     *  void CLOGLN_INF(const char* str);
     *
     *  Alias of `CLOGLN_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_INF(str) CLOGLN_INFO(str)

    /**
     *  void CLOGF_INF(const char* format, ...);
     *
     *  Alias of `CLOGF_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_INF(...) CLOGF_INFO(__VA_ARGS__)

    /**
     *  void CLOGFLN_INF(const char* format, ...);
     *
     *  Alias of `CLOGFLN_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_INF(...) CLOGFLN_INFO(__VA_ARGS__)


    /**
     *  void CLOG_HEAD(const char* str);
     *
     *  Alias of `CLOG_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_HEAD(str) CLOG_HEADER(str)

    /**
     *  void CLOGLN_HEAD(const char* str);
     *
     *  Alias of `CLOG_TRACE` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_HEAD(str) CLOGLN_HEADER(str)

    /**
     *  void CLOGF_HEAD(const char* format, ...);
     *
     *  Alias of `CLOGF_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_HEAD(...) CLOGF_HEADER(__VA_ARGS__)

    /**
     *  void CLOGFLN_HEAD(const char* format, ...);
     *
     *  Alias of `CLOGFLN_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_HEAD(...) CLOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void CLOG_SUC(const char* str);
     *
     *  Alias of `CLOG_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_SUC(str) CLOG_SUCCESS(str)

    /**
     *  void CLOGLN_SUC(const char* str);
     *
     *  Alias of `CLOGLN_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_SUC(str) CLOGLN_SUCCESS(str)

    /**
     *  void CLOGF_SUC(const char* format, ...);
     *
     *  Alias of `CLOGF_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_SUC(...) CLOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void CLOGFLN_SUC(const char* format, ...);
     *
     *  Alias of `CLOGFLN_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_SUC(...) CLOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void CLOG_MON(const char* str);
     *
     *  Alias of `CLOG_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_MON(str) CLOG_MONEY(str)

    /**
     *  void CLOGLN_MON(const char* str);
     *
     *  Alias of `CLOGLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_MON(str) CLOGLN_MONEY(str)

    /**
     *  void CLOGF_MON(const char* format, ...);
     *
     *  Alias of `CLOGF_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_MON(...) CLOGF_MONEY(__VA_ARGS__)

    /**
     *  void CLOGFLN_MON(const char* format, ...);
     *
     *  Alias of `CLOGFLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_MON(...) CLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void CLOG_MNY(const char* str);
     *
     *  Alias of `CLOG_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_MNY(str) CLOG_MONEY(str)

    /**
     *  void CLOGLN_MNY(const char* str);
     *
     *  Alias of `CLOGLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_MNY(str) CLOGLN_MONEY(str)

    /**
     *  void CLOGF_MNY(const char* format, ...);
     *
     *  Alias of `CLOGF_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_MNY(...) CLOGF_MONEY(__VA_ARGS__)

    /**
     *  void CLOGFLN_MNY(const char* format, ...);
     *
     *  Alias of `CLOGFLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_MNY(...) CLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void CLOG_IN(const char* str);
     *
     *  Alias of `CLOG_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_IN(str) CLOG_INPUT(str)

    /**
     *  void CLOGLN_IN(const char* str);
     *
     *  Alias of `CLOGLN_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_IN(str) CLOGLN_INPUT(str)

    /**
     *  void CLOGF_IN(const char* format, ...);
     *
     *  Alias of `CLOGF_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_IN(...) CLOGF_INPUT(__VA_ARGS__)

    /**
     *  void CLOGFLN_IN(const char* format, ...);
     *
     *  Alias of `CLOGFLN_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_IN(...) CLOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void CLOG_WARN(const char* str);
     *
     *  Alias of `CLOG_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_WARN(str) CLOG_WARNING(str)

    /**
     *  void CLOGLN_WARN(const char* str);
     *
     *  Alias of `CLOGLN_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_WARN(str) CLOGLN_WARNING(str)

    /**
     *  void CLOGF_WARN(const char* format, ...);
     *
     *  Alias of `CLOGF_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_WARN(...) CLOGF_WARNING(__VA_ARGS__)

    /**
     *  void CLOGFLN_WARN(const char* format, ...);
     *
     *  Alias of `CLOGFLN_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_WARN(...) CLOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_WARN(const char* str);
     *
     *  Alias of `CLOG_PERROR_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_WARN(str) CLOG_PERROR_WARNING(str)

    /**
     *  void CLOG_PERRORF_WARN(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_WARN(...) CLOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void CLOG_ERR(const char* str);
     *
     *  Alias of `CLOG_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_ERR(str) CLOG_ERROR(str)

    /**
     *  void CLOGLN_ERR(const char* str);
     *
     *  Alias of `CLOGLN_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_ERR(str) CLOGLN_ERROR(str)

    /**
     *  void CLOGF_ERR(const char* format, ...);
     *
     *  Alias of `CLOGF_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_ERR(...) CLOGF_ERROR(__VA_ARGS__)

    /**
     *  void CLOGFLN_ERR(const char* format, ...);
     *
     *  Alias of `CLOGFLN_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_ERR(...) CLOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_ERR(const char* str);
     *
     *  Alias of `CLOG_PERROR_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_ERR(str) CLOG_PERROR_ERROR(str)

    /**
     *  void CLOG_PERRORF_ERR(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_ERR(...) CLOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void CLOG_CRIT(const char* str);
     *
     *  Alias of `CLOG_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_CRIT(str) CLOG_CRITICAL(str)

    /**
     *  void CLOGLN_CRIT(const char* str);
     *
     *  Alias of `CLOGLN_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_CRIT(str) CLOGLN_CRITICAL(str)

    /**
     *  void CLOGF_CRIT(const char* format, ...);
     *
     *  Alias of `CLOGF_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_CRIT(...) CLOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void CLOGFLN_CRIT(const char* format, ...);
     *
     *  Alias of `CLOGFLN_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_CRIT(...) CLOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_CRIT(const char* str);
     *
     *  Alias of `CLOG_PERROR_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_CRIT(str) CLOG_PERROR_CRITICAL(str)

    /**
     *  void CLOG_PERRORF_CRIT(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_CRIT(...) CLOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void CLOG_FAT(const char* str);
     *
     *  Alias of `CLOG_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_FAT(str) CLOG_FATAL(str)

    /**
     *  void CLOGLN_FAT(const char* str);
     *
     *  Alias of `CLOGLN_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_FAT(str) CLOGLN_FATAL(str)

    /**
     *  void CLOGF_FAT(const char* format, ...);
     *
     *  Alias of `CLOGF_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_FAT(...) CLOGF_FATAL(__VA_ARGS__)

    /**
     *  void CLOGFLN_FAT(const char* format, ...);
     *
     *  Alias of `CLOGFLN_FATAL` function.
     *
     *  Print timestamp, CLOGFLN_FATAL level symbol, and the given format
     *  string and format arguments to standard error followed by a newline in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_FAT(...) CLOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_FAT(const char* str);
     *
     *  Alias of `CLOG_PERROR_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_FAT(str) CLOG_PERROR_FATAL(str)

    /**
     *  void CLOG_PERRORF_FAT(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_FAT(...) CLOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "clog_level" Shorter Aliases
 *  ----------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  void CLOG_TR(const char* str);
     *
     *  Alias of `CLOG_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_TR(str) CLOG_TRACE(str)

    /**
     *  void CLOGLN_TR(const char* str);
     *
     *  Alias of `CLOGLN_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error followed by a newline in the appropriate log
     *  color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_TR(str) CLOGLN_TRACE(str)

    /**
     *  void CLOGF_TR(const char* format, ...);
     *
     *  Alias of `CLOGF_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error in the appropriate
     *  log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_TR(...) CLOGF_TRACE(__VA_ARGS__)

    /**
     *  void CLOGFLN_TR(const char* format, ...);
     *
     *  Alias of `CLOGFLN_TRACE` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error followed by a
     *  newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_TR(...) CLOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void CLOG_DB(const char* str);
     *
     *  Alias of `CLOG_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_DB(str) CLOG_DEBUG(str)

    /**
     *  void CLOGLN_DB(const char* str);
     *
     *  Alias of `CLOGLN_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  string to standard error followed by a newline in the appropriate log
     *  color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_DB(str) CLOGLN_DEBUG(str)

    /**
     *  void CLOGF_DB(const char* format, ...);
     *
     *  Alias of `CLOGF_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error in the appropriate
     *  log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_DB(...) CLOGF_DEBUG(__VA_ARGS__)

    /**
     *  void CLOGFLN_DB(const char* format, ...);
     *
     *  Alias of `CLOGFLN_DEBUG` function.
     *
     *  Print timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error followed by a
     *  newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_DB(...) CLOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void CLOG_EX(const char* str);
     *
     *  Alias of `CLOG_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_EX(str) CLOG_EXTRA(str)

    /**
     *  void CLOGLN_EX(const char* str);
     *
     *  Alias of `CLOGLN_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_EX(str) CLOGLN_EXTRA(str)

    /**
     *  void CLOGF_EX(const char* format, ...);
     *
     *  Alias of `CLOGF_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_EX(...) CLOGF_EXTRA(__VA_ARGS__)

    /**
     *  void CLOGFLN_EX(const char* format, ...);
     *
     *  Alias of `CLOGFLN_EXTRA` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_EX(...) CLOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void CLOG_IF(const char* str);
     *
     *  Alias of `CLOG_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_IF(str) CLOG_INFO(str)

    /**
     *  void CLOGLN_IF(const char* str);
     *
     *  Alias of `CLOGLN_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_IF(str) CLOGLN_INFO(str)

    /**
     *  void CLOGF_IF(const char* format, ...);
     *
     *  Alias of `CLOGF_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_IF(...) CLOGF_INFO(__VA_ARGS__)

    /**
     *  void CLOGFLN_IF(const char* format, ...);
     *
     *  Alias of `CLOGFLN_INFO` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_IF(...) CLOGFLN_INFO(__VA_ARGS__)


    /**
     *  void CLOG_HD(const char* str);
     *
     *  Alias of `CLOG_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_HD(str) CLOG_HEADER(str)

    /**
     *  void CLOGLN_HD(const char* str);
     *
     *  Alias of `CLOG_TRACE` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_HD(str) CLOGLN_HEADER(str)

    /**
     *  void CLOGF_HD(const char* format, ...);
     *
     *  Alias of `CLOGF_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_HD(...) CLOGF_HEADER(__VA_ARGS__)

    /**
     *  void CLOGFLN_HD(const char* format, ...);
     *
     *  Alias of `CLOGFLN_HEADER` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_HD(...) CLOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void CLOG_SC(const char* str);
     *
     *  Alias of `CLOG_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_SC(str) CLOG_SUCCESS(str)

    /**
     *  void CLOGLN_SC(const char* str);
     *
     *  Alias of `CLOGLN_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_SC(str) CLOGLN_SUCCESS(str)

    /**
     *  void CLOGF_SC(const char* format, ...);
     *
     *  Alias of `CLOGF_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_SC(...) CLOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void CLOGFLN_SC(const char* format, ...);
     *
     *  Alias of `CLOGFLN_SUCCESS` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_SC(...) CLOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void CLOG_MN(const char* str);
     *
     *  Alias of `CLOG_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_MN(str) CLOG_MONEY(str)

    /**
     *  void CLOGLN_MN(const char* str);
     *
     *  Alias of `CLOGLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_MN(str) CLOGLN_MONEY(str)

    /**
     *  void CLOGF_MN(const char* format, ...);
     *
     *  Alias of `CLOGF_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_MN(...) CLOGF_MONEY(__VA_ARGS__)

    /**
     *  void CLOGFLN_MN(const char* format, ...);
     *
     *  Alias of `CLOGFLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_MN(...) CLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void CLOG_MY(const char* str);
     *
     *  Alias of `CLOG_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_MY(str) CLOG_MONEY(str)

    /**
     *  void CLOGLN_MY(const char* str);
     *
     *  Alias of `CLOGLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_MY(str) CLOGLN_MONEY(str)

    /**
     *  void CLOGF_MY(const char* format, ...);
     *
     *  Alias of `CLOGF_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_MY(...) CLOGF_MONEY(__VA_ARGS__)

    /**
     *  void CLOGFLN_MY(const char* format, ...);
     *
     *  Alias of `CLOGFLN_MONEY` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_MY(...) CLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void CLOG_IN(const char* str);
     *
     *  Alias of `CLOG_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_IN(str) CLOG_INPUT(str)

    /**
     *  void CLOGLN_IN(const char* str);
     *
     *  Alias of `CLOGLN_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_IN(str) CLOGLN_INPUT(str)

    /**
     *  void CLOGF_IN(const char* format, ...);
     *
     *  Alias of `CLOGF_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_IN(...) CLOGF_INPUT(__VA_ARGS__)

    /**
     *  void CLOGFLN_IN(const char* format, ...);
     *
     *  Alias of `CLOGFLN_INPUT` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_IN(...) CLOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void CLOG_WN(const char* str);
     *
     *  Alias of `CLOG_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_WN(str) CLOG_WARNING(str)

    /**
     *  void CLOGLN_WN(const char* str);
     *
     *  Alias of `CLOGLN_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_WN(str) CLOGLN_WARNING(str)

    /**
     *  void CLOGF_WN(const char* format, ...);
     *
     *  Alias of `CLOGF_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_WN(...) CLOGF_WARNING(__VA_ARGS__)

    /**
     *  void CLOGFLN_WN(const char* format, ...);
     *
     *  Alias of `CLOGFLN_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_WN(...) CLOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_WN(const char* str);
     *
     *  Alias of `CLOG_PERROR_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_WN(str) CLOG_PERROR_WARNING(str)

    /**
     *  void CLOG_PERRORF_WN(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_WARNING` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_WN(...) CLOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void CLOG_ER(const char* str);
     *
     *  Alias of `CLOG_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_ER(str) CLOG_ERROR(str)

    /**
     *  void CLOGLN_ER(const char* str);
     *
     *  Alias of `CLOGLN_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_ER(str) CLOGLN_ERROR(str)

    /**
     *  void CLOGF_ER(const char* format, ...);
     *
     *  Alias of `CLOGF_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_ER(...) CLOGF_ERROR(__VA_ARGS__)

    /**
     *  void CLOGFLN_ER(const char* format, ...);
     *
     *  Alias of `CLOGFLN_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_ER(...) CLOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_ER(const char* str);
     *
     *  Alias of `CLOG_PERROR_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_ER(str) CLOG_PERROR_ERROR(str)

    /**
     *  void CLOG_PERRORF_ER(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_ERROR` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_ER(...) CLOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void CLOG_CR(const char* str);
     *
     *  Alias of `CLOG_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_CR(str) CLOG_CRITICAL(str)

    /**
     *  void CLOGLN_CR(const char* str);
     *
     *  Alias of `CLOGLN_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_CR(str) CLOGLN_CRITICAL(str)

    /**
     *  void CLOGF_CR(const char* format, ...);
     *
     *  Alias of `CLOGF_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_CR(...) CLOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void CLOGFLN_CR(const char* format, ...);
     *
     *  Alias of `CLOGFLN_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a newline in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_CR(...) CLOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_CR(const char* str);
     *
     *  Alias of `CLOG_PERROR_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_CR(str) CLOG_PERROR_CRITICAL(str)

    /**
     *  void CLOG_PERRORF_CR(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_CRITICAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_CR(...) CLOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void CLOG_FT(const char* str);
     *
     *  Alias of `CLOG_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_FT(str) CLOG_FATAL(str)

    /**
     *  void CLOGLN_FT(const char* str);
     *
     *  Alias of `CLOGLN_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOGLN_FT(str) CLOGLN_FATAL(str)

    /**
     *  void CLOGF_FT(const char* format, ...);
     *
     *  Alias of `CLOGF_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGF_FT(...) CLOGF_FATAL(__VA_ARGS__)

    /**
     *  void CLOGFLN_FT(const char* format, ...);
     *
     *  Alias of `CLOGFLN_FATAL` function.
     *
     *  Print timestamp, CLOGFLN_FATAL level symbol, and the given format
     *  string and format arguments to standard error followed by a newline in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOGFLN_FT(...) CLOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void CLOG_PERROR_FT(const char* str);
     *
     *  Alias of `CLOG_PERROR_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given string to standard
     *  error and then print the C error message in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CLOG_PERROR_FT(str) CLOG_PERROR_FATAL(str)

    /**
     *  void CLOG_PERRORF_FT(const char* format, ...);
     *
     *  Alias of `CLOG_PERRORF_FATAL` function.
     *
     *  Print timestamp, log level symbol, and the given format string and
     *  format arguments to standard error followed by a C error message in the
     *  appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CLOG_PERRORF_FT(...) CLOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "flog" Functions
 *  ================
 *
 *  File logging behaves in the same way as console logging except for there is
 *  never color logging and the logging is to a file instead of the console.
 *
 *  There are several function-like macros available:
 *
 *      FLOG(const char* str)
 *      FLOGLN(const char* str)
 *      FLOGF(const char* format, ...)
 *      FLOGFLN(const char* format, ...)
 *      FLOG_HEX(const uint8_t* buffer, size_t length)
 *      FLOGLN_HEX(const uint8_t* buffer, size_t length)
 *      FLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      FLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      FLOG_PERROR(const char* str)
 *      FLOG_PERRORF(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void FLOG(const char* str);
 *
 *  Log timestamp and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINT(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN(const char* str);
 *
 *  Log timestamp and the given string to a log file followed by a
 *  newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINTLN(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGF(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to
 *  a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINTF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGFLN(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to
 *  a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINTFLN(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to
 *  a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOG_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINT_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to
 *  a log file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOGLN_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINTLN_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOG_WIDE_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINT_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to a log file
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOGLN_WIDE_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPRINTLN_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_PERROR(const char* str);
 *
 *  Log timestamp and the given string to a log file and then print the C
 *  error message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPERROR(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_PERRORF(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to
 *  a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    FPERRORF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}


/**
 *  "flog_stream" Functions
 *  -----------------------
 *
 *  The "flog_stream" series are for logging to a file just like the "flog"
 *  functions, but these ones do NOT prepend the log with a timestamp,
 *  so they can be used to continue lines without a line break or for logging
 *  data without having a timestamp.
 *
 *  There are several function-like macros available:
 *
 *      FLOG_STREAM(const char* str)
 *      FLOGLN_STREAM(const char* str)
 *      FLOGF_STREAM(const char* format, ...)
 *      FLOGFLN_STREAM(const char* format, ...)
 *      FLOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      FLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      FLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      FLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      FLOG_PERROR_STREAM(const char* str)
 *      FLOG_PERRORF_STREAM(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void FLOG_STREAM(const char* str);
 *
 *  Log the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_STREAM(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINT(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_STREAM(const char* str);
 *
 *  Log the given string to a log file followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_STREAM(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINTLN(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGF_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_STREAM(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINTF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGFLN_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to a log file
 *  followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_STREAM(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINTFLN(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string to a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOG_HEX_STREAM(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINT_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string to a log file
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOGLN_HEX_STREAM(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINTLN_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOG_WIDE_HEX_STREAM(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINT_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to a log file followed by a
 *  newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FLOGLN_WIDE_HEX_STREAM(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPRINTLN_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_PERROR_STREAM(const char* str);
 *
 *  Log the given string to a log file and then print the C error
 *  message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR_STREAM(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPERROR(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FLOG_PERRORF_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to a log file
 *  followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF_STREAM(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    FPERRORF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}


/**
 *  "ftlog" Functions
 *  -----------------
 *
 *  The "ftlog" series also print to a log file with a timestamp just like
 *  the "flog" functions. But these functions also add a tracing element to the
 *  log for the case where you specifically want tracing information.
 *
 *  There are several function-like macros available:
 *
 *      FTLOG(const char* str)
 *      FTLOGLN(const char* str)
 *      FTLOGF(const char* format, ...)
 *      FTLOGFLN(const char* format, ...)
 *      FTLOG_HEX(const uint8_t* buffer, size_t length)
 *      FTLOGLN_HEX(const uint8_t* buffer, size_t length)
 *      FTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      FTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      FTLOG_PERROR(const char* str)
 *      FTLOG_PERRORF(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void FTLOG(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard
 *  error.
 *
 *  @param  str         String to print.
 */
#define FTLOG(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINT(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOGLN(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard
 *  error followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FTLOGLN(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINTLN(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOGF(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and
 *  format arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FTLOGF(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINTF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOGFLN(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and
 *  format arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FTLOGFLN(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINTFLN(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FTLOG_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINT_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string to a log file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FTLOGLN_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINTLN_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to a log file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FTLOG_WIDE_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINT_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as
 *  a hex string with preceding "0x" before each byte and delimited by spaces
 *  to a log file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define FTLOGLN_WIDE_HEX(buffer, length) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPRINTLN_WIDE_HEX(_clog_glog, buffer, length); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOG_PERROR(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard
 *  error and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define FTLOG_PERROR(str) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPERROR(_clog_glog, str); \
    fclose(_clog_glog); \
}

/**
 *  void FTLOG_PERRORF(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and
 *  format arguments to a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FTLOG_PERRORF(...) { \
    _clog_glog = fopen(CLOG_FILE, "a+"); \
    _CLOG_TIME(_clog_glog); \
    _CLOG_TRACING(_clog_glog); \
    FPERRORF(_clog_glog, __VA_ARGS__); \
    fclose(_clog_glog); \
}


/**
 *  "flog_level" Functions
 *  ------------------------
 *
 *  Additionally, there are "flog_level" functions which add a symbol header
 *  to each line based on the level selected and print it in addition to the
 *  timestamp for flog functions. These functions print to a file. Trace and
 *  debug level logs also print tracing information.
 *
 *  There are several of these function-like macros available:
 *
 *      FLOG_TRACE(const char* str)
 *      FLOGLN_TRACE(const char* str)
 *      FLOGF_TRACE(const char* format, ...)
 *      FLOGFLN_TRACE(const char* format, ...)
 *
 *      FLOG_DEBUG(const char* str)
 *      FLOGLN_DEBUG(const char* str)
 *      FLOGF_DEBUG(const char* format, ...)
 *      FLOGFLN_DEBUG(const char* format, ...)
 *
 *      FLOG_EXTRA(const char* str)
 *      FLOGLN_EXTRA(const char* str)
 *      FLOGF_EXTRA(const char* format, ...)
 *      FLOGFLN_EXTRA(const char* format, ...)
 *
 *      FLOG_INFO(const char* str)
 *      FLOGLN_INFO(const char* str)
 *      FLOGF_INFO(const char* format, ...)
 *      FLOGFLN_INFO(const char* format, ...)
 *
 *      FLOG_HEADER(const char* str)
 *      FLOGLN_HEADER(const char* str)
 *      FLOGF_HEADER(const char* format, ...)
 *      FLOGFLN_HEADER(const char* format, ...)
 *
 *      FLOG_SUCCESS(const char* str)
 *      FLOGLN_SUCCESS(const char* str)
 *      FLOGF_SUCCESS(const char* format, ...)
 *      FLOGFLN_SUCCESS(const char* format, ...)
 *
 *      FLOG_MONEY(const char* str)
 *      FLOGLN_MONEY(const char* str)
 *      FLOGF_MONEY(const char* format, ...)
 *      FLOGFLN_MONEY(const char* format, ...)
 *
 *      FLOG_INPUT(const char* str)
 *      FLOGLN_INPUT(const char* str)
 *      FLOGF_INPUT(const char* format, ...)
 *      FLOGFLN_INPUT(const char* format, ...)
 *
 *      FLOG_WARNING(const char* str)
 *      FLOGLN_WARNING(const char* str)
 *      FLOGF_WARNING(const char* format, ...)
 *      FLOGFLN_WARNING(const char* format, ...)
 *      FLOG_PERROR_WARNING(const char* str)
 *      FLOG_PERRORF_WARNING(const char* format, ...)
 *
 *      FLOG_ERROR(const char* str)
 *      FLOGLN_ERROR(const char* str)
 *      FLOGF_ERROR(const char* format, ...)
 *      FLOGFLN_ERROR(const char* format, ...)
 *      FLOG_PERROR_ERROR(const char* str)
 *      FLOG_PERRORF_ERROR(const char* format, ...)
 *
 *      FLOG_CRITICAL(const char* str)
 *      FLOGLN_CRITICAL(const char* str)
 *      FLOGF_CRITICAL(const char* format, ...)
 *      FLOGFLN_CRITICAL(const char* format, ...)
 *      FLOG_PERROR_CRITICAL(const char* str)
 *      FLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *      FLOG_FATAL(const char* str)
 *      FLOGLN_FATAL(const char* str)
 *      FLOGF_FATAL(const char* format, ...)
 *      FLOGFLN_FATAL(const char* format, ...)
 *      FLOG_PERROR_CRITICAL(const char* str)
 *      FLOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void FLOG_TRACE(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_TRACE(str) \
    FTLOG(_CSYM_TRACE str)

/**
 *  void FLOGLN_TRACE(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to a log file followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_TRACE(str) \
    FTLOGLN(_CSYM_TRACE str)

/**
 *  void FLOGF_TRACE(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_TRACE(...) \
    FTLOGF(_CSYM_TRACE __VA_ARGS__)

/**
 *  void FLOGFLN_TRACE(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_TRACE(...) \
    FTLOGFLN(_CSYM_TRACE __VA_ARGS__)

/**
 *  void FLOG_DEBUG(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_DEBUG(str) \
    FTLOG(_CSYM_DEBUG str)

/**
 *  void FLOGLN_DEBUG(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to a log file followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_DEBUG(str) \
    FTLOGLN(_CSYM_DEBUG str)

/**
 *  void FLOGF_DEBUG(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_DEBUG(...) \
    FTLOGF(_CSYM_DEBUG __VA_ARGS__)

/**
 *  void FLOGFLN_DEBUG(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_DEBUG(...) \
    FTLOGFLN(_CSYM_DEBUG __VA_ARGS__)

/**
 *  void FLOG_EXTRA(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_EXTRA(str) \
    FLOG(_CSYM_EXTRA str)

/**
 *  void FLOGLN_EXTRA(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_EXTRA(str) \
    FLOGLN(_CSYM_EXTRA str)

/**
 *  void FLOGF_EXTRA(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_EXTRA(...) \
    FLOGF(_CSYM_EXTRA __VA_ARGS__)

/**
 *  void FLOGFLN_EXTRA(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_EXTRA(...) \
    FLOGFLN(_CSYM_EXTRA __VA_ARGS__)

/**
 *  void FLOG_INFO(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_INFO(str) \
    FLOG(_CSYM_INFO str)

/**
 *  void FLOGLN_INFO(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_INFO(str) \
    FLOGLN(_CSYM_INFO str)

/**
 *  void FLOGF_INFO(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_INFO(...) \
    FLOGF(_CSYM_INFO __VA_ARGS__)

/**
 *  void FLOGFLN_INFO(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_INFO(...) \
    FLOGFLN(_CSYM_INFO __VA_ARGS__)


/**
 *  void FLOG_HEADER(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_HEADER(str) \
    FLOG(_CSYM_HEADER str)

/**
 *  void FLOGLN_HEADER(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_HEADER(str) \
    FLOGLN(_CSYM_HEADER str)

/**
 *  void FLOGF_HEADER(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_HEADER(...) \
    FLOGF(_CSYM_HEADER __VA_ARGS__)

/**
 *  void FLOGFLN_HEADER(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_HEADER(...) \
    FLOGFLN(_CSYM_HEADER __VA_ARGS__)


/**
 *  void FLOG_SUCCESS(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_SUCCESS(str) \
    FLOG(_CSYM_SUCCESS str)

/**
 *  void FLOGLN_SUCCESS(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_SUCCESS(str) \
    FLOGLN(_CSYM_SUCCESS str)

/**
 *  void FLOGF_SUCCESS(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_SUCCESS(...) \
    FLOGF(_CSYM_SUCCESS __VA_ARGS__)

/**
 *  void FLOGFLN_SUCCESS(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_SUCCESS(...) \
    FLOGFLN(_CSYM_SUCCESS __VA_ARGS__)


/**
 *  void FLOG_MONEY(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_MONEY(str) \
    FLOG(_CSYM_MONEY str)

/**
 *  void FLOGLN_MONEY(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_MONEY(str) \
    FLOGLN(_CSYM_MONEY str)

/**
 *  void FLOGF_MONEY(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_MONEY(...) \
    FLOGF(_CSYM_MONEY __VA_ARGS__)

/**
 *  void FLOGFLN_MONEY(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_MONEY(...) \
    FLOGFLN(_CSYM_MONEY __VA_ARGS__)


/**
 *  void FLOG_INPUT(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_INPUT(str) \
    FLOG(_CSYM_INPUT str)

/**
 *  void FLOGLN_INPUT(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_INPUT(str) \
    FLOGLN(_CSYM_INPUT str)

/**
 *  void FLOGF_INPUT(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_INPUT(...) \
    FLOGF(_CSYM_INPUT __VA_ARGS__)

/**
 *  void FLOGFLN_INPUT(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_INPUT(...) \
    FLOGFLN(_CSYM_INPUT __VA_ARGS__)


/**
 *  void FLOG_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_WARNING(str) \
    FLOG(_CSYM_WARNING str)

/**
 *  void FLOGLN_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_WARNING(str) \
    FLOGLN(_CSYM_WARNING str)

/**
 *  void FLOGF_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_WARNING(...) \
    FLOGF(_CSYM_WARNING __VA_ARGS__)

/**
 *  void FLOGFLN_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_WARNING(...) \
    FLOGFLN(_CSYM_WARNING __VA_ARGS__)

/**
 *  void FLOG_PERROR_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR_WARNING(str)  \
    FLOG_PERROR(_CSYM_WARNING str)

/**
 *  void FLOG_PERRORF_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF_WARNING(...) \
    FLOG_PERRORF(_CSYM_WARNING __VA_ARGS__)


/**
 *  void FLOG_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_ERROR(str) \
    FTLOG(_CSYM_ERROR str)

/**
 *  void FLOGLN_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_ERROR(str) \
    FTLOGLN(_CSYM_ERROR str)

/**
 *  void FLOGF_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_ERROR(...) \
    FTLOGF(_CSYM_ERROR __VA_ARGS__)

/**
 *  void FLOGFLN_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_ERROR(...) \
    FTLOGFLN(_CSYM_ERROR __VA_ARGS__)

/**
 *  void FLOG_PERROR_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR_ERROR(str)  \
    FTLOG_PERROR(_CSYM_ERROR str)

/**
 *  void FLOG_PERRORF_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF_ERROR(...) \
    FTLOG_PERRORF(_CSYM_ERROR __VA_ARGS__)


/**
 *  void FLOG_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_CRITICAL(str) \
    FTLOG(_CSYM_CRITICAL str)

/**
 *  void FLOGLN_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_CRITICAL(str) \
    FTLOGLN(_CSYM_CRITICAL str)

/**
 *  void FLOGF_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_CRITICAL(...) \
    FTLOGF(_CSYM_CRITICAL __VA_ARGS__)

/**
 *  void FLOGFLN_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_CRITICAL(...) \
    FTLOGFLN(_CSYM_CRITICAL __VA_ARGS__)

/**
 *  void FLOG_PERROR_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR_CRITICAL(str)  \
    FTLOG_PERROR(_CSYM_CRITICAL str)

/**
 *  void FLOG_PERRORF_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF_CRITICAL(...) \
    FTLOG_PERRORF(_CSYM_CRITICAL __VA_ARGS__)


/**
 *  void FLOG_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file.
 *
 *  @param  str         String to print.
 */
#define FLOG_FATAL(str) \
    FTLOG(_CSYM_FATAL str)

/**
 *  void FLOGLN_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  followed by a newline.
 *
 *  @param  str         String to print.
 */
#define FLOGLN_FATAL(str) \
    FTLOGLN(_CSYM_FATAL str)

/**
 *  void FLOGF_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGF_FATAL(...) \
    FTLOGF(_CSYM_FATAL __VA_ARGS__)

/**
 *  void FLOGFLN_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOGFLN_FATAL(...) \
    FTLOGFLN(_CSYM_FATAL __VA_ARGS__)

/**
 *  void FLOG_PERROR_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to a log file
 *  and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define FLOG_PERROR_FATAL(str)  \
    FTLOG_PERROR(_CSYM_FATAL str)

/**
 *  void FLOG_PERRORF_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to a log file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define FLOG_PERRORF_FATAL(...) \
    FTLOG_PERRORF(_CSYM_FATAL __VA_ARGS__)


/**
 *  "flog_level" Short Aliases
 *  --------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  void FLOG_TRC(const char* str);
     *
     *  Alias of `FLOG_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_TRC(str) FLOG_TRACE(str)

    /**
     *  void FLOGLN_TRC(const char* str);
     *
     *  Alias of `FLOGLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_TRC(str) FLOGLN_TRACE(str)

    /**
     *  void FLOGF_TRC(const char* format, ...);
     *
     *  Alias of `FLOGF_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_TRC(...) FLOGF_TRACE(__VA_ARGS__)

    /**
     *  void FLOGFLN_TRC(const char* format, ...);
     *
     *  Alias of `FLOGFLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file followed by a
     *  newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_TRC(...) FLOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void FLOG_DBG(const char* str);
     *
     *  Alias of `FLOG_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_DBG(str) FLOG_DEBUG(str)

    /**
     *  void FLOGLN_DBG(const char* str);
     *
     *  Alias of `FLOGLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_DBG(str) FLOGLN_DEBUG(str)

    /**
     *  void FLOGF_DBG(const char* format, ...);
     *
     *  Alias of `FLOGF_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_DBG(...) FLOGF_DEBUG(__VA_ARGS__)

    /**
     *  void FLOGFLN_DBG(const char* format, ...);
     *
     *  Alias of `FLOGFLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file followed by a
     *  newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_DBG(...) FLOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void FLOG_EXT(const char* str);
     *
     *  Alias of `FLOG_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_EXT(str) FLOG_EXTRA(str)

    /**
     *  void FLOGLN_EXT(const char* str);
     *
     *  Alias of `FLOGLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_EXT(str) FLOGLN_EXTRA(str)

    /**
     *  void FLOGF_EXT(const char* format, ...);
     *
     *  Alias of `FLOGF_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_EXT(...) FLOGF_EXTRA(__VA_ARGS__)

    /**
     *  void FLOGFLN_EXT(const char* format, ...);
     *
     *  Alias of `FLOGFLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_EXT(...) FLOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void FLOG_INF(const char* str);
     *
     *  Alias of `FLOG_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_INF(str) FLOG_INFO(str)

    /**
     *  void FLOGLN_INF(const char* str);
     *
     *  Alias of `FLOGLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_INF(str) FLOGLN_INFO(str)

    /**
     *  void FLOGF_INF(const char* format, ...);
     *
     *  Alias of `FLOGF_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_INF(...) FLOGF_INFO(__VA_ARGS__)

    /**
     *  void FLOGFLN_INF(const char* format, ...);
     *
     *  Alias of `FLOGFLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_INF(...) FLOGFLN_INFO(__VA_ARGS__)


    /**
     *  void FLOG_HEAD(const char* str);
     *
     *  Alias of `FLOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_HEAD(str) FLOG_HEADER(str)

    /**
     *  void FLOGLN_HEAD(const char* str);
     *
     *  Alias of `FLOG_TRACE` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_HEAD(str) FLOGLN_HEADER(str)

    /**
     *  void FLOGF_HEAD(const char* format, ...);
     *
     *  Alias of `FLOGF_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_HEAD(...) FLOGF_HEADER(__VA_ARGS__)

    /**
     *  void FLOGFLN_HEAD(const char* format, ...);
     *
     *  Alias of `FLOGFLN_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_HEAD(...) FLOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void FLOG_SUC(const char* str);
     *
     *  Alias of `FLOG_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_SUC(str) FLOG_SUCCESS(str)

    /**
     *  void FLOGLN_SUC(const char* str);
     *
     *  Alias of `FLOGLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_SUC(str) FLOGLN_SUCCESS(str)

    /**
     *  void FLOGF_SUC(const char* format, ...);
     *
     *  Alias of `FLOGF_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_SUC(...) FLOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void FLOGFLN_SUC(const char* format, ...);
     *
     *  Alias of `FLOGFLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline in the
     *  appropriate log
     * .
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_SUC(...) FLOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void FLOG_MON(const char* str);
     *
     *  Alias of `FLOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_MON(str) FLOG_MONEY(str)

    /**
     *  void FLOGLN_MON(const char* str);
     *
     *  Alias of `FLOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_MON(str) FLOGLN_MONEY(str)

    /**
     *  void FLOGF_MON(const char* format, ...);
     *
     *  Alias of `FLOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_MON(...) FLOGF_MONEY(__VA_ARGS__)

    /**
     *  void FLOGFLN_MON(const char* format, ...);
     *
     *  Alias of `FLOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline in the
     *  appropriate log
     * .
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_MON(...) FLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void FLOG_MNY(const char* str);
     *
     *  Alias of `FLOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_MNY(str) FLOG_MONEY(str)

    /**
     *  void FLOGLN_MNY(const char* str);
     *
     *  Alias of `FLOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_MNY(str) FLOGLN_MONEY(str)

    /**
     *  void FLOGF_MNY(const char* format, ...);
     *
     *  Alias of `FLOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_MNY(...) FLOGF_MONEY(__VA_ARGS__)

    /**
     *  void FLOGFLN_MNY(const char* format, ...);
     *
     *  Alias of `FLOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_MNY(...) FLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void FLOG_IN(const char* str);
     *
     *  Alias of `FLOG_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_IN(str) FLOG_INPUT(str)

    /**
     *  void FLOGLN_IN(const char* str);
     *
     *  Alias of `FLOGLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_IN(str) FLOGLN_INPUT(str)

    /**
     *  void FLOGF_IN(const char* format, ...);
     *
     *  Alias of `FLOGF_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_IN(...) FLOGF_INPUT(__VA_ARGS__)

    /**
     *  void FLOGFLN_IN(const char* format, ...);
     *
     *  Alias of `FLOGFLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_IN(...) FLOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void FLOG_WARN(const char* str);
     *
     *  Alias of `FLOG_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_WARN(str) FLOG_WARNING(str)

    /**
     *  void FLOGLN_WARN(const char* str);
     *
     *  Alias of `FLOGLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_WARN(str) FLOGLN_WARNING(str)

    /**
     *  void FLOGF_WARN(const char* format, ...);
     *
     *  Alias of `FLOGF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_WARN(...) FLOGF_WARNING(__VA_ARGS__)

    /**
     *  void FLOGFLN_WARN(const char* format, ...);
     *
     *  Alias of `FLOGFLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_WARN(...) FLOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_WARN(const char* str);
     *
     *  Alias of `FLOG_PERROR_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_WARN(str) FLOG_PERROR_WARNING(str)

    /**
     *  void FLOG_PERRORF_WARN(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_WARN(...) FLOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void FLOG_ERR(const char* str);
     *
     *  Alias of `FLOG_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_ERR(str) FLOG_ERROR(str)

    /**
     *  void FLOGLN_ERR(const char* str);
     *
     *  Alias of `FLOGLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_ERR(str) FLOGLN_ERROR(str)

    /**
     *  void FLOGF_ERR(const char* format, ...);
     *
     *  Alias of `FLOGF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_ERR(...) FLOGF_ERROR(__VA_ARGS__)

    /**
     *  void FLOGFLN_ERR(const char* format, ...);
     *
     *  Alias of `FLOGFLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_ERR(...) FLOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_ERR(const char* str);
     *
     *  Alias of `FLOG_PERROR_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_ERR(str) FLOG_PERROR_ERROR(str)

    /**
     *  void FLOG_PERRORF_ERR(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_ERR(...) FLOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void FLOG_CRIT(const char* str);
     *
     *  Alias of `FLOG_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_CRIT(str) FLOG_CRITICAL(str)

    /**
     *  void FLOGLN_CRIT(const char* str);
     *
     *  Alias of `FLOGLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_CRIT(str) FLOGLN_CRITICAL(str)

    /**
     *  void FLOGF_CRIT(const char* format, ...);
     *
     *  Alias of `FLOGF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_CRIT(...) FLOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void FLOGFLN_CRIT(const char* format, ...);
     *
     *  Alias of `FLOGFLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_CRIT(...) FLOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_CRIT(const char* str);
     *
     *  Alias of `FLOG_PERROR_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_CRIT(str) FLOG_PERROR_CRITICAL(str)

    /**
     *  void FLOG_PERRORF_CRIT(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_CRIT(...) FLOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void FLOG_FAT(const char* str);
     *
     *  Alias of `FLOG_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_FAT(str) FLOG_FATAL(str)

    /**
     *  void FLOGLN_FAT(const char* str);
     *
     *  Alias of `FLOGLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_FAT(str) FLOGLN_FATAL(str)

    /**
     *  void FLOGF_FAT(const char* format, ...);
     *
     *  Alias of `FLOGF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_FAT(...) FLOGF_FATAL(__VA_ARGS__)

    /**
     *  void FLOGFLN_FAT(const char* format, ...);
     *
     *  Alias of `FLOGFLN_FATAL` function.
     *
     *  Log timestamp, FLOGFLN_FATAL level symbol, and the given format
     *  string and format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_FAT(...) FLOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_FAT(const char* str);
     *
     *  Alias of `FLOG_PERROR_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_FAT(str) FLOG_PERROR_FATAL(str)

    /**
     *  void FLOG_PERRORF_FAT(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_FAT(...) FLOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "flog_level" Shorter Aliases
 *  ----------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  void FLOG_TR(const char* str);
     *
     *  Alias of `FLOG_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_TR(str) FLOG_TRACE(str)

    /**
     *  void FLOGLN_TR(const char* str);
     *
     *  Alias of `FLOGLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_TR(str) FLOGLN_TRACE(str)

    /**
     *  void FLOGF_TR(const char* format, ...);
     *
     *  Alias of `FLOGF_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_TR(...) FLOGF_TRACE(__VA_ARGS__)

    /**
     *  void FLOGFLN_TR(const char* format, ...);
     *
     *  Alias of `FLOGFLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file followed by a
     *  newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_TR(...) FLOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void FLOG_DB(const char* str);
     *
     *  Alias of `FLOG_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_DB(str) FLOG_DEBUG(str)

    /**
     *  void FLOGLN_DB(const char* str);
     *
     *  Alias of `FLOGLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to a log file followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_DB(str) FLOGLN_DEBUG(str)

    /**
     *  void FLOGF_DB(const char* format, ...);
     *
     *  Alias of `FLOGF_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_DB(...) FLOGF_DEBUG(__VA_ARGS__)

    /**
     *  void FLOGFLN_DB(const char* format, ...);
     *
     *  Alias of `FLOGFLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to a log file followed by a
     *  newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_DB(...) FLOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void FLOG_EX(const char* str);
     *
     *  Alias of `FLOG_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_EX(str) FLOG_EXTRA(str)

    /**
     *  void FLOGLN_EX(const char* str);
     *
     *  Alias of `FLOGLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_EX(str) FLOGLN_EXTRA(str)

    /**
     *  void FLOGF_EX(const char* format, ...);
     *
     *  Alias of `FLOGF_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_EX(...) FLOGF_EXTRA(__VA_ARGS__)

    /**
     *  void FLOGFLN_EX(const char* format, ...);
     *
     *  Alias of `FLOGFLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_EX(...) FLOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void FLOG_IF(const char* str);
     *
     *  Alias of `FLOG_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_IF(str) FLOG_INFO(str)

    /**
     *  void FLOGLN_IF(const char* str);
     *
     *  Alias of `FLOGLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_IF(str) FLOGLN_INFO(str)

    /**
     *  void FLOGF_IF(const char* format, ...);
     *
     *  Alias of `FLOGF_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_IF(...) FLOGF_INFO(__VA_ARGS__)

    /**
     *  void FLOGFLN_IF(const char* format, ...);
     *
     *  Alias of `FLOGFLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_IF(...) FLOGFLN_INFO(__VA_ARGS__)


    /**
     *  void FLOG_HD(const char* str);
     *
     *  Alias of `FLOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_HD(str) FLOG_HEADER(str)

    /**
     *  void FLOGLN_HD(const char* str);
     *
     *  Alias of `FLOG_TRACE` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_HD(str) FLOGLN_HEADER(str)

    /**
     *  void FLOGF_HD(const char* format, ...);
     *
     *  Alias of `FLOGF_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_HD(...) FLOGF_HEADER(__VA_ARGS__)

    /**
     *  void FLOGFLN_HD(const char* format, ...);
     *
     *  Alias of `FLOGFLN_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_HD(...) FLOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void FLOG_SC(const char* str);
     *
     *  Alias of `FLOG_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_SC(str) FLOG_SUCCESS(str)

    /**
     *  void FLOGLN_SC(const char* str);
     *
     *  Alias of `FLOGLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_SC(str) FLOGLN_SUCCESS(str)

    /**
     *  void FLOGF_SC(const char* format, ...);
     *
     *  Alias of `FLOGF_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_SC(...) FLOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void FLOGFLN_SC(const char* format, ...);
     *
     *  Alias of `FLOGFLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_SC(...) FLOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void FLOG_MN(const char* str);
     *
     *  Alias of `FLOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_MN(str) FLOG_MONEY(str)

    /**
     *  void FLOGLN_MN(const char* str);
     *
     *  Alias of `FLOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_MN(str) FLOGLN_MONEY(str)

    /**
     *  void FLOGF_MN(const char* format, ...);
     *
     *  Alias of `FLOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_MN(...) FLOGF_MONEY(__VA_ARGS__)

    /**
     *  void FLOGFLN_MN(const char* format, ...);
     *
     *  Alias of `FLOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_MN(...) FLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void FLOG_MY(const char* str);
     *
     *  Alias of `FLOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_MY(str) FLOG_MONEY(str)

    /**
     *  void FLOGLN_MY(const char* str);
     *
     *  Alias of `FLOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_MY(str) FLOGLN_MONEY(str)

    /**
     *  void FLOGF_MY(const char* format, ...);
     *
     *  Alias of `FLOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_MY(...) FLOGF_MONEY(__VA_ARGS__)

    /**
     *  void FLOGFLN_MY(const char* format, ...);
     *
     *  Alias of `FLOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_MY(...) FLOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void FLOG_IN(const char* str);
     *
     *  Alias of `FLOG_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_IN(str) FLOG_INPUT(str)

    /**
     *  void FLOGLN_IN(const char* str);
     *
     *  Alias of `FLOGLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_IN(str) FLOGLN_INPUT(str)

    /**
     *  void FLOGF_IN(const char* format, ...);
     *
     *  Alias of `FLOGF_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_IN(...) FLOGF_INPUT(__VA_ARGS__)

    /**
     *  void FLOGFLN_IN(const char* format, ...);
     *
     *  Alias of `FLOGFLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_IN(...) FLOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void FLOG_WN(const char* str);
     *
     *  Alias of `FLOG_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_WN(str) FLOG_WARNING(str)

    /**
     *  void FLOGLN_WN(const char* str);
     *
     *  Alias of `FLOGLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_WN(str) FLOGLN_WARNING(str)

    /**
     *  void FLOGF_WN(const char* format, ...);
     *
     *  Alias of `FLOGF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_WN(...) FLOGF_WARNING(__VA_ARGS__)

    /**
     *  void FLOGFLN_WN(const char* format, ...);
     *
     *  Alias of `FLOGFLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_WN(...) FLOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_WN(const char* str);
     *
     *  Alias of `FLOG_PERROR_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_WN(str) FLOG_PERROR_WARNING(str)

    /**
     *  void FLOG_PERRORF_WN(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_WN(...) FLOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void FLOG_ER(const char* str);
     *
     *  Alias of `FLOG_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_ER(str) FLOG_ERROR(str)

    /**
     *  void FLOGLN_ER(const char* str);
     *
     *  Alias of `FLOGLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_ER(str) FLOGLN_ERROR(str)

    /**
     *  void FLOGF_ER(const char* format, ...);
     *
     *  Alias of `FLOGF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_ER(...) FLOGF_ERROR(__VA_ARGS__)

    /**
     *  void FLOGFLN_ER(const char* format, ...);
     *
     *  Alias of `FLOGFLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_ER(...) FLOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_ER(const char* str);
     *
     *  Alias of `FLOG_PERROR_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_ER(str) FLOG_PERROR_ERROR(str)

    /**
     *  void FLOG_PERRORF_ER(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_ER(...) FLOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void FLOG_CR(const char* str);
     *
     *  Alias of `FLOG_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_CR(str) FLOG_CRITICAL(str)

    /**
     *  void FLOGLN_CR(const char* str);
     *
     *  Alias of `FLOGLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_CR(str) FLOGLN_CRITICAL(str)

    /**
     *  void FLOGF_CR(const char* format, ...);
     *
     *  Alias of `FLOGF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_CR(...) FLOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void FLOGFLN_CR(const char* format, ...);
     *
     *  Alias of `FLOGFLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_CR(...) FLOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_CR(const char* str);
     *
     *  Alias of `FLOG_PERROR_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_CR(str) FLOG_PERROR_CRITICAL(str)

    /**
     *  void FLOG_PERRORF_CR(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_CR(...) FLOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void FLOG_FT(const char* str);
     *
     *  Alias of `FLOG_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file.
     *
     *  @param  str         String to print.
     */
    #define FLOG_FT(str) FLOG_FATAL(str)

    /**
     *  void FLOGLN_FT(const char* str);
     *
     *  Alias of `FLOGLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file
     *  followed by a newline.
     *
     *  @param  str         String to print.
     */
    #define FLOGLN_FT(str) FLOGLN_FATAL(str)

    /**
     *  void FLOGF_FT(const char* format, ...);
     *
     *  Alias of `FLOGF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGF_FT(...) FLOGF_FATAL(__VA_ARGS__)

    /**
     *  void FLOGFLN_FT(const char* format, ...);
     *
     *  Alias of `FLOGFLN_FATAL` function.
     *
     *  Log timestamp, FLOGFLN_FATAL level symbol, and the given format
     *  string and format arguments to a log file followed by a newline.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOGFLN_FT(...) FLOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void FLOG_PERROR_FT(const char* str);
     *
     *  Alias of `FLOG_PERROR_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to a file and
     *  then print the C error message.
     *
     *  @param  str         String to print.
     */
    #define FLOG_PERROR_FT(str) FLOG_PERROR_FATAL(str)

    /**
     *  void FLOG_PERRORF_FT(const char* format, ...);
     *
     *  Alias of `FLOG_PERRORF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to a log file followed by a C error message.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FLOG_PERRORF_FT(...) FLOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 * Logging
 * =======
 *
 * The "log" functions allow for console and file logging based on the
 * configuration options.
 */

#if CLOG_MODE == CLOG_MODE_NONE

    #define _CLOG_LOG(...)
    #define _CLOG_LOGLN(...)
    #define _CLOG_LOGF(...)
    #define _CLOG_LOGFLN(...)
    #define _CLOG_LOG_HEX(...)
    #define _CLOG_LOGLN_HEX(...)
    #define _CLOG_LOG_WIDE_HEX(...)
    #define _CLOG_LOGLN_WIDE_HEX(...)
    #define _CLOG_LOG_PERROR(...)
    #define _CLOG_LOG_PERRORF(...)

    #define _CLOG_LOG_STREAM(...)
    #define _CLOG_LOGLN_STREAM(...)
    #define _CLOG_LOGF_STREAM(...)
    #define _CLOG_LOGFLN_STREAM(...)
    #define _CLOG_LOG_HEX_STREAM(...)
    #define _CLOG_LOGLN_HEX_STREAM(...)
    #define _CLOG_LOG_WIDE_HEX_STREAM(...)
    #define _CLOG_LOGLN_WIDE_HEX_STREAM(...)
    #define _CLOG_LOG_PERROR_STREAM(...)
    #define _CLOG_LOG_PERRORF_STREAM(...)

    #define _CLOG_TLOG(...)
    #define _CLOG_TLOGLN(...)
    #define _CLOG_TLOGF(...)
    #define _CLOG_TLOGFLN(...)
    #define _CLOG_TLOG_HEX(...)
    #define _CLOG_TLOGLN_HEX(...)
    #define _CLOG_TLOG_WIDE_HEX(...)
    #define _CLOG_TLOGLN_WIDE_HEX(...)
    #define _CLOG_TLOG_PERROR(...)
    #define _CLOG_TLOG_PERRORF(...)


    #define _CLOG_C_LOG(...)
    #define _CLOG_C_LOGLN(...)
    #define _CLOG_C_LOGF(...)
    #define _CLOG_C_LOGFLN(...)
    #define _CLOG_C_LOG_HEX(...)
    #define _CLOG_C_LOGLN_HEX(...)
    #define _CLOG_C_LOG_WIDE_HEX(...)
    #define _CLOG_C_LOGLN_WIDE_HEX(...)
    #define _CLOG_C_LOG_PERROR(...)
    #define _CLOG_C_LOG_PERRORF(...)

    #define _CLOG_C_LOG_STREAM(...)
    #define _CLOG_C_LOGLN_STREAM(...)
    #define _CLOG_C_LOGF_STREAM(...)
    #define _CLOG_C_LOGFLN_STREAM(...)
    #define _CLOG_C_LOG_HEX_STREAM(...)
    #define _CLOG_C_LOGLN_HEX_STREAM(...)
    #define _CLOG_C_LOG_WIDE_HEX_STREAM(...)
    #define _CLOG_C_LOGLN_WIDE_HEX_STREAM(...)
    #define _CLOG_C_LOG_PERROR_STREAM(...)
    #define _CLOG_C_LOG_PERRORF_STREAM(...)

    #define _CLOG_C_TLOG(...)
    #define _CLOG_C_TLOGLN(...)
    #define _CLOG_C_TLOGF(...)
    #define _CLOG_C_TLOGFLN(...)
    #define _CLOG_C_TLOG_HEX(...)
    #define _CLOG_C_TLOGLN_HEX(...)
    #define _CLOG_C_TLOG_WIDE_HEX(...)
    #define _CLOG_C_TLOGLN_WIDE_HEX(...)
    #define _CLOG_C_TLOG_PERROR(...)
    #define _CLOG_C_TLOG_PERRORF(...)


    // Disable console log functions.

    #undef CLOG
    #define CLOG(...)
    #undef CLOGLN
    #define CLOGLN(...)
    #undef CLOGF
    #define CLOGF(...)
    #undef CLOGFLN
    #define CLOGFLN(...)
    #undef CLOG_HEX
    #define CLOG_HEX(...)
    #undef CLOGLN_HEX
    #define CLOGLN_HEX(...)
    #undef CLOG_WIDE_HEX
    #define CLOG_WIDE_HEX(...)
    #undef CLOGLN_WIDE_HEX
    #define CLOGLN_WIDE_HEX(...)
    #undef CLOG_PERROR
    #define CLOG_PERROR(...)
    #undef CLOG_PERRORF
    #define CLOG_PERRORF(...)

    #undef CLOG_STREAM
    #define CLOG_STREAM(...)
    #undef CLOGLN_STREAM
    #define CLOGLN_STREAM(...)
    #undef CLOGF_STREAM
    #define CLOGF_STREAM(...)
    #undef CLOGFLN_STREAM
    #define CLOGFLN_STREAM(...)
    #undef CLOG_HEX_STREAM
    #define CLOG_HEX_STREAM(...)
    #undef CLOGLN_HEX_STREAM
    #define CLOGLN_HEX_STREAM(...)
    #undef CLOG_WIDE_HEX_STREAM
    #define CLOG_WIDE_HEX_STREAM(...)
    #undef CLOGLN_WIDE_HEX_STREAM
    #define CLOGLN_WIDE_HEX_STREAM(...)
    #undef CLOG_PERROR_STREAM
    #define CLOG_PERROR_STREAM(...)
    #undef CLOG_PERRORF_STREAM
    #define CLOG_PERRORF_STREAM(...)

    #undef CTLOG
    #define CTLOG(...)
    #undef CTLOGLN
    #define CTLOGLN(...)
    #undef CTLOGF
    #define CTLOGF(...)
    #undef CTLOGFLN
    #define CTLOGFLN(...)
    #undef CTLOG_HEX
    #define CTLOG_HEX(...)
    #undef CTLOGLN_HEX
    #define CTLOGLN_HEX(...)
    #undef CTLOG_WIDE_HEX
    #define CTLOG_WIDE_HEX(...)
    #undef CTLOGLN_WIDE_HEX
    #define CTLOGLN_WIDE_HEX(...)
    #undef CTLOG_PERROR
    #define CTLOG_PERROR(...)
    #undef CTLOG_PERRORF
    #define CTLOG_PERRORF(...)

    #undef CCLOG
    #define CCLOG(...)
    #undef CCLOGLN
    #define CCLOGLN(...)
    #undef CCLOGF
    #define CCLOGF(...)
    #undef CCLOGFLN
    #define CCLOGFLN(...)
    #undef CCLOG_HEX
    #define CCLOG_HEX(...)
    #undef CCLOGLN_HEX
    #define CCLOGLN_HEX(...)
    #undef CCLOG_WIDE_HEX
    #define CCLOG_WIDE_HEX(...)
    #undef CCLOGLN_WIDE_HEX
    #define CCLOGLN_WIDE_HEX(...)
    #undef CCLOG_PERROR
    #define CCLOG_PERROR(...)
    #undef CCLOG_PERRORF
    #define CCLOG_PERRORF(...)

    #undef CCLOG_STREAM
    #define CCLOG_STREAM(...)
    #undef CCLOGLN_STREAM
    #define CCLOGLN_STREAM(...)
    #undef CCLOGF_STREAM
    #define CCLOGF_STREAM(...)
    #undef CCLOGFLN_STREAM
    #define CCLOGFLN_STREAM(...)
    #undef CCLOG_HEX_STREAM
    #define CCLOG_HEX_STREAM(...)
    #undef CCLOGLN_HEX_STREAM
    #define CCLOGLN_HEX_STREAM(...)
    #undef CCLOG_WIDE_HEX_STREAM
    #define CCLOG_WIDE_HEX_STREAM(...)
    #undef CCLOGLN_WIDE_HEX_STREAM
    #define CCLOGLN_WIDE_HEX_STREAM(...)
    #undef CCLOG_PERROR_STREAM
    #define CCLOG_PERROR_STREAM(...)
    #undef CCLOG_PERRORF_STREAM
    #define CCLOG_PERRORF_STREAM(...)

    #undef CCTLOG
    #define CCTLOG(...)
    #undef CCTLOGLN
    #define CCTLOGLN(...)
    #undef CCTLOGF
    #define CCTLOGF(...)
    #undef CCTLOGFLN
    #define CCTLOGFLN(...)
    #undef CCTLOG_HEX
    #define CCTLOG_HEX(...)
    #undef CCTLOGLN_HEX
    #define CCTLOGLN_HEX(...)
    #undef CCTLOG_WIDE_HEX
    #define CCTLOG_WIDE_HEX(...)
    #undef CCTLOGLN_WIDE_HEX
    #define CCTLOGLN_WIDE_HEX(...)
    #undef CCTLOG_PERROR
    #define CCTLOG_PERROR(...)
    #undef CCTLOG_PERRORF
    #define CCTLOG_PERRORF(...)

    // Disable file log functions.

    #undef FLOG
    #define FLOG(...)
    #undef FLOGLN
    #define FLOGLN(...)
    #undef FLOGF
    #define FLOGF(...)
    #undef FLOGFLN
    #define FLOGFLN(...)
    #undef FLOG_HEX
    #define FLOG_HEX(...)
    #undef FLOGLN_HEX
    #define FLOGLN_HEX(...)
    #undef FLOG_WIDE_HEX
    #define FLOG_WIDE_HEX(...)
    #undef FLOGLN_WIDE_HEX
    #define FLOGLN_WIDE_HEX(...)
    #undef FLOG_PERROR
    #define FLOG_PERROR(...)
    #undef FLOG_PERRORF
    #define FLOG_PERRORF(...)

    #undef FLOG_STREAM
    #define FLOG_STREAM(...)
    #undef FLOGLN_STREAM
    #define FLOGLN_STREAM(...)
    #undef FLOGF_STREAM
    #define FLOGF_STREAM(...)
    #undef FLOGFLN_STREAM
    #define FLOGFLN_STREAM(...)
    #undef FLOG_HEX_STREAM
    #define FLOG_HEX_STREAM(...)
    #undef FLOGLN_HEX_STREAM
    #define FLOGLN_HEX_STREAM(...)
    #undef FLOG_WIDE_HEX_STREAM
    #define FLOG_WIDE_HEX_STREAM(...)
    #undef FLOGLN_WIDE_HEX_STREAM
    #define FLOGLN_WIDE_HEX_STREAM(...)
    #undef FLOG_PERROR_STREAM
    #define FLOG_PERROR_STREAM(...)
    #undef FLOG_PERRORF_STREAM
    #define FLOG_PERRORF_STREAM(...)

    #undef FTLOG
    #define FTLOG(...)
    #undef FTLOGLN
    #define FTLOGLN(...)
    #undef FTLOGF
    #define FTLOGF(...)
    #undef FTLOGFLN
    #define FTLOGFLN(...)
    #undef FTLOG_HEX
    #define FTLOG_HEX(...)
    #undef FTLOGLN_HEX
    #define FTLOGLN_HEX(...)
    #undef FTLOG_WIDE_HEX
    #define FTLOG_WIDE_HEX(...)
    #undef FTLOGLN_WIDE_HEX
    #define FTLOGLN_WIDE_HEX(...)
    #undef FTLOG_PERROR
    #define FTLOG_PERROR(...)
    #undef FTLOG_PERRORF
    #define FTLOG_PERRORF(...)


#elif CLOG_MODE == CLOG_MODE_CONSOLE

    #define _CLOG_LOG(str) \
        CLOG(str)

    #define _CLOG_LOGLN(str) \
        CLOGLN(str)

    #define _CLOG_LOGF(...) \
        CLOGF(__VA_ARGS__)

    #define _CLOG_LOGFLN(...) \
        CLOGFLN(__VA_ARGS__)

    #define _CLOG_LOG_HEX(buffer, length) \
        CLOG_HEX(buffer, length)

    #define _CLOG_LOGLN_HEX(buffer, length) \
        CLOGLN_HEX(buffer, length)

    #define _CLOG_LOG_WIDE_HEX(buffer, length) \
        CLOG_WIDE_HEX(buffer, length)

    #define _CLOG_LOGLN_WIDE_HEX(buffer, length) \
        CLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_LOG_PERROR(str) \
        CLOG_PERROR(str)

    #define _CLOG_LOG_PERRORF(...) \
        CLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_LOG_STREAM(str) \
        CLOG_STREAM(str)

    #define _CLOG_LOGLN_STREAM(str) \
        CLOGLN_STREAM(str)

    #define _CLOG_LOGF_STREAM(...) \
        CLOGF_STREAM(__VA_ARGS__)

    #define _CLOG_LOGFLN_STREAM(...) \
        CLOGFLN_STREAM(__VA_ARGS__)

    #define _CLOG_LOG_HEX_STREAM(buffer, length) \
        CLOG_HEX_STREAM(buffer, length)

    #define _CLOG_LOGLN_HEX_STREAM(buffer, length) \
        CLOGLN_HEX_STREAM(buffer, length)

    #define _CLOG_LOG_WIDE_HEX_STREAM(buffer, length) \
        CLOG_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_LOGLN_WIDE_HEX_STREAM(buffer, length) \
        CLOGLN_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_LOG_PERROR_STREAM(str) \
        CLOG_PERROR_STREAM(str)

    #define _CLOG_LOG_PERRORF_STREAM(...) \
        CLOG_PERRORF_STREAM(__VA_ARGS__)


    #define _CLOG_TLOG(str) \
        CTLOG(str)

    #define _CLOG_TLOGLN(str) \
        CTLOGLN(str)

    #define _CLOG_TLOGF(...) \
        CTLOGF(__VA_ARGS__)

    #define _CLOG_TLOGFLN(...) \
        CTLOGFLN(__VA_ARGS__)

    #define _CLOG_TLOG_HEX(buffer, length) \
        CTLOG_HEX(buffer, length)

    #define _CLOG_TLOGLN_HEX(buffer, length) \
        CTLOGLN_HEX(buffer, length)

    #define _CLOG_TLOG_WIDE_HEX(buffer, length) \
        CTLOG_WIDE_HEX(buffer, length)

    #define _CLOG_TLOGLN_WIDE_HEX(buffer, length) \
        CTLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_TLOG_PERROR(str) \
        CTLOG_PERROR(str)

    #define _CLOG_TLOG_PERRORF(...) \
        CTLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_C_LOG(color, str) \
        _CLOG(color, str)

    #define _CLOG_C_LOGLN(color, str) \
        _CLOGLN(color, str)

    #define _CLOG_C_LOGF(color, ...) \
        _CLOGF(color, __VA_ARGS__)

    #define _CLOG_C_LOGFLN(color, ...) \
        _CLOGFLN(color, __VA_ARGS__)

    #define _CLOG_C_LOG_HEX(color, buffer, length) \
        _CLOG_HEX(color, buffer, length)

    #define _CLOG_C_LOGLN_HEX(color, buffer, length) \
        _CLOGLN_HEX(color, buffer, length)

    #define _CLOG_C_LOG_WIDE_HEX(color, buffer, length) \
        _CLOG_WIDE_HEX(color, buffer, length)

    #define _CLOG_C_LOGLN_WIDE_HEX(color, buffer, length) \
        _CLOGLN_WIDE_HEX(color, buffer, length)

    #define _CLOG_C_LOG_PERROR(color, str) \
        _CLOG_PERROR(color, str)

    #define _CLOG_C_LOG_PERRORF(color, ...) \
        _CLOG_PERRORF(color, __VA_ARGS__)


    #define _CLOG_C_LOG_STREAM(color, str) \
        _CLOG_STREAM(color, str)

    #define _CLOG_C_LOGLN_STREAM(color, str) \
        _CLOGLN_STREAM(color, str)

    #define _CLOG_C_LOGF_STREAM(color, ...) \
        _CLOGF_STREAM(color, __VA_ARGS__)

    #define _CLOG_C_LOGFLN_STREAM(color, ...) \
        _CLOGFLN_STREAM(color, __VA_ARGS__)

    #define _CLOG_C_LOG_HEX_STREAM(color, buffer, length) \
        _CLOG_HEX_STREAM(color, buffer, length)

    #define _CLOG_C_LOGLN_HEX_STREAM(color, buffer, length) \
        _CLOGLN_HEX_STREAM(color, buffer, length)

    #define _CLOG_C_LOG_WIDE_HEX_STREAM(color, buffer, length) \
        _CLOG_WIDE_HEX_STREAM(color, buffer, length)

    #define _CLOG_C_LOGLN_WIDE_HEX_STREAM(color, buffer, length) \
        _CLOGLN_WIDE_HEX_STREAM(color, buffer, length)

    #define _CLOG_C_LOG_PERROR_STREAM(color, str) \
        _CLOG_PERROR_STREAM(color, str)

    #define _CLOG_C_LOG_PERRORF_STREAM(color, ...) \
        _CLOG_PERRORF_STREAM(color, __VA_ARGS__)


    #define _CLOG_C_TLOG(color, str) \
        _CTLOG(color, str)

    #define _CLOG_C_TLOGLN(color, str) \
        _CTLOGLN(color, str)

    #define _CLOG_C_TLOGF(color, ...) \
        _CTLOGF(color, __VA_ARGS__)

    #define _CLOG_C_TLOGFLN(color, ...) \
        _CTLOGFLN(color, __VA_ARGS__)

    #define _CLOG_C_TLOG_HEX(color, buffer, length) \
        _CTLOG_HEX(color, buffer, length)

    #define _CLOG_C_TLOGLN_HEX(color, buffer, length) \
        _CTLOGLN_HEX(color, buffer, length)

    #define _CLOG_C_TLOG_WIDE_HEX(color, buffer, length) \
        _CTLOG_WIDE_HEX(color, buffer, length)

    #define _CLOG_C_TLOGLN_WIDE_HEX(color, buffer, length) \
        _CTLOGLN_WIDE_HEX(color, buffer, length)

    #define _CLOG_C_TLOG_PERROR(color, str) \
        _CTLOG_PERROR(color, str)

    #define _CLOG_C_TLOG_PERRORF(color, ...) \
        _CTLOG_PERRORF(color, __VA_ARGS__)


    // Disable file log functions.

    #undef FLOG
    #define FLOG(...)
    #undef FLOGLN
    #define FLOGLN(...)
    #undef FLOGF
    #define FLOGF(...)
    #undef FLOGFLN
    #define FLOGFLN(...)
    #undef FLOG_HEX
    #define FLOG_HEX(...)
    #undef FLOGLN_HEX
    #define FLOGLN_HEX(...)
    #undef FLOG_WIDE_HEX
    #define FLOG_WIDE_HEX(...)
    #undef FLOGLN_WIDE_HEX
    #define FLOGLN_WIDE_HEX(...)
    #undef FLOG_PERROR
    #define FLOG_PERROR(...)
    #undef FLOG_PERRORF
    #define FLOG_PERRORF(...)

    #undef FLOG_STREAM
    #define FLOG_STREAM(...)
    #undef FLOGLN_STREAM
    #define FLOGLN_STREAM(...)
    #undef FLOGF_STREAM
    #define FLOGF_STREAM(...)
    #undef FLOGFLN_STREAM
    #define FLOGFLN_STREAM(...)
    #undef FLOG_HEX_STREAM
    #define FLOG_HEX_STREAM(...)
    #undef FLOGLN_HEX_STREAM
    #define FLOGLN_HEX_STREAM(...)
    #undef FLOG_WIDE_HEX_STREAM
    #define FLOG_WIDE_HEX_STREAM(...)
    #undef FLOGLN_WIDE_HEX_STREAM
    #define FLOGLN_WIDE_HEX_STREAM(...)
    #undef FLOG_PERROR_STREAM
    #define FLOG_PERROR_STREAM(...)
    #undef FLOG_PERRORF_STREAM
    #define FLOG_PERRORF_STREAM(...)

    #undef FTLOG
    #define FTLOG(...)
    #undef FTLOGLN
    #define FTLOGLN(...)
    #undef FTLOGF
    #define FTLOGF(...)
    #undef FTLOGFLN
    #define FTLOGFLN(...)
    #undef FTLOG_HEX
    #define FTLOG_HEX(...)
    #undef FTLOGLN_HEX
    #define FTLOGLN_HEX(...)
    #undef FTLOG_WIDE_HEX
    #define FTLOG_WIDE_HEX(...)
    #undef FTLOGLN_WIDE_HEX
    #define FTLOGLN_WIDE_HEX(...)
    #undef FTLOG_PERROR
    #define FTLOG_PERROR(...)
    #undef FTLOG_PERRORF
    #define FTLOG_PERRORF(...)


#elif CLOG_MODE == CLOG_MODE_FILE

    #define _CLOG_LOG(str) \
        FLOG(str)

    #define _CLOG_LOGLN(str) \
        FLOGLN(str)

    #define _CLOG_LOGF(...) \
        FLOGF(__VA_ARGS__)

    #define _CLOG_LOGFLN(...) \
        FLOGFLN(__VA_ARGS__)

    #define _CLOG_LOG_HEX(buffer, length) \
        FLOG_HEX(buffer, length)

    #define _CLOG_LOGLN_HEX(buffer, length) \
        FLOGLN_HEX(buffer, length)

    #define _CLOG_LOG_WIDE_HEX(buffer, length) \
        FLOG_WIDE_HEX(buffer, length)

    #define _CLOG_LOGLN_WIDE_HEX(buffer, length) \
        FLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_LOG_PERROR(str) \
        FLOG_PERROR(str)

    #define _CLOG_LOG_PERRORF(...) \
        FLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_LOG_STREAM(str) \
        FLOG_STREAM(str)

    #define _CLOG_LOGLN_STREAM(str) \
        FLOGLN_STREAM(str)

    #define _CLOG_LOGF_STREAM(...) \
        FLOGF_STREAM(__VA_ARGS__)

    #define _CLOG_LOGFLN_STREAM(...) \
        FLOGFLN_STREAM(__VA_ARGS__)

    #define _CLOG_LOG_HEX_STREAM(buffer, length) \
        FLOG_HEX_STREAM(buffer, length)

    #define _CLOG_LOGLN_HEX_STREAM(buffer, length) \
        FLOGLN_HEX_STREAM(buffer, length)

    #define _CLOG_LOG_WIDE_HEX_STREAM(buffer, length) \
        FLOG_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_LOGLN_WIDE_HEX_STREAM(buffer, length) \
        FLOGLN_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_LOG_PERROR_STREAM(str) \
        FLOG_PERROR_STREAM(str)

    #define _CLOG_LOG_PERRORF_STREAM(...) \
        FLOG_PERRORF_STREAM(__VA_ARGS__)


    #define _CLOG_TLOG(str) \
        FTLOG(str)

    #define _CLOG_TLOGLN(str) \
        FTLOGLN(str)

    #define _CLOG_TLOGF(...) \
        FTLOGF(__VA_ARGS__)

    #define _CLOG_TLOGFLN(...) \
        FTLOGFLN(__VA_ARGS__)

    #define _CLOG_TLOG_HEX(buffer, length) \
        FTLOG_HEX(buffer, length)

    #define _CLOG_TLOGLN_HEX(buffer, length) \
        FTLOGLN_HEX(buffer, length)

    #define _CLOG_TLOG_WIDE_HEX(buffer, length) \
        FTLOG_WIDE_HEX(buffer, length)

    #define _CLOG_TLOGLN_WIDE_HEX(buffer, length) \
        FTLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_TLOG_PERROR(str) \
        FTLOG_PERROR(str)

    #define _CLOG_TLOG_PERRORF(...) \
        FTLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_C_LOG(color, str) \
        FLOG(str)

    #define _CLOG_C_LOGLN(color, str) \
        FLOGLN(str)

    #define _CLOG_C_LOGF(color, ...) \
        FLOGF(__VA_ARGS__)

    #define _CLOG_C_LOGFLN(color, ...) \
        FLOGFLN(__VA_ARGS__)

    #define _CLOG_C_LOG_HEX(color, buffer, length) \
        FLOG_HEX(buffer, length)

    #define _CLOG_C_LOGLN_HEX(color, buffer, length) \
        FLOGLN_HEX(buffer, length)

    #define _CLOG_C_LOG_WIDE_HEX(color, buffer, length) \
        FLOG_WIDE_HEX(buffer, length)

    #define _CLOG_C_LOGLN_WIDE_HEX(color, buffer, length) \
        FLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_C_LOG_PERROR(color, str) \
        FLOG_PERROR(str)

    #define _CLOG_C_LOG_PERRORF(color, ...) \
        FLOG_PERRORF(__VA_ARGS__)


    #define _CLOG_C_LOG_STREAM(color, str) \
        FLOG_STREAM(str)

    #define _CLOG_C_LOGLN_STREAM(color, str) \
        FLOGLN_STREAM(str)

    #define _CLOG_C_LOGF_STREAM(color, ...) \
        FLOGF_STREAM(__VA_ARGS__)

    #define _CLOG_C_LOGFLN_STREAM(color, ...) \
        FLOGFLN_STREAM(__VA_ARGS__)

    #define _CLOG_C_LOG_HEX_STREAM(color, buffer, length) \
        FLOG_HEX_STREAM(buffer, length)

    #define _CLOG_C_LOGLN_HEX_STREAM(color, buffer, length) \
        FLOGLN_HEX_STREAM(buffer, length)

    #define _CLOG_C_LOG_WIDE_HEX_STREAM(color, buffer, length) \
        FLOG_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_C_LOGLN_WIDE_HEX_STREAM(color, buffer, length) \
        FLOGLN_WIDE_HEX_STREAM(buffer, length)

    #define _CLOG_C_LOG_PERROR_STREAM(color, str) \
        FLOG_PERROR_STREAM(str)

    #define _CLOG_C_LOG_PERRORF_STREAM(color, ...) \
        FLOG_PERRORF_STREAM(__VA_ARGS__)


    #define _CLOG_C_TLOG(color, str) \
        FTLOG(str)

    #define _CLOG_C_TLOGLN(color, str) \
        FTLOGLN(str)

    #define _CLOG_C_TLOGF(color, ...) \
        FTLOGF(__VA_ARGS__)

    #define _CLOG_C_TLOGFLN(color, ...) \
        FTLOGFLN(__VA_ARGS__)

    #define _CLOG_C_TLOG_HEX(color, buffer, length) \
        FTLOG_HEX(buffer, length)

    #define _CLOG_C_TLOGLN_HEX(color, buffer, length) \
        FTLOGLN_HEX(buffer, length)

    #define _CLOG_C_TLOG_WIDE_HEX(color, buffer, length) \
        FTLOG_WIDE_HEX(buffer, length)

    #define _CLOG_C_TLOGLN_WIDE_HEX(color, buffer, length) \
        FTLOGLN_WIDE_HEX(buffer, length)

    #define _CLOG_C_TLOG_PERROR(color, str) \
        FTLOG_PERROR(str)

    #define _CLOG_C_TLOG_PERRORF(color, ...) \
        FTLOG_PERRORF(__VA_ARGS__)


    // For now, CLOG_MODE_FILE disables console logging.

    #undef CLOG
    #define CLOG(...)
    #undef CLOGLN
    #define CLOGLN(...)
    #undef CLOGF
    #define CLOGF(...)
    #undef CLOGFLN
    #define CLOGFLN(...)
    #undef CLOG_HEX
    #define CLOG_HEX(...)
    #undef CLOGLN_HEX
    #define CLOGLN_HEX(...)
    #undef CLOG_WIDE_HEX
    #define CLOG_WIDE_HEX(...)
    #undef CLOGLN_WIDE_HEX
    #define CLOGLN_WIDE_HEX(...)
    #undef CLOG_PERROR
    #define CLOG_PERROR(...)
    #undef CLOG_PERRORF
    #define CLOG_PERRORF(...)

    #undef CLOG_STREAM
    #define CLOG_STREAM(...)
    #undef CLOGLN_STREAM
    #define CLOGLN_STREAM(...)
    #undef CLOGF_STREAM
    #define CLOGF_STREAM(...)
    #undef CLOGFLN_STREAM
    #define CLOGFLN_STREAM(...)
    #undef CLOG_HEX_STREAM
    #define CLOG_HEX_STREAM(...)
    #undef CLOGLN_HEX_STREAM
    #define CLOGLN_HEX_STREAM(...)
    #undef CLOG_WIDE_HEX_STREAM
    #define CLOG_WIDE_HEX_STREAM(...)
    #undef CLOGLN_WIDE_HEX_STREAM
    #define CLOGLN_WIDE_HEX_STREAM(...)
    #undef CLOG_PERROR_STREAM
    #define CLOG_PERROR_STREAM(...)
    #undef CLOG_PERRORF_STREAM
    #define CLOG_PERRORF_STREAM(...)

    #undef CTLOG
    #define CTLOG(...)
    #undef CTLOGLN
    #define CTLOGLN(...)
    #undef CTLOGF
    #define CTLOGF(...)
    #undef CTLOGFLN
    #define CTLOGFLN(...)
    #undef CTLOG_HEX
    #define CTLOG_HEX(...)
    #undef CTLOGLN_HEX
    #define CTLOGLN_HEX(...)
    #undef CTLOG_WIDE_HEX
    #define CTLOG_WIDE_HEX(...)
    #undef CTLOGLN_WIDE_HEX
    #define CTLOGLN_WIDE_HEX(...)
    #undef CTLOG_PERROR
    #define CTLOG_PERROR(...)
    #undef CTLOG_PERRORF
    #define CTLOG_PERRORF(...)

    #undef CCLOG
    #define CCLOG(...)
    #undef CCLOGLN
    #define CCLOGLN(...)
    #undef CCLOGF
    #define CCLOGF(...)
    #undef CCLOGFLN
    #define CCLOGFLN(...)
    #undef CCLOG_HEX
    #define CCLOG_HEX(...)
    #undef CCLOGLN_HEX
    #define CCLOGLN_HEX(...)
    #undef CCLOG_WIDE_HEX
    #define CCLOG_WIDE_HEX(...)
    #undef CCLOGLN_WIDE_HEX
    #define CCLOGLN_WIDE_HEX(...)
    #undef CCLOG_PERROR
    #define CCLOG_PERROR(...)
    #undef CCLOG_PERRORF
    #define CCLOG_PERRORF(...)

    #undef CCLOG_STREAM
    #define CCLOG_STREAM(...)
    #undef CCLOGLN_STREAM
    #define CCLOGLN_STREAM(...)
    #undef CCLOGF_STREAM
    #define CCLOGF_STREAM(...)
    #undef CCLOGFLN_STREAM
    #define CCLOGFLN_STREAM(...)
    #undef CCLOG_HEX_STREAM
    #define CCLOG_HEX_STREAM(...)
    #undef CCLOGLN_HEX_STREAM
    #define CCLOGLN_HEX_STREAM(...)
    #undef CCLOG_WIDE_HEX_STREAM
    #define CCLOG_WIDE_HEX_STREAM(...)
    #undef CCLOGLN_WIDE_HEX_STREAM
    #define CCLOGLN_WIDE_HEX_STREAM(...)
    #undef CCLOG_PERROR_STREAM
    #define CCLOG_PERROR_STREAM(...)
    #undef CCLOG_PERRORF_STREAM
    #define CCLOG_PERRORF_STREAM(...)

    #undef CCTLOG
    #define CCTLOG(...)
    #undef CCTLOGLN
    #define CCTLOGLN(...)
    #undef CCTLOGF
    #define CCTLOGF(...)
    #undef CCTLOGFLN
    #define CCTLOGFLN(...)
    #undef CCTLOG_HEX
    #define CCTLOG_HEX(...)
    #undef CCTLOGLN_HEX
    #define CCTLOGLN_HEX(...)
    #undef CCTLOG_WIDE_HEX
    #define CCTLOG_WIDE_HEX(...)
    #undef CCTLOGLN_WIDE_HEX
    #define CCTLOGLN_WIDE_HEX(...)
    #undef CCTLOG_PERROR
    #define CCTLOG_PERROR(...)
    #undef CCTLOG_PERRORF
    #define CCTLOG_PERRORF(...)


#else

    #define _CLOG_LOG(str) { \
        CLOG(str) \
        FLOG(str) \
    }

    #define _CLOG_LOGLN(str) { \
        CLOGLN(str) \
        FLOGLN(str) \
    }

    #define _CLOG_LOGF(...) { \
        CLOGF(__VA_ARGS__) \
        FLOGF(__VA_ARGS__) \
    }

    #define _CLOG_LOGFLN(...) { \
        CLOGFLN(__VA_ARGS__) \
        FLOGFLN(__VA_ARGS__) \
    }

    #define _CLOG_LOG_HEX(buffer, length) { \
        CLOG_HEX(buffer, length) \
        FLOG_HEX(buffer, length) \
    }

    #define _CLOG_LOGLN_HEX(buffer, length) { \
        CLOGLN_HEX(buffer, length) \
        FLOGLN_HEX(buffer, length) \
    }

    #define _CLOG_LOG_WIDE_HEX(buffer, length) { \
        CLOG_WIDE_HEX(buffer, length) \
        FLOG_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_LOGLN_WIDE_HEX(buffer, length) { \
        CLOGLN_WIDE_HEX(buffer, length) \
        FLOGLN_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_LOG_PERROR(str) { \
        CLOG_PERROR(str) \
        FLOG_PERROR(str) \
    }

    #define _CLOG_LOG_PERRORF(...) { \
        CLOG_PERRORF(__VA_ARGS__) \
        FLOG_PERRORF(__VA_ARGS__) \
    }


    #define _CLOG_LOG_STREAM(str) { \
        CLOG_STREAM(str) \
        FLOG_STREAM(str) \
    }

    #define _CLOG_LOGLN_STREAM(str) { \
        CLOGLN_STREAM(str) \
        FLOGLN_STREAM(str) \
    }

    #define _CLOG_LOGF_STREAM(...) { \
        CLOGF_STREAM(__VA_ARGS__) \
        FLOGF_STREAM(__VA_ARGS__) \
    }

    #define _CLOG_LOGFLN_STREAM(...) { \
        CLOGFLN_STREAM(__VA_ARGS__) \
        FLOGFLN_STREAM(__VA_ARGS__) \
    }

    #define _CLOG_LOG_HEX_STREAM(buffer, length) { \
        CLOG_HEX_STREAM(buffer, length) \
        FLOG_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_LOGLN_HEX_STREAM(buffer, length) { \
        CLOGLN_HEX_STREAM(buffer, length) \
        FLOGLN_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_LOG_WIDE_HEX_STREAM(buffer, length) { \
        CLOG_WIDE_HEX_STREAM(buffer, length) \
        FLOG_WIDE_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_LOGLN_WIDE_HEX_STREAM(buffer, length) { \
        CLOGLN_WIDE_HEX_STREAM(buffer, length) \
        FLOGLN_WIDE_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_LOG_PERROR_STREAM(str) { \
        CLOG_PERROR_STREAM(str) \
        FLOG_PERROR_STREAM(str) \
    }

    #define _CLOG_LOG_PERRORF_STREAM(...) { \
        CLOG_PERRORF_STREAM(__VA_ARGS__) \
        FLOG_PERRORF_STREAM(__VA_ARGS__) \
    }


    #define _CLOG_TLOG(str) { \
        CTLOG(str) \
        FTLOG(str) \
    }

    #define _CLOG_TLOGLN(str) { \
        CTLOGLN(str) \
        FTLOGLN(str) \
    }

    #define _CLOG_TLOGF(...) { \
        CTLOGF(__VA_ARGS__) \
        FTLOGF(__VA_ARGS__) \
    }

    #define _CLOG_TLOGFLN(...) { \
        CTLOGFLN(__VA_ARGS__) \
        FTLOGFLN(__VA_ARGS__) \
    }

    #define _CLOG_TLOG_HEX(buffer, length) { \
        CTLOG_HEX(buffer, length) \
        FTLOG_HEX(buffer, length) \
    }

    #define _CLOG_TLOGLN_HEX(buffer, length) { \
        CTLOGLN_HEX(buffer, length) \
        FTLOGLN_HEX(buffer, length) \
    }

    #define _CLOG_TLOG_WIDE_HEX(buffer, length) { \
        CTLOG_WIDE_HEX(buffer, length) \
        FTLOG_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_TLOGLN_WIDE_HEX(buffer, length) { \
        CTLOGLN_WIDE_HEX(buffer, length) \
        FTLOGLN_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_TLOG_PERROR(str) { \
        CTLOG_PERROR(str) \
        FTLOG_PERROR(str) \
    }

    #define _CLOG_TLOG_PERRORF(...) { \
        CTLOG_PERRORF(__VA_ARGS__) \
        FTLOG_PERRORF(__VA_ARGS__) \
    }



    #define _CLOG_C_LOG(color, str) { \
        _CLOG(color, str) \
        FLOG(str) \
    }

    #define _CLOG_C_LOGLN(color, str) { \
        _CLOGLN(color, str) \
        FLOGLN(str) \
    }

    #define _CLOG_C_LOGF(color, ...) { \
        _CLOGF(color, __VA_ARGS__) \
        FLOGF(__VA_ARGS__) \
    }

    #define _CLOG_C_LOGFLN(color, ...) { \
        _CLOGFLN(color, __VA_ARGS__) \
        FLOGFLN(__VA_ARGS__) \
    }

    #define _CLOG_C_LOG_HEX(color, buffer, length) { \
        _CLOG_HEX(color, buffer, length) \
        FLOG_HEX(buffer, length) \
    }

    #define _CLOG_C_LOGLN_HEX(color, buffer, length) { \
        _CLOGLN_HEX(color, buffer, length) \
        FLOGLN_HEX(buffer, length) \
    }

    #define _CLOG_C_LOG_WIDE_HEX(color, buffer, length) { \
        _CLOG_WIDE_HEX(color, buffer, length) \
        FLOG_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_C_LOGLN_WIDE_HEX(color, buffer, length) { \
        _CLOGLN_WIDE_HEX(color, buffer, length) \
        FLOGLN_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_C_LOG_PERROR(color, str) { \
        _CLOG_PERROR(color, str) \
        FLOG_PERROR(str) \
    }

    #define _CLOG_C_LOG_PERRORF(color, ...) { \
        _CLOG_PERRORF(color, __VA_ARGS__) \
        FLOG_PERRORF(__VA_ARGS__) \
    }


    #define _CLOG_C_LOG_STREAM(color, str) { \
        _CLOG_STREAM(color, str) \
        FLOG_STREAM(str) \
    }

    #define _CLOG_C_LOGLN_STREAM(color, str) { \
        _CLOGLN_STREAM(color, str) \
        FLOGLN_STREAM(str) \
    }

    #define _CLOG_C_LOGF_STREAM(color, ...) { \
        _CLOGF_STREAM(color, __VA_ARGS__) \
        FLOGF_STREAM(__VA_ARGS__) \
    }

    #define _CLOG_C_LOGFLN_STREAM(color, ...) { \
        _CLOGFLN_STREAM(color, __VA_ARGS__) \
        FLOGFLN_STREAM(__VA_ARGS__) \
    }

    #define _CLOG_C_LOG_HEX_STREAM(color, buffer, length) { \
        _CLOG_HEX_STREAM(color, buffer, length) \
        FLOG_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_C_LOGLN_HEX_STREAM(color, buffer, length) { \
        _CLOGLN_HEX_STREAM(color, buffer, length) \
        FLOGLN_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_C_LOG_WIDE_HEX_STREAM(color, buffer, length) { \
        _CLOG_WIDE_HEX_STREAM(color, buffer, length) \
        FLOG_WIDE_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_C_LOGLN_WIDE_HEX_STREAM(color, buffer, length) { \
        _CLOGLN_WIDE_HEX_STREAM(color, buffer, length) \
        FLOGLN_WIDE_HEX_STREAM(buffer, length) \
    }

    #define _CLOG_C_LOG_PERROR_STREAM(color, str) { \
        _CLOG_PERROR_STREAM(color, str) \
        FLOG_PERROR_STREAM(str) \
    }

    #define _CLOG_C_LOG_PERRORF_STREAM(color, ...) { \
        _CLOG_PERRORF_STREAM(color, __VA_ARGS__) \
        FLOG_PERRORF_STREAM(__VA_ARGS__) \
    }


    #define _CLOG_C_TLOG(color, str) { \
        _CTLOG(color, str) \
        FTLOG(str) \
    }

    #define _CLOG_C_TLOGLN(color, str) { \
        _CTLOGLN(color, str) \
        FTLOGLN(str) \
    }

    #define _CLOG_C_TLOGF(color, ...) { \
        _CTLOGF(color, __VA_ARGS__) \
        FTLOGF(__VA_ARGS__) \
    }

    #define _CLOG_C_TLOGFLN(color, ...) { \
        _CTLOGFLN(color, __VA_ARGS__) \
        FTLOGFLN(__VA_ARGS__) \
    }

    #define _CLOG_C_TLOG_HEX(color, buffer, length) { \
        _CTLOG_HEX(color, buffer, length) \
        FTLOG_HEX(buffer, length) \
    }

    #define _CLOG_C_TLOGLN_HEX(color, buffer, length) { \
        _CTLOGLN_HEX(color, buffer, length) \
        FTLOGLN_HEX(buffer, length) \
    }

    #define _CLOG_C_TLOG_WIDE_HEX(color, buffer, length) { \
        _CTLOG_WIDE_HEX(color, buffer, length) \
        FTLOG_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_C_TLOGLN_WIDE_HEX(color, buffer, length) { \
        _CTLOGLN_WIDE_HEX(color, buffer, length) \
        FTLOGLN_WIDE_HEX(buffer, length) \
    }

    #define _CLOG_C_TLOG_PERROR(color, str) { \
        _CTLOG_PERROR(color, str) \
        FTLOG_PERROR(str) \
    }

    #define _CLOG_C_TLOG_PERRORF(color, ...) { \
        _CTLOG_PERRORF(color, __VA_ARGS__) \
        FTLOG_PERRORF(__VA_ARGS__) \
    }

#endif


/**
 *  "log" Functions
 *  =================
 *
 *  The "log" series are for logging to standard error and/or a file and
 *  prepend the log with a timestamp.
 *
 *  There are several function-like macros available:
 *
 *      LOG(const char* str)
 *      LOGLN(const char* str)
 *      LOGF(const char* format, ...)
 *      LOGFLN(const char* format, ...)
 *      LOG_HEX(const uint8_t* buffer, size_t length)
 *      LOGLN_HEX(const uint8_t* buffer, size_t length)
 *      LOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      LOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      LOG_PERROR(const char* str)
 *      LOG_PERRORF(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void LOG(const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file.
 *
 *  @param  str         String to print.
 */
#define LOG(str) \
    _CLOG_LOG(str)

/**
 *  void LOGLN(const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file followed
 *  by a newline.
 *
 *  @param  str         String to print.
 */
#define LOGLN(str) \
    _CLOG_LOGLN(str)

/**
 *  void LOGF(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF(...) \
    _CLOG_LOGF(__VA_ARGS__)

/**
 *  void LOGFLN(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN(...) \
    _CLOG_LOGFLN(__VA_ARGS__)

/**
 *  void LOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to standard
 *  error and/or a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOG_HEX(buffer, length) \
    _CLOG_LOG_HEX(buffer, length)

/**
 *  void LOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to standard
 *  error and/or a file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOGLN_HEX(buffer, length) \
    _CLOG_LOGLN_HEX(buffer, length)

/**
 *  void LOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  and/or a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOG_WIDE_HEX(buffer, length) \
    _CLOG_LOG_WIDE_HEX(buffer, length)

/**
 *  void LOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  and/or a file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOGLN_WIDE_HEX(buffer, length) \
    _CLOG_LOGLN_WIDE_HEX(buffer, length)

/**
 *  void LOG_PERROR(const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file and then
 *  print the C error message.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR(str) \
    _CLOG_LOG_PERROR(str)

/**
 *  void LOG_PERRORF(const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF(...) \
    _CLOG_LOG_PERRORF(__VA_ARGS__)


/**
 *  "log_stream" Functions
 *  -----------------------
 *
 *  The "log_stream" series are for logging to standard error and/or a file
 *  just like the "log" functions, but these ones do NOT prepend the log with a
 *  timestamp, so they can be used to continue lines without a line break or
 *  for logging data without having a timestamp.
 *
 *  There are several function-like macros available:
 *
 *      LOG_STREAM(const char* str)
 *      LOGLN_STREAM(const char* str)
 *      LOGF_STREAM(const char* format, ...)
 *      LOGFLN_STREAM(const char* format, ...)
 *      LOG_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      LOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      LOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      LOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)
 *      LOG_PERROR_STREAM(const char* str)
 *      LOG_PERRORF_STREAM(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void LOG_STREAM(const char* str);
 *
 *  Log the given string to standard error and/or a file.
 *
 *  @param  str         String to print.
 */
#define LOG_STREAM(str) \
    _CLOG_LOG_STREAM(str)

/**
 *  void LOGLN_STREAM(const char* str);
 *
 *  Log the given string to standard error and/or a file followed by a newline.
 *
 *  @param  str         String to print.
 */
#define LOGLN_STREAM(str) \
    _CLOG_LOGLN_STREAM(str)

/**
 *  void LOGF_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_STREAM(...) \
    _CLOG_LOGF_STREAM(__VA_ARGS__)

/**
 *  void LOGFLN_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_STREAM(...) \
    _CLOG_LOGFLN_STREAM(__VA_ARGS__)

/**
 *  void LOG_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string to standard error and/or
 *  a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOG_HEX_STREAM(buffer, length) \
    _CLOG_LOG_HEX_STREAM(buffer, length)

/**
 *  void LOGLN_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string to standard error and/or
 *  a file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOGLN_HEX_STREAM(buffer, length) \
    _CLOG_LOGLN_HEX_STREAM(buffer, length)

/**
 *  void LOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error and/or a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOG_WIDE_HEX_STREAM(buffer, length) \
    _CLOG_LOG_WIDE_HEX_STREAM(buffer, length)

/**
 *  void LOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length);
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error and/or a file
 *  followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define LOGLN_WIDE_HEX_STREAM(buffer, length) \
    _CLOG_LOGLN_WIDE_HEX_STREAM(buffer, length)

/**
 *  void LOG_PERROR_STREAM(const char* str);
 *
 *  Log the given string to standard error and/or a file and then print the C
 *  error message.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR_STREAM(str) \
    _CLOG_LOG_PERROR_STREAM(str)

/**
 *  void LOG_PERRORF_STREAM(const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF_STREAM(...) \
    _CLOG_LOG_PERRORF_STREAM(__VA_ARGS__)


/**
 *  "tlog" Functions
 *  -----------------
 *
 *  The "tlog" series also print to standard error and/or a file with a
 *  timestamp just like the "log" functions. But these functions also add a
 *  tracing element to the log for the case where you specifically want tracing
 *  information.
 *
 *  There are several function-like macros available:
 *
 *      TLOG(const char* str)
 *      TLOGLN(const char* str)
 *      TLOGF(const char* format, ...)
 *      TLOGFLN(const char* format, ...)
 *      TLOG_HEX(const uint8_t* buffer, size_t length)
 *      TLOGLN_HEX(const uint8_t* buffer, size_t length)
 *      TLOG_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      TLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)
 *      TLOG_PERROR(const char* str)
 *      TLOG_PERRORF(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void TLOG(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file.
 *
 *  @param  str         String to print.
 */
#define TLOG(str) \
    _CLOG_TLOG(str)

/**
 *  void TLOGLN(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file followed by a newline.
 *
 *  @param  str         String to print.
 */
#define TLOGLN(str) \
    _CLOG_TLOGLN(str)

/**
 *  void TLOGF(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define TLOGF(...) \
    _CLOG_TLOGF(__VA_ARGS__)

/**
 *  void TLOGFLN(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define TLOGFLN(...) \
    _CLOG_TLOGFLN(__VA_ARGS__)

/**
 *  void TLOG_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string to standard error and/or a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define TLOG_HEX(buffer, length) \
    _CLOG_TLOG_HEX(buffer, length)

/**
 *  void TLOGLN_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string to standard error and/or a file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define TLOGLN_HEX(buffer, length) \
    _CLOG_TLOGLN_HEX(buffer, length)

/**
 *  void TLOG_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string with preceding "0x" before each byte and delimited by spaces to
 *  standard error and/or a file.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define TLOG_WIDE_HEX(buffer, length) \
    _CLOG_TLOG_WIDE_HEX(buffer, length)

/**
 *  void TLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string with preceding "0x" before each byte and delimited by spaces to
 *  standard error and/or a file followed by a newline.
 *
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define TLOGLN_WIDE_HEX(buffer, length) \
    _CLOG_TLOGLN_WIDE_HEX(buffer, length)

/**
 *  void TLOG_PERROR(const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file and then print the C error message.
 *
 *  @param  str         String to print.
 */
#define TLOG_PERROR(str) \
    _CLOG_TLOG_PERROR(str)

/**
 *  void TLOG_PERRORF(const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define TLOG_PERRORF(...) \
    _CLOG_TLOG_PERRORF(__VA_ARGS__)


/**
 *  "c_log" Functions
 *  -----------------
 *
 *  The "c_log" series also print to standard error and/or a file with a
 *  timestamp just like the "c_log" functions. But these functions have a color
 *  parameter and output colored text in console logs.
 *
 *  There are several function-like macros available:
 *
 *      C_LOG(const char* color, const char* str)
 *      C_LOGLN(const char* color, const char* str)
 *      C_LOGF(const char* color, const char* format, ...)
 *      C_LOGFLN(const char* color, const char* format, ...)
 *      C_LOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      C_LOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      C_LOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      C_LOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_LOG_PERROR(const char* color, const char* str)
 *      C_LOG_PERRORF(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void C_LOG(const char* color, const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file in the
 *  given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOG(color, str) \
    _CLOG_C_LOG(color, str)

/**
 *  void C_LOGLN(const char* color, const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file followed
 *  by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOGLN(color, str) \
    _CLOG_C_LOGLN(color, str)

/**
 *  void C_LOGF(const char* color, const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOGF(color, ...) \
    _CLOG_C_LOGF(color, __VA_ARGS__)

/**
 *  void C_LOGFLN(const char* color, const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file followed by a newline in the given color (for console
 *  logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOGFLN(color, ...) \
    _CLOG_C_LOGFLN(color, __VA_ARGS__)

/**
 *  void C_LOG_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to standard
 *  error and/or a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOG_HEX(color, buffer, length) \
    _CLOG_C_LOG_HEX(color, buffer, length)

/**
 *  void C_LOGLN_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Log timestamp and the bytes of the given buffer as a hex string to standard
 *  error and/or a file followed by a newline in the given color (for console
 *  logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOGLN_HEX(color, buffer, length) \
    _CLOG_C_LOGLN_HEX(color, buffer, length)

/**
 *  void C_LOG_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  and/or a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOG_WIDE_HEX(color, buffer, length) \
    _CLOG_C_LOG_WIDE_HEX(color, buffer, length)

/**
 *  void C_LOGLN_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log timestamp and the bytes of the given buffer as a hex string with
 *  preceding "0x" before each byte and delimited by spaces to standard error
 *  and/or a file followed by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOGLN_WIDE_HEX(color, buffer, length) \
    _CLOG_C_LOGLN_WIDE_HEX(color, buffer, length)

/**
 *  void C_LOG_PERROR(const char* color, const char* str);
 *
 *  Log timestamp and the given string to standard error and/or a file and then
 *  print the C error message in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOG_PERROR(color, str) \
    _CLOG_C_LOG_PERROR(color, str)

/**
 *  void C_LOG_PERRORF(const char* color, const char* format, ...);
 *
 *  Log timestamp and the given format string and format arguments to standard
 *  error and/or a file followed by a C error message in the given color (for
 *  console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOG_PERRORF(color, ...) \
    _CLOG_C_LOG_PERRORF(color, __VA_ARGS__)


/**
 *  "c_log_stream" Functions
 *  -----------------------
 *
 *  The "c_log_stream" series are for logging to standard err and/or a file
 *  just like the "log" functions, but these ones do NOT prepend the log with a
 *  timestamp, so they can be used to continue lines without a line break or
 *  for logging data without having a timestamp. But these functions have a
 *  color parameter and output colored text in console logs.
 *
 *  There are several function-like macros available:
 *
 *      C_LOG_STREAM(const char* color, const char* str)
 *      C_LOGLN_STREAM(const char* color, const char* str)
 *      C_LOGF_STREAM(const char* color, const char* format, ...)
 *      C_LOGFLN_STREAM(const char* color, const char* format, ...)
 *      C_LOG_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_LOGLN_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_LOG_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_LOGLN_WIDE_HEX_STREAM(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_LOG_PERROR_STREAM(const char* color, const char* str)
 *      C_LOG_PERRORF_STREAM(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void C_LOG_STREAM(const char* color, const char* str);
 *
 *  Log the given string to standard error and/or a file in the given color
 *  (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOG_STREAM(color, str) \
    _CLOG_C_LOG_STREAM(color, str)

/**
 *  void C_LOGLN_STREAM(const char* color, const char* str);
 *
 *  Log the given string to standard error and/or a file followed by a newline
 *  in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOGLN_STREAM(color, str) \
    _CLOG_C_LOGLN_STREAM(color, str)

/**
 *  void C_LOGF_STREAM(const char* color, const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOGF_STREAM(color, ...) \
    _CLOG_C_LOGF_STREAM(color, __VA_ARGS__)

/**
 *  void C_LOGFLN_STREAM(const char* color, const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file followed by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOGFLN_STREAM(color, ...) \
    _CLOG_C_LOGFLN_STREAM(color, __VA_ARGS__)

/**
 *  void C_LOG_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log the bytes of the given buffer as a hex string to standard error and/or
 *  a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOG_HEX_STREAM(color, buffer, length) \
    _CLOG_C_LOG_HEX_STREAM(color, buffer, length)

/**
 *  void C_LOGLN_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log the bytes of the given buffer as a hex string to standard error and/or
 *  a file followed by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOGLN_HEX_STREAM(color, buffer, length) \
    _CLOG_C_LOGLN_HEX_STREAM(color, buffer, length)

/**
 *  void C_LOG_WIDE_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error and/or a file in
 *  the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOG_WIDE_HEX_STREAM(color, buffer, length) \
    _CLOG_C_LOG_WIDE_HEX_STREAM(color, buffer, length)

/**
 *  void C_LOGLN_WIDE_HEX_STREAM(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log the bytes of the given buffer as a hex string with preceding "0x"
 *  before each byte and delimited by spaces to standard error and/or a file
 *  followed by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_LOGLN_WIDE_HEX_STREAM(color, buffer, length) \
    _CLOG_C_LOGLN_WIDE_HEX_STREAM(color, buffer, length)

/**
 *  void C_LOG_PERROR_STREAM(const char* color, const char* str);
 *
 *  Log the given string to standard error and/or a file and then print the C
 *  error message in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_LOG_PERROR_STREAM(color, str) \
    _CLOG_C_LOG_PERROR_STREAM(color, str)

/**
 *  void C_LOG_PERRORF_STREAM(const char* color, const char* format, ...);
 *
 *  Log the given format string and format arguments to standard error and/or a
 *  file followed by a C error message in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_LOG_PERRORF_STREAM(color, ...) \
    _CLOG_C_LOG_PERRORF_STREAM(color, __VA_ARGS__)


/**
 *  "c_tlog" Functions
 *  ------------------
 *
 *  The "c_tlog" series also print to standard error and/or a file with a
 *  timestamp just like the "log" functions. But these functions also add a
 *  tracing element to the log for the case where you specifically want tracing
 *  information, and these functions have a color parameter and output colored
 *  text in console logs.
 *
 *  There are several function-like macros available:
 *
 *      C_TLOG(const char* color, const char* str)
 *      C_TLOGLN(const char* color, const char* str)
 *      C_TLOGF(const char* color, const char* format, ...)
 *      C_TLOGFLN(const char* color, const char* format, ...)
 *      C_TLOG_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      C_TLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)
 *      C_TLOG_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_TLOGLN_WIDE_HEX(
 *          const char* color, const uint8_t* buffer, size_t length
 *      )
 *      C_TLOG_PERROR(const char* color, const char* str)
 *      C_TLOG_PERRORF(const char* color, const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void C_TLOG(const char* color, const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_TLOG(color, str) \
    _CLOG_C_TLOG(color, str)

/**
 *  void C_TLOGLN(const char* color, const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file followed by a newline in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_TLOGLN(color, str) \
    _CLOG_C_TLOGLN(color, str)

/**
 *  void C_TLOGF(const char* color, const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file in the given color (for console
 *  logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_TLOGF(color, ...) \
    _CLOG_C_TLOGF(color, __VA_ARGS__)

/**
 *  void C_TLOGFLN(const char* color, const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_TLOGFLN(color, ...) \
    _CLOG_C_TLOGFLN(color, __VA_ARGS__)

/**
 *  void C_TLOG_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string to standard error and/or a file in the given color (for console
 *  logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_TLOG_HEX(color, buffer, length) \
    _CLOG_C_TLOG_HEX(color, buffer, length)

/**
 *  void C_TLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length);
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string to standard error and/or a file followed by a newline in the
 *  given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_TLOGLN_HEX(color, buffer, length) \
    _CLOG_C_TLOGLN_HEX(color, buffer, length)

/**
 *  void C_TLOG_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string with preceding "0x" before each byte and delimited by spaces to
 *  standard error and/or a file in the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_TLOG_WIDE_HEX(color, buffer, length) \
    _CLOG_C_TLOG_WIDE_HEX(color, buffer, length)

/**
 *  void C_TLOGLN_WIDE_HEX(
 *      const char* color, const uint8_t* buffer, size_t length
 *  );
 *
 *  Log timestamp, tracing information, and the bytes of the given buffer as a
 *  hex string with preceding "0x" before each byte and delimited by spaces to
 *  standard error and/or a file followed by a newline in the given color (for
 *  console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  buffer      Pointer to data to be printed as a hex string.
 *  @param  length      Number of bytes to print.
 */
#define C_TLOGLN_WIDE_HEX(color, buffer, length) \
    _CLOG_C_TLOGLN_WIDE_HEX(color, buffer, length)

/**
 *  void C_TLOG_PERROR(const char* color, const char* str);
 *
 *  Log timestamp, tracing information, and the given string to standard error
 *  and/or a file and then print the C error message in the given color (for
 *  console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  str         String to print.
 */
#define C_TLOG_PERROR(color, str) \
    _CLOG_C_TLOG_PERROR(color, str)

/**
 *  void C_TLOG_PERRORF(const char* color, const char* format, ...);
 *
 *  Log timestamp, tracing information, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message in
 *  the given color (for console logs).
 *
 *  @param  color       ANZI terminal code to prefix string with.
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define C_TLOG_PERRORF(color, ...) \
    _CLOG_C_TLOG_PERRORF(color, __VA_ARGS__)


/**
 *  "log_level" Functions
 *  ---------------------
 *
 *  Additionally, there are "log_level" functions which add a symbol header
 *  to each line based on the level selected and print in the log level color
 *  in addition to the timestamp for log functions. These functions print to
 *  standard error and/or a file. Trace and debug level logs also print tracing
 *  information.
 *
 *  There are several of these function-like macros available:
 *
 *      LOG_TRACE(const char* str)
 *      LOGLN_TRACE(const char* str)
 *      LOGF_TRACE(const char* format, ...)
 *      LOGFLN_TRACE(const char* format, ...)
 *
 *      LOG_DEBUG(const char* str)
 *      LOGLN_DEBUG(const char* str)
 *      LOGF_DEBUG(const char* format, ...)
 *      LOGFLN_DEBUG(const char* format, ...)
 *
 *      LOG_EXTRA(const char* str)
 *      LOGLN_EXTRA(const char* str)
 *      LOGF_EXTRA(const char* format, ...)
 *      LOGFLN_EXTRA(const char* format, ...)
 *
 *      LOG_INFO(const char* str)
 *      LOGLN_INFO(const char* str)
 *      LOGF_INFO(const char* format, ...)
 *      LOGFLN_INFO(const char* format, ...)
 *
 *      LOG_HEADER(const char* str)
 *      LOGLN_HEADER(const char* str)
 *      LOGF_HEADER(const char* format, ...)
 *      LOGFLN_HEADER(const char* format, ...)
 *
 *      LOG_SUCCESS(const char* str)
 *      LOGLN_SUCCESS(const char* str)
 *      LOGF_SUCCESS(const char* format, ...)
 *      LOGFLN_SUCCESS(const char* format, ...)
 *
 *      LOG_MONEY(const char* str)
 *      LOGLN_MONEY(const char* str)
 *      LOGF_MONEY(const char* format, ...)
 *      LOGFLN_MONEY(const char* format, ...)
 *
 *      LOG_INPUT(const char* str)
 *      LOGLN_INPUT(const char* str)
 *      LOGF_INPUT(const char* format, ...)
 *      LOGFLN_INPUT(const char* format, ...)
 *
 *      LOG_WARNING(const char* str)
 *      LOGLN_WARNING(const char* str)
 *      LOGF_WARNING(const char* format, ...)
 *      LOGFLN_WARNING(const char* format, ...)
 *      LOG_PERROR_WARNING(const char* str)
 *      LOG_PERRORF_WARNING(const char* format, ...)
 *
 *      LOG_ERROR(const char* str)
 *      LOGLN_ERROR(const char* str)
 *      LOGF_ERROR(const char* format, ...)
 *      LOGFLN_ERROR(const char* format, ...)
 *      LOG_PERROR_ERROR(const char* str)
 *      LOG_PERRORF_ERROR(const char* format, ...)
 *
 *      LOG_CRITICAL(const char* str)
 *      LOGLN_CRITICAL(const char* str)
 *      LOGF_CRITICAL(const char* format, ...)
 *      LOGFLN_CRITICAL(const char* format, ...)
 *      LOG_PERROR_CRITICAL(const char* str)
 *      LOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *      LOG_FATAL(const char* str)
 *      LOGLN_FATAL(const char* str)
 *      LOGF_FATAL(const char* format, ...)
 *      LOGFLN_FATAL(const char* format, ...)
 *      LOG_PERROR_CRITICAL(const char* str)
 *      LOG_PERRORF_CRITICAL(const char* format, ...)
 *
 *  Descriptions of each function can be found at each function definition.
 */

/**
 *  void LOG_TRACE(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to standard error and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_TRACE(str) \
    _CLOG_C_TLOG(C_TRACE, _CSYM_TRACE str)

/**
 *  void LOGLN_TRACE(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_TRACE(str) \
    _CLOG_C_TLOGLN(C_TRACE, _CSYM_TRACE str)

/**
 *  void LOGF_TRACE(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error and/or a file in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_TRACE(...) \
    _CLOG_C_TLOGF(C_TRACE, _CSYM_TRACE __VA_ARGS__)

/**
 *  void LOGFLN_TRACE(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error and/or a file followed
 *  by a newline in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_TRACE(...) \
    _CLOG_C_TLOGFLN(C_TRACE, _CSYM_TRACE __VA_ARGS__)


/**
 *  void LOG_DEBUG(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to standard error and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_DEBUG(str) \
    _CLOG_C_TLOG(C_DEBUG, _CSYM_DEBUG str)

/**
 *  void LOGLN_DEBUG(const char* str);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  string to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_DEBUG(str) \
    _CLOG_C_TLOGLN(C_DEBUG, _CSYM_DEBUG str)

/**
 *  void LOGF_DEBUG(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error and/or a file in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_DEBUG(...) \
    _CLOG_C_TLOGF(C_DEBUG, _CSYM_DEBUG __VA_ARGS__)

/**
 *  void LOGFLN_DEBUG(const char* format, ...);
 *
 *  Log timestamp, tracing information, log level symbol, and the given
 *  format string and format arguments to standard error and/or a file followed
 *  by a newline in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_DEBUG(...) \
    _CLOG_C_TLOGFLN(C_DEBUG, _CSYM_DEBUG __VA_ARGS__)


/**
 *  void LOG_EXTRA(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_EXTRA(str) \
    _CLOG_C_LOG(C_EXTRA, _CSYM_EXTRA str)

/**
 *  void LOGLN_EXTRA(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_EXTRA(str) \
    _CLOG_C_LOGLN(C_EXTRA, _CSYM_EXTRA str)

/**
 *  void LOGF_EXTRA(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_EXTRA(...) \
    _CLOG_C_LOGF(C_EXTRA, _CSYM_EXTRA __VA_ARGS__)

/**
 *  void LOGFLN_EXTRA(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_EXTRA(...) \
    _CLOG_C_LOGFLN(C_EXTRA, _CSYM_EXTRA __VA_ARGS__)


/**
 *  void LOG_INFO(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_INFO(str) \
    _CLOG_C_LOG(C_INFO, _CSYM_INFO str)

/**
 *  void LOGLN_INFO(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_INFO(str) \
    _CLOG_C_LOGLN(C_INFO, _CSYM_INFO str)

/**
 *  void LOGF_INFO(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_INFO(...) \
    _CLOG_C_LOGF(C_INFO, _CSYM_INFO __VA_ARGS__)

/**
 *  void LOGFLN_INFO(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_INFO(...) \
    _CLOG_C_LOGFLN(C_INFO, _CSYM_INFO __VA_ARGS__)


/**
 *  void LOG_HEADER(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_HEADER(str) \
    _CLOG_C_LOG(C_HEADER, _CSYM_HEADER str)

/**
 *  void LOGLN_HEADER(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_HEADER(str) \
    _CLOG_C_LOGLN(C_HEADER, _CSYM_HEADER str)

/**
 *  void LOGF_HEADER(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_HEADER(...) \
    _CLOG_C_LOGF(C_HEADER, _CSYM_HEADER __VA_ARGS__)

/**
 *  void LOGFLN_HEADER(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_HEADER(...) \
    _CLOG_C_LOGFLN(C_HEADER, _CSYM_HEADER __VA_ARGS__)


/**
 *  void LOG_SUCCESS(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_SUCCESS(str) \
    _CLOG_C_LOG(C_SUCCESS, _CSYM_SUCCESS str)

/**
 *  void LOGLN_SUCCESS(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_SUCCESS(str) \
    _CLOG_C_LOGLN(C_SUCCESS, _CSYM_SUCCESS str)

/**
 *  void LOGF_SUCCESS(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_SUCCESS(...) \
    _CLOG_C_LOGF(C_SUCCESS, _CSYM_SUCCESS __VA_ARGS__)

/**
 *  void LOGFLN_SUCCESS(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_SUCCESS(...) \
    _CLOG_C_LOGFLN(C_SUCCESS, _CSYM_SUCCESS __VA_ARGS__)


/**
 *  void LOG_MONEY(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_MONEY(str) \
    _CLOG_C_LOG(C_MONEY, _CSYM_MONEY str)

/**
 *  void LOGLN_MONEY(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_MONEY(str) \
    _CLOG_C_LOGLN(C_MONEY, _CSYM_MONEY str)

/**
 *  void LOGF_MONEY(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_MONEY(...) \
    _CLOG_C_LOGF(C_MONEY, _CSYM_MONEY __VA_ARGS__)

/**
 *  void LOGFLN_MONEY(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_MONEY(...) \
    _CLOG_C_LOGFLN(C_MONEY, _CSYM_MONEY __VA_ARGS__)


/**
 *  void LOG_INPUT(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_INPUT(str) \
    _CLOG_C_LOG(C_INPUT, _CSYM_INPUT str)

/**
 *  void LOGLN_INPUT(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_INPUT(str) \
    _CLOG_C_LOGLN(C_INPUT, _CSYM_INPUT str)

/**
 *  void LOGF_INPUT(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_INPUT(...) \
    _CLOG_C_LOGF(C_INPUT, _CSYM_INPUT __VA_ARGS__)

/**
 *  void LOGFLN_INPUT(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_INPUT(...) \
    _CLOG_C_LOGFLN(C_INPUT, _CSYM_INPUT __VA_ARGS__)


/**
 *  void LOG_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_WARNING(str) \
    _CLOG_C_LOG(C_WARNING, _CSYM_WARNING str)

/**
 *  void LOGLN_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_WARNING(str) \
    _CLOG_C_LOGLN(C_WARNING, _CSYM_WARNING str)

/**
 *  void LOGF_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_WARNING(...) \
    _CLOG_C_LOGF(C_WARNING, _CSYM_WARNING __VA_ARGS__)

/**
 *  void LOGFLN_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_WARNING(...) \
    _CLOG_C_LOGFLN(C_WARNING, _CSYM_WARNING __VA_ARGS__)

/**
 *  void LOG_PERROR_WARNING(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file and then print the C error message in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR_WARNING(str)  \
    _CLOG_C_LOG_PERROR(C_WARNING, _CSYM_WARNING str)

/**
 *  void LOG_PERRORF_WARNING(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message in
 *  the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF_WARNING(...) \
    _CLOG_C_LOG_PERRORF(C_WARNING, _CSYM_WARNING __VA_ARGS__)


/**
 *  void LOG_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_ERROR(str) \
    _CLOG_C_TLOG(C_ERROR, _CSYM_ERROR str)

/**
 *  void LOGLN_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_ERROR(str) \
    _CLOG_C_TLOGLN(C_ERROR, _CSYM_ERROR str)

/**
 *  void LOGF_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_ERROR(...) \
    _CLOG_C_TLOGF(C_ERROR, _CSYM_ERROR __VA_ARGS__)

/**
 *  void LOGFLN_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_ERROR(...) \
    _CLOG_C_TLOGFLN(C_ERROR, _CSYM_ERROR __VA_ARGS__)

/**
 *  void LOG_PERROR_ERROR(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file and then print the C error message in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR_ERROR(str)  \
    _CLOG_C_TLOG_PERROR(C_ERROR, _CSYM_ERROR str)

/**
 *  void LOG_PERRORF_ERROR(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message in
 *  the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF_ERROR(...) \
    _CLOG_C_TLOG_PERRORF(C_ERROR, _CSYM_ERROR __VA_ARGS__)


/**
 *  void LOG_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_CRITICAL(str) \
    _CLOG_C_TLOG(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void LOGLN_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_CRITICAL(str) \
    _CLOG_C_TLOGLN(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void LOGF_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_CRITICAL(...) \
    _CLOG_C_TLOGF(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)

/**
 *  void LOGFLN_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_CRITICAL(...) \
    _CLOG_C_TLOGFLN(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)

/**
 *  void LOG_PERROR_CRITICAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file and then print the C error message in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR_CRITICAL(str)  \
    _CLOG_C_TLOG_PERROR(C_CRITICAL, _CSYM_CRITICAL str)

/**
 *  void LOG_PERRORF_CRITICAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message in
 *  the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF_CRITICAL(...) \
    _CLOG_C_TLOG_PERRORF(C_CRITICAL, _CSYM_CRITICAL __VA_ARGS__)


/**
 *  void LOG_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOG_FATAL(str) \
    _CLOG_C_TLOG(C_FATAL, _CSYM_FATAL str)

/**
 *  void LOGLN_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file followed by a newline in the appropriate log color.
 *
 *  @param  str         String to print.
 */
#define LOGLN_FATAL(str) \
    _CLOG_C_TLOGLN(C_FATAL, _CSYM_FATAL str)

/**
 *  void LOGF_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file in the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGF_FATAL(...) \
    _CLOG_C_TLOGF(C_FATAL, _CSYM_FATAL __VA_ARGS__)

/**
 *  void LOGFLN_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a newline in the
 *  appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOGFLN_FATAL(...) \
    _CLOG_C_TLOGFLN(C_FATAL, _CSYM_FATAL __VA_ARGS__)

/**
 *  void LOG_PERROR_FATAL(const char* str);
 *
 *  Log timestamp, log level symbol, and the given string to standard error
 *  and/or a file and then print the C error message in the appropriate log
 *  color.
 *
 *  @param  str         String to print.
 */
#define LOG_PERROR_FATAL(str)  \
    _CLOG_C_TLOG_PERROR(C_FATAL, _CSYM_FATAL str)

/**
 *  void LOG_PERRORF_FATAL(const char* format, ...);
 *
 *  Log timestamp, log level symbol, and the given format string and format
 *  arguments to standard error and/or a file followed by a C error message in
 *  the appropriate log color.
 *
 *  @param  format      Format specifier.
 *  @param  ...         Format specifier arguments.
 */
#define LOG_PERRORF_FATAL(...) \
    _CLOG_C_TLOG_PERRORF(C_FATAL, _CSYM_FATAL __VA_ARGS__)


/**
 *  "log_level" Short Aliases
 *  --------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Short aliases only have three or four character log level names.
 */

#ifdef CLOG_ENABLE_SHORT_ALIASES

    /**
     *  void LOG_TRC(const char* str);
     *
     *  Alias of `LOG_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_TRC(str) LOG_TRACE(str)

    /**
     *  void LOGLN_TRC(const char* str);
     *
     *  Alias of `LOGLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_TRC(str) LOGLN_TRACE(str)

    /**
     *  void LOGF_TRC(const char* format, ...);
     *
     *  Alias of `LOGF_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_TRC(...) LOGF_TRACE(__VA_ARGS__)

    /**
     *  void LOGFLN_TRC(const char* format, ...);
     *
     *  Alias of `LOGFLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_TRC(...) LOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void LOG_DBG(const char* str);
     *
     *  Alias of `LOG_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_DBG(str) LOG_DEBUG(str)

    /**
     *  void LOGLN_DBG(const char* str);
     *
     *  Alias of `LOGLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_DBG(str) LOGLN_DEBUG(str)

    /**
     *  void LOGF_DBG(const char* format, ...);
     *
     *  Alias of `LOGF_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_DBG(...) LOGF_DEBUG(__VA_ARGS__)

    /**
     *  void LOGFLN_DBG(const char* format, ...);
     *
     *  Alias of `LOGFLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_DBG(...) LOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void LOG_EXT(const char* str);
     *
     *  Alias of `LOG_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_EXT(str) LOG_EXTRA(str)

    /**
     *  void LOGLN_EXT(const char* str);
     *
     *  Alias of `LOGLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_EXT(str) LOGLN_EXTRA(str)

    /**
     *  void LOGF_EXT(const char* format, ...);
     *
     *  Alias of `LOGF_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_EXT(...) LOGF_EXTRA(__VA_ARGS__)

    /**
     *  void LOGFLN_EXT(const char* format, ...);
     *
     *  Alias of `LOGFLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_EXT(...) LOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void LOG_INF(const char* str);
     *
     *  Alias of `LOG_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_INF(str) LOG_INFO(str)

    /**
     *  void LOGLN_INF(const char* str);
     *
     *  Alias of `LOGLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_INF(str) LOGLN_INFO(str)

    /**
     *  void LOGF_INF(const char* format, ...);
     *
     *  Alias of `LOGF_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_INF(...) LOGF_INFO(__VA_ARGS__)

    /**
     *  void LOGFLN_INF(const char* format, ...);
     *
     *  Alias of `LOGFLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_INF(...) LOGFLN_INFO(__VA_ARGS__)


    /**
     *  void LOG_HEAD(const char* str);
     *
     *  Alias of `LOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_HEAD(str) LOG_HEADER(str)

    /**
     *  void LOGLN_HEAD(const char* str);
     *
     *  Alias of `LOG_TRACE` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_HEAD(str) LOGLN_HEADER(str)

    /**
     *  void LOGF_HEAD(const char* format, ...);
     *
     *  Alias of `LOGF_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_HEAD(...) LOGF_HEADER(__VA_ARGS__)

    /**
     *  void LOGFLN_HEAD(const char* format, ...);
     *
     *  Alias of `LOGFLN_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_HEAD(...) LOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void LOG_SUC(const char* str);
     *
     *  Alias of `LOG_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_SUC(str) LOG_SUCCESS(str)

    /**
     *  void LOGLN_SUC(const char* str);
     *
     *  Alias of `LOGLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_SUC(str) LOGLN_SUCCESS(str)

    /**
     *  void LOGF_SUC(const char* format, ...);
     *
     *  Alias of `LOGF_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_SUC(...) LOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void LOGFLN_SUC(const char* format, ...);
     *
     *  Alias of `LOGFLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_SUC(...) LOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void LOG_MON(const char* str);
     *
     *  Alias of `LOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_MON(str) LOG_MONEY(str)

    /**
     *  void LOGLN_MON(const char* str);
     *
     *  Alias of `LOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_MON(str) LOGLN_MONEY(str)

    /**
     *  void LOGF_MON(const char* format, ...);
     *
     *  Alias of `LOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_MON(...) LOGF_MONEY(__VA_ARGS__)

    /**
     *  void LOGFLN_MON(const char* format, ...);
     *
     *  Alias of `LOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_MON(...) LOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void LOG_MNY(const char* str);
     *
     *  Alias of `LOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_MNY(str) LOG_MONEY(str)

    /**
     *  void LOGLN_MNY(const char* str);
     *
     *  Alias of `LOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_MNY(str) LOGLN_MONEY(str)

    /**
     *  void LOGF_MNY(const char* format, ...);
     *
     *  Alias of `LOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_MNY(...) LOGF_MONEY(__VA_ARGS__)

    /**
     *  void LOGFLN_MNY(const char* format, ...);
     *
     *  Alias of `LOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_MNY(...) LOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void LOG_IN(const char* str);
     *
     *  Alias of `LOG_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_IN(str) LOG_INPUT(str)

    /**
     *  void LOGLN_IN(const char* str);
     *
     *  Alias of `LOGLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_IN(str) LOGLN_INPUT(str)

    /**
     *  void LOGF_IN(const char* format, ...);
     *
     *  Alias of `LOGF_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_IN(...) LOGF_INPUT(__VA_ARGS__)

    /**
     *  void LOGFLN_IN(const char* format, ...);
     *
     *  Alias of `LOGFLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_IN(...) LOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void LOG_WARN(const char* str);
     *
     *  Alias of `LOG_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_WARN(str) LOG_WARNING(str)

    /**
     *  void LOGLN_WARN(const char* str);
     *
     *  Alias of `LOGLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_WARN(str) LOGLN_WARNING(str)

    /**
     *  void LOGF_WARN(const char* format, ...);
     *
     *  Alias of `LOGF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_WARN(...) LOGF_WARNING(__VA_ARGS__)

    /**
     *  void LOGFLN_WARN(const char* format, ...);
     *
     *  Alias of `LOGFLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_WARN(...) LOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void LOG_PERROR_WARN(const char* str);
     *
     *  Alias of `LOG_PERROR_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_WARN(str) LOG_PERROR_WARNING(str)

    /**
     *  void LOG_PERRORF_WARN(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_WARN(...) LOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void LOG_ERR(const char* str);
     *
     *  Alias of `LOG_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_ERR(str) LOG_ERROR(str)

    /**
     *  void LOGLN_ERR(const char* str);
     *
     *  Alias of `LOGLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_ERR(str) LOGLN_ERROR(str)

    /**
     *  void LOGF_ERR(const char* format, ...);
     *
     *  Alias of `LOGF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_ERR(...) LOGF_ERROR(__VA_ARGS__)

    /**
     *  void LOGFLN_ERR(const char* format, ...);
     *
     *  Alias of `LOGFLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_ERR(...) LOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void LOG_PERROR_ERR(const char* str);
     *
     *  Alias of `LOG_PERROR_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_ERR(str) LOG_PERROR_ERROR(str)

    /**
     *  void LOG_PERRORF_ERR(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_ERR(...) LOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void LOG_CRIT(const char* str);
     *
     *  Alias of `LOG_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_CRIT(str) LOG_CRITICAL(str)

    /**
     *  void LOGLN_CRIT(const char* str);
     *
     *  Alias of `LOGLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_CRIT(str) LOGLN_CRITICAL(str)

    /**
     *  void LOGF_CRIT(const char* format, ...);
     *
     *  Alias of `LOGF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_CRIT(...) LOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void LOGFLN_CRIT(const char* format, ...);
     *
     *  Alias of `LOGFLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_CRIT(...) LOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void LOG_PERROR_CRIT(const char* str);
     *
     *  Alias of `LOG_PERROR_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_CRIT(str) LOG_PERROR_CRITICAL(str)

    /**
     *  void LOG_PERRORF_CRIT(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_CRIT(...) LOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void LOG_FAT(const char* str);
     *
     *  Alias of `LOG_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_FAT(str) LOG_FATAL(str)

    /**
     *  void LOGLN_FAT(const char* str);
     *
     *  Alias of `LOGLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_FAT(str) LOGLN_FATAL(str)

    /**
     *  void LOGF_FAT(const char* format, ...);
     *
     *  Alias of `LOGF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_FAT(...) LOGF_FATAL(__VA_ARGS__)

    /**
     *  void LOGFLN_FAT(const char* format, ...);
     *
     *  Alias of `LOGFLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format
     *  string and format arguments to standard error and/or a file followed by
     *  a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_FAT(...) LOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void LOG_PERROR_FAT(const char* str);
     *
     *  Alias of `LOG_PERROR_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_FAT(str) LOG_PERROR_FATAL(str)

    /**
     *  void LOG_PERRORF_FAT(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_FAT(...) LOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "log_level" Shorter Aliases
 *  ----------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  Shorter aliases only have two character log level names.
 */

#ifdef CLOG_ENABLE_SHORTER_ALIASES

    /**
     *  void LOG_TR(const char* str);
     *
     *  Alias of `LOG_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_TR(str) LOG_TRACE(str)

    /**
     *  void LOGLN_TR(const char* str);
     *
     *  Alias of `LOGLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_TR(str) LOGLN_TRACE(str)

    /**
     *  void LOGF_TR(const char* format, ...);
     *
     *  Alias of `LOGF_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_TR(...) LOGF_TRACE(__VA_ARGS__)

    /**
     *  void LOGFLN_TR(const char* format, ...);
     *
     *  Alias of `LOGFLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_TR(...) LOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void LOG_DB(const char* str);
     *
     *  Alias of `LOG_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_DB(str) LOG_DEBUG(str)

    /**
     *  void LOGLN_DB(const char* str);
     *
     *  Alias of `LOGLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_DB(str) LOGLN_DEBUG(str)

    /**
     *  void LOGF_DB(const char* format, ...);
     *
     *  Alias of `LOGF_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_DB(...) LOGF_DEBUG(__VA_ARGS__)

    /**
     *  void LOGFLN_DB(const char* format, ...);
     *
     *  Alias of `LOGFLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_DB(...) LOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void LOG_EX(const char* str);
     *
     *  Alias of `LOG_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_EX(str) LOG_EXTRA(str)

    /**
     *  void LOGLN_EX(const char* str);
     *
     *  Alias of `LOGLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_EX(str) LOGLN_EXTRA(str)

    /**
     *  void LOGF_EX(const char* format, ...);
     *
     *  Alias of `LOGF_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_EX(...) LOGF_EXTRA(__VA_ARGS__)

    /**
     *  void LOGFLN_EX(const char* format, ...);
     *
     *  Alias of `LOGFLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_EX(...) LOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void LOG_IF(const char* str);
     *
     *  Alias of `LOG_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_IF(str) LOG_INFO(str)

    /**
     *  void LOGLN_IF(const char* str);
     *
     *  Alias of `LOGLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_IF(str) LOGLN_INFO(str)

    /**
     *  void LOGF_IF(const char* format, ...);
     *
     *  Alias of `LOGF_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_IF(...) LOGF_INFO(__VA_ARGS__)

    /**
     *  void LOGFLN_IF(const char* format, ...);
     *
     *  Alias of `LOGFLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_IF(...) LOGFLN_INFO(__VA_ARGS__)


    /**
     *  void LOG_HD(const char* str);
     *
     *  Alias of `LOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_HD(str) LOG_HEADER(str)

    /**
     *  void LOGLN_HD(const char* str);
     *
     *  Alias of `LOG_TRACE` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_HD(str) LOGLN_HEADER(str)

    /**
     *  void LOGF_HD(const char* format, ...);
     *
     *  Alias of `LOGF_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_HD(...) LOGF_HEADER(__VA_ARGS__)

    /**
     *  void LOGFLN_HD(const char* format, ...);
     *
     *  Alias of `LOGFLN_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_HD(...) LOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void LOG_SC(const char* str);
     *
     *  Alias of `LOG_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_SC(str) LOG_SUCCESS(str)

    /**
     *  void LOGLN_SC(const char* str);
     *
     *  Alias of `LOGLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_SC(str) LOGLN_SUCCESS(str)

    /**
     *  void LOGF_SC(const char* format, ...);
     *
     *  Alias of `LOGF_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_SC(...) LOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void LOGFLN_SC(const char* format, ...);
     *
     *  Alias of `LOGFLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_SC(...) LOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void LOG_MN(const char* str);
     *
     *  Alias of `LOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_MN(str) LOG_MONEY(str)

    /**
     *  void LOGLN_MN(const char* str);
     *
     *  Alias of `LOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_MN(str) LOGLN_MONEY(str)

    /**
     *  void LOGF_MN(const char* format, ...);
     *
     *  Alias of `LOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_MN(...) LOGF_MONEY(__VA_ARGS__)

    /**
     *  void LOGFLN_MN(const char* format, ...);
     *
     *  Alias of `LOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_MN(...) LOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void LOG_MY(const char* str);
     *
     *  Alias of `LOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_MY(str) LOG_MONEY(str)

    /**
     *  void LOGLN_MY(const char* str);
     *
     *  Alias of `LOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_MY(str) LOGLN_MONEY(str)

    /**
     *  void LOGF_MY(const char* format, ...);
     *
     *  Alias of `LOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_MY(...) LOGF_MONEY(__VA_ARGS__)

    /**
     *  void LOGFLN_MY(const char* format, ...);
     *
     *  Alias of `LOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_MY(...) LOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void LOG_IN(const char* str);
     *
     *  Alias of `LOG_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_IN(str) LOG_INPUT(str)

    /**
     *  void LOGLN_IN(const char* str);
     *
     *  Alias of `LOGLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_IN(str) LOGLN_INPUT(str)

    /**
     *  void LOGF_IN(const char* format, ...);
     *
     *  Alias of `LOGF_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_IN(...) LOGF_INPUT(__VA_ARGS__)

    /**
     *  void LOGFLN_IN(const char* format, ...);
     *
     *  Alias of `LOGFLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_IN(...) LOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void LOG_WN(const char* str);
     *
     *  Alias of `LOG_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_WN(str) LOG_WARNING(str)

    /**
     *  void LOGLN_WN(const char* str);
     *
     *  Alias of `LOGLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_WN(str) LOGLN_WARNING(str)

    /**
     *  void LOGF_WN(const char* format, ...);
     *
     *  Alias of `LOGF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_WN(...) LOGF_WARNING(__VA_ARGS__)

    /**
     *  void LOGFLN_WN(const char* format, ...);
     *
     *  Alias of `LOGFLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_WN(...) LOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void LOG_PERROR_WN(const char* str);
     *
     *  Alias of `LOG_PERROR_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_WN(str) LOG_PERROR_WARNING(str)

    /**
     *  void LOG_PERRORF_WN(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_WN(...) LOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void LOG_ER(const char* str);
     *
     *  Alias of `LOG_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_ER(str) LOG_ERROR(str)

    /**
     *  void LOGLN_ER(const char* str);
     *
     *  Alias of `LOGLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_ER(str) LOGLN_ERROR(str)

    /**
     *  void LOGF_ER(const char* format, ...);
     *
     *  Alias of `LOGF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_ER(...) LOGF_ERROR(__VA_ARGS__)

    /**
     *  void LOGFLN_ER(const char* format, ...);
     *
     *  Alias of `LOGFLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_ER(...) LOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void LOG_PERROR_ER(const char* str);
     *
     *  Alias of `LOG_PERROR_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_ER(str) LOG_PERROR_ERROR(str)

    /**
     *  void LOG_PERRORF_ER(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_ER(...) LOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void LOG_CR(const char* str);
     *
     *  Alias of `LOG_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_CR(str) LOG_CRITICAL(str)

    /**
     *  void LOGLN_CR(const char* str);
     *
     *  Alias of `LOGLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_CR(str) LOGLN_CRITICAL(str)

    /**
     *  void LOGF_CR(const char* format, ...);
     *
     *  Alias of `LOGF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_CR(...) LOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void LOGFLN_CR(const char* format, ...);
     *
     *  Alias of `LOGFLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_CR(...) LOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void LOG_PERROR_CR(const char* str);
     *
     *  Alias of `LOG_PERROR_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_CR(str) LOG_PERROR_CRITICAL(str)

    /**
     *  void LOG_PERRORF_CR(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_CR(...) LOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void LOG_FT(const char* str);
     *
     *  Alias of `LOG_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_FT(str) LOG_FATAL(str)

    /**
     *  void LOGLN_FT(const char* str);
     *
     *  Alias of `LOGLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOGLN_FT(str) LOGLN_FATAL(str)

    /**
     *  void LOGF_FT(const char* format, ...);
     *
     *  Alias of `LOGF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGF_FT(...) LOGF_FATAL(__VA_ARGS__)

    /**
     *  void LOGFLN_FT(const char* format, ...);
     *
     *  Alias of `LOGFLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format
     *  string and format arguments to standard error and/or a file followed by
     *  a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOGFLN_FT(...) LOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void LOG_PERROR_FT(const char* str);
     *
     *  Alias of `LOG_PERROR_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define LOG_PERROR_FT(str) LOG_PERROR_FATAL(str)

    /**
     *  void LOG_PERRORF_FT(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define LOG_PERRORF_FT(...) LOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/**
 *  "log_level" Name Aliases
 *  ----------------------------
 *
 *  These are short aliases for shorter macros if desired. They are turned off
 *  by default and can be enabled by using an configuration header.
 *
 *  These aliases use just the log level names to call functions.
 */

#ifdef CLOG_ENABLE_NAME_ALIASES

    /**
     *  void TRACE(const char* str);
     *
     *  Alias of `LOG_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define TRACE(str) LOG_TRACE(str)

    /**
     *  void TRACELN(const char* str);
     *
     *  Alias of `LOGLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define TRACELN(str) LOGLN_TRACE(str)

    /**
     *  void TRACEF(const char* format, ...);
     *
     *  Alias of `LOGF_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define TRACEF(...) LOGF_TRACE(__VA_ARGS__)

    /*
     *  void TRACEFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_TRACE` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define TRACEFLN(...) LOGFLN_TRACE(__VA_ARGS__)


    /**
     *  void DEBUG(const char* str);
     *
     *  Alias of `LOG_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define DEBUG(str) LOG_DEBUG(str)

    /**
     *  void DEBUGLN(const char* str);
     *
     *  Alias of `LOGLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  string to standard error and/or a file followed by a newline in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define DEBUGLN(str) LOGLN_DEBUG(str)

    /**
     *  void DEBUGF(const char* format, ...);
     *
     *  Alias of `LOGF_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file in
     *  the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define DEBUGF(...) LOGF_DEBUG(__VA_ARGS__)

    /**
     *  void DEBUGFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_DEBUG` function.
     *
     *  Log timestamp, tracing information, log level symbol, and the given
     *  format string and format arguments to standard error and/or a file
     *  followed by a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define DEBUGFLN(...) LOGFLN_DEBUG(__VA_ARGS__)


    /**
     *  void EXTRA(const char* str);
     *
     *  Alias of `LOG_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define EXTRA(str) LOG_EXTRA(str)

    /**
     *  void EXTRALN(const char* str);
     *
     *  Alias of `LOGLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define EXTRALN(str) LOGLN_EXTRA(str)

    /**
     *  void EXTRAF(const char* format, ...);
     *
     *  Alias of `LOGF_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define EXTRAF(...) LOGF_EXTRA(__VA_ARGS__)

    /**
     *  void EXTRAFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_EXTRA` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define EXTRAFLN(...) LOGFLN_EXTRA(__VA_ARGS__)


    /**
     *  void INFO(const char* str);
     *
     *  Alias of `LOG_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define INFO(str) LOG_INFO(str)

    /**
     *  void INFOLN(const char* str);
     *
     *  Alias of `LOGLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define INFOLN(str) LOGLN_INFO(str)

    /**
     *  void INFOF(const char* format, ...);
     *
     *  Alias of `LOGF_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define INFOF(...) LOGF_INFO(__VA_ARGS__)

    /**
     *  void INFOFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_INFO` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define INFOFLN(...) LOGFLN_INFO(__VA_ARGS__)


    /**
     *  void HEADER(const char* str);
     *
     *  Alias of `LOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define HEADER(str) LOG_HEADER(str)

    /**
     *  void HEADERLN(const char* str);
     *
     *  Alias of `LOG_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define HEADERLN(str) LOGLN_HEADER(str)

    /**
     *  void HEADERF(const char* format, ...);
     *
     *  Alias of `LOGF_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define HEADERF(...) LOGF_HEADER(__VA_ARGS__)

    /**
     *  void HEADERFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_HEADER` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define HEADERFLN(...) LOGFLN_HEADER(__VA_ARGS__)


    /**
     *  void SUCCESS(const char* str);
     *
     *  Alias of `LOG_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define SUCCESS(str) LOG_SUCCESS(str)

    /**
     *  void SUCCESSLN(const char* str);
     *
     *  Alias of `LOGLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define SUCCESSLN(str) LOGLN_SUCCESS(str)

    /**
     *  void SUCCESSF(const char* format, ...);
     *
     *  Alias of `LOGF_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define SUCCESSF(...) LOGF_SUCCESS(__VA_ARGS__)

    /**
     *  void SUCCESSFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_SUCCESS` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define SUCCESSFLN(...) LOGFLN_SUCCESS(__VA_ARGS__)


    /**
     *  void MONEY(const char* str);
     *
     *  Alias of `LOG_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define MONEY(str) LOG_MONEY(str)

    /**
     *  void MONEYLN(const char* str);
     *
     *  Alias of `LOGLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define MONEYLN(str) LOGLN_MONEY(str)

    /**
     *  void MONEYF(const char* format, ...);
     *
     *  Alias of `LOGF_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define MONEYF(...) LOGF_MONEY(__VA_ARGS__)

    /**
     *  void MONEYFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_MONEY` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define MONEYFLN(...) LOGFLN_MONEY(__VA_ARGS__)


    /**
     *  void INPUT(const char* str);
     *
     *  Alias of `LOG_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define INPUT(str) LOG_INPUT(str)

    /**
     *  void INPUTLN(const char* str);
     *
     *  Alias of `LOGLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define INPUTLN(str) LOGLN_INPUT(str)

    /**
     *  void INPUTF(const char* format, ...);
     *
     *  Alias of `LOGF_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define INPUTF(...) LOGF_INPUT(__VA_ARGS__)

    /**
     *  void INPUTFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_INPUT` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define INPUTFLN(...) LOGFLN_INPUT(__VA_ARGS__)


    /**
     *  void WARNING(const char* str);
     *
     *  Alias of `LOG_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define WARNING(str) LOG_WARNING(str)

    /**
     *  void WARNINGLN(const char* str);
     *
     *  Alias of `LOGLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define WARNINGLN(str) LOGLN_WARNING(str)

    /**
     *  void WARNINGF(const char* format, ...);
     *
     *  Alias of `LOGF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define WARNINGF(...) LOGF_WARNING(__VA_ARGS__)

    /**
     *  void WARNINGFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define WARNINGFLN(...) LOGFLN_WARNING(__VA_ARGS__)

    /**
     *  void WARNING_PERROR(const char* str);
     *
     *  Alias of `LOG_PERROR_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define WARNING_PERROR(str) LOG_PERROR_WARNING(str)

    /**
     *  void WARNING_PERRORF(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_WARNING` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define WARNING_PERRORF(...) LOG_PERRORF_WARNING(__VA_ARGS__)


    /**
     *  void ERROR(const char* str);
     *
     *  Alias of `LOG_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define ERROR(str) LOG_ERROR(str)

    /**
     *  void ERRORLN(const char* str);
     *
     *  Alias of `LOGLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define ERRORLN(str) LOGLN_ERROR(str)

    /**
     *  void ERRORF(const char* format, ...);
     *
     *  Alias of `LOGF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define ERRORF(...) LOGF_ERROR(__VA_ARGS__)

    /**
     *  void ERRORFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define ERRORFLN(...) LOGFLN_ERROR(__VA_ARGS__)

    /**
     *  void ERROR_PERROR(const char* str);
     *
     *  Alias of `LOG_PERROR_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define ERROR_PERROR(str) LOG_PERROR_ERROR(str)

    /**
     *  void ERROR_PERRORF(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_ERROR` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define ERROR_PERRORF(...) LOG_PERRORF_ERROR(__VA_ARGS__)


    /**
     *  void CRITICAL(const char* str);
     *
     *  Alias of `LOG_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CRITICAL(str) LOG_CRITICAL(str)

    /**
     *  void CRITICALLN(const char* str);
     *
     *  Alias of `LOGLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CRITICALLN(str) LOGLN_CRITICAL(str)

    /**
     *  void CRITICALF(const char* format, ...);
     *
     *  Alias of `LOGF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CRITICALF(...) LOGF_CRITICAL(__VA_ARGS__)

    /**
     *  void CRITICALFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a newline
     *  in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CRITICALFLN(...) LOGFLN_CRITICAL(__VA_ARGS__)

    /**
     *  void CRITICAL_PERROR(const char* str);
     *
     *  Alias of `LOG_PERROR_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define CRITICAL_PERROR(str) LOG_PERROR_CRITICAL(str)

    /**
     *  void CRITICAL_PERRORF(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_CRITICAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define CRITICAL_PERRORF(...) LOG_PERRORF_CRITICAL(__VA_ARGS__)


    /**
     *  void FATAL(const char* str);
     *
     *  Alias of `LOG_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define FATAL(str) LOG_FATAL(str)

    /**
     *  void FATALLN(const char* str);
     *
     *  Alias of `LOGLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file followed by a newline in the appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define FATALLN(str) LOGLN_FATAL(str)

    /**
     *  void FATALF(const char* format, ...);
     *
     *  Alias of `LOGF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file in the appropriate log
     *  color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FATALF(...) LOGF_FATAL(__VA_ARGS__)

    /**
     *  void FATALFLN(const char* format, ...);
     *
     *  Alias of `LOGFLN_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format
     *  string and format arguments to standard error and/or a file followed by
     *  a newline in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FATALFLN(...) LOGFLN_FATAL(__VA_ARGS__)

    /**
     *  void FATAL_PERROR(const char* str);
     *
     *  Alias of `LOG_PERROR_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given string to standard
     *  error and/or a file and then print the C error message in the
     *  appropriate log color.
     *
     *  @param  str         String to print.
     */
    #define FATAL_PERROR(str) LOG_PERROR_FATAL(str)

    /**
     *  void FATAL_PERRORF(const char* format, ...);
     *
     *  Alias of `LOG_PERRORF_FATAL` function.
     *
     *  Log timestamp, log level symbol, and the given format string and
     *  format arguments to standard error and/or a file followed by a C error
     *  message in the appropriate log color.
     *
     *  @param  format      Format specifier.
     *  @param  ...         Format specifier arguments.
     */
    #define FATAL_PERRORF(...) LOG_PERRORF_FATAL(__VA_ARGS__)

#endif


/* Log Level Undefinitions */

#if CLOG_LEVEL == CLOG_LEVEL_NONE

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)

    #undef CLOG_EXTRA
    #define CLOG_EXTRA(...)
    #undef CLOGLN_EXTRA
    #define CLOGLN_EXTRA(...)
    #undef CLOGF_EXTRA
    #define CLOGF_EXTRA(...)
    #undef CLOGFLN_EXTRA
    #define CLOGFLN_EXTRA(...)

    #undef CLOG_INFO
    #define CLOG_INFO(...)
    #undef CLOGLN_INFO
    #define CLOGLN_INFO(...)
    #undef CLOGF_INFO
    #define CLOGF_INFO(...)
    #undef CLOGFLN_INFO
    #define CLOGFLN_INFO(...)

    #undef CLOG_HEADER
    #define CLOG_HEADER(...)
    #undef CLOGLN_HEADER
    #define CLOGLN_HEADER(...)
    #undef CLOGF_HEADER
    #define CLOGF_HEADER(...)
    #undef CLOGFLN_HEADER
    #define CLOGFLN_HEADER(...)

    #undef CLOG_SUCCESS
    #define CLOG_SUCCESS(...)
    #undef CLOGLN_SUCCESS
    #define CLOGLN_SUCCESS(...)
    #undef CLOGF_SUCCESS
    #define CLOGF_SUCCESS(...)
    #undef CLOGFLN_SUCCESS
    #define CLOGFLN_SUCCESS(...)

    #undef CLOG_MONEY
    #define CLOG_MONEY(...)
    #undef CLOGLN_MONEY
    #define CLOGLN_MONEY(...)
    #undef CLOGF_MONEY
    #define CLOGF_MONEY(...)
    #undef CLOGFLN_MONEY
    #define CLOGFLN_MONEY(...)

    #undef CLOG_INPUT
    #define CLOG_INPUT(...)
    #undef CLOGLN_INPUT
    #define CLOGLN_INPUT(...)
    #undef CLOGF_INPUT
    #define CLOGF_INPUT(...)
    #undef CLOGFLN_INPUT
    #define CLOGFLN_INPUT(...)

    #undef CLOG_WARNING
    #define CLOG_WARNING(...)
    #undef CLOGLN_WARNING
    #define CLOGLN_WARNING(...)
    #undef CLOGF_WARNING
    #define CLOGF_WARNING(...)
    #undef CLOGFLN_WARNING
    #define CLOGFLN_WARNING(...)
    #undef CLOG_PERROR_WARNING
    #define CLOG_PERROR_WARNING(...)
    #undef CLOG_PERRORF_WARNING
    #define CLOG_PERRORF_WARNING(...)

    #undef CLOG_ERROR
    #define CLOG_ERROR(...)
    #undef CLOGLN_ERROR
    #define CLOGLN_ERROR(...)
    #undef CLOGF_ERROR
    #define CLOGF_ERROR(...)
    #undef CLOGFLN_ERROR
    #define CLOGFLN_ERROR(...)
    #undef CLOG_PERROR_ERROR
    #define CLOG_PERROR_ERROR(...)
    #undef CLOG_PERRORF_ERROR
    #define CLOG_PERRORF_ERROR(...)

    #undef CLOG_CRITICAL
    #define CLOG_CRITICAL(...)
    #undef CLOGLN_CRITICAL
    #define CLOGLN_CRITICAL(...)
    #undef CLOGF_CRITICAL
    #define CLOGF_CRITICAL(...)
    #undef CLOGFLN_CRITICAL
    #define CLOGFLN_CRITICAL(...)
    #undef CLOG_PERROR_CRITICAL
    #define CLOG_PERROR_CRITICAL(...)
    #undef CLOG_PERRORF_CRITICAL
    #define CLOG_PERRORF_CRITICAL(...)

    #undef CLOG_FATAL
    #define CLOG_FATAL(...)
    #undef CLOGLN_FATAL
    #define CLOGLN_FATAL(...)
    #undef CLOGF_FATAL
    #define CLOGF_FATAL(...)
    #undef CLOGFLN_FATAL
    #define CLOGFLN_FATAL(...)
    #undef CLOG_PERROR_FATAL
    #define CLOG_PERROR_FATAL(...)
    #undef CLOG_PERRORF_FATAL
    #define CLOG_PERRORF_FATAL(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

        #undef CLOG_EXT
        #define CLOG_EXT(...)
        #undef CLOGLN_EXT
        #define CLOGLN_EXT(...)
        #undef CLOGF_EXT
        #define CLOGF_EXT(...)
        #undef CLOGFLN_EXT
        #define CLOGFLN_EXT(...)

        #undef CLOG_INF
        #define CLOG_INF(...)
        #undef CLOGLN_INF
        #define CLOGLN_INF(...)
        #undef CLOGF_INF
        #define CLOGF_INF(...)
        #undef CLOGFLN_INF
        #define CLOGFLN_INF(...)

        #undef CLOG_HEAD
        #define CLOG_HEAD(...)
        #undef CLOGLN_HEAD
        #define CLOGLN_HEAD(...)
        #undef CLOGF_HEAD
        #define CLOGF_HEAD(...)
        #undef CLOGFLN_HEAD
        #define CLOGFLN_HEAD(...)

        #undef CLOG_SUC
        #define CLOG_SUC(...)
        #undef CLOGLN_SUC
        #define CLOGLN_SUC(...)
        #undef CLOGF_SUC
        #define CLOGF_SUC(...)
        #undef CLOGFLN_SUC
        #define CLOGFLN_SUC(...)

        #undef CLOG_MON
        #define CLOG_MON(...)
        #undef CLOGLN_MON
        #define CLOGLN_MON(...)
        #undef CLOGF_MON
        #define CLOGF_MON(...)
        #undef CLOGFLN_MON
        #define CLOGFLN_MON(...)

        #undef CLOG_MNY
        #define CLOG_MNY(...)
        #undef CLOGLN_MNY
        #define CLOGLN_MNY(...)
        #undef CLOGF_MNY
        #define CLOGF_MNY(...)
        #undef CLOGFLN_MNY
        #define CLOGFLN_MNY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WARN
        #define CLOG_WARN(...)
        #undef CLOGLN_WARN
        #define CLOGLN_WARN(...)
        #undef CLOGF_WARN
        #define CLOGF_WARN(...)
        #undef CLOGFLN_WARN
        #define CLOGFLN_WARN(...)
        #undef CLOG_PERROR_WARN
        #define CLOG_PERROR_WARN(...)
        #undef CLOG_PERRORF_WARN
        #define CLOG_PERRORF_WARN(...)

        #undef CLOG_ERR
        #define CLOG_ERR(...)
        #undef CLOGLN_ERR
        #define CLOGLN_ERR(...)
        #undef CLOGF_ERR
        #define CLOGF_ERR(...)
        #undef CLOGFLN_ERR
        #define CLOGFLN_ERR(...)
        #undef CLOG_PERROR_ERR
        #define CLOG_PERROR_ERR(...)
        #undef CLOG_PERRORF_ERR
        #define CLOG_PERRORF_ERR(...)

        #undef CLOG_CRIT
        #define CLOG_CRIT(...)
        #undef CLOGLN_CRIT
        #define CLOGLN_CRIT(...)
        #undef CLOGF_CRIT
        #define CLOGF_CRIT(...)
        #undef CLOGFLN_CRIT
        #define CLOGFLN_CRIT(...)
        #undef CLOG_PERROR_CRIT
        #define CLOG_PERROR_CRIT(...)
        #undef CLOG_PERRORF_CRIT
        #define CLOG_PERRORF_CRIT(...)

        #undef CLOG_FAT
        #define CLOG_FAT(...)
        #undef CLOGLN_FAT
        #define CLOGLN_FAT(...)
        #undef CLOGF_FAT
        #define CLOGF_FAT(...)
        #undef CLOGFLN_FAT
        #define CLOGFLN_FAT(...)
        #undef CLOG_PERROR_FAT
        #define CLOG_PERROR_FAT(...)
        #undef CLOG_PERRORF_FAT
        #define CLOG_PERRORF_FAT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

        #undef CLOG_EX
        #define CLOG_EX(...)
        #undef CLOGLN_EX
        #define CLOGLN_EX(...)
        #undef CLOGF_EX
        #define CLOGF_EX(...)
        #undef CLOGFLN_EX
        #define CLOGFLN_EX(...)

        #undef CLOG_IF
        #define CLOG_IF(...)
        #undef CLOGLN_IF
        #define CLOGLN_IF(...)
        #undef CLOGF_IF
        #define CLOGF_IF(...)
        #undef CLOGFLN_IF
        #define CLOGFLN_IF(...)

        #undef CLOG_HD
        #define CLOG_HD(...)
        #undef CLOGLN_HD
        #define CLOGLN_HD(...)
        #undef CLOGF_HD
        #define CLOGF_HD(...)
        #undef CLOGFLN_HD
        #define CLOGFLN_HD(...)

        #undef CLOG_SC
        #define CLOG_SC(...)
        #undef CLOGLN_SC
        #define CLOGLN_SC(...)
        #undef CLOGF_SC
        #define CLOGF_SC(...)
        #undef CLOGFLN_SC
        #define CLOGFLN_SC(...)

        #undef CLOG_MN
        #define CLOG_MN(...)
        #undef CLOGLN_MN
        #define CLOGLN_MN(...)
        #undef CLOGF_MN
        #define CLOGF_MN(...)
        #undef CLOGFLN_MN
        #define CLOGFLN_MN(...)

        #undef CLOG_MY
        #define CLOG_MY(...)
        #undef CLOGLN_MY
        #define CLOGLN_MY(...)
        #undef CLOGF_MY
        #define CLOGF_MY(...)
        #undef CLOGFLN_MY
        #define CLOGFLN_MY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WN
        #define CLOG_WN(...)
        #undef CLOGLN_WN
        #define CLOGLN_WN(...)
        #undef CLOGF_WN
        #define CLOGF_WN(...)
        #undef CLOGFLN_WN
        #define CLOGFLN_WN(...)
        #undef CLOG_PERROR_WN
        #define CLOG_PERROR_WN(...)
        #undef CLOG_PERRORF_WN
        #define CLOG_PERRORF_WN(...)

        #undef CLOG_ER
        #define CLOG_ER(...)
        #undef CLOGLN_ER
        #define CLOGLN_ER(...)
        #undef CLOGF_ER
        #define CLOGF_ER(...)
        #undef CLOGFLN_ER
        #define CLOGFLN_ER(...)
        #undef CLOG_PERROR_ER
        #define CLOG_PERROR_ER(...)
        #undef CLOG_PERRORF_ER
        #define CLOG_PERRORF_ER(...)

        #undef CLOG_CR
        #define CLOG_CR(...)
        #undef CLOGLN_CR
        #define CLOGLN_CR(...)
        #undef CLOGF_CR
        #define CLOGF_CR(...)
        #undef CLOGFLN_CR
        #define CLOGFLN_CR(...)
        #undef CLOG_PERROR_CR
        #define CLOG_PERROR_CR(...)
        #undef CLOG_PERRORF_CR
        #define CLOG_PERRORF_CR(...)

        #undef CLOG_FT
        #define CLOG_FT(...)
        #undef CLOGLN_FT
        #define CLOGLN_FT(...)
        #undef CLOGF_FT
        #define CLOGF_FT(...)
        #undef CLOGFLN_FT
        #define CLOGFLN_FT(...)
        #undef CLOG_PERROR_FT
        #define CLOG_PERROR_FT(...)
        #undef CLOG_PERRORF_FT
        #define CLOG_PERRORF_FT(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)

    #undef FLOG_EXTRA
    #define FLOG_EXTRA(...)
    #undef FLOGLN_EXTRA
    #define FLOGLN_EXTRA(...)
    #undef FLOGF_EXTRA
    #define FLOGF_EXTRA(...)
    #undef FLOGFLN_EXTRA
    #define FLOGFLN_EXTRA(...)

    #undef FLOG_INFO
    #define FLOG_INFO(...)
    #undef FLOGLN_INFO
    #define FLOGLN_INFO(...)
    #undef FLOGF_INFO
    #define FLOGF_INFO(...)
    #undef FLOGFLN_INFO
    #define FLOGFLN_INFO(...)

    #undef FLOG_HEADER
    #define FLOG_HEADER(...)
    #undef FLOGLN_HEADER
    #define FLOGLN_HEADER(...)
    #undef FLOGF_HEADER
    #define FLOGF_HEADER(...)
    #undef FLOGFLN_HEADER
    #define FLOGFLN_HEADER(...)

    #undef FLOG_SUCCESS
    #define FLOG_SUCCESS(...)
    #undef FLOGLN_SUCCESS
    #define FLOGLN_SUCCESS(...)
    #undef FLOGF_SUCCESS
    #define FLOGF_SUCCESS(...)
    #undef FLOGFLN_SUCCESS
    #define FLOGFLN_SUCCESS(...)

    #undef FLOG_MONEY
    #define FLOG_MONEY(...)
    #undef FLOGLN_MONEY
    #define FLOGLN_MONEY(...)
    #undef FLOGF_MONEY
    #define FLOGF_MONEY(...)
    #undef FLOGFLN_MONEY
    #define FLOGFLN_MONEY(...)

    #undef FLOG_INPUT
    #define FLOG_INPUT(...)
    #undef FLOGLN_INPUT
    #define FLOGLN_INPUT(...)
    #undef FLOGF_INPUT
    #define FLOGF_INPUT(...)
    #undef FLOGFLN_INPUT
    #define FLOGFLN_INPUT(...)

    #undef FLOG_WARNING
    #define FLOG_WARNING(...)
    #undef FLOGLN_WARNING
    #define FLOGLN_WARNING(...)
    #undef FLOGF_WARNING
    #define FLOGF_WARNING(...)
    #undef FLOGFLN_WARNING
    #define FLOGFLN_WARNING(...)
    #undef FLOG_PERROR_WARNING
    #define FLOG_PERROR_WARNING(...)
    #undef FLOG_PERRORF_WARNING
    #define FLOG_PERRORF_WARNING(...)

    #undef FLOG_ERROR
    #define FLOG_ERROR(...)
    #undef FLOGLN_ERROR
    #define FLOGLN_ERROR(...)
    #undef FLOGF_ERROR
    #define FLOGF_ERROR(...)
    #undef FLOGFLN_ERROR
    #define FLOGFLN_ERROR(...)
    #undef FLOG_PERROR_ERROR
    #define FLOG_PERROR_ERROR(...)
    #undef FLOG_PERRORF_ERROR
    #define FLOG_PERRORF_ERROR(...)

    #undef FLOG_CRITICAL
    #define FLOG_CRITICAL(...)
    #undef FLOGLN_CRITICAL
    #define FLOGLN_CRITICAL(...)
    #undef FLOGF_CRITICAL
    #define FLOGF_CRITICAL(...)
    #undef FLOGFLN_CRITICAL
    #define FLOGFLN_CRITICAL(...)
    #undef FLOG_PERROR_CRITICAL
    #define FLOG_PERROR_CRITICAL(...)
    #undef FLOG_PERRORF_CRITICAL
    #define FLOG_PERRORF_CRITICAL(...)

    #undef FLOG_FATAL
    #define FLOG_FATAL(...)
    #undef FLOGLN_FATAL
    #define FLOGLN_FATAL(...)
    #undef FLOGF_FATAL
    #define FLOGF_FATAL(...)
    #undef FLOGFLN_FATAL
    #define FLOGFLN_FATAL(...)
    #undef FLOG_PERROR_FATAL
    #define FLOG_PERROR_FATAL(...)
    #undef FLOG_PERRORF_FATAL
    #define FLOG_PERRORF_FATAL(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

        #undef FLOG_EXT
        #define FLOG_EXT(...)
        #undef FLOGLN_EXT
        #define FLOGLN_EXT(...)
        #undef FLOGF_EXT
        #define FLOGF_EXT(...)
        #undef FLOGFLN_EXT
        #define FLOGFLN_EXT(...)

        #undef FLOG_INF
        #define FLOG_INF(...)
        #undef FLOGLN_INF
        #define FLOGLN_INF(...)
        #undef FLOGF_INF
        #define FLOGF_INF(...)
        #undef FLOGFLN_INF
        #define FLOGFLN_INF(...)

        #undef FLOG_HEAD
        #define FLOG_HEAD(...)
        #undef FLOGLN_HEAD
        #define FLOGLN_HEAD(...)
        #undef FLOGF_HEAD
        #define FLOGF_HEAD(...)
        #undef FLOGFLN_HEAD
        #define FLOGFLN_HEAD(...)

        #undef FLOG_SUC
        #define FLOG_SUC(...)
        #undef FLOGLN_SUC
        #define FLOGLN_SUC(...)
        #undef FLOGF_SUC
        #define FLOGF_SUC(...)
        #undef FLOGFLN_SUC
        #define FLOGFLN_SUC(...)

        #undef FLOG_MON
        #define FLOG_MON(...)
        #undef FLOGLN_MON
        #define FLOGLN_MON(...)
        #undef FLOGF_MON
        #define FLOGF_MON(...)
        #undef FLOGFLN_MON
        #define FLOGFLN_MON(...)

        #undef FLOG_MNY
        #define FLOG_MNY(...)
        #undef FLOGLN_MNY
        #define FLOGLN_MNY(...)
        #undef FLOGF_MNY
        #define FLOGF_MNY(...)
        #undef FLOGFLN_MNY
        #define FLOGFLN_MNY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WARN
        #define FLOG_WARN(...)
        #undef FLOGLN_WARN
        #define FLOGLN_WARN(...)
        #undef FLOGF_WARN
        #define FLOGF_WARN(...)
        #undef FLOGFLN_WARN
        #define FLOGFLN_WARN(...)
        #undef FLOG_PERROR_WARN
        #define FLOG_PERROR_WARN(...)
        #undef FLOG_PERRORF_WARN
        #define FLOG_PERRORF_WARN(...)

        #undef FLOG_ERR
        #define FLOG_ERR(...)
        #undef FLOGLN_ERR
        #define FLOGLN_ERR(...)
        #undef FLOGF_ERR
        #define FLOGF_ERR(...)
        #undef FLOGFLN_ERR
        #define FLOGFLN_ERR(...)
        #undef FLOG_PERROR_ERR
        #define FLOG_PERROR_ERR(...)
        #undef FLOG_PERRORF_ERR
        #define FLOG_PERRORF_ERR(...)

        #undef FLOG_CRIT
        #define FLOG_CRIT(...)
        #undef FLOGLN_CRIT
        #define FLOGLN_CRIT(...)
        #undef FLOGF_CRIT
        #define FLOGF_CRIT(...)
        #undef FLOGFLN_CRIT
        #define FLOGFLN_CRIT(...)
        #undef FLOG_PERROR_CRIT
        #define FLOG_PERROR_CRIT(...)
        #undef FLOG_PERRORF_CRIT
        #define FLOG_PERRORF_CRIT(...)

        #undef FLOG_FAT
        #define FLOG_FAT(...)
        #undef FLOGLN_FAT
        #define FLOGLN_FAT(...)
        #undef FLOGF_FAT
        #define FLOGF_FAT(...)
        #undef FLOGFLN_FAT
        #define FLOGFLN_FAT(...)
        #undef FLOG_PERROR_FAT
        #define FLOG_PERROR_FAT(...)
        #undef FLOG_PERRORF_FAT
        #define FLOG_PERRORF_FAT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

        #undef FLOG_EX
        #define FLOG_EX(...)
        #undef FLOGLN_EX
        #define FLOGLN_EX(...)
        #undef FLOGF_EX
        #define FLOGF_EX(...)
        #undef FLOGFLN_EX
        #define FLOGFLN_EX(...)

        #undef FLOG_IF
        #define FLOG_IF(...)
        #undef FLOGLN_IF
        #define FLOGLN_IF(...)
        #undef FLOGF_IF
        #define FLOGF_IF(...)
        #undef FLOGFLN_IF
        #define FLOGFLN_IF(...)

        #undef FLOG_HD
        #define FLOG_HD(...)
        #undef FLOGLN_HD
        #define FLOGLN_HD(...)
        #undef FLOGF_HD
        #define FLOGF_HD(...)
        #undef FLOGFLN_HD
        #define FLOGFLN_HD(...)

        #undef FLOG_SC
        #define FLOG_SC(...)
        #undef FLOGLN_SC
        #define FLOGLN_SC(...)
        #undef FLOGF_SC
        #define FLOGF_SC(...)
        #undef FLOGFLN_SC
        #define FLOGFLN_SC(...)

        #undef FLOG_MN
        #define FLOG_MN(...)
        #undef FLOGLN_MN
        #define FLOGLN_MN(...)
        #undef FLOGF_MN
        #define FLOGF_MN(...)
        #undef FLOGFLN_MN
        #define FLOGFLN_MN(...)

        #undef FLOG_MY
        #define FLOG_MY(...)
        #undef FLOGLN_MY
        #define FLOGLN_MY(...)
        #undef FLOGF_MY
        #define FLOGF_MY(...)
        #undef FLOGFLN_MY
        #define FLOGFLN_MY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WN
        #define FLOG_WN(...)
        #undef FLOGLN_WN
        #define FLOGLN_WN(...)
        #undef FLOGF_WN
        #define FLOGF_WN(...)
        #undef FLOGFLN_WN
        #define FLOGFLN_WN(...)
        #undef FLOG_PERROR_WN
        #define FLOG_PERROR_WN(...)
        #undef FLOG_PERRORF_WN
        #define FLOG_PERRORF_WN(...)

        #undef FLOG_ER
        #define FLOG_ER(...)
        #undef FLOGLN_ER
        #define FLOGLN_ER(...)
        #undef FLOGF_ER
        #define FLOGF_ER(...)
        #undef FLOGFLN_ER
        #define FLOGFLN_ER(...)
        #undef FLOG_PERROR_ER
        #define FLOG_PERROR_ER(...)
        #undef FLOG_PERRORF_ER
        #define FLOG_PERRORF_ER(...)

        #undef FLOG_CR
        #define FLOG_CR(...)
        #undef FLOGLN_CR
        #define FLOGLN_CR(...)
        #undef FLOGF_CR
        #define FLOGF_CR(...)
        #undef FLOGFLN_CR
        #define FLOGFLN_CR(...)
        #undef FLOG_PERROR_CR
        #define FLOG_PERROR_CR(...)
        #undef FLOG_PERRORF_CR
        #define FLOG_PERRORF_CR(...)

        #undef FLOG_FT
        #define FLOG_FT(...)
        #undef FLOGLN_FT
        #define FLOGLN_FT(...)
        #undef FLOGF_FT
        #define FLOGF_FT(...)
        #undef FLOGFLN_FT
        #define FLOGFLN_FT(...)
        #undef FLOG_PERROR_FT
        #define FLOG_PERROR_FT(...)
        #undef FLOG_PERRORF_FT
        #define FLOG_PERRORF_FT(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)

    #undef LOG_EXTRA
    #define LOG_EXTRA(...)
    #undef LOGLN_EXTRA
    #define LOGLN_EXTRA(...)
    #undef LOGF_EXTRA
    #define LOGF_EXTRA(...)
    #undef LOGFLN_EXTRA
    #define LOGFLN_EXTRA(...)

    #undef LOG_INFO
    #define LOG_INFO(...)
    #undef LOGLN_INFO
    #define LOGLN_INFO(...)
    #undef LOGF_INFO
    #define LOGF_INFO(...)
    #undef LOGFLN_INFO
    #define LOGFLN_INFO(...)

    #undef LOG_HEADER
    #define LOG_HEADER(...)
    #undef LOGLN_HEADER
    #define LOGLN_HEADER(...)
    #undef LOGF_HEADER
    #define LOGF_HEADER(...)
    #undef LOGFLN_HEADER
    #define LOGFLN_HEADER(...)

    #undef LOG_SUCCESS
    #define LOG_SUCCESS(...)
    #undef LOGLN_SUCCESS
    #define LOGLN_SUCCESS(...)
    #undef LOGF_SUCCESS
    #define LOGF_SUCCESS(...)
    #undef LOGFLN_SUCCESS
    #define LOGFLN_SUCCESS(...)

    #undef LOG_MONEY
    #define LOG_MONEY(...)
    #undef LOGLN_MONEY
    #define LOGLN_MONEY(...)
    #undef LOGF_MONEY
    #define LOGF_MONEY(...)
    #undef LOGFLN_MONEY
    #define LOGFLN_MONEY(...)

    #undef LOG_INPUT
    #define LOG_INPUT(...)
    #undef LOGLN_INPUT
    #define LOGLN_INPUT(...)
    #undef LOGF_INPUT
    #define LOGF_INPUT(...)
    #undef LOGFLN_INPUT
    #define LOGFLN_INPUT(...)

    #undef LOG_WARNING
    #define LOG_WARNING(...)
    #undef LOGLN_WARNING
    #define LOGLN_WARNING(...)
    #undef LOGF_WARNING
    #define LOGF_WARNING(...)
    #undef LOGFLN_WARNING
    #define LOGFLN_WARNING(...)
    #undef LOG_PERROR_WARNING
    #define LOG_PERROR_WARNING(...)
    #undef LOG_PERRORF_WARNING
    #define LOG_PERRORF_WARNING(...)

    #undef LOG_ERROR
    #define LOG_ERROR(...)
    #undef LOGLN_ERROR
    #define LOGLN_ERROR(...)
    #undef LOGF_ERROR
    #define LOGF_ERROR(...)
    #undef LOGFLN_ERROR
    #define LOGFLN_ERROR(...)
    #undef LOG_PERROR_ERROR
    #define LOG_PERROR_ERROR(...)
    #undef LOG_PERRORF_ERROR
    #define LOG_PERRORF_ERROR(...)

    #undef LOG_CRITICAL
    #define LOG_CRITICAL(...)
    #undef LOGLN_CRITICAL
    #define LOGLN_CRITICAL(...)
    #undef LOGF_CRITICAL
    #define LOGF_CRITICAL(...)
    #undef LOGFLN_CRITICAL
    #define LOGFLN_CRITICAL(...)
    #undef LOG_PERROR_CRITICAL
    #define LOG_PERROR_CRITICAL(...)
    #undef LOG_PERRORF_CRITICAL
    #define LOG_PERRORF_CRITICAL(...)

    #undef LOG_FATAL
    #define LOG_FATAL(...)
    #undef LOGLN_FATAL
    #define LOGLN_FATAL(...)
    #undef LOGF_FATAL
    #define LOGF_FATAL(...)
    #undef LOGFLN_FATAL
    #define LOGFLN_FATAL(...)
    #undef LOG_PERROR_FATAL
    #define LOG_PERROR_FATAL(...)
    #undef LOG_PERRORF_FATAL
    #define LOG_PERRORF_FATAL(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

        #undef LOG_EXT
        #define LOG_EXT(...)
        #undef LOGLN_EXT
        #define LOGLN_EXT(...)
        #undef LOGF_EXT
        #define LOGF_EXT(...)
        #undef LOGFLN_EXT
        #define LOGFLN_EXT(...)

        #undef LOG_INF
        #define LOG_INF(...)
        #undef LOGLN_INF
        #define LOGLN_INF(...)
        #undef LOGF_INF
        #define LOGF_INF(...)
        #undef LOGFLN_INF
        #define LOGFLN_INF(...)

        #undef LOG_HEAD
        #define LOG_HEAD(...)
        #undef LOGLN_HEAD
        #define LOGLN_HEAD(...)
        #undef LOGF_HEAD
        #define LOGF_HEAD(...)
        #undef LOGFLN_HEAD
        #define LOGFLN_HEAD(...)

        #undef LOG_SUC
        #define LOG_SUC(...)
        #undef LOGLN_SUC
        #define LOGLN_SUC(...)
        #undef LOGF_SUC
        #define LOGF_SUC(...)
        #undef LOGFLN_SUC
        #define LOGFLN_SUC(...)

        #undef LOG_MON
        #define LOG_MON(...)
        #undef LOGLN_MON
        #define LOGLN_MON(...)
        #undef LOGF_MON
        #define LOGF_MON(...)
        #undef LOGFLN_MON
        #define LOGFLN_MON(...)

        #undef LOG_MNY
        #define LOG_MNY(...)
        #undef LOGLN_MNY
        #define LOGLN_MNY(...)
        #undef LOGF_MNY
        #define LOGF_MNY(...)
        #undef LOGFLN_MNY
        #define LOGFLN_MNY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WARN
        #define LOG_WARN(...)
        #undef LOGLN_WARN
        #define LOGLN_WARN(...)
        #undef LOGF_WARN
        #define LOGF_WARN(...)
        #undef LOGFLN_WARN
        #define LOGFLN_WARN(...)
        #undef LOG_PERROR_WARN
        #define LOG_PERROR_WARN(...)
        #undef LOG_PERRORF_WARN
        #define LOG_PERRORF_WARN(...)

        #undef LOG_ERR
        #define LOG_ERR(...)
        #undef LOGLN_ERR
        #define LOGLN_ERR(...)
        #undef LOGF_ERR
        #define LOGF_ERR(...)
        #undef LOGFLN_ERR
        #define LOGFLN_ERR(...)
        #undef LOG_PERROR_ERR
        #define LOG_PERROR_ERR(...)
        #undef LOG_PERRORF_ERR
        #define LOG_PERRORF_ERR(...)

        #undef LOG_CRIT
        #define LOG_CRIT(...)
        #undef LOGLN_CRIT
        #define LOGLN_CRIT(...)
        #undef LOGF_CRIT
        #define LOGF_CRIT(...)
        #undef LOGFLN_CRIT
        #define LOGFLN_CRIT(...)
        #undef LOG_PERROR_CRIT
        #define LOG_PERROR_CRIT(...)
        #undef LOG_PERRORF_CRIT
        #define LOG_PERRORF_CRIT(...)

        #undef LOG_FAT
        #define LOG_FAT(...)
        #undef LOGLN_FAT
        #define LOGLN_FAT(...)
        #undef LOGF_FAT
        #define LOGF_FAT(...)
        #undef LOGFLN_FAT
        #define LOGFLN_FAT(...)
        #undef LOG_PERROR_FAT
        #define LOG_PERROR_FAT(...)
        #undef LOG_PERRORF_FAT
        #define LOG_PERRORF_FAT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

        #undef LOG_EX
        #define LOG_EX(...)
        #undef LOGLN_EX
        #define LOGLN_EX(...)
        #undef LOGF_EX
        #define LOGF_EX(...)
        #undef LOGFLN_EX
        #define LOGFLN_EX(...)

        #undef LOG_IF
        #define LOG_IF(...)
        #undef LOGLN_IF
        #define LOGLN_IF(...)
        #undef LOGF_IF
        #define LOGF_IF(...)
        #undef LOGFLN_IF
        #define LOGFLN_IF(...)

        #undef LOG_HD
        #define LOG_HD(...)
        #undef LOGLN_HD
        #define LOGLN_HD(...)
        #undef LOGF_HD
        #define LOGF_HD(...)
        #undef LOGFLN_HD
        #define LOGFLN_HD(...)

        #undef LOG_SC
        #define LOG_SC(...)
        #undef LOGLN_SC
        #define LOGLN_SC(...)
        #undef LOGF_SC
        #define LOGF_SC(...)
        #undef LOGFLN_SC
        #define LOGFLN_SC(...)

        #undef LOG_MN
        #define LOG_MN(...)
        #undef LOGLN_MN
        #define LOGLN_MN(...)
        #undef LOGF_MN
        #define LOGF_MN(...)
        #undef LOGFLN_MN
        #define LOGFLN_MN(...)

        #undef LOG_MY
        #define LOG_MY(...)
        #undef LOGLN_MY
        #define LOGLN_MY(...)
        #undef LOGF_MY
        #define LOGF_MY(...)
        #undef LOGFLN_MY
        #define LOGFLN_MY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WN
        #define LOG_WN(...)
        #undef LOGLN_WN
        #define LOGLN_WN(...)
        #undef LOGF_WN
        #define LOGF_WN(...)
        #undef LOGFLN_WN
        #define LOGFLN_WN(...)
        #undef LOG_PERROR_WN
        #define LOG_PERROR_WN(...)
        #undef LOG_PERRORF_WN
        #define LOG_PERRORF_WN(...)

        #undef LOG_ER
        #define LOG_ER(...)
        #undef LOGLN_ER
        #define LOGLN_ER(...)
        #undef LOGF_ER
        #define LOGF_ER(...)
        #undef LOGFLN_ER
        #define LOGFLN_ER(...)
        #undef LOG_PERROR_ER
        #define LOG_PERROR_ER(...)
        #undef LOG_PERRORF_ER
        #define LOG_PERRORF_ER(...)

        #undef LOG_CR
        #define LOG_CR(...)
        #undef LOGLN_CR
        #define LOGLN_CR(...)
        #undef LOGF_CR
        #define LOGF_CR(...)
        #undef LOGFLN_CR
        #define LOGFLN_CR(...)
        #undef LOG_PERROR_CR
        #define LOG_PERROR_CR(...)
        #undef LOG_PERRORF_CR
        #define LOG_PERRORF_CR(...)

        #undef LOG_FT
        #define LOG_FT(...)
        #undef LOGLN_FT
        #define LOGLN_FT(...)
        #undef LOGF_FT
        #define LOGF_FT(...)
        #undef LOGFLN_FT
        #define LOGFLN_FT(...)
        #undef LOG_PERROR_FT
        #define LOG_PERROR_FT(...)
        #undef LOG_PERRORF_FT
        #define LOG_PERRORF_FT(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

        #undef EXTRA
        #define EXTRA(...)
        #undef EXTRALN
        #define EXTRALN(...)
        #undef EXTRAF
        #define EXTRAF(...)
        #undef EXTRAFLN
        #define EXTRAFLN(...)

        #undef INFO
        #define INFO(...)
        #undef INFOLN
        #define INFOLN(...)
        #undef INFOF
        #define INFOF(...)
        #undef INFOFLN
        #define INFOFLN(...)

        #undef HEADER
        #define HEADER(...)
        #undef HEADERLN
        #define HEADERLN(...)
        #undef HEADERF
        #define HEADERF(...)
        #undef HEADERFLN
        #define HEADERFLN(...)

        #undef SUCCESS
        #define SUCCESS(...)
        #undef SUCCESSLN
        #define SUCCESSLN(...)
        #undef SUCCESSF
        #define SUCCESSF(...)
        #undef SUCCESSFLN
        #define SUCCESSFLN(...)

        #undef MONEY
        #define MONEY(...)
        #undef MONEYLN
        #define MONEYLN(...)
        #undef MONEYF
        #define MONEYF(...)
        #undef MONEYFLN
        #define MONEYFLN(...)

        #undef INPUT
        #define INPUT(...)
        #undef INPUTLN
        #define INPUTLN(...)
        #undef INPUTF
        #define INPUTF(...)
        #undef INPUTFLN
        #define INPUTFLN(...)

        #undef WARNING
        #define WARNING(...)
        #undef WARNINGLN
        #define WARNINGLN(...)
        #undef WARNINGF
        #define WARNINGF(...)
        #undef WARNINGFLN
        #define WARNINGFLN(...)
        #undef WARNING_PERROR
        #define WARNING_PERROR(...)
        #undef WARNING_PERRORF
        #define WARNING_PERRORF(...)

        #undef ERROR
        #define ERROR(...)
        #undef ERRORLN
        #define ERRORLN(...)
        #undef ERRORF
        #define ERRORF(...)
        #undef ERRORFLN
        #define ERRORFLN(...)
        #undef ERROR_PERROR
        #define ERROR_PERROR(...)
        #undef ERROR_PERRORF
        #define ERROR_PERRORF(...)

        #undef CRITICAL
        #define CRITICAL(...)
        #undef CRITICALLN
        #define CRITICALLN(...)
        #undef CRITICALF
        #define CRITICALF(...)
        #undef CRITICALFLN
        #define CRITICALFLN(...)
        #undef CRITICAL_PERROR
        #define CRITICAL_PERROR(...)
        #undef CRITICAL_PERRORF
        #define CRITICAL_PERRORF(...)

        #undef FATAL
        #define FATAL(...)
        #undef FATALLN
        #define FATALLN(...)
        #undef FATALF
        #define FATALF(...)
        #undef FATALFLN
        #define FATALFLN(...)
        #undef FATAL_PERROR
        #define FATAL_PERROR(...)
        #undef FATAL_PERRORF
        #define FATAL_PERRORF(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_CRITICAL

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)

    #undef CLOG_EXTRA
    #define CLOG_EXTRA(...)
    #undef CLOGLN_EXTRA
    #define CLOGLN_EXTRA(...)
    #undef CLOGF_EXTRA
    #define CLOGF_EXTRA(...)
    #undef CLOGFLN_EXTRA
    #define CLOGFLN_EXTRA(...)

    #undef CLOG_INFO
    #define CLOG_INFO(...)
    #undef CLOGLN_INFO
    #define CLOGLN_INFO(...)
    #undef CLOGF_INFO
    #define CLOGF_INFO(...)
    #undef CLOGFLN_INFO
    #define CLOGFLN_INFO(...)

    #undef CLOG_HEADER
    #define CLOG_HEADER(...)
    #undef CLOGLN_HEADER
    #define CLOGLN_HEADER(...)
    #undef CLOGF_HEADER
    #define CLOGF_HEADER(...)
    #undef CLOGFLN_HEADER
    #define CLOGFLN_HEADER(...)

    #undef CLOG_SUCCESS
    #define CLOG_SUCCESS(...)
    #undef CLOGLN_SUCCESS
    #define CLOGLN_SUCCESS(...)
    #undef CLOGF_SUCCESS
    #define CLOGF_SUCCESS(...)
    #undef CLOGFLN_SUCCESS
    #define CLOGFLN_SUCCESS(...)

    #undef CLOG_MONEY
    #define CLOG_MONEY(...)
    #undef CLOGLN_MONEY
    #define CLOGLN_MONEY(...)
    #undef CLOGF_MONEY
    #define CLOGF_MONEY(...)
    #undef CLOGFLN_MONEY
    #define CLOGFLN_MONEY(...)

    #undef CLOG_INPUT
    #define CLOG_INPUT(...)
    #undef CLOGLN_INPUT
    #define CLOGLN_INPUT(...)
    #undef CLOGF_INPUT
    #define CLOGF_INPUT(...)
    #undef CLOGFLN_INPUT
    #define CLOGFLN_INPUT(...)

    #undef CLOG_WARNING
    #define CLOG_WARNING(...)
    #undef CLOGLN_WARNING
    #define CLOGLN_WARNING(...)
    #undef CLOGF_WARNING
    #define CLOGF_WARNING(...)
    #undef CLOGFLN_WARNING
    #define CLOGFLN_WARNING(...)
    #undef CLOG_PERROR_WARNING
    #define CLOG_PERROR_WARNING(...)
    #undef CLOG_PERRORF_WARNING
    #define CLOG_PERRORF_WARNING(...)

    #undef CLOG_ERROR
    #define CLOG_ERROR(...)
    #undef CLOGLN_ERROR
    #define CLOGLN_ERROR(...)
    #undef CLOGF_ERROR
    #define CLOGF_ERROR(...)
    #undef CLOGFLN_ERROR
    #define CLOGFLN_ERROR(...)
    #undef CLOG_PERROR_ERROR
    #define CLOG_PERROR_ERROR(...)
    #undef CLOG_PERRORF_ERROR
    #define CLOG_PERRORF_ERROR(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

        #undef CLOG_EXT
        #define CLOG_EXT(...)
        #undef CLOGLN_EXT
        #define CLOGLN_EXT(...)
        #undef CLOGF_EXT
        #define CLOGF_EXT(...)
        #undef CLOGFLN_EXT
        #define CLOGFLN_EXT(...)

        #undef CLOG_INF
        #define CLOG_INF(...)
        #undef CLOGLN_INF
        #define CLOGLN_INF(...)
        #undef CLOGF_INF
        #define CLOGF_INF(...)
        #undef CLOGFLN_INF
        #define CLOGFLN_INF(...)

        #undef CLOG_HEAD
        #define CLOG_HEAD(...)
        #undef CLOGLN_HEAD
        #define CLOGLN_HEAD(...)
        #undef CLOGF_HEAD
        #define CLOGF_HEAD(...)
        #undef CLOGFLN_HEAD
        #define CLOGFLN_HEAD(...)

        #undef CLOG_SUC
        #define CLOG_SUC(...)
        #undef CLOGLN_SUC
        #define CLOGLN_SUC(...)
        #undef CLOGF_SUC
        #define CLOGF_SUC(...)
        #undef CLOGFLN_SUC
        #define CLOGFLN_SUC(...)

        #undef CLOG_MON
        #define CLOG_MON(...)
        #undef CLOGLN_MON
        #define CLOGLN_MON(...)
        #undef CLOGF_MON
        #define CLOGF_MON(...)
        #undef CLOGFLN_MON
        #define CLOGFLN_MON(...)

        #undef CLOG_MNY
        #define CLOG_MNY(...)
        #undef CLOGLN_MNY
        #define CLOGLN_MNY(...)
        #undef CLOGF_MNY
        #define CLOGF_MNY(...)
        #undef CLOGFLN_MNY
        #define CLOGFLN_MNY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WARN
        #define CLOG_WARN(...)
        #undef CLOGLN_WARN
        #define CLOGLN_WARN(...)
        #undef CLOGF_WARN
        #define CLOGF_WARN(...)
        #undef CLOGFLN_WARN
        #define CLOGFLN_WARN(...)
        #undef CLOG_PERROR_WARN
        #define CLOG_PERROR_WARN(...)
        #undef CLOG_PERRORF_WARN
        #define CLOG_PERRORF_WARN(...)

        #undef CLOG_ERR
        #define CLOG_ERR(...)
        #undef CLOGLN_ERR
        #define CLOGLN_ERR(...)
        #undef CLOGF_ERR
        #define CLOGF_ERR(...)
        #undef CLOGFLN_ERR
        #define CLOGFLN_ERR(...)
        #undef CLOG_PERROR_ERR
        #define CLOG_PERROR_ERR(...)
        #undef CLOG_PERRORF_ERR
        #define CLOG_PERRORF_ERR(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

        #undef CLOG_EX
        #define CLOG_EX(...)
        #undef CLOGLN_EX
        #define CLOGLN_EX(...)
        #undef CLOGF_EX
        #define CLOGF_EX(...)
        #undef CLOGFLN_EX
        #define CLOGFLN_EX(...)

        #undef CLOG_IF
        #define CLOG_IF(...)
        #undef CLOGLN_IF
        #define CLOGLN_IF(...)
        #undef CLOGF_IF
        #define CLOGF_IF(...)
        #undef CLOGFLN_IF
        #define CLOGFLN_IF(...)

        #undef CLOG_HD
        #define CLOG_HD(...)
        #undef CLOGLN_HD
        #define CLOGLN_HD(...)
        #undef CLOGF_HD
        #define CLOGF_HD(...)
        #undef CLOGFLN_HD
        #define CLOGFLN_HD(...)

        #undef CLOG_SC
        #define CLOG_SC(...)
        #undef CLOGLN_SC
        #define CLOGLN_SC(...)
        #undef CLOGF_SC
        #define CLOGF_SC(...)
        #undef CLOGFLN_SC
        #define CLOGFLN_SC(...)

        #undef CLOG_MN
        #define CLOG_MN(...)
        #undef CLOGLN_MN
        #define CLOGLN_MN(...)
        #undef CLOGF_MN
        #define CLOGF_MN(...)
        #undef CLOGFLN_MN
        #define CLOGFLN_MN(...)

        #undef CLOG_MY
        #define CLOG_MY(...)
        #undef CLOGLN_MY
        #define CLOGLN_MY(...)
        #undef CLOGF_MY
        #define CLOGF_MY(...)
        #undef CLOGFLN_MY
        #define CLOGFLN_MY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WN
        #define CLOG_WN(...)
        #undef CLOGLN_WN
        #define CLOGLN_WN(...)
        #undef CLOGF_WN
        #define CLOGF_WN(...)
        #undef CLOGFLN_WN
        #define CLOGFLN_WN(...)
        #undef CLOG_PERROR_WN
        #define CLOG_PERROR_WN(...)
        #undef CLOG_PERRORF_WN
        #define CLOG_PERRORF_WN(...)

        #undef CLOG_ER
        #define CLOG_ER(...)
        #undef CLOGLN_ER
        #define CLOGLN_ER(...)
        #undef CLOGF_ER
        #define CLOGF_ER(...)
        #undef CLOGFLN_ER
        #define CLOGFLN_ER(...)
        #undef CLOG_PERROR_ER
        #define CLOG_PERROR_ER(...)
        #undef CLOG_PERRORF_ER
        #define CLOG_PERRORF_ER(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)

    #undef FLOG_EXTRA
    #define FLOG_EXTRA(...)
    #undef FLOGLN_EXTRA
    #define FLOGLN_EXTRA(...)
    #undef FLOGF_EXTRA
    #define FLOGF_EXTRA(...)
    #undef FLOGFLN_EXTRA
    #define FLOGFLN_EXTRA(...)

    #undef FLOG_INFO
    #define FLOG_INFO(...)
    #undef FLOGLN_INFO
    #define FLOGLN_INFO(...)
    #undef FLOGF_INFO
    #define FLOGF_INFO(...)
    #undef FLOGFLN_INFO
    #define FLOGFLN_INFO(...)

    #undef FLOG_HEADER
    #define FLOG_HEADER(...)
    #undef FLOGLN_HEADER
    #define FLOGLN_HEADER(...)
    #undef FLOGF_HEADER
    #define FLOGF_HEADER(...)
    #undef FLOGFLN_HEADER
    #define FLOGFLN_HEADER(...)

    #undef FLOG_SUCCESS
    #define FLOG_SUCCESS(...)
    #undef FLOGLN_SUCCESS
    #define FLOGLN_SUCCESS(...)
    #undef FLOGF_SUCCESS
    #define FLOGF_SUCCESS(...)
    #undef FLOGFLN_SUCCESS
    #define FLOGFLN_SUCCESS(...)

    #undef FLOG_MONEY
    #define FLOG_MONEY(...)
    #undef FLOGLN_MONEY
    #define FLOGLN_MONEY(...)
    #undef FLOGF_MONEY
    #define FLOGF_MONEY(...)
    #undef FLOGFLN_MONEY
    #define FLOGFLN_MONEY(...)

    #undef FLOG_INPUT
    #define FLOG_INPUT(...)
    #undef FLOGLN_INPUT
    #define FLOGLN_INPUT(...)
    #undef FLOGF_INPUT
    #define FLOGF_INPUT(...)
    #undef FLOGFLN_INPUT
    #define FLOGFLN_INPUT(...)

    #undef FLOG_WARNING
    #define FLOG_WARNING(...)
    #undef FLOGLN_WARNING
    #define FLOGLN_WARNING(...)
    #undef FLOGF_WARNING
    #define FLOGF_WARNING(...)
    #undef FLOGFLN_WARNING
    #define FLOGFLN_WARNING(...)
    #undef FLOG_PERROR_WARNING
    #define FLOG_PERROR_WARNING(...)
    #undef FLOG_PERRORF_WARNING
    #define FLOG_PERRORF_WARNING(...)

    #undef FLOG_ERROR
    #define FLOG_ERROR(...)
    #undef FLOGLN_ERROR
    #define FLOGLN_ERROR(...)
    #undef FLOGF_ERROR
    #define FLOGF_ERROR(...)
    #undef FLOGFLN_ERROR
    #define FLOGFLN_ERROR(...)
    #undef FLOG_PERROR_ERROR
    #define FLOG_PERROR_ERROR(...)
    #undef FLOG_PERRORF_ERROR
    #define FLOG_PERRORF_ERROR(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

        #undef FLOG_EXT
        #define FLOG_EXT(...)
        #undef FLOGLN_EXT
        #define FLOGLN_EXT(...)
        #undef FLOGF_EXT
        #define FLOGF_EXT(...)
        #undef FLOGFLN_EXT
        #define FLOGFLN_EXT(...)

        #undef FLOG_INF
        #define FLOG_INF(...)
        #undef FLOGLN_INF
        #define FLOGLN_INF(...)
        #undef FLOGF_INF
        #define FLOGF_INF(...)
        #undef FLOGFLN_INF
        #define FLOGFLN_INF(...)

        #undef FLOG_HEAD
        #define FLOG_HEAD(...)
        #undef FLOGLN_HEAD
        #define FLOGLN_HEAD(...)
        #undef FLOGF_HEAD
        #define FLOGF_HEAD(...)
        #undef FLOGFLN_HEAD
        #define FLOGFLN_HEAD(...)

        #undef FLOG_SUC
        #define FLOG_SUC(...)
        #undef FLOGLN_SUC
        #define FLOGLN_SUC(...)
        #undef FLOGF_SUC
        #define FLOGF_SUC(...)
        #undef FLOGFLN_SUC
        #define FLOGFLN_SUC(...)

        #undef FLOG_MON
        #define FLOG_MON(...)
        #undef FLOGLN_MON
        #define FLOGLN_MON(...)
        #undef FLOGF_MON
        #define FLOGF_MON(...)
        #undef FLOGFLN_MON
        #define FLOGFLN_MON(...)

        #undef FLOG_MNY
        #define FLOG_MNY(...)
        #undef FLOGLN_MNY
        #define FLOGLN_MNY(...)
        #undef FLOGF_MNY
        #define FLOGF_MNY(...)
        #undef FLOGFLN_MNY
        #define FLOGFLN_MNY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WARN
        #define FLOG_WARN(...)
        #undef FLOGLN_WARN
        #define FLOGLN_WARN(...)
        #undef FLOGF_WARN
        #define FLOGF_WARN(...)
        #undef FLOGFLN_WARN
        #define FLOGFLN_WARN(...)
        #undef FLOG_PERROR_WARN
        #define FLOG_PERROR_WARN(...)
        #undef FLOG_PERRORF_WARN
        #define FLOG_PERRORF_WARN(...)

        #undef FLOG_ERR
        #define FLOG_ERR(...)
        #undef FLOGLN_ERR
        #define FLOGLN_ERR(...)
        #undef FLOGF_ERR
        #define FLOGF_ERR(...)
        #undef FLOGFLN_ERR
        #define FLOGFLN_ERR(...)
        #undef FLOG_PERROR_ERR
        #define FLOG_PERROR_ERR(...)
        #undef FLOG_PERRORF_ERR
        #define FLOG_PERRORF_ERR(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

        #undef FLOG_EX
        #define FLOG_EX(...)
        #undef FLOGLN_EX
        #define FLOGLN_EX(...)
        #undef FLOGF_EX
        #define FLOGF_EX(...)
        #undef FLOGFLN_EX
        #define FLOGFLN_EX(...)

        #undef FLOG_IF
        #define FLOG_IF(...)
        #undef FLOGLN_IF
        #define FLOGLN_IF(...)
        #undef FLOGF_IF
        #define FLOGF_IF(...)
        #undef FLOGFLN_IF
        #define FLOGFLN_IF(...)

        #undef FLOG_HD
        #define FLOG_HD(...)
        #undef FLOGLN_HD
        #define FLOGLN_HD(...)
        #undef FLOGF_HD
        #define FLOGF_HD(...)
        #undef FLOGFLN_HD
        #define FLOGFLN_HD(...)

        #undef FLOG_SC
        #define FLOG_SC(...)
        #undef FLOGLN_SC
        #define FLOGLN_SC(...)
        #undef FLOGF_SC
        #define FLOGF_SC(...)
        #undef FLOGFLN_SC
        #define FLOGFLN_SC(...)

        #undef FLOG_MN
        #define FLOG_MN(...)
        #undef FLOGLN_MN
        #define FLOGLN_MN(...)
        #undef FLOGF_MN
        #define FLOGF_MN(...)
        #undef FLOGFLN_MN
        #define FLOGFLN_MN(...)

        #undef FLOG_MY
        #define FLOG_MY(...)
        #undef FLOGLN_MY
        #define FLOGLN_MY(...)
        #undef FLOGF_MY
        #define FLOGF_MY(...)
        #undef FLOGFLN_MY
        #define FLOGFLN_MY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WN
        #define FLOG_WN(...)
        #undef FLOGLN_WN
        #define FLOGLN_WN(...)
        #undef FLOGF_WN
        #define FLOGF_WN(...)
        #undef FLOGFLN_WN
        #define FLOGFLN_WN(...)
        #undef FLOG_PERROR_WN
        #define FLOG_PERROR_WN(...)
        #undef FLOG_PERRORF_WN
        #define FLOG_PERRORF_WN(...)

        #undef FLOG_ER
        #define FLOG_ER(...)
        #undef FLOGLN_ER
        #define FLOGLN_ER(...)
        #undef FLOGF_ER
        #define FLOGF_ER(...)
        #undef FLOGFLN_ER
        #define FLOGFLN_ER(...)
        #undef FLOG_PERROR_ER
        #define FLOG_PERROR_ER(...)
        #undef FLOG_PERRORF_ER
        #define FLOG_PERRORF_ER(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)

    #undef LOG_EXTRA
    #define LOG_EXTRA(...)
    #undef LOGLN_EXTRA
    #define LOGLN_EXTRA(...)
    #undef LOGF_EXTRA
    #define LOGF_EXTRA(...)
    #undef LOGFLN_EXTRA
    #define LOGFLN_EXTRA(...)

    #undef LOG_INFO
    #define LOG_INFO(...)
    #undef LOGLN_INFO
    #define LOGLN_INFO(...)
    #undef LOGF_INFO
    #define LOGF_INFO(...)
    #undef LOGFLN_INFO
    #define LOGFLN_INFO(...)

    #undef LOG_HEADER
    #define LOG_HEADER(...)
    #undef LOGLN_HEADER
    #define LOGLN_HEADER(...)
    #undef LOGF_HEADER
    #define LOGF_HEADER(...)
    #undef LOGFLN_HEADER
    #define LOGFLN_HEADER(...)

    #undef LOG_SUCCESS
    #define LOG_SUCCESS(...)
    #undef LOGLN_SUCCESS
    #define LOGLN_SUCCESS(...)
    #undef LOGF_SUCCESS
    #define LOGF_SUCCESS(...)
    #undef LOGFLN_SUCCESS
    #define LOGFLN_SUCCESS(...)

    #undef LOG_MONEY
    #define LOG_MONEY(...)
    #undef LOGLN_MONEY
    #define LOGLN_MONEY(...)
    #undef LOGF_MONEY
    #define LOGF_MONEY(...)
    #undef LOGFLN_MONEY
    #define LOGFLN_MONEY(...)

    #undef LOG_INPUT
    #define LOG_INPUT(...)
    #undef LOGLN_INPUT
    #define LOGLN_INPUT(...)
    #undef LOGF_INPUT
    #define LOGF_INPUT(...)
    #undef LOGFLN_INPUT
    #define LOGFLN_INPUT(...)

    #undef LOG_WARNING
    #define LOG_WARNING(...)
    #undef LOGLN_WARNING
    #define LOGLN_WARNING(...)
    #undef LOGF_WARNING
    #define LOGF_WARNING(...)
    #undef LOGFLN_WARNING
    #define LOGFLN_WARNING(...)
    #undef LOG_PERROR_WARNING
    #define LOG_PERROR_WARNING(...)
    #undef LOG_PERRORF_WARNING
    #define LOG_PERRORF_WARNING(...)

    #undef LOG_ERROR
    #define LOG_ERROR(...)
    #undef LOGLN_ERROR
    #define LOGLN_ERROR(...)
    #undef LOGF_ERROR
    #define LOGF_ERROR(...)
    #undef LOGFLN_ERROR
    #define LOGFLN_ERROR(...)
    #undef LOG_PERROR_ERROR
    #define LOG_PERROR_ERROR(...)
    #undef LOG_PERRORF_ERROR
    #define LOG_PERRORF_ERROR(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

        #undef LOG_EXT
        #define LOG_EXT(...)
        #undef LOGLN_EXT
        #define LOGLN_EXT(...)
        #undef LOGF_EXT
        #define LOGF_EXT(...)
        #undef LOGFLN_EXT
        #define LOGFLN_EXT(...)

        #undef LOG_INF
        #define LOG_INF(...)
        #undef LOGLN_INF
        #define LOGLN_INF(...)
        #undef LOGF_INF
        #define LOGF_INF(...)
        #undef LOGFLN_INF
        #define LOGFLN_INF(...)

        #undef LOG_HEAD
        #define LOG_HEAD(...)
        #undef LOGLN_HEAD
        #define LOGLN_HEAD(...)
        #undef LOGF_HEAD
        #define LOGF_HEAD(...)
        #undef LOGFLN_HEAD
        #define LOGFLN_HEAD(...)

        #undef LOG_SUC
        #define LOG_SUC(...)
        #undef LOGLN_SUC
        #define LOGLN_SUC(...)
        #undef LOGF_SUC
        #define LOGF_SUC(...)
        #undef LOGFLN_SUC
        #define LOGFLN_SUC(...)

        #undef LOG_MON
        #define LOG_MON(...)
        #undef LOGLN_MON
        #define LOGLN_MON(...)
        #undef LOGF_MON
        #define LOGF_MON(...)
        #undef LOGFLN_MON
        #define LOGFLN_MON(...)

        #undef LOG_MNY
        #define LOG_MNY(...)
        #undef LOGLN_MNY
        #define LOGLN_MNY(...)
        #undef LOGF_MNY
        #define LOGF_MNY(...)
        #undef LOGFLN_MNY
        #define LOGFLN_MNY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WARN
        #define LOG_WARN(...)
        #undef LOGLN_WARN
        #define LOGLN_WARN(...)
        #undef LOGF_WARN
        #define LOGF_WARN(...)
        #undef LOGFLN_WARN
        #define LOGFLN_WARN(...)
        #undef LOG_PERROR_WARN
        #define LOG_PERROR_WARN(...)
        #undef LOG_PERRORF_WARN
        #define LOG_PERRORF_WARN(...)

        #undef LOG_ERR
        #define LOG_ERR(...)
        #undef LOGLN_ERR
        #define LOGLN_ERR(...)
        #undef LOGF_ERR
        #define LOGF_ERR(...)
        #undef LOGFLN_ERR
        #define LOGFLN_ERR(...)
        #undef LOG_PERROR_ERR
        #define LOG_PERROR_ERR(...)
        #undef LOG_PERRORF_ERR
        #define LOG_PERRORF_ERR(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

        #undef LOG_EX
        #define LOG_EX(...)
        #undef LOGLN_EX
        #define LOGLN_EX(...)
        #undef LOGF_EX
        #define LOGF_EX(...)
        #undef LOGFLN_EX
        #define LOGFLN_EX(...)

        #undef LOG_IF
        #define LOG_IF(...)
        #undef LOGLN_IF
        #define LOGLN_IF(...)
        #undef LOGF_IF
        #define LOGF_IF(...)
        #undef LOGFLN_IF
        #define LOGFLN_IF(...)

        #undef LOG_HD
        #define LOG_HD(...)
        #undef LOGLN_HD
        #define LOGLN_HD(...)
        #undef LOGF_HD
        #define LOGF_HD(...)
        #undef LOGFLN_HD
        #define LOGFLN_HD(...)

        #undef LOG_SC
        #define LOG_SC(...)
        #undef LOGLN_SC
        #define LOGLN_SC(...)
        #undef LOGF_SC
        #define LOGF_SC(...)
        #undef LOGFLN_SC
        #define LOGFLN_SC(...)

        #undef LOG_MN
        #define LOG_MN(...)
        #undef LOGLN_MN
        #define LOGLN_MN(...)
        #undef LOGF_MN
        #define LOGF_MN(...)
        #undef LOGFLN_MN
        #define LOGFLN_MN(...)

        #undef LOG_MY
        #define LOG_MY(...)
        #undef LOGLN_MY
        #define LOGLN_MY(...)
        #undef LOGF_MY
        #define LOGF_MY(...)
        #undef LOGFLN_MY
        #define LOGFLN_MY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WN
        #define LOG_WN(...)
        #undef LOGLN_WN
        #define LOGLN_WN(...)
        #undef LOGF_WN
        #define LOGF_WN(...)
        #undef LOGFLN_WN
        #define LOGFLN_WN(...)
        #undef LOG_PERROR_WN
        #define LOG_PERROR_WN(...)
        #undef LOG_PERRORF_WN
        #define LOG_PERRORF_WN(...)

        #undef LOG_ER
        #define LOG_ER(...)
        #undef LOGLN_ER
        #define LOGLN_ER(...)
        #undef LOGF_ER
        #define LOGF_ER(...)
        #undef LOGFLN_ER
        #define LOGFLN_ER(...)
        #undef LOG_PERROR_ER
        #define LOG_PERROR_ER(...)
        #undef LOG_PERRORF_ER
        #define LOG_PERRORF_ER(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

        #undef EXTRA
        #define EXTRA(...)
        #undef EXTRALN
        #define EXTRALN(...)
        #undef EXTRAF
        #define EXTRAF(...)
        #undef EXTRAFLN
        #define EXTRAFLN(...)

        #undef INFO
        #define INFO(...)
        #undef INFOLN
        #define INFOLN(...)
        #undef INFOF
        #define INFOF(...)
        #undef INFOFLN
        #define INFOFLN(...)

        #undef HEADER
        #define HEADER(...)
        #undef HEADERLN
        #define HEADERLN(...)
        #undef HEADERF
        #define HEADERF(...)
        #undef HEADERFLN
        #define HEADERFLN(...)

        #undef SUCCESS
        #define SUCCESS(...)
        #undef SUCCESSLN
        #define SUCCESSLN(...)
        #undef SUCCESSF
        #define SUCCESSF(...)
        #undef SUCCESSFLN
        #define SUCCESSFLN(...)

        #undef MONEY
        #define MONEY(...)
        #undef MONEYLN
        #define MONEYLN(...)
        #undef MONEYF
        #define MONEYF(...)
        #undef MONEYFLN
        #define MONEYFLN(...)

        #undef INPUT
        #define INPUT(...)
        #undef INPUTLN
        #define INPUTLN(...)
        #undef INPUTF
        #define INPUTF(...)
        #undef INPUTFLN
        #define INPUTFLN(...)

        #undef WARNING
        #define WARNING(...)
        #undef WARNINGLN
        #define WARNINGLN(...)
        #undef WARNINGF
        #define WARNINGF(...)
        #undef WARNINGFLN
        #define WARNINGFLN(...)
        #undef WARNING_PERROR
        #define WARNING_PERROR(...)
        #undef WARNING_PERRORF
        #define WARNING_PERRORF(...)

        #undef ERROR
        #define ERROR(...)
        #undef ERRORLN
        #define ERRORLN(...)
        #undef ERRORF
        #define ERRORF(...)
        #undef ERRORFLN
        #define ERRORFLN(...)
        #undef ERROR_PERROR
        #define ERROR_PERROR(...)
        #undef ERROR_PERRORF
        #define ERROR_PERRORF(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_ERROR

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)

    #undef CLOG_EXTRA
    #define CLOG_EXTRA(...)
    #undef CLOGLN_EXTRA
    #define CLOGLN_EXTRA(...)
    #undef CLOGF_EXTRA
    #define CLOGF_EXTRA(...)
    #undef CLOGFLN_EXTRA
    #define CLOGFLN_EXTRA(...)

    #undef CLOG_INFO
    #define CLOG_INFO(...)
    #undef CLOGLN_INFO
    #define CLOGLN_INFO(...)
    #undef CLOGF_INFO
    #define CLOGF_INFO(...)
    #undef CLOGFLN_INFO
    #define CLOGFLN_INFO(...)

    #undef CLOG_HEADER
    #define CLOG_HEADER(...)
    #undef CLOGLN_HEADER
    #define CLOGLN_HEADER(...)
    #undef CLOGF_HEADER
    #define CLOGF_HEADER(...)
    #undef CLOGFLN_HEADER
    #define CLOGFLN_HEADER(...)

    #undef CLOG_SUCCESS
    #define CLOG_SUCCESS(...)
    #undef CLOGLN_SUCCESS
    #define CLOGLN_SUCCESS(...)
    #undef CLOGF_SUCCESS
    #define CLOGF_SUCCESS(...)
    #undef CLOGFLN_SUCCESS
    #define CLOGFLN_SUCCESS(...)

    #undef CLOG_MONEY
    #define CLOG_MONEY(...)
    #undef CLOGLN_MONEY
    #define CLOGLN_MONEY(...)
    #undef CLOGF_MONEY
    #define CLOGF_MONEY(...)
    #undef CLOGFLN_MONEY
    #define CLOGFLN_MONEY(...)

    #undef CLOG_INPUT
    #define CLOG_INPUT(...)
    #undef CLOGLN_INPUT
    #define CLOGLN_INPUT(...)
    #undef CLOGF_INPUT
    #define CLOGF_INPUT(...)
    #undef CLOGFLN_INPUT
    #define CLOGFLN_INPUT(...)

    #undef CLOG_WARNING
    #define CLOG_WARNING(...)
    #undef CLOGLN_WARNING
    #define CLOGLN_WARNING(...)
    #undef CLOGF_WARNING
    #define CLOGF_WARNING(...)
    #undef CLOGFLN_WARNING
    #define CLOGFLN_WARNING(...)
    #undef CLOG_PERROR_WARNING
    #define CLOG_PERROR_WARNING(...)
    #undef CLOG_PERRORF_WARNING
    #define CLOG_PERRORF_WARNING(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

        #undef CLOG_EXT
        #define CLOG_EXT(...)
        #undef CLOGLN_EXT
        #define CLOGLN_EXT(...)
        #undef CLOGF_EXT
        #define CLOGF_EXT(...)
        #undef CLOGFLN_EXT
        #define CLOGFLN_EXT(...)

        #undef CLOG_INF
        #define CLOG_INF(...)
        #undef CLOGLN_INF
        #define CLOGLN_INF(...)
        #undef CLOGF_INF
        #define CLOGF_INF(...)
        #undef CLOGFLN_INF
        #define CLOGFLN_INF(...)

        #undef CLOG_HEAD
        #define CLOG_HEAD(...)
        #undef CLOGLN_HEAD
        #define CLOGLN_HEAD(...)
        #undef CLOGF_HEAD
        #define CLOGF_HEAD(...)
        #undef CLOGFLN_HEAD
        #define CLOGFLN_HEAD(...)

        #undef CLOG_SUC
        #define CLOG_SUC(...)
        #undef CLOGLN_SUC
        #define CLOGLN_SUC(...)
        #undef CLOGF_SUC
        #define CLOGF_SUC(...)
        #undef CLOGFLN_SUC
        #define CLOGFLN_SUC(...)

        #undef CLOG_MON
        #define CLOG_MON(...)
        #undef CLOGLN_MON
        #define CLOGLN_MON(...)
        #undef CLOGF_MON
        #define CLOGF_MON(...)
        #undef CLOGFLN_MON
        #define CLOGFLN_MON(...)

        #undef CLOG_MNY
        #define CLOG_MNY(...)
        #undef CLOGLN_MNY
        #define CLOGLN_MNY(...)
        #undef CLOGF_MNY
        #define CLOGF_MNY(...)
        #undef CLOGFLN_MNY
        #define CLOGFLN_MNY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WARN
        #define CLOG_WARN(...)
        #undef CLOGLN_WARN
        #define CLOGLN_WARN(...)
        #undef CLOGF_WARN
        #define CLOGF_WARN(...)
        #undef CLOGFLN_WARN
        #define CLOGFLN_WARN(...)
        #undef CLOG_PERROR_WARN
        #define CLOG_PERROR_WARN(...)
        #undef CLOG_PERRORF_WARN
        #define CLOG_PERRORF_WARN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

        #undef CLOG_EX
        #define CLOG_EX(...)
        #undef CLOGLN_EX
        #define CLOGLN_EX(...)
        #undef CLOGF_EX
        #define CLOGF_EX(...)
        #undef CLOGFLN_EX
        #define CLOGFLN_EX(...)

        #undef CLOG_IF
        #define CLOG_IF(...)
        #undef CLOGLN_IF
        #define CLOGLN_IF(...)
        #undef CLOGF_IF
        #define CLOGF_IF(...)
        #undef CLOGFLN_IF
        #define CLOGFLN_IF(...)

        #undef CLOG_HD
        #define CLOG_HD(...)
        #undef CLOGLN_HD
        #define CLOGLN_HD(...)
        #undef CLOGF_HD
        #define CLOGF_HD(...)
        #undef CLOGFLN_HD
        #define CLOGFLN_HD(...)

        #undef CLOG_SC
        #define CLOG_SC(...)
        #undef CLOGLN_SC
        #define CLOGLN_SC(...)
        #undef CLOGF_SC
        #define CLOGF_SC(...)
        #undef CLOGFLN_SC
        #define CLOGFLN_SC(...)

        #undef CLOG_MN
        #define CLOG_MN(...)
        #undef CLOGLN_MN
        #define CLOGLN_MN(...)
        #undef CLOGF_MN
        #define CLOGF_MN(...)
        #undef CLOGFLN_MN
        #define CLOGFLN_MN(...)

        #undef CLOG_MY
        #define CLOG_MY(...)
        #undef CLOGLN_MY
        #define CLOGLN_MY(...)
        #undef CLOGF_MY
        #define CLOGF_MY(...)
        #undef CLOGFLN_MY
        #define CLOGFLN_MY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

        #undef CLOG_WN
        #define CLOG_WN(...)
        #undef CLOGLN_WN
        #define CLOGLN_WN(...)
        #undef CLOGF_WN
        #define CLOGF_WN(...)
        #undef CLOGFLN_WN
        #define CLOGFLN_WN(...)
        #undef CLOG_PERROR_WN
        #define CLOG_PERROR_WN(...)
        #undef CLOG_PERRORF_WN
        #define CLOG_PERRORF_WN(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)

    #undef FLOG_EXTRA
    #define FLOG_EXTRA(...)
    #undef FLOGLN_EXTRA
    #define FLOGLN_EXTRA(...)
    #undef FLOGF_EXTRA
    #define FLOGF_EXTRA(...)
    #undef FLOGFLN_EXTRA
    #define FLOGFLN_EXTRA(...)

    #undef FLOG_INFO
    #define FLOG_INFO(...)
    #undef FLOGLN_INFO
    #define FLOGLN_INFO(...)
    #undef FLOGF_INFO
    #define FLOGF_INFO(...)
    #undef FLOGFLN_INFO
    #define FLOGFLN_INFO(...)

    #undef FLOG_HEADER
    #define FLOG_HEADER(...)
    #undef FLOGLN_HEADER
    #define FLOGLN_HEADER(...)
    #undef FLOGF_HEADER
    #define FLOGF_HEADER(...)
    #undef FLOGFLN_HEADER
    #define FLOGFLN_HEADER(...)

    #undef FLOG_SUCCESS
    #define FLOG_SUCCESS(...)
    #undef FLOGLN_SUCCESS
    #define FLOGLN_SUCCESS(...)
    #undef FLOGF_SUCCESS
    #define FLOGF_SUCCESS(...)
    #undef FLOGFLN_SUCCESS
    #define FLOGFLN_SUCCESS(...)

    #undef FLOG_MONEY
    #define FLOG_MONEY(...)
    #undef FLOGLN_MONEY
    #define FLOGLN_MONEY(...)
    #undef FLOGF_MONEY
    #define FLOGF_MONEY(...)
    #undef FLOGFLN_MONEY
    #define FLOGFLN_MONEY(...)

    #undef FLOG_INPUT
    #define FLOG_INPUT(...)
    #undef FLOGLN_INPUT
    #define FLOGLN_INPUT(...)
    #undef FLOGF_INPUT
    #define FLOGF_INPUT(...)
    #undef FLOGFLN_INPUT
    #define FLOGFLN_INPUT(...)

    #undef FLOG_WARNING
    #define FLOG_WARNING(...)
    #undef FLOGLN_WARNING
    #define FLOGLN_WARNING(...)
    #undef FLOGF_WARNING
    #define FLOGF_WARNING(...)
    #undef FLOGFLN_WARNING
    #define FLOGFLN_WARNING(...)
    #undef FLOG_PERROR_WARNING
    #define FLOG_PERROR_WARNING(...)
    #undef FLOG_PERRORF_WARNING
    #define FLOG_PERRORF_WARNING(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

        #undef FLOG_EXT
        #define FLOG_EXT(...)
        #undef FLOGLN_EXT
        #define FLOGLN_EXT(...)
        #undef FLOGF_EXT
        #define FLOGF_EXT(...)
        #undef FLOGFLN_EXT
        #define FLOGFLN_EXT(...)

        #undef FLOG_INF
        #define FLOG_INF(...)
        #undef FLOGLN_INF
        #define FLOGLN_INF(...)
        #undef FLOGF_INF
        #define FLOGF_INF(...)
        #undef FLOGFLN_INF
        #define FLOGFLN_INF(...)

        #undef FLOG_HEAD
        #define FLOG_HEAD(...)
        #undef FLOGLN_HEAD
        #define FLOGLN_HEAD(...)
        #undef FLOGF_HEAD
        #define FLOGF_HEAD(...)
        #undef FLOGFLN_HEAD
        #define FLOGFLN_HEAD(...)

        #undef FLOG_SUC
        #define FLOG_SUC(...)
        #undef FLOGLN_SUC
        #define FLOGLN_SUC(...)
        #undef FLOGF_SUC
        #define FLOGF_SUC(...)
        #undef FLOGFLN_SUC
        #define FLOGFLN_SUC(...)

        #undef FLOG_MON
        #define FLOG_MON(...)
        #undef FLOGLN_MON
        #define FLOGLN_MON(...)
        #undef FLOGF_MON
        #define FLOGF_MON(...)
        #undef FLOGFLN_MON
        #define FLOGFLN_MON(...)

        #undef FLOG_MNY
        #define FLOG_MNY(...)
        #undef FLOGLN_MNY
        #define FLOGLN_MNY(...)
        #undef FLOGF_MNY
        #define FLOGF_MNY(...)
        #undef FLOGFLN_MNY
        #define FLOGFLN_MNY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WARN
        #define FLOG_WARN(...)
        #undef FLOGLN_WARN
        #define FLOGLN_WARN(...)
        #undef FLOGF_WARN
        #define FLOGF_WARN(...)
        #undef FLOGFLN_WARN
        #define FLOGFLN_WARN(...)
        #undef FLOG_PERROR_WARN
        #define FLOG_PERROR_WARN(...)
        #undef FLOG_PERRORF_WARN
        #define FLOG_PERRORF_WARN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

        #undef FLOG_EX
        #define FLOG_EX(...)
        #undef FLOGLN_EX
        #define FLOGLN_EX(...)
        #undef FLOGF_EX
        #define FLOGF_EX(...)
        #undef FLOGFLN_EX
        #define FLOGFLN_EX(...)

        #undef FLOG_IF
        #define FLOG_IF(...)
        #undef FLOGLN_IF
        #define FLOGLN_IF(...)
        #undef FLOGF_IF
        #define FLOGF_IF(...)
        #undef FLOGFLN_IF
        #define FLOGFLN_IF(...)

        #undef FLOG_HD
        #define FLOG_HD(...)
        #undef FLOGLN_HD
        #define FLOGLN_HD(...)
        #undef FLOGF_HD
        #define FLOGF_HD(...)
        #undef FLOGFLN_HD
        #define FLOGFLN_HD(...)

        #undef FLOG_SC
        #define FLOG_SC(...)
        #undef FLOGLN_SC
        #define FLOGLN_SC(...)
        #undef FLOGF_SC
        #define FLOGF_SC(...)
        #undef FLOGFLN_SC
        #define FLOGFLN_SC(...)

        #undef FLOG_MN
        #define FLOG_MN(...)
        #undef FLOGLN_MN
        #define FLOGLN_MN(...)
        #undef FLOGF_MN
        #define FLOGF_MN(...)
        #undef FLOGFLN_MN
        #define FLOGFLN_MN(...)

        #undef FLOG_MY
        #define FLOG_MY(...)
        #undef FLOGLN_MY
        #define FLOGLN_MY(...)
        #undef FLOGF_MY
        #define FLOGF_MY(...)
        #undef FLOGFLN_MY
        #define FLOGFLN_MY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

        #undef FLOG_WN
        #define FLOG_WN(...)
        #undef FLOGLN_WN
        #define FLOGLN_WN(...)
        #undef FLOGF_WN
        #define FLOGF_WN(...)
        #undef FLOGFLN_WN
        #define FLOGFLN_WN(...)
        #undef FLOG_PERROR_WN
        #define FLOG_PERROR_WN(...)
        #undef FLOG_PERRORF_WN
        #define FLOG_PERRORF_WN(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)

    #undef LOG_EXTRA
    #define LOG_EXTRA(...)
    #undef LOGLN_EXTRA
    #define LOGLN_EXTRA(...)
    #undef LOGF_EXTRA
    #define LOGF_EXTRA(...)
    #undef LOGFLN_EXTRA
    #define LOGFLN_EXTRA(...)

    #undef LOG_INFO
    #define LOG_INFO(...)
    #undef LOGLN_INFO
    #define LOGLN_INFO(...)
    #undef LOGF_INFO
    #define LOGF_INFO(...)
    #undef LOGFLN_INFO
    #define LOGFLN_INFO(...)

    #undef LOG_HEADER
    #define LOG_HEADER(...)
    #undef LOGLN_HEADER
    #define LOGLN_HEADER(...)
    #undef LOGF_HEADER
    #define LOGF_HEADER(...)
    #undef LOGFLN_HEADER
    #define LOGFLN_HEADER(...)

    #undef LOG_SUCCESS
    #define LOG_SUCCESS(...)
    #undef LOGLN_SUCCESS
    #define LOGLN_SUCCESS(...)
    #undef LOGF_SUCCESS
    #define LOGF_SUCCESS(...)
    #undef LOGFLN_SUCCESS
    #define LOGFLN_SUCCESS(...)

    #undef LOG_MONEY
    #define LOG_MONEY(...)
    #undef LOGLN_MONEY
    #define LOGLN_MONEY(...)
    #undef LOGF_MONEY
    #define LOGF_MONEY(...)
    #undef LOGFLN_MONEY
    #define LOGFLN_MONEY(...)

    #undef LOG_INPUT
    #define LOG_INPUT(...)
    #undef LOGLN_INPUT
    #define LOGLN_INPUT(...)
    #undef LOGF_INPUT
    #define LOGF_INPUT(...)
    #undef LOGFLN_INPUT
    #define LOGFLN_INPUT(...)

    #undef LOG_WARNING
    #define LOG_WARNING(...)
    #undef LOGLN_WARNING
    #define LOGLN_WARNING(...)
    #undef LOGF_WARNING
    #define LOGF_WARNING(...)
    #undef LOGFLN_WARNING
    #define LOGFLN_WARNING(...)
    #undef LOG_PERROR_WARNING
    #define LOG_PERROR_WARNING(...)
    #undef LOG_PERRORF_WARNING
    #define LOG_PERRORF_WARNING(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

        #undef LOG_EXT
        #define LOG_EXT(...)
        #undef LOGLN_EXT
        #define LOGLN_EXT(...)
        #undef LOGF_EXT
        #define LOGF_EXT(...)
        #undef LOGFLN_EXT
        #define LOGFLN_EXT(...)

        #undef LOG_INF
        #define LOG_INF(...)
        #undef LOGLN_INF
        #define LOGLN_INF(...)
        #undef LOGF_INF
        #define LOGF_INF(...)
        #undef LOGFLN_INF
        #define LOGFLN_INF(...)

        #undef LOG_HEAD
        #define LOG_HEAD(...)
        #undef LOGLN_HEAD
        #define LOGLN_HEAD(...)
        #undef LOGF_HEAD
        #define LOGF_HEAD(...)
        #undef LOGFLN_HEAD
        #define LOGFLN_HEAD(...)

        #undef LOG_SUC
        #define LOG_SUC(...)
        #undef LOGLN_SUC
        #define LOGLN_SUC(...)
        #undef LOGF_SUC
        #define LOGF_SUC(...)
        #undef LOGFLN_SUC
        #define LOGFLN_SUC(...)

        #undef LOG_MON
        #define LOG_MON(...)
        #undef LOGLN_MON
        #define LOGLN_MON(...)
        #undef LOGF_MON
        #define LOGF_MON(...)
        #undef LOGFLN_MON
        #define LOGFLN_MON(...)

        #undef LOG_MNY
        #define LOG_MNY(...)
        #undef LOGLN_MNY
        #define LOGLN_MNY(...)
        #undef LOGF_MNY
        #define LOGF_MNY(...)
        #undef LOGFLN_MNY
        #define LOGFLN_MNY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WARN
        #define LOG_WARN(...)
        #undef LOGLN_WARN
        #define LOGLN_WARN(...)
        #undef LOGF_WARN
        #define LOGF_WARN(...)
        #undef LOGFLN_WARN
        #define LOGFLN_WARN(...)
        #undef LOG_PERROR_WARN
        #define LOG_PERROR_WARN(...)
        #undef LOG_PERRORF_WARN
        #define LOG_PERRORF_WARN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

        #undef LOG_EX
        #define LOG_EX(...)
        #undef LOGLN_EX
        #define LOGLN_EX(...)
        #undef LOGF_EX
        #define LOGF_EX(...)
        #undef LOGFLN_EX
        #define LOGFLN_EX(...)

        #undef LOG_IF
        #define LOG_IF(...)
        #undef LOGLN_IF
        #define LOGLN_IF(...)
        #undef LOGF_IF
        #define LOGF_IF(...)
        #undef LOGFLN_IF
        #define LOGFLN_IF(...)

        #undef LOG_HD
        #define LOG_HD(...)
        #undef LOGLN_HD
        #define LOGLN_HD(...)
        #undef LOGF_HD
        #define LOGF_HD(...)
        #undef LOGFLN_HD
        #define LOGFLN_HD(...)

        #undef LOG_SC
        #define LOG_SC(...)
        #undef LOGLN_SC
        #define LOGLN_SC(...)
        #undef LOGF_SC
        #define LOGF_SC(...)
        #undef LOGFLN_SC
        #define LOGFLN_SC(...)

        #undef LOG_MN
        #define LOG_MN(...)
        #undef LOGLN_MN
        #define LOGLN_MN(...)
        #undef LOGF_MN
        #define LOGF_MN(...)
        #undef LOGFLN_MN
        #define LOGFLN_MN(...)

        #undef LOG_MY
        #define LOG_MY(...)
        #undef LOGLN_MY
        #define LOGLN_MY(...)
        #undef LOGF_MY
        #define LOGF_MY(...)
        #undef LOGFLN_MY
        #define LOGFLN_MY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

        #undef LOG_WN
        #define LOG_WN(...)
        #undef LOGLN_WN
        #define LOGLN_WN(...)
        #undef LOGF_WN
        #define LOGF_WN(...)
        #undef LOGFLN_WN
        #define LOGFLN_WN(...)
        #undef LOG_PERROR_WN
        #define LOG_PERROR_WN(...)
        #undef LOG_PERRORF_WN
        #define LOG_PERRORF_WN(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

        #undef EXTRA
        #define EXTRA(...)
        #undef EXTRALN
        #define EXTRALN(...)
        #undef EXTRAF
        #define EXTRAF(...)
        #undef EXTRAFLN
        #define EXTRAFLN(...)

        #undef INFO
        #define INFO(...)
        #undef INFOLN
        #define INFOLN(...)
        #undef INFOF
        #define INFOF(...)
        #undef INFOFLN
        #define INFOFLN(...)

        #undef HEADER
        #define HEADER(...)
        #undef HEADERLN
        #define HEADERLN(...)
        #undef HEADERF
        #define HEADERF(...)
        #undef HEADERFLN
        #define HEADERFLN(...)

        #undef SUCCESS
        #define SUCCESS(...)
        #undef SUCCESSLN
        #define SUCCESSLN(...)
        #undef SUCCESSF
        #define SUCCESSF(...)
        #undef SUCCESSFLN
        #define SUCCESSFLN(...)

        #undef MONEY
        #define MONEY(...)
        #undef MONEYLN
        #define MONEYLN(...)
        #undef MONEYF
        #define MONEYF(...)
        #undef MONEYFLN
        #define MONEYFLN(...)

        #undef INPUT
        #define INPUT(...)
        #undef INPUTLN
        #define INPUTLN(...)
        #undef INPUTF
        #define INPUTF(...)
        #undef INPUTFLN
        #define INPUTFLN(...)

        #undef WARNING
        #define WARNING(...)
        #undef WARNINGLN
        #define WARNINGLN(...)
        #undef WARNINGF
        #define WARNINGF(...)
        #undef WARNINGFLN
        #define WARNINGFLN(...)
        #undef WARNING_PERROR
        #define WARNING_PERROR(...)
        #undef WARNING_PERRORF
        #define WARNING_PERRORF(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_WARNING

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)

    #undef CLOG_EXTRA
    #define CLOG_EXTRA(...)
    #undef CLOGLN_EXTRA
    #define CLOGLN_EXTRA(...)
    #undef CLOGF_EXTRA
    #define CLOGF_EXTRA(...)
    #undef CLOGFLN_EXTRA
    #define CLOGFLN_EXTRA(...)

    #undef CLOG_INFO
    #define CLOG_INFO(...)
    #undef CLOGLN_INFO
    #define CLOGLN_INFO(...)
    #undef CLOGF_INFO
    #define CLOGF_INFO(...)
    #undef CLOGFLN_INFO
    #define CLOGFLN_INFO(...)

    #undef CLOG_HEADER
    #define CLOG_HEADER(...)
    #undef CLOGLN_HEADER
    #define CLOGLN_HEADER(...)
    #undef CLOGF_HEADER
    #define CLOGF_HEADER(...)
    #undef CLOGFLN_HEADER
    #define CLOGFLN_HEADER(...)

    #undef CLOG_SUCCESS
    #define CLOG_SUCCESS(...)
    #undef CLOGLN_SUCCESS
    #define CLOGLN_SUCCESS(...)
    #undef CLOGF_SUCCESS
    #define CLOGF_SUCCESS(...)
    #undef CLOGFLN_SUCCESS
    #define CLOGFLN_SUCCESS(...)

    #undef CLOG_MONEY
    #define CLOG_MONEY(...)
    #undef CLOGLN_MONEY
    #define CLOGLN_MONEY(...)
    #undef CLOGF_MONEY
    #define CLOGF_MONEY(...)
    #undef CLOGFLN_MONEY
    #define CLOGFLN_MONEY(...)

    #undef CLOG_INPUT
    #define CLOG_INPUT(...)
    #undef CLOGLN_INPUT
    #define CLOGLN_INPUT(...)
    #undef CLOGF_INPUT
    #define CLOGF_INPUT(...)
    #undef CLOGFLN_INPUT
    #define CLOGFLN_INPUT(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

        #undef CLOG_EXT
        #define CLOG_EXT(...)
        #undef CLOGLN_EXT
        #define CLOGLN_EXT(...)
        #undef CLOGF_EXT
        #define CLOGF_EXT(...)
        #undef CLOGFLN_EXT
        #define CLOGFLN_EXT(...)

        #undef CLOG_INF
        #define CLOG_INF(...)
        #undef CLOGLN_INF
        #define CLOGLN_INF(...)
        #undef CLOGF_INF
        #define CLOGF_INF(...)
        #undef CLOGFLN_INF
        #define CLOGFLN_INF(...)

        #undef CLOG_HEAD
        #define CLOG_HEAD(...)
        #undef CLOGLN_HEAD
        #define CLOGLN_HEAD(...)
        #undef CLOGF_HEAD
        #define CLOGF_HEAD(...)
        #undef CLOGFLN_HEAD
        #define CLOGFLN_HEAD(...)

        #undef CLOG_SUC
        #define CLOG_SUC(...)
        #undef CLOGLN_SUC
        #define CLOGLN_SUC(...)
        #undef CLOGF_SUC
        #define CLOGF_SUC(...)
        #undef CLOGFLN_SUC
        #define CLOGFLN_SUC(...)

        #undef CLOG_MON
        #define CLOG_MON(...)
        #undef CLOGLN_MON
        #define CLOGLN_MON(...)
        #undef CLOGF_MON
        #define CLOGF_MON(...)
        #undef CLOGFLN_MON
        #define CLOGFLN_MON(...)

        #undef CLOG_MNY
        #define CLOG_MNY(...)
        #undef CLOGLN_MNY
        #define CLOGLN_MNY(...)
        #undef CLOGF_MNY
        #define CLOGF_MNY(...)
        #undef CLOGFLN_MNY
        #define CLOGFLN_MNY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

        #undef CLOG_EX
        #define CLOG_EX(...)
        #undef CLOGLN_EX
        #define CLOGLN_EX(...)
        #undef CLOGF_EX
        #define CLOGF_EX(...)
        #undef CLOGFLN_EX
        #define CLOGFLN_EX(...)

        #undef CLOG_IF
        #define CLOG_IF(...)
        #undef CLOGLN_IF
        #define CLOGLN_IF(...)
        #undef CLOGF_IF
        #define CLOGF_IF(...)
        #undef CLOGFLN_IF
        #define CLOGFLN_IF(...)

        #undef CLOG_HD
        #define CLOG_HD(...)
        #undef CLOGLN_HD
        #define CLOGLN_HD(...)
        #undef CLOGF_HD
        #define CLOGF_HD(...)
        #undef CLOGFLN_HD
        #define CLOGFLN_HD(...)

        #undef CLOG_SC
        #define CLOG_SC(...)
        #undef CLOGLN_SC
        #define CLOGLN_SC(...)
        #undef CLOGF_SC
        #define CLOGF_SC(...)
        #undef CLOGFLN_SC
        #define CLOGFLN_SC(...)

        #undef CLOG_MN
        #define CLOG_MN(...)
        #undef CLOGLN_MN
        #define CLOGLN_MN(...)
        #undef CLOGF_MN
        #define CLOGF_MN(...)
        #undef CLOGFLN_MN
        #define CLOGFLN_MN(...)

        #undef CLOG_MY
        #define CLOG_MY(...)
        #undef CLOGLN_MY
        #define CLOGLN_MY(...)
        #undef CLOGF_MY
        #define CLOGF_MY(...)
        #undef CLOGFLN_MY
        #define CLOGFLN_MY(...)

        #undef CLOG_IN
        #define CLOG_IN(...)
        #undef CLOGLN_IN
        #define CLOGLN_IN(...)
        #undef CLOGF_IN
        #define CLOGF_IN(...)
        #undef CLOGFLN_IN
        #define CLOGFLN_IN(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)

    #undef FLOG_EXTRA
    #define FLOG_EXTRA(...)
    #undef FLOGLN_EXTRA
    #define FLOGLN_EXTRA(...)
    #undef FLOGF_EXTRA
    #define FLOGF_EXTRA(...)
    #undef FLOGFLN_EXTRA
    #define FLOGFLN_EXTRA(...)

    #undef FLOG_INFO
    #define FLOG_INFO(...)
    #undef FLOGLN_INFO
    #define FLOGLN_INFO(...)
    #undef FLOGF_INFO
    #define FLOGF_INFO(...)
    #undef FLOGFLN_INFO
    #define FLOGFLN_INFO(...)

    #undef FLOG_HEADER
    #define FLOG_HEADER(...)
    #undef FLOGLN_HEADER
    #define FLOGLN_HEADER(...)
    #undef FLOGF_HEADER
    #define FLOGF_HEADER(...)
    #undef FLOGFLN_HEADER
    #define FLOGFLN_HEADER(...)

    #undef FLOG_SUCCESS
    #define FLOG_SUCCESS(...)
    #undef FLOGLN_SUCCESS
    #define FLOGLN_SUCCESS(...)
    #undef FLOGF_SUCCESS
    #define FLOGF_SUCCESS(...)
    #undef FLOGFLN_SUCCESS
    #define FLOGFLN_SUCCESS(...)

    #undef FLOG_MONEY
    #define FLOG_MONEY(...)
    #undef FLOGLN_MONEY
    #define FLOGLN_MONEY(...)
    #undef FLOGF_MONEY
    #define FLOGF_MONEY(...)
    #undef FLOGFLN_MONEY
    #define FLOGFLN_MONEY(...)

    #undef FLOG_INPUT
    #define FLOG_INPUT(...)
    #undef FLOGLN_INPUT
    #define FLOGLN_INPUT(...)
    #undef FLOGF_INPUT
    #define FLOGF_INPUT(...)
    #undef FLOGFLN_INPUT
    #define FLOGFLN_INPUT(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

        #undef FLOG_EXT
        #define FLOG_EXT(...)
        #undef FLOGLN_EXT
        #define FLOGLN_EXT(...)
        #undef FLOGF_EXT
        #define FLOGF_EXT(...)
        #undef FLOGFLN_EXT
        #define FLOGFLN_EXT(...)

        #undef FLOG_INF
        #define FLOG_INF(...)
        #undef FLOGLN_INF
        #define FLOGLN_INF(...)
        #undef FLOGF_INF
        #define FLOGF_INF(...)
        #undef FLOGFLN_INF
        #define FLOGFLN_INF(...)

        #undef FLOG_HEAD
        #define FLOG_HEAD(...)
        #undef FLOGLN_HEAD
        #define FLOGLN_HEAD(...)
        #undef FLOGF_HEAD
        #define FLOGF_HEAD(...)
        #undef FLOGFLN_HEAD
        #define FLOGFLN_HEAD(...)

        #undef FLOG_SUC
        #define FLOG_SUC(...)
        #undef FLOGLN_SUC
        #define FLOGLN_SUC(...)
        #undef FLOGF_SUC
        #define FLOGF_SUC(...)
        #undef FLOGFLN_SUC
        #define FLOGFLN_SUC(...)

        #undef FLOG_MON
        #define FLOG_MON(...)
        #undef FLOGLN_MON
        #define FLOGLN_MON(...)
        #undef FLOGF_MON
        #define FLOGF_MON(...)
        #undef FLOGFLN_MON
        #define FLOGFLN_MON(...)

        #undef FLOG_MNY
        #define FLOG_MNY(...)
        #undef FLOGLN_MNY
        #define FLOGLN_MNY(...)
        #undef FLOGF_MNY
        #define FLOGF_MNY(...)
        #undef FLOGFLN_MNY
        #define FLOGFLN_MNY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

        #undef FLOG_EX
        #define FLOG_EX(...)
        #undef FLOGLN_EX
        #define FLOGLN_EX(...)
        #undef FLOGF_EX
        #define FLOGF_EX(...)
        #undef FLOGFLN_EX
        #define FLOGFLN_EX(...)

        #undef FLOG_IF
        #define FLOG_IF(...)
        #undef FLOGLN_IF
        #define FLOGLN_IF(...)
        #undef FLOGF_IF
        #define FLOGF_IF(...)
        #undef FLOGFLN_IF
        #define FLOGFLN_IF(...)

        #undef FLOG_HD
        #define FLOG_HD(...)
        #undef FLOGLN_HD
        #define FLOGLN_HD(...)
        #undef FLOGF_HD
        #define FLOGF_HD(...)
        #undef FLOGFLN_HD
        #define FLOGFLN_HD(...)

        #undef FLOG_SC
        #define FLOG_SC(...)
        #undef FLOGLN_SC
        #define FLOGLN_SC(...)
        #undef FLOGF_SC
        #define FLOGF_SC(...)
        #undef FLOGFLN_SC
        #define FLOGFLN_SC(...)

        #undef FLOG_MN
        #define FLOG_MN(...)
        #undef FLOGLN_MN
        #define FLOGLN_MN(...)
        #undef FLOGF_MN
        #define FLOGF_MN(...)
        #undef FLOGFLN_MN
        #define FLOGFLN_MN(...)

        #undef FLOG_MY
        #define FLOG_MY(...)
        #undef FLOGLN_MY
        #define FLOGLN_MY(...)
        #undef FLOGF_MY
        #define FLOGF_MY(...)
        #undef FLOGFLN_MY
        #define FLOGFLN_MY(...)

        #undef FLOG_IN
        #define FLOG_IN(...)
        #undef FLOGLN_IN
        #define FLOGLN_IN(...)
        #undef FLOGF_IN
        #define FLOGF_IN(...)
        #undef FLOGFLN_IN
        #define FLOGFLN_IN(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)

    #undef LOG_EXTRA
    #define LOG_EXTRA(...)
    #undef LOGLN_EXTRA
    #define LOGLN_EXTRA(...)
    #undef LOGF_EXTRA
    #define LOGF_EXTRA(...)
    #undef LOGFLN_EXTRA
    #define LOGFLN_EXTRA(...)

    #undef LOG_INFO
    #define LOG_INFO(...)
    #undef LOGLN_INFO
    #define LOGLN_INFO(...)
    #undef LOGF_INFO
    #define LOGF_INFO(...)
    #undef LOGFLN_INFO
    #define LOGFLN_INFO(...)

    #undef LOG_HEADER
    #define LOG_HEADER(...)
    #undef LOGLN_HEADER
    #define LOGLN_HEADER(...)
    #undef LOGF_HEADER
    #define LOGF_HEADER(...)
    #undef LOGFLN_HEADER
    #define LOGFLN_HEADER(...)

    #undef LOG_SUCCESS
    #define LOG_SUCCESS(...)
    #undef LOGLN_SUCCESS
    #define LOGLN_SUCCESS(...)
    #undef LOGF_SUCCESS
    #define LOGF_SUCCESS(...)
    #undef LOGFLN_SUCCESS
    #define LOGFLN_SUCCESS(...)

    #undef LOG_MONEY
    #define LOG_MONEY(...)
    #undef LOGLN_MONEY
    #define LOGLN_MONEY(...)
    #undef LOGF_MONEY
    #define LOGF_MONEY(...)
    #undef LOGFLN_MONEY
    #define LOGFLN_MONEY(...)

    #undef LOG_INPUT
    #define LOG_INPUT(...)
    #undef LOGLN_INPUT
    #define LOGLN_INPUT(...)
    #undef LOGF_INPUT
    #define LOGF_INPUT(...)
    #undef LOGFLN_INPUT
    #define LOGFLN_INPUT(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

        #undef LOG_EXT
        #define LOG_EXT(...)
        #undef LOGLN_EXT
        #define LOGLN_EXT(...)
        #undef LOGF_EXT
        #define LOGF_EXT(...)
        #undef LOGFLN_EXT
        #define LOGFLN_EXT(...)

        #undef LOG_INF
        #define LOG_INF(...)
        #undef LOGLN_INF
        #define LOGLN_INF(...)
        #undef LOGF_INF
        #define LOGF_INF(...)
        #undef LOGFLN_INF
        #define LOGFLN_INF(...)

        #undef LOG_HEAD
        #define LOG_HEAD(...)
        #undef LOGLN_HEAD
        #define LOGLN_HEAD(...)
        #undef LOGF_HEAD
        #define LOGF_HEAD(...)
        #undef LOGFLN_HEAD
        #define LOGFLN_HEAD(...)

        #undef LOG_SUC
        #define LOG_SUC(...)
        #undef LOGLN_SUC
        #define LOGLN_SUC(...)
        #undef LOGF_SUC
        #define LOGF_SUC(...)
        #undef LOGFLN_SUC
        #define LOGFLN_SUC(...)

        #undef LOG_MON
        #define LOG_MON(...)
        #undef LOGLN_MON
        #define LOGLN_MON(...)
        #undef LOGF_MON
        #define LOGF_MON(...)
        #undef LOGFLN_MON
        #define LOGFLN_MON(...)

        #undef LOG_MNY
        #define LOG_MNY(...)
        #undef LOGLN_MNY
        #define LOGLN_MNY(...)
        #undef LOGF_MNY
        #define LOGF_MNY(...)
        #undef LOGFLN_MNY
        #define LOGFLN_MNY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

        #undef LOG_EX
        #define LOG_EX(...)
        #undef LOGLN_EX
        #define LOGLN_EX(...)
        #undef LOGF_EX
        #define LOGF_EX(...)
        #undef LOGFLN_EX
        #define LOGFLN_EX(...)

        #undef LOG_IF
        #define LOG_IF(...)
        #undef LOGLN_IF
        #define LOGLN_IF(...)
        #undef LOGF_IF
        #define LOGF_IF(...)
        #undef LOGFLN_IF
        #define LOGFLN_IF(...)

        #undef LOG_HD
        #define LOG_HD(...)
        #undef LOGLN_HD
        #define LOGLN_HD(...)
        #undef LOGF_HD
        #define LOGF_HD(...)
        #undef LOGFLN_HD
        #define LOGFLN_HD(...)

        #undef LOG_SC
        #define LOG_SC(...)
        #undef LOGLN_SC
        #define LOGLN_SC(...)
        #undef LOGF_SC
        #define LOGF_SC(...)
        #undef LOGFLN_SC
        #define LOGFLN_SC(...)

        #undef LOG_MN
        #define LOG_MN(...)
        #undef LOGLN_MN
        #define LOGLN_MN(...)
        #undef LOGF_MN
        #define LOGF_MN(...)
        #undef LOGFLN_MN
        #define LOGFLN_MN(...)

        #undef LOG_MY
        #define LOG_MY(...)
        #undef LOGLN_MY
        #define LOGLN_MY(...)
        #undef LOGF_MY
        #define LOGF_MY(...)
        #undef LOGFLN_MY
        #define LOGFLN_MY(...)

        #undef LOG_IN
        #define LOG_IN(...)
        #undef LOGLN_IN
        #define LOGLN_IN(...)
        #undef LOGF_IN
        #define LOGF_IN(...)
        #undef LOGFLN_IN
        #define LOGFLN_IN(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

        #undef EXTRA
        #define EXTRA(...)
        #undef EXTRALN
        #define EXTRALN(...)
        #undef EXTRAF
        #define EXTRAF(...)
        #undef EXTRAFLN
        #define EXTRAFLN(...)

        #undef INFO
        #define INFO(...)
        #undef INFOLN
        #define INFOLN(...)
        #undef INFOF
        #define INFOF(...)
        #undef INFOFLN
        #define INFOFLN(...)

        #undef HEADER
        #define HEADER(...)
        #undef HEADERLN
        #define HEADERLN(...)
        #undef HEADERF
        #define HEADERF(...)
        #undef HEADERFLN
        #define HEADERFLN(...)

        #undef SUCCESS
        #define SUCCESS(...)
        #undef SUCCESSLN
        #define SUCCESSLN(...)
        #undef SUCCESSF
        #define SUCCESSF(...)
        #undef SUCCESSFLN
        #define SUCCESSFLN(...)

        #undef MONEY
        #define MONEY(...)
        #undef MONEYLN
        #define MONEYLN(...)
        #undef MONEYF
        #define MONEYF(...)
        #undef MONEYFLN
        #define MONEYFLN(...)

        #undef INPUT
        #define INPUT(...)
        #undef INPUTLN
        #define INPUTLN(...)
        #undef INPUTF
        #define INPUTF(...)
        #undef INPUTFLN
        #define INPUTFLN(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_INFO

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)

    #undef CLOG_EXTRA
    #define CLOG_EXTRA(...)
    #undef CLOGLN_EXTRA
    #define CLOGLN_EXTRA(...)
    #undef CLOGF_EXTRA
    #define CLOGF_EXTRA(...)
    #undef CLOGFLN_EXTRA
    #define CLOGFLN_EXTRA(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

        #undef CLOG_EXT
        #define CLOG_EXT(...)
        #undef CLOGLN_EXT
        #define CLOGLN_EXT(...)
        #undef CLOGF_EXT
        #define CLOGF_EXT(...)
        #undef CLOGFLN_EXT
        #define CLOGFLN_EXT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

        #undef CLOG_EX
        #define CLOG_EX(...)
        #undef CLOGLN_EX
        #define CLOGLN_EX(...)
        #undef CLOGF_EX
        #define CLOGF_EX(...)
        #undef CLOGFLN_EX
        #define CLOGFLN_EX(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)

    #undef FLOG_EXTRA
    #define FLOG_EXTRA(...)
    #undef FLOGLN_EXTRA
    #define FLOGLN_EXTRA(...)
    #undef FLOGF_EXTRA
    #define FLOGF_EXTRA(...)
    #undef FLOGFLN_EXTRA
    #define FLOGFLN_EXTRA(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

        #undef FLOG_EXT
        #define FLOG_EXT(...)
        #undef FLOGLN_EXT
        #define FLOGLN_EXT(...)
        #undef FLOGF_EXT
        #define FLOGF_EXT(...)
        #undef FLOGFLN_EXT
        #define FLOGFLN_EXT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

        #undef FLOG_EX
        #define FLOG_EX(...)
        #undef FLOGLN_EX
        #define FLOGLN_EX(...)
        #undef FLOGF_EX
        #define FLOGF_EX(...)
        #undef FLOGFLN_EX
        #define FLOGFLN_EX(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)

    #undef LOG_EXTRA
    #define LOG_EXTRA(...)
    #undef LOGLN_EXTRA
    #define LOGLN_EXTRA(...)
    #undef LOGF_EXTRA
    #define LOGF_EXTRA(...)
    #undef LOGFLN_EXTRA
    #define LOGFLN_EXTRA(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

        #undef LOG_EXT
        #define LOG_EXT(...)
        #undef LOGLN_EXT
        #define LOGLN_EXT(...)
        #undef LOGF_EXT
        #define LOGF_EXT(...)
        #undef LOGFLN_EXT
        #define LOGFLN_EXT(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

        #undef LOG_EX
        #define LOG_EX(...)
        #undef LOGLN_EX
        #define LOGLN_EX(...)
        #undef LOGF_EX
        #define LOGF_EX(...)
        #undef LOGFLN_EX
        #define LOGFLN_EX(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

        #undef EXTRA
        #define EXTRA(...)
        #undef EXTRALN
        #define EXTRALN(...)
        #undef EXTRAF
        #define EXTRAF(...)
        #undef EXTRAFLN
        #define EXTRAFLN(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_EXTRA

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef CLOG_DEBUG
    #define CLOG_DEBUG(...)
    #undef CLOGLN_DEBUG
    #define CLOGLN_DEBUG(...)
    #undef CLOGF_DEBUG
    #define CLOGF_DEBUG(...)
    #undef CLOGFLN_DEBUG
    #define CLOGFLN_DEBUG(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

        #undef CLOG_DBG
        #define CLOG_DBG(...)
        #undef CLOGLN_DBG
        #define CLOGLN_DBG(...)
        #undef CLOGF_DBG
        #define CLOGF_DBG(...)
        #undef CLOGFLN_DBG
        #define CLOGFLN_DBG(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

        #undef CLOG_DB
        #define CLOG_DB(...)
        #undef CLOGLN_DB
        #define CLOGLN_DB(...)
        #undef CLOGF_DB
        #define CLOGF_DB(...)
        #undef CLOGFLN_DB
        #define CLOGFLN_DB(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef FLOG_DEBUG
    #define FLOG_DEBUG(...)
    #undef FLOGLN_DEBUG
    #define FLOGLN_DEBUG(...)
    #undef FLOGF_DEBUG
    #define FLOGF_DEBUG(...)
    #undef FLOGFLN_DEBUG
    #define FLOGFLN_DEBUG(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

        #undef FLOG_DBG
        #define FLOG_DBG(...)
        #undef FLOGLN_DBG
        #define FLOGLN_DBG(...)
        #undef FLOGF_DBG
        #define FLOGF_DBG(...)
        #undef FLOGFLN_DBG
        #define FLOGFLN_DBG(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

        #undef FLOG_DB
        #define FLOG_DB(...)
        #undef FLOGLN_DB
        #define FLOGLN_DB(...)
        #undef FLOGF_DB
        #define FLOGF_DB(...)
        #undef FLOGFLN_DB
        #define FLOGFLN_DB(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

    #undef LOG_DEBUG
    #define LOG_DEBUG(...)
    #undef LOGLN_DEBUG
    #define LOGLN_DEBUG(...)
    #undef LOGF_DEBUG
    #define LOGF_DEBUG(...)
    #undef LOGFLN_DEBUG
    #define LOGFLN_DEBUG(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

        #undef LOG_DBG
        #define LOG_DBG(...)
        #undef LOGLN_DBG
        #define LOGLN_DBG(...)
        #undef LOGF_DBG
        #define LOGF_DBG(...)
        #undef LOGFLN_DBG
        #define LOGFLN_DBG(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

        #undef LOG_DB
        #define LOG_DB(...)
        #undef LOGLN_DB
        #define LOGLN_DB(...)
        #undef LOGF_DB
        #define LOGF_DB(...)
        #undef LOGFLN_DB
        #define LOGFLN_DB(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

        #undef DEBUG
        #define DEBUG(...)
        #undef DEBUGLN
        #define DEBUGLN(...)
        #undef DEBUGF
        #define DEBUGF(...)
        #undef DEBUGFLN
        #define DEBUGFLN(...)

    #endif


#elif CLOG_LEVEL == CLOG_LEVEL_DEBUG

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef CLOG_TRC
        #define CLOG_TRC(...)
        #undef CLOGLN_TRC
        #define CLOGLN_TRC(...)
        #undef CLOGF_TRC
        #define CLOGF_TRC(...)
        #undef CLOGFLN_TRC
        #define CLOGFLN_TRC(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef CLOG_TR
        #define CLOG_TR(...)
        #undef CLOGLN_TR
        #define CLOGLN_TR(...)
        #undef CLOGF_TR
        #define CLOGF_TR(...)
        #undef CLOGFLN_TR
        #define CLOGFLN_TR(...)

    #endif


    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef FLOG_TRC
        #define FLOG_TRC(...)
        #undef FLOGLN_TRC
        #define FLOGLN_TRC(...)
        #undef FLOGF_TRC
        #define FLOGF_TRC(...)
        #undef FLOGFLN_TRC
        #define FLOGFLN_TRC(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef FLOG_TR
        #define FLOG_TR(...)
        #undef FLOGLN_TR
        #define FLOGLN_TR(...)
        #undef FLOGF_TR
        #define FLOGF_TR(...)
        #undef FLOGFLN_TR
        #define FLOGFLN_TR(...)

    #endif


    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)


    #ifdef CLOG_ENABLE_SHORT_ALIASES

        #undef LOG_TRC
        #define LOG_TRC(...)
        #undef LOGLN_TRC
        #define LOGLN_TRC(...)
        #undef LOGF_TRC
        #define LOGF_TRC(...)
        #undef LOGFLN_TRC
        #define LOGFLN_TRC(...)

    #endif


    #ifdef CLOG_ENABLE_SHORTER_ALIASES

        #undef LOG_TR
        #define LOG_TR(...)
        #undef LOGLN_TR
        #define LOGLN_TR(...)
        #undef LOGF_TR
        #define LOGF_TR(...)
        #undef LOGFLN_TR
        #define LOGFLN_TR(...)

    #endif


    #ifdef CLOG_ENABLE_NAME_ALIASES

        #undef TRACE
        #define TRACE(...)
        #undef TRACELN
        #define TRACELN(...)
        #undef TRACEF
        #define TRACEF(...)
        #undef TRACEFLN
        #define TRACEFLN(...)

    #endif

#endif


// Globals.

_CLOG_DECLARE;


