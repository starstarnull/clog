
#include "test-fprint.h"


// Function Declarations

static struct test* test_manual_fprint();


// Main test function.

struct unit* unit_fprint() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"fprint\" Functions");

    ADD_TEST(unit, test_manual_fprint());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_fprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_FPRINT(FPRINT);
    TEST_FPRINTLN(FPRINTLN);
    TEST_FPRINTF(FPRINTF);
    TEST_FPRINTFLN(FPRINTFLN);
    TEST_FHEX(FPRINT_HEX);
    TEST_FHEXLN(FPRINTLN_HEX);
    TEST_FHEX(FPRINT_WIDE_HEX);
    TEST_FHEXLN(FPRINTLN_WIDE_HEX);
    TEST_FPRINTLN(FPERROR);
    errno = ENOENT;
    TEST_FPRINTLN(FPERROR);
    errno = 0;
    TEST_FPRINTFLN(FPERRORF);
    errno = ENOENT;
    TEST_FPRINTFLN(FPERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, FPRINTLN(stdout, "MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");

    PASS_TEST();
}


