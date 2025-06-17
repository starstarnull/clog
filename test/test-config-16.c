
#include "test-config-16.h"


// Function Declarations

static struct test* test_manual_mode_file();


// Main test function.

struct unit* unit_config_16() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 16 Options");

    ADD_TEST(unit, test_manual_mode_file());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("");

    return unit;
}


static struct test* test_manual_mode_file() {

    int fd;
    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    // Create log.
    FLOGLN("Test creation.");

    fd = open(CLOG_FILE, O_RDONLY);
    ASSERT(fd != -1 && "Failed to open log file.");
    lseek(fd, 0, SEEK_END);

    // Test CLOG functions.
    TEST_PRINT(CLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CLOG_STREAM functions.
    TEST_PRINT(CLOG_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOG_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOGLN_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOG_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CLOGLN_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOG_PERROR_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOG_PERRORF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CTLOG functions.
    TEST_PRINT(CTLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CTLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CTLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CTLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGFLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CTLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CTLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CTLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_HEX(CTLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CTLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CTLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CTLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CTLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CLOG_LEVEL functions.
    TEST_PRINT(CLOG_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR_WARNING);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF_WARNING);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR_ERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF_ERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR_CRITICAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF_CRITICAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_PRINT(CLOG_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINT(CLOGLN_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGF_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_PRINTF(CLOGFLN_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINT(CLOG_PERROR_FATAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_PRINTF(CLOG_PERRORF_FATAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CCLOG functions.
    TEST_CPRINT(CCLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGFLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINT(CCLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINTF(CCLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CCLOG_STREAM functions.
    TEST_CPRINT(CCLOG_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCLOGLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOGF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOGFLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGFLN_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOG_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOGLN_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOG_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCLOGLN_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCLOG_PERROR_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINT(CCLOG_PERROR_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCLOG_PERRORF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINTF(CCLOG_PERRORF_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test CCTLOG functions.
    TEST_CPRINT(CCTLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCTLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCTLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCTLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGFLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCTLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCTLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCTLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CHEX(CCTLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINT(CCTLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINT(CCTLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_CPRINTF(CCTLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_CPRINTF(CCTLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test flog functions.
    TEST_FLOGPRINT(FLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    // FLOG STREAM functions.
    TEST_FLOGPRINT(FLOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FLOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FLOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FLOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    // FTLOG functions.
    TEST_FLOGPRINT(FTLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FTLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FTLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FTLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FTLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FTLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEX(FTLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGHEXLN(FTLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FTLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FTLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    // FLOG level functions.
    TEST_FLOGPRINT(FLOG_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");

    TEST_FLOGPRINT(FLOG_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTLN(FLOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTF(FLOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    TEST_FLOGPRINTFLN(FLOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    puts("");


    // Test LOG functions.
    TEST_PRINT(LOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    // LOG STREAM functions.
    TEST_PRINT(LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_STREAM("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");


    // Test TLOG functions.
    TEST_PRINT(TLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(TLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(TLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(TLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGFLN("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_HEX(TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(TLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(TLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERRORF("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");


    // C_LOG functions.
    TEST_CPRINT(C_LOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGFLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINT(C_LOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINTF(C_LOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");


    // Test C_LOG_STREAM functions.
    TEST_CPRINT(C_LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGFLN_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINT(C_LOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINTF(C_LOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    // Test C_TLOG functions.
    TEST_CPRINT(C_TLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_TLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_TLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_TLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGFLN(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CHEX(C_TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINT(C_TLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERROR(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_CPRINTF(C_TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_CPRINTF(C_TLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    // Test LOG_LEVEL functions.
    TEST_PRINT(LOG_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_TRACE("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_DEBUG("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_EXTRA("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_INFO("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_HEADER("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_SUCCESS("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_MONEY("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_INPUT("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_WARNING("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_ERROR("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_CRITICAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("");

    TEST_PRINT(LOG_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINTF(LOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINT(LOG_PERROR_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);

    errno = ENOENT;
    TEST_PRINTF(LOG_PERRORF_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(*buf && "LOG did not log when configured to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_FATAL("MARKER"););
    ASSERT(!*buf && "LOG logged when configured not to.");
    lseek(fd, 0, SEEK_END);
    puts("\n");

    close(fd);

    PASS_TEST();
}


