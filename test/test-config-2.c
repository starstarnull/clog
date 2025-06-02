
#include "test-config-2.h"


// Function Declarations

static struct test* test_manual_syms_none();
static struct test* test_manual_mode_file();
static struct test* test_manual_file();
static struct test* test_manual_disable_timestamps();
static struct test* test_manual_disable_tracing();


// Main test function.

struct unit* unit_config_2() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 2 Options");

    ADD_TEST(unit, test_manual_syms_none());
    ADD_TEST(unit, test_manual_mode_file());
    ADD_TEST(unit, test_manual_file());
    ADD_TEST(unit, test_manual_disable_timestamps());
    ADD_TEST(unit, test_manual_disable_tracing());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_syms_none() {

    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINTLN(CLOGLN_TRACE);
    TEST_PRINTLN(CLOGLN_DEBUG);
    TEST_PRINTLN(CLOGLN_EXTRA);
    TEST_PRINTLN(CLOGLN_INFO);
    TEST_PRINTLN(CLOGLN_HEADER);
    TEST_PRINTLN(CLOGLN_SUCCESS);
    TEST_PRINTLN(CLOGLN_MONEY);
    TEST_PRINTLN(CLOGLN_INPUT);
    TEST_PRINTLN(CLOGLN_WARNING);
    TEST_PRINTLN(CLOGLN_ERROR);
    TEST_PRINTLN(CLOGLN_CRITICAL);
    TEST_PRINTLN(CLOGLN_FATAL);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_TRACE("This is a test");
    );
    ASSERT(!strstr(buf, "[TRACE]") && "Tracing symbol was found.");

    PASS_TEST();
}


static struct test* test_manual_mode_file() {

    int fd;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    // Create log.
    FLOGLN("Test creation.");

    fd = open(CLOG_FILE, O_RDONLY);
    ASSERT(fd != -1 && "Failed to open log file.");
    lseek(fd, 0, SEEK_END);

    #undef LOG_FILENAME
    #define LOG_FILENAME CLOG_FILE

    TEST_PRINT(LOGLN_TRACE);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_HEADER);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_MONEY);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_INPUT);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_WARNING);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_ERROR);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOGLN_FATAL);
    PRINT_FILE_LINE(fd, buf);
    puts("");

    LOGLN("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(strstr(buf, "MARKER\n") && "Log test failed.");
    close(fd);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    PASS_TEST();
}


static struct test* test_manual_file() {

    int fd;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    fd = open(CLOG_FILE, O_RDONLY);
    ASSERT(fd != -1 && "Failed to open log file.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOGLN_INFO);
    PRINT_FILE_LINE(fd, buf);
    puts("\n");

    ASSERT(!strcmp(CLOG_FILE, "clog.log") && "Filename does not match.");

    PASS_TEST();
}


static struct test* test_manual_disable_timestamps() {

    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINTLN(CLOGLN_INFO);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_INFO("This is a test");
    );
    ASSERT(!strstr(buf, "2025") && "Timestamp found.");

    PASS_TEST();
}


static struct test* test_manual_disable_tracing() {

    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINTLN(CLOGLN_TRACE);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(
        buf, LINE_BUF_SIZE, CLOGLN_TRACE("This is a test");
    );
    ASSERT(!strstr(buf, "2025") && "Timestamp found.");
    ASSERT(!strstr(buf, (char*) __FUNCTION__) && "Trace function found.");

    PASS_TEST();
}


