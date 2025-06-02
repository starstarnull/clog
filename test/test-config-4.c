
#include "test-config-4.h"
#include "clog.h"


// Function Declarations

static struct test* test_manual_syms_one_char();


// Main test function.

struct unit* unit_config_4() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 4 Options");

    ADD_TEST(unit, test_manual_syms_one_char());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_syms_one_char() {

    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINTLN(CLOGLN_TRACE);
    TEST_PRINTLN(CLOGLN_DEBUG);
    TEST_PRINTLN(CLOGLN_EXTRA);
    TEST_PRINTLN(CLOGLN_INFO);
    TEST_PRINTLN(CLOGLN_HEADER);
    TEST_PRINTLN(CLOGLN_SUCCESS);
    TEST_PRINTLN(CLOGLN_MONEY);
    TEST_PRINTLN(CLOGLN_INPUT);
    TEST_PRINTLN(CLOGLN_WARNING);
    TEST_PRINTLN(CLOGLN_ERROR);
    TEST_PRINTLN(CLOGLN_CRITICAL);
    TEST_PRINTLN(CLOGLN_FATAL);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_TRACE("This is a test");
    );
    ASSERT(!strstr(buf, "[TRACE]") && "Tracing symbol was found.");
    ASSERT(strlen(CLOG_SYM_TRACE) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_DEBUG) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_EXTRA) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_INFO) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_HEADER) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_SUCCESS) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_MONEY) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_INPUT) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_WARNING) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_ERROR) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_CRITICAL) == 3 && "Symbol was not one character plus brackets.");
    ASSERT(strlen(CLOG_SYM_FATAL) == 3 && "Symbol was not one character plus brackets.");

    PASS_TEST();
}


