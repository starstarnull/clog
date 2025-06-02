
#include "test-flog.h"


// Function Declarations

static struct test* test_manual_flog();
static struct test* test_manual_flog_stream();
static struct test* test_manual_ftlog();
static struct test* test_manual_flog_level();


// Main test function.

struct unit* unit_flog() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"flog\" Functions");

    ADD_TEST(unit, test_manual_flog());
    ADD_TEST(unit, test_manual_flog_stream());
    ADD_TEST(unit, test_manual_ftlog());
    ADD_TEST(unit, test_manual_flog_level());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_flog() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    // Test log file creation.
    unlink(LOG_FILENAME);
    FLOGLN("Test creation.");

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_FLOGPRINT(FLOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FLOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    FLOGLN("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    puts("\n");

    PASS_TEST();
}


static struct test* test_manual_flog_stream() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_FLOGPRINT(FLOG_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FLOG_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FLOGLN_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FLOG_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FLOGLN_WIDE_HEX_STREAM);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_STREAM);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    FLOGLN_STREAM("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!strcmp(buf, "MARKER\n") && "Log test failed.");
    puts("\n");

    PASS_TEST();
}


static struct test* test_manual_ftlog() {

    int integer = 1234567890, fd = 0;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_FLOGPRINT(FTLOG);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FTLOGLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FTLOGF);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FTLOGFLN);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FTLOG_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FTLOGLN_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEX(FTLOG_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGHEXLN(FTLOGLN_WIDE_HEX);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FTLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FTLOG_PERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = 0;
    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FTLOG_PERRORF);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    FTLOGLN("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    puts("\n");

    PASS_TEST();
}


static struct test* test_manual_flog_level() {

    int integer = 1234567890, fd = 0;
    char buf[LINE_BUF_SIZE];
    
    TEST_HEADER(__FUNCTION__);

    fd = open(LOG_FILENAME, O_RDONLY);
    ASSERT(fd);
    lseek(fd, 0, SEEK_END);

    TEST_FLOGPRINT(FLOG_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_TRACE);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_TRACE);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_INFO);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_INFO);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_HEADER);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_HEADER);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_MONEY);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_MONEY);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_INPUT);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_INPUT);
    PRINT_FILE_LINE(fd, buf);

    puts("");

    TEST_FLOGPRINT(FLOG_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_WARNING);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_WARNING);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_WARNING);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_WARNING);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    puts("");

    TEST_FLOGPRINT(FLOG_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_ERROR);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_ERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_ERROR);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_ERROR);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    puts("");

    TEST_FLOGPRINT(FLOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_CRITICAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    puts("");

    TEST_FLOGPRINT(FLOG_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTLN(FLOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTF(FLOGF_FATAL);
    PRINT_FILE_LINE(fd, buf);

    TEST_FLOGPRINTFLN(FLOGFLN_FATAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTLN(FLOG_PERROR_FATAL);
    PRINT_FILE_LINE(fd, buf);

    errno = ENOENT;
    TEST_FLOGPRINTFLN(FLOG_PERRORF_FATAL);
    PRINT_FILE_LINE(fd, buf);
    errno = 0;

    FLOGLN_TRACE("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "2025") && "Time stamp year not found.");
    ASSERT(strstr(buf, (char*) __FUNCTION__) && "Trace function not found.");
    ASSERT(strstr(buf, "TRACE") && "Trace symbol not found.");
    puts("\n");

    PASS_TEST();
}


