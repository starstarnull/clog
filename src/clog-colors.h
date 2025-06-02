
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
 * ===========================
 * Clog Terminal Colors Header
 * ===========================
 *
 * Version: 1.0.0
 *
 * Provides macros for terminal color codes.
 *
 * The clog color C header library is used to define colors terminal console
 * output. It can be used for customizing colors in the Clog Logging library.
 *
 *
 * Features
 * ========
 *
 *      * ANZI terminal code constants.
 *      * ANZI terminal color code macro functions.
 *
 *
 * Requirements
 * ============
 *
 *      * None.
 *
 *
 * Usage
 * =====
 *
 * Simply include the header file in your project and start using the macros.
 * ANZI terminal codes are strings that can be included before the text you
 * want to affect.
 *
 *
 * Examples
 * ========
 *
 * ``` c
 *  #include <clog-colors.h>
 *  #include <stdio.h>
 *
 *  int main() {
 *      puts(C_BOLD C_RED "Hello World in bold red." C_RESET);
 *      return 0;
 *  }
 * ```
 *
 *  Outputs:    "Hello World in bold red.\n" (in bold red text).
 *
 *
 * ``` c
 *  #include <clog-colors.h>
 *  #include <stdio.h>
 *
 *  #define LINE_BUF_MAX 1024
 *
 *  int main() {
 *
 *      char line_buf[LINE_BUF_MAX];
 *
 *      while (1) {
 *          puts(C_YELLOW "> " C_RESET);
 *          fgets(line_buf, LINE_BUF_MAX, stdin);
 *
 *          if (!strcmp(line_buf, "exit\n"))
 *              break;
 *      }
 *      puts(C_BOLD C_RED "Exiting." C_RESET);
 *
 *      return 0;
 *  }
 * ```
 *
 *  Outputs:    "> " (in yellow text).
 *
 *
 * Future Plans
 * ============
 *
 *  * Add more predefined colors including all html colors.
 *  * Consider adding functions that take in rgb color codes (#00ffffff).
 *
 *
 * Exposed Constant Macros
 * =======================
 *
 * ANZI Terminal Control Codes
 * ---------------------------
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
 * Exposed Function Macros
 * =======================
 *
 *      8-Bit Colors
 *      ------------
 *
 *      C_8BIT(n)       Make text foreground `n` color where `n` is a ANZI
 *                      8-bit color code.
 *
 *      C_B_8BIT(n)     Make text background `n` color where `n` is a ANZI
 *                      8-bit color code.
 *
 *      24-Bit Colors
 *      -------------
 *
 *      C_24BIT(red, green, blue)   Make text foreground a RGB color with `red`
 *                                  amount of red, `green` amount of green, and
 *                                  `blue` amount of blue.
 *
 *      C_RGB(red, green, blue)     Alias of `C_24BIT()`.
 *
 *      C_B_24BIT(red, green, blue) Make text background a RGB color with `red`
 *                                  amount of red, `green` amount of green, and
 *                                  `blue` amount of blue.
 *
 *      C_B_RGB(red, green, blue)   Alias of `C_B_24BIT()`.
 */

// Include guard.
#pragma once


// Macros.

/**
 * ANZI Terminal Control Codes
 * ===========================
 *
 * Modifiers
 * ---------
 *
 * `C_RESET` resets the terminal colors back to normal.
 * `C_BOLD` makes text bold.
 */

/**
 *  ANZI terminal code for "reset". Resets the terminal back to default
 *  setttings.
 */
#define C_RESET             "\x1b[0m"

/**
 *  ANZI terminal code for "bold". Uses bold font.
 */
#define C_BOLD              "\x1b[1m"


/**
 * 3-Bit Colors
 * ------------
 *
 * `C_<color>` sets the terminal foreground color to <color>.
 * `C_B_<color>` sets the terminal background color to <color>.
 */

/**
 *  ANZI terminal code for black foreground color.
 */
#define C_BLACK            "\x1b[30m"

/**
 *  ANZI terminal code for red foreground color.
 */
#define C_RED              "\x1b[31m"

/**
 *  ANZI terminal code for green foreground color.
 */
#define C_GREEN            "\x1b[32m"

/**
 *  ANZI terminal code for yellow foreground color.
 */
#define C_YELLOW           "\x1b[33m"

/**
 *  ANZI terminal code for blue foreground color.
 */
#define C_BLUE             "\x1b[34m"

/**
 *  ANZI terminal code for magenta foreground color.
 */
#define C_MAGENTA          "\x1b[35m"

/**
 *  ANZI terminal code for cyan foreground color.
 */
#define C_CYAN             "\x1b[36m"

/**
 *  ANZI terminal code for white foreground color.
 */
#define C_WHITE            "\x1b[37m"

/**
 *  ANZI terminal code for black background color.
 */
#define C_B_BLACK          "\x1b[40m"

/**
 *  ANZI terminal code for red background color.
 */
#define C_B_RED            "\x1b[41m"

/**
 *  ANZI terminal code for green background color.
 */
#define C_B_GREEN          "\x1b[42m"

/**
 *  ANZI terminal code for yellow background color.
 */
#define C_B_YELLOW         "\x1b[43m"

/**
 *  ANZI terminal code for blue background color.
 */
#define C_B_BLUE           "\x1b[44m"

/**
 *  ANZI terminal code for magenta background color.
 */
#define C_B_MAGENTA        "\x1b[45m"

/**
 *  ANZI terminal code for cyan background color.
 */
#define C_B_CYAN           "\x1b[46m"

/**
 *  ANZI terminal code for white background color.
 */
#define C_B_WHITE          "\x1b[47m"


/**
 * 4-Bit Colors
 * ------------
 *
 * `C_BR_<color>` sets the terminal foreground color to bright <color>.
 * `C_B_BR_<color>` sets the terminal background color to bright <color>.
 */

/**
 *  ANZI terminal code for bright black foreground color.
 */
#define C_BR_BLACK         "\x1b[90m"

/**
 *  ANZI terminal code for bright red foreground color.
 */
#define C_BR_RED           "\x1b[91m"

/**
 *  ANZI terminal code for bright green foreground color.
 */
#define C_BR_GREEN         "\x1b[92m"

/**
 *  ANZI terminal code for bright yellow foreground color.
 */
#define C_BR_YELLOW        "\x1b[93m"

/**
 *  ANZI terminal code for bright blue foreground color.
 */
#define C_BR_BLUE          "\x1b[94m"

/**
 *  ANZI terminal code for bright magenta foreground color.
 */
#define C_BR_MAGENTA       "\x1b[95m"

/**
 *  ANZI terminal code for bright cyan foreground color.
 */
#define C_BR_CYAN          "\x1b[96m"

/**
 *  ANZI terminal code for bright white foreground color.
 */
#define C_BR_WHITE         "\x1b[97m"

/**
 *  ANZI terminal code for bright black background color.
 */
#define C_B_BR_BLACK       "\x1b[100m"

/**
 *  ANZI terminal code for bright red background color.
 */
#define C_B_BR_RED         "\x1b[101m"

/**
 *  ANZI terminal code for bright green background color.
 */
#define C_B_BR_GREEN       "\x1b[102m"

/**
 *  ANZI terminal code for bright yellow background color.
 */
#define C_B_BR_YELLOW      "\x1b[103m"

/**
 *  ANZI terminal code for bright blue background color.
 */
#define C_B_BR_BLUE        "\x1b[104m"

/**
 *  ANZI terminal code for bright magenta background color.
 */
#define C_B_BR_MAGENTA     "\x1b[105m"

/**
 *  ANZI terminal code for bright cyan background color.
 */
#define C_B_BR_CYAN        "\x1b[106m"

/**
 *  ANZI terminal code for bright white background color.
 */
#define C_B_BR_WHITE       "\x1b[107m"


/**
 * 8-bit Color Codes
 * -----------------
 *
 * `C_8BIT(<n>)` is used for foreground colors.
 * `C_B_8BIT(<n>)` is used for background colors.
 *
 * `C_8BIT(<n>)` accepts a decimal number between 0 and 255.
 * `C_B_8BIT(<n>)` accepts a decimal number between 0 and 255.
 *
 * 0 - 7 represent standard 3-bit colors.
 * 8 - 15 represent standard 4-bit bright colors.
 * 16 - 51 represent extended colors.
 * <extended color number> + 36 will lighten color.
 * 232 - 255 represent grayscale colors.
 */

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
 *  This function is a macro and does not validate that the input parameter is
 *  an integer or that it is between 0 and 255.
 *
 *  @param  n       Positive integer between 0 and 255 representing ANZI color
 *                  code.
 *  @return char*   ANZI color code string.
 */
#define C_8BIT(n)           "\x1b[38;5;" #n "m"

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
 *  This function is a macro and does not validate that the input parameter is
 *  an integer or that it is between 0 and 255.
 *
 *  @param  n       Positive integer between 0 and 255 representing ANZI color
 *                  code.
 *  @return char*   ANZI color code string.
 */
#define C_B_8BIT(n)         "\x1b[48;5;" #n "m"


/**
 * 24-bit Color Codes
 * ------------------
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
 * `C_B_24BIT(<r>, <g>, <b>)` accepts a decimal number between 0 and 255 for
 * <r>, <g>, and <b> parameters.
 *
 * 0 represents no color (i.e. black) and 255 represents the most of that
 * color (i.e., most the red for the <r> parameter, the most green for the <g>
 * parameter, and the most blue for the <b> parameter).
 */

/**
 *  const char* C_24BIT(uint_8 red, uint_8 green, uint_8 blue);
 *
 *  Convert given red, green, blue color values to a ANZI foreground color.
 *
 *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
 *  amount of blue.
 *
 *  This function is a macro and does not validate that the input parameters
 *  are integers or that their values are between 0 and 255.
 *
 *  @param  red     Positive integer between 0 and 255 representing amount of
 *                  red.
 *  @param  green   Positive integer between 0 and 255 representing amount of
 *                  green.
 *  @param  blue    Positive integer between 0 and 255 representing amount of
 *                  blue.
 *  @return char*   ANZI color code string.
 */
#define C_24BIT(red, green, blue)    "\x1b[38;2;" #red ";" #green ";" #blue "m"

/**
 *  const char* C_RGB(uint_8 red, uint_8 green, uint_8 blue);
 *
 *  Alias of `C_24BIT()`.
 *
 *  Convert given red, green, blue color values to a ANZI foreground color.
 *
 *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
 *  amount of blue.
 *
 *  This function is a macro and does not validate that the input parameters
 *  are integers or that their values are between 0 and 255.
 *
 *  @param  red     Positive integer between 0 and 255 representing amount of
 *                  red.
 *  @param  green   Positive integer between 0 and 255 representing amount of
 *                  green.
 *  @param  blue    Positive integer between 0 and 255 representing amount of
 *                  blue.
 *  @return char*   ANZI color code string.
 */
#define C_RGB(red, green, blue)      C_24BIT(red, green, blue)

/**
 *  const char* C_B_24BIT(uint_8 red, uint_8 green, uint_8 blue);
 *
 *  Convert given red, green, blue color values to a ANZI background color.
 *
 *  0 - 255 for amount of red; 0 - 255 for amount of green; and 0 - 255 for
 *  amount of blue.
 *
 *  This function is a macro and does not validate that the input parameters
 *  are integers or that their values are between 0 and 255.
 *
 *  @param  red     Positive integer between 0 and 255 representing amount of
 *                  red.
 *  @param  green   Positive integer between 0 and 255 representing amount of
 *                  green.
 *  @param  blue    Positive integer between 0 and 255 representing amount of
 *                  blue.
 *  @return char*   ANZI color code string.
 */
#define C_B_24BIT(red, green, blue)  "\x1b[48;2;" #red ";" #green ";" #blue "m"

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
 *  This function is a macro and does not validate that the input parameters
 *  are integers or that their values are between 0 and 255.
 *
 *  @param  red     Positive integer between 0 and 255 representing amount of
 *                  red.
 *  @param  green   Positive integer between 0 and 255 representing amount of
 *                  green.
 *  @param  blue    Positive integer between 0 and 255 representing amount of
 *                  blue.
 *  @return char*   ANZI color code string.
 */
#define C_B_RGB(red, green, blue)    C_B_24BIT(red, green, blue)


/**
 *  Other Colors
 *  ------------
 *
 *  These colors are just extra predefined colors.
 */

/**
 *  ANZI terminal code for orange foreground color.
 */
#define C_ORANGE            C_24BIT(253, 198, 21)

/**
 *  ANZI terminal code for orange background color.
 */
#define C_B_ORANGE          C_B_24BIT(253, 198, 21)

/**
 *  ANZI terminal code for gray foreground color.
 */
#define C_GRAY              C_24BIT(128, 128, 128)

/**
 *  ANZI terminal code for gray background color.
 */
#define C_B_GRAY            C_B_24BIT(128, 128, 128)

/**
 *  ANZI terminal code for dark gray foreground color.
 */
#define C_DARK_GRAY         C_24BIT(64, 64, 64)

/**
 *  ANZI terminal code for dark gray background color.
 */
#define C_B_DARK_GRAY       C_B_24BIT(64, 64, 64)


