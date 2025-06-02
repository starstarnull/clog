
#include "test-config-7.h"


// Function Declarations

static struct test* test_manual_custom_syms();


// Main test function.

struct unit* unit_config_7() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 7 Options");

    ADD_TEST(unit, test_manual_custom_syms());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_custom_syms() {

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

    PASS_TEST();
}


