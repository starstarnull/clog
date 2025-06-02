
#include "test-config-5.h"


// Function Declarations

static struct test* test_manual_syms_three_char();


// Main test function.

struct unit* unit_config_5() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 5 Options");

    ADD_TEST(unit, test_manual_syms_three_char());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_syms_three_char() {

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
    ASSERT(strlen(CLOG_SYM_TRACE) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_DEBUG) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_EXTRA) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_INFO) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_HEADER) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_SUCCESS) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_MONEY) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_INPUT) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_WARNING) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_ERROR) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_CRITICAL) == 5 && "Symbol was not three characters plus brackets.");
    ASSERT(strlen(CLOG_SYM_FATAL) == 5 && "Symbol was not three characters plus brackets.");

    PASS_TEST();
}


