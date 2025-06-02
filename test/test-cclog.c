
#include "test-cclog.h"


// Function Declarations

static struct test* test_manual_cclog();
static struct test* test_manual_cclog_stream();
static struct test* test_manual_cctlog();


// Main test function.

struct unit* unit_cclog() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"cclog\" Functions");

    ADD_TEST(unit, test_manual_cclog());
    ADD_TEST(unit, test_manual_cclog_stream());
    ADD_TEST(unit, test_manual_cctlog());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_cclog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_CPRINT(CCLOG);
    TEST_CPRINTLN(CCLOGLN);
    TEST_CPRINTF(CCLOGF);
    TEST_CPRINTFLN(CCLOGFLN);
    TEST_CHEX(CCLOG_HEX);
    TEST_CHEXLN(CCLOGLN_HEX);
    TEST_CHEX(CCLOG_WIDE_HEX);
    TEST_CHEXLN(CCLOGLN_WIDE_HEX);
    TEST_CPRINTLN(CCLOG_PERROR);
    errno = ENOENT;
    TEST_CPRINTLN(CCLOG_PERROR);
    errno = 0;
    TEST_CPRINTFLN(CCLOG_PERRORF);
    errno = ENOENT;
    TEST_CPRINTFLN(CCLOG_PERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CCLOGLN(C_RED, "This is a test");
    );
    ASSERT(strstr(buf, C_RED) && "RED not found in info log.");

    PASS_TEST();
}


static struct test* test_manual_cclog_stream() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_CPRINT(CCLOG_STREAM);
    TEST_CPRINTLN(CCLOGLN_STREAM);
    TEST_CPRINTF(CCLOGF_STREAM);
    TEST_CPRINTFLN(CCLOGFLN_STREAM);
    TEST_CHEX(CCLOG_HEX_STREAM);
    TEST_CHEXLN(CCLOGLN_HEX_STREAM);
    TEST_CHEX(CCLOG_WIDE_HEX_STREAM);
    TEST_CHEXLN(CCLOGLN_WIDE_HEX_STREAM);
    TEST_CPRINTLN(CCLOG_PERROR_STREAM);
    errno = ENOENT;
    TEST_CPRINTLN(CCLOG_PERROR_STREAM);
    errno = 0;
    TEST_CPRINTFLN(CCLOG_PERRORF_STREAM);
    errno = ENOENT;
    TEST_CPRINTFLN(CCLOG_PERRORF_STREAM);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CCLOGLN_STREAM(C_RED, "This is a test");
    );
    ASSERT(strstr(buf, C_RED) && "RED not found in info log.");

    PASS_TEST();
}


static struct test* test_manual_cctlog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_CPRINT(CCTLOG);
    TEST_CPRINTLN(CCTLOGLN);
    TEST_CPRINTF(CCTLOGF);
    TEST_CPRINTFLN(CCTLOGFLN);
    TEST_CHEX(CCTLOG_HEX);
    TEST_CHEXLN(CCTLOGLN_HEX);
    TEST_CHEX(CCTLOG_WIDE_HEX);
    TEST_CHEXLN(CCTLOGLN_WIDE_HEX);
    TEST_CPRINTLN(CCTLOG_PERROR);
    errno = ENOENT;
    TEST_CPRINTLN(CCTLOG_PERROR);
    errno = 0;
    TEST_CPRINTFLN(CCTLOG_PERRORF);
    errno = ENOENT;
    TEST_CPRINTFLN(CCTLOG_PERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CCTLOGLN(C_RED, "This is a test");
    );
    ASSERT(strstr(buf, C_RED) && "RED not found in info log.");

    PASS_TEST();
}


