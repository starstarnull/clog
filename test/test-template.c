
#include "test-template.h"


// Function Declarations

static struct test* test_manual_template();


// Main test function.

struct unit* unit_template() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Template");

    ADD_TEST(unit, test_manual_template());

    REVERSE_LIST(unit);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_template() {

    TEST_HEADER(__FUNCTION__);
    
    ASSERT(true);
    puts("\n");

    PASS_TEST();
}


