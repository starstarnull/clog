
#include "test-config-13.h"


// Function Declarations

static struct test* test_manual_level_critical();


// Main test function.

struct unit* unit_config_13() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 13 Options");

    ADD_TEST(unit, test_manual_level_critical());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_level_critical() {

    int fd;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    // Create log.
    FLOGLN("Test creation.");

    fd = open(CLOG_FILE, O_RDONLY);
    ASSERT(fd != -1 && "Failed to open log file.");
    lseek(fd, 0, SEEK_END);

    TEST_PRINT(LOG_TRACE);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_DEBUG);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_EXTRA);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_INFO);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_HEADER);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_SUCCESS);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_MONEY);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_INPUT);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_WARNING);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_ERROR);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_CRITICAL);
    PRINT_FILE_LINE(fd, buf);
    TEST_PRINT(LOG_FATAL);
    PRINT_FILE_LINE(fd, buf);
    puts("\n");

    LOGLN_TRACE("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_DEBUG("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_EXTRA("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_INFO("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_HEADER("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_SUCCESS("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_MONEY("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_INPUT("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_WARNING("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    LOGLN_ERROR("MARKER");
    PRINT_FILE_LINE(fd, buf);
    ASSERT(!*buf && "LOG logged when configured not to.");

    close(fd);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_TRACE("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_DEBUG("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_EXTRA("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INFO("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_HEADER("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_SUCCESS("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_MONEY("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_INPUT("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_WARNING("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_ERROR("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    PASS_TEST();
}


