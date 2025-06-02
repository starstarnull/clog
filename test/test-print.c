
#include "test-print.h"


// Function Declarations

static struct test* test_manual_print();
static struct test* test_manual_print_level();


// Main test function.

struct unit* unit_print() {

    struct unit* unit = (struct unit*) malloc(sizeof(*unit));

    unit->name = (char*) __FUNCTION__;
    unit->result = true;
    unit->tests = NULL;
    unit->next = NULL;
    assert(unit);
    UNIT_HEADER("Testing \"print\" Functions");

    ADD_TEST(unit, test_manual_print());
    ADD_TEST(unit, test_manual_print_level());

    REVERSE_LIST(unit->tests);
    PRINT_UNIT_RESULT(unit);
    puts("\n");

    return unit;
}


static struct test* test_manual_print() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINT(PRINT);
    TEST_PRINTLN(PRINTLN);
    TEST_PRINTF(PRINTF);
    TEST_PRINTFLN(PRINTFLN);
    TEST_HEX(PRINT_HEX);
    TEST_HEXLN(PRINTLN_HEX);
    TEST_HEX(PRINT_WIDE_HEX);
    TEST_HEXLN(PRINTLN_WIDE_HEX);
    TEST_PRINTLN(PERROR);
    errno = ENOENT;
    TEST_PRINTLN(PERROR);
    errno = 0;
    TEST_PRINTFLN(PERRORF);
    errno = ENOENT;
    TEST_PRINTFLN(PERRORF);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, PRINTLN("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");

    PASS_TEST();
}


static struct test* test_manual_print_level() {

    int integer = 1234567890;
    char buf[LINE_BUF_SIZE];

    TEST_HEADER(__FUNCTION__);
    
    TEST_PRINT(PRINT_TRACE);
    TEST_PRINTLN(PRINTLN_TRACE);
    TEST_PRINTF(PRINTF_TRACE);
    TEST_PRINTFLN(PRINTFLN_TRACE);
    puts("");

    TEST_PRINT(PRINT_DEBUG);
    TEST_PRINTLN(PRINTLN_DEBUG);
    TEST_PRINTF(PRINTF_DEBUG);
    TEST_PRINTFLN(PRINTFLN_DEBUG);
    puts("");

    TEST_PRINT(PRINT_EXTRA);
    TEST_PRINTLN(PRINTLN_EXTRA);
    TEST_PRINTF(PRINTF_EXTRA);
    TEST_PRINTFLN(PRINTFLN_EXTRA);
    puts("");

    TEST_PRINT(PRINT_INFO);
    TEST_PRINTLN(PRINTLN_INFO);
    TEST_PRINTF(PRINTF_INFO);
    TEST_PRINTFLN(PRINTFLN_INFO);
    puts("");

    TEST_PRINT(PRINT_HEADER);
    TEST_PRINTLN(PRINTLN_HEADER);
    TEST_PRINTF(PRINTF_HEADER);
    TEST_PRINTFLN(PRINTFLN_HEADER);
    puts("");

    TEST_PRINT(PRINT_SUCCESS);
    TEST_PRINTLN(PRINTLN_SUCCESS);
    TEST_PRINTF(PRINTF_SUCCESS);
    TEST_PRINTFLN(PRINTFLN_SUCCESS);
    puts("");

    TEST_PRINT(PRINT_MONEY);
    TEST_PRINTLN(PRINTLN_MONEY);
    TEST_PRINTF(PRINTF_MONEY);
    TEST_PRINTFLN(PRINTFLN_MONEY);
    puts("");

    TEST_PRINT(PRINT_INPUT);
    TEST_PRINTLN(PRINTLN_INPUT);
    TEST_PRINTF(PRINTF_INPUT);
    TEST_PRINTFLN(PRINTFLN_INPUT);
    puts("");

    TEST_PRINT(PRINT_WARNING);
    TEST_PRINTLN(PRINTLN_WARNING);
    TEST_PRINTF(PRINTF_WARNING);
    TEST_PRINTFLN(PRINTFLN_WARNING);
    errno = ENOENT;
    TEST_PRINTLN(PERROR_WARNING);
    errno = ENOENT;
    TEST_PRINTFLN(PERRORF_WARNING);
    errno = 0;
    puts("");

    TEST_PRINT(PRINT_ERROR);
    TEST_PRINTLN(PRINTLN_ERROR);
    TEST_PRINTF(PRINTF_ERROR);
    TEST_PRINTFLN(PRINTFLN_ERROR);
    errno = ENOENT;
    TEST_PRINTLN(PERROR_ERROR);
    errno = ENOENT;
    TEST_PRINTFLN(PERRORF_ERROR);
    errno = 0;
    puts("");

    TEST_PRINT(PRINT_CRITICAL);
    TEST_PRINTLN(PRINTLN_CRITICAL);
    TEST_PRINTF(PRINTF_CRITICAL);
    TEST_PRINTFLN(PRINTFLN_CRITICAL);
    errno = ENOENT;
    TEST_PRINTLN(PERROR_CRITICAL);
    errno = ENOENT;
    TEST_PRINTFLN(PERRORF_CRITICAL);
    errno = 0;
    puts("");

    TEST_PRINT(PRINT_FATAL);
    TEST_PRINTLN(PRINTLN_FATAL);
    TEST_PRINTF(PRINTF_FATAL);
    TEST_PRINTFLN(PRINTFLN_FATAL);
    errno = ENOENT;
    TEST_PRINTLN(PERROR_FATAL);
    errno = ENOENT;
    TEST_PRINTFLN(PERRORF_FATAL);
    errno = 0;
    puts("\n");

    FILL_LINE_BUF_FROM_STDOUT(
        buf, LINE_BUF_SIZE, PRINTLN_TRACE("MARKER");
    );
    ASSERT(strstr(buf, "MARKER\n") && "Print test failed.");
    ASSERT(strstr(buf, "TRACE") && "Trace symbol not found.");

    PASS_TEST();
}


