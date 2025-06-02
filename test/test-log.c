
#include "test-log.h"


// Function Declarations

static struct test* test_manual_log();
static struct test* test_manual_log_stream();
static struct test* test_manual_tlog();
static struct test* test_manual_c_log();
static struct test* test_manual_c_log_stream();
static struct test* test_manual_c_tlog();
static struct test* test_manual_log_level();


// Main test function.

struct unit* unit_log() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"log\" Functions");

    ADD_TEST(unit, test_manual_log());
    ADD_TEST(unit, test_manual_log_stream());
    ADD_TEST(unit, test_manual_tlog());
    ADD_TEST(unit, test_manual_c_log());
    ADD_TEST(unit, test_manual_c_log_stream());
    ADD_TEST(unit, test_manual_c_tlog());
    ADD_TEST(unit, test_manual_log_level());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_log() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    // Need to delete log file.
    unlink(LOG_FILENAME);
    LOGLN("Test creation.");

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(LOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_PRINTFLN(LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    LOGLN("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, LOGLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");

    PASS_TEST();
}


static struct test* test_manual_log_stream() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_PRINTFLN(LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    LOGLN_STREAM("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, LOGLN_STREAM("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");

    PASS_TEST();
}


static struct test* test_manual_tlog() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(TLOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(TLOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(TLOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(TLOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEX(TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_HEXLN(TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_PRINTFLN(TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    TLOGLN("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, TLOGLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");

    PASS_TEST();
}


static struct test* test_manual_c_log() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_LOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTF(C_LOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTFLN(C_LOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_LOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_LOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_LOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_LOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTLN(C_LOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_CPRINTFLN(C_LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTFLN(C_LOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    C_LOGLN(C_RED, "MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(!strstr(buf, C_RED) && "RED found in log.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, C_LOGLN(C_RED, "MARKER");
    );
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, C_RED) && "RED not found in log.");

    PASS_TEST();
}


static struct test* test_manual_c_log_stream() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_LOG_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_LOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTF(C_LOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTFLN(C_LOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_LOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_LOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_LOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_LOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTLN(C_LOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_CPRINTFLN(C_LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTFLN(C_LOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    C_LOGLN_STREAM(C_RED, "MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER") && "Log test failed.");
    ASSERT(!strstr(buf, "2025") && "Time stamp year found.");
    ASSERT(!strstr(buf, C_RED) && "RED found in log.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, C_LOGLN_STREAM(C_RED, "MARKER");
    );
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(!strstr(buf, "2025") && "Time stamp year found.");
    ASSERT(strstr(buf, C_RED) && "RED not found in log.");

    PASS_TEST();
}


static struct test* test_manual_c_tlog() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_CPRINT(C_TLOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_TLOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTF(C_TLOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTFLN(C_TLOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_TLOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_TLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEX(C_TLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CHEXLN(C_TLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_CPRINTLN(C_TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTLN(C_TLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_CPRINTFLN(C_TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_CPRINTFLN(C_TLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    C_TLOGLN(C_RED, "MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(!strstr(buf, C_RED) && "RED found in log.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, C_TLOGLN(C_RED, "MARKER");
    );
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, C_RED) && "RED not found in log.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");

    PASS_TEST();
}


static struct test* test_manual_log_level() {

    int integer = 1234567890, fd = 0;
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_WARNING);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_WARNING);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_ERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_ERROR);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_PRINT(LOG_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTLN(LOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTF(LOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_PRINTFLN(LOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTLN(LOG_PERROR_FATAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_PRINTFLN(LOG_PERRORF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;
    puts("");

    LOGLN_TRACE("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    ASSERT(!strstr(buf, "\x1b") && "Terminal code found in log.");
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, TLOGLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    ASSERT(strstr(buf, "\x1b") && "Terminal code not found in log.");

    PASS_TEST();
}


