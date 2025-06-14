
#include "test-constants.h"


// Function Declarations

static struct test* test_manual_colors();
static struct test* test_manual_palette();
static struct test* test_manual_symbols();
static struct test* test_manual_options_constants();


// Main test function.

struct unit* unit_constants() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Constant Macros");

    ADD_TEST(unit, test_manual_colors());
    ADD_TEST(unit, test_manual_palette());
    ADD_TEST(unit, test_manual_symbols());
    ADD_TEST(unit, test_manual_options_constants());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_colors() {

    TEST_HEADER(__FUNCTION__);

    COLOR_MACRO_TEST(C_RESET);
    COLOR_MACRO_TEST(C_BOLD);
    COLOR_MACRO_TEST(C_BLACK);
    COLOR_MACRO_TEST(C_RED);
    COLOR_MACRO_TEST(C_GREEN);
    COLOR_MACRO_TEST(C_YELLOW);
    COLOR_MACRO_TEST(C_BLUE);
    COLOR_MACRO_TEST(C_MAGENTA);
    COLOR_MACRO_TEST(C_CYAN);
    COLOR_MACRO_TEST(C_WHITE);
    COLOR_MACRO_TEST(C_B_BLACK);
    COLOR_MACRO_TEST(C_B_RED);
    COLOR_MACRO_TEST(C_B_GREEN);
    COLOR_MACRO_TEST(C_B_YELLOW);
    COLOR_MACRO_TEST(C_B_BLUE);
    COLOR_MACRO_TEST(C_B_MAGENTA);
    COLOR_MACRO_TEST(C_B_CYAN);
    COLOR_MACRO_TEST(C_B_WHITE);
    COLOR_MACRO_TEST(C_BR_BLACK);
    COLOR_MACRO_TEST(C_BR_RED);
    COLOR_MACRO_TEST(C_BR_GREEN);
    COLOR_MACRO_TEST(C_BR_YELLOW);
    COLOR_MACRO_TEST(C_BR_BLUE);
    COLOR_MACRO_TEST(C_BR_MAGENTA);
    COLOR_MACRO_TEST(C_BR_CYAN);
    COLOR_MACRO_TEST(C_BR_WHITE);
    COLOR_MACRO_TEST(C_B_BR_BLACK);
    COLOR_MACRO_TEST(C_B_BR_RED);
    COLOR_MACRO_TEST(C_B_BR_GREEN);
    COLOR_MACRO_TEST(C_B_BR_YELLOW);
    COLOR_MACRO_TEST(C_B_BR_BLUE);
    COLOR_MACRO_TEST(C_B_BR_MAGENTA);
    COLOR_MACRO_TEST(C_B_BR_CYAN);
    COLOR_MACRO_TEST(C_B_BR_WHITE);
    COLOR_MACRO_TEST_LINE(C_ORANGE);
    COLOR_MACRO_TEST_LINE(C_B_ORANGE);
    COLOR_MACRO_TEST_LINE(C_GRAY);
    COLOR_MACRO_TEST_LINE(C_B_GRAY);
    COLOR_MACRO_TEST_LINE(C_DARK_GRAY);
    COLOR_MACRO_TEST_LINE(C_B_DARK_GRAY);
    puts("\n");

    ASSERT(strstr(C_BLUE, "\x1b") && "Terminal code not detected.");

    PASS_TEST();
}


static struct test* test_manual_palette() {

    TEST_HEADER(__FUNCTION__);

    COLOR_MACRO_TEST_LINE(C_TRACE);
    COLOR_MACRO_TEST_LINE(C_DEBUG);
    COLOR_MACRO_TEST_LINE(C_EXTRA);
    COLOR_MACRO_TEST_LINE(C_INFO);
    COLOR_MACRO_TEST_LINE(C_HEADER);
    COLOR_MACRO_TEST_LINE(C_SUCCESS);
    COLOR_MACRO_TEST_LINE(C_MONEY);
    COLOR_MACRO_TEST_LINE(C_INPUT);
    COLOR_MACRO_TEST_LINE(C_WARNING);
    COLOR_MACRO_TEST_LINE(C_ERROR);
    COLOR_MACRO_TEST_LINE(C_CRITICAL);
    COLOR_MACRO_TEST_LINE(C_FATAL);
    puts("\n");

    ASSERT(strstr(C_TRACE, "\x1b") && "Terminal code not detected.");

    PASS_TEST();
}


static struct test* test_manual_symbols() {

    TEST_HEADER(__FUNCTION__);

    SYMBOL_MACRO_TEST(CLOG_SYM_TRACE);
    SYMBOL_MACRO_TEST(CLOG_SYM_DEBUG);
    SYMBOL_MACRO_TEST(CLOG_SYM_EXTRA);
    SYMBOL_MACRO_TEST(CLOG_SYM_INFO);
    SYMBOL_MACRO_TEST(CLOG_SYM_HEADER);
    SYMBOL_MACRO_TEST(CLOG_SYM_SUCCESS);
    SYMBOL_MACRO_TEST(CLOG_SYM_MONEY);
    SYMBOL_MACRO_TEST(CLOG_SYM_INPUT);
    SYMBOL_MACRO_TEST(CLOG_SYM_WARNING);
    SYMBOL_MACRO_TEST(CLOG_SYM_ERROR);
    SYMBOL_MACRO_TEST(CLOG_SYM_CRITICAL);
    SYMBOL_MACRO_TEST(CLOG_SYM_FATAL);
    puts("\n");

    ASSERT(!strcmp(CLOG_SYM_TRACE, "[TRACE]") && "Symbols do not match.");

    PASS_TEST();
}


static struct test* test_manual_options_constants() {

    TEST_HEADER(__FUNCTION__);

    CONSTANT_DEFINED_TEST(
        CLOG_ENABLE_SHORT_ALIASES, IS_DEFINED(CLOG_ENABLE_SHORT_ALIASES)
    );
    CONSTANT_DEFINED_TEST(
        CLOG_ENABLE_SHORTER_ALIASES, IS_DEFINED(CLOG_ENABLE_SHORTER_ALIASES)
    );
    CONSTANT_DEFINED_TEST(
        CLOG_ENABLE_NAME_ALIASES, IS_DEFINED(CLOG_ENABLE_NAME_ALIASES)
    );
    ASSERT(!IS_DEFINED(CLOG_ENABLE_SHORT_ALIASES) && "Not default option.");
    ASSERT(!IS_DEFINED(CLOG_ENABLE_SHORTER_ALIASES) && "Not default option.");
    ASSERT(!IS_DEFINED(CLOG_ENABLE_NAME_ALIASES) && "Not default option.");
    puts("");

    CONSTANT_STR_TEST(CLOG_LINE_HEADER_SEP);
    ASSERT(*CLOG_LINE_HEADER_SEP == ' ' && "Not default option.");

    CONSTANT_STR_TEST(CLOG_TRACING_SEP);
    ASSERT(*CLOG_TRACING_SEP == ':' && "Not default option.");
    puts("");

    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_NONE);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_WORDS);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_LETTERS);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_ONE_CHAR);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_THREE_CHAR);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_EMOJIS);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS_DEFAULT);
    CONSTANT_INT_TEST(CLOG_LEVEL_SYMS);
    ASSERT(CLOG_LEVEL_SYMS == CLOG_LEVEL_SYMS_DEFAULT && "Not default option.");
    puts("");

    CONSTANT_INT_TEST(CLOG_CONSOLE_MODE_NOCOLOR);
    CONSTANT_INT_TEST(CLOG_CONSOLE_MODE_COLOR);
    CONSTANT_INT_TEST(CLOG_CONSOLE_MODE);
    ASSERT(CLOG_CONSOLE_MODE == CLOG_CONSOLE_MODE_COLOR && "Not default option.");
    puts("");

    CONSTANT_INT_TEST(CLOG_MODE_NONE);
    CONSTANT_INT_TEST(CLOG_MODE_CONSOLE);
    CONSTANT_INT_TEST(CLOG_MODE_FILE);
    CONSTANT_INT_TEST(CLOG_MODE_CONSOLE_AND_FILE);
    CONSTANT_INT_TEST(CLOG_MODE);
    ASSERT(CLOG_MODE == CLOG_MODE_CONSOLE_AND_FILE && "Not default option.");
    puts("");

    CONSTANT_INT_TEST(CLOG_LEVEL_NONE);
    CONSTANT_INT_TEST(CLOG_LEVEL_CRITICAL);
    CONSTANT_INT_TEST(CLOG_LEVEL_ERROR);
    CONSTANT_INT_TEST(CLOG_LEVEL_WARNING);
    CONSTANT_INT_TEST(CLOG_LEVEL_INFO);
    CONSTANT_INT_TEST(CLOG_LEVEL_EXTRA);
    CONSTANT_INT_TEST(CLOG_LEVEL_DEBUG);
    CONSTANT_INT_TEST(CLOG_LEVEL_ALL);
    CONSTANT_INT_TEST(CLOG_LEVEL);
    ASSERT(CLOG_LEVEL == CLOG_LEVEL_ALL && "Not default option.");
    puts("");

    CONSTANT_STR_TEST(CLOG_FILE);
    CONSTANT_STR_TEST(CLOG_TIME_FORMAT);
    puts("");

    CONSTANT_DEFINED_TEST(
        CLOG_DISABLE_TIMESTAMPS, IS_DEFINED(CLOG_DISABLE_TIMESTAMPS)
    );
    CONSTANT_DEFINED_TEST(CLOG_USE_UTC_TIME, IS_DEFINED(CLOG_USE_UTC_TIME));
    CONSTANT_DEFINED_TEST(
        CLOG_DISABLE_TRACING, IS_DEFINED(CLOG_DISABLE_TRACING)
    );
    ASSERT(!IS_DEFINED(CLOG_DISABLE_TIMESTAMPS) && "Not default option.");
    ASSERT(!IS_DEFINED(CLOG_UTC_TIME) && "Not default option.");
    ASSERT(!IS_DEFINED(CLOG_DISABLE_TRACING) && "Not default option.");
    puts("\n");

    PASS_TEST();
}


