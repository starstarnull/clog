
#include "test-clog.h"


// Function Declarations

static struct test* test_manual_clog();
static struct test* test_manual_clog_stream();
static struct test* test_manual_ctlog();
static struct test* test_manual_clog_level();


// Main test function.

struct unit* unit_clog() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"clog\" Functions");

    ADD_TEST(unit, test_manual_clog());
    ADD_TEST(unit, test_manual_clog_stream());
    ADD_TEST(unit, test_manual_ctlog());
    ADD_TEST(unit, test_manual_clog_level());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_clog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    TEST_PRINT(CLOG);
    TEST_PRINTLN(CLOGLN);
    TEST_PRINTF(CLOGF);
    TEST_PRINTFLN(CLOGFLN);
    TEST_HEX(CLOG_HEX);
    TEST_HEXLN(CLOGLN_HEX);
    TEST_HEX(CLOG_WIDE_HEX);
    TEST_HEXLN(CLOGLN_WIDE_HEX);
    TEST_PRINTLN(CLOG_PERROR);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR);
    errno = 0;
    TEST_PRINTFLN(CLOG_PERRORF);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");

    PASS_TEST();
}


static struct test* test_manual_clog_stream() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    TEST_PRINT(CLOG_STREAM);
    TEST_PRINTLN(CLOGLN_STREAM);
    TEST_PRINTF(CLOGF_STREAM);
    TEST_PRINTFLN(CLOGFLN_STREAM);
    TEST_HEX(CLOG_HEX_STREAM);
    TEST_HEXLN(CLOGLN_HEX_STREAM);
    TEST_HEX(CLOG_WIDE_HEX_STREAM);
    TEST_HEXLN(CLOGLN_WIDE_HEX_STREAM);
    TEST_PRINTLN(CLOG_PERROR_STREAM);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_STREAM);
    errno = 0;
    TEST_PRINTFLN(CLOG_PERRORF_STREAM);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_STREAM);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_STREAM("MARKER");
    );
    ASSERT(!strcmp(buf, "MARKER\n") && "Print test failed.");

    PASS_TEST();
}


static struct test* test_manual_ctlog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    TEST_PRINT(CTLOG);
    TEST_PRINTLN(CTLOGLN);
    TEST_PRINTF(CTLOGF);
    TEST_PRINTFLN(CTLOGFLN);
    TEST_HEX(CTLOG_HEX);
    TEST_HEXLN(CTLOGLN_HEX);
    TEST_HEX(CTLOG_WIDE_HEX);
    TEST_HEXLN(CTLOGLN_WIDE_HEX);
    TEST_PRINTLN(CTLOG_PERROR);
    errno = ENOENT;
    TEST_PRINTLN(CTLOG_PERROR);
    errno = 0;
    TEST_PRINTFLN(CTLOG_PERRORF);
    errno = ENOENT;
    TEST_PRINTFLN(CTLOG_PERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CTLOGLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");

    PASS_TEST();
}


static struct test* test_manual_clog_level() {

    int integer = 1234567890;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    TEST_PRINT(CLOG_TRACE);
    TEST_PRINTLN(CLOGLN_TRACE);
    TEST_PRINTF(CLOGF_TRACE);
    TEST_PRINTFLN(CLOGFLN_TRACE);
    puts("");

    TEST_PRINT(CLOG_DEBUG);
    TEST_PRINTLN(CLOGLN_DEBUG);
    TEST_PRINTF(CLOGF_DEBUG);
    TEST_PRINTFLN(CLOGFLN_DEBUG);
    puts("");

    TEST_PRINT(CLOG_EXTRA);
    TEST_PRINTLN(CLOGLN_EXTRA);
    TEST_PRINTF(CLOGF_EXTRA);
    TEST_PRINTFLN(CLOGFLN_EXTRA);
    puts("");

    TEST_PRINT(CLOG_INFO);
    TEST_PRINTLN(CLOGLN_INFO);
    TEST_PRINTF(CLOGF_INFO);
    TEST_PRINTFLN(CLOGFLN_INFO);
    puts("");

    TEST_PRINT(CLOG_HEADER);
    TEST_PRINTLN(CLOGLN_HEADER);
    TEST_PRINTF(CLOGF_HEADER);
    TEST_PRINTFLN(CLOGFLN_HEADER);
    puts("");

    TEST_PRINT(CLOG_SUCCESS);
    TEST_PRINTLN(CLOGLN_SUCCESS);
    TEST_PRINTF(CLOGF_SUCCESS);
    TEST_PRINTFLN(CLOGFLN_SUCCESS);
    puts("");

    TEST_PRINT(CLOG_MONEY);
    TEST_PRINTLN(CLOGLN_MONEY);
    TEST_PRINTF(CLOGF_MONEY);
    TEST_PRINTFLN(CLOGFLN_MONEY);
    puts("");

    TEST_PRINT(CLOG_INPUT);
    TEST_PRINTLN(CLOGLN_INPUT);
    TEST_PRINTF(CLOGF_INPUT);
    TEST_PRINTFLN(CLOGFLN_INPUT);
    puts("");

    TEST_PRINT(CLOG_WARNING);
    TEST_PRINTLN(CLOGLN_WARNING);
    TEST_PRINTF(CLOGF_WARNING);
    TEST_PRINTFLN(CLOGFLN_WARNING);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_WARNING);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_WARNING);
    errno = 0;
    puts("");

    TEST_PRINT(CLOG_ERROR);
    TEST_PRINTLN(CLOGLN_ERROR);
    TEST_PRINTF(CLOGF_ERROR);
    TEST_PRINTFLN(CLOGFLN_ERROR);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_ERROR);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_ERROR);
    errno = 0;
    puts("");

    TEST_PRINT(CLOG_CRITICAL);
    TEST_PRINTLN(CLOGLN_CRITICAL);
    TEST_PRINTF(CLOGF_CRITICAL);
    TEST_PRINTFLN(CLOGFLN_CRITICAL);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_CRITICAL);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_CRITICAL);
    errno = 0;
    puts("");

    TEST_PRINT(CLOG_FATAL);
    TEST_PRINTLN(CLOGLN_FATAL);
    TEST_PRINTF(CLOGF_FATAL);
    TEST_PRINTFLN(CLOGFLN_FATAL);
    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_FATAL);
    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_FATAL);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_TRACE("MARKER");
    );
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    ASSERT(strstr(buf, "TRACE") && "Trace symbol not found.");

    PASS_TEST();
}


