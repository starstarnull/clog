
#include "test-cprint.h"


// Function Declarations

static struct test* test_manual_cprint();
static struct test* test_manual_cprint_level();


// Main test function.

struct unit* unit_cprint() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"cprint\" Functions");

    ADD_TEST(unit, test_manual_cprint());
    ADD_TEST(unit, test_manual_cprint_level());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_cprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_CPRINT(CPRINT);
    TEST_CPRINTLN(CPRINTLN);
    TEST_CPRINTF(CPRINTF);
    TEST_CPRINTFLN(CPRINTFLN);
    TEST_CHEX(CPRINT_HEX);
    TEST_CHEXLN(CPRINTLN_HEX);
    TEST_CHEX(CPRINT_WIDE_HEX);
    TEST_CHEXLN(CPRINTLN_WIDE_HEX);
    TEST_CPRINTLN(CPERROR);
    errno = ENOENT;
    TEST_CPRINTLN(CPERROR);
    errno = 0;
    TEST_CPRINTFLN(CPERRORF);
    errno = ENOENT;
    TEST_CPRINTFLN(CPERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, CPRINTLN(C_RED, "MARKER");
    );
    printf("buf: '%s'\n", buf);
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, C_RED) && "RED not found in info print.");

    PASS_TEST();
}


static struct test* test_manual_cprint_level() {

    int integer = 1234567890;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_CPRINT(CPRINT_TRACE);
    TEST_CPRINTLN(CPRINTLN_TRACE);
    TEST_CPRINTF(CPRINTF_TRACE);
    TEST_CPRINTFLN(CPRINTFLN_TRACE);
    puts("");

    TEST_CPRINT(CPRINT_DEBUG);
    TEST_CPRINTLN(CPRINTLN_DEBUG);
    TEST_CPRINTF(CPRINTF_DEBUG);
    TEST_CPRINTFLN(CPRINTFLN_DEBUG);
    puts("");

    TEST_CPRINT(CPRINT_EXTRA);
    TEST_CPRINTLN(CPRINTLN_EXTRA);
    TEST_CPRINTF(CPRINTF_EXTRA);
    TEST_CPRINTFLN(CPRINTFLN_EXTRA);
    puts("");

    TEST_CPRINT(CPRINT_INFO);
    TEST_CPRINTLN(CPRINTLN_INFO);
    TEST_CPRINTF(CPRINTF_INFO);
    TEST_CPRINTFLN(CPRINTFLN_INFO);
    puts("");

    TEST_CPRINT(CPRINT_HEADER);
    TEST_CPRINTLN(CPRINTLN_HEADER);
    TEST_CPRINTF(CPRINTF_HEADER);
    TEST_CPRINTFLN(CPRINTFLN_HEADER);
    puts("");

    TEST_CPRINT(CPRINT_SUCCESS);
    TEST_CPRINTLN(CPRINTLN_SUCCESS);
    TEST_CPRINTF(CPRINTF_SUCCESS);
    TEST_CPRINTFLN(CPRINTFLN_SUCCESS);
    puts("");

    TEST_CPRINT(CPRINT_MONEY);
    TEST_CPRINTLN(CPRINTLN_MONEY);
    TEST_CPRINTF(CPRINTF_MONEY);
    TEST_CPRINTFLN(CPRINTFLN_MONEY);
    puts("");

    TEST_CPRINT(CPRINT_INPUT);
    TEST_CPRINTLN(CPRINTLN_INPUT);
    TEST_CPRINTF(CPRINTF_INPUT);
    TEST_CPRINTFLN(CPRINTFLN_INPUT);
    puts("");

    TEST_CPRINT(CPRINT_WARNING);
    TEST_CPRINTLN(CPRINTLN_WARNING);
    TEST_CPRINTF(CPRINTF_WARNING);
    TEST_CPRINTFLN(CPRINTFLN_WARNING);
    errno = ENOENT;
    TEST_CPRINTLN(CPERROR_WARNING);
    errno = ENOENT;
    TEST_CPRINTFLN(CPERRORF_WARNING);
    errno = 0;
    puts("");

    TEST_CPRINT(CPRINT_ERROR);
    TEST_CPRINTLN(CPRINTLN_ERROR);
    TEST_CPRINTF(CPRINTF_ERROR);
    TEST_CPRINTFLN(CPRINTFLN_ERROR);
    errno = ENOENT;
    TEST_CPRINTLN(CPERROR_ERROR);
    errno = ENOENT;
    TEST_CPRINTFLN(CPERRORF_ERROR);
    errno = 0;
    puts("");

    TEST_CPRINT(CPRINT_CRITICAL);
    TEST_CPRINTLN(CPRINTLN_CRITICAL);
    TEST_CPRINTF(CPRINTF_CRITICAL);
    TEST_CPRINTFLN(CPRINTFLN_CRITICAL);
    errno = ENOENT;
    TEST_CPRINTLN(CPERROR_CRITICAL);
    errno = ENOENT;
    TEST_CPRINTFLN(CPERRORF_CRITICAL);
    errno = 0;
    puts("");

    TEST_CPRINT(CPRINT_FATAL);
    TEST_CPRINTLN(CPRINTLN_FATAL);
    TEST_CPRINTF(CPRINTF_FATAL);
    TEST_CPRINTFLN(CPRINTFLN_FATAL);
    errno = ENOENT;
    TEST_CPRINTLN(CPERROR_FATAL);
    errno = ENOENT;
    TEST_CPRINTFLN(CPERRORF_FATAL);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, CPRINTLN_TRACE(C_RED, "MARKER");
    );
    ASSERT(strstr(buf, C_RED) && "RED not found in print.");
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, "TRACE") && "Trace symbol not found.");

    PASS_TEST();
}


