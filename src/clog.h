
/**
 * Clog C header - Provides macros for color console and file logging.
 *
 * Copyright (C) <year>  <name of author>
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
 * jdkfjkdskf sdklfj ksdjkfj ksdjkfjsdkj f
 *
 * djfkjsdk jfkjsdkjfkjsdkljfkljsdkfjklsdjfk jsdkjfkjsdkj f
 * Requirements:
 *
 *      Currently uses standard C library.
 *
 * Use:
 *
 *      Macros with preceding underscores (like `_<macro`) are not intended to 
 *      be used by the user.
 *
 *
 * Rules:
 *      These are macros, but they are wrapped with brackets so they can be
 *      used without brackets. For example, the following works:
 *
 *          if (err)
 *              PERROR("This is an error")
 *
 *      Since the macro functions are bracketed, the semicolon is not required.
 *      But you can still use it an it is recommended. For example, these
 *      statements both work and are equivalent:
 *
 *          PRINT("hello");
 *          PRINT("hello")
 *
 *      The hex functions use the variable name _clog_i
 *
 *
 *
 * Examples:
 *
 *
 * Exposed constant macros:
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Exposed function macros:
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
 * ANZI terminal control codes.
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
 * 8-bit Color codes.
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
 * 24-bit Color codes.
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
 * Color Palettes.
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
#define C_INPUT     C_MAGENTA
#define C_WARN      C_ORANGE
#define C_ERR       C_RED
#define C_FATAL     C_BOLD C_RED


/**
 * Logging level symbols.
 *
 * These are the line headers for log-like printing and logging and are 
 * prepended to user strings when the appropriate function is used.
 */

#define _SYM_TRACE                  "[TRACE] "
#define _SYM_DEBUG                  "[DEBUG] "
#define _SYM_EXTRA                  "[.] "
#define _SYM_INFO                   "[*] "
#define _SYM_HEADER                 "[***] "
#define _SYM_SUCCESS                "[+] "
#define _SYM_INPUT                  "[?] "
#define _SYM_WARN                   "[!] "
#define _SYM_ERR                    "[-] "
#define _SYM_FATAL                  "[FATAL] "


/**
 * fprint functions.
 *
 * The "fprint" series of macros are the base functions used in the other
 * macro functions. For this implementation, they use the `fprintf` function.
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
 * Examples:
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

#define _NOTHING 

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
 * cfprint functions.
 *
 * The "cfprint" series of macros are the base functions used in the other
 * macro functions for colored printing. 
 *
 * The first parameter of all these functions is the color to print the text as
 * by prepending the string argument with the ANZI terminal color code and by
 * resetting the color output at the end.  The second parameter is the `FILE*` 
 * pointer (which may be `stdout` or `stderr` or a `FILE*` to a file`) to 
 * write to. 
 * 
 * There are several function-like macros available:
 *
 *      CFPRINT(char* string, FILE*, char* string)
 *      CFPRINTLN(char* string, FILE*, char* string)
 *      CFPRINTF(char* string, FILE*, char* format_string, ...)
 *      CFPRINTFLN(char* string, FILE*, char* format_string, ...)
 *      CFPRINT_HEX(char* string, FILE*, void* buffer, size_t size)
 *      CFPRINTLN_HEX(char* string, FILE*, void* buffer, size_t size)
 *      CFPRINT_WIDE_HEX(char* string, FILE*, void* buffer, size_t size)
 *      CFPRINTLN_WIDE_HEX(char* string, FILE*, void* buffer, size_t size)
 *      CFPERROR(char* string, FILE*, char* string)
 *      CFPERRORF(char* string, FILE*, char* format_string, ...)
 *
 * Examples:
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

#define CFPRINT(c, f, s)                { FPRINT(f, c s C_RESET) }
#define CFPRINTLN(c, f, s)              { FPRINTLN(f, c s C_RESET) }
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

                                                                                        
// Print functions.
#define PRINT(s)                    FPRINT(stdout, s)
#define PRINTLN(s)                  FPRINTLN(stdout, s)
#define PRINTF(...)                 FPRINTF(stdout, __VA_ARGS__)
#define PRINTFLN(...)               FPRINTFLN(stdout, __VA_ARGS__)
#define PRINT_HEX(s, l)             FPRINT_HEX(stdout, s, l)
#define PRINTLN_HEX(s, l)           FPRINTLN_HEX(stdout, s, l)
#define PRINT_WIDE_HEX(s, l)        FPRINT_WIDE_HEX(stdout, s, l)
#define PRINTLN_WIDE_HEX(s, l)      FPRINTLN_WIDE_HEX(stdout, s, l)
#define PERROR(...)                 FPERROR(stdout, __VA_ARGS__)

#define CPRINT(c, s)                CFPRINT(c, stdout, s)
#define CPRINTLN(c, s)              CFPRINTLN(c, stdout, s)
#define CPRINTF(c, ...)             CFPRINTF(c, stdout, __VA_ARGS__); PRINT(C_RESET)
#define CPRINTFLN(c, ...)           CFPRINTFLN(c, stdout, __VA_ARGS__); PRINT(C_RESET)
#define CPRINT_HEX(c, s, l)         CFPRINT_HEX(c, stdout, s, l)
#define CPRINTLN_HEX(c, s, l)       CFPRINTLN_HEX(c, stdout, s, l)
#define CPRINT_WIDE_HEX(c, s, l)    CFPRINT_WIDE_HEX(c, stdout, s, l)
#define CPRINTLN_WIDE_HEX(c, s, l)  CFPRINTLN_WIDE_HEX(c, stdout, s, l)
#define CPERROR(c, ...)             CFPERROR(c, stdout, __VA_ARGS__)

#define PRINT_TRACE(s)              PRINT(_SYM_TRACE s)
#define PRINTLN_TRACE(s)            PRINTLN(_SYM_TRACE s)
#define PRINTF_TRACE(...)           PRINTF(_SYM_TRACE __VA_ARGS__)
#define PRINTFLN_TRACE(...)         PRINTFLN(_SYM_TRACE __VA_ARGS__)

#define PRINT_DEBUG(s)              PRINT(_SYM_DEBUG s)
#define PRINTLN_DEBUG(s)            PRINTLN(_SYM_DEBUG s)
#define PRINTF_DEBUG(...)           PRINTF(_SYM_DEBUG __VA_ARGS__)
#define PRINTFLN_DEBUG(...)         PRINTFLN(_SYM_DEBUG __VA_ARGS__)

#define PRINT_EXTRA(s)              PRINT(_SYM_EXTRA s)
#define PRINTLN_EXTRA(s)            PRINTLN(_SYM_EXTRA s)
#define PRINTF_EXTRA(...)           PRINTF(_SYM_EXTRA __VA_ARGS__)
#define PRINTFLN_EXTRA(...)         PRINTFLN(_SYM_EXTRA __VA_ARGS__)

#define PRINT_INFO(s)               PRINT(_SYM_INFO s)
#define PRINTLN_INFO(s)             PRINTLN(_SYM_INFO s)
#define PRINTF_INFO(...)            PRINTF(_SYM_INFO __VA_ARGS__)
#define PRINTFLN_INFO(...)          PRINTFLN(_SYM_INFO __VA_ARGS__)

#define PRINT_HEADER(s)             PRINT(_SYM_HEADER s)
#define PRINTLN_HEADER(s)           PRINTLN(_SYM_HEADER s)
#define PRINTF_HEADER(...)          PRINTF(_SYM_HEADER __VA_ARGS__)
#define PRINTFLN_HEADER(...)        PRINTFLN(_SYM_HEADER __VA_ARGS__)

#define PRINT_SUCCESS(s)            PRINT(_SYM_SUCCESS s)
#define PRINTLN_SUCCESS(s)          PRINTLN(_SYM_SUCCESS s)
#define PRINTF_SUCCESS(...)         PRINTF(_SYM_SUCCESS __VA_ARGS__)
#define PRINTFLN_SUCCESS(...)       PRINTFLN(_SYM_SUCCESS __VA_ARGS__)

#define PRINT_INPUT(s)              PRINT(_SYM_INPUT s)
#define PRINTLN_INPUT(s)            PRINTLN(_SYM_INPUT s)
#define PRINTF_INPUT(...)           PRINTF(_SYM_INPUT __VA_ARGS__)
#define PRINTFLN_INPUT(...)         PRINTFLN(_SYM_INPUT __VA_ARGS__)

#define PRINT_WARN(s)               PRINT(_SYM_WARN s)
#define PRINTLN_WARN(s)             PRINTLN(_SYM_WARN s)
#define PRINTF_WARN(...)            PRINTF(_SYM_WARN __VA_ARGS__)
#define PRINTFLN_WARN(...)          PRINTFLN(_SYM_WARN __VA_ARGS__)

#define PRINT_ERR(s)                PRINT(_SYM_ERR s)
#define PRINTLN_ERR(s)              PRINTLN(_SYM_ERR s)
#define PRINTF_ERR(...)             PRINTF(_SYM_ERR __VA_ARGS__)
#define PRINTFLN_ERR(...)           PRINTFLN(_SYM_ERR __VA_ARGS__)
#define PERROR_ERR(...)             PERROR(_SYM_ERR __VA_ARGS__)

#define PRINT_FATAL(s)              PRINT(_SYM_FATAL s)
#define PRINTLN_FATAL(s)            PRINTLN(_SYM_FATAL s)
#define PRINTF_FATAL(...)           PRINTF(_SYM_FATAL __VA_ARGS__)
#define PRINTFLN_FATAL(...)         PRINTFLN(_SYM_FATAL __VA_ARGS__)



#define CPRINT_TRACE(s)             CPRINT(C_TRACE, _SYM_TRACE s)
#define CPRINTLN_TRACE(s)           CPRINTLN(C_TRACE, _SYM_TRACE s)
#define CPRINTF_TRACE(...)          CPRINTF(C_TRACE, _SYM_TRACE __VA_ARGS__)
#define CPRINTFLN_TRACE(...)        CPRINTFLN(C_TRACE, _SYM_TRACE __VA_ARGS__)

#define CPRINT_DEBUG(s)             CPRINT(C_DEBUG, _SYM_DEBUG s)
#define CPRINTLN_DEBUG(s)           CPRINTLN(C_DEBUG, _SYM_DEBUG s)
#define CPRINTF_DEBUG(...)          CPRINTF(C_DEBUG, _SYM_DEBUG __VA_ARGS__)
#define CPRINTFLN_DEBUG(...)        CPRINTFLN(C_DEBUG, _SYM_DEBUG __VA_ARGS__)

#define CPRINT_EXTRA(s)             CPRINT(C_EXTRA, _SYM_EXTRA s)
#define CPRINTLN_EXTRA(s)           CPRINTLN(C_EXTRA, _SYM_EXTRA s)
#define CPRINTF_EXTRA(...)          CPRINTF(C_EXTRA, _SYM_EXTRA __VA_ARGS__)
#define CPRINTFLN_EXTRA(...)        CPRINTFLN(C_EXTRA, _SYM_EXTRA __VA_ARGS__)

#define CPRINT_INFO(s)              CPRINT(C_INFO, _SYM_INFO s)
#define CPRINTLN_INFO(s)            CPRINTLN(C_INFO, _SYM_INFO s)
#define CPRINTF_INFO(...)           CPRINTF(C_INFO, _SYM_INFO __VA_ARGS__)
#define CPRINTFLN_INFO(...)         CPRINTFLN(C_INFO, _SYM_INFO __VA_ARGS__)

#define CPRINT_HEADER(s)            CPRINT(C_HEADER, _SYM_HEADER s)
#define CPRINTLN_HEADER(s)          CPRINTLN(C_HEADER, _SYM_HEADER s)
#define CPRINTF_HEADER(...)         CPRINTF(C_HEADER, _SYM_HEADER __VA_ARGS__)
#define CPRINTFLN_HEADER(...)       CPRINTFLN(C_HEADER, _SYM_HEADER __VA_ARGS__)

#define CPRINT_SUCCESS(s)           CPRINT(C_SUCCESS, _SYM_SUCCESS s)
#define CPRINTLN_SUCCESS(s)         CPRINTLN(C_SUCCESS, _SYM_SUCCESS s)
#define CPRINTF_SUCCESS(...)        CPRINTF(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)
#define CPRINTFLN_SUCCESS(...)      CPRINTFLN(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)

#define CPRINT_INPUT(s)             CPRINT(C_INPUT, _SYM_INPUT s)
#define CPRINTLN_INPUT(s)           CPRINTLN(C_INPUT, _SYM_INPUT s)
#define CPRINTF_INPUT(...)          CPRINTF(C_INPUT, _SYM_INPUT __VA_ARGS__)
#define CPRINTFLN_INPUT(...)        CPRINTFLN(C_INPUT, _SYM_INPUT __VA_ARGS__)

#define CPRINT_WARN(s)              CPRINT(C_WARN, _SYM_WARN s)
#define CPRINTLN_WARN(s)            CPRINTLN(C_WARN, _SYM_WARN s)
#define CPRINTF_WARN(...)           CPRINTF(C_WARN, _SYM_WARN __VA_ARGS__)
#define CPRINTFLN_WARN(...)         CPRINTFLN(C_WARN, _SYM_WARN __VA_ARGS__)

#define CPRINT_ERR(s)               CPRINT(C_ERR, _SYM_ERR s)
#define CPRINTLN_ERR(s)             CPRINTLN(C_ERR, _SYM_ERR s)
#define CPRINTF_ERR(...)            CPRINTF(C_ERR, _SYM_ERR __VA_ARGS__)
#define CPRINTFLN_ERR(...)          CPRINTFLN(C_ERR, _SYM_ERR __VA_ARGS__)
#define CPERROR_ERR(...)            CPERROR(C_ERR, _SYM_ERR __VA_ARGS__)

#define CPRINT_FATAL(s)             CPRINT(C_FATAL, _SYM_FATAL s)
#define CPRINTLN_FATAL(s)           CPRINTLN(C_FATAL, _SYM_FATAL s)
#define CPRINTF_FATAL(...)          CPRINTF(C_FATAL, _SYM_FATAL __VA_ARGS__)
#define CPRINTFLN_FATAL(...)        CPRINTFLN(C_FATAL, _SYM_FATAL __VA_ARGS__)

// Logging.

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
#define TM_BUFSZ                    128
#define TM_FMT                      "%FT%T%z"

#define LOG_DECLARE                 FILE* _glog = NULL; \
                                    char _gtime_buf[TM_BUFSZ] = { 0 }; \
                                    time_t _gtime = 0;
#define LOGFILE_INIT(f)             _glog = fopen(f, "a+")

// Log functions.
#define _LOG_TIME(f)                time(&_gtime); \
                                    strftime( \
                                        _gtime_buf, \
                                        TM_BUFSZ, \
                                        TM_FMT, \
                                        localtime(&_gtime) \
                                    ); \
                                    FPRINTF(f, "%s: ", _gtime_buf)
#define _LOG_FTRACE(f)              FPRINTF( \
                                        f, \
                                        "%s:%s:%u: ", \
                                        __FILE__, \
                                        __FUNCTION__, \
                                        __LINE__ \
                                    ); 
#define _LOG_CTRACE(f)              FPRINTF( \
                                        f, \
                                        C_MAGENTA "%s" C_RESET ":" \
                                        C_GREEN "%s" C_RESET ":" \
                                        C_BLUE "%u" C_RESET ": ", \
                                        __FILE__, \
                                        __FUNCTION__, \
                                        __LINE__ \
                                    ); 

// File logging.
#define FLOG(s)                     _LOG_TIME(_glog); FPRINT(_glog, s)
#define FLOGLN(s)                   _LOG_TIME(_glog); FPRINTLN(_glog, s)
#define FLOGF(...)                  _LOG_TIME(_glog); FPRINTF(_glog, __VA_ARGS__)
#define FLOGFLN(...)                _LOG_TIME(_glog); FPRINTFLN(_glog, __VA_ARGS__)
#define FLOG_PERROR(...)            _LOG_TIME(_glog); FPERROR(_glog, __VA_ARGS__)

#define FLOG_T(s)                   _LOG_TIME(_glog); _LOG_FTRACE(_glog); FPRINT(_glog, s)
#define FLOGLN_T(s)                 _LOG_TIME(_glog); _LOG_FTRACE(_glog); FPRINTLN(_glog, s)
#define FLOGF_T(...)                _LOG_TIME(_glog); _LOG_FTRACE(_glog); FPRINTF(_glog, __VA_ARGS__)
#define FLOGFLN_T(...)              _LOG_TIME(_glog); _LOG_FTRACE(_glog); FPRINTFLN(_glog, __VA_ARGS__)
#define FLOG_PERROR_T(...)          _LOG_TIME(_glog); _LOG_FTRACE(_glog); FPERROR(_glog, __VA_ARGS__)

#define FLOG_STREAM(s)              FPRINT(_glog, s)
#define FLOGLN_STREAM(s)            FPRINTLN(_glog, s)
#define FLOGF_STREAM(...)           FPRINTF(_glog, __VA_ARGS__)
#define FLOGFLN_STREAM(...)         FPRINTFLN(_glog, __VA_ARGS__)
#define FLOG_STREAM_HEX(s, l)       FPRINTLN_HEX(_glog, s, l)
#define FLOG_STREAM_WIDE_HEX(s, l)  FPRINTLN_WIDE_HEX(_glog, s, l)

#define FLOG_TRACE(s)               FLOG_T(_SYM_TRACE s)
#define FLOGLN_TRACE(s)             FLOGLN_T(_SYM_TRACE s)
#define FLOGF_TRACE(...)            FLOGF_T(_SYM_TRACE __VA_ARGS__)
#define FLOGFLN_TRACE(...)          FLOGFLN_T(_SYM_TRACE __VA_ARGS__)

#define FLOG_DEBUG(s)               FLOG_T(_SYM_DEBUG s)
#define FLOGLN_DEBUG(s)             FLOGLN_T(_SYM_DEBUG s)
#define FLOGF_DEBUG(...)            FLOGF_T(_SYM_DEBUG __VA_ARGS__)
#define FLOGFLN_DEBUG(...)          FLOGFLN_T(_SYM_DEBUG __VA_ARGS__)

#define FLOG_EXTRA(s)               FLOG(_SYM_EXTRA s)
#define FLOGLN_EXTRA(s)             FLOGLN(_SYM_EXTRA s)
#define FLOGF_EXTRA(...)            FLOGF(_SYM_EXTRA __VA_ARGS__)
#define FLOGFLN_EXTRA(...)          FLOGFLN(_SYM_EXTRA __VA_ARGS__)

#define FLOG_INFO(s)                FLOG(_SYM_INFO s)
#define FLOGLN_INFO(s)              FLOGLN(_SYM_INFO s)
#define FLOGF_INFO(...)             FLOGF(_SYM_INFO __VA_ARGS__)
#define FLOGFLN_INFO(...)           FLOGFLN(_SYM_INFO __VA_ARGS__)

#define FLOG_HEADER(s)              FLOG(_SYM_HEADER s)
#define FLOGLN_HEADER(s)            FLOGLN(_SYM_HEADER s)
#define FLOGF_HEADER(...)           FLOGF(_SYM_HEADER __VA_ARGS__)
#define FLOGFLN_HEADER(...)         FLOGFLN(_SYM_HEADER __VA_ARGS__)

#define FLOG_SUCCESS(s)             FLOG(_SYM_SUCCESS s)
#define FLOGLN_SUCCESS(s)           FLOGLN(_SYM_SUCCESS s)
#define FLOGF_SUCCESS(...)          FLOGF(_SYM_SUCCESS __VA_ARGS__)
#define FLOGFLN_SUCCESS(...)        FLOGFLN(_SYM_SUCCESS __VA_ARGS__)

#define FLOG_INPUT(s)               FLOG(_SYM_INPUT s)
#define FLOGLN_INPUT(s)             FLOGLN(_SYM_INPUT s)
#define FLOGF_INPUT(...)            FLOGF(_SYM_INPUT __VA_ARGS__)
#define FLOGFLN_INPUT(...)          FLOGFLN(_SYM_INPUT __VA_ARGS__)

#define FLOG_WARN(s)                FLOG(_SYM_WARN s)
#define FLOGLN_WARN(s)              FLOGLN(_SYM_WARN s)
#define FLOGF_WARN(...)             FLOGF(_SYM_WARN __VA_ARGS__)
#define FLOGFLN_WARN(...)           FLOGFLN(_SYM_WARN __VA_ARGS__)

#define FLOG_ERR(s)                 FLOG(_SYM_ERR s)
#define FLOGLN_ERR(s)               FLOGLN(_SYM_ERR s)
#define FLOGF_ERR(...)              FLOGF(_SYM_ERR __VA_ARGS__)
#define FLOGFLN_ERR(...)            FLOGFLN(_SYM_ERR __VA_ARGS__)
#define FLOG_PERROR_ERR(...)        FLOG_PERROR(_SYM_ERR __VA_ARGS__)

#define FLOG_FATAL(s)               FLOG(_SYM_FATAL s)
#define FLOGLN_FATAL(s)             FLOGLN(_SYM_FATAL s)
#define FLOGF_FATAL(...)            FLOGF(_SYM_FATAL __VA_ARGS__)
#define FLOGFLN_FATAL(...)          FLOGFLN(_SYM_FATAL __VA_ARGS__)
#define FLOG_PERRROR_FATAL(...)     FLOG_PERROR(_SYM_FATAL __VA_ARGS__)

// Console logging.
#define _NC_CLOG(c, s)              _LOG_TIME(stderr); FPRINT(stderr, s)
#define _NC_CLOGLN(c, s)            _LOG_TIME(stderr); FPRINTLN(stderr, s)
#define _NC_CLOGF(c, ...)           _LOG_TIME(stderr); FPRINTF(stderr, __VA_ARGS__)
#define _NC_CLOGFLN(c, ...)         _LOG_TIME(stderr); FPRINTFLN(stderr, __VA_ARGS__)
#define _NC_CLOG_PERROR(c, ...)     _LOG_TIME(stderr); FPERROR(stderr, __VA_ARGS__)

#define _NCT_CLOG(c, s)             _LOG_TIME(stderr); \
                                    _LOG_FTRACE(stderr); \
                                    FPRINT(stderr, s)
#define _NCT_CLOGLN(c, s)           _LOG_TIME(stderr); \
                                    _LOG_FTRACE(stderr); \
                                    FPRINTLN(stderr, s)
#define _NCT_CLOGF(c, ...)          _LOG_TIME(stderr); \
                                    _LOG_FTRACE(stderr); \
                                    FPRINTF(stderr, __VA_ARGS__)
#define _NCT_CLOGFLN(c, ...)        _LOG_TIME(stderr); \
                                    _LOG_FTRACE(stderr); \
                                    FPRINTFLN(stderr, __VA_ARGS__)
#define _NCT_CLOG_PERROR(c, ...)    _LOG_TIME(stderr); \
                                    _LOG_FTRACE(stderr); \
                                    FPERROR(stderr, __VA_ARGS__)

#define _C_CLOG(c, s)               _LOG_TIME(stderr); CFPRINT(c, stderr, s)
#define _C_CLOGLN(c, s)             _LOG_TIME(stderr); CFPRINTLN(c, stderr, s)
#define _C_CLOGF(c, ...)            _LOG_TIME(stderr); CFPRINTF(c, stderr, __VA_ARGS__)
#define _C_CLOGFLN(c, ...)          _LOG_TIME(stderr); CFPRINTFLN(c, stderr, __VA_ARGS__)
#define _C_CLOG_PERROR(c, ...)      _LOG_TIME(stderr); CFPERROR(c, stderr, __VA_ARGS__)

#define _CT_CLOG(c, s)              _LOG_TIME(stderr); \
                                    _LOG_CTRACE(stderr); \
                                    CFPRINT(c, stderr, s)
#define _CT_CLOGLN(c, s)            _LOG_TIME(stderr); \
                                    _LOG_CTRACE(stderr); \
                                    CFPRINTLN(c, stderr, s)
#define _CT_CLOGF(c, ...)           _LOG_TIME(stderr); \
                                    _LOG_CTRACE(stderr); \
                                    CFPRINTF(c, stderr, __VA_ARGS__)
#define _CT_CLOGFLN(c, ...)         _LOG_TIME(stderr); \
                                    _LOG_CTRACE(stderr); \
                                    CFPRINTFLN(c, stderr, __VA_ARGS__)
#define _CT_CLOG_PERROR(c, ...)     _LOG_TIME(stderr); \
                                    _LOG_CTRACE(stderr); \
                                    CFPERROR(c, stderr, __VA_ARGS__)

#if LOG_CONSOLE_MODE == LOG_CONSOLE_MODE_NOCOLOR
    #define _CLOG(c, s)             _NC_CLOG(c, s)
    #define _CLOGLN(c, s)           _NC_CLOGLN(c, s)
    #define _CLOGF(c, ...)          _NC_CLOGF(c, __VA_ARGS__)
    #define _CLOGFLN(c, ...)        _NC_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_PERROR(c, ...)    _NC_CLOG_PERROR(c, __VA_ARGS__)

    #define _CLOG_T(c, s)           _NCT_CLOG(c, s)
    #define _CLOGLN_T(c, s)         _NCT_CLOGLN(c, s)
    #define _CLOGF_T(c, ...)        _NCT_CLOGF(c, __VA_ARGS__)
    #define _CLOGFLN_T(c, ...)      _NCT_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_PERROR_T(c, ...)  _NCT_CLOG_PERROR(c, __VA_ARGS__)

#else
    #define _CLOG(c, s)             _C_CLOG(c, s)
    #define _CLOGLN(c, s)           _C_CLOGLN(c, s)
    #define _CLOGF(c, ...)          _C_CLOGF(c, __VA_ARGS__)
    #define _CLOGFLN(c, ...)        _C_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_PERROR(c, ...)    _C_CLOG_PERROR(c, __VA_ARGS__)

    #define _CLOG_T(c, s)           _CT_CLOG(c, s)
    #define _CLOGLN_T(c, s)         _CT_CLOGLN(c, s)
    #define _CLOGF_T(c, ...)        _CT_CLOGF(c, __VA_ARGS__)
    #define _CLOGFLN_T(c, ...)      _CT_CLOGFLN(c, __VA_ARGS__)
    #define _CLOG_PERROR_T(c, ...)  _CT_CLOG_PERROR(c, __VA_ARGS__)

#endif

#define CLOG(s)                     _NC_CLOG(_NOTHING, s)
#define CLOGLN(s)                   _NC_CLOGLN(_NOTHING, s)
#define CLOGF(...)                  _NC_CLOGF(_NOTHING, __VA_ARGS__)
#define CLOGFLN(...)                _NC_CLOGFLN(_NOTHING, __VA_ARGS__)
#define CLOG_PERROR(...)            _NC_CLOG_PERROR(_NOTHING, __VA_ARGS__)

#define CLOG_T(s)                   _NCT_CLOG(_NOTHING, s)
#define CLOGLN_T(s)                 _NCT_CLOGLN(_NOTHING, s)
#define CLOGF_T(...)                _NCT_CLOGF(_NOTHING, __VA_ARGS__)
#define CLOGFLN_T(...)              _NCT_CLOGFLN(_NOTHING, __VA_ARGS__)
#define CLOG_PERROR_T(...)          _NCT_CLOG_PERROR(_NOTHING, __VA_ARGS__)

#define CLOG_STREAM(s)              FPRINT(stderr, s)
#define CLOGLN_STREAM(s)            FPRINTLN(stderr, s)
#define CLOGF_STREAM(...)           FPRINTF(stderr, __VA_ARGS__)
#define CLOGFLN_STREAM(...)         FPRINTFLN(stderr, __VA_ARGS__)
#define CLOG_STREAM_HEX(s, l)       FPRINTLN_HEX(stderr, s, l)
#define CLOG_STREAM_WIDE_HEX(s, l)  FPRINTLN_WIDE_HEX(stderr, s, l)

#define CLOG_TRACE(s)               _CLOG_T(C_TRACE, _SYM_TRACE s)
#define CLOGLN_TRACE(s)             _CLOGLN_T(C_TRACE, _SYM_TRACE s)
#define CLOGF_TRACE(...)            _CLOGF_T(C_TRACE, _SYM_TRACE __VA_ARGS__)
#define CLOGFLN_TRACE(...)          _CLOGFLN_T(C_TRACE, _SYM_TRACE __VA_ARGS__)

#define CLOG_DEBUG(s)               _CLOG_T(C_DEBUG, _SYM_DEBUG s)
#define CLOGLN_DEBUG(s)             _CLOGLN_T(C_DEBUG, _SYM_DEBUG s)
#define CLOGF_DEBUG(...)            _CLOGF_T(C_DEBUG, _SYM_DEBUG __VA_ARGS__)
#define CLOGFLN_DEBUG(...)          _CLOGFLN_T(C_DEBUG, _SYM_DEBUG __VA_ARGS__)

#define CLOG_EXTRA(s)               _CLOG(C_EXTRA, _SYM_EXTRA s)
#define CLOGLN_EXTRA(s)             _CLOGLN(C_EXTRA, _SYM_EXTRA s)
#define CLOGF_EXTRA(...)            _CLOGF(C_EXTRA, _SYM_EXTRA __VA_ARGS__)
#define CLOGFLN_EXTRA(...)          _CLOGFLN(C_EXTRA, _SYM_EXTRA __VA_ARGS__)

#define CLOG_INFO(s)                _CLOG(C_INFO, _SYM_INFO s)
#define CLOGLN_INFO(s)              _CLOGLN(C_INFO, _SYM_INFO s)
#define CLOGF_INFO(...)             _CLOGF(C_INFO, _SYM_INFO __VA_ARGS__)
#define CLOGFLN_INFO(...)           _CLOGFLN(C_INFO, _SYM_INFO __VA_ARGS__)

#define CLOG_HEADER(s)              _CLOG(C_HEADER, _SYM_HEADER s)
#define CLOGLN_HEADER(s)            _CLOGLN(C_HEADER, _SYM_HEADER s)
#define CLOGF_HEADER(...)           _CLOGF(C_HEADER, _SYM_HEADER __VA_ARGS__)
#define CLOGFLN_HEADER(...)         _CLOGFLN(C_HEADER, _SYM_HEADER __VA_ARGS__)

#define CLOG_SUCCESS(s)             _CLOG(C_SUCCESS, _SYM_SUCCESS s)
#define CLOGLN_SUCCESS(s)           _CLOGLN(C_SUCCESS, _SYM_SUCCESS s)
#define CLOGF_SUCCESS(...)          _CLOGF(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)
#define CLOGFLN_SUCCESS(...)        _CLOGFLN(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)

#define CLOG_INPUT(s)               _CLOG(C_INPUT, _SYM_INPUT s)
#define CLOGLN_INPUT(s)             _CLOGLN(C_INPUT, _SYM_INPUT s)
#define CLOGF_INPUT(...)            _CLOGF(C_INPUT, _SYM_INPUT __VA_ARGS__)
#define CLOGFLN_INPUT(...)          _CLOGFLN(C_INPUT, _SYM_INPUT __VA_ARGS__)

#define CLOG_WARN(s)                _CLOG(C_WARN, _SYM_WARN s)
#define CLOGLN_WARN(s)              _CLOGLN(C_WARN, _SYM_WARN s)
#define CLOGF_WARN(...)             _CLOGF(C_WARN, _SYM_WARN __VA_ARGS__)
#define CLOGFLN_WARN(...)           _CLOGFLN(C_WARN, _SYM_WARN __VA_ARGS__)

#define CLOG_ERR(s)                 _CLOG(C_ERR, _SYM_ERR s)
#define CLOGLN_ERR(s)               _CLOGLN(C_ERR, _SYM_ERR s)
#define CLOGF_ERR(...)              _CLOGF(C_ERR, _SYM_ERR __VA_ARGS__)
#define CLOGFLN_ERR(...)            _CLOGFLN(C_ERR, _SYM_ERR __VA_ARGS__)
#define CLOG_PERROR_ERR(...)        _CLOG_PERROR(C_ERR, _SYM_ERR __VA_ARGS__)

#define CLOG_FATAL(s)               _CLOG(C_FATAL, _SYM_FATAL s)
#define CLOGLN_FATAL(s)             _CLOGLN(C_FATAL, _SYM_FATAL s)
#define CLOGF_FATAL(...)            _CLOGF(C_FATAL, _SYM_FATAL __VA_ARGS__)
#define CLOGFLN_FATAL(...)          _CLOGFLN(C_FATAL, C_FATAL, _SYM_FATAL __VA_ARGS__)
#define CLOG_PERROR_FATAL(...)      _CLOG_PERROR(C_FATAL, C_FATAL, _SYM_FATAL __VA_ARGS__)

// Dual logging.
#if LOG_MODE == LOG_MODE_NONE
    #define _LOG(...)                  
    #define _LOGLN(...)                  
    #define _LOGF(...)                  
    #define _LOGFLN(...)                  
    #define _LOG_PERROR(...)                  

    #define _LOG_T(...)                  
    #define _LOGLN_T(...)                  
    #define _LOGF_T(...)                  
    #define _LOGFLN_T(...)                  
    #define _LOG_PERROR_T(...)                  

    #define _LOG_STREAM(...)           
    #define _LOGLN_STREAM(...)
    #define _LOGF_STREAM(...)           
    #define _LOGFLN_STREAM(...)         
    #define _LOG_STREAM_HEX(...)
    #define _LOG_STREAM_WIDE_HEX(...)

#elif LOG_MODE == LOG_MODE_CONSOLE
    #define _LOG(c, s)              _CLOG(c, s)
    #define _LOGLN(c, s)            _CLOGLN(c, s)
    #define _LOGF(c, ...)           _CLOGF(c, __VA_ARGS__)
    #define _LOGFLN(c, ...)         _CLOGFLN(c, __VA_ARGS__)
    #define _LOG_PERROR(c, ...)     _CLOG_PERROR(c, __VA_ARGS__)

    #define _LOG_T(c, s)            _CLOG_T(c, s)
    #define _LOGLN_T(c, s)          _CLOGLN_T(c, s)
    #define _LOGF_T(c, ...)         _CLOGF_T(c, __VA_ARGS__)
    #define _LOGFLN_T(c, ...)       _CLOGFLN_T(c, __VA_ARGS__)
    #define _LOG_PERROR_T(c, ...)   _CLOG_PERROR_T(c, __VA_ARGS__)
    
    #define _LOG_STREAM(s)          CLOG_STREAM(s)
    #define _LOGLN_STREAM(s)        CLOGLN_STREAM(s)
    #define _LOGF_STREAM(...)       CLOGF_STREAM(__VA_ARGS__)    
    #define _LOGFLN_STREAM(...)     CLOGFLN_STREAM(__VA_ARGS__)
    #define _LOG_STREAM_HEX(s, l)   CLOG_STREAM_HEX(s, l)
    #define _LOG_STREAM_WIDE_HEX(s, l) CLOG_STREAM_WIDE_HEX(s, l)

#elif LOG_MODE == LOG_MODE_FILE
    #define _LOG(c, s)              FLOG(s)
    #define _LOGLN(c, s)            FLOGLN(s)
    #define _LOGF(c, ...)           FLOGF(__VA_ARGS__)
    #define _LOGFLN(c, ...)         FLOGFLN(__VA_ARGS__)
    #define _LOG_PERROR(c, ...)     FLOG_PERROR(__VA_ARGS__)

    #define _LOG_T(c, s)            FLOG_T(s)
    #define _LOGLN_T(c, s)          FLOGLN_T(s)
    #define _LOGF_T(c, ...)         FLOGF_T(__VA_ARGS__)
    #define _LOGFLN_T(c, ...)       FLOGFLN_T(__VA_ARGS__)
    #define _LOG_PERROR_T(c, ...)   FLOG_PERROR_T(__VA_ARGS__)

    #define _LOG_STREAM(s)          FLOG_STREAM(s)
    #define _LOGLN_STREAM(s)        FLOGLN_STREAM(s)
    #define _LOGF_STREAM(...)       FLOGF_STREAM(__VA_ARGS__)    
    #define _LOGFLN_STREAM(...)     FLOGFLN_STREAM(__VA_ARGS__)
    #define _LOG_STREAM_HEX(s, l)   FLOG_STREAM_HEX(s, l)
    #define _LOG_STREAM_WIDE_HEX(s, l) FLOG_STREAM_WIDE_HEX(s, l)

#else
    #define _LOG(c, s)              _CLOG(c, s); FLOG(s)
    #define _LOGLN(c, s)            _CLOGLN(c, s); FLOGLN(s)
    #define _LOGF(c, ...)           _CLOGF(c, __VA_ARGS__); FLOGF(__VA_ARGS__)
    #define _LOGFLN(c, ...)         _CLOGFLN(c, __VA_ARGS__); FLOGFLN(__VA_ARGS__)
    #define _LOG_PERROR(c, ...)     _CLOG_PERROR(c, __VA_ARGS__); FLOG_PERROR(__VA_ARGS__)

    #define _LOG_T(c, s)            _CLOG_T(c, s); FLOG_T(s)
    #define _LOGLN_T(c, s)          _CLOGLN_T(c, s); FLOGLN_T(s)
    #define _LOGF_T(c, ...)         _CLOGF_T(c, __VA_ARGS__); FLOGF_T(__VA_ARGS__)
    #define _LOGFLN_T(c, ...)       _CLOGFLN_T(c, __VA_ARGS__); FLOGFLN_T(__VA_ARGS__)
    #define _LOG_PERROR_T(c, ...)   _CLOG_PERROR_T(c, __VA_ARGS__); FLOG_PERROR_T(__VA_ARGS__)

    #define _LOG_STREAM(s)          CLOG_STREAM(s); FLOG_STREAM(s)
    #define _LOGLN_STREAM(s)        CLOGLN_STREAM(s); FLOGFLN_STREAM(s)
    #define _LOGF_STREAM(...)       CLOGF_STREAM(__VA_ARGS__); FLOGF_STREAM(__VA_ARGS__)
    #define _LOGFLN_STREAM(...)     CLOGFLN_STREAM(__VA_ARGS__); FLOGFLN_STREAM(__VA_ARGS__)
    #define _LOG_STREAM_HEX(s, l)   CLOG_STREAM_HEX(s, l); FLOG_STREAM_HEX(s, l)
    #define _LOG_STREAM_WIDE_HEX(s, l) CLOG_STREAM_WIDE_HEX(s, l); FLOG_STREAM_WIDE_HEX(s, l)
    
#endif

#define LOG(s)                      _LOG(_NOTHING, s)
#define LOGLN(s)                    _LOGLN(_NOTHING, s)
#define LOGF(...)                   _LOGF(_NOTHING, __VA_ARGS__)
#define LOGFLN(...)                 _LOGFLN(_NOTHING, __VA_ARGS__)
#define LOG_PERROR(...)             _LOG_PERROR(_NOTHING, __VA_ARGS__)

#define LOG_T(s)                    _LOG_T(_NOTHING, s)
#define LOGLN_T(s)                  _LOGLN_T(_NOTHING, s)
#define LOGF_T(...)                 _LOGF_T(_NOTHING, __VA_ARGS__)
#define LOGFLN_T(...)               _LOGFLN_T(_NOTHING, __VA_ARGS__)
#define LOG_PERROR_T(...)           _LOG_PERROR_T(_NOTHING, __VA_ARGS__)

#define LOG_STREAM(s)               _LOG_STREAM(s)
#define LOGLN_STREAM(s)             _LOGLN_STREAM(s)
#define LOGF_STREAM(...)            _LOGF_STREAM(__VA_ARGS__)
#define LOGFLN_STREAM(...)          _LOGFLN_STREAM(__VA_ARGS__)
#define LOG_STREAM_HEX(s, l)        _LOG_STREAM_HEX(s, l)
#define LOG_STREAM_WIDE_HEX(s, l)   _LOG_STREAM_WIDE_HEX(s, l)

#define LOG_TRACE(s)                _LOG_T(C_TRACE, _SYM_TRACE s)
#define LOGLN_TRACE(s)              _LOGLN_T(C_TRACE, _SYM_TRACE s)
#define LOGF_TRACE(...)             _LOGF_T(C_TRACE, _SYM_TRACE __VA_ARGS__)
#define LOGFLN_TRACE(...)           _LOGFLN_T(C_TRACE, _SYM_TRACE __VA_ARGS__)

#define LOG_DEBUG(s)                _LOG_T(C_DEBUG, _SYM_DEBUG s)
#define LOGLN_DEBUG(s)              _LOGLN_T(C_DEBUG, _SYM_DEBUG s)
#define LOGF_DEBUG(...)             _LOGF_T(C_DEBUG, _SYM_DEBUG __VA_ARGS__)
#define LOGFLN_DEBUG(...)           _LOGFLN_T(C_DEBUG, _SYM_DEBUG __VA_ARGS__)

#define LOG_EXTRA(s)                _LOG(C_EXTRA, _SYM_EXTRA s)
#define LOGLN_EXTRA(s)              _LOGLN(C_EXTRA, _SYM_EXTRA s)
#define LOGF_EXTRA(...)             _LOGF(C_EXTRA, _SYM_EXTRA __VA_ARGS__)
#define LOGFLN_EXTRA(...)           _LOGFLN(C_EXTRA, _SYM_EXTRA __VA_ARGS__)

#define LOG_INFO(s)                 _LOG(C_INFO, _SYM_INFO s)
#define LOGLN_INFO(s)               _LOGLN(C_INFO, _SYM_INFO s)
#define LOGF_INFO(...)              _LOGF(C_INFO, _SYM_INFO __VA_ARGS__)
#define LOGFLN_INFO(...)            _LOGFLN(C_INFO, _SYM_INFO __VA_ARGS__)

#define LOG_HEADER(s)               _LOG(C_HEADER, _SYM_HEADER s)
#define LOGLN_HEADER(s)             _LOGLN(C_HEADER, _SYM_HEADER s)
#define LOGF_HEADER(...)            _LOGF(C_HEADER, _SYM_HEADER __VA_ARGS__)
#define LOGFLN_HEADER(...)          _LOGFLN(C_HEADER, _SYM_HEADER __VA_ARGS__)

#define LOG_SUCCESS(s)              _LOG(C_SUCCESS, _SYM_SUCCESS s)
#define LOGLN_SUCCESS(s)            _LOGLN(C_SUCCESS, _SYM_SUCCESS s)
#define LOGF_SUCCESS(...)           _LOGF(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)
#define LOGFLN_SUCCESS(...)         _LOGFLN(C_SUCCESS, _SYM_SUCCESS __VA_ARGS__)

#define LOG_INPUT(s)                _LOG(C_INPUT, _SYM_INPUT s)
#define LOGLN_INPUT(s)              _LOGLN(C_INPUT, _SYM_INPUT s)
#define LOGF_INPUT(...)             _LOGF(C_INPUT, _SYM_INPUT __VA_ARGS__)
#define LOGFLN_INPUT(...)           _LOGFLN(C_INPUT, _SYM_INPUT __VA_ARGS__)

#define LOG_WARN(s)                 _LOG(C_WARN, _SYM_WARN s)
#define LOGLN_WARN(s)               _LOGLN(C_WARN, _SYM_WARN s)
#define LOGF_WARN(...)              _LOGF(C_WARN, _SYM_WARN __VA_ARGS__)
#define LOGFLN_WARN(...)            _LOGFLN(C_WARN, _SYM_WARN __VA_ARGS__)

#define LOG_ERR(s)                  _LOG(C_ERR, _SYM_ERR s)
#define LOGLN_ERR(s)                _LOGLN(C_ERR, _SYM_ERR s)
#define LOGF_ERR(...)               _LOGF(C_ERR, _SYM_ERR __VA_ARGS__)
#define LOGFLN_ERR(...)             _LOGFLN(C_ERR, _SYM_ERR __VA_ARGS__)
#define LOG_PERROR_ERR(...)         _LOG_PERROR(C_ERR, _SYM_ERR __VA_ARGS__)

#define LOG_FATAL(s)                _LOG(C_FATAL, _SYM_FATAL s)
#define LOGLN_FATAL(s)              _LOGLN(C_FATAL, _SYM_FATAL s)
#define LOGF_FATAL(...)             _LOGF(C_FATAL, _SYM_FATAL __VA_ARGS__)
#define LOGFLN_FATAL(...)           _LOGFLN(C_FATAL, _SYM_FATAL __VA_ARGS__)
#define LOG_PERROR_FATAL(...)       _LOG_PERROR(C_FATAL, _SYM_FATAL __VA_ARGS__)

#if LOG_LEVEL == LOG_LEVEL_NONE
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
    #undef FLOG_STREAM_WIDE_HEX
    #define FLOG_STREAM_WIDE_HEX(...)

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

    #undef FLOG_WARN
    #define FLOG_WARN(...)
    #undef FLOGLN_WARN
    #define FLOGLN_WARN(...)
    #undef FLOGF_WARN
    #define FLOGF_WARN(...)
    #undef FLOGFLN_WARN
    #define FLOGFLN_WARN(...)

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

    #undef FLOG_FATAL
    #define FLOG_FATAL(...)
    #undef FLOGLN_FATAL
    #define FLOGLN_FATAL(...)
    #undef FLOGF_FATAL
    #define FLOGF_FATAL(...)
    #undef FLOGFLN_FATAL
    #define FLOGFLN_FATAL(...)
    #define FLOG_PERROR_FATAL(...)

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
    #undef CLOG_STREAM_WIDE_HEX
    #define CLOG_STREAM_WIDE_HEX(...)

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

    #undef CLOG_WARN
    #define CLOG_WARN(...)
    #undef CLOGLN_WARN
    #define CLOGLN_WARN(...)
    #undef CLOGF_WARN
    #define CLOGF_WARN(...)
    #undef CLOGFLN_WARN
    #define CLOGFLN_WARN(...)

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

    #undef CLOG_FATAL
    #define CLOG_FATAL(...)
    #undef CLOGLN_FATAL
    #define CLOGLN_FATAL(...)
    #undef CLOGF_FATAL
    #define CLOGF_FATAL(...)
    #undef CLOGFLN_FATAL
    #define CLOGFLN_FATAL(...)
    #define CLOG_PERROR_FATAL(...)

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
    #undef LOG_STREAM_WIDE_HEX
    #define LOG_STREAM_WIDE_HEX(...)

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

    #undef LOG_WARN
    #define LOG_WARN(...)
    #undef LOGLN_WARN
    #define LOGLN_WARN(...)
    #undef LOGF_WARN
    #define LOGF_WARN(...)
    #undef LOGFLN_WARN
    #define LOGFLN_WARN(...)

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

    #undef LOG_FATAL
    #define LOG_FATAL(...)
    #undef LOGLN_FATAL
    #define LOGLN_FATAL(...)
    #undef LOGF_FATAL
    #define LOGF_FATAL(...)
    #undef LOGFLN_FATAL
    #define LOGFLN_FATAL(...)
    #define LOG_PERROR_FATAL(...)

#elif LOG_LEVEL == LOG_LEVEL_ERR
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

    #undef FLOG_WARN
    #define FLOG_WARN(...)
    #undef FLOGLN_WARN
    #define FLOGLN_WARN(...)
    #undef FLOGF_WARN
    #define FLOGF_WARN(...)
    #undef FLOGFLN_WARN
    #define FLOGFLN_WARN(...)

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

    #undef CLOG_WARN
    #define CLOG_WARN(...)
    #undef CLOGLN_WARN
    #define CLOGLN_WARN(...)
    #undef CLOGF_WARN
    #define CLOGF_WARN(...)
    #undef CLOGFLN_WARN
    #define CLOGFLN_WARN(...)

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

    #undef LOG_WARN
    #define LOG_WARN(...)
    #undef LOGLN_WARN
    #define LOGLN_WARN(...)
    #undef LOGF_WARN
    #define LOGF_WARN(...)
    #undef LOGFLN_WARN
    #define LOGFLN_WARN(...)

#elif LOG_LEVEL == LOG_LEVEL_WARN
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

#elif LOG_LEVEL == LOG_LEVEL_INFO
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

#elif LOG_LEVEL == LOG_LEVEL_EXTRA
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

#elif LOG_LEVEL == LOG_LEVEL_DEBUG
    #undef FLOG_TRACE
    #define FLOG_TRACE(...)
    #undef FLOGLN_TRACE
    #define FLOGLN_TRACE(...)
    #undef FLOGF_TRACE
    #define FLOGF_TRACE(...)
    #undef FLOGFLN_TRACE
    #define FLOGFLN_TRACE(...)

    #undef CLOG_TRACE
    #define CLOG_TRACE(...)
    #undef CLOGLN_TRACE
    #define CLOGLN_TRACE(...)
    #undef CLOGF_TRACE
    #define CLOGF_TRACE(...)
    #undef CLOGFLN_TRACE
    #define CLOGFLN_TRACE(...)

    #undef LOG_TRACE
    #define LOG_TRACE(...)
    #undef LOGLN_TRACE
    #define LOGLN_TRACE(...)
    #undef LOGF_TRACE
    #define LOGF_TRACE(...)
    #undef LOGFLN_TRACE
    #define LOGFLN_TRACE(...)

#else
    _NOTHING

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

LOG_DECLARE;


