
#include "test-cfprint.h"


// Function Declarations

static struct test* test_manual_cfprint();


// Main test function.

struct unit* unit_cfprint() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"cfprint\" Functions");

    ADD_TEST(unit, test_manual_cfprint());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_cfprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    TEST_CFPRINT(CFPRINT);
    TEST_CFPRINTLN(CFPRINTLN);
    TEST_CFPRINTF(CFPRINTF);
    TEST_CFPRINTFLN(CFPRINTFLN);
    TEST_CFHEX(CFPRINT_HEX);
    TEST_CFHEXLN(CFPRINTLN_HEX);
    TEST_CFHEX(CFPRINT_WIDE_HEX);
    TEST_CFHEXLN(CFPRINTLN_WIDE_HEX);
    TEST_CFPRINTLN(CFPERROR);
    errno = ENOENT;
    TEST_CFPRINTLN(CFPERROR);
    errno = 0;
    TEST_CFPRINTFLN(CFPERRORF);
    errno = ENOENT;
    TEST_CFPRINTFLN(CFPERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, CFPRINTLN(C_RED, stdout, "MARKER");
    );
    ASSERT(strstr(buf, C_RED) && "RED not found in info print.");

    PASS_TEST();
}


