
Exposed Constant Macros
=======================

ANZI Terminal Control Codes
---------------------------

Modifiers
---------

    C_RESET         Reset terminal color and modifier state.
    C_BOLD          Make text bold font.


3-bit Foreground Colors
-----------------------

    C_BLACK         Make text foreground black.
    C_RED           Make text foreground red.
    C_GREEN         Make text foreground green.
    C_YELLOW        Make text foreground yellow.
    C_BLUE          Make text foreground blue.
    C_MAGENTA       Make text foreground magenta.
    C_CYAN          Make text foreground cyan.
    C_WHITE         Make text foreground white.


3-bit Background Colors
-----------------------

    C_B_BLACK       Make text background black.
    C_B_RED         Make text background red.
    C_B_GREEN       Make text background green.
    C_B_YELLOW      Make text background yellow.
    C_B_BLUE        Make text background blue.
    C_B_MAGENTA     Make text background magenta.
    C_B_CYAN        Make text background cyan.
    C_B_WHITE       Make text background white.


4-bit Bright Foreground Colors
------------------------------

    C_BR_BLACK      Make text foreground bright black.
    C_BR_RED        Make text foreground bright red.
    C_BR_GREEN      Make text foreground bright green.
    C_BR_YELLOW     Make text foreground bright yellow.
    C_BR_BLUE       Make text foreground bright blue.
    C_BR_MAGENTA    Make text foreground bright magenta.
    C_BR_CYAN       Make text foreground bright cyan.
    C_BR_WHITE      Make text foreground bright white.


4-bit Bright Background Colors
------------------------------

    C_B_BR_BLACK    Make text background bright black.
    C_B_BR_RED      Make text background bright red.
    C_B_BR_GREEN    Make text background bright green.
    C_B_BR_YELLOW   Make text background bright yellow.
    C_B_BR_BLUE     Make text background bright blue.
    C_B_BR_MAGENTA  Make text background bright magenta.
    C_B_BR_CYAN     Make text background bright cyan.
    C_B_BR_WHITE    Make text background bright white.


Other Colors
------------

    C_ORANGE        Maket text foreground an orange color.
    C_B_ORANGE      Maket text background an orange color.
    C_GRAY          Maket text foreground an gray color.
    C_B_GRAY        Maket text background an gray color.
    C_DARK_GRAY     Maket text foreground an dark gray color.
    C_B_DARK_GRAY   Maket text background an dark gray color.


Log Level Color Palette
-----------------------

    C_TRACE         Defaults to dark gray.
    C_DEBUG         Defaults to cyan.
    C_EXTRA         Defaults to dark gray.
    C_INFO          Defaults to bright blue.
    C_HEADER        Defaults to bold bright yellow.
    C_SUCCESS       Defaults to green.
    C_MONEY         Defaults to bold green.
    C_INPUT         Defaults to bright magenta.
    C_WARNING       Defaults to orange.
    C_ERROR         Defaults to bright red.
    C_CRITICAL      Defaults to bold bright red.
    C_FATAL         Defaults to bold bright red.


Log Level Color Short Aliases (if enabled)
------------------------------------------

    C_TRC           Defaults to C_TRACE.
    C_DBG           Defaults to C_DEBUG.
    C_EXT           Defaults to C_EXTRA.
    C_INF           Defaults to C_INFO.
    C_HEAD          Defaults to C_HEADER.
    C_SUC           Defaults to C_SUCCESS.
    C_MON           Defaults to C_MONEY.
    C_MNY           Defaults to C_MONEY.
    C_IN            Defaults to C_INPUT.
    C_WARN          Defaults to C_WARNING.
    C_ERR           Defaults to C_ERROR.
    C_CRIT          Defaults to C_CRITICAL.
    C_FAT           Defaults to C_FATAL.


Log Level Color Shorter Aliases (if enabled)
--------------------------------------------

    C_TR            Defaults to C_TRACE.
    C_DB            Defaults to C_DEBUG.
    C_EX            Defaults to C_EXTRA.
    C_IF            Defaults to C_INFO.
    C_HD            Defaults to C_HEADER.
    C_SC            Defaults to C_SUCCESS.
    C_MN            Defaults to C_MONEY.
    C_MY            Defaults to C_MONEY.
    C_IN            Defaults to C_INPUT.
    C_WN            Defaults to C_WARNING.
    C_ER            Defaults to C_ERROR.
    C_CR            Defaults to C_CRITICAL.
    C_FT            Defaults to C_FATAL.


Logging Strings
---------------

### Log Level Header Symbols

    CLOG_SYM_TRACE      Defaults to "[TRACE]"
    CLOG_SYM_DEBUG      Defaults to "[DEBUG]"
    CLOG_SYM_EXTRA      Defaults to "[.]"
    CLOG_SYM_INFO       Defaults to "[*]"
    CLOG_SYM_HEADER     Defaults to "[***]"
    CLOG_SYM_SUCCESS    Defaults to "[+]"
    CLOG_SYM_MONEY      Defaults to "[$]"
    CLOG_SYM_INPUT      Defaults to "[?]"
    CLOG_SYM_WARNING    Defaults to "[!]"
    CLOG_SYM_ERROR      Defaults to "[-]"
    CLOG_SYM_CRITICAL   Defaults to "[!!!]"
    CLOG_SYM_FATAL      Defaults to "[FATAL]"


### Log Level Header Symbol Short Aliases (if enabled)

    CSYM_TRC        Defaults to CLOG_SYM_TRACE.
    CSYM_DBG        Defaults to CLOG_SYM_DEBUG.
    CSYM_EXT        Defaults to CLOG_SYM_EXTRA.
    CSYM_INF        Defaults to CLOG_SYM_INFO.
    CSYM_HEAD       Defaults to CLOG_SYM_HEADER.
    CSYM_SUC        Defaults to CLOG_SYM_SUCCESS.
    CSYM_MON        Defaults to CLOG_SYM_MONEY.
    CSYM_MNY        Defaults to CLOG_SYM_MONEY.
    CSYM_IN         Defaults to CLOG_SYM_INPUT.
    CSYM_WARN       Defaults to CLOG_SYM_WARNING.
    CSYM_ERR        Defaults to CLOG_SYM_ERROR.
    CSYM_CRIT       Defaults to CLOG_SYM_CRITICAL.
    CSYM_FAT        Defaults to CLOG_SYM_FATAL.


### Log Level Color Shorter Aliases (if enabled)

    CSYM_TR         Defaults to CLOG_SYM_TRACE.
    CSYM_DB         Defaults to CLOG_SYM_DEBUG.
    CSYM_EX         Defaults to CLOG_SYM_EXTRA.
    CSYM_IF         Defaults to CLOG_SYM_INFO.
    CSYM_HD         Defaults to CLOG_SYM_HEADER.
    CSYM_SC         Defaults to CLOG_SYM_SUCCESS.
    CSYM_MN         Defaults to CLOG_SYM_MONEY.
    CSYM_MY         Defaults to CLOG_SYM_MONEY.
    CSYM_IN         Defaults to CLOG_SYM_INPUT.
    CSYM_WN         Defaults to CLOG_SYM_WARNING.
    CSYM_ER         Defaults to CLOG_SYM_ERROR.
    CSYM_CR         Defaults to CLOG_SYM_CRITICAL.
    CSYM_FT         Defaults to CLOG_SYM_FATAL.


Options Constants
-----------------

    CLOG_ENABLE_SHORT_ALIASES       Defaults to not defined.
    CLOG_ENABLE_SHORTER_ALIASES     Defaults to not defined.
    CLOG_ENABLE_NAME_ALIASES        Defaults to not defined.

    CLOG_LINE_HEADER_SEP            Defaults to space.
    CLOG_TRACING_SEP                Defaults to colon.

    CLOG_LEVEL_SYMS_NONE            Symbol option 0.
    CLOG_LEVEL_SYMS_WORDS           Symbol option 1.
    CLOG_LEVEL_SYMS_LETTERS         Symbol option 2.
    CLOG_LEVEL_SYMS_ONE_CHAR        Symbol option 3.
    CLOG_LEVEL_SYMS_THREE_CHAR      Symbol option 4.
    CLOG_LEVEL_SYMS_EMOJIS          Symbol option 5.
    CLOG_LEVEL_SYMS_DEFAULT         Symbol option 6.
    CLOG_LEVEL_SYMS                 Defaults to CLOG_LEVEL_DEFAULT.

    CLOG_CONSOLE_MODE_NOCOLOR       Console mode option 0.
    CLOG_CONSOLE_MODE_COLOR         Console mode option 1.
    CLOG_CONSOLE_MODE               Defaults to CLOG_CONSOLE_MODE_COLOR.

    CLOG_MODE_NONE                  Log mode option 0.
    CLOG_MODE_CONSOLE               Log mode option 1.
    CLOG_MODE_FILE                  Log mode option 2.
    CLOG_MODE_CONSOLE_AND_FILE      Log mode option 3.
    CLOG_MODE                       Defaults to CLOG_MODE_CONSOLE_AND_FILE.

    CLOG_LEVEL_NONE                 Log level option 0.
    CLOG_LEVEL_CRITICAL             Log level option 1.
    CLOG_LEVEL_ERROR                Log level option 2.
    CLOG_LEVEL_WARNING              Log level option 3.
    CLOG_LEVEL_INFO                 Log level option 4.
    CLOG_LEVEL_EXTRA                Log level option 5.
    CLOG_LEVEL_DEBUG                Log level option 6.
    CLOG_LEVEL_ALL                  Log level option 7.
    CLOG_LEVEL                      Defaults to CLOG_LEVEL_ALL.

    CLOG_FILE                       Defaults to "<c_source_file>.log".
    CLOG_TIME_FORMAT                Defaults to "%FT%T%z"

    CLOG_DISABLE_TIMESTAMPS         Defaults to not defined.
    CLOG_USE_UTC_TIME               Defaults to not defined.
    CLOG_DISABLE_TRACING            Defaults to not defined.


Exposed Function Macros
=======================

Color Functions
---------------

### 8-Bit Colors

    C_8BIT(n)       Make text foreground `n` color where `n` is a ANZI
                    8-bit color code. Argument must be in decimal.

    C_B_8BIT(n)     Make text background `n` color where `n` is a ANZI
                    8-bit color code. Argument must be in decimal.


### 24-Bit Colors

    C_24BIT(red, green, blue)   Make text foreground a RGB color with `red`
                                amount of red, `green` amount of green, and
                                `blue` amount of blue. Arguments must be in
                                decimal.

    C_RGB(red, green, blue)     Alias of `C_24BIT()`.

    C_B_24BIT(red, green, blue) Make text background a RGB color with `red`
                                amount of red, `green` amount of green, and
                                `blue` amount of blue. Arguments must be in
                                decimal.

    C_B_RGB(red, green, blue)   Alias of `C_B_24BIT()`.


Fundamental Functions
---------------------

### "fprint" Functions

    FPRINT(FILE* stream, const char* str)

        Print the given string to the given stream.

    FPRINTLN(FILE* stream, const char* str)

        Print the given string to the given stream followed by a newline.

    FPRINTF(FILE* stream, const char* format, ...)

        Print given format string and format arguments to the given file
        stream.

    FPRINTFLN(FILE* stream, const char* format, ...)

        Print given format string and format arguments to the given file
        stream followed by a newline.

    FPRINT_HEX(FILE* stream, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string.

    FPRINTLN_HEX(FILE* stream, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string followed by a
        newline.

    FPRINT_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces.

    FPRINTLN_WIDE_HEX(FILE* stream, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces followed by a
        newline.

    FPERROR(FILE* stream, char* str)

        Print given string to the given file stream and then print the C
        error message.

    FPERRORF(FILE* stream, char* format, ...)

        Print given format string and format arguments to the given file
        stream followed by a C error message.


### "cfprint" Functions

    CFPRINT(const char* color, FILE* stream, const char* str)

        Print given string to the given file stream in the given color.

    CFPRINTLN(const char* color, FILE* stream, const char* str)

        Print given string to the given file stream followed by a newline
        in the given color.

    CFPRINTF(const char* color, FILE* stream, const char* format, ...)

        Print given format string and format arguments to the given file
        stream in the given color.

    CFPRINTFLN(const char* color, FILE* stream, const char* format, ...)

        Print given format string and format arguments to the given file
        stream followed by a newline in the given color.

    CFPRINT_HEX(
        const char* color,
        FILE* stream,
        const uint8_t* buffer,
        size_t length
    )

        Print the bytes of the given buffer as a hex string in the given
        color.

    CFPRINTLN_HEX(
        const char* color,
        FILE* stream,
        const uint8_t* buffer,
        size_t length
    )

        Print the bytes of the given buffer as a hex string followed by a
        newline in the given color.

    CFPRINT_WIDE_HEX(
        const char* color,
        FILE* stream,
        const uint8_t* buffer,
        size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces in the given color.

    CFPRINTLN_WIDE_HEX(
        const char* color,
        FILE* stream,
        const uint8_t* buffer,
        size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces followed by a newline
        in the given color.

    CFPERROR(const char* color, FILE* stream, const char* str)

        Print given string to the given file stream and then print the C
        error message in the given color.

    CFPERRORF(const char* color, FILE* stream, const char* format, ...)

        Print given format string and format arguments to the given file
        stream followed by a C error message in the given color.


Printing Functions
------------------

### "print" Functions

    PRINT(const char* str)

        Print given string to standard output.

    PRINTLN(const char* str)

        Print given string to standard output followed by a newline.

    PRINTF(const char* format, ...)

        Print given format string and format arguments to standard output.

    PRINTFLN(const char* format, ...)

        Print given format string and format arguments to standard output
        followed by a newline.

    PRINT_HEX(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        output.

    PRINTLN_HEX(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        output followed by a newline.

    PRINT_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard output.

    PRINTLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard output
        followed by a newline.

    PERROR(const char* str)

        Print given string to standard output and then print the C error
        message.

    PERRORF(const char* format, ...)

        Print given format string and format arguments to standard output
        followed by a C error message.


### "print_level" Functions

    PRINT_TRACE(const char* str)

        Print trace line header followed by the given string to standard
        output.

    PRINTLN_TRACE(const char* str)

        Print trace line header followed by given string to standard
        output followed by a newline.

    PRINTF_TRACE(const char* format, ...)

        Print trace line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_TRACE(const char* format, ...)

        Print trace line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_DEBUG(const char* str)

        Print debug line header followed by the given string to standard
        output.

    PRINTLN_DEBUG(const char* str)

        Print debug line header followed by given string to standard
        output followed by a newline.

    PRINTF_DEBUG(const char* format, ...)

        Print debug line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_DEBUG(const char* format, ...)

        Print debug line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_EXTRA(const char* str)

        Print extra line header followed by the given string to standard
        output.

    PRINTLN_EXTRA(const char* str)

        Print extra line header followed by given string to standard
        output followed by a newline.

    PRINTF_EXTRA(const char* format, ...)

        Print extra line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_EXTRA(const char* format, ...)

        Print extra line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_INFO(const char* str)

        Print info line header followed by the given string to standard
        output.

    PRINTLN_INFO(const char* str)

        Print info line header followed by given string to standard
        output followed by a newline.

    PRINTF_INFO(const char* format, ...)

        Print info line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_INFO(const char* format, ...)

        Print info line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_HEADER(const char* str)

        Print header line header followed by the given string to standard
        output.

    PRINTLN_HEADER(const char* str)

        Print header line header followed by given string to standard
        output followed by a newline.

    PRINTF_HEADER(const char* format, ...)

        Print header line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_HEADER(const char* format, ...)

        Print header line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_SUCCESS(const char* str)

        Print success line header followed by the given string to standard
        output.

    PRINTLN_SUCCESS(const char* str)

        Print success line header followed by given string to standard
        output followed by a newline.

    PRINTF_SUCCESS(const char* format, ...)

        Print success line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_SUCCESS(const char* format, ...)

        Print success line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_MONEY(const char* str)

        Print money line header followed by the given string to standard
        output.

    PRINTLN_MONEY(const char* str)

        Print money line header followed by given string to standard
        output followed by a newline.

    PRINTF_MONEY(const char* format, ...)

        Print money line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_MONEY(const char* format, ...)

        Print money line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_INPUT(const char* str)

        Print input line header followed by the given string to standard
        output.

    PRINTLN_INPUT(const char* str)

        Print input line header followed by given string to standard
        output followed by a newline.

    PRINTF_INPUT(const char* format, ...)

        Print input line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_INPUT(const char* format, ...)

        Print input line header followed by given format string and
        format arguments to standard output followed by a newline.


    PRINT_WARNING(const char* str)

        Print warning line header followed by the given string to standard
        output.

    PRINTLN_WARNING(const char* str)

        Print warning line header followed by given string to standard
        output followed by a newline.

    PRINTF_WARNING(const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_WARNING(const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output followed by a newline.

    PERROR_WARNING(const char* str)

        Print warning line header followed by given string to standard
        output and then print the C error message.

    PERRORF_WARNING(const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output followed by a C error message.


    PRINT_ERROR(const char* str)

        Print error line header followed by the given string to standard
        output.

    PRINTLN_ERROR(const char* str)

        Print error line header followed by given string to standard
        output followed by a newline.

    PRINTF_ERROR(const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_ERROR(const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output followed by a newline.

    PERROR_ERROR(const char* str)

        Print error line header followed by given string to standard
        output and then print the C error message.

    PERRORF_ERROR(const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output followed by a C error message.


    PRINT_CRITICAL(const char* str)

        Print critical line header followed by the given string to standard
        output.

    PRINTLN_CRITICAL(const char* str)

        Print critical line header followed by given string to standard
        output followed by a newline.

    PRINTF_CRITICAL(const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_CRITICAL(const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output followed by a newline.

    PERROR_CRITICAL(const char* str)

        Print critical line header followed by given string to standard
        output and then print the C error message.

    PERRORF_CRITICAL(const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output followed by a C error message.


    PRINT_FATAL(const char* str)

        Print fatal line header followed by the given string to standard
        output.

    PRINTLN_FATAL(const char* str)

        Print fatal line header followed by given string to standard
        output followed by a newline.

    PRINTF_FATAL(const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output.

    PRINTFLN_FATAL(const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output followed by a newline.

    PERROR_FATAL(const char* str)

        Print fatal line header followed by given string to standard
        output and then print the C error message.

    PERRORF_FATAL(const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output followed by a C error message.


### "print_level" Functions Short Aliases (if enabled)

    PRINT_TRC(const char* str)              Alias of PRINT_TRACE.
    PRINTLN_TRC(const char* str)            Alias of PRINTLN_TRACE.
    PRINTF_TRC(const char* format, ...)     Alias of PRINTF_TRACE.
    PRINTFLN_TRC(const char* format, ...)   Alias of PRINTFLN_TRACE.

    PRINT_DBG(const char* str)              Alias of PRINT_DEBUG.
    PRINTLN_DBG(const char* str)            Alias of PRINTLN_DEBUG.
    PRINTF_DBG(const char* format, ...)     Alias of PRINTF_DEBUG.
    PRINTFLN_DBG(const char* format, ...)   Alias of PRINTFLN_DEBUG.

    PRINT_EXT(const char* str)              Alias of PRINT_EXTRA.
    PRINTLN_EXT(const char* str)            Alias of PRINTLN_EXTRA.
    PRINTF_EXT(const char* format, ...)     Alias of PRINTF_EXTRA.
    PRINTFLN_EXT(const char* format, ...)   Alias of PRINTFLN_EXTRA.

    PRINT_INF(const char* str)              Alias of PRINT_INFO.
    PRINTLN_INF(const char* str)            Alias of PRINTLN_INFO.
    PRINTF_INF(const char* format, ...)     Alias of PRINTF_INFO.
    PRINTFLN_INF(const char* format, ...)   Alias of PRINTFLN_INFO.

    PRINT_HEAD(const char* str)             Alias of PRINT_HEADER.
    PRINTLN_HEAD(const char* str)           Alias of PRINTLN_HEADER.
    PRINTF_HEAD(const char* format, ...)    Alias of PRINTF_HEADER.
    PRINTFLN_HEAD(const char* format, ...)  Alias of PRINTFLN_HEADER.

    PRINT_SUC(const char* str)              Alias of PRINT_SUCCESS.
    PRINTLN_SUC(const char* str)            Alias of PRINTLN_SUCCESS.
    PRINTF_SUC(const char* format, ...)     Alias of PRINTF_SUCCESS.
    PRINTFLN_SUC(const char* format, ...)   Alias of PRINTFLN_SUCCESS.

    PRINT_MON(const char* str)              Alias of PRINT_MONEY.
    PRINTLN_MON(const char* str)            Alias of PRINTLN_MONEY.
    PRINTF_MON(const char* format, ...)     Alias of PRINTF_MONEY.
    PRINTFLN_MON(const char* format, ...)   Alias of PRINTFLN_MONEY.

    PRINT_MNY(const char* str)              Alias of PRINT_MONEY.
    PRINTLN_MNY(const char* str)            Alias of PRINTLN_MONEY.
    PRINTF_MNY(const char* format, ...)     Alias of PRINTF_MONEY.
    PRINTFLN_MNY(const char* format, ...)   Alias of PRINTFLN_MONEY.

    PRINT_IN(const char* str)               Alias of PRINT_INPUT.
    PRINTLN_IN(const char* str)             Alias of PRINTLN_INPUT.
    PRINTF_IN(const char* format, ...)      Alias of PRINTF_INPUT.
    PRINTFLN_IN(const char* format, ...)    Alias of PRINTFLN_INPUT.

    PRINT_WARN(const char* str)             Alias of PRINT_WARNING.
    PRINTLN_WARN(const char* str)           Alias of PRINTLN_WARNING.
    PRINTF_WARN(const char* format, ...)    Alias of PRINTF_WARNING.
    PRINTFLN_WARN(const char* format, ...)  Alias of PRINTFLN_WARNING.

    PERROR_WARN(const char* str)            Alias of PERROR_WARNING.
    PERRORF_WARN(const char* format, ...)   Alias of PERRORF_WARNING.

    PRINT_ERR(const char* str)              Alias of PRINT_ERROR.
    PRINTLN_ERR(const char* str)            Alias of PRINTLN_ERROR.
    PRINTF_ERR(const char* format, ...)     Alias of PRINTF_ERROR.
    PRINTFLN_ERR(const char* format, ...)   Alias of PRINTFLN_ERROR.

    PERROR_ERR(const char* str)             Alias of PERROR_ERROR.
    PERRORF_ERR(const char* format, ...)    Alias of PERRORF_ERROR.

    PRINT_CRIT(const char* str)             Alias of PRINT_CRITICAL.
    PRINTLN_CRIT(const char* str)           Alias of PRINTLN_CRITICAL.
    PRINTF_CRIT(const char* format, ...)    Alias of PRINTF_CRITICAL.
    PRINTFLN_CRIT(const char* format, ...)  Alias of PRINTFLN_CRITICAL.

    PERROR_CRIT(const char* str)            Alias of PERROR_CRITICAL.
    PERRORF_CRIT(const char* format, ...)   Alias of PERRORF_CRITICAL.

    PRINT_FAT(const char* str)              Alias of PRINT_FATAL.
    PRINTLN_FAT(const char* str)            Alias of PRINTLN_FATAL.
    PRINTF_FAT(const char* format, ...)     Alias of PRINTF_FATAL.
    PRINTFLN_FAT(const char* format, ...)   Alias of PRINTFLN_FATAL.

    PERROR_FAT(const char* str)             Alias of PERROR_FATAL.
    PERRORF_FAT(const char* format, ...)    Alias of PERRORF_FATAL.


### "print_level" Functions Shorter Aliases (if enabled)

    PRINT_TR(const char* str)               Alias of PRINT_TRACE.
    PRINTLN_TR(const char* str)             Alias of PRINTLN_TRACE.
    PRINTF_TR(const char* format, ...)      Alias of PRINTF_TRACE.
    PRINTFLN_TR(const char* format, ...)    Alias of PRINTFLN_TRACE.

    PRINT_DB(const char* str)               Alias of PRINT_DEBUG.
    PRINTLN_DB(const char* str)             Alias of PRINTLN_DEBUG.
    PRINTF_DB(const char* format, ...)      Alias of PRINTF_DEBUG.
    PRINTFLN_DB(const char* format, ...)    Alias of PRINTFLN_DEBUG.

    PRINT_EX(const char* str)               Alias of PRINT_EXTRA.
    PRINTLN_EX(const char* str)             Alias of PRINTLN_EXTRA.
    PRINTF_EX(const char* format, ...)      Alias of PRINTF_EXTRA.
    PRINTFLN_EX(const char* format, ...)    Alias of PRINTFLN_EXTRA.

    PRINT_IF(const char* str)               Alias of PRINT_INFO.
    PRINTLN_IF(const char* str)             Alias of PRINTLN_INFO.
    PRINTF_IF(const char* format, ...)      Alias of PRINTF_INFO.
    PRINTFLN_IF(const char* format, ...)    Alias of PRINTFLN_INFO.

    PRINT_HD(const char* str)               Alias of PRINT_HEADER.
    PRINTLN_HD(const char* str)             Alias of PRINTLN_HEADER.
    PRINTF_HD(const char* format, ...)      Alias of PRINTF_HEADER.
    PRINTFLN_HD(const char* format, ...)    Alias of PRINTFLN_HEADER.

    PRINT_SC(const char* str)               Alias of PRINT_SUCCESS.
    PRINTLN_SC(const char* str)             Alias of PRINTLN_SUCCESS.
    PRINTF_SC(const char* format, ...)      Alias of PRINTF_SUCCESS.
    PRINTFLN_SC(const char* format, ...)    Alias of PRINTFLN_SUCCESS.

    PRINT_MN(const char* str)               Alias of PRINT_MONEY.
    PRINTLN_MN(const char* str)             Alias of PRINTLN_MONEY.
    PRINTF_MN(const char* format, ...)      Alias of PRINTF_MONEY.
    PRINTFLN_MN(const char* format, ...)    Alias of PRINTFLN_MONEY.

    PRINT_MY(const char* str)               Alias of PRINT_MONEY.
    PRINTLN_MY(const char* str)             Alias of PRINTLN_MONEY.
    PRINTF_MY(const char* format, ...)      Alias of PRINTF_MONEY.
    PRINTFLN_MY(const char* format, ...)    Alias of PRINTFLN_MONEY.

    PRINT_IN(const char* str)               Alias of PRINT_INPUT.
    PRINTLN_IN(const char* str)             Alias of PRINTLN_INPUT.
    PRINTF_IN(const char* format, ...)      Alias of PRINTF_INPUT.
    PRINTFLN_IN(const char* format, ...)    Alias of PRINTFLN_INPUT.

    PRINT_WN(const char* str)               Alias of PRINT_WARNING.
    PRINTLN_WN(const char* str)             Alias of PRINTLN_WARNING.
    PRINTF_WN(const char* format, ...)      Alias of PRINTF_WARNING.
    PRINTFLN_WN(const char* format, ...)    Alias of PRINTFLN_WARNING.

    PERROR_WN(const char* str)              Alias of PERROR_WARNING.
    PERRORF_WN(const char* format, ...)     Alias of PERRORF_WARNING.

    PRINT_ER(const char* str)               Alias of PRINT_ERROR.
    PRINTLN_ER(const char* str)             Alias of PRINTLN_ERROR.
    PRINTF_ER(const char* format, ...)      Alias of PRINTF_ERROR.
    PRINTFLN_ER(const char* format, ...)    Alias of PRINTFLN_ERROR.

    PERROR_ER(const char* str)              Alias of PERROR_ERROR.
    PERRORF_ER(const char* format, ...)     Alias of PERRORF_ERROR.

    PRINT_CR(const char* str)               Alias of PRINT_CRITICAL.
    PRINTLN_CR(const char* str)             Alias of PRINTLN_CRITICAL.
    PRINTF_CR(const char* format, ...)      Alias of PRINTF_CRITICAL.
    PRINTFLN_CR(const char* format, ...)    Alias of PRINTFLN_CRITICAL.

    PERROR_CR(const char* str)              Alias of PERROR_CRITICAL.
    PERRORF_CR(const char* format, ...)     Alias of PERRORF_CRITICAL.

    PRINT_FT(const char* str)               Alias of PRINT_FATAL.
    PRINTLN_FT(const char* str)             Alias of PRINTLN_FATAL.
    PRINTF_FT(const char* format, ...)      Alias of PRINTF_FATAL.
    PRINTFLN_FT(const char* format, ...)    Alias of PRINTFLN_FATAL.

    PERROR_FT(const char* str)              Alias of PERROR_FATAL.
    PERRORF_FT(const char* format, ...)     Alias of PERRORF_FATAL.


### "cprint" Functions

    CPRINT(const char* color, const char* str)

        Print given string to standard output in the given color.

    CPRINTLN(const char* color, const char* str)

        Print given string to standard output followed by a newline in the
        given color.

    CPRINTF(const char* color, const char* format, ...)

        Print given format string and format arguments to standard output
        in the given color.

    CPRINTFLN(const char* color, const char* format, ...)

        Print given format string and format arguments to standard output
        followed by a newline in the given color.

    CPRINT_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        output in the given color.

    CPRINTLN_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        output followed by a newline in the given color.

    CPRINT_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard output in
        the given color.

    CPRINTLN_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard output
        followed by a newline in the given color.

    CPERROR(const char* color, const char* str)

        Print given string to standard output and then print the C error
        message in the given color.

    CPERRORF(const char* color, const char* format, ...)

        Print given format string and format arguments to standard output
        followed by a C error message in the given color.


### "cprint_level" Functions

    CPRINT_TRACE(const char* color, const char* str)

        Print trace line header followed by the given string to standard
        output in the given color.

    CPRINTLN_TRACE(const char* color, const char* str)

        Print trace line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_TRACE(const char* color, const char* format, ...)

        Print trace line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_TRACE(const char* color, const char* format, ...)

        Print trace line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_DEBUG(const char* color, const char* str)

        Print debug line header followed by the given string to standard
        output in the given color.

    CPRINTLN_DEBUG(const char* color, const char* str)

        Print debug line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_DEBUG(const char* color, const char* format, ...)

        Print debug line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_DEBUG(const char* color, const char* format, ...)

        Print debug line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_EXTRA(const char* color, const char* str)

        Print extra line header followed by the given string to standard
        output in the given color.

    CPRINTLN_EXTRA(const char* color, const char* str)

        Print extra line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_EXTRA(const char* color, const char* format, ...)

        Print extra line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_EXTRA(const char* color, const char* format, ...)

        Print extra line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_INFO(const char* color, const char* str)

        Print info line header followed by the given string to standard
        output in the given color.

    CPRINTLN_INFO(const char* color, const char* str)

        Print info line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_INFO(const char* color, const char* format, ...)

        Print info line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_INFO(const char* color, const char* format, ...)

        Print info line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_HEADER(const char* color, const char* str)

        Print header line header followed by the given string to standard
        output in the given color.

    CPRINTLN_HEADER(const char* color, const char* str)

        Print header line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_HEADER(const char* color, const char* format, ...)

        Print header line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_HEADER(const char* color, const char* format, ...)

        Print header line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_SUCCESS(const char* color, const char* str)

        Print success line header followed by the given string to standard
        output in the given color.

    CPRINTLN_SUCCESS(const char* color, const char* str)

        Print success line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_SUCCESS(const char* color, const char* format, ...)

        Print success line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_SUCCESS(const char* color, const char* format, ...)

        Print success line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_MONEY(const char* color, const char* str)

        Print money line header followed by the given string to standard
        output in the given color.

    CPRINTLN_MONEY(const char* color, const char* str)

        Print money line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_MONEY(const char* color, const char* format, ...)

        Print money line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_MONEY(const char* color, const char* format, ...)

        Print money line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_INPUT(const char* color, const char* str)

        Print input line header followed by the given string to standard
        output in the given color.

    CPRINTLN_INPUT(const char* color, const char* str)

        Print input line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_INPUT(const char* color, const char* format, ...)

        Print input line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_INPUT(const char* color, const char* format, ...)

        Print input line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.


    CPRINT_WARNING(const char* color, const char* str)

        Print warning line header followed by the given string to standard
        output in the given color.

    CPRINTLN_WARNING(const char* color, const char* str)

        Print warning line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_WARNING(const char* color, const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_WARNING(const char* color, const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.

    CPERROR_WARNING(const char* color, const char* str)

        Print warning line header followed by given string to standard
        output and then print the C error message in the given color.

    CPERRORF_WARNING(const char* color, const char* format, ...)

        Print warning line header followed by given format string and
        format arguments to standard output followed by a C error message
        in the given color.


    CPRINT_ERROR(const char* color, const char* str)

        Print error line header followed by the given string to standard
        output in the given color.

    CPRINTLN_ERROR(const char* color, const char* str)

        Print error line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_ERROR(const char* color, const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_ERROR(const char* color, const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.

    CPERROR_ERROR(const char* color, const char* str)

        Print error line header followed by given string to standard
        output and then print the C error message in the given color.

    CPERRORF_ERROR(const char* color, const char* format, ...)

        Print error line header followed by given format string and
        format arguments to standard output followed by a C error message
        in the given color.


    CPRINT_CRITICAL(const char* color, const char* str)

        Print critical line header followed by the given string to standard
        output in the given color.

    CPRINTLN_CRITICAL(const char* color, const char* str)

        Print critical line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_CRITICAL(const char* color, const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_CRITICAL(const char* color, const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.

    CPERROR_CRITICAL(const char* color, const char* str)

        Print critical line header followed by given string to standard
        output and then print the C error message in the given color.

    CPERRORF_CRITICAL(const char* color, const char* format, ...)

        Print critical line header followed by given format string and
        format arguments to standard output followed by a C error message
        in the given color.


    CPRINT_FATAL(const char* color, const char* str)

        Print fatal line header followed by the given string to standard
        output in the given color.

    CPRINTLN_FATAL(const char* color, const char* str)

        Print fatal line header followed by given string to standard
        output followed by a newline in the given color.

    CPRINTF_FATAL(const char* color, const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output in the given color.

    CPRINTFLN_FATAL(const char* color, const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output followed by a newline in the
        given color.

    CPERROR_FATAL(const char* color, const char* str)

        Print fatal line header followed by given string to standard
        output and then print the C error message in the given color.

    CPERRORF_FATAL(const char* color, const char* format, ...)

        Print fatal line header followed by given format string and
        format arguments to standard output followed by a C error message
        in the given color.


### "cprint_level" Functions Short Aliases (if enabled)

    CPRINT_TRC(const char* color, const char* str)

        Alias of CPRINT_TRACE.

    CPRINTLN_TRC(const char* color, const char* str)

        Alias of CPRINTLN_TRACE.

    CPRINTF_TRC(const char* color, const char* format, ...)

        Alias of CPRINTF_TRACE.

    CPRINTFLN_TRC(const char* color, const char* format, ...)

        Alias of CPRINTFLN_TRACE.


    CPRINT_DBG(const char* color, const char* str)

        Alias of CPRINT_DEBUG.

    CPRINTLN_DBG(const char* color, const char* str)

        Alias of CPRINTLN_DEBUG.

    CPRINTF_DBG(const char* color, const char* format, ...)

        Alias of CPRINTF_DEBUG.

    CPRINTFLN_DBG(const char* color, const char* format, ...)

        Alias of CPRINTFLN_DEBUG.


    CPRINT_EXT(const char* color, const char* str)

        Alias of CPRINT_EXTRA.

    CPRINTLN_EXT(const char* color, const char* str)

        Alias of CPRINTLN_EXTRA.

    CPRINTF_EXT(const char* color, const char* format, ...)

        Alias of CPRINTF_EXTRA.

    CPRINTFLN_EXT(const char* color, const char* format, ...)

        Alias of CPRINTFLN_EXTRA.


    CPRINT_INF(const char* color, const char* str)

        Alias of CPRINT_INFO.

    CPRINTLN_INF(const char* color, const char* str)

        Alias of CPRINTLN_INFO.

    CPRINTF_INF(const char* color, const char* format, ...)

        Alias of CPRINTF_INFO.

    CPRINTFLN_INF(const char* color, const char* format, ...)

        Alias of CPRINTFLN_INFO.


    CPRINT_HEAD(const char* color, const char* str)

        Alias of CPRINT_HEADER.

    CPRINTLN_HEAD(const char* color, const char* str)

        Alias of CPRINTLN_HEADER.

    CPRINTF_HEAD(const char* color, const char* format, ...)

        Alias of CPRINTF_HEADER.

    CPRINTFLN_HEAD(const char* color, const char* format, ...)

        Alias of CPRINTFLN_HEADER.


    CPRINT_SUC(const char* color, const char* str)

        Alias of CPRINT_SUCCESS.

    CPRINTLN_SUC(const char* color, const char* str)

        Alias of CPRINTLN_SUCCESS.

    CPRINTF_SUC(const char* color, const char* format, ...)

        Alias of CPRINTF_SUCCESS.

    CPRINTFLN_SUC(const char* color, const char* format, ...)

        Alias of CPRINTFLN_SUCCESS.


    CPRINT_MON(const char* color, const char* str)

        Alias of CPRINT_MONEY.

    CPRINTLN_MON(const char* color, const char* str)

        Alias of CPRINTLN_MONEY.

    CPRINTF_MON(const char* color, const char* format, ...)

        Alias of CPRINTF_MONEY.

    CPRINTFLN_MON(const char* color, const char* format, ...)

        Alias of CPRINTFLN_MONEY.


    CPRINT_MNY(const char* color, const char* str)

        Alias of CPRINT_MONEY.

    CPRINTLN_MNY(const char* color, const char* str)

        Alias of CPRINTLN_MONEY.

    CPRINTF_MNY(const char* color, const char* format, ...)

        Alias of CPRINTF_MONEY.

    CPRINTFLN_MNY(const char* color, const char* format, ...)

        Alias of CPRINTFLN_MONEY.


    CPRINT_IN(const char* color, const char* str)

        Alias of CPRINT_INPUT.

    CPRINTLN_IN(const char* color, const char* str)

        Alias of CPRINTLN_INPUT.

    CPRINTF_IN(const char* color, const char* format, ...)

        Alias of CPRINTF_INPUT.

    CPRINTFLN_IN(const char* color, const char* format, ...)

        Alias of CPRINTFLN_INPUT.


    CPRINT_WARN(const char* color, const char* str)

        Alias of CPRINT_WARNING.

    CPRINTLN_WARN(const char* color, const char* str)

        Alias of CPRINTLN_WARNING.

    CPRINTF_WARN(const char* color, const char* format, ...)

        Alias of CPRINTF_WARNING.

    CPRINTFLN_WARN(const char* color, const char* format, ...)

        Alias of CPRINTFLN_WARNING.


    CPERROR_WARN(const char* color, const char* str)

        Alias of CPERROR_WARNING.

    CPERRORF_WARN(const char* color, const char* format, ...)

        Alias of CPERRORF_WARNING.


    CPRINT_ERR(const char* color, const char* str)

        Alias of CPRINT_ERROR.

    CPRINTLN_ERR(const char* color, const char* str)

        Alias of CPRINTLN_ERROR.

    CPRINTF_ERR(const char* color, const char* format, ...)

        Alias of CPRINTF_ERROR.

    CPRINTFLN_ERR(const char* color, const char* format, ...)

        Alias of CPRINTFLN_ERROR.


    CPERROR_ERR(const char* color, const char* str)

        Alias of CPERROR_ERROR.

    CPERRORF_ERR(const char* color, const char* format, ...)

        Alias of CPERRORF_ERROR.


    CPRINT_CRIT(const char* color, const char* str)

        Alias of CPRINT_CRITICAL.

    CPRINTLN_CRIT(const char* color, const char* str)

        Alias of CPRINTLN_CRITICAL.

    CPRINTF_CRIT(const char* color, const char* format, ...)

        Alias of CPRINTF_CRITICAL.

    CPRINTFLN_CRIT(const char* color, const char* format, ...)

        Alias of CPRINTFLN_CRITICAL.


    CPERROR_CRIT(const char* color, const char* str)

        Alias of CPERROR_CRITICAL.

    CPERRORF_CRIT(const char* color, const char* format, ...)

        Alias of CPERRORF_CRITICAL.


    CPRINT_FAT(const char* color, const char* str)

        Alias of CPRINT_FATAL.

    CPRINTLN_FAT(const char* color, const char* str)

        Alias of CPRINTLN_FATAL.

    CPRINTF_FAT(const char* color, const char* format, ...)

        Alias of CPRINTF_FATAL.

    CPRINTFLN_FAT(const char* color, const char* format, ...)

        Alias of CPRINTFLN_FATAL.


    CPERROR_FAT(const char* color, const char* str)

        Alias of CPERROR_FATAL.

    CPERRORF_FAT(const char* color, const char* format, ...)

        Alias of CPERRORF_FATAL.


### "cprint_level" Functions Shorter Aliases (if enabled)

    CPRINT_TR(const char* color, const char* str)

        Alias of CPRINT_TRACE.

    CPRINTLN_TR(const char* color, const char* str)

        Alias of CPRINTLN_TRACE.

    CPRINTF_TR(const char* color, const char* format, ...)

        Alias of CPRINTF_TRACE.

    CPRINTFLN_TR(const char* color, const char* format, ...)

        Alias of CPRINTFLN_TRACE.


    CPRINT_DB(const char* color, const char* str)

        Alias of CPRINT_DEBUG.

    CPRINTLN_DB(const char* color, const char* str)

        Alias of CPRINTLN_DEBUG.

    CPRINTF_DB(const char* color, const char* format, ...)

        Alias of CPRINTF_DEBUG.

    CPRINTFLN_DB(const char* color, const char* format, ...)

        Alias of CPRINTFLN_DEBUG.


    CPRINT_EX(const char* color, const char* str)

        Alias of CPRINT_EXTRA.

    CPRINTLN_EX(const char* color, const char* str)

        Alias of CPRINTLN_EXTRA.

    CPRINTF_EX(const char* color, const char* format, ...)

        Alias of CPRINTF_EXTRA.

    CPRINTFLN_EX(const char* color, const char* format, ...)

        Alias of CPRINTFLN_EXTRA.


    CPRINT_IF(const char* color, const char* str)

        Alias of CPRINT_INFO.

    CPRINTLN_IF(const char* color, const char* str)

        Alias of CPRINTLN_INFO.

    CPRINTF_IF(const char* color, const char* format, ...)

        Alias of CPRINTF_INFO.

    CPRINTFLN_IF(const char* color, const char* format, ...)

        Alias of CPRINTFLN_INFO.


    CPRINT_HD(const char* color, const char* str)

        Alias of CPRINT_HEADER.

    CPRINTLN_HD(const char* color, const char* str)

        Alias of CPRINTLN_HEADER.

    CPRINTF_HD(const char* color, const char* format, ...)

        Alias of CPRINTF_HEADER.

    CPRINTFLN_HD(const char* color, const char* format, ...)

        Alias of CPRINTFLN_HEADER.


    CPRINT_SC(const char* color, const char* str)

        Alias of CPRINT_SUCCESS.

    CPRINTLN_SC(const char* color, const char* str)

        Alias of CPRINTLN_SUCCESS.

    CPRINTF_SC(const char* color, const char* format, ...)

        Alias of CPRINTF_SUCCESS.

    CPRINTFLN_SC(const char* color, const char* format, ...)

        Alias of CPRINTFLN_SUCCESS.


    CPRINT_MN(const char* color, const char* str)

        Alias of CPRINT_MONEY.

    CPRINTLN_MN(const char* color, const char* str)

        Alias of CPRINTLN_MONEY.

    CPRINTF_MN(const char* color, const char* format, ...)

        Alias of CPRINTF_MONEY.

    CPRINTFLN_MN(const char* color, const char* format, ...)

        Alias of CPRINTFLN_MONEY.


    CPRINT_MY(const char* color, const char* str)

        Alias of CPRINT_MONEY.

    CPRINTLN_MY(const char* color, const char* str)

        Alias of CPRINTLN_MONEY.

    CPRINTF_MY(const char* color, const char* format, ...)

        Alias of CPRINTF_MONEY.

    CPRINTFLN_MY(const char* color, const char* format, ...)

        Alias of CPRINTFLN_MONEY.


    CPRINT_IN(const char* color, const char* str)

        Alias of CPRINT_INPUT.

    CPRINTLN_IN(const char* color, const char* str)

        Alias of CPRINTLN_INPUT.

    CPRINTF_IN(const char* color, const char* format, ...)

        Alias of CPRINTF_INPUT.

    CPRINTFLN_IN(const char* color, const char* format, ...)

        Alias of CPRINTFLN_INPUT.


    CPRINT_WN(const char* color, const char* str)

        Alias of CPRINT_WARNING.

    CPRINTLN_WN(const char* color, const char* str)

        Alias of CPRINTLN_WARNING.

    CPRINTF_WN(const char* color, const char* format, ...)

        Alias of CPRINTF_WARNING.

    CPRINTFLN_WN(const char* color, const char* format, ...)

        Alias of CPRINTFLN_WARNING.


    CPERROR_WN(const char* color, const char* str)

        Alias of CPERROR_WARNING.

    CPERRORF_WN(const char* color, const char* format, ...)

        Alias of CPERRORF_WARNING.


    CPRINT_ER(const char* color, const char* str)

        Alias of CPRINT_ERROR.

    CPRINTLN_ER(const char* color, const char* str)

        Alias of CPRINTLN_ERROR.

    CPRINTF_ER(const char* color, const char* format, ...)

        Alias of CPRINTF_ERROR.

    CPRINTFLN_ER(const char* color, const char* format, ...)

        Alias of CPRINTFLN_ERROR.


    CPERROR_ER(const char* color, const char* str)

        Alias of CPERROR_ERROR.

    CPERRORF_ER(const char* color, const char* format, ...)

        Alias of CPERRORF_ERROR.


    CPRINT_CR(const char* color, const char* str)

        Alias of CPRINT_CRITICAL.

    CPRINTLN_CR(const char* color, const char* str)

        Alias of CPRINTLN_CRITICAL.

    CPRINTF_CR(const char* color, const char* format, ...)

        Alias of CPRINTF_CRITICAL.

    CPRINTFLN_CR(const char* color, const char* format, ...)

        Alias of CPRINTFLN_CRITICAL.


    CPERROR_CR(const char* color, const char* str)

        Alias of CPERROR_CRITICAL.

    CPERRORF_CR(const char* color, const char* format, ...)

        Alias of CPERRORF_CRITICAL.


    CPRINT_FT(const char* color, const char* str)

        Alias of CPRINT_FATAL.

    CPRINTLN_FT(const char* color, const char* str)

        Alias of CPRINTLN_FATAL.

    CPRINTF_FT(const char* color, const char* format, ...)

        Alias of CPRINTF_FATAL.

    CPRINTFLN_FT(const char* color, const char* format, ...)

        Alias of CPRINTFLN_FATAL.


    CPERROR_FT(const char* color, const char* str)

        Alias of CPERROR_FATAL.

    CPERRORF_FT(const char* color, const char* format, ...)

        Alias of CPERRORF_FATAL.


Logging Functions
-----------------

### "clog" Functions

    CLOG(const char* str)

        Print timestamp and the given string to standard error.

    CLOGLN(const char* str)

        Print timestamp and the given string to standard error followed by
        a newline.

    CLOGF(const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error.

    CLOGFLN(const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error followed by a newline.

    CLOG_HEX(const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        to standard error.

    CLOGLN_HEX(const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        to standard error followed by a newline.

    CLOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error.

    CLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error followed by a newline.

    CLOG_PERROR(const char* str)

        Print timestamp and the given string to standard error and then
        print the C error message.

    CLOG_PERRORF(const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error followed by a C error message.


### "clog_stream" Functions

    CLOG_STREAM(const char* str)

        Print the given string to standard error.

    CLOGLN_STREAM(const char* str)

        Print the given string to standard error followed by a newline.

    CLOGF_STREAM(const char* format, ...)

        Print the given format string and format arguments to standard
        error.

    CLOGFLN_STREAM(const char* format, ...)

        Print the given format string and format arguments to standard
        error followed by a newline.

    CLOG_HEX_STREAM(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        error.

    CLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string to standard
        error followed by a newline.

    CLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error.

    CLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        followed by a newline.

    CLOG_PERROR_STREAM(const char* str)

        Print the given string to standard error and then print the C error
        message.

    CLOG_PERRORF_STREAM(const char* format, ...)

        Print the given format string and format arguments to standard
        error followed by a C error message.


### "ctlog" Functions

    CTLOG(const char* str)

        Print timestamp, tracing information, and the given string to
        standard error.

    CTLOGLN(const char* str)

        Print timestamp, tracing information, and the given string to
        standard error followed by a newline.

    CTLOGF(const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error.

    CTLOGFLN(const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error followed by a newline.

    CTLOG_HEX(const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error.

    CTLOGLN_HEX(const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error followed by a newline.

    CTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error.

    CTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error followed by a newline.

    CTLOG_PERROR(const char* str)

        Print timestamp, tracing information, and the given string to
        standard error and then print the C error message.

    CTLOG_PERRORF(const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error followed by a C error
        message.


### "cclog" Functions

    CCLOG(const char* color, const char* str)

        Print timestamp and the given string to standard error in the given
        color.

    CCLOGLN(const char* color, const char* str)

        Print timestamp and the given string to standard error followed by
        a newline in the given color.

    CCLOGF(const char* color, const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error in the given color.

    CCLOGFLN(const char* color, const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error followed by a newline in the given color.

    CCLOG_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        to standard error in the given color.

    CCLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        to standard error followed by a newline in the given color.

    CCLOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error in the given color.

    CCLOGLN_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error followed by a newline in the given color.

    CCLOG_PERROR(const char* color, const char* str)

        Print timestamp and the given string to standard error and then
        print the C error message in the given color.

    CCLOG_PERRORF(const char* color, const char* format, ...)

        Print timestamp and the given format string and format arguments to
        standard error followed by a C error message in the given color.


### "cclog_stream" Functions

    CCLOG_STREAM(const char* color, const char* str)

        Print the given string to standard error in the given color.

    CCLOGLN_STREAM(const char* color, const char* str)

        Print the given string to standard error followed by a newline in
        the given color.

    CCLOGF_STREAM(const char* color, const char* format, ...)

        Print the given format string and format arguments to standard
        error in the given color.

    CCLOGFLN_STREAM(const char* color, const char* format, ...)

        Print the given format string and format arguments to standard
        error followed by a newline in the given color.

    CCLOG_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string to standard
        error in the given color.

    CCLOGLN_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string to standard
        error followed by a newline in the given color.

    CCLOG_WIDE_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error in
        the given color.

    CCLOGLN_WIDE_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        followed by a newline in the given color.

    CCLOG_PERROR_STREAM(const char* color, const char* str)

        Print the given string to standard error and then print the C error
        message in the given color.

    CCLOG_PERRORF_STREAM(const char* color, const char* format, ...)

        Print the given format string and format arguments to standard
        error followed by a C error message in the given color.


### "cctlog" Functions

    CCTLOG(const char* color, const char* str)

        Print timestamp, tracing information, and the given string to
        standard error in the given color.

    CCTLOGLN(const char* color, const char* str)

        Print timestamp, tracing information, and the given string to
        standard error followed by a newline in the given color.

    CCTLOGF(const char* color, const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error in the given color.

    CCTLOGFLN(const char* color, const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error followed by a newline in the
        given color.

    CCTLOG_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error in the given color.

    CCTLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error followed by a newline in
        the given color.

    CCTLOG_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error in the given color.

    CCTLOGLN_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Print timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error followed by a newline in the
        given color.

    CCTLOG_PERROR(const char* color, const char* str)

        Print timestamp, tracing information, and the given string to
        standard error and then print the C error message in the given
        color.

    CCTLOG_PERRORF(const char* color, const char* format, ...)

        Print timestamp, tracing information, and the given format string
        and format arguments to standard error followed by a C error
        message in the given color.


### "clog_level" Functions

    CLOG_TRACE(const char* str)

        Print timestamp, tracing information, log level symbol, and the
        given string to standard error in the appropriate log color.

    CLOGLN_TRACE(const char* str)

        Print timestamp, tracing information, log level symbol, and the
        given string to standard error followed by a newline in the
        appropriate log color.

    CLOGF_TRACE(const char* format, ...)

        Print timestamp, tracing information, log level symbol, and the
        given format string and format arguments to standard error in the
        appropriate log color.

    CLOGFLN_TRACE(const char* format, ...)

        Print timestamp, tracing information, log level symbol, and the
        given format string and format arguments to standard error followed
        by a newline in the appropriate log color.


    CLOG_DEBUG(const char* str)

        Print timestamp, tracing information, log level symbol, and the
        given string to standard error in the appropriate log color.

    CLOGLN_DEBUG(const char* str)

        Print timestamp, tracing information, log level symbol, and the
        given string to standard error followed by a newline in the
        appropriate log color.

    CLOGF_DEBUG(const char* format, ...)

        Print timestamp, tracing information, log level symbol, and the
        given format string and format arguments to standard error in the
        appropriate log color.

    CLOGFLN_DEBUG(const char* format, ...)

        Print timestamp, tracing information, log level symbol, and the
        given format string and format arguments to standard error followed
        by a newline in the appropriate log color.


    CLOG_EXTRA(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_EXTRA(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_EXTRA(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_EXTRA(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_INFO(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_INFO(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_INFO(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_INFO(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_HEADER(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_HEADER(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_HEADER(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_HEADER(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_SUCCESS(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_SUCCESS(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_SUCCESS(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_SUCCESS(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_MONEY(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_MONEY(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_MONEY(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_MONEY(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_INPUT(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_INPUT(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_INPUT(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_INPUT(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.


    CLOG_WARNING(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_WARNING(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_WARNING(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_WARNING(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.

    CLOG_PERROR_WARNING(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error and then print the C error message in the appropriate log
        color.

    CLOG_PERRORF_WARNING(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a C error message in
        the appropriate log color.


    CLOG_ERROR(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_ERROR(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_ERROR(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_ERROR(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.

    CLOG_PERROR_ERROR(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error and then print the C error message in the appropriate log
        color.

    CLOG_PERRORF_ERROR(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a C error message in
        the appropriate log color.


    CLOG_CRITICAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_CRITICAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_CRITICAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_CRITICAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.

    CLOG_PERROR_CRITICAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error and then print the C error message in the appropriate log
        color.

    CLOG_PERRORF_CRITICAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a C error message in
        the appropriate log color.


    CLOG_FATAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error in the appropriate log color.

    CLOGLN_FATAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error followed by a newline in the appropriate log color.

    CLOGF_FATAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error in the appropriate log color.

    CLOGFLN_FATAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a newline in the
        appropriate log color.

    CLOG_PERROR_FATAL(const char* str)

        Print timestamp, log level symbol, and the given string to standard
        error and then print the C error message in the appropriate log
        color.

    CLOG_PERRORF_FATAL(const char* format, ...)

        Print timestamp, log level symbol, and the given format string and
        format arguments to standard error followed by a C error message in
        the appropriate log color.


### "clog_level" Functions Short Aliases (if enabled)

    CLOG_TRC(const char* str);

        Alias of `CLOG_TRACE` function.

    CLOGLN_TRC(const char* str);

        Alias of `CLOGLN_TRACE` function.

    CLOGF_TRC(const char* format, ...);

        Alias of `CLOGF_TRACE` function.

    CLOGFLN_TRC(const char* format, ...);

        Alias of `CLOGFLN_TRACE` function.


    CLOG_DBG(const char* str);

        Alias of `CLOG_DEBUG` function.

    CLOGLN_DBG(const char* str);

        Alias of `CLOGLN_DEBUG` function.

    CLOGF_DBG(const char* format, ...);

        Alias of `CLOGF_DEBUG` function.

    CLOGFLN_DBG(const char* format, ...);

        Alias of `CLOGFLN_DEBUG` function.


    CLOG_EXT(const char* str);

        Alias of `CLOG_EXTRA` function.

    CLOGLN_EXT(const char* str);

        Alias of `CLOGLN_EXTRA` function.

    CLOGF_EXT(const char* format, ...);

        Alias of `CLOGF_EXTRA` function.

    CLOGFLN_EXT(const char* format, ...);

        Alias of `CLOGFLN_EXTRA` function.


    CLOG_INF(const char* str);

        Alias of `CLOG_INFO` function.

    CLOGLN_INF(const char* str);

        Alias of `CLOGLN_INFO` function.

    CLOGF_INF(const char* format, ...);

        Alias of `CLOGF_INFO` function.

    CLOGFLN_INF(const char* format, ...);

        Alias of `CLOGFLN_INFO` function.


    CLOG_HEAD(const char* str);

        Alias of `CLOG_HEADER` function.

    CLOGLN_HEAD(const char* str);

        Alias of `CLOG_TRACE` function.

    CLOGF_HEAD(const char* format, ...);

        Alias of `CLOGF_HEADER` function.

    CLOGFLN_HEAD(const char* format, ...);

        Alias of `CLOGFLN_HEADER` function.


    CLOG_SUC(const char* str);

        Alias of `CLOG_SUCCESS` function.

    CLOGLN_SUC(const char* str);

        Alias of `CLOGLN_SUCCESS` function.

    CLOGF_SUC(const char* format, ...);

        Alias of `CLOGF_SUCCESS` function.

    CLOGFLN_SUC(const char* format, ...);

        Alias of `CLOGFLN_SUCCESS` function.


    CLOG_MON(const char* str);

        Alias of `CLOG_MONEY` function.

    CLOGLN_MON(const char* str);

        Alias of `CLOGLN_MONEY` function.

    CLOGF_MON(const char* format, ...);

        Alias of `CLOGF_MONEY` function.

    CLOGFLN_MON(const char* format, ...);

        Alias of `CLOGFLN_MONEY` function.


    CLOG_MNY(const char* str);

        Alias of `CLOG_MONEY` function.

    CLOGLN_MNY(const char* str);

        Alias of `CLOGLN_MONEY` function.

    CLOGF_MNY(const char* format, ...);

        Alias of `CLOGF_MONEY` function.

    CLOGFLN_MNY(const char* format, ...);

        Alias of `CLOGFLN_MONEY` function.


    CLOG_IN(const char* str);

        Alias of `CLOG_INPUT` function.

    CLOGLN_IN(const char* str);

        Alias of `CLOGLN_INPUT` function.

    CLOGF_IN(const char* format, ...);

        Alias of `CLOGF_INPUT` function.

    CLOGFLN_IN(const char* format, ...);

        Alias of `CLOGFLN_INPUT` function.


    CLOG_WARN(const char* str);

        Alias of `CLOG_WARNING` function.

    CLOGLN_WARN(const char* str);

        Alias of `CLOGLN_WARNING` function.

    CLOGF_WARN(const char* format, ...);

        Alias of `CLOGF_WARNING` function.

    CLOGFLN_WARN(const char* format, ...);

        Alias of `CLOGFLN_WARNING` function.

    CLOG_PERROR_WARN(const char* str);

        Alias of `CLOG_PERROR_WARNING` function.

    CLOG_PERRORF_WARN(const char* format, ...);

        Alias of `CLOG_PERRORF_WARNING` function.


    CLOG_ERR(const char* str);

        Alias of `CLOG_ERROR` function.

    CLOGLN_ERR(const char* str);

        Alias of `CLOGLN_ERROR` function.

    CLOGF_ERR(const char* format, ...);

        Alias of `CLOGF_ERROR` function.

    CLOGFLN_ERR(const char* format, ...);

        Alias of `CLOGFLN_ERROR` function.

    CLOG_PERROR_ERR(const char* str);

        Alias of `CLOG_PERROR_ERROR` function.

    CLOG_PERRORF_ERR(const char* format, ...);

        Alias of `CLOG_PERRORF_ERROR` function.


    CLOG_CRIT(const char* str);

        Alias of `CLOG_CRITICAL` function.

    CLOGLN_CRIT(const char* str);

        Alias of `CLOGLN_CRITICAL` function.

    CLOGF_CRIT(const char* format, ...);

        Alias of `CLOGF_CRITICAL` function.

    CLOGFLN_CRIT(const char* format, ...);

        Alias of `CLOGFLN_CRITICAL` function.

    CLOG_PERROR_CRIT(const char* str);

        Alias of `CLOG_PERROR_CRITICAL` function.

    CLOG_PERRORF_CRIT(const char* format, ...);

        Alias of `CLOG_PERRORF_CRITICAL` function.


    CLOG_FAT(const char* str);

        Alias of `CLOG_FATAL` function.

    CLOGLN_FAT(const char* str);

        Alias of `CLOGLN_FATAL` function.

    CLOGF_FAT(const char* format, ...);

        Alias of `CLOGF_FATAL` function.

    CLOGFLN_FAT(const char* format, ...);

        Alias of `CLOGFLN_FATAL` function.

    CLOG_PERROR_FAT(const char* str);

        Alias of `CLOG_PERROR_FATAL` function.

    CLOG_PERRORF_FAT(const char* format, ...);

        Alias of `CLOG_PERRORF_FATAL` function.


### "clog_level" Functions Shorter Aliases (if enabled)

    CLOG_TR(const char* str);

        Alias of `CLOG_TRACE` function.

    CLOGLN_TR(const char* str);

        Alias of `CLOGLN_TRACE` function.

    CLOGF_TR(const char* format, ...);

        Alias of `CLOGF_TRACE` function.

    CLOGFLN_TR(const char* format, ...);

        Alias of `CLOGFLN_TRACE` function.


    CLOG_DB(const char* str);

        Alias of `CLOG_DEBUG` function.

    CLOGLN_DB(const char* str);

        Alias of `CLOGLN_DEBUG` function.

    CLOGF_DB(const char* format, ...);

        Alias of `CLOGF_DEBUG` function.

    CLOGFLN_DB(const char* format, ...);

        Alias of `CLOGFLN_DEBUG` function.


    CLOG_EX(const char* str);

        Alias of `CLOG_EXTRA` function.

    CLOGLN_EX(const char* str);

        Alias of `CLOGLN_EXTRA` function.

    CLOGF_EX(const char* format, ...);

        Alias of `CLOGF_EXTRA` function.

    CLOGFLN_EX(const char* format, ...);

        Alias of `CLOGFLN_EXTRA` function.


    CLOG_IF(const char* str);

        Alias of `CLOG_INFO` function.

    CLOGLN_IF(const char* str);

        Alias of `CLOGLN_INFO` function.

    CLOGF_IF(const char* format, ...);

        Alias of `CLOGF_INFO` function.

    CLOGFLN_IF(const char* format, ...);

        Alias of `CLOGFLN_INFO` function.


    CLOG_HD(const char* str);

        Alias of `CLOG_HEADER` function.

    CLOGLN_HD(const char* str);

        Alias of `CLOG_TRACE` function.

    CLOGF_HD(const char* format, ...);

        Alias of `CLOGF_HEADER` function.

    CLOGFLN_HD(const char* format, ...);

        Alias of `CLOGFLN_HEADER` function.


    CLOG_SC(const char* str);

        Alias of `CLOG_SUCCESS` function.

    CLOGLN_SC(const char* str);

        Alias of `CLOGLN_SUCCESS` function.

    CLOGF_SC(const char* format, ...);

        Alias of `CLOGF_SUCCESS` function.

    CLOGFLN_SC(const char* format, ...);

        Alias of `CLOGFLN_SUCCESS` function.


    CLOG_MN(const char* str);

        Alias of `CLOG_MONEY` function.

    CLOGLN_MN(const char* str);

        Alias of `CLOGLN_MONEY` function.

    CLOGF_MN(const char* format, ...);

        Alias of `CLOGF_MONEY` function.

    CLOGFLN_MN(const char* format, ...);

        Alias of `CLOGFLN_MONEY` function.


    CLOG_MY(const char* str);

        Alias of `CLOG_MONEY` function.

    CLOGLN_MY(const char* str);

        Alias of `CLOGLN_MONEY` function.

    CLOGF_MY(const char* format, ...);

        Alias of `CLOGF_MONEY` function.

    CLOGFLN_MY(const char* format, ...);

        Alias of `CLOGFLN_MONEY` function.


    CLOG_IN(const char* str);

        Alias of `CLOG_INPUT` function.

    CLOGLN_IN(const char* str);

        Alias of `CLOGLN_INPUT` function.

    CLOGF_IN(const char* format, ...);

        Alias of `CLOGF_INPUT` function.

    CLOGFLN_IN(const char* format, ...);

        Alias of `CLOGFLN_INPUT` function.


    CLOG_WN(const char* str);

        Alias of `CLOG_WARNING` function.

    CLOGLN_WN(const char* str);

        Alias of `CLOGLN_WARNING` function.

    CLOGF_WN(const char* format, ...);

        Alias of `CLOGF_WARNING` function.

    CLOGFLN_WN(const char* format, ...);

        Alias of `CLOGFLN_WARNING` function.

    CLOG_PERROR_WN(const char* str);

        Alias of `CLOG_PERROR_WARNING` function.

    CLOG_PERRORF_WN(const char* format, ...);

        Alias of `CLOG_PERRORF_WARNING` function.


    CLOG_ER(const char* str);

        Alias of `CLOG_ERROR` function.

    CLOGLN_ER(const char* str);

        Alias of `CLOGLN_ERROR` function.

    CLOGF_ER(const char* format, ...);

        Alias of `CLOGF_ERROR` function.

    CLOGFLN_ER(const char* format, ...);

        Alias of `CLOGFLN_ERROR` function.

    CLOG_PERROR_ER(const char* str);

        Alias of `CLOG_PERROR_ERROR` function.

    CLOG_PERRORF_ER(const char* format, ...);

        Alias of `CLOG_PERRORF_ERROR` function.


    CLOG_CR(const char* str);

        Alias of `CLOG_CRITICAL` function.

    CLOGLN_CR(const char* str);

        Alias of `CLOGLN_CRITICAL` function.

    CLOGF_CR(const char* format, ...);

        Alias of `CLOGF_CRITICAL` function.

    CLOGFLN_CR(const char* format, ...);

        Alias of `CLOGFLN_CRITICAL` function.

    CLOG_PERROR_CR(const char* str);

        Alias of `CLOG_PERROR_CRITICAL` function.

    CLOG_PERRORF_CR(const char* format, ...);

        Alias of `CLOG_PERRORF_CRITICAL` function.


    CLOG_FT(const char* str);

        Alias of `CLOG_FATAL` function.

    CLOGLN_FT(const char* str);

        Alias of `CLOGLN_FATAL` function.

    CLOGF_FT(const char* format, ...);

        Alias of `CLOGF_FATAL` function.

    CLOGFLN_FT(const char* format, ...);

        Alias of `CLOGFLN_FATAL` function.

    CLOG_PERROR_FT(const char* str);

        Alias of `CLOG_PERROR_FATAL` function.

    CLOG_PERRORF_FT(const char* format, ...);

        Alias of `CLOG_PERRORF_FATAL` function.


### "flog" Functions

    FLOG(const char* str)

        Log timestamp and the given string to a log file.

    FLOGLN(const char* str)

        Log timestamp and the given string to a log file followed by a
        newline.

    FLOGF(const char* format, ...)

        Log timestamp and the given format string and format arguments to a
        log file.

    FLOGFLN(const char* format, ...)

        Log timestamp and the given format string and format arguments to a
        log file followed by a newline.

    FLOG_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        a log file.

    FLOGLN_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        a log file followed by a newline.

    FLOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to a
        log file.

    FLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to a
        log file followed by a newline.

    FLOG_PERROR(const char* str)

        Log timestamp and the given string to a log file and then print the
        C error message.

    FLOG_PERRORF(const char* format, ...)

        Log timestamp and the given format string and format arguments to a
        log file followed by a C error message.


### "flog_stream" Functions

    FLOG_STREAM(const char* str)

        Log the given string to a log file.

    FLOGLN_STREAM(const char* str)

        Log the given string to a log file followed by a newline.

    FLOGF_STREAM(const char* format, ...)

        Log the given format string and format arguments to a log file.

    FLOGFLN_STREAM(const char* format, ...)

        Log the given format string and format arguments to a log file
        followed by a newline.

    FLOG_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string to a log file.

    FLOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string to a log file
        followed by a newline.

    FLOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to a log file.

    FLOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to a log file
        followed by a newline.

    FLOG_PERROR_STREAM(const char* str)

        Log the given string to a log file and then print the C error
        message.

    FLOG_PERRORF_STREAM(const char* format, ...)

        Log the given format string and format arguments to a log file
        followed by a C error message.


### "ftlog" Functions

    FTLOG(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error.

    FTLOGLN(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error.

    FTLOGF(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to a log file.

    FTLOGFLN(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to a log file followed by a newline.

    FTLOG_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to a log file.

    FTLOGLN_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to a log file followed by a newline.

    FTLOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to a log file.

    FTLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to a log file followed by a newline.

    FTLOG_PERROR(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and then print the C error message.

    FTLOG_PERRORF(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to a log file followed by a C error message.


### "flog_level" Functions

    FLOG_TRACE(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to a log file.

    FLOGLN_TRACE(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to a log file followed by a newline.

    FLOGF_TRACE(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to a log file.

    FLOGFLN_TRACE(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to a log file followed by a
        newline.

    FLOG_DEBUG(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to a log file.

    FLOGLN_DEBUG(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to a log file followed by a newline.

    FLOGF_DEBUG(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to a log file.

    FLOGFLN_DEBUG(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to a log file followed by a
        newline.


    FLOG_EXTRA(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_EXTRA(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_EXTRA(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_EXTRA(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_INFO(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_INFO(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_INFO(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_INFO(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_HEADER(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_HEADER(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_HEADER(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_HEADER(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_SUCCESS(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_SUCCESS(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_SUCCESS(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_SUCCESS(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_MONEY(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_MONEY(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_MONEY(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_MONEY(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_INPUT(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_INPUT(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_INPUT(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_INPUT(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.


    FLOG_WARNING(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_WARNING(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_WARNING(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_WARNING(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.

    FLOG_PERROR_WARNING(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        and then print the C error message.

    FLOG_PERRORF_WARNING(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a C error message.


    FLOG_ERROR(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_ERROR(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_ERROR(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_ERROR(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.

    FLOG_PERROR_ERROR(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        and then print the C error message.

    FLOG_PERRORF_ERROR(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a C error message.


    FLOG_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.

    FLOG_PERROR_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        and then print the C error message.

    FLOG_PERRORF_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a C error message.


    FLOG_FATAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log
        file.

    FLOGLN_FATAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        followed by a newline.

    FLOGF_FATAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file.

    FLOGFLN_FATAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a newline.

    FLOG_PERROR_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to a log file
        and then print the C error message.

    FLOG_PERRORF_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to a log file followed by a C error message.


### "flog_level" Functions Short Aliases (if enabled)

    FLOG_TRC(const char* str);

        Alias of `FLOG_TRACE` function.

    FLOGLN_TRC(const char* str);

        Alias of `FLOGLN_TRACE` function.

    FLOGF_TRC(const char* format, ...);

        Alias of `FLOGF_TRACE` function.

    FLOGFLN_TRC(const char* format, ...);

        Alias of `FLOGFLN_TRACE` function.


    FLOG_DBG(const char* str);

        Alias of `FLOG_DEBUG` function.

    FLOGLN_DBG(const char* str);

        Alias of `FLOGLN_DEBUG` function.

    FLOGF_DBG(const char* format, ...);

        Alias of `FLOGF_DEBUG` function.

    FLOGFLN_DBG(const char* format, ...);

        Alias of `FLOGFLN_DEBUG` function.


    FLOG_EXT(const char* str);

        Alias of `FLOG_EXTRA` function.

    FLOGLN_EXT(const char* str);

        Alias of `FLOGLN_EXTRA` function.

    FLOGF_EXT(const char* format, ...);

        Alias of `FLOGF_EXTRA` function.

    FLOGFLN_EXT(const char* format, ...);

        Alias of `FLOGFLN_EXTRA` function.


    FLOG_INF(const char* str);

        Alias of `FLOG_INFO` function.

    FLOGLN_INF(const char* str);

        Alias of `FLOGLN_INFO` function.

    FLOGF_INF(const char* format, ...);

        Alias of `FLOGF_INFO` function.

    FLOGFLN_INF(const char* format, ...);

        Alias of `FLOGFLN_INFO` function.


    FLOG_HEAD(const char* str);

        Alias of `FLOG_HEADER` function.

    FLOGLN_HEAD(const char* str);

        Alias of `FLOG_TRACE` function.

    FLOGF_HEAD(const char* format, ...);

        Alias of `FLOGF_HEADER` function.

    FLOGFLN_HEAD(const char* format, ...);

        Alias of `FLOGFLN_HEADER` function.


    FLOG_SUC(const char* str);

        Alias of `FLOG_SUCCESS` function.

    FLOGLN_SUC(const char* str);

        Alias of `FLOGLN_SUCCESS` function.

    FLOGF_SUC(const char* format, ...);

        Alias of `FLOGF_SUCCESS` function.

    FLOGFLN_SUC(const char* format, ...);

        Alias of `FLOGFLN_SUCCESS` function.


    FLOG_MON(const char* str);

        Alias of `FLOG_MONEY` function.

    FLOGLN_MON(const char* str);

        Alias of `FLOGLN_MONEY` function.

    FLOGF_MON(const char* format, ...);

        Alias of `FLOGF_MONEY` function.

    FLOGFLN_MON(const char* format, ...);

        Alias of `FLOGFLN_MONEY` function.


    FLOG_MNY(const char* str);

        Alias of `FLOG_MONEY` function.

    FLOGLN_MNY(const char* str);

        Alias of `FLOGLN_MONEY` function.

    FLOGF_MNY(const char* format, ...);

        Alias of `FLOGF_MONEY` function.

    FLOGFLN_MNY(const char* format, ...);

        Alias of `FLOGFLN_MONEY` function.


    FLOG_IN(const char* str);

        Alias of `FLOG_INPUT` function.

    FLOGLN_IN(const char* str);

        Alias of `FLOGLN_INPUT` function.

    FLOGF_IN(const char* format, ...);

        Alias of `FLOGF_INPUT` function.

    FLOGFLN_IN(const char* format, ...);

        Alias of `FLOGFLN_INPUT` function.


    FLOG_WARN(const char* str);

        Alias of `FLOG_WARNING` function.

    FLOGLN_WARN(const char* str);

        Alias of `FLOGLN_WARNING` function.

    FLOGF_WARN(const char* format, ...);

        Alias of `FLOGF_WARNING` function.

    FLOGFLN_WARN(const char* format, ...);

        Alias of `FLOGFLN_WARNING` function.

    FLOG_PERROR_WARN(const char* str);

        Alias of `FLOG_PERROR_WARNING` function.

    FLOG_PERRORF_WARN(const char* format, ...);

        Alias of `FLOG_PERRORF_WARNING` function.


    FLOG_ERR(const char* str);

        Alias of `FLOG_ERROR` function.

    FLOGLN_ERR(const char* str);

        Alias of `FLOGLN_ERROR` function.

    FLOGF_ERR(const char* format, ...);

        Alias of `FLOGF_ERROR` function.

    FLOGFLN_ERR(const char* format, ...);

        Alias of `FLOGFLN_ERROR` function.

    FLOG_PERROR_ERR(const char* str);

        Alias of `FLOG_PERROR_ERROR` function.

    FLOG_PERRORF_ERR(const char* format, ...);

        Alias of `FLOG_PERRORF_ERROR` function.


    FLOG_CRIT(const char* str);

        Alias of `FLOG_CRITICAL` function.

    FLOGLN_CRIT(const char* str);

        Alias of `FLOGLN_CRITICAL` function.

    FLOGF_CRIT(const char* format, ...);

        Alias of `FLOGF_CRITICAL` function.

    FLOGFLN_CRIT(const char* format, ...);

        Alias of `FLOGFLN_CRITICAL` function.

    FLOG_PERROR_CRIT(const char* str);

        Alias of `FLOG_PERROR_CRITICAL` function.

    FLOG_PERRORF_CRIT(const char* format, ...);

        Alias of `FLOG_PERRORF_CRITICAL` function.


    FLOG_FAT(const char* str);

        Alias of `FLOG_FATAL` function.

    FLOGLN_FAT(const char* str);

        Alias of `FLOGLN_FATAL` function.

    FLOGF_FAT(const char* format, ...);

        Alias of `FLOGF_FATAL` function.

    FLOGFLN_FAT(const char* format, ...);

        Alias of `FLOGFLN_FATAL` function.

    FLOG_PERROR_FAT(const char* str);

        Alias of `FLOG_PERROR_FATAL` function.

    FLOG_PERRORF_FAT(const char* format, ...);

        Alias of `FLOG_PERRORF_FATAL` function.


### "flog_level" Functions Shorter Aliases (if enabled)

    FLOG_TR(const char* str);

        Alias of `FLOG_TRACE` function.

    FLOGLN_TR(const char* str);

        Alias of `FLOGLN_TRACE` function.

    FLOGF_TR(const char* format, ...);

        Alias of `FLOGF_TRACE` function.

    FLOGFLN_TR(const char* format, ...);

        Alias of `FLOGFLN_TRACE` function.


    FLOG_DB(const char* str);

        Alias of `FLOG_DEBUG` function.

    FLOGLN_DB(const char* str);

        Alias of `FLOGLN_DEBUG` function.

    FLOGF_DB(const char* format, ...);

        Alias of `FLOGF_DEBUG` function.

    FLOGFLN_DB(const char* format, ...);

        Alias of `FLOGFLN_DEBUG` function.


    FLOG_EX(const char* str);

        Alias of `FLOG_EXTRA` function.

    FLOGLN_EX(const char* str);

        Alias of `FLOGLN_EXTRA` function.

    FLOGF_EX(const char* format, ...);

        Alias of `FLOGF_EXTRA` function.

    FLOGFLN_EX(const char* format, ...);

        Alias of `FLOGFLN_EXTRA` function.


    FLOG_IF(const char* str);

        Alias of `FLOG_INFO` function.

    FLOGLN_IF(const char* str);

        Alias of `FLOGLN_INFO` function.

    FLOGF_IF(const char* format, ...);

        Alias of `FLOGF_INFO` function.

    FLOGFLN_IF(const char* format, ...);

        Alias of `FLOGFLN_INFO` function.


    FLOG_HD(const char* str);

        Alias of `FLOG_HEADER` function.

    FLOGLN_HD(const char* str);

        Alias of `FLOG_TRACE` function.

    FLOGF_HD(const char* format, ...);

        Alias of `FLOGF_HEADER` function.

    FLOGFLN_HD(const char* format, ...);

        Alias of `FLOGFLN_HEADER` function.


    FLOG_SC(const char* str);

        Alias of `FLOG_SUCCESS` function.

    FLOGLN_SC(const char* str);

        Alias of `FLOGLN_SUCCESS` function.

    FLOGF_SC(const char* format, ...);

        Alias of `FLOGF_SUCCESS` function.

    FLOGFLN_SC(const char* format, ...);

        Alias of `FLOGFLN_SUCCESS` function.


    FLOG_MN(const char* str);

        Alias of `FLOG_MONEY` function.

    FLOGLN_MN(const char* str);

        Alias of `FLOGLN_MONEY` function.

    FLOGF_MN(const char* format, ...);

        Alias of `FLOGF_MONEY` function.

    FLOGFLN_MN(const char* format, ...);

        Alias of `FLOGFLN_MONEY` function.


    FLOG_MY(const char* str);

        Alias of `FLOG_MONEY` function.

    FLOGLN_MY(const char* str);

        Alias of `FLOGLN_MONEY` function.

    FLOGF_MY(const char* format, ...);

        Alias of `FLOGF_MONEY` function.

    FLOGFLN_MY(const char* format, ...);

        Alias of `FLOGFLN_MONEY` function.


    FLOG_IN(const char* str);

        Alias of `FLOG_INPUT` function.

    FLOGLN_IN(const char* str);

        Alias of `FLOGLN_INPUT` function.

    FLOGF_IN(const char* format, ...);

        Alias of `FLOGF_INPUT` function.

    FLOGFLN_IN(const char* format, ...);

        Alias of `FLOGFLN_INPUT` function.


    FLOG_WN(const char* str);

        Alias of `FLOG_WARNING` function.

    FLOGLN_WN(const char* str);

        Alias of `FLOGLN_WARNING` function.

    FLOGF_WN(const char* format, ...);

        Alias of `FLOGF_WARNING` function.

    FLOGFLN_WN(const char* format, ...);

        Alias of `FLOGFLN_WARNING` function.

    FLOG_PERROR_WN(const char* str);

        Alias of `FLOG_PERROR_WARNING` function.

    FLOG_PERRORF_WN(const char* format, ...);

        Alias of `FLOG_PERRORF_WARNING` function.


    FLOG_ER(const char* str);

        Alias of `FLOG_ERROR` function.

    FLOGLN_ER(const char* str);

        Alias of `FLOGLN_ERROR` function.

    FLOGF_ER(const char* format, ...);

        Alias of `FLOGF_ERROR` function.

    FLOGFLN_ER(const char* format, ...);

        Alias of `FLOGFLN_ERROR` function.

    FLOG_PERROR_ER(const char* str);

        Alias of `FLOG_PERROR_ERROR` function.

    FLOG_PERRORF_ER(const char* format, ...);

        Alias of `FLOG_PERRORF_ERROR` function.


    FLOG_CR(const char* str);

        Alias of `FLOG_CRITICAL` function.

    FLOGLN_CR(const char* str);

        Alias of `FLOGLN_CRITICAL` function.

    FLOGF_CR(const char* format, ...);

        Alias of `FLOGF_CRITICAL` function.

    FLOGFLN_CR(const char* format, ...);

        Alias of `FLOGFLN_CRITICAL` function.

    FLOG_PERROR_CR(const char* str);

        Alias of `FLOG_PERROR_CRITICAL` function.

    FLOG_PERRORF_CR(const char* format, ...);

        Alias of `FLOG_PERRORF_CRITICAL` function.


    FLOG_FT(const char* str);

        Alias of `FLOG_FATAL` function.

    FLOGLN_FT(const char* str);

        Alias of `FLOGLN_FATAL` function.

    FLOGF_FT(const char* format, ...);

        Alias of `FLOGF_FATAL` function.

    FLOGFLN_FT(const char* format, ...);

        Alias of `FLOGFLN_FATAL` function.

    FLOG_PERROR_FT(const char* str);

        Alias of `FLOG_PERROR_FATAL` function.

    FLOG_PERRORF_FT(const char* format, ...);

        Alias of `FLOG_PERRORF_FATAL` function.


### "log" Functions

    LOG(const char* str)

        Log timestamp and the given string to standard error and/or a file.

    LOGLN(const char* str)

        Log timestamp and the given string to standard error and/or a file
        followed by a newline.

    LOGF(const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file.

    LOGFLN(const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file followed by a newline.

    LOG_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        standard error and/or a file.

    LOGLN_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        standard error and/or a file followed by a newline.

    LOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error and/or a file.

    LOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error and/or a file followed by a newline.

    LOG_PERROR(const char* str)

        Log timestamp and the given string to standard error and/or a file
        and then print the C error message.

    LOG_PERRORF(const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file followed by a C error message.


### "log_stream" Functions

    LOG_STREAM(const char* str)

        Log the given string to standard error and/or a file.

    LOGLN_STREAM(const char* str)

        Log the given string to standard error and/or a file followed by a
        newline.

    LOGF_STREAM(const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file.

    LOGFLN_STREAM(const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file followed by a newline.

    LOG_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string to standard error
        and/or a file.

    LOGLN_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string to standard error
        and/or a file followed by a newline.

    LOG_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        and/or a file.

    LOGLN_WIDE_HEX_STREAM(const uint8_t* buffer, size_t length)

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        and/or a file followed by a newline.

    LOG_PERROR_STREAM(const char* str)

        Log the given string to standard error and/or a file and then print
        the C error message.

    LOG_PERRORF_STREAM(const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file followed by a C error message.


### "tlog" Functions

    TLOG(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file.

    TLOGLN(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file followed by a newline.

    TLOGF(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file.

    TLOGFLN(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file followed by a
        newline.

    TLOG_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error and/or a file.

    TLOGLN_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error and/or a file followed by
        a newline.

    TLOG_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error and/or a file.

    TLOGLN_WIDE_HEX(const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error and/or a file followed by a
        newline.

    TLOG_PERROR(const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file and then print the C error message.

    TLOG_PERRORF(const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message.


### "c_log" Functions

    C_LOG(const char* color, const char* str)

        Log timestamp and the given string to standard error and/or a file
        in the given color (for console logs).

    C_LOGLN(const char* color, const char* str)

        Log timestamp and the given string to standard error and/or a file
        followed by a newline in the given color (for console logs).

    C_LOGF(const char* color, const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file in the given color (for console logs).

    C_LOGFLN(const char* color, const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file followed by a newline in the given
        color (for console logs).

    C_LOG_HEX(const char* color, const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        standard error and/or a file in the given color (for console logs).

    C_LOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string to
        standard error and/or a file followed by a newline in the given
        color (for console logs).

    C_LOG_WIDE_HEX(const char* color, const uint8_t* buffer, size_t length)

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error and/or a file in the given color (for console logs).

    C_LOGLN_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log timestamp and the bytes of the given buffer as a hex string
        with preceding "0x" before each byte and delimited by spaces to
        standard error and/or a file followed by a newline in the given
        color (for console logs).

    C_LOG_PERROR(const char* color, const char* str)

        Log timestamp and the given string to standard error and/or a file
        and then print the C error message in the given color (for console
        logs).

    C_LOG_PERRORF(const char* color, const char* format, ...)

        Log timestamp and the given format string and format arguments to
        standard error and/or a file followed by a C error message in the
        given color (for console logs).


### "c_log_stream" Functions

    C_LOG_STREAM(const char* color, const char* str)

        Log the given string to standard error and/or a file in the given
        color (for console logs).

    C_LOGLN_STREAM(const char* color, const char* str)

        Log the given string to standard error and/or a file followed by a
        newline in the given color (for console logs).

    C_LOGF_STREAM(const char* color, const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file in the given color (for console logs).

    C_LOGFLN_STREAM(const char* color, const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file followed by a newline in the given color (for console
        logs).

    C_LOG_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log the bytes of the given buffer as a hex string to standard error
        and/or a file in the given color (for console logs).

    C_LOGLN_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log the bytes of the given buffer as a hex string to standard error
        and/or a file followed by a newline in the given color (for console
        logs).

    C_LOG_WIDE_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        and/or a file in the given color (for console logs).

    C_LOGLN_WIDE_HEX_STREAM(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log the bytes of the given buffer as a hex string with preceding
        "0x" before each byte and delimited by spaces to standard error
        and/or a file followed by a newline in the given color (for console
        logs).

    C_LOG_PERROR_STREAM(const char* color, const char* str)

        Log the given string to standard error and/or a file and then print
        the C error message in the given color (for console logs).

    C_LOG_PERRORF_STREAM(const char* color, const char* format, ...)

        Log the given format string and format arguments to standard error
        and/or a file followed by a C error message in the given color (for
        console logs).


### "c_tlog" Functions

    C_TLOG(const char* color, const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file in the given color (for console logs).

    C_TLOGLN(const char* color, const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file followed by a newline in the given
        color (for console logs).

    C_TLOGF(const char* color, const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file in the given color
        (for console logs).

    C_TLOGFLN(const char* color, const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file followed by a
        newline in the given color (for console logs).

    C_TLOG_HEX(const char* color, const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error and/or a file in the given
        color (for console logs).

    C_TLOGLN_HEX(const char* color, const uint8_t* buffer, size_t length)

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string to standard error and/or a file followed by
        a newline in the given color (for console logs).

    C_TLOG_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error and/or a file in the given
        color (for console logs).

    C_TLOGLN_WIDE_HEX(
        const char* color, const uint8_t* buffer, size_t length
    )

        Log timestamp, tracing information, and the bytes of the given
        buffer as a hex string with preceding "0x" before each byte and
        delimited by spaces to standard error and/or a file followed by a
        newline in the given color (for console logs).

    C_TLOG_PERROR(const char* color, const char* str)

        Log timestamp, tracing information, and the given string to
        standard error and/or a file and then print the C error message in
        the given color (for console logs).

    C_TLOG_PERRORF(const char* color, const char* format, ...)

        Log timestamp, tracing information, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message in the given color (for console logs).


### "log_level" Functions

    LOG_TRACE(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_TRACE(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_TRACE(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_TRACE(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_DEBUG(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_DEBUG(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_DEBUG(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_DEBUG(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_EXTRA(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_EXTRA(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_EXTRA(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_EXTRA(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_INFO(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_INFO(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_INFO(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_INFO(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_HEADER(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_HEADER(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_HEADER(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_HEADER(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_SUCCESS(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_SUCCESS(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_SUCCESS(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_SUCCESS(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_MONEY(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_MONEY(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_MONEY(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_MONEY(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_INPUT(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_INPUT(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_INPUT(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_INPUT(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.


    LOG_WARNING(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_WARNING(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_WARNING(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_WARNING(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.

    LOG_PERROR_WARNING(const char* str)

        Log timestamp, log level symbol, and the given string to standard
        error and/or a file and then print the C error message in the
        appropriate log color.

    LOG_PERRORF_WARNING(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message in the appropriate log color.


    LOG_ERROR(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_ERROR(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_ERROR(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_ERROR(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.

    LOG_PERROR_ERROR(const char* str)

        Log timestamp, log level symbol, and the given string to standard
        error and/or a file and then print the C error message in the
        appropriate log color.

    LOG_PERRORF_ERROR(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message in the appropriate log color.


    LOG_CRITICAL(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_CRITICAL(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_CRITICAL(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_CRITICAL(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.

    LOG_PERROR_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to standard
        error and/or a file and then print the C error message in the
        appropriate log color.

    LOG_PERRORF_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message in the appropriate log color.


    LOG_FATAL(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file in the appropriate log
        color.

    LOGLN_FATAL(const char* str)

        Log timestamp, tracing information, log level symbol, and the given
        string to standard error and/or a file followed by a newline in the
        appropriate log color.

    LOGF_FATAL(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        in the appropriate log color.

    LOGFLN_FATAL(const char* format, ...)

        Log timestamp, tracing information, log level symbol, and the given
        format string and format arguments to standard error and/or a file
        followed by a newline in the appropriate log color.

    LOG_PERROR_CRITICAL(const char* str)

        Log timestamp, log level symbol, and the given string to standard
        error and/or a file and then print the C error message in the
        appropriate log color.

    LOG_PERRORF_CRITICAL(const char* format, ...)

        Log timestamp, log level symbol, and the given format string and
        format arguments to standard error and/or a file followed by a C
        error message in the appropriate log color.


### "log_level" Functions Short Aliases (if enabled)

    LOG_TRC(const char* str);

        Alias of `LOG_TRACE` function.

    LOGLN_TRC(const char* str);

        Alias of `LOGLN_TRACE` function.

    LOGF_TRC(const char* format, ...);

        Alias of `LOGF_TRACE` function.

    LOGFLN_TRC(const char* format, ...);

        Alias of `LOGFLN_TRACE` function.


    LOG_DBG(const char* str);

        Alias of `LOG_DEBUG` function.

    LOGLN_DBG(const char* str);

        Alias of `LOGLN_DEBUG` function.

    LOGF_DBG(const char* format, ...);

        Alias of `LOGF_DEBUG` function.

    LOGFLN_DBG(const char* format, ...);

        Alias of `LOGFLN_DEBUG` function.


    LOG_EXT(const char* str);

        Alias of `LOG_EXTRA` function.

    LOGLN_EXT(const char* str);

        Alias of `LOGLN_EXTRA` function.

    LOGF_EXT(const char* format, ...);

        Alias of `LOGF_EXTRA` function.

    LOGFLN_EXT(const char* format, ...);

        Alias of `LOGFLN_EXTRA` function.


    LOG_INF(const char* str);

        Alias of `LOG_INFO` function.

    LOGLN_INF(const char* str);

        Alias of `LOGLN_INFO` function.

    LOGF_INF(const char* format, ...);

        Alias of `LOGF_INFO` function.

    LOGFLN_INF(const char* format, ...);

        Alias of `LOGFLN_INFO` function.


    LOG_HEAD(const char* str);

        Alias of `LOG_HEADER` function.

    LOGLN_HEAD(const char* str);

        Alias of `LOG_TRACE` function.

    LOGF_HEAD(const char* format, ...);

        Alias of `LOGF_HEADER` function.

    LOGFLN_HEAD(const char* format, ...);

        Alias of `LOGFLN_HEADER` function.


    LOG_SUC(const char* str);

        Alias of `LOG_SUCCESS` function.

    LOGLN_SUC(const char* str);

        Alias of `LOGLN_SUCCESS` function.

    LOGF_SUC(const char* format, ...);

        Alias of `LOGF_SUCCESS` function.

    LOGFLN_SUC(const char* format, ...);

        Alias of `LOGFLN_SUCCESS` function.


    LOG_MON(const char* str);

        Alias of `LOG_MONEY` function.

    LOGLN_MON(const char* str);

        Alias of `LOGLN_MONEY` function.

    LOGF_MON(const char* format, ...);

        Alias of `LOGF_MONEY` function.

    LOGFLN_MON(const char* format, ...);

        Alias of `LOGFLN_MONEY` function.


    LOG_MNY(const char* str);

        Alias of `LOG_MONEY` function.

    LOGLN_MNY(const char* str);

        Alias of `LOGLN_MONEY` function.

    LOGF_MNY(const char* format, ...);

        Alias of `LOGF_MONEY` function.

    LOGFLN_MNY(const char* format, ...);

        Alias of `LOGFLN_MONEY` function.


    LOG_IN(const char* str);

        Alias of `LOG_INPUT` function.

    LOGLN_IN(const char* str);

        Alias of `LOGLN_INPUT` function.

    LOGF_IN(const char* format, ...);

        Alias of `LOGF_INPUT` function.

    LOGFLN_IN(const char* format, ...);

        Alias of `LOGFLN_INPUT` function.


    LOG_WARN(const char* str);

        Alias of `LOG_WARNING` function.

    LOGLN_WARN(const char* str);

        Alias of `LOGLN_WARNING` function.

    LOGF_WARN(const char* format, ...);

        Alias of `LOGF_WARNING` function.

    LOGFLN_WARN(const char* format, ...);

        Alias of `LOGFLN_WARNING` function.

    LOG_PERROR_WARN(const char* str);

        Alias of `LOG_PERROR_WARNING` function.

    LOG_PERRORF_WARN(const char* format, ...);

        Alias of `LOG_PERRORF_WARNING` function.


    LOG_ERR(const char* str);

        Alias of `LOG_ERROR` function.

    LOGLN_ERR(const char* str);

        Alias of `LOGLN_ERROR` function.

    LOGF_ERR(const char* format, ...);

        Alias of `LOGF_ERROR` function.

    LOGFLN_ERR(const char* format, ...);

        Alias of `LOGFLN_ERROR` function.

    LOG_PERROR_ERR(const char* str);

        Alias of `LOG_PERROR_ERROR` function.

    LOG_PERRORF_ERR(const char* format, ...);

        Alias of `LOG_PERRORF_ERROR` function.


    LOG_CRIT(const char* str);

        Alias of `LOG_CRITICAL` function.

    LOGLN_CRIT(const char* str);

        Alias of `LOGLN_CRITICAL` function.

    LOGF_CRIT(const char* format, ...);

        Alias of `LOGF_CRITICAL` function.

    LOGFLN_CRIT(const char* format, ...);

        Alias of `LOGFLN_CRITICAL` function.

    LOG_PERROR_CRIT(const char* str);

        Alias of `LOG_PERROR_CRITICAL` function.

    LOG_PERRORF_CRIT(const char* format, ...);

        Alias of `LOG_PERRORF_CRITICAL` function.


    LOG_FAT(const char* str);

        Alias of `LOG_FATAL` function.

    LOGLN_FAT(const char* str);

        Alias of `LOGLN_FATAL` function.

    LOGF_FAT(const char* format, ...);

        Alias of `LOGF_FATAL` function.

    LOGFLN_FAT(const char* format, ...);

        Alias of `LOGFLN_FATAL` function.

    LOG_PERROR_FAT(const char* str);

        Alias of `LOG_PERROR_FATAL` function.

    LOG_PERRORF_FAT(const char* format, ...);

        Alias of `LOG_PERRORF_FATAL` function.


### "log_level" Functions Shorter Aliases (if enabled)

    LOG_TR(const char* str);

        Alias of `LOG_TRACE` function.

    LOGLN_TR(const char* str);

        Alias of `LOGLN_TRACE` function.

    LOGF_TR(const char* format, ...);

        Alias of `LOGF_TRACE` function.

    LOGFLN_TR(const char* format, ...);

        Alias of `LOGFLN_TRACE` function.


    LOG_DB(const char* str);

        Alias of `LOG_DEBUG` function.

    LOGLN_DB(const char* str);

        Alias of `LOGLN_DEBUG` function.

    LOGF_DB(const char* format, ...);

        Alias of `LOGF_DEBUG` function.

    LOGFLN_DB(const char* format, ...);

        Alias of `LOGFLN_DEBUG` function.


    LOG_EX(const char* str);

        Alias of `LOG_EXTRA` function.

    LOGLN_EX(const char* str);

        Alias of `LOGLN_EXTRA` function.

    LOGF_EX(const char* format, ...);

        Alias of `LOGF_EXTRA` function.

    LOGFLN_EX(const char* format, ...);

        Alias of `LOGFLN_EXTRA` function.


    LOG_IF(const char* str);

        Alias of `LOG_INFO` function.

    LOGLN_IF(const char* str);

        Alias of `LOGLN_INFO` function.

    LOGF_IF(const char* format, ...);

        Alias of `LOGF_INFO` function.

    LOGFLN_IF(const char* format, ...);

        Alias of `LOGFLN_INFO` function.


    LOG_HD(const char* str);

        Alias of `LOG_HEADER` function.

    LOGLN_HD(const char* str);

        Alias of `LOG_TRACE` function.

    LOGF_HD(const char* format, ...);

        Alias of `LOGF_HEADER` function.

    LOGFLN_HD(const char* format, ...);

        Alias of `LOGFLN_HEADER` function.


    LOG_SC(const char* str);

        Alias of `LOG_SUCCESS` function.

    LOGLN_SC(const char* str);

        Alias of `LOGLN_SUCCESS` function.

    LOGF_SC(const char* format, ...);

        Alias of `LOGF_SUCCESS` function.

    LOGFLN_SC(const char* format, ...);

        Alias of `LOGFLN_SUCCESS` function.


    LOG_MN(const char* str);

        Alias of `LOG_MONEY` function.

    LOGLN_MN(const char* str);

        Alias of `LOGLN_MONEY` function.

    LOGF_MN(const char* format, ...);

        Alias of `LOGF_MONEY` function.

    LOGFLN_MN(const char* format, ...);

        Alias of `LOGFLN_MONEY` function.


    LOG_MY(const char* str);

        Alias of `LOG_MONEY` function.

    LOGLN_MY(const char* str);

        Alias of `LOGLN_MONEY` function.

    LOGF_MY(const char* format, ...);

        Alias of `LOGF_MONEY` function.

    LOGFLN_MY(const char* format, ...);

        Alias of `LOGFLN_MONEY` function.


    LOG_IN(const char* str);

        Alias of `LOG_INPUT` function.

    LOGLN_IN(const char* str);

        Alias of `LOGLN_INPUT` function.

    LOGF_IN(const char* format, ...);

        Alias of `LOGF_INPUT` function.

    LOGFLN_IN(const char* format, ...);

        Alias of `LOGFLN_INPUT` function.


    LOG_WN(const char* str);

        Alias of `LOG_WARNING` function.

    LOGLN_WN(const char* str);

        Alias of `LOGLN_WARNING` function.

    LOGF_WN(const char* format, ...);

        Alias of `LOGF_WARNING` function.

    LOGFLN_WN(const char* format, ...);

        Alias of `LOGFLN_WARNING` function.

    LOG_PERROR_WN(const char* str);

        Alias of `LOG_PERROR_WARNING` function.

    LOG_PERRORF_WN(const char* format, ...);

        Alias of `LOG_PERRORF_WARNING` function.


    LOG_ER(const char* str);

        Alias of `LOG_ERROR` function.

    LOGLN_ER(const char* str);

        Alias of `LOGLN_ERROR` function.

    LOGF_ER(const char* format, ...);

        Alias of `LOGF_ERROR` function.

    LOGFLN_ER(const char* format, ...);

        Alias of `LOGFLN_ERROR` function.

    LOG_PERROR_ER(const char* str);

        Alias of `LOG_PERROR_ERROR` function.

    LOG_PERRORF_ER(const char* format, ...);

        Alias of `LOG_PERRORF_ERROR` function.


    LOG_CR(const char* str);

        Alias of `LOG_CRITICAL` function.

    LOGLN_CR(const char* str);

        Alias of `LOGLN_CRITICAL` function.

    LOGF_CR(const char* format, ...);

        Alias of `LOGF_CRITICAL` function.

    LOGFLN_CR(const char* format, ...);

        Alias of `LOGFLN_CRITICAL` function.

    LOG_PERROR_CR(const char* str);

        Alias of `LOG_PERROR_CRITICAL` function.

    LOG_PERRORF_CR(const char* format, ...);

        Alias of `LOG_PERRORF_CRITICAL` function.


    LOG_FT(const char* str);

        Alias of `LOG_FATAL` function.

    LOGLN_FT(const char* str);

        Alias of `LOGLN_FATAL` function.

    LOGF_FT(const char* format, ...);

        Alias of `LOGF_FATAL` function.

    LOGFLN_FT(const char* format, ...);

        Alias of `LOGFLN_FATAL` function.

    LOG_PERROR_FT(const char* str);

        Alias of `LOG_PERROR_FATAL` function.

    LOG_PERRORF_FT(const char* format, ...);

        Alias of `LOG_PERRORF_FATAL` function.


### "log_level" Functions Names Aliases (if enabled)

    TRACE(const char* str);

        Alias of `LOG_TRACE` function.

    TRACELN(const char* str);

        Alias of `LOGLN_TRACE` function.

    TRACEF(const char* format, ...);

        Alias of `LOGF_TRACE` function.

    TRACEFLN(const char* format, ...);

        Alias of `LOGFLN_TRACE` function.


    DEBUG(const char* str);

        Alias of `LOG_DEBUG` function.

    DEBUGLN(const char* str);

        Alias of `LOGLN_DEBUG` function.

    DEBUGF(const char* format, ...);

        Alias of `LOGF_DEBUG` function.

    DEBUGFLN(const char* format, ...);

        Alias of `LOGFLN_DEBUG` function.


    EXTRA(const char* str);

        Alias of `LOG_EXTRA` function.

    EXTRALN(const char* str);

        Alias of `LOGLN_EXTRA` function.

    EXTRAF(const char* format, ...);

        Alias of `LOGF_EXTRA` function.

    EXTRAFLN(const char* format, ...);

        Alias of `LOGFLN_EXTRA` function.


    INFO(const char* str);

        Alias of `LOG_INFO` function.

    INFOLN(const char* str);

        Alias of `LOGLN_INFO` function.

    INFOF(const char* format, ...);

        Alias of `LOGF_INFO` function.

    INFOFLN(const char* format, ...);

        Alias of `LOGFLN_INFO` function.


    HEADER(const char* str);

        Alias of `LOG_HEADER` function.

    HEADERLN(const char* str);

        Alias of `LOG_HEADER` function.

    HEADERF(const char* format, ...);

        Alias of `LOGF_HEADER` function.

    HEADERFLN(const char* format, ...);

        Alias of `LOGFLN_HEADER` function.


    SUCCESS(const char* str);

        Alias of `LOG_SUCCESS` function.

    SUCCESSLN(const char* str);

        Alias of `LOGLN_SUCCESS` function.

    SUCCESSF(const char* format, ...);

        Alias of `LOGF_SUCCESS` function.

    SUCCESSFLN(const char* format, ...);

        Alias of `LOGFLN_SUCCESS` function.


    MONEY(const char* str);

        Alias of `LOG_MONEY` function.

    MONEYLN(const char* str);

        Alias of `LOGLN_MONEY` function.

    MONEYF(const char* format, ...);

        Alias of `LOGF_MONEY` function.

    MONEYFLN(const char* format, ...);

        Alias of `LOGFLN_MONEY` function.


    INPUT(const char* str);

        Alias of `LOG_INPUT` function.

    INPUTLN(const char* str);

        Alias of `LOGLN_INPUT` function.

    INPUTF(const char* format, ...);

        Alias of `LOGF_INPUT` function.

    INPUTFLN(const char* format, ...);

        Alias of `LOGFLN_INPUT` function.


    WARNING(const char* str);

        Alias of `LOG_WARNING` function.

    WARNINGLN(const char* str);

        Alias of `LOGLN_WARNING` function.

    WARNINGF(const char* format, ...);

        Alias of `LOGF_WARNING` function.

    WARNINGFLN(const char* format, ...);

        Alias of `LOGFLN_WARNING` function.

    WARNING_PERROR(const char* str);

        Alias of `LOG_PERROR_WARNING` function.

    WARNING_PERRORF(const char* format, ...);

        Alias of `LOG_PERRORF_WARNING` function.


    ERROR(const char* str);

        Alias of `LOG_ERROR` function.

    ERRORLN(const char* str);

        Alias of `LOGLN_ERROR` function.

    ERRORF(const char* format, ...);

        Alias of `LOGF_ERROR` function.

    ERRORFLN(const char* format, ...);

        Alias of `LOGFLN_ERROR` function.

    ERROR_PERROR(const char* str);

        Alias of `LOG_PERROR_ERROR` function.

    ERROR_PERRORF(const char* format, ...);

        Alias of `LOG_PERRORF_ERROR` function.


    CRITICAL(const char* str);

        Alias of `LOG_CRITICAL` function.

    CRITICALLN(const char* str);

        Alias of `LOGLN_CRITICAL` function.

    CRITICALF(const char* format, ...);

        Alias of `LOGF_CRITICAL` function.

    CRITICALFLN(const char* format, ...);

        Alias of `LOGFLN_CRITICAL` function.

    CRITICAL_PERROR(const char* str);

        Alias of `LOG_PERROR_CRITICAL` function.

    CRITICAL_PERRORF(const char* format, ...);

        Alias of `LOG_PERRORF_CRITICAL` function.


    FATAL(const char* str);

        Alias of `LOG_FATAL` function.

    FATALLN(const char* str);

        Alias of `LOGLN_FATAL` function.

    FATALF(const char* format, ...);

        Alias of `LOGF_FATAL` function.

    FATALFLN(const char* format, ...);

        Alias of `LOGFLN_FATAL` function.

    FATAL_PERROR(const char* str);

        Alias of `LOG_PERROR_FATAL` function.

    FATAL_PERRORF(const char* format, ...);

        Alias of `LOG_PERRORF_FATAL` function.

