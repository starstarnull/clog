
#include "test-config-9.h"


// Function Declarations

static struct test* test_manual_level_extra();


// Main test function.

struct unit* unit_config_9() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing Config 9 Options");

    ADD_TEST(unit, test_manual_level_extra());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_level_extra() {

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

    close(fd);
    puts("\n");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_TRACE("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    FILL_LINE_BUF_FROM_STDERR(buf, LINE_BUF_SIZE, LOGLN_DEBUG("MARKER"));
    ASSERT(!*buf && "LOG printed to stderr when configured not to.");

    PASS_TEST();
}


