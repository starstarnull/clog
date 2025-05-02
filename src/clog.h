
/**
 * =============
 * Clog C Header
 * =============
 *
 * Version: 0.0.1-1 beta
 *
 * Provides macros for color console and file logging.
 *
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
 * Clog C Header is a C header library of functions that can be included in a C
 * project to provide colored printing and console and file logging macros.
 * These functions can be configured to allow versatility of compile-time
 * logging function inclusion.
 *
 *
 * Features
 * ========
 *
 *      * Normal print functions.
 *      * Normal file print functions.
 *      * Print line functions.
 *      * Colored print functions.
 *      * Log level header print functions.
 *      * Colored log level header print functions.
 *      * Logging configuration.
 *      * Console logging.
 *      * File logging.
 *      * Dual logging.
 *      * Colored console logging.
 *      * Timestamps in logging.
 *
 *
 * Philosophy
 * ==========
 *
 * This logging library provides functions that are grouped and use letters to
 * tweak the function. The logs can be used during development and then
 * deactivated for release. Or they can be customized and controlled by the
 * developer.
 *
 *
 * Requirements
 * ============
 *
 *      * Currently uses standard C library.
 *
 *      * Currently developed and tested in Linux environment with the gcc
 *      compiler.
 *
 *
 * Usage
 * =====
 *
 * Macros with preceding underscores (like `_<macro`) are not intended to be
 * used by the user.
 *
 * Simply include the header file in your project and start calling the print
 * and logging functions. To customize the filename, use the `CLOG_INIT` macro
 * in the main function.
 *
 * To configure logging, use a separate configuration header file and include
 * before the clog header or make macro definitions before the include for the
 * log header file.
 *
 * There are several "groups" of functions.
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
 *  * "print" functions print to standard out.
 *
 *  * "cprint" functions print to standard out in the given color. The "c"
 * stands for "color" and indicates that the first argument is a ANZI color
 * string (provided via constant macros). The output has a color reset appended
 * to the end.
 *
 *  * "xxx" functions print to standard out using predefined colors and line
 *  headers.
 *
 *  * "clog" functions print to standard error using predefined colors,
 *  timestamps, and line headers and respond to log level and log color option
 *  configurations. The "c" here stands for "console" (yeah, I know it breaks
 *  the regular function rules -- it also stands for "color", but no color
 *  argument is required). The output has a color reset appended to the
 *  end.
 *
 *  * "flog" functions print to a predefined file using predefined colors,
 *  timestamps, and line headers and respond to log level configurations. The
 *  "f" stands for "file", but no file argument is needed.
 *
 *  * "log" functions log to standard error and a file using predefined colors,
 *  timestamps, and line headers (unless configured to do otherwise) and
 *  respond to log level and log color configurations.
 *
 * Each group has suffixes that determine the specific behavior of the
 * function.
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
 *
 * Rules
 * =====
 *
 * These are macros, but they are wrapped with brackets so they can be used
 * without brackets. For example, the following works:
 *
 *      if (err)
 *          PERROR_ERROR("This is an error")
 *
 * Since the macro functions are bracketed, the semicolon is not required. But
 * you can still use it, and it is recommended. For example, these statements
 * both work and are equivalent:
 *
 *      PRINT("hello");
 *      PRINT("hello")
 *
 * The hex functions use the variable name _clog_i
 *
 *
 *
 * Examples
 * ========
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *      `PRINTFLN("Your number is %d.", 22);`
 *
 *          Output: "Your number is 22\n"
 *
 *
 * Notes
 * =====
 *
 *  * `SYM_<level>` are redefinable after inclusion.
 *
 *
 * TODOs
 * =====
 *
 *  * Need to test in multiple files for any translation unit issues.
 *  * Need to finish basic manual testing.
 *  * Need to add tracing option.
 *  * Need to add example configuration header and configuration examples.
 *  * Spell out parameters.
 *  * Add format string parameters to format functions.
 *
 *
 * Future Plans
 * ============
 *
 *  * More configurations options.
 *
 *      * Time configurations (such as local time and formats).
 *      * Order configurations.
 *      * Color configurations.
 *      * Symbol/order configurations.
 *
 *  * Add verbosity functionality.
 *  * Add tracing option to all functions and/or add tracing mode.
 *  * Add documentation comments to each define (for IDE recognition).
 *  * Add aliases for function variations.
 *  * Add namespace mode (with defines in more limited namespace).
 *  * Add color hex and string hex (#ffffff) conversion functions.
 *  * Add option to set new log file instead of appending to file.
 *  * Add emoji mode.
 *  * Add exported symbols.
 *  * Add python library.
 *  * Add cpp library.
 *  * Port to Windows.
 *  * Add secret money function.
 *  * Need to consider backward compatability.
 *  * Need to consider critical level.
 *  * Add automated testing.
 *  * Consider reducing binary size with functions.
 *
 *
 * Exposed Constant Macros
 * =======================
 *
 * Modifiers
 * ---------
 *
 * C_RESET
 * C_BOLD
 * 
 * 3-bit Foreground Colors
 * -----------------------
 *
 * C_BLACK
 * C_RED
 * C_GREEN
 * C_YELLOW
 * C_BLUE
 * C_MAGENTA
 * C_CYAN
 * C_WHITE
 * 
 * 3-bit Background Colors
 * -----------------------
 *
 * C_B_BLACK
 * C_B_RED
 * C_B_GREEN
 * C_B_YELLOW
 * C_B_BLUE
 * C_B_MAGENTA
 * C_B_CYAN
 * C_B_WHITE
 * 
 * 4-bit Bright Foreground Colors
 * ------------------------------
 *
 * C_BR_BLACK
 * C_BR_RED
 * C_BR_GREEN
 * C_BR_YELLOW
 * C_BR_BLUE
 * C_BR_MAGENTA
 * C_BR_CYAN
 * C_BR_WHITE
 * 
 * 4-bit Bright Background Colors
 * ------------------------------
 *
 * C_B_BR_BLACK
 * C_B_BR_RED
 * C_B_BR_GREEN
 * C_B_BR_YELLOW
 * C_B_BR_BLUE
 * C_B_BR_MAGENTA
 * C_B_BR_CYAN
 * C_B_BR_WHITE
 * 
 * Other Colors
 * ------------
 *
 * C_ORANGE
 * C_B_ORANGE
 * 
 * Log Level Color Palette
 * -----------------------
 *
 * C_TRACE          Defaults to bright black
 * C_DEBUG          Defaults to cyan.          
 * C_EXTRA          Defaults to bright black
 * C_INFO           Defaults to blue
 * C_HEADER         Defaults to bold yellow
 * C_SUCCESS        Defaults to green
 * C_INPUT          Defaults to magenta
 * C_WARN           Defaults to orange
 * C_ERR            Defaults to red
 * C_FATAL          Defaults to bold red
 * 
 * Log Level Header Strings
 * ------------------------
 *
 * SYM_TRACE        Defaults to "[TRACE] "
 * SYM_DEBUG        Defaults to "[DEBUG] "
 * SYM_EXTRA        Defaults to "[.] "
 * SYM_INFO         Defaults to "[*] "
 * SYM_HEADER       Defaults to "[***] "
 * SYM_SUCCESS      Defaults to "[+] "
 * SYM_INPUT        Defaults to "[?] "
 * SYM_WARN         Defaults to "[!] "
 * SYM_ERR          Defaults to "[-] "
 * SYM_FATAL        Defaults to "[FATAL] "
 * 
 *
 * Exposed Function Macros
 * =======================
 *
 *
 *
 */

// Include guard.
#pragma once


// Includes.

// Standard libraries.

#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <string.h>


// Other libraries.

// None.


// Local libraries.

// None.


// Macros.

/**
 * ANZI Terminal Control Codes
 * ===========================
 *
 * `C_RESET` resets the terminal colors back to normal.
 * `C_BOLD` makes text bold.
 * `C_<color>` stands for color. 
 * `C_B_<color>` stands for background color.
 * `C_BR_<color>` stands for bright color.
 * `C_B_BR_<color>` stands for bright background color.
 */

// Modifiers.

#define C_RESET             "\x1b[0m"
#define C_BOLD              "\x1b[1m"

// 3-bit colors.

#define C_BLACK            "\x1b[30m"
#define C_RED              "\x1b[31m"
#define C_GREEN            "\x1b[32m"
#define C_YELLOW           "\x1b[33m"
#define C_BLUE             "\x1b[34m"
#define C_MAGENTA          "\x1b[35m"
#define C_CYAN             "\x1b[36m"
#define C_WHITE            "\x1b[37m"

#define C_B_BLACK          "\x1b[40m"
#define C_B_RED            "\x1b[41m"
#define C_B_GREEN          "\x1b[42m"
#define C_B_YELLOW         "\x1b[43m"
#define C_B_BLUE           "\x1b[44m"
#define C_B_MAGENTA        "\x1b[45m"
#define C_B_CYAN           "\x1b[46m"
#define C_B_WHITE          "\x1b[47m"

// 4-bit colors.

#define C_BR_BLACK         "\x1b[90m"
#define C_BR_RED           "\x1b[91m"
#define C_BR_GREEN         "\x1b[92m"
#define C_BR_YELLOW        "\x1b[93m"
#define C_BR_BLUE          "\x1b[94m"
#define C_BR_MAGENTA       "\x1b[95m"
#define C_BR_CYAN          "\x1b[96m"
#define C_BR_WHITE         "\x1b[97m"

#define C_B_BR_BLACK       "\x1b[100m"
#define C_B_BR_RED         "\x1b[101m"
#define C_B_BR_GREEN       "\x1b[102m"
#define C_B_BR_YELLOW      "\x1b[103m"
#define C_B_BR_BLUE        "\x1b[104m"
#define C_B_BR_MAGENTA     "\x1b[105m"
#define C_B_BR_CYAN        "\x1b[106m"
#define C_B_BR_WHITE       "\x1b[107m"


/**
 * 8-bit Color Codes
 * =================
 *
 * `C_8BIT(<n>)` is used for foreground colors.
 * `C_B_8BIT(<n>)` is used for background colors.
 *
 * `C_8BIT(<n>)` accepts a decimal number between 0 and 255.
 * `C_B_8BIT(<n>)` accepts a decimal number between 0 and 255.
 * 0 - 7 represent standard 3-bit colors.
 * 8 - 15 represent standard 4-bit bright colors.
 * 16 - 51 represent extended colors.
 * <extended color number> + 36 will lighten color.
 * 232 - 255 represent grayscale colors.
 */

// 8-bit colors.

#define C_8BIT(n)           "\x1b[38;5;" #n "m"

// 8-bit background colors.

#define C_B_8BIT(n)         "\x1b[48;5;" #n "m"


/**
 * 24-bit Color Codes
 * ==================
 *
 * 24-bit color codes use the traditional `red, green, blue` color model.
 *
 * `C_24BIT(<r>, <g>, <b>)` is used for foreground colors.
 * `C_B_24BIT(<r>, <g>, <b>)` is used for background colors.
 * 
 * `C_RBG(<r>, <g>, <b>)` is an alias of `C_24BIT(<r>, <g>, <b>)`.
 * `C_B_RBG(<r>, <g>, <b>)` is an alias of `C_B_24BIT(<r>, <g>, <b>)`.
 *
 * `C_24BIT(<r>, <g>, <b>)` accepts a decimal number between 0 and 255 for <r>,
 * <g>, and <b> parameters.
 * `C_B_24BIT(<r>, <g>, <b>)` accepts a decimal number between 0 and 255 for <r>,
 * <g>, and <b> parameters.
 *
 * 0 represents no color (i.e. black) and 255 represents the most of that 
 * color (i.e., most the red for the <r> parameter, the most green for the <g> 
 * parameter, and the most blue for the <b> parameter).
 */

// 24-bit colors.

#define C_24BIT(r, g, b)    "\x1b[38;2;" #r ";" #g ";" #b "m"      
#define C_RGB(r, g, b)      C_24BIT(r, g, b)

// 24-bit background colors.

#define C_B_24BIT(r, g, b)  "\x1b[48;2;" #r ";" #g ";" #b "m"      
#define C_B_RGB(r, g, b)    C_B_24BIT(r, g, b)

// Other colors.

#define C_ORANGE            C_24BIT(253, 198, 21)
#define C_B_ORANGE          C_B_24BIT(253, 198, 21)


/**
 * Color Palettes
 * ==============
 *
 * Color palettes are main available colors. Users can create their own 
 * palettes by defining MACROS that use other colors. For example:
 *
 *      #define MY_UI_COLOR C_RGB(128, 228, 288)
 */

// Palettes.

#define C_TRACE     C_BR_BLACK
#define C_DEBUG     C_CYAN
#define C_EXTRA     C_BR_BLACK
#define C_INFO      C_BLUE
#define C_HEADER    C_BOLD C_YELLOW
#define C_SUCCESS   C_GREEN
#define C_MONEY     C_GREEN
#define C_INPUT     C_MAGENTA
#define C_WARNING   C_ORANGE
#define C_ERROR     C_RED
#define C_FATAL     C_BOLD C_RED

// Aliases.

#define C_TR        C_TRACE  
#define C_DB        C_DEBUG  
#define C_EX        C_EXTRA  
#define C_IF        C_INFO   
#define C_HEAD      C_HEADER 
#define C_HD        C_HEADER 
#define C_SUC       C_SUCCESS
#define C_SC        C_SUCCESS
#define C_MON       C_MONEY
#define C_MNY       C_MONEY
#define C_MN        C_MONEY
#define C_IN        C_INPUT  
#define C_WARN      C_WARNING   
#define C_WN        C_WARNING   
#define C_ERR       C_ERROR    
#define C_ER        C_ERROR    
#define C_FAT       C_FATAL  
#define C_FT        C_FATAL  


/**
 * Logging Level Symbols
 * =====================
 *
 * These are the line headers for log-like printing and logging and are 
 * prepended to user strings when the appropriate function is used.
 */

#define CSYM_TRACE                  "[TRACE] "
#define CSYM_TRACE_1                "[T] "
#define CSYM_DEBUG                  "[DEBUG] "
#define CSYM_DEBUG_1                "[D] "
#define CSYM_EXTRA                  "[.] "
#define CSYM_INFO                   "[*] "
#define CSYM_HEADER                 "[***] "
#define CSYM_HEADER_1               "[#] "
#define CSYM_SUCCESS                "[+] "
#define CSYM_MONEY                  "[$] "
#define CSYM_LOTS_MONEY             "[$$$] "
#define CSYM_INPUT                  "[?] "
#define CSYM_WARNING                "[!] "
#define CSYM_ERROR                  "[-] "
#define CSYM_FATAL                  "[FATAL] "
#define CSYM_FATAL_1                "[F] "

// Aliases.

#define CSYM_TR                     CSYM_TRACE
#define CSYM_TR1                    CSYM_TRACE_1
#define CSYM_DB                     CSYM_DEBUG
#define CSYM_DB1                    CSYM_DEBUG_1
#define CSYM_EX                     CSYM_EXTRA
#define CSYM_IF                     CSYM_INFO
#define CSYM_HEAD                   CSYM_HEADER
#define CSYM_HD                     CSYM_HEADER
#define CSYM_HEAD1                  CSYM_HEADER_1
#define CSYM_HD1                    CSYM_HEADER_1
#define CSYM_SUC                    CSYM_SUCCESS
#define CSYM_SC                     CSYM_SUCCESS
#define CSYM_MON                    CSYM_MONEY
#define CSYM_MNY                    CSYM_MONEY
#define CSYM_MN                     CSYM_MONEY
#define CSYM_LOTS                   CSYM_LOTS_MONEY
#define CSYM_LM                     CSYM_LOTS_MONEY
#define CSYM_IN                     CSYM_INPUT
#define CSYM_WARN                   CSYM_WARNING
#define CSYM_WN                     CSYM_WARNING
#define CSYM_ERR                    CSYM_ERROR
#define CSYM_ER                     CSYM_ERROR
#define CSYM_FAT                    CSYM_FATAL
#define CSYM_FT                     CSYM_FATAL
#define CSYM_FAT1                   CSYM_FATAL_1
#define CSYM_FT1                    CSYM_FATAL_1


/**
 * "fprint" Functions
 * ================
 *
 * The "fprint" series of macros are the base functions used in the other
 * macro functions. They are for printing to a given file pointer. For this 
 * implementation, they use the `fprintf` function.
 *
 * The first parameter of all these functions is the `FILE*` pointer (which \
 * may be `stdout` or `stderr` or a `FILE*` to a file`) to write to. 
 * 
 * There are several function-like macros available:
 *
 *      FPRINT(FILE*, char* string)
 *      FPRINTLN(FILE*, char* string)
 *      FPRINTF(FILE*, char* format_string, ...)
 *      FPRINTFLN(FILE*, char* format_string, ...)
 *      FPRINT_HEX(FILE*, void* buffer, size_t size)
 *      FPRINTLN_HEX(FILE*, void* buffer, size_t size)
 *      FPRINT_WIDE_HEX(FILE*, void* buffer, size_t size)
 *      FPRINTLN_WIDE_HEX(FILE*, void* buffer, size_t size)
 *      FPERROR(FILE*, char* string)
 *      FPERRORF(FILE*, char* format_string, ...)
 *
 * Examples
 * --------
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
 *  Descriptions of each function can be found at the top comment of this file.
 */

#define FPRINT(f, s)                { fprintf(f, "%s", s); }
#define FPRINTLN(f, s)              { fprintf(f, "%s\n", s); }
#define FPRINTF(f, ...)             { fprintf(f, __VA_ARGS__); }
#define FPRINTFLN(f, ...)           { \
                                        fprintf(f, __VA_ARGS__); \
                                        fprintf(f, "\n"); \
                                    }
#define FPRINT_HEX(f, s, l)         { \
                                        for ( \
                                            size_t _clog_i = 0;  \
                                            _clog_i < l;  \
                                            ++_clog_i \
                                        ) \
                                            fprintf( \
                                                f, \
                                                "%02x", \
                                                ((unsigned char*) s)[_clog_i] \
                                            ); \
                                    }
#define FPRINTLN_HEX(f, s, l)       { FPRINT_HEX(f, s, l); fprintf(f, "\n"); }
#define FPRINT_WIDE_HEX(f, s, l)    { \
                                        for ( \
                                            size_t _clog_i = 0;  \
                                            _clog_i < l;  \
                                            ++_clog_i \
                                        ) \
                                            fprintf( \
                                                f, \
                                                "0x%02x ", \
                                                ((unsigned char*) s)[_clog_i] \
                                            ); \
                                    }
#define FPRINTLN_WIDE_HEX(f, s, l)  { \
                                        FPRINT_WIDE_HEX(f, s, l); \
                                        fprintf(f, "\n"); \
                                    }
#define FPERROR(f, s)               { \
                                        FPRINT(f, s); \
                                        FPRINTFLN(f, ": %s", strerror(errno)); \
                                    }
#define FPERRORF(f, ...)            { \
                                        FPRINTF(f, __VA_ARGS__); \
                                        FPRINTFLN(f, ": %s", strerror(errno)); \
                                    }


/**
 * "cfprint" Functions
 * ===================
 *
 * The "cfprint" series of macros are the base functions used in the other
 * macro functions and are for colored printing to the given file pointer. 
 *
 * The first parameter of all these functions is the color to print the text as
 * by prepending the string argument with the ANZI terminal color code and by
 * resetting the color output at the end.  The second parameter is the `FILE*` 
 * pointer (which may be `stdout` or `stderr` or a `FILE*` to a file`) to 
 * write to. 
 * 
 * There are several function-like macros available:
 *
 *      CFPRINT(char* color_string, FILE*, char* string)
 *      CFPRINTLN(char* color_string, FILE*, char* string)
 *      CFPRINTF(char* color_string, FILE*, char* format_string, ...)
 *      CFPRINTFLN(char* color_string, FILE*, char* format_string, ...)
 *      CFPRINT_HEX(char* color_string, FILE*, void* buffer, size_t size)
 *      CFPRINTLN_HEX(char* color_string, FILE*, void* buffer, size_t size)
 *      CFPRINT_WIDE_HEX(char* color_string, FILE*, void* buffer, size_t size)
 *      CFPRINTLN_WIDE_HEX(char* color_string, FILE*, void* buffer, size_t size)
 *      CFPERROR(char* color_string, FILE*, char* string)
 *      CFPERRORF(char* color_string, FILE*, char* format_string, ...)
 *
 * Examples
 * --------
 *
 *      `CFPRINT(C_RED, stdout, "Hello"); printf("you");`
 *
 *          Output: `\033[31mHelloyou\033[0m` (Red "Helloyou")
 *
 *      `int i = 15; CFPRINT_HEX(C_RED, stdout, &i, sizeof(int));` 
 *
 *          Output: `\033[31m0f000000\033[0m`. (Red "0f000000")
 *      
 *  Descriptions of each function can be found at the top comment of this file.
 */

#define CFPRINT(c, f, s)                FPRINT(f, c s C_RESET);
#define CFPRINTLN(c, f, s)              FPRINTLN(f, c s C_RESET);
#define CFPRINTF(c, f, ...)             { \
                                            FPRINTF(f, c __VA_ARGS__); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPRINTFLN(c, f, ...)           { \
                                            FPRINTFLN(f, c __VA_ARGS__); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPRINT_HEX(c, f, s, l)         { \
                                            FPRINT(f, c); \
                                            FPRINT_HEX(f, s, l); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPRINTLN_HEX(c, f, s, l)       { \
                                            FPRINT(f, c); \
                                            FPRINTLN_HEX(f, s, l); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPRINT_WIDE_HEX(c, f, s, l)    { \
                                            FPRINT(f, c); \
                                            FPRINT_WIDE_HEX(f, s, l); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPRINTLN_WIDE_HEX(c, f, s, l)  { \
                                            FPRINT(f, c); \
                                            FPRINTLN_WIDE_HEX(f, s, l); \
                                            FPRINT(f, C_RESET); \
                                        }
#define CFPERROR(c, f, s)               { \
                                            FPRINT(f, c s); \
                                            FPRINTFLN( \
                                                f, \
                                                ": %s" C_RESET, \
                                                strerror(errno) \
                                            ); \
                                        }
#define CFPERRORF(c, f, ...)            { \
                                            FPRINTF(f, c __VA_ARGS__); \
                                            FPRINTFLN( \
                                                f, \
                                                ": %s" C_RESET, \
                                                strerror(errno) \
                                            ); \
                                        }


/**
 * "print" Functions
 * =================
 *
 * The "print" series are for printing to standard out. 
 *
 * There are several function-like macros available:
 *
 *      PRINT(char* string)
 *      PRINTLN(char* string)
 *      PRINTF(char* format_string, ...)
 *      PRINTFLN(char* format_string, ...)
 *      PRINT_HEX(void* buffer, size_t size)
 *      PRINTLN_HEX(void* buffer, size_t size)
 *      PRINT_WIDE_HEX(void* buffer, size_t size)
 *      PRINTLN_WIDE_HEX(void* buffer, size_t size)
 *      PERROR(char* string)
 *      PERRORF(char* format_string, ...)
 *
 * Examples
 * --------
 *
 *      `PRINT("Hello"); printf("you");`
 *
 *          Output: `Helloyou`
 *
 *      `int i = 15; PRINT_HEX(&i, sizeof(int));` 
 *
 *          Output: `0f000000`. 
 *
 *
 *  "print_level" Functions
 *  =======================
 *
 *  Additionally, there are "print_level" functions which add a symbol header
 *  to each line based on the level selected. 
 *
 *  ** Note: These will ALWAYS print regardless of logging level. For
 *  controlling prints using levels, see "CLOG" and "LOG" functions.
 *
 * There are several of these function-like macros available:
 *
 *      PRINT_TRACE(char* string)
 *      PRINTLN_TRACE(char* string)
 *      PRINTF_TRACE(char* format_string, ...)
 *      PRINTFLN_TRACE(char* format_string, ...)
 *
 *      PRINT_DEBUG(char* string)
 *      PRINTLN_DEBUG(char* string)
 *      PRINTF_DEBUG(char* format_string, ...)
 *      PRINTFLN_DEBUG(char* format_string, ...)
 *
 *      PRINT_EXTRA(char* string)
 *      PRINTLN_EXTRA(char* string)
 *      PRINTF_EXTRA(char* format_string, ...)
 *      PRINTFLN_EXTRA(char* format_string, ...)
 *
 *      PRINT_INFO(char* string)
 *      PRINTLN_INFO(char* string)
 *      PRINTF_INFO(char* format_string, ...)
 *      PRINTFLN_INFO(char* format_string, ...)
 *
 *      PRINT_HEADER(char* string)
 *      PRINTLN_HEADER(char* string)
 *      PRINTF_HEADER(char* format_string, ...)
 *      PRINTFLN_HEADER(char* format_string, ...)
 *
 *      PRINT_SUCCESS(char* string)
 *      PRINTLN_SUCCESS(char* string)
 *      PRINTF_SUCCESS(char* format_string, ...)
 *      PRINTFLN_SUCCESS(char* format_string, ...)
 *
 *      PRINT_INPUT(char* string)
 *      PRINTLN_INPUT(char* string)
 *      PRINTF_INPUT(char* format_string, ...)
 *      PRINTFLN_INPUT(char* format_string, ...)
 *
 *      PRINT_WARNING(char* string)
 *      PRINTLN_WARNING(char* string)
 *      PRINTF_WARNING(char* format_string, ...)
 *      PRINTFLN_WARNING(char* format_string, ...)
 *
 *      PRINT_ERROR(char* string)
 *      PRINTLN_ERROR(char* string)
 *      PRINTF_ERROR(char* format_string, ...)
 *      PRINTFLN_ERROR(char* format_string, ...)
 *
 *      PERROR_ERROR(char* string)
 *      PERRORF_ERROR(char* format_string, ...)
 *
 *      PRINT_FATAL(char* string)
 *      PRINTLN_FATAL(char* string)
 *      PRINTF_FATAL(char* format_string, ...)
 *      PRINTFLN_FATAL(char* format_string, ...)
 *
 *      PERROR_FATAL(char* string)
 *      PERRORF_FATAL(char* format_string, ...)
 *
 * Examples
 * --------
 *
 *      `PRINT_INFO("Hello"); printf("you");`
 *
 *          Output: `[*] Helloyou`
 *
 *  Descriptions of each function can be found at the top comment of this file.
 */

#define PRINT(s)                    FPRINT(stdout, s)
#define PRINTLN(s)                  FPRINTLN(stdout, s)
#define PRINTF(...)                 FPRINTF(stdout, __VA_ARGS__)
#define PRINTFLN(...)               FPRINTFLN(stdout, __VA_ARGS__)
#define PRINT_HEX(s, l)             FPRINT_HEX(stdout, s, l)
#define PRINTLN_HEX(s, l)           FPRINTLN_HEX(stdout, s, l)
#define PRINT_WIDE_HEX(s, l)        FPRINT_WIDE_HEX(stdout, s, l)
#define PRINTLN_WIDE_HEX(s, l)      FPRINTLN_WIDE_HEX(stdout, s, l)
#define PERROR(s)                   FPERROR(stdout, s)
#define PERRORF(...)                FPERRORF(stdout, __VA_ARGS__)

#define PRINT_TRACE(s)              PRINT(CSYM_TRACE s)
#define PRINTLN_TRACE(s)            PRINTLN(CSYM_TRACE s)
#define PRINTF_TRACE(...)           PRINTF(CSYM_TRACE __VA_ARGS__)
#define PRINTFLN_TRACE(...)         PRINTFLN(CSYM_TRACE __VA_ARGS__)

#define PRINT_DEBUG(s)              PRINT(CSYM_DEBUG s)
#define PRINTLN_DEBUG(s)            PRINTLN(CSYM_DEBUG s)
#define PRINTF_DEBUG(...)           PRINTF(CSYM_DEBUG __VA_ARGS__)
#define PRINTFLN_DEBUG(...)         PRINTFLN(CSYM_DEBUG __VA_ARGS__)

#define PRINT_EXTRA(s)              PRINT(CSYM_EXTRA s)
#define PRINTLN_EXTRA(s)            PRINTLN(CSYM_EXTRA s)
#define PRINTF_EXTRA(...)           PRINTF(CSYM_EXTRA __VA_ARGS__)
#define PRINTFLN_EXTRA(...)         PRINTFLN(CSYM_EXTRA __VA_ARGS__)

#define PRINT_INFO(s)               PRINT(CSYM_INFO s)
#define PRINTLN_INFO(s)             PRINTLN(CSYM_INFO s)
#define PRINTF_INFO(...)            PRINTF(CSYM_INFO __VA_ARGS__)
#define PRINTFLN_INFO(...)          PRINTFLN(CSYM_INFO __VA_ARGS__)

#define PRINT_HEADER(s)             PRINT(CSYM_HEADER s)
#define PRINTLN_HEADER(s)           PRINTLN(CSYM_HEADER s)
#define PRINTF_HEADER(...)          PRINTF(CSYM_HEADER __VA_ARGS__)
#define PRINTFLN_HEADER(...)        PRINTFLN(CSYM_HEADER __VA_ARGS__)

#define PRINT_SUCCESS(s)            PRINT(CSYM_SUCCESS s)
#define PRINTLN_SUCCESS(s)          PRINTLN(CSYM_SUCCESS s)
#define PRINTF_SUCCESS(...)         PRINTF(CSYM_SUCCESS __VA_ARGS__)
#define PRINTFLN_SUCCESS(...)       PRINTFLN(CSYM_SUCCESS __VA_ARGS__)

#define PRINT_INPUT(s)              PRINT(CSYM_INPUT s)
#define PRINTLN_INPUT(s)            PRINTLN(CSYM_INPUT s)
#define PRINTF_INPUT(...)           PRINTF(CSYM_INPUT __VA_ARGS__)
#define PRINTFLN_INPUT(...)         PRINTFLN(CSYM_INPUT __VA_ARGS__)

#define PRINT_WARNING(s)            PRINT(CSYM_WARN s)
#define PRINTLN_WARNING(s)          PRINTLN(CSYM_WARN s)
#define PRINTF_WARNING(...)         PRINTF(CSYM_WARN __VA_ARGS__)
#define PRINTFLN_WARNING(...)       PRINTFLN(CSYM_WARN __VA_ARGS__)
#define PERROR_WARNING(s)           PERROR(CSYM_WARN s)
#define PERRORF_WARNING(...)        PERRORF(CSYM_WARN __VA_ARGS__)

#define PRINT_ERROR(s)              PRINT(CSYM_ERR s)
#define PRINTLN_ERROR(s)            PRINTLN(CSYM_ERR s)
#define PRINTF_ERROR(...)           PRINTF(CSYM_ERR __VA_ARGS__)
#define PRINTFLN_ERROR(...)         PRINTFLN(CSYM_ERR __VA_ARGS__)
#define PERROR_ERROR(s)             PERROR(CSYM_ERR s)
#define PERRORF_ERROR(...)          PERRORF(CSYM_ERR __VA_ARGS__)

#define PRINT_FATAL(s)              PRINT(CSYM_FATAL s)
#define PRINTLN_FATAL(s)            PRINTLN(CSYM_FATAL s)
#define PRINTF_FATAL(...)           PRINTF(CSYM_FATAL __VA_ARGS__)
#define PRINTFLN_FATAL(...)         PRINTFLN(CSYM_FATAL __VA_ARGS__)
#define PERROR_FATAL(s)             PERROR(CSYM_FATAL s)
#define PERRORF_FATAL(...)          PERRORF(CSYM_FATAL __VA_ARGS__)

// Aliases.

#define PRINT_TR(s)                 PRINT_TRACE(s)       
#define PRINTLN_TR(s)               PRINTLN_TRACE(s)     
#define PRINTF_TR(...)              PRINTF_TRACE(__VA_ARGS__)    
#define PRINTFLN_TR(...)            PRINTFLN_TRACE(__VA_ARGS__)  
                                                            
#define PRINT_DB(s)                 PRINT_DEBUG(s)       
#define PRINTLN_DB(s)               PRINTLN_DEBUG(s)     
#define PRINTF_DB(...)              PRINTF_DEBUG(__VA_ARGS__)    
#define PRINTFLN_DB(...)            PRINTFLN_DEBUG(__VA_ARGS__)  
                                                            
#define PRINT_EX(s)                 PRINT_EXTRA(s)       
#define PRINTLN_EX(s)               PRINTLN_EXTRA(s)     
#define PRINTF_EX(...)              PRINTF_EXTRA(__VA_ARGS__)    
#define PRINTFLN_EX(...)            PRINTFLN_EXTRA(__VA_ARGS__)  
                                                            
#define PRINT_IF(s)                 PRINT_INFO(s)        
#define PRINTLN_IF(s)               PRINTLN_INFO(s)      
#define PRINTF_IF(...)              PRINTF_INFO(__VA_ARGS__)     
#define PRINTFLN_IF(...)            PRINTFLN_INFO(__VA_ARGS__)   
                                                           
#define PRINT_HEAD(s)               PRINT_HEADER(s)      
#define PRINTLN_HEAD(s)             PRINTLN_HEADER(s)    
#define PRINTF_HEAD(...)            PRINTF_HEADER(__VA_ARGS__)   
#define PRINTFLN_HEAD(...)          PRINTFLN_HEADER(__VA_ARGS__) 
                                                            
#define PRINT_HD(s)                 PRINT_HEADER(s)      
#define PRINTLN_HD(s)               PRINTLN_HEADER(s)    
#define PRINTF_HD(...)              PRINTF_HEADER(__VA_ARGS__)   
#define PRINTFLN_HD(...)            PRINTFLN_HEADER(__VA_ARGS__) 
                                                             
#define PRINT_SUC(s)                PRINT_SUCCESS(s)     
#define PRINTLN_SUC(s)              PRINTLN_SUCCESS(s)   
#define PRINTF_SUC(...)             PRINTF_SUCCESS(__VA_ARGS__)  
#define PRINTFLN_SUC(...)           PRINTFLN_SUCCESS(__VA_ARGS__)
                                                            
#define PRINT_SC(s)                 PRINT_SUCCESS(s)     
#define PRINTLN_SC(s)               PRINTLN_SUCCESS(s)   
#define PRINTF_SC(...)              PRINTF_SUCCESS(__VA_ARGS__)  
#define PRINTFLN_SC(...)            PRINTFLN_SUCCESS(__VA_ARGS__)
                                                            
#define PRINT_IN(s)                 PRINT_INPUT(s)       
#define PRINTLN_IN(s)               PRINTLN_INPUT(s)     
#define PRINTF_IN(...)              PRINTF_INPUT(__VA_ARGS__)    
#define PRINTFLN_IN(...)            PRINTFLN_INPUT(__VA_ARGS__)  
                                                            
#define PRINT_WARN(s)               PRINT_WARNING(s)     
#define PRINTLN_WARN(s)             PRINTLN_WARNING(s)   
#define PRINTF_WARN(...)            PRINTF_WARNING(__VA_ARGS__)  
#define PRINTFLN_WARN(...)          PRINTFLN_WARNING(__VA_ARGS__)
#define PERROR_WARN(s)              PERROR_WARNING(s)      
#define PERRORF_WARN(...)           PERRORF_WARNING(__VA_ARGS__)   
                                                            
#define PRINT_WN(s)                 PRINT_WARNING(s)     
#define PRINTLN_WN(s)               PRINTLN_WARNING(s)   
#define PRINTF_WN(...)              PRINTF_WARNING(__VA_ARGS__)  
#define PRINTFLN_WN(...)            PRINTFLN_WARNING(__VA_ARGS__)
#define PERROR_WN(s)                PERROR_WARNING(s)      
#define PERRORF_WN(...)             PERRORF_WARNING(__VA_ARGS__)   
                                                            
#define PRINT_ERR(s)                PRINT_ERROR(s)       
#define PRINTLN_ERR(s)              PRINTLN_ERROR(s)     
#define PRINTF_ERR(...)             PRINTF_ERROR(__VA_ARGS__)    
#define PRINTFLN_ERR(...)           PRINTFLN_ERROR(__VA_ARGS__)  
#define PERROR_ERR(s)               PERROR_ERROR(s)      
#define PERRORF_ERR(...)            PERRORF_ERROR(__VA_ARGS__)   
                                                            
#define PRINT_ER(s)                 PRINT_ERROR(s)       
#define PRINTLN_ER(s)               PRINTLN_ERROR(s)     
#define PRINTF_ER(...)              PRINTF_ERROR(__VA_ARGS__)    
#define PRINTFLN_ER(...)            PRINTFLN_ERROR(__VA_ARGS__)  
#define PERROR_ER(s)                PERROR_ERROR(s)      
#define PERRORF_ER(...)             PERRORF_ERROR(__VA_ARGS__)   
                                                            
#define PRINT_FAT(s)                PRINT_FATAL(s)       
#define PRINTLN_FAT(s)              PRINTLN_FATAL(s)     
#define PRINTF_FAT(...)             PRINTF_FATAL(__VA_ARGS__)    
#define PRINTFLN_FAT(...)           PRINTFLN_FATAL(__VA_ARGS__)  
#define PERROR_FAT(s)               PERROR_FATAL(s)      
#define PERRORF_FAT(...)            PERRORF_FATAL(__VA_ARGS__)   

#define PRINT_FT(s)                 PRINT_FATAL(s)       
#define PRINTLN_FT(s)               PRINTLN_FATAL(s)     
#define PRINTF_FT(...)              PRINTF_FATAL(__VA_ARGS__)    
#define PRINTFLN_FT(...)            PRINTFLN_FATAL(__VA_ARGS__)  
#define PERROR_FT(s)                PERROR_FATAL(s)      
#define PERRORF_FT(...)             PERRORF_FATAL(__VA_ARGS__)   


/**
 * "cprint" Functions
 * ==================
 *
 * The "cprint" series of macros are for colored printing to standard out. 
 *
 * The first parameter of all these functions is the color to print the text as
 * by prepending the string argument with the ANZI terminal color code and by
 * resetting the color output at the end.
 * 
 * There are several function-like macros available:
 *
 *      CPRINT(char* color_string, char* string)
 *      CPRINTLN(char* color_string, char* string)
 *      CPRINTF(char* color_string, char* format_string, ...)
 *      CPRINTFLN(char* color_string, char* format_string, ...)
 *      CPRINT_HEX(char* color_string, void* buffer, size_t size)
 *      CPRINTLN_HEX(char* color_string, void* buffer, size_t size)
 *      CPRINT_WIDE_HEX(char* color_string, void* buffer, size_t size)
 *      CPRINTLN_WIDE_HEX(char* color_string, void* buffer, size_t size)
 *      CPERROR(char* color_string, char* string)
 *      CPERRORF(char* color_string, char* format_string, ...)
 *
 * Examples
 * --------
 *
 *      `CFPRINT(C_RED, "Hello"); printf("you");`
 *
 *          Output: `\033[31mHelloyou\033[0m` (Red "Helloyou")
 *
 *      `int i = 15; CFPRINT_HEX(C_RED, &i, sizeof(int));` 
 *
 *          Output: `\033[31m0f000000\033[0m`. (Red "0f000000")
 *      
 *
 *  "cprint_level" Functions
 *  ========================
 *
 *  Additionally, there are "cprint_level" functions which add a symbol header
 *  to each line based on the level selected and the given color. 
 *
 *  ** Note: These will ALWAYS print regardless of logging level. For
 *  controlling prints using levels, see "CLOG" and "LOG" functions.
 *
 * There are several of these function-like macros available:
 *
 *      CPRINT_TRACE(char* color_string, char* string)
 *      CPRINTLN_TRACE(char* color_string, char* string)
 *      CPRINTF_TRACE(char* color_string, char* format_string, ...)
 *      CPRINTFLN_TRACE(char* color_string, char* format_string, ...)
 *
 *      CPRINT_DEBUG(char* color_string, char* string)
 *      CPRINTLN_DEBUG(char* color_string, char* string)
 *      CPRINTF_DEBUG(char* color_string, char* format_string, ...)
 *      CPRINTFLN_DEBUG(char* color_string, char* format_string, ...)
 *
 *      CPRINT_EXTRA(char* color_string, char* string)
 *      CPRINTLN_EXTRA(char* color_string, char* string)
 *      CPRINTF_EXTRA(char* color_string, char* format_string, ...)
 *      CPRINTFLN_EXTRA(char* color_string, char* format_string, ...)
 *
 *      CPRINT_INFO(char* color_string, char* string)
 *      CPRINTLN_INFO(char* color_string, char* string)
 *      CPRINTF_INFO(char* color_string, char* format_string, ...)
 *      CPRINTFLN_INFO(char* color_string, char* format_string, ...)
 *
 *      CPRINT_HEADER(char* color_string, char* string)
 *      CPRINTLN_HEADER(char* color_string, char* string)
 *      CPRINTF_HEADER(char* color_string, char* format_string, ...)
 *      CPRINTFLN_HEADER(char* color_string, char* format_string, ...)
 *
 *      CPRINT_SUCCESS(char* color_string, char* string)
 *      CPRINTLN_SUCCESS(char* color_string, char* string)
 *      CPRINTF_SUCCESS(char* color_string, char* format_string, ...)
 *      CPRINTFLN_SUCCESS(char* color_string, char* format_string, ...)
 *
 *      CPRINT_INPUT(char* color_string, char* string)
 *      CPRINTLN_INPUT(char* color_string, char* string)
 *      CPRINTF_INPUT(char* color_string, char* format_string, ...)
 *      CPRINTFLN_INPUT(char* color_string, char* format_string, ...)
 *
 *      CPRINT_WARNING(char* color_string, char* string)
 *      CPRINTLN_WARNING(char* color_string, char* string)
 *      CPRINTF_WARNING(char* color_string, char* format_string, ...)
 *      CPRINTFLN_WARNING(char* color_string, char* format_string, ...)
 *
 *      CPRINT_ERROR(char* color_string, char* string)
 *      CPRINTLN_ERROR(char* color_string, char* string)
 *      CPRINTF_ERROR(char* color_string, char* format_string, ...)
 *      CPRINTFLN_ERROR(char* color_string, char* format_string, ...)
 *
 *      CPERROR_ERROR(char* color_string, char* string)
 *      CPERRORF_ERROR(char* color_string, char* format_string, ...)
 *
 *      CPRINT_FATAL(char* color_string, char* string)
 *      CPRINTLN_FATAL(char* color_string, char* string)
 *      CPRINTF_FATAL(char* color_string, char* format_string, ...)
 *      CPRINTFLN_FATAL(char* color_string, char* format_string, ...)
 *
 *      CPERROR_FATAL(char* color_string, char* string)
 *      CPERRORF_FATAL(char* color_string, char* format_string, ...)
 *
 * Examples
 * --------
 *
 *      `CPRINT_INFO(C_RED, "Hello"); printf("you");`
 *
 *          Output: `\033[31m[*] Helloyou\033[0m` (Red "[*] Helloyou")
 *
 *  Descriptions of each function can be found at the top comment of this file.
 */

#define CPRINT(c, s)                CFPRINT(c, stdout, s)
#define CPRINTLN(c, s)              CFPRINTLN(c, stdout, s)
#define CPRINTF(c, ...)             CFPRINTF(c, stdout, __VA_ARGS__)
#define CPRINTFLN(c, ...)           CFPRINTFLN(c, stdout, __VA_ARGS__)
#define CPRINT_HEX(c, s, l)         CFPRINT_HEX(c, stdout, s, l)
#define CPRINTLN_HEX(c, s, l)       CFPRINTLN_HEX(c, stdout, s, l)
#define CPRINT_WIDE_HEX(c, s, l)    CFPRINT_WIDE_HEX(c, stdout, s, l)
#define CPRINTLN_WIDE_HEX(c, s, l)  CFPRINTLN_WIDE_HEX(c, stdout, s, l)
#define CPERROR(c, s)               CFPERROR(c, stdout, s)
#define CPERRORF(c, ...)            CFPERRORF(c, stdout, __VA_ARGS__)

#define CPRINT_TRACE(c, s)          CPRINT(c, CSYM_TRACE s)
#define CPRINTLN_TRACE(c, s)        CPRINTLN(c, CSYM_TRACE s)
#define CPRINTF_TRACE(c, ...)       CPRINTF(c, CSYM_TRACE __VA_ARGS__)
#define CPRINTFLN_TRACE(c, ...)     CPRINTFLN(c, CSYM_TRACE __VA_ARGS__)

#define CPRINT_DEBUG(c, s)          CPRINT(c, CSYM_DEBUG s)
#define CPRINTLN_DEBUG(c, s)        CPRINTLN(c, CSYM_DEBUG s)
#define CPRINTF_DEBUG(c, ...)       CPRINTF(c, CSYM_DEBUG __VA_ARGS__)
#define CPRINTFLN_DEBUG(c, ...)     CPRINTFLN(c, CSYM_DEBUG __VA_ARGS__)

#define CPRINT_EXTRA(c, s)          CPRINT(c, CSYM_EXTRA s)
#define CPRINTLN_EXTRA(c, s)        CPRINTLN(c, CSYM_EXTRA s)
#define CPRINTF_EXTRA(c, ...)       CPRINTF(c, CSYM_EXTRA __VA_ARGS__)
#define CPRINTFLN_EXTRA(c, ...)     CPRINTFLN(c, CSYM_EXTRA __VA_ARGS__)

#define CPRINT_INFO(c, s)           CPRINT(c, CSYM_INFO s)
#define CPRINTLN_INFO(c, s)         CPRINTLN(c, CSYM_INFO s)
#define CPRINTF_INFO(c, ...)        CPRINTF(c, CSYM_INFO __VA_ARGS__)
#define CPRINTFLN_INFO(c, ...)      CPRINTFLN(c, CSYM_INFO __VA_ARGS__)

#define CPRINT_HEADER(c, s)         CPRINT(c, CSYM_HEADER s)
#define CPRINTLN_HEADER(c, s)       CPRINTLN(c, CSYM_HEADER s)
#define CPRINTF_HEADER(c, ...)      CPRINTF(c, CSYM_HEADER __VA_ARGS__)
#define CPRINTFLN_HEADER(c, ...)    CPRINTFLN(c, CSYM_HEADER __VA_ARGS__)

#define CPRINT_SUCCESS(c, s)        CPRINT(c, CSYM_SUCCESS s)
#define CPRINTLN_SUCCESS(c, s)      CPRINTLN(c, CSYM_SUCCESS s)
#define CPRINTF_SUCCESS(c, ...)     CPRINTF(c, CSYM_SUCCESS __VA_ARGS__)
#define CPRINTFLN_SUCCESS(c, ...)   CPRINTFLN(c, CSYM_SUCCESS __VA_ARGS__)

#define CPRINT_INPUT(c, s)          CPRINT(c, CSYM_INPUT s)
#define CPRINTLN_INPUT(c, s)        CPRINTLN(c, CSYM_INPUT s)
#define CPRINTF_INPUT(c, ...)       CPRINTF(c, CSYM_INPUT __VA_ARGS__)
#define CPRINTFLN_INPUT(c, ...)     CPRINTFLN(c, CSYM_INPUT __VA_ARGS__)

#define CPRINT_WARNING(c, s)        CPRINT(c, CSYM_WARN s)
#define CPRINTLN_WARNING(c, s)      CPRINTLN(c, CSYM_WARN s)
#define CPRINTF_WARNING(c, ...)     CPRINTF(c, CSYM_WARN __VA_ARGS__)
#define CPRINTFLN_WARNING(c, ...)   CPRINTFLN(c, CSYM_WARN __VA_ARGS__)
#define CPERROR_WARNING(c, s)       CPERROR(c, CSYM_WARN s)
#define CPERRORF_WARNING(c, ...)    CPERRORF(c, CSYM_WARN __VA_ARGS__)

#define CPRINT_ERROR(c, s)          CPRINT(c, CSYM_ERR s)
#define CPRINTLN_ERROR(c, s)        CPRINTLN(c, CSYM_ERR s)
#define CPRINTF_ERROR(c, ...)       CPRINTF(c, CSYM_ERR __VA_ARGS__)
#define CPRINTFLN_ERROR(c, ...)     CPRINTFLN(c, CSYM_ERR __VA_ARGS__)
#define CPERROR_ERROR(c, s)         CPERROR(c, CSYM_ERR s)
#define CPERRORF_ERROR(c, ...)      CPERRORF(c, CSYM_ERR __VA_ARGS__)

#define CPRINT_FATAL(c, s)          CPRINT(c, CSYM_FATAL s)
#define CPRINTLN_FATAL(c, s)        CPRINTLN(c, CSYM_FATAL s)
#define CPRINTF_FATAL(c, ...)       CPRINTF(c, CSYM_FATAL __VA_ARGS__)
#define CPRINTFLN_FATAL(c, ...)     CPRINTFLN(c, CSYM_FATAL __VA_ARGS__)
#define CPERROR_FATAL(c, s)         CPERROR(c, CSYM_ERR s)
#define CPERRORF_FATAL(c, ...)      CPERRORF(c, CSYM_ERR __VA_ARGS__)

// Aliases.

#define CPRINT_TR(c, s)             CPRINT_TRACE(c, s)       
#define CPRINTLN_TR(c, s)           CPRINTLN_TRACE(c, s)     
#define CPRINTF_TR(c, ...)          CPRINTF_TRACE(c, __VA_ARGS__)    
#define CPRINTFLN_TR(c, ...)        CPRINTFLN_TRACE(c, __VA_ARGS__)  

#define CPRINT_DB(c, s)             CPRINT_DEBUG(c, s)       
#define CPRINTLN_DB(c, s)           CPRINTLN_DEBUG(c, s)     
#define CPRINTF_DB(c, ...)          CPRINTF_DEBUG(c, __VA_ARGS__)    
#define CPRINTFLN_DB(c, ...)        CPRINTFLN_DEBUG(c, __VA_ARGS__)  

#define CPRINT_EX(c, s)             CPRINT_EXTRA(c, s)       
#define CPRINTLN_EX(c, s)           CPRINTLN_EXTRA(c, s)     
#define CPRINTF_EX(c, ...)          CPRINTF_EXTRA(c, __VA_ARGS__)    
#define CPRINTFLN_EX(c, ...)        CPRINTFLN_EXTRA(c, __VA_ARGS__)  

#define CPRINT_IF(c, s)             CPRINT_INFO(c, s)        
#define CPRINTLN_IF(c, s)           CPRINTLN_INFO(c, s)      
#define CPRINTF_IF(c, ...)          CPRINTF_INFO(c, __VA_ARGS__)     
#define CPRINTFLN_IF(c, ...)        CPRINTFLN_INFO(c, __VA_ARGS__)   

#define CPRINT_HEAD(c, s)           CPRINT_HEADER(c, s)      
#define CPRINTLN_HEAD(c, s)         CPRINTLN_HEADER(c, s)    
#define CPRINTF_HEAD(c, ...)        CPRINTF_HEADER(c, __VA_ARGS__)   
#define CPRINTFLN_HEAD(c, ...)      CPRINTFLN_HEADER(c, __VA_ARGS__) 

#define CPRINT_HD(c, s)             CPRINT_HEADER(c, s)      
#define CPRINTLN_HD(c, s)           CPRINTLN_HEADER(c, s)    
#define CPRINTF_HD(c, ...)          CPRINTF_HEADER(c, __VA_ARGS__)   
#define CPRINTFLN_HD(c, ...)        CPRINTFLN_HEADER(c, __VA_ARGS__) 

#define CPRINT_SUC(c, s)            CPRINT_SUCCESS(c, s)     
#define CPRINTLN_SUC(c, s)          CPRINTLN_SUCCESS(c, s)   
#define CPRINTF_SUC(c, ...)         CPRINTF_SUCCESS(c, __VA_ARGS__)  
#define CPRINTFLN_SUC(c, ...)       CPRINTFLN_SUCCESS(c, __VA_ARGS__)

#define CPRINT_SC(c, s)             CPRINT_SUCCESS(c, s)     
#define CPRINTLN_SC(c, s)           CPRINTLN_SUCCESS(c, s)   
#define CPRINTF_SC(c, ...)          CPRINTF_SUCCESS(c, __VA_ARGS__)  
#define CPRINTFLN_SC(c, ...)        CPRINTFLN_SUCCESS(c, __VA_ARGS__)

#define CPRINT_IN(c, s)             CPRINT_INPUT(c, s)       
#define CPRINTLN_IN(c, s)           CPRINTLN_INPUT(c, s)     
#define CPRINTF_IN(c, ...)          CPRINTF_INPUT(c, __VA_ARGS__)    
#define CPRINTFLN_IN(c, ...)        CPRINTFLN_INPUT(c, __VA_ARGS__)  

#define CPRINT_WARN(c, s)           CPRINT_WARNING(c, s)     
#define CPRINTLN_WARN(c, s)         CPRINTLN_WARNING(c, s)   
#define CPRINTF_WARN(c, ...)        CPRINTF_WARNING(c, __VA_ARGS__)  
#define CPRINTFLN_WARN(c, ...)      CPRINTFLN_WARNING(c, __VA_ARGS__)
#define CPERROR_WARN(c, s)          CPERROR_WARNING(c, s)      
#define CPERRORF_WARN(c, ...)       CPERRORF_WARNING(c, __VA_ARGS__)   

#define CPRINT_WN(c, s)             CPRINT_WARNING(c, s)     
#define CPRINTLN_WN(c, s)           CPRINTLN_WARNING(c, s)   
#define CPRINTF_WN(c, ...)          CPRINTF_WARNING(c, __VA_ARGS__)  
#define CPRINTFLN_WN(c, ...)        CPRINTFLN_WARNING(c, __VA_ARGS__)
#define CPERROR_WN(c, s)            CPERROR_WARNING(c, s)      
#define CPERRORF_WN(c, ...)         CPERRORF_WARNING(c, __VA_ARGS__)   

#define CPRINT_ERR(c, s)            CPRINT_ERROR(c, s)       
#define CPRINTLN_ERR(c, s)          CPRINTLN_ERROR(c, s)     
#define CPRINTF_ERR(c, ...)         CPRINTF_ERROR(c, __VA_ARGS__)    
#define CPRINTFLN_ERR(c, ...)       CPRINTFLN_ERROR(c, __VA_ARGS__)  
#define CPERROR_ERR(c, s)           CPERROR_ERROR(c, s)      
#define CPERRORF_ERR(c, ...)        CPERRORF_ERROR(c, __VA_ARGS__)   

#define CPRINT_ER(c, s)             CPRINT_ERROR(c, s)       
#define CPRINTLN_ER(c, s)           CPRINTLN_ERROR(c, s)     
#define CPRINTF_ER(c, ...)          CPRINTF_ERROR(c, __VA_ARGS__)    
#define CPRINTFLN_ER(c, ...)        CPRINTFLN_ERROR(c, __VA_ARGS__)  
#define CPERROR_ER(c, s)            CPERROR_ERROR(c, s)      
#define CPERRORF_ER(c, ...)         CPERRORF_ERROR(c, __VA_ARGS__)   

#define CPRINT_FAT(c, s)            CPRINT_FATAL(c, s)       
#define CPRINTLN_FAT(c, s)          CPRINTLN_FATAL(c, s)     
#define CPRINTF_FAT(c, ...)         CPRINTF_FATAL(c, __VA_ARGS__)    
#define CPRINTFLN_FAT(c, ...)       CPRINTFLN_FATAL(c, __VA_ARGS__)  
#define CPERROR_FAT(c, s)           CPERROR_FATAL(c, s)      
#define CPERRORF_FAT(c, ...)        CPERRORF_FATAL(c, __VA_ARGS__)   

#define CPRINT_FT(c, s)             CPRINT_FATAL(c, s)       
#define CPRINTLN_FT(c, s)           CPRINTLN_FATAL(c, s)     
#define CPRINTF_FT(c, ...)          CPRINTF_FATAL(c, __VA_ARGS__)    
#define CPRINTFLN_FT(c, ...)        CPRINTFLN_FATAL(c, __VA_ARGS__)  
#define CPERROR_FT(c, s)            CPERROR_FATAL(c, s)      
#define CPERRORF_FT(c, ...)         CPERRORF_FATAL(c, __VA_ARGS__)   


/**
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

#define _CLOG_NOTHING 

// Log options.

#define LOG_CONSOLE_MODE_NOCOLOR    0
#define LOG_CONSOLE_MODE_COLOR      1

#ifndef LOG_CONSOLE_MODE
    #define LOG_CONSOLE_MODE        LOG_CONSOLE_MODE_COLOR
#endif

#define LOG_MODE_NONE               0
#define LOG_MODE_CONSOLE            1
#define LOG_MODE_FILE               2
#define LOG_MODE_CONSOLE_AND_FILE   3

#ifndef LOG_MODE
    #define LOG_MODE                LOG_MODE_CONSOLE_AND_FILE
#endif

#define LOG_LEVEL_NONE              0
#define LOG_LEVEL_ERR               1
#define LOG_LEVEL_WARN              2
#define LOG_LEVEL_INFO              3
#define LOG_LEVEL_EXTRA             4
#define LOG_LEVEL_DEBUG             5
#define LOG_LEVEL_ALL               6

#ifndef LOG_LEVEL
    #define LOG_LEVEL               LOG_LEVEL_ALL
#endif

// Log initialization.

#define _CLOG_TM_BUFSZ              128
#define _CLOG_TM_FMT                "%FT%T%z"

#define CLOG_DECLARE                FILE* _clog_glog = NULL; \
                                    char _clog_gtime_buf[_CLOG_TM_BUFSZ] = {0};\
                                    time_t _clog_gtime = 0; 

#define CLOG_FILE_INIT(f)           _clog_glog = fopen(f, "a+");

// Log functions.

#define _CLOG_TIME(f)               time(&_clog_gtime); \
                                    strftime( \
                                        _clog_gtime_buf, \
                                        _CLOG_TM_BUFSZ, \
                                        _CLOG_TM_FMT, \
                                        localtime(&_clog_gtime) \
                                    ); \
                                    FPRINTF(f, "%s: ", _clog_gtime_buf);

#define _CLOG_TRACING(f)            FPRINTF( \
                                        f, \
                                        "%s:%s:%u: ", \
                                        __FILE__, \
                                        __FUNCTION__, \
                                        __LINE__ \
                                    ); 

#define _CLOG_CTRACING(f)           FPRINTF( \
                                        f, \
                                        C_MAGENTA "%s" C_RESET ":" \
                                        C_GREEN "%s" C_RESET ":" \
                                        C_BLUE "%u" C_RESET ": ", \
                                        __FILE__, \
                                        __FUNCTION__, \
                                        __LINE__ \
                                    );


/**
 * Console Logging
 * ===============
 *
 * Console logging obeys log level and log console color mode configuration
 * options and prints to standard error. Console logging also includes a
 * timestamp and log level symbol string line header.
 *
 */

// Console Logging Setup.

// Need to redo this to get rid of the extra arguments and messiness (although
// not really necessary right now).

#define _CLOG_NC_CLOG(c, s)             { \
                                            _CLOG_TIME(stderr); \
                                            FPRINT(stderr, s); \
                                        }
#define _CLOG_NC_CLOGLN(c, s)           { \
                                            _CLOG_TIME(stderr); \
                                            FPRINTLN(stderr, s); \
                                        }
#define _CLOG_NC_CLOGF(c, ...)          { \
                                            _CLOG_TIME(stderr); \
                                            FPRINTF(stderr, __VA_ARGS__); \
                                        }
#define _CLOG_NC_CLOGFLN(c, ...)        { \
                                            _CLOG_TIME(stderr); \
                                            FPRINTFLN(stderr, __VA_ARGS__); \
                                        }
#define _CLOG_NC_CLOG_PERROR(c, s)      { \
                                            _CLOG_TIME(stderr); \
                                            FPERROR(stderr, s); \
                                        }
#define _CLOG_NC_CLOG_PERRORF(c, ...)   { \
                                            _CLOG_TIME(stderr); \
                                            FPERRORF(stderr, __VA_ARGS__); \
                                        }

#define _CLOG_NC_CLOG_T(c, s)           { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPRINT(stderr, s); \
                                        }
#define _CLOG_NC_CLOGLN_T(c, s)         { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPRINTLN(stderr, s); \
                                        }
#define _CLOG_NC_CLOGF_T(c, ...)        { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPRINTF(stderr, __VA_ARGS__); \
                                        }
#define _CLOG_NC_CLOGFLN_T(c, ...)      { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPRINTFLN(stderr, __VA_ARGS__); \
                                        }
#define _CLOG_NC_CLOG_PERROR_T(c, s)    { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPERROR(stderr, s); \
                                        }
#define _CLOG_NC_CLOG_PERRORF_T(c, ...) { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_TRACING(stderr); \
                                            FPERRORF(stderr, __VA_ARGS__); \
                                        }

#define _CLOG_C_CLOG(c, s)              { \
                                            _CLOG_TIME(stderr); \
                                            CFPRINT(c, stderr, s); \
                                        }
#define _CLOG_C_CLOGLN(c, s)            { \
                                            _CLOG_TIME(stderr); \
                                            CFPRINTLN(c, stderr, s); \
                                        }
#define _CLOG_C_CLOGF(c, ...)           { \
                                            _CLOG_TIME(stderr); \
                                            CFPRINTF(c, stderr, __VA_ARGS__); \
                                        }
#define _CLOG_C_CLOGFLN(c, ...)         { \
                                            _CLOG_TIME(stderr); \
                                            CFPRINTFLN(c, stderr, __VA_ARGS__);\
                                        }
#define _CLOG_C_CLOG_PERROR(c, s)       { \
                                            _CLOG_TIME(stderr); \
                                            CFPERROR(c, stderr, s); \
                                        }
#define _CLOG_C_CLOG_PERRORF(c, ...)    { \
                                            _CLOG_TIME(stderr); \
                                            CFPERRORF(c, stderr, __VA_ARGS__); \
                                        }

#define _CLOG_C_CLOG_T(c, s)            { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPRINT(c, stderr, s); \
                                        }
#define _CLOG_C_CLOGLN_T(c, s)          { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPRINTLN(c, stderr, s); \
                                        }
#define _CLOG_C_CLOGF_T(c, ...)         { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPRINTF(c, stderr, __VA_ARGS__); \
                                        }
#define _CLOG_C_CLOGFLN_T(c, ...)       { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPRINTFLN(c, stderr, __VA_ARGS__);\
                                        }
#define _CLOG_C_CLOG_PERROR_T(c, s)     { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPERROR(c, stderr, s); \
                                        }
#define _CLOG_C_CLOG_PERRORF_T(c, ...)  { \
                                            _CLOG_TIME(stderr); \
                                            _CLOG_CTRACING(stderr); \
                                            CFPERRORF(c, stderr, __VA_ARGS__); \
                                        }

#if LOG_CONSOLE_MODE == LOG_CONSOLE_MODE_NOCOLOR
    #define _CLOG_CLOG(c, s)             _CLOG_NC_CLOG(c, s)
    #define _CLOG_CLOGLN(c, s)           _CLOG_NC_CLOGLN(c, s)
    #define _CLOG_CLOGF(c, ...)          _CLOG_NC_CLOGF(c, __VA_ARGS__)
    #define _CLOG_CLOGFLN(c, ...)        _CLOG_NC_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_CLOG_PERROR(c, s)      _CLOG_NC_CLOG_PERROR(c, s)
    #define _CLOG_CLOG_PERRORF(c, ...)   _CLOG_NC_CLOG_PERRORF(c, __VA_ARGS__)

    #define _CLOG_CLOG_T(c, s)           _CLOG_NC_CLOG_T(c, s)
    #define _CLOG_CLOGLN_T(c, s)         _CLOG_NC_CLOGLN_T(c, s)
    #define _CLOG_CLOGF_T(c, ...)        _CLOG_NC_CLOGF_T(c, __VA_ARGS__)
    #define _CLOG_CLOGFLN_T(c, ...)      _CLOG_NC_CLOGFLN_T(c, __VA_ARGS__)
    #define _CLOG_CLOG_PERROR_T(c, s)    _CLOG_NC_CLOG_PERROR_T(c, s)
    #define _CLOG_CLOG_PERRORF_T(c, ...) _CLOG_NC_CLOG_PERRORF_T(c, __VA_ARGS__)

#else
    #define _CLOG_CLOG(c, s)             _CLOG_C_CLOG(c, s)
    #define _CLOG_CLOGLN(c, s)           _CLOG_C_CLOGLN(c, s)
    #define _CLOG_CLOGF(c, ...)          _CLOG_C_CLOGF(c, __VA_ARGS__)
    #define _CLOG_CLOGFLN(c, ...)        _CLOG_C_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_CLOG_PERROR(c, s)      _CLOG_C_CLOG_PERROR(c, s)
    #define _CLOG_CLOG_PERRORF(c, ...)   _CLOG_C_CLOG_PERRORF(c, __VA_ARGS__)

    #define _CLOG_CLOG_T(c, s)           _CLOG_C_CLOG_T(c, s)
    #define _CLOG_CLOGLN_T(c, s)         _CLOG_C_CLOGLN_T(c, s)
    #define _CLOG_CLOGF_T(c, ...)        _CLOG_C_CLOGF_T(c, __VA_ARGS__)
    #define _CLOG_CLOGFLN_T(c, ...)      _CLOG_C_CLOGFLN_T(c, __VA_ARGS__)
    #define _CLOG_CLOG_PERROR_T(c, s)    _CLOG_C_CLOG_PERROR_T(c, s)
    #define _CLOG_CLOG_PERRORF_T(c, ...) _CLOG_C_CLOG_PERRORF_T(c, __VA_ARGS__)

#endif

// Console Logging Functions.

#define CLOG(s)                     _CLOG_NC_CLOG(_CLOG_NOTHING, s)
#define CLOGLN(s)                   _CLOG_NC_CLOGLN(_CLOG_NOTHING, s)
#define CLOGF(...)                  _CLOG_NC_CLOGF(_CLOG_NOTHING, __VA_ARGS__)
#define CLOGFLN(...)                _CLOG_NC_CLOGFLN(_CLOG_NOTHING, __VA_ARGS__)
#define CLOG_PERROR(s)              _CLOG_NC_CLOG_PERROR(_CLOG_NOTHING, s)
#define CLOG_PERRORF(...)           _CLOG_NC_CLOG_PERRORF( \
                                        _CLOG_NOTHING, __VA_ARGS__ \
                                    )

#define CLOG_STREAM(s)              FPRINT(stderr, s)
#define CLOGLN_STREAM(s)            FPRINTLN(stderr, s)
#define CLOGF_STREAM(...)           FPRINTF(stderr, __VA_ARGS__)
#define CLOGFLN_STREAM(...)         FPRINTFLN(stderr, __VA_ARGS__)
#define CLOG_STREAM_HEX(s, l)       FPRINT_HEX(stderr, s, l)
#define CLOGLN_STREAM_HEX(s, l)     FPRINTLN_HEX(stderr, s, l)
#define CLOG_STREAM_WIDE_HEX(s, l)  FPRINT_WIDE_HEX(stderr, s, l)
#define CLOGLN_STREAM_WIDE_HEX(s, l) FPRINTLN_WIDE_HEX(stderr, s, l)

// Console logging functions with tracing.

#define CLOG_T(s)                   _CLOG_NC_CLOG_T(_CLOG_NOTHING, s)
#define CLOGLN_T(s)                 _CLOG_NC_CLOGLN_T(_CLOG_NOTHING, s)
#define CLOGF_T(...)                _CLOG_NC_CLOGF_T(_CLOG_NOTHING, __VA_ARGS__)
#define CLOGFLN_T(...)              _CLOG_NC_CLOGFLN_T( \
                                        _CLOG_NOTHING, __VA_ARGS__ \
                                    )
#define CLOG_PERROR_T(s)            _CLOG_NC_CLOG_PERROR_T(_CLOG_NOTHING, s)
#define CLOG_PERRORF_T(...)         _CLOG_NC_CLOG_PERRORF_T( \
                                        _CLOG_NOTHING, __VA_ARGS__ \
                                    )

// Color console logging functions.

#define CCLOG(c, s)                 _CLOG_CLOG(c, s)
#define CCLOGLN(c, s)               _CLOG_CLOGLN(c, s)
#define CCLOGF(c, ...)              _CLOG_CLOGF(c, __VA_ARGS__)
#define CCLOGFLN(c, ...)            _CLOG_CLOGFLN(c, __VA_ARGS__)
#define CCLOG_PERROR(c, s)          _CLOG_CLOG_PERROR(c, s)
#define CCLOG_PERRORF(c, ...)       _CLOG_CLOG_PERRORF(c, __VA_ARGS__)

#define CCLOG_STREAM(c, s)             CFPRINT(c, stderr, s)
#define CCLOGLN_STREAM(c, s)           CFPRINTLN(c, stderr, s)
#define CCLOGF_STREAM(c, ...)          CFPRINTF(c, stderr, __VA_ARGS__)
#define CCLOGFLN_STREAM(c, ...)        CFPRINTFLN(c, stderr, __VA_ARGS__)
#define CCLOG_STREAM_HEX(c, s, l)      CFPRINT_HEX(c, stderr, s, l)
#define CCLOGLN_STREAM_HEX(c, s, l)    CFPRINTLN_HEX(c, stderr, s, l)
#define CCLOG_STREAM_WIDE_HEX(c, s, l) CFPRINT_WIDE_HEX(c, stderr, s, l)
#define CCLOGLN_STREAM_WIDE_HEX(c, s, l) CFPRINTLN_WIDE_HEX(c, stderr, s, l)

// Color console logging functions with tracing.

#define CCLOG_T(c, s)               _CLOG_CLOG_T(c, s)
#define CCLOGLN_T(c, s)             _CLOG_CLOGLN_T(c, s)
#define CCLOGF_T(c, ...)            _CLOG_CLOGF_T(c, __VA_ARGS__)
#define CCLOGFLN_T(c, ...)          _CLOG_CLOGFLN_T(c, __VA_ARGS__)
#define CCLOG_PERROR_T(c, s)        _CLOG_CLOG_PERROR_T(c, s)
#define CCLOG_PERRORF_T(c, ...)     _CLOG_CLOG_PERRORF_T(c, __VA_ARGS__)

// Console level logging functions.

#define CLOG_TRACE(s)           _CLOG_CLOG_T(C_TRACE, CSYM_TRACE s)
#define CLOGLN_TRACE(s)         _CLOG_CLOGLN_T(C_TRACE, CSYM_TRACE s)
#define CLOGF_TRACE(...)        _CLOG_CLOGF_T(C_TRACE, CSYM_TRACE __VA_ARGS__)
#define CLOGFLN_TRACE(...)      _CLOG_CLOGFLN_T(C_TRACE, CSYM_TRACE __VA_ARGS__)

#define CLOG_DEBUG(s)           _CLOG_CLOG_T(C_DEBUG, CSYM_DEBUG s)
#define CLOGLN_DEBUG(s)         _CLOG_CLOGLN_T(C_DEBUG, CSYM_DEBUG s)
#define CLOGF_DEBUG(...)        _CLOG_CLOGF_T(C_DEBUG, CSYM_DEBUG __VA_ARGS__)
#define CLOGFLN_DEBUG(...)      _CLOG_CLOGFLN_T(C_DEBUG, CSYM_DEBUG __VA_ARGS__)

#define CLOG_EXTRA(s)           _CLOG_CLOG(C_EXTRA, CSYM_EXTRA s)
#define CLOGLN_EXTRA(s)         _CLOG_CLOGLN(C_EXTRA, CSYM_EXTRA s)
#define CLOGF_EXTRA(...)        _CLOG_CLOGF(C_EXTRA, CSYM_EXTRA __VA_ARGS__)
#define CLOGFLN_EXTRA(...)      _CLOG_CLOGFLN(C_EXTRA, CSYM_EXTRA __VA_ARGS__)

#define CLOG_INFO(s)            _CLOG_CLOG(C_INFO, CSYM_INFO s)
#define CLOGLN_INFO(s)          _CLOG_CLOGLN(C_INFO, CSYM_INFO s)
#define CLOGF_INFO(...)         _CLOG_CLOGF(C_INFO, CSYM_INFO __VA_ARGS__)
#define CLOGFLN_INFO(...)       _CLOG_CLOGFLN(C_INFO, CSYM_INFO __VA_ARGS__)

#define CLOG_HEADER(s)          _CLOG_CLOG(C_HEADER, CSYM_HEADER s)
#define CLOGLN_HEADER(s)        _CLOG_CLOGLN(C_HEADER, CSYM_HEADER s)
#define CLOGF_HEADER(...)       _CLOG_CLOGF(C_HEADER, CSYM_HEADER __VA_ARGS__)
#define CLOGFLN_HEADER(...)     _CLOG_CLOGFLN(C_HEADER, CSYM_HEADER __VA_ARGS__)

#define CLOG_SUCCESS(s)         _CLOG_CLOG(C_SUCCESS, CSYM_SUCCESS s)
#define CLOGLN_SUCCESS(s)       _CLOG_CLOGLN(C_SUCCESS, CSYM_SUCCESS s)
#define CLOGF_SUCCESS(...)      _CLOG_CLOGF(C_SUCCESS, CSYM_SUCCESS __VA_ARGS__)
#define CLOGFLN_SUCCESS(...)    _CLOG_CLOGFLN( \
                                    C_SUCCESS, CSYM_SUCCESS __VA_ARGS__ \
                                )

#define CLOG_INPUT(s)           _CLOG_CLOG(C_INPUT, CSYM_INPUT s)
#define CLOGLN_INPUT(s)         _CLOG_CLOGLN(C_INPUT, CSYM_INPUT s)
#define CLOGF_INPUT(...)        _CLOG_CLOGF(C_INPUT, CSYM_INPUT __VA_ARGS__)
#define CLOGFLN_INPUT(...)      _CLOG_CLOGFLN(C_INPUT, CSYM_INPUT __VA_ARGS__)

#define CLOG_WARNING(s)         _CLOG_CLOG(C_WARN, CSYM_WARN s)
#define CLOGLN_WARNING(s)       _CLOG_CLOGLN(C_WARN, CSYM_WARN s)
#define CLOGF_WARNING(...)      _CLOG_CLOGF(C_WARN, CSYM_WARN __VA_ARGS__)
#define CLOGFLN_WARNING(...)    _CLOG_CLOGFLN(C_WARN, CSYM_WARN __VA_ARGS__)
#define CLOG_PERROR_WARNING(s)  _CLOG_CLOG_PERROR(C_WARN, CSYM_WARN s)
#define CLOG_PERRORF_WARNING(...) _CLOG_CLOG_PERROR(C_WARN, CSYM_WARN __VA_ARGS__)

#define CLOG_ERROR(s)           _CLOG_CLOG(C_ERR, CSYM_ERR s)
#define CLOGLN_ERROR(s)         _CLOG_CLOGLN(C_ERR, CSYM_ERR s)
#define CLOGF_ERROR(...)        _CLOG_CLOGF(C_ERR, CSYM_ERR __VA_ARGS__)
#define CLOGFLN_ERROR(...)      _CLOG_CLOGFLN(C_ERR, CSYM_ERR __VA_ARGS__)
#define CLOG_PERROR_ERROR(s)    _CLOG_CLOG_PERROR(C_ERR, CSYM_ERR s)
#define CLOG_PERRORF_ERROR(...) _CLOG_CLOG_PERROR(C_ERR, CSYM_ERR __VA_ARGS__)

#define CLOG_FATAL(s)           _CLOG_CLOG(C_FATAL, CSYM_FATAL s)
#define CLOGLN_FATAL(s)         _CLOG_CLOGLN(C_FATAL, CSYM_FATAL s)
#define CLOGF_FATAL(...)        _CLOG_CLOGF(C_FATAL, CSYM_FATAL __VA_ARGS__)
#define CLOGFLN_FATAL(...)      _CLOG_CLOGFLN(C_FATAL, CSYM_FATAL __VA_ARGS__)
#define CLOG_PERROR_FATAL(s)    _CLOG_CLOG_PERROR(C_FATAL, CSYM_FATAL s)
#define CLOG_PERRORF_FATAL(...) _CLOG_CLOG_PERRORF( \
                                    C_FATAL, CSYM_FATAL __VA_ARGS__ \
                                )

// Aliases.

#define CLOG_TR(s)              CLOG_TRACE(s)      
#define CLOGLN_TR(s)            CLOGLN_TRACE(s)    
#define CLOGF_TR(...)           CLOGF_TRACE(__VA_ARGS__)   
#define CLOGFLN_TR(...)         CLOGFLN_TRACE(__VA_ARGS__) 
                                                   
#define CLOG_DB(s)              CLOG_DEBUG(s)      
#define CLOGLN_DB(s)            CLOGLN_DEBUG(s)    
#define CLOGF_DB(...)           CLOGF_DEBUG(__VA_ARGS__)   
#define CLOGFLN_DB(...)         CLOGFLN_DEBUG(__VA_ARGS__) 
                                                   
#define CLOG_EX(s)              CLOG_EXTRA(s)      
#define CLOGLN_EX(s)            CLOGLN_EXTRA(s)    
#define CLOGF_EX(...)           CLOGF_EXTRA(__VA_ARGS__)   
#define CLOGFLN_EX(...)         CLOGFLN_EXTRA(__VA_ARGS__) 
                                                   
#define CLOG_IF(s)              CLOG_INFO(s)        
#define CLOGLN_IF(s)            CLOGLN_INFO(s)      
#define CLOGF_IF(...)           CLOGF_INFO(__VA_ARGS__)     
#define CLOGFLN_IF(...)         CLOGFLN_INFO(__VA_ARGS__)   
                                                   
#define CLOG_HEAD(s)            CLOG_HEADER(s)      
#define CLOGLN_HEAD(s)          CLOGLN_HEADER(s)    
#define CLOGF_HEAD(...)         CLOGF_HEADER(__VA_ARGS__)   
#define CLOGFLN_HEAD(...)       CLOGFLN_HEADER(__VA_ARGS__) 

#define CLOG_HD(s)              CLOG_HEADER(s)      
#define CLOGLN_HD(s)            CLOGLN_HEADER(s)    
#define CLOGF_HD(...)           CLOGF_HEADER(__VA_ARGS__)   
#define CLOGFLN_HD(...)         CLOGFLN_HEADER(__VA_ARGS__) 

#define CLOG_SUC(s)             CLOG_SUCCESS(s)      
#define CLOGLN_SUC(s)           CLOGLN_SUCCESS(s)    
#define CLOGF_SUC(...)          CLOGF_SUCCESS(__VA_ARGS__)   
#define CLOGFLN_SUC(...)        CLOGFLN_SUCCESS(__VA_ARGS__) 
                                
#define CLOG_SC(s)              CLOG_SUCCESS(s)      
#define CLOGLN_SC(s)            CLOGLN_SUCCESS(s)    
#define CLOGF_SC(...)           CLOGF_SUCCESS(__VA_ARGS__)   
#define CLOGFLN_SC(...)         CLOGFLN_SUCCESS(__VA_ARGS__) 
                                     
#define CLOG_IN(s)              CLOG_INPUT(s)       
#define CLOGLN_IN(s)            CLOGLN_INPUT(s)     
#define CLOGF_IN(...)           CLOGF_INPUT(__VA_ARGS__)    
#define CLOGFLN_IN(...)         CLOGFLN_INPUT(__VA_ARGS__)  

#define CLOG_WARN(s)            CLOG_WARNING(s)     
#define CLOGLN_WARN(s)          CLOGLN_WARNING(s)   
#define CLOGF_WARN(...)         CLOGF_WARNING(__VA_ARGS__)  
#define CLOGFLN_WARN(...)       CLOGFLN_WARNING(__VA_ARGS__)
#define CLOG_PERROR_WARN(s)     CLOG_PERROR_WARNING(s)   
#define CLOG_PERRORF_WARN(...)  CLOG_PERRORF_WARNING(__VA_ARGS__)

#define CLOG_WN(s)              CLOG_WARNING(s)     
#define CLOGLN_WN(s)            CLOGLN_WARNING(s)   
#define CLOGF_WN(...)           CLOGF_WARNING(__VA_ARGS__)  
#define CLOGFLN_WN(...)         CLOGFLN_WARNING(__VA_ARGS__)
#define CLOG_PERROR_WN(s)       CLOG_PERROR_WARNING(s)   
#define CLOG_PERRORF_WN(...)    CLOG_PERRORF_WARNING(__VA_ARGS__)

#define CLOG_ERR(s)             CLOG_ERROR(s)          
#define CLOGLN_ERR(s)           CLOGLN_ERROR(s)        
#define CLOGF_ERR(...)          CLOGF_ERROR(__VA_ARGS__)       
#define CLOGFLN_ERR(...)        CLOGFLN_ERROR(__VA_ARGS__)     
#define CLOG_PERROR_ERR(s)      CLOG_PERROR_ERROR(s)   
#define CLOG_PERRORF_ERR(...)   CLOG_PERRORF_ERROR(__VA_ARGS__)

#define CLOG_ER(s)              CLOG_ERROR(s)          
#define CLOGLN_ER(s)            CLOGLN_ERROR(s)        
#define CLOGF_ER(...)           CLOGF_ERROR(__VA_ARGS__)       
#define CLOGFLN_ER(...)         CLOGFLN_ERROR(__VA_ARGS__)     
#define CLOG_PERROR_ER(s)       CLOG_PERROR_ERROR(s)   
#define CLOG_PERRORF_ER(...)    CLOG_PERRORF_ERROR(__VA_ARGS__)

#define CLOG_FAT(s)             CLOG_FATAL(s)          
#define CLOGLN_FAT(s)           CLOGLN_FATAL(s)        
#define CLOGF_FAT(...)          CLOGF_FATAL(__VA_ARGS__)       
#define CLOGFLN_FAT(...)        CLOGFLN_FATAL(__VA_ARGS__)     
#define CLOG_PERROR_FAT(s)      CLOG_PERROR_FATAL(s)   
#define CLOG_PERRORF_FAT(...)   CLOG_PERRORF_FATAL(__VA_ARGS__)

#define CLOG_FT(s)              CLOG_FATAL(s)          
#define CLOGLN_FT(s)            CLOGLN_FATAL(s)        
#define CLOGF_FT(...)           CLOGF_FATAL(__VA_ARGS__)       
#define CLOGFLN_FT(...)         CLOGFLN_FATAL(__VA_ARGS__)     
#define CLOG_PERROR_FT(s)       CLOG_PERROR_FATAL(s)   
#define CLOG_PERRORF_FT(...)    CLOG_PERRORF_FATAL(__VA_ARGS__)


/**
 * File Logging
 * ============
 *
 * File logging behaves in the same way as console logging except for there is
 * never color logging and the logging is to a file instead of the console.
 *
 */

// File logging functions.

#define FLOG(s)                     { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPRINT(_clog_glog, s); \
                                    }
#define FLOGLN(s)                   { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPRINTLN(_clog_glog, s); \
                                    }
#define FLOGF(...)                  { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPRINTF(_clog_glog, __VA_ARGS__); \
                                    }
#define FLOGFLN(...)                { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPRINTFLN(_clog_glog, __VA_ARGS__); \
                                    }
#define FLOG_PERROR(s)              { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPERROR(_clog_glog, s); \
                                    }
#define FLOG_PERRORF(...)           { \
                                        _CLOG_TIME(_clog_glog); \
                                        FPERRORF(_clog_glog, __VA_ARGS__); \
                                    }

#define FLOG_STREAM(s)              FPRINT(_clog_glog, s)
#define FLOGLN_STREAM(s)            FPRINTLN(_clog_glog, s)
#define FLOGF_STREAM(...)           FPRINTF(_clog_glog, __VA_ARGS__)
#define FLOGFLN_STREAM(...)         FPRINTFLN(_clog_glog, __VA_ARGS__)
#define FLOG_STREAM_HEX(s, l)       FPRINT_HEX(_clog_glog, s, l)
#define FLOGLN_STREAM_HEX(s, l)     FPRINTLN_HEX(_clog_glog, s, l)
#define FLOG_STREAM_WIDE_HEX(s, l)  FPRINT_WIDE_HEX(_clog_glog, s, l)
#define FLOGLN_STREAM_WIDE_HEX(s, l) FPRINTLN_WIDE_HEX(_clog_glog, s, l)

// File logging functions with tracing.

#define FLOG_T(s)                   { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPRINT(_clog_glog, s); \
                                    }
#define FLOGLN_T(s)                 { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPRINTLN(_clog_glog, s); \
                                    }
#define FLOGF_T(...)                { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPRINTF(_clog_glog, __VA_ARGS__); \
                                    }
#define FLOGFLN_T(...)              { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPRINTFLN(_clog_glog, __VA_ARGS__); \
                                    }
#define FLOG_PERROR_T(s)            { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPERROR(_clog_glog, s); \
                                    }
#define FLOG_PERRORF_T(...)         { \
                                        _CLOG_TIME(_clog_glog); \
                                        _CLOG_TRACING(_clog_glog); \
                                        FPERRORF(_clog_glog, __VA_ARGS__); \
                                    }

// File logging level functions.

#define FLOG_TRACE(s)               FLOG_T(CSYM_TRACE s)
#define FLOGLN_TRACE(s)             FLOGLN_T(CSYM_TRACE s)
#define FLOGF_TRACE(...)            FLOGF_T(CSYM_TRACE __VA_ARGS__)
#define FLOGFLN_TRACE(...)          FLOGFLN_T(CSYM_TRACE __VA_ARGS__)

#define FLOG_DEBUG(s)               FLOG_T(CSYM_DEBUG s)
#define FLOGLN_DEBUG(s)             FLOGLN_T(CSYM_DEBUG s)
#define FLOGF_DEBUG(...)            FLOGF_T(CSYM_DEBUG __VA_ARGS__)
#define FLOGFLN_DEBUG(...)          FLOGFLN_T(CSYM_DEBUG __VA_ARGS__)

#define FLOG_EXTRA(s)               FLOG(CSYM_EXTRA s)
#define FLOGLN_EXTRA(s)             FLOGLN(CSYM_EXTRA s)
#define FLOGF_EXTRA(...)            FLOGF(CSYM_EXTRA __VA_ARGS__)
#define FLOGFLN_EXTRA(...)          FLOGFLN(CSYM_EXTRA __VA_ARGS__)

#define FLOG_INFO(s)                FLOG(CSYM_INFO s)
#define FLOGLN_INFO(s)              FLOGLN(CSYM_INFO s)
#define FLOGF_INFO(...)             FLOGF(CSYM_INFO __VA_ARGS__)
#define FLOGFLN_INFO(...)           FLOGFLN(CSYM_INFO __VA_ARGS__)

#define FLOG_HEADER(s)              FLOG(CSYM_HEADER s)
#define FLOGLN_HEADER(s)            FLOGLN(CSYM_HEADER s)
#define FLOGF_HEADER(...)           FLOGF(CSYM_HEADER __VA_ARGS__)
#define FLOGFLN_HEADER(...)         FLOGFLN(CSYM_HEADER __VA_ARGS__)

#define FLOG_SUCCESS(s)             FLOG(CSYM_SUCCESS s)
#define FLOGLN_SUCCESS(s)           FLOGLN(CSYM_SUCCESS s)
#define FLOGF_SUCCESS(...)          FLOGF(CSYM_SUCCESS __VA_ARGS__)
#define FLOGFLN_SUCCESS(...)        FLOGFLN(CSYM_SUCCESS __VA_ARGS__)

#define FLOG_INPUT(s)               FLOG(CSYM_INPUT s)
#define FLOGLN_INPUT(s)             FLOGLN(CSYM_INPUT s)
#define FLOGF_INPUT(...)            FLOGF(CSYM_INPUT __VA_ARGS__)
#define FLOGFLN_INPUT(...)          FLOGFLN(CSYM_INPUT __VA_ARGS__)

#define FLOG_WARNING(s)             FLOG(CSYM_WARN s)
#define FLOGLN_WARNING(s)           FLOGLN(CSYM_WARN s)
#define FLOGF_WARNING(...)          FLOGF(CSYM_WARN __VA_ARGS__)
#define FLOGFLN_WARNING(...)        FLOGFLN(CSYM_WARN __VA_ARGS__)
#define FLOG_PERROR_WARNING(s)      FLOG_PERROR(CSYM_WARN s)
#define FLOG_PERRORF_WARNING(...)   FLOG_PERRORF(CSYM_WARN __VA_ARGS__)

#define FLOG_ERROR(s)               FLOG(CSYM_ERR s)
#define FLOGLN_ERROR(s)             FLOGLN(CSYM_ERR s)
#define FLOGF_ERROR(...)            FLOGF(CSYM_ERR __VA_ARGS__)
#define FLOGFLN_ERROR(...)          FLOGFLN(CSYM_ERR __VA_ARGS__)
#define FLOG_PERROR_ERROR(s)        FLOG_PERROR(CSYM_ERR s)
#define FLOG_PERRORF_ERROR(...)     FLOG_PERRORF(CSYM_ERR __VA_ARGS__)

#define FLOG_FATAL(s)               FLOG(CSYM_FATAL s)
#define FLOGLN_FATAL(s)             FLOGLN(CSYM_FATAL s)
#define FLOGF_FATAL(...)            FLOGF(CSYM_FATAL __VA_ARGS__)
#define FLOGFLN_FATAL(...)          FLOGFLN(CSYM_FATAL __VA_ARGS__)
#define FLOG_PERROR_FATAL(s)        FLOG_PERROR(CSYM_FATAL s)
#define FLOG_PERRORF_FATAL(...)     FLOG_PERRORF(CSYM_FATAL __VA_ARGS__)

// Aliases.

#define FLOG_TR(s)              FLOG_TRACE(s)      
#define FLOGLN_TR(s)            FLOGLN_TRACE(s)    
#define FLOGF_TR(...)           FLOGF_TRACE(__VA_ARGS__)   
#define FLOGFLN_TR(...)         FLOGFLN_TRACE(__VA_ARGS__) 

#define FLOG_DB(s)              FLOG_DEBUG(s)      
#define FLOGLN_DB(s)            FLOGLN_DEBUG(s)    
#define FLOGF_DB(...)           FLOGF_DEBUG(__VA_ARGS__)   
#define FLOGFLN_DB(...)         FLOGFLN_DEBUG(__VA_ARGS__) 

#define FLOG_EX(s)              FLOG_EXTRA(s)      
#define FLOGLN_EX(s)            FLOGLN_EXTRA(s)    
#define FLOGF_EX(...)           FLOGF_EXTRA(__VA_ARGS__)   
#define FLOGFLN_EX(...)         FLOGFLN_EXTRA(__VA_ARGS__) 

#define FLOG_IF(s)              FLOG_INFO(s)        
#define FLOGLN_IF(s)            FLOGLN_INFO(s)      
#define FLOGF_IF(...)           FLOGF_INFO(__VA_ARGS__)     
#define FLOGFLN_IF(...)         FLOGFLN_INFO(__VA_ARGS__)   

#define FLOG_HEAD(s)            FLOG_HEADER(s)      
#define FLOGLN_HEAD(s)          FLOGLN_HEADER(s)    
#define FLOGF_HEAD(...)         FLOGF_HEADER(__VA_ARGS__)   
#define FLOGFLN_HEAD(...)       FLOGFLN_HEADER(__VA_ARGS__) 

#define FLOG_HD(s)              FLOG_HEADER(s)      
#define FLOGLN_HD(s)            FLOGLN_HEADER(s)    
#define FLOGF_HD(...)           FLOGF_HEADER(__VA_ARGS__)   
#define FLOGFLN_HD(...)         FLOGFLN_HEADER(__VA_ARGS__) 

#define FLOG_SUC(s)             FLOG_SUCCESS(s)      
#define FLOGLN_SUC(s)           FLOGLN_SUCCESS(s)    
#define FLOGF_SUC(...)          FLOGF_SUCCESS(__VA_ARGS__)   
#define FLOGFLN_SUC(...)        FLOGFLN_SUCCESS(__VA_ARGS__) 

#define FLOG_SC(s)              FLOG_SUCCESS(s)      
#define FLOGLN_SC(s)            FLOGLN_SUCCESS(s)    
#define FLOGF_SC(...)           FLOGF_SUCCESS(__VA_ARGS__)   
#define FLOGFLN_SC(...)         FLOGFLN_SUCCESS(__VA_ARGS__) 

#define FLOG_IN(s)              FLOG_INPUT(s)       
#define FLOGLN_IN(s)            FLOGLN_INPUT(s)     
#define FLOGF_IN(...)           FLOGF_INPUT(__VA_ARGS__)    
#define FLOGFLN_IN(...)         FLOGFLN_INPUT(__VA_ARGS__)  

#define FLOG_WARN(s)            FLOG_WARNING(s)     
#define FLOGLN_WARN(s)          FLOGLN_WARNING(s)   
#define FLOGF_WARN(...)         FLOGF_WARNING(__VA_ARGS__)  
#define FLOGFLN_WARN(...)       FLOGFLN_WARNING(__VA_ARGS__)
#define FLOG_PERROR_WARN(s)     FLOG_PERROR_WARNING(s)   
#define FLOG_PERRORF_WARN(...)  FLOG_PERRORF_WARNING(__VA_ARGS__)

#define FLOG_WN(s)              FLOG_WARNING(s)     
#define FLOGLN_WN(s)            FLOGLN_WARNING(s)   
#define FLOGF_WN(...)           FLOGF_WARNING(__VA_ARGS__)  
#define FLOGFLN_WN(...)         FLOGFLN_WARNING(__VA_ARGS__)
#define FLOG_PERROR_WN(s)       FLOG_PERROR_WARNING(s)   
#define FLOG_PERRORF_WN(...)    FLOG_PERRORF_WARNING(__VA_ARGS__)

#define FLOG_ERR(s)             FLOG_ERROR(s)          
#define FLOGLN_ERR(s)           FLOGLN_ERROR(s)        
#define FLOGF_ERR(...)          FLOGF_ERROR(__VA_ARGS__)       
#define FLOGFLN_ERR(...)        FLOGFLN_ERROR(__VA_ARGS__)     
#define FLOG_PERROR_ERR(s)      FLOG_PERROR_ERROR(s)   
#define FLOG_PERRORF_ERR(...)   FLOG_PERRORF_ERROR(__VA_ARGS__)

#define FLOG_ER(s)              FLOG_ERROR(s)          
#define FLOGLN_ER(s)            FLOGLN_ERROR(s)        
#define FLOGF_ER(...)           FLOGF_ERROR(__VA_ARGS__)       
#define FLOGFLN_ER(...)         FLOGFLN_ERROR(__VA_ARGS__)     
#define FLOG_PERROR_ER(s)       FLOG_PERROR_ERROR(s)   
#define FLOG_PERRORF_ER(...)    FLOG_PERRORF_ERROR(__VA_ARGS__)

#define FLOG_FAT(s)             FLOG_FATAL(s)          
#define FLOGLN_FAT(s)           FLOGLN_FATAL(s)        
#define FLOGF_FAT(...)          FLOGF_FATAL(__VA_ARGS__)       
#define FLOGFLN_FAT(...)        FLOGFLN_FATAL(__VA_ARGS__)     
#define FLOG_PERROR_FAT(s)      FLOG_PERROR_FATAL(s)   
#define FLOG_PERRORF_FAT(...)   FLOG_PERRORF_FATAL(__VA_ARGS__)

#define FLOG_FT(s)              FLOG_FATAL(s)          
#define FLOGLN_FT(s)            FLOGLN_FATAL(s)        
#define FLOGF_FT(...)           FLOGF_FATAL(__VA_ARGS__)       
#define FLOGFLN_FT(...)         FLOGFLN_FATAL(__VA_ARGS__)     
#define FLOG_PERROR_FT(s)       FLOG_PERROR_FATAL(s)   
#define FLOG_PERRORF_FT(...)    FLOG_PERRORF_FATAL(__VA_ARGS__)


/**
 * Logging
 * =======
 *
 * The "log" functions allow for console and file logging based on the
 * configuration options.
 *
 */

#if LOG_MODE == LOG_MODE_NONE
    #define _CLOG_LOG(...)                  
    #define _CLOG_LOGLN(...)                  
    #define _CLOG_LOGF(...)                  
    #define _CLOG_LOGFLN(...)                  
    #define _CLOG_LOG_PERROR(s)                  
    #define _CLOG_LOG_PERRORF(...)                  

    #define _CLOG_LOG_T(...)                  
    #define _CLOG_LOGLN_T(...)                  
    #define _CLOG_LOGF_T(...)                  
    #define _CLOG_LOGFLN_T(...)                  
    #define _CLOG_LOG_PERROR_T(s)                  
    #define _CLOG_LOG_PERRORF_T(...)                  

    #define _CLOG_LOG_STREAM(...)           
    #define _CLOG_LOGLN_STREAM(...)
    #define _CLOG_LOGF_STREAM(...)           
    #define _CLOG_LOGFLN_STREAM(...)         
    #define _CLOG_LOG_STREAM_HEX(...)
    #define _CLOG_LOGLN_STREAM_HEX(...)
    #define _CLOG_LOG_STREAM_WIDE_HEX(...)
    #define _CLOG_LOGLN_STREAM_WIDE_HEX(...)

#elif LOG_MODE == LOG_MODE_CONSOLE
    #define _CLOG_LOG(c, s)              CCLOG(c, s)
    #define _CLOG_LOGLN(c, s)            CCLOGLN(c, s)
    #define _CLOG_LOGF(c, ...)           CCLOGF(c, __VA_ARGS__)
    #define _CLOG_LOGFLN(c, ...)         CCLOGFLN(c, __VA_ARGS__)
    #define _CLOG_LOG_PERROR(c, s)       CCLOG_PERROR(c, s)
    #define _CLOG_LOG_PERRORF(c, ...)    CCLOG_PERRORF(c, __VA_ARGS__)

    #define _CLOG_LOG_T(c, s)            CCLOG_T(c, s)
    #define _CLOG_LOGLN_T(c, s)          CCLOGLN_T(c, s)
    #define _CLOG_LOGF_T(c, ...)         CCLOGF_T(c, __VA_ARGS__)
    #define _CLOG_LOGFLN_T(c, ...)       CCLOGFLN_T(c, __VA_ARGS__)
    #define _CLOG_LOG_PERROR_T(c, s)     CCLOG_PERROR_T(c, s)
    #define _CLOG_LOG_PERRORF_T(c, ...)  CCLOG_PERRORF_T(c, __VA_ARGS__)
    
    // Log streams don't have color right now.

    #define _CLOG_LOG_STREAM(s)          CLOG_STREAM(s)
    #define _CLOG_LOGLN_STREAM(s)        CLOGLN_STREAM(s)
    #define _CLOG_LOGF_STREAM(...)       CLOGF_STREAM(__VA_ARGS__)    
    #define _CLOG_LOGFLN_STREAM(...)     CLOGFLN_STREAM(__VA_ARGS__)
    #define _CLOG_LOG_STREAM_HEX(s, l)   CLOG_STREAM_HEX(s, l)
    #define _CLOG_LOGLN_STREAM_HEX(s, l) CLOGLN_STREAM_HEX(s, l)
    #define _CLOG_LOG_STREAM_WIDE_HEX(s, l) CLOG_STREAM_WIDE_HEX(s, l)
    #define _CLOG_LOGLN_STREAM_WIDE_HEX(s, l) CLOGLN_STREAM_WIDE_HEX(s, l)

#elif LOG_MODE == LOG_MODE_FILE
    #define _CLOG_LOG(c, s)              FLOG(s)
    #define _CLOG_LOGLN(c, s)            FLOGLN(s)
    #define _CLOG_LOGF(c, ...)           FLOGF(__VA_ARGS__)
    #define _CLOG_LOGFLN(c, ...)         FLOGFLN(__VA_ARGS__)
    #define _CLOG_LOG_PERROR(c, s)       FLOG_PERROR(s)
    #define _CLOG_LOG_PERRORF(c, ...)    FLOG_PERRORF(__VA_ARGS__)

    #define _CLOG_LOG_T(c, s)            FLOG_T(s)
    #define _CLOG_LOGLN_T(c, s)          FLOGLN_T(s)
    #define _CLOG_LOGF_T(c, ...)         FLOGF_T(__VA_ARGS__)
    #define _CLOG_LOGFLN_T(c, ...)       FLOGFLN_T(__VA_ARGS__)
    #define _CLOG_LOG_PERROR_T(c, s)     FLOG_PERROR_T(s)
    #define _CLOG_LOG_PERRORF_T(c, ...)  FLOG_PERRORF_T(__VA_ARGS__)

    #define _CLOG_LOG_STREAM(s)          FLOG_STREAM(s)
    #define _CLOG_LOGLN_STREAM(s)        FLOGLN_STREAM(s)
    #define _CLOG_LOGF_STREAM(...)       FLOGF_STREAM(__VA_ARGS__)    
    #define _CLOG_LOGFLN_STREAM(...)     FLOGFLN_STREAM(__VA_ARGS__)
    #define _CLOG_LOG_STREAM_HEX(s, l)   FLOG_STREAM_HEX(s, l)
    #define _CLOG_LOGLN_STREAM_HEX(s, l) FLOGLN_STREAM_HEX(s, l)
    #define _CLOG_LOG_STREAM_WIDE_HEX(s, l) FLOG_STREAM_WIDE_HEX(s, l)
    #define _CLOG_LOGLN_STREAM_WIDE_HEX(s, l) FLOGLN_STREAM_WIDE_HEX(s, l)

#else
    #define _CLOG_LOG(c, s)              { CCLOG(c, s); FLOG(s); }
    #define _CLOG_LOGLN(c, s)            { CCLOGLN(c, s); FLOGLN(s); }
    #define _CLOG_LOGF(c, ...)           { CCLOGF(c, __VA_ARGS__); FLOGF(__VA_ARGS__); }
    #define _CLOG_LOGFLN(c, ...)         { CCLOGFLN(c, __VA_ARGS__); FLOGFLN(__VA_ARGS__); }
    #define _CLOG_LOG_PERROR(c, s)       { CCLOG_PERROR(c, s); FLOG_PERROR(s); }
    #define _CLOG_LOG_PERRORF(c, ...)    { CCLOG_PERRORF(c, __VA_ARGS__); FLOG_PERRORF(__VA_ARGS__); }

    #define _CLOG_LOG_T(c, s)            { CCLOG_T(c, s); FLOG_T(s); }
    #define _CLOG_LOGLN_T(c, s)          { CCLOGLN_T(c, s); FLOGLN_T(s); }
    #define _CLOG_LOGF_T(c, ...)         { CCLOGF_T(c, __VA_ARGS__); FLOGF_T(__VA_ARGS__); }
    #define _CLOG_LOGFLN_T(c, ...)       { CCLOGFLN_T(c, __VA_ARGS__); FLOGFLN_T(__VA_ARGS__); }
    #define _CLOG_LOG_PERROR_T(c, s)     { CCLOG_PERROR_T(c, s); FLOG_PERROR_T(s); }
    #define _CLOG_LOG_PERRORF_T(c, ...)  { CCLOG_PERRORF_T(c, __VA_ARGS__); FLOG_PERRORF_T(__VA_ARGS__); }

    #define _CLOG_LOG_STREAM(s)          { CLOG_STREAM(s); FLOG_STREAM(s); }
    #define _CLOG_LOGLN_STREAM(s)        { CLOGLN_STREAM(s); FLOGFLN_STREAM(s); }
    #define _CLOG_LOGF_STREAM(...)       { CLOGF_STREAM(__VA_ARGS__); FLOGF_STREAM(__VA_ARGS__); }
    #define _CLOG_LOGFLN_STREAM(...)     { CLOGFLN_STREAM(__VA_ARGS__); FLOGFLN_STREAM(__VA_ARGS__); }
    #define _CLOG_LOG_STREAM_HEX(s, l)   { CLOG_STREAM_HEX(s, l); FLOG_STREAM_HEX(s, l); }
    #define _CLOG_LOGLN_STREAM_HEX(s, l) { CLOGLN_STREAM_HEX(s, l); FLOGLN_STREAM_HEX(s, l); }
    #define _CLOG_LOG_STREAM_WIDE_HEX(s, l) { CLOG_STREAM_WIDE_HEX(s, l); FLOG_STREAM_WIDE_HEX(s, l); }
    #define _CLOG_LOGLN_STREAM_WIDE_HEX(s, l) { CLOGLN_STREAM_WIDE_HEX(s, l); FLOGLN_STREAM_WIDE_HEX(s, l); }
    
#endif

#define LOG(s)                      _CLOG_LOG(_CLOG_NOTHING, s)
#define LOGLN(s)                    _CLOG_LOGLN(_CLOG_NOTHING, s)
#define LOGF(...)                   _CLOG_LOGF(_CLOG_NOTHING, __VA_ARGS__)
#define LOGFLN(...)                 _CLOG_LOGFLN(_CLOG_NOTHING, __VA_ARGS__)
#define LOG_PERROR(s)               _CLOG_LOG_PERROR(_CLOG_NOTHING, s)
#define LOG_PERRORF(...)            _CLOG_LOG_PERRORF(_CLOG_NOTHING, __VA_ARGS__)

#define LOG_T(s)                    _CLOG_LOG_T(_CLOG_NOTHING, s)
#define LOGLN_T(s)                  _CLOG_LOGLN_T(_CLOG_NOTHING, s)
#define LOGF_T(...)                 _CLOG_LOGF_T(_CLOG_NOTHING, __VA_ARGS__)
#define LOGFLN_T(...)               _CLOG_LOGFLN_T(_CLOG_NOTHING, __VA_ARGS__)
#define LOG_PERROR_T(s)             _CLOG_LOG_PERROR_T(_CLOG_NOTHING, s)
#define LOG_PERRORF_T(...)          _CLOG_LOG_PERRORF_T(_CLOG_NOTHING, __VA_ARGS__)

#define LOG_STREAM(s)               _CLOG_LOG_STREAM(s)
#define LOGLN_STREAM(s)             _CLOG_LOGLN_STREAM(s)
#define LOGF_STREAM(...)            _CLOG_LOGF_STREAM(__VA_ARGS__)
#define LOGFLN_STREAM(...)          _CLOG_LOGFLN_STREAM(__VA_ARGS__)
#define LOG_STREAM_HEX(s, l)        _CLOG_LOG_STREAM_HEX(s, l)
#define LOGLN_STREAM_HEX(s, l)      _CLOG_LOGLN_STREAM_HEX(s, l)
#define LOG_STREAM_WIDE_HEX(s, l)   _CLOG_LOG_STREAM_WIDE_HEX(s, l)
#define LOGLN_STREAM_WIDE_HEX(s, l) _CLOG_LOGLN_STREAM_WIDE_HEX(s, l)

#define LOG_TRACE(s)                _CLOG_LOG_T(C_TRACE, CSYM_TRACE s)
#define LOGLN_TRACE(s)              _CLOG_LOGLN_T(C_TRACE, CSYM_TRACE s)
#define LOGF_TRACE(...)             _CLOG_LOGF_T(C_TRACE, CSYM_TRACE __VA_ARGS__)
#define LOGFLN_TRACE(...)           _CLOG_LOGFLN_T(C_TRACE, CSYM_TRACE __VA_ARGS__)

#define LOG_DEBUG(s)                _CLOG_LOG_T(C_DEBUG, CSYM_DEBUG s)
#define LOGLN_DEBUG(s)              _CLOG_LOGLN_T(C_DEBUG, CSYM_DEBUG s)
#define LOGF_DEBUG(...)             _CLOG_LOGF_T(C_DEBUG, CSYM_DEBUG __VA_ARGS__)
#define LOGFLN_DEBUG(...)           _CLOG_LOGFLN_T(C_DEBUG, CSYM_DEBUG __VA_ARGS__)

#define LOG_EXTRA(s)                _CLOG_LOG(C_EXTRA, CSYM_EXTRA s)
#define LOGLN_EXTRA(s)              _CLOG_LOGLN(C_EXTRA, CSYM_EXTRA s)
#define LOGF_EXTRA(...)             _CLOG_LOGF(C_EXTRA, CSYM_EXTRA __VA_ARGS__)
#define LOGFLN_EXTRA(...)           _CLOG_LOGFLN(C_EXTRA, CSYM_EXTRA __VA_ARGS__)

#define LOG_INFO(s)                 _CLOG_LOG(C_INFO, CSYM_INFO s)
#define LOGLN_INFO(s)               _CLOG_LOGLN(C_INFO, CSYM_INFO s)
#define LOGF_INFO(...)              _CLOG_LOGF(C_INFO, CSYM_INFO __VA_ARGS__)
#define LOGFLN_INFO(...)            _CLOG_LOGFLN(C_INFO, CSYM_INFO __VA_ARGS__)

#define LOG_HEADER(s)               _CLOG_LOG(C_HEADER, CSYM_HEADER s)
#define LOGLN_HEADER(s)             _CLOG_LOGLN(C_HEADER, CSYM_HEADER s)
#define LOGF_HEADER(...)            _CLOG_LOGF(C_HEADER, CSYM_HEADER __VA_ARGS__)
#define LOGFLN_HEADER(...)          _CLOG_LOGFLN(C_HEADER, CSYM_HEADER __VA_ARGS__)

#define LOG_SUCCESS(s)              _CLOG_LOG(C_SUCCESS, CSYM_SUCCESS s)
#define LOGLN_SUCCESS(s)            _CLOG_LOGLN(C_SUCCESS, CSYM_SUCCESS s)
#define LOGF_SUCCESS(...)           _CLOG_LOGF(C_SUCCESS, CSYM_SUCCESS __VA_ARGS__)
#define LOGFLN_SUCCESS(...)         _CLOG_LOGFLN(C_SUCCESS, CSYM_SUCCESS __VA_ARGS__)

#define LOG_INPUT(s)                _CLOG_LOG(C_INPUT, CSYM_INPUT s)
#define LOGLN_INPUT(s)              _CLOG_LOGLN(C_INPUT, CSYM_INPUT s)
#define LOGF_INPUT(...)             _CLOG_LOGF(C_INPUT, CSYM_INPUT __VA_ARGS__)
#define LOGFLN_INPUT(...)           _CLOG_LOGFLN(C_INPUT, CSYM_INPUT __VA_ARGS__)

#define LOG_WARNING(s)              _CLOG_LOG(C_WARN, CSYM_WARN s)
#define LOGLN_WARNING(s)            _CLOG_LOGLN(C_WARN, CSYM_WARN s)
#define LOGF_WARNING(...)           _CLOG_LOGF(C_WARN, CSYM_WARN __VA_ARGS__)
#define LOGFLN_WARNING(...)         _CLOG_LOGFLN(C_WARN, CSYM_WARN __VA_ARGS__)
#define LOG_PERROR_WARNING(s)       _CLOG_LOG_PERROR(C_WARN, CSYM_WARN s)
#define LOG_PERRORF_WARNING(...)    _CLOG_LOG_PERRORF(C_WARN, CSYM_WARN __VA_ARGS__)

#define LOG_ERROR(s)                _CLOG_LOG(C_ERR, CSYM_ERR s)
#define LOGLN_ERROR(s)              _CLOG_LOGLN(C_ERR, CSYM_ERR s)
#define LOGF_ERROR(...)             _CLOG_LOGF(C_ERR, CSYM_ERR __VA_ARGS__)
#define LOGFLN_ERROR(...)           _CLOG_LOGFLN(C_ERR, CSYM_ERR __VA_ARGS__)
#define LOG_PERROR_ERROR(s)         _CLOG_LOG_PERROR(C_ERR, CSYM_ERR s)
#define LOG_PERRORF_ERROR(...)      _CLOG_LOG_PERRORF(C_ERR, CSYM_ERR __VA_ARGS__)

#define LOG_FATAL(s)                _CLOG_LOG(C_FATAL, CSYM_FATAL s)
#define LOGLN_FATAL(s)              _CLOG_LOGLN(C_FATAL, CSYM_FATAL s)
#define LOGF_FATAL(...)             _CLOG_LOGF(C_FATAL, CSYM_FATAL __VA_ARGS__)
#define LOGFLN_FATAL(...)           _CLOG_LOGFLN(C_FATAL, CSYM_FATAL __VA_ARGS__)
#define LOG_PERROR_FATAL(s)         _CLOG_LOG_PERROR(C_FATAL, CSYM_FATAL s)
#define LOG_PERRORF_FATAL(...)      _CLOG_LOG_PERRORF(C_FATAL, CSYM_FATAL __VA_ARGS__)

// Aliases.

#define LOG_TR(s)              LOG_TRACE(s)      
#define LOGLN_TR(s)            LOGLN_TRACE(s)    
#define LOGF_TR(...)           LOGF_TRACE(__VA_ARGS__)   
#define LOGFLN_TR(...)         LOGFLN_TRACE(__VA_ARGS__) 

#define LOG_DB(s)              LOG_DEBUG(s)      
#define LOGLN_DB(s)            LOGLN_DEBUG(s)    
#define LOGF_DB(...)           LOGF_DEBUG(__VA_ARGS__)   
#define LOGFLN_DB(...)         LOGFLN_DEBUG(__VA_ARGS__) 

#define LOG_EX(s)              LOG_EXTRA(s)      
#define LOGLN_EX(s)            LOGLN_EXTRA(s)    
#define LOGF_EX(...)           LOGF_EXTRA(__VA_ARGS__)   
#define LOGFLN_EX(...)         LOGFLN_EXTRA(__VA_ARGS__) 

#define LOG_IF(s)              LOG_INFO(s)        
#define LOGLN_IF(s)            LOGLN_INFO(s)      
#define LOGF_IF(...)           LOGF_INFO(__VA_ARGS__)     
#define LOGFLN_IF(...)         LOGFLN_INFO(__VA_ARGS__)   

#define LOG_HEAD(s)            LOG_HEADER(s)      
#define LOGLN_HEAD(s)          LOGLN_HEADER(s)    
#define LOGF_HEAD(...)         LOGF_HEADER(__VA_ARGS__)   
#define LOGFLN_HEAD(...)       LOGFLN_HEADER(__VA_ARGS__) 

#define LOG_HD(s)              LOG_HEADER(s)      
#define LOGLN_HD(s)            LOGLN_HEADER(s)    
#define LOGF_HD(...)           LOGF_HEADER(__VA_ARGS__)   
#define LOGFLN_HD(...)         LOGFLN_HEADER(__VA_ARGS__) 

#define LOG_SUC(s)             LOG_SUCCESS(s)      
#define LOGLN_SUC(s)           LOGLN_SUCCESS(s)    
#define LOGF_SUC(...)          LOGF_SUCCESS(__VA_ARGS__)   
#define LOGFLN_SUC(...)        LOGFLN_SUCCESS(__VA_ARGS__) 

#define LOG_SC(s)              LOG_SUCCESS(s)      
#define LOGLN_SC(s)            LOGLN_SUCCESS(s)    
#define LOGF_SC(...)           LOGF_SUCCESS(__VA_ARGS__)   
#define LOGFLN_SC(...)         LOGFLN_SUCCESS(__VA_ARGS__) 

#define LOG_IN(s)              LOG_INPUT(s)       
#define LOGLN_IN(s)            LOGLN_INPUT(s)     
#define LOGF_IN(...)           LOGF_INPUT(__VA_ARGS__)    
#define LOGFLN_IN(...)         LOGFLN_INPUT(__VA_ARGS__)  

#define LOG_WARN(s)            LOG_WARNING(s)     
#define LOGLN_WARN(s)          LOGLN_WARNING(s)   
#define LOGF_WARN(...)         LOGF_WARNING(__VA_ARGS__)  
#define LOGFLN_WARN(...)       LOGFLN_WARNING(__VA_ARGS__)
#define LOG_PERROR_WARN(s)     LOG_PERROR_WARNING(s)   
#define LOG_PERRORF_WARN(...)  LOG_PERRORF_WARNING(__VA_ARGS__)

#define LOG_WN(s)              LOG_WARNING(s)     
#define LOGLN_WN(s)            LOGLN_WARNING(s)   
#define LOGF_WN(...)           LOGF_WARNING(__VA_ARGS__)  
#define LOGFLN_WN(...)         LOGFLN_WARNING(__VA_ARGS__)
#define LOG_PERROR_WN(s)       LOG_PERROR_WARNING(s)   
#define LOG_PERRORF_WN(...)    LOG_PERRORF_WARNING(__VA_ARGS__)

#define LOG_ERR(s)             LOG_ERROR(s)          
#define LOGLN_ERR(s)           LOGLN_ERROR(s)        
#define LOGF_ERR(...)          LOGF_ERROR(__VA_ARGS__)       
#define LOGFLN_ERR(...)        LOGFLN_ERROR(__VA_ARGS__)     
#define LOG_PERROR_ERR(s)      LOG_PERROR_ERROR(s)   
#define LOG_PERRORF_ERR(...)   LOG_PERRORF_ERROR(__VA_ARGS__)

#define LOG_ER(s)              LOG_ERROR(s)          
#define LOGLN_ER(s)            LOGLN_ERROR(s)        
#define LOGF_ER(...)           LOGF_ERROR(__VA_ARGS__)       
#define LOGFLN_ER(...)         LOGFLN_ERROR(__VA_ARGS__)     
#define LOG_PERROR_ER(s)       LOG_PERROR_ERROR(s)   
#define LOG_PERRORF_ER(...)    LOG_PERRORF_ERROR(__VA_ARGS__)

#define LOG_FAT(s)             LOG_FATAL(s)          
#define LOGLN_FAT(s)           LOGLN_FATAL(s)        
#define LOGF_FAT(...)          LOGF_FATAL(__VA_ARGS__)       
#define LOGFLN_FAT(...)        LOGFLN_FATAL(__VA_ARGS__)     
#define LOG_PERROR_FAT(s)      LOG_PERROR_FATAL(s)   
#define LOG_PERRORF_FAT(...)   LOG_PERRORF_FATAL(__VA_ARGS__)

#define LOG_FT(s)              LOG_FATAL(s)          
#define LOGLN_FT(s)            LOGLN_FATAL(s)        
#define LOGF_FT(...)           LOGF_FATAL(__VA_ARGS__)       
#define LOGFLN_FT(...)         LOGFLN_FATAL(__VA_ARGS__)     
#define LOG_PERROR_FT(s)       LOG_PERROR_FATAL(s)   
#define LOG_PERRORF_FT(...)    LOG_PERRORF_FATAL(__VA_ARGS__)


#if LOG_LEVEL == LOG_LEVEL_NONE

#undef CLOG
#define CLOG(...)
#undef CLOGLN
#define CLOGLN(...)
#undef CLOGF
#define CLOGF(...)
#undef CLOGFLN
#define CLOGFLN(...)
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
#undef CLOG_STREAM_HEX
#define CLOG_STREAM_HEX(...)
#undef CLOGLN_STREAM_HEX
#define CLOGLN_STREAM_HEX(...)
#undef CLOG_STREAM_WIDE_HEX
#define CLOG_STREAM_WIDE_HEX(...)
#undef CLOGLN_STREAM_WIDE_HEX
#define CLOGLN_STREAM_WIDE_HEX(...)
#undef CLOG_T
#define CLOG_T(...)
#undef CLOGLN_T
#define CLOGLN_T(...)
#undef CLOGF_T
#define CLOGF_T(...)
#undef CLOGFLN_T
#define CLOGFLN_T(...)
#undef CLOG_PERROR_T
#define CLOG_PERROR_T(...)
#undef CLOG_PERRORF_T
#define CLOG_PERRORF_T(...)
#undef CCLOG
#define CCLOG(...)
#undef CCLOGLN
#define CCLOGLN(...)
#undef CCLOGF
#define CCLOGF(...)
#undef CCLOGFLN
#define CCLOGFLN(...)
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
#undef CCLOG_STREAM_HEX
#define CCLOG_STREAM_HEX(...)
#undef CCLOGLN_STREAM_HEX
#define CCLOGLN_STREAM_HEX(...)
#undef CCLOG_STREAM_WIDE_HEX
#define CCLOG_STREAM_WIDE_HEX(...)
#undef CCLOGLN_STREAM_WIDE_HEX
#define CCLOGLN_STREAM_WIDE_HEX(...)
#undef CCLOG_T
#define CCLOG_T(...)
#undef CCLOGLN_T
#define CCLOGLN_T(...)
#undef CCLOGF_T
#define CCLOGF_T(...)
#undef CCLOGFLN_T
#define CCLOGFLN_T(...)
#undef CCLOG_PERROR_T
#define CCLOG_PERROR_T(...)
#undef CCLOG_PERRORF_T
#define CCLOG_PERRORF_T(...)
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
#undef CLOG_HEAD
#define CLOG_HEAD(...)
#undef CLOGLN_HEAD
#define CLOGLN_HEAD(...)
#undef CLOGF_HEAD
#define CLOGF_HEAD(...)
#undef CLOGFLN_HEAD
#define CLOGFLN_HEAD(...)
#undef CLOG_HD
#define CLOG_HD(...)
#undef CLOGLN_HD
#define CLOGLN_HD(...)
#undef CLOGF_HD
#define CLOGF_HD(...)
#undef CLOGFLN_HD
#define CLOGFLN_HD(...)
#undef CLOG_SUC
#define CLOG_SUC(...)
#undef CLOGLN_SUC
#define CLOGLN_SUC(...)
#undef CLOGF_SUC
#define CLOGF_SUC(...)
#undef CLOGFLN_SUC
#define CLOGFLN_SUC(...)
#undef CLOG_SC
#define CLOG_SC(...)
#undef CLOGLN_SC
#define CLOGLN_SC(...)
#undef CLOGF_SC
#define CLOGF_SC(...)
#undef CLOGFLN_SC
#define CLOGFLN_SC(...)
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
#undef FLOG
#define FLOG(...)
#undef FLOGLN
#define FLOGLN(...)
#undef FLOGF
#define FLOGF(...)
#undef FLOGFLN
#define FLOGFLN(...)
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
#undef FLOG_STREAM_HEX
#define FLOG_STREAM_HEX(...)
#undef FLOGLN_STREAM_HEX
#define FLOGLN_STREAM_HEX(...)
#undef FLOG_STREAM_WIDE_HEX
#define FLOG_STREAM_WIDE_HEX(...)
#undef FLOGLN_STREAM_WIDE_HEX
#define FLOGLN_STREAM_WIDE_HEX(...)
#undef FLOG_T
#define FLOG_T(...)
#undef FLOGLN_T
#define FLOGLN_T(...)
#undef FLOGF_T
#define FLOGF_T(...)
#undef FLOGFLN_T
#define FLOGFLN_T(...)
#undef FLOG_PERROR_T
#define FLOG_PERROR_T(...)
#undef FLOG_PERRORF_T
#define FLOG_PERRORF_T(...)
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
#undef FLOG_HEAD
#define FLOG_HEAD(...)
#undef FLOGLN_HEAD
#define FLOGLN_HEAD(...)
#undef FLOGF_HEAD
#define FLOGF_HEAD(...)
#undef FLOGFLN_HEAD
#define FLOGFLN_HEAD(...)
#undef FLOG_HD
#define FLOG_HD(...)
#undef FLOGLN_HD
#define FLOGLN_HD(...)
#undef FLOGF_HD
#define FLOGF_HD(...)
#undef FLOGFLN_HD
#define FLOGFLN_HD(...)
#undef FLOG_SUC
#define FLOG_SUC(...)
#undef FLOGLN_SUC
#define FLOGLN_SUC(...)
#undef FLOGF_SUC
#define FLOGF_SUC(...)
#undef FLOGFLN_SUC
#define FLOGFLN_SUC(...)
#undef FLOG_SC
#define FLOG_SC(...)
#undef FLOGLN_SC
#define FLOGLN_SC(...)
#undef FLOGF_SC
#define FLOGF_SC(...)
#undef FLOGFLN_SC
#define FLOGFLN_SC(...)
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
#undef LOG
#define LOG(...)
#undef LOGLN
#define LOGLN(...)
#undef LOGF
#define LOGF(...)
#undef LOGFLN
#define LOGFLN(...)
#undef LOG_PERROR
#define LOG_PERROR(...)
#undef LOG_PERRORF
#define LOG_PERRORF(...)
#undef LOG_T
#define LOG_T(...)
#undef LOGLN_T
#define LOGLN_T(...)
#undef LOGF_T
#define LOGF_T(...)
#undef LOGFLN_T
#define LOGFLN_T(...)
#undef LOG_PERROR_T
#define LOG_PERROR_T(...)
#undef LOG_PERRORF_T
#define LOG_PERRORF_T(...)
#undef LOG_STREAM
#define LOG_STREAM(...)
#undef LOGLN_STREAM
#define LOGLN_STREAM(...)
#undef LOGF_STREAM
#define LOGF_STREAM(...)
#undef LOGFLN_STREAM
#define LOGFLN_STREAM(...)
#undef LOG_STREAM_HEX
#define LOG_STREAM_HEX(...)
#undef LOGLN_STREAM_HEX
#define LOGLN_STREAM_HEX(...)
#undef LOG_STREAM_WIDE_HEX
#define LOG_STREAM_WIDE_HEX(...)
#undef LOGLN_STREAM_WIDE_HEX
#define LOGLN_STREAM_WIDE_HEX(...)
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
#undef LOG_HEAD
#define LOG_HEAD(...)
#undef LOGLN_HEAD
#define LOGLN_HEAD(...)
#undef LOGF_HEAD
#define LOGF_HEAD(...)
#undef LOGFLN_HEAD
#define LOGFLN_HEAD(...)
#undef LOG_HD
#define LOG_HD(...)
#undef LOGLN_HD
#define LOGLN_HD(...)
#undef LOGF_HD
#define LOGF_HD(...)
#undef LOGFLN_HD
#define LOGFLN_HD(...)
#undef LOG_SUC
#define LOG_SUC(...)
#undef LOGLN_SUC
#define LOGLN_SUC(...)
#undef LOGF_SUC
#define LOGF_SUC(...)
#undef LOGFLN_SUC
#define LOGFLN_SUC(...)
#undef LOG_SC
#define LOG_SC(...)
#undef LOGLN_SC
#define LOGLN_SC(...)
#undef LOGF_SC
#define LOGF_SC(...)
#undef LOGFLN_SC
#define LOGFLN_SC(...)
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

#elif LOG_LEVEL == LOG_LEVEL_ERR

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
#undef CLOG_HEAD
#define CLOG_HEAD(...)
#undef CLOGLN_HEAD
#define CLOGLN_HEAD(...)
#undef CLOGF_HEAD
#define CLOGF_HEAD(...)
#undef CLOGFLN_HEAD
#define CLOGFLN_HEAD(...)
#undef CLOG_HD
#define CLOG_HD(...)
#undef CLOGLN_HD
#define CLOGLN_HD(...)
#undef CLOGF_HD
#define CLOGF_HD(...)
#undef CLOGFLN_HD
#define CLOGFLN_HD(...)
#undef CLOG_SUC
#define CLOG_SUC(...)
#undef CLOGLN_SUC
#define CLOGLN_SUC(...)
#undef CLOGF_SUC
#define CLOGF_SUC(...)
#undef CLOGFLN_SUC
#define CLOGFLN_SUC(...)
#undef CLOG_SC
#define CLOG_SC(...)
#undef CLOGLN_SC
#define CLOGLN_SC(...)
#undef CLOGF_SC
#define CLOGF_SC(...)
#undef CLOGFLN_SC
#define CLOGFLN_SC(...)
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
#undef FLOG_HEAD
#define FLOG_HEAD(...)
#undef FLOGLN_HEAD
#define FLOGLN_HEAD(...)
#undef FLOGF_HEAD
#define FLOGF_HEAD(...)
#undef FLOGFLN_HEAD
#define FLOGFLN_HEAD(...)
#undef FLOG_HD
#define FLOG_HD(...)
#undef FLOGLN_HD
#define FLOGLN_HD(...)
#undef FLOGF_HD
#define FLOGF_HD(...)
#undef FLOGFLN_HD
#define FLOGFLN_HD(...)
#undef FLOG_SUC
#define FLOG_SUC(...)
#undef FLOGLN_SUC
#define FLOGLN_SUC(...)
#undef FLOGF_SUC
#define FLOGF_SUC(...)
#undef FLOGFLN_SUC
#define FLOGFLN_SUC(...)
#undef FLOG_SC
#define FLOG_SC(...)
#undef FLOGLN_SC
#define FLOGLN_SC(...)
#undef FLOGF_SC
#define FLOGF_SC(...)
#undef FLOGFLN_SC
#define FLOGFLN_SC(...)
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
#undef LOG_HEAD
#define LOG_HEAD(...)
#undef LOGLN_HEAD
#define LOGLN_HEAD(...)
#undef LOGF_HEAD
#define LOGF_HEAD(...)
#undef LOGFLN_HEAD
#define LOGFLN_HEAD(...)
#undef LOG_HD
#define LOG_HD(...)
#undef LOGLN_HD
#define LOGLN_HD(...)
#undef LOGF_HD
#define LOGF_HD(...)
#undef LOGFLN_HD
#define LOGFLN_HD(...)
#undef LOG_SUC
#define LOG_SUC(...)
#undef LOGLN_SUC
#define LOGLN_SUC(...)
#undef LOGF_SUC
#define LOGF_SUC(...)
#undef LOGFLN_SUC
#define LOGFLN_SUC(...)
#undef LOG_SC
#define LOG_SC(...)
#undef LOGLN_SC
#define LOGLN_SC(...)
#undef LOGF_SC
#define LOGF_SC(...)
#undef LOGFLN_SC
#define LOGFLN_SC(...)
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

#elif LOG_LEVEL == LOG_LEVEL_WARN

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
#undef CLOG_INPUT
#define CLOG_INPUT(...)
#undef CLOGLN_INPUT
#define CLOGLN_INPUT(...)
#undef CLOGF_INPUT
#define CLOGF_INPUT(...)
#undef CLOGFLN_INPUT
#define CLOGFLN_INPUT(...)
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
#undef CLOG_HEAD
#define CLOG_HEAD(...)
#undef CLOGLN_HEAD
#define CLOGLN_HEAD(...)
#undef CLOGF_HEAD
#define CLOGF_HEAD(...)
#undef CLOGFLN_HEAD
#define CLOGFLN_HEAD(...)
#undef CLOG_HD
#define CLOG_HD(...)
#undef CLOGLN_HD
#define CLOGLN_HD(...)
#undef CLOGF_HD
#define CLOGF_HD(...)
#undef CLOGFLN_HD
#define CLOGFLN_HD(...)
#undef CLOG_SUC
#define CLOG_SUC(...)
#undef CLOGLN_SUC
#define CLOGLN_SUC(...)
#undef CLOGF_SUC
#define CLOGF_SUC(...)
#undef CLOGFLN_SUC
#define CLOGFLN_SUC(...)
#undef CLOG_SC
#define CLOG_SC(...)
#undef CLOGLN_SC
#define CLOGLN_SC(...)
#undef CLOGF_SC
#define CLOGF_SC(...)
#undef CLOGFLN_SC
#define CLOGFLN_SC(...)
#undef CLOG_IN
#define CLOG_IN(...)
#undef CLOGLN_IN
#define CLOGLN_IN(...)
#undef CLOGF_IN
#define CLOGF_IN(...)
#undef CLOGFLN_IN
#define CLOGFLN_IN(...)
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
#undef FLOG_INPUT
#define FLOG_INPUT(...)
#undef FLOGLN_INPUT
#define FLOGLN_INPUT(...)
#undef FLOGF_INPUT
#define FLOGF_INPUT(...)
#undef FLOGFLN_INPUT
#define FLOGFLN_INPUT(...)
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
#undef FLOG_HEAD
#define FLOG_HEAD(...)
#undef FLOGLN_HEAD
#define FLOGLN_HEAD(...)
#undef FLOGF_HEAD
#define FLOGF_HEAD(...)
#undef FLOGFLN_HEAD
#define FLOGFLN_HEAD(...)
#undef FLOG_HD
#define FLOG_HD(...)
#undef FLOGLN_HD
#define FLOGLN_HD(...)
#undef FLOGF_HD
#define FLOGF_HD(...)
#undef FLOGFLN_HD
#define FLOGFLN_HD(...)
#undef FLOG_SUC
#define FLOG_SUC(...)
#undef FLOGLN_SUC
#define FLOGLN_SUC(...)
#undef FLOGF_SUC
#define FLOGF_SUC(...)
#undef FLOGFLN_SUC
#define FLOGFLN_SUC(...)
#undef FLOG_SC
#define FLOG_SC(...)
#undef FLOGLN_SC
#define FLOGLN_SC(...)
#undef FLOGF_SC
#define FLOGF_SC(...)
#undef FLOGFLN_SC
#define FLOGFLN_SC(...)
#undef FLOG_IN
#define FLOG_IN(...)
#undef FLOGLN_IN
#define FLOGLN_IN(...)
#undef FLOGF_IN
#define FLOGF_IN(...)
#undef FLOGFLN_IN
#define FLOGFLN_IN(...)
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
#undef LOG_INPUT
#define LOG_INPUT(...)
#undef LOGLN_INPUT
#define LOGLN_INPUT(...)
#undef LOGF_INPUT
#define LOGF_INPUT(...)
#undef LOGFLN_INPUT
#define LOGFLN_INPUT(...)
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
#undef LOG_HEAD
#define LOG_HEAD(...)
#undef LOGLN_HEAD
#define LOGLN_HEAD(...)
#undef LOGF_HEAD
#define LOGF_HEAD(...)
#undef LOGFLN_HEAD
#define LOGFLN_HEAD(...)
#undef LOG_HD
#define LOG_HD(...)
#undef LOGLN_HD
#define LOGLN_HD(...)
#undef LOGF_HD
#define LOGF_HD(...)
#undef LOGFLN_HD
#define LOGFLN_HD(...)
#undef LOG_SUC
#define LOG_SUC(...)
#undef LOGLN_SUC
#define LOGLN_SUC(...)
#undef LOGF_SUC
#define LOGF_SUC(...)
#undef LOGFLN_SUC
#define LOGFLN_SUC(...)
#undef LOG_SC
#define LOG_SC(...)
#undef LOGLN_SC
#define LOGLN_SC(...)
#undef LOGF_SC
#define LOGF_SC(...)
#undef LOGFLN_SC
#define LOGFLN_SC(...)
#undef LOG_IN
#define LOG_IN(...)
#undef LOGLN_IN
#define LOGLN_IN(...)
#undef LOGF_IN
#define LOGF_IN(...)
#undef LOGFLN_IN
#define LOGFLN_IN(...)

#elif LOG_LEVEL == LOG_LEVEL_INFO

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

#elif LOG_LEVEL == LOG_LEVEL_EXTRA

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

#elif LOG_LEVEL == LOG_LEVEL_DEBUG

#undef CLOG_TRACE
#define CLOG_TRACE(...)
#undef CLOGLN_TRACE
#define CLOGLN_TRACE(...)
#undef CLOGF_TRACE
#define CLOGF_TRACE(...)
#undef CLOGFLN_TRACE
#define CLOGFLN_TRACE(...)
#undef CLOG_TR
#define CLOG_TR(...)
#undef CLOGLN_TR
#define CLOGLN_TR(...)
#undef CLOGF_TR
#define CLOGF_TR(...)
#undef CLOGFLN_TR
#define CLOGFLN_TR(...)
#undef FLOG_TRACE
#define FLOG_TRACE(...)
#undef FLOGLN_TRACE
#define FLOGLN_TRACE(...)
#undef FLOGF_TRACE
#define FLOGF_TRACE(...)
#undef FLOGFLN_TRACE
#define FLOGFLN_TRACE(...)
#undef FLOG_TR
#define FLOG_TR(...)
#undef FLOGLN_TR
#define FLOGLN_TR(...)
#undef FLOGF_TR
#define FLOGF_TR(...)
#undef FLOGFLN_TR
#define FLOGFLN_TR(...)
#undef LOG_TRACE
#define LOG_TRACE(...)
#undef LOGLN_TRACE
#define LOGLN_TRACE(...)
#undef LOGF_TRACE
#define LOGF_TRACE(...)
#undef LOGFLN_TRACE
#define LOGFLN_TRACE(...)
#undef LOG_TR
#define LOG_TR(...)
#undef LOGLN_TR
#define LOGLN_TR(...)
#undef LOGF_TR
#define LOGF_TR(...)
#undef LOGFLN_TR
#define LOGFLN_TR(...)

#endif


// Types.
// None.


// Structs and enums.
// None.


// External Functions.
// None.


// Function Declarations.
// None.


// Globals.

CLOG_DECLARE;


