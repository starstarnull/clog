
#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <signal.h>
#include <stdlib.h>


#define STR(str)    #str
#define XSTR(str)   STR(str)
#define QSTR(str)   STR(#str)
#define QXSTR(str)  XSTR(str)
#define TSTR(str)   "`" #str "`"

#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define GREEN       "\x1b[32m"
#define RED         "\x1b[91m"
#define YELLOW      "\x1b[93m"
#define BLUE        "\x1b[94m"
#define MAGENTA     "\x1b[95m"
#define CYAN        "\x1b[96m"

#define UNIT_HEADER(str) \
    printf( \
        BOLD YELLOW "%.*s %s %.*s%s" RESET "\n\n", \
        (int)(80 - strlen(str)- 2)/2, \
        "========================================================", \
        str, \
        (int)(80 - strlen(str)- 2)/2, \
        "========================================================", \
        strlen(str) % 2 ? "=" : "" \
    )

#define TEST_HEADER(str) printf(YELLOW "Testing %s...\n\n" RESET, str)

struct test {
    struct test* next;
    char* unit_name;
    char* name;
    bool result;
    char* test_str;
    size_t line;
};

struct unit {
    struct unit* next;
    char* name;
    bool result;
    struct test* tests;
};


#define PRINT_TEST_RESULT(_test) { \
    printf( \
        BLUE "%s:" MAGENTA "%s" BLUE " Test status: %.*s%s\n" RESET, \
        _test->unit_name, \
        _test->name, \
        56 - (int) strlen(_test->unit_name) - (int) strlen(_test->name), \
        ".........................................................", \
        _test->result ? GREEN "PASS" : BOLD RED "FAIL" \
    ); \
    if (!_test->result) \
        printf( \
            BOLD RED "\n        FAILURE (%s:%lu): " RESET RED "`%s`\n\n" RESET, \
            _test->name, \
            _test->line, \
            _test->test_str \
        ); \
}

#define PASS_TEST() { \
    struct test* _test_ = (struct test*) malloc(sizeof(*_test_)); \
    assert(_test_); \
    _test_->unit_name = __FILE__; \
    _test_->name = (char*) __FUNCTION__; \
    _test_->result = true; \
    _test_->test_str = NULL; \
    _test_->line = 0; \
    _test_->next = NULL; \
    PRINT_TEST_RESULT(_test_); \
    return _test_; \
}

#define FAIL_TEST(_assert_statement) { \
    struct test* _test_ = (struct test*) malloc(sizeof(*_test_)); \
    assert(_test_); \
    _test_->unit_name = __FILE__; \
    _test_->name = (char*) __FUNCTION__; \
    _test_->result = false; \
    _test_->test_str = STR(_assert_statement); \
    _test_->line = __LINE__; \
    _test_->next = NULL; \
    PRINT_TEST_RESULT(_test_); \
    return _test_; \
}

#define ASSERT(_assert_statement) \
    if (!(_assert_statement)) { \
        FAIL_TEST(_assert_statement); \
    }

#define PRINT_UNIT_RESULT(_unit) { \
    _unit->result = true; \
    struct test* _test_ = _unit->tests; \
    size_t _test_count_ = 0; \
    while (_test_) { \
        ++_test_count_; \
\
        if (!_test_->result) {\
            _unit->result = false; \
        } \
        _test_ = _test_->next; \
    } \
    printf( \
        BOLD CYAN "%s Unit Test Status (%lu tests): %s\n" RESET, \
        _unit->name, \
        _test_count_, \
        _unit->result ? GREEN "PASS" : RED "FAIL" \
    ); \
}

#define DID_UNITS_PASS(_units, _ret) { \
    struct unit* _unit_ = _units; \
    while (_unit_) { \
        if (!_unit_->result) \
            _ret = false; \
\
        _unit_ = _unit_->next; \
    } \
}

#define PRINT_UNITS_RESULTS(_units) { \
    puts("\n"); \
    UNIT_HEADER("UNIT TEST RESULTS"); \
    struct unit* _unit_ = _units; \
    size_t _unit_count_ = 0; \
    size_t _tests_count_ = 0; \
    bool _pass_ = true; \
\
    while (_unit_) { \
        ++_unit_count_; \
        PRINT_UNIT_RESULT(_unit_); \
        struct test* _test_ = _unit_->tests; \
        while (_test_) { \
            ++_tests_count_; \
            printf("    "); \
            PRINT_TEST_RESULT(_test_); \
            _test_ = _test_->next; \
        } \
        puts(""); \
        _unit_ = _unit_->next; \
    } \
    printf("Number of Units: %lu\n", _unit_count_); \
    printf("Number of Tests: %lu\n", _tests_count_); \
    DID_UNITS_PASS(_units, _pass_); \
    printf( \
        BOLD "\n%s\n" RESET, \
        _pass_ ? GREEN "All tests PASSED!" : RED "Tests have FAILURES!" \
    ); \
}

#define ADD_TEST(_unit, _test) { \
    struct test* _test_ = _test; \
    if (_unit->tests) \
        _test_->next = _unit->tests; \
\
    _unit->tests = _test_; \
}

#define ADD_UNIT(_units, _unit) { \
    struct unit* _unit_ = _unit; \
    if (_units) \
        _unit_->next = _units; \
\
    _units = _unit_; \
}


#define REVERSE_LIST(_head) { \
    if (_head) { \
        struct unit* _cur_ = (void*) _head; \
        struct unit* _prev_ = NULL; \
        struct unit* _next_ = (void*) _head->next; \
\
        while (_next_) { \
            _cur_->next = _prev_; \
            _prev_ = _cur_; \
            _cur_ = _next_; \
            _next_ = _next_->next; \
        } \
        _cur_->next = _prev_; \
        _head = (void*) _cur_; \
    } \
}


#define FILL_LINE_BUF_FROM_STDOUT(_buf, _size, _calls) { \
    FILE* _fp_ = tmpfile(), * _oldfp_ = stdout; \
    assert(_fp_ && "`tmpfile` failed."); \
    bzero(buf, _size); \
    stdout = _fp_; \
    _calls; \
    stdout = _oldfp_; \
    rewind(_fp_); \
    fread(_buf, 1, _size, _fp_); \
    fclose(_fp_); \
}


#define FILL_LINE_BUF_FROM_STDERR(_buf, _size, _calls) { \
    FILE* _fp_ = tmpfile(), * _oldfp_ = stderr; \
    assert(_fp_ && "`tmpfile` failed."); \
    bzero(buf, _size); \
    stderr = _fp_; \
    _calls; \
    stderr = _oldfp_; \
    rewind(_fp_); \
    fread(_buf, 1, _size, _fp_); \
    fclose(_fp_); \
}


static void abort_handler(int signum) {

    fprintf(stderr, "\n" BOLD RED "*** Test FAILED. Aborted. ***\n\n" RESET);

    exit(EXIT_FAILURE);
}


static struct sigaction __attribute__((__unused__)) sa = { {abort_handler} };


