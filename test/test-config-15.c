
#include "test-config-15.h"
#include <fcntl.h>
#include <stdio.h>


// Function Declarations

static struct test* test_manual_mode_console();


// Main test function.

struct unit* unit_config_15() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 15 Options");

    ADD_TEST(unit, test_manual_mode_console());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("");

    return unit;
}


static struct test* test_manual_mode_console() {

    int fd;
    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);

    // Create log.
    unlink(CLOG_FILE);
    fd = open(CLOG_FILE, O_CREAT | O_TRUNC, 0644);
    close(fd);

    fd = open(CLOG_FILE, O_RDONLY);
    ASSERT(fd != -1 && "Failed to open log file.");
    lseek(fd, 0, SEEK_END);

    // Test CLOG functions.
    TEST_PRINT(CLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_HEX(CLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEX(CLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CLOG_STREAM functions.
    TEST_PRINT(CLOG_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_HEX(CLOG_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CLOGLN_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEX(CLOG_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CLOGLN_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOG_PERROR_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOG_PERRORF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CTLOG functions.
    TEST_PRINT(CTLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CTLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CTLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CTLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGFLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_HEX(CTLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CTLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_HEX(CTLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_HEXLN(CTLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CTLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CTLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CTLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CTLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CTLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CLOG_LEVEL functions.
    TEST_PRINT(CLOG_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_TRACE);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_DEBUG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_EXTRA);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_INFO);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_HEADER);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_SUCCESS);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_MONEY);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_INPUT);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_WARNING);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_WARNING);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_WARNING);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_ERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_ERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_ERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_CRITICAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_CRITICAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_CRITICAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");

    TEST_PRINT(CLOG_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTLN(CLOGLN_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGLN_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTF(CLOGF_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGF_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_PRINTFLN(CLOGFLN_FATAL);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOGFLN_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTLN(CLOG_PERROR_FATAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERROR_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_PRINTFLN(CLOG_PERRORF_FATAL);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CLOG_PERRORF_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CCLOG functions.
    TEST_CPRINT(CCLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTF(CCLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGFLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CHEX(CCLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEX(CCLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTLN(CCLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTFLN(CCLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CCLOG_STREAM functions.
    TEST_CPRINT(CCLOG_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCLOGLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTF(CCLOGF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCLOGFLN_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGFLN_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CHEX(CCLOG_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCLOGLN_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEX(CCLOG_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCLOGLN_WIDE_HEX_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOGLN_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCLOG_PERROR_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTLN(CCLOG_PERROR_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCLOG_PERRORF_STREAM);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTFLN(CCLOG_PERRORF_STREAM);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCLOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test CCTLOG functions.
    TEST_CPRINT(CCTLOG);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCTLOGLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTF(CCTLOGF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCTLOGFLN);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGFLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CHEX(CCTLOG_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCTLOGLN_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "LOG did not print to STDERR.");

    TEST_CHEX(CCTLOG_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CHEXLN(CCTLOGLN_WIDE_HEX);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "LOG did not print to STDERR.");

    TEST_CPRINTLN(CCTLOG_PERROR);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTLN(CCTLOG_PERROR);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    TEST_CPRINTFLN(CCTLOG_PERRORF);
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");

    errno = ENOENT;
    TEST_CPRINTFLN(CCTLOG_PERRORF);
    errno = 0;
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, CCTLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "LOG did not print to STDERR.");
    puts("");


    // Test that flog functions don't log.
    TEST_FLOGPRINT(FLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    // FLOG STREAM functions.
    TEST_FLOGPRINT(FLOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FLOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FLOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FLOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    // FTLOG functions.
    TEST_FLOGPRINT(FTLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FTLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FTLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FTLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FTLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FTLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEX(FTLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGHEXLN(FTLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FTLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FTLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    // FLOG level functions.
    TEST_FLOGPRINT(FLOG_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");

    TEST_FLOGPRINT(FLOG_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTLN(FLOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTF(FLOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    TEST_FLOGPRINTFLN(FLOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    puts("");


    // Test LOG functions.
    TEST_PRINT(LOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_HEX(LOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEXLN(LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEX(LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_HEXLN(LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_PRINTLN(LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    // LOG STREAM functions.
    TEST_PRINT(LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_HEX(LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEXLN(LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEX(LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_HEXLN(LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WIDE_HEX_STREAM(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_PRINTLN(LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_STREAM("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");


    // Test TLOG functions.
    TEST_PRINT(TLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(TLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(TLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(TLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGFLN("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_HEX(TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEXLN(TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_HEX(TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_HEXLN(TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOGLN_WIDE_HEX(&hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_PRINTLN(TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(TLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(TLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, TLOG_PERRORF("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");


    // C_LOG functions.
    TEST_CPRINT(C_LOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTLN(C_LOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTF(C_LOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_LOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGFLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CHEX(C_LOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEXLN(C_LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEX(C_LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CHEXLN(C_LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CPRINTLN(C_LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTLN(C_LOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTFLN(C_LOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");


    // Test C_LOG_STREAM functions.
    TEST_CPRINT(C_LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTLN(C_LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTF(C_LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGFLN_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CHEX(C_LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEXLN(C_LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEX(C_LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CHEXLN(C_LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOGLN_WIDE_HEX_STREAM(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CPRINTLN(C_LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTLN(C_LOG_PERROR_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERROR_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTFLN(C_LOG_PERRORF_STREAM);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_LOG_PERRORF_STREAM(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    // Test C_TLOG functions.
    TEST_CPRINT(C_TLOG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTLN(C_TLOGLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTF(C_TLOGF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_TLOGFLN);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGFLN(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CHEX(C_TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEXLN(C_TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "cafe") && "Print test failed.");

    TEST_CHEX(C_TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CHEXLN(C_TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOGLN_WIDE_HEX(C_RED, &hex, sizeof(hex)););
    ASSERT(strstr(buf, "0xca 0xfe") && "Print test failed.");

    TEST_CPRINTLN(C_TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTLN(C_TLOG_PERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERROR(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_CPRINTFLN(C_TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_CPRINTFLN(C_TLOG_PERRORF);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, C_TLOG_PERRORF(C_RED, "MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    // Test LOG_LEVEL functions.
    TEST_PRINT(LOG_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_TRACE("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_DEBUG("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_EXTRA("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_INFO("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_HEADER("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_SUCCESS("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_MONEY("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_INPUT("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_WARNING);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_WARNING("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_ERROR);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_ERROR("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_CRITICAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_CRITICAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("");

    TEST_PRINT(LOG_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTLN(LOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTF(LOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGF_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    TEST_PRINTFLN(LOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGFLN_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERROR_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_FATAL);
    errno = 0;
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");
    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOG_PERRORF_FATAL("MARKER"););
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    puts("\n");

    close(fd);

    PASS_TEST();
}


