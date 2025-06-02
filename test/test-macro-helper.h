
#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>


#define COLOR_MACRO_TEST(macro) \
    printf( \
        "%sTest `%s` (%s)%*c:%s %s This is a color test." RESET "\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        36 - ((int) strlen(#macro) + (int) strlen(STR(macro))), \
        ' ', \
        RESET, \
        macro \
    );

#define COLOR_MACRO_TEST_LINE(macro) \
    printf( \
        "%sTest `%s` (%s):%s\n  %s This is a color test." RESET "\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        RESET, \
        macro \
    );

#define SYMBOL_MACRO_TEST(macro) \
    printf( \
        "%sTest `%s` (%s)%*c:%s %s This is a test." RESET "\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        36 - ((int) strlen(#macro) + (int) strlen(STR(macro))), \
        ' ', \
        RESET, \
        macro \
    );

#define CONSTANT_INT_TEST(macro) \
    printf( \
        "%sTest `%s` (%s)%*c:%s Value: %d\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        36 - ((int) strlen(#macro) + (int) strlen(STR(macro))), \
        ' ', \
        RESET, \
        macro \
    );

#define CONSTANT_STR_TEST(macro) \
    printf( \
        "%sTest `%s` (%s):%s\n  Value: '%s'\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        RESET, \
        macro \
    );

#define IS_DEFINED(macro)  strcmp(#macro, STR(macro))

#define CONSTANT_DEFINED_TEST(macro, is_true) \
    printf( \
        "%sTest `%s` (%s):%s\n  Value: %s\n", \
        BLUE, \
        #macro, \
        STR(macro), \
        RESET, \
        is_true ? "DEFINED" : "NOT DEFINED" \
    );


#define TEST_FPRINT(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, "This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_FPRINTLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, "This is a `" #macro_fn "` test"); \
}

#define TEST_FPRINTF(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, "This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_FPRINTFLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, "This is a `" #macro_fn "` test: %d", integer); \
}

#define TEST_FHEX(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, &hex, sizeof(hex)); \
    puts(""); \
}

#define TEST_FHEXLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(stdout, &hex, sizeof(hex)); \
}


#define TEST_CFPRINT(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, "This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_CFPRINTLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, "This is a `" #macro_fn "` test"); \
}

#define TEST_CFPRINTF(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, "This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_CFPRINTFLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, "This is a `" #macro_fn "` test: %d", integer); \
}

#define TEST_CFHEX(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, &hex, sizeof(hex)); \
    puts(""); \
}

#define TEST_CFHEXLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, stdout, &hex, sizeof(hex)); \
}


#define TEST_PRINT(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_PRINTLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test"); \
}

#define TEST_PRINTF(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_PRINTFLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test: %d", integer); \
}

#define TEST_HEX(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(&hex, sizeof(hex)); \
    puts(""); \
}

#define TEST_HEXLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(&hex, sizeof(hex)); \
}


#define TEST_CPRINT(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, "This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_CPRINTLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, "This is a `" #macro_fn "` test"); \
}

#define TEST_CPRINTF(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, "This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_CPRINTFLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, "This is a `" #macro_fn "` test: %d", integer); \
}

#define TEST_CHEX(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, &hex, sizeof(hex)); \
    puts(""); \
}

#define TEST_CHEXLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(C_RED, &hex, sizeof(hex)); \
}


#define TEST_FLOGPRINT(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_FLOGPRINTLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test"); \
    puts(""); \
}

#define TEST_FLOGPRINTF(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_FLOGPRINTFLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn("This is a `" #macro_fn "` test: %d", integer); \
    puts(""); \
}

#define TEST_FLOGHEX(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(&hex, sizeof(hex)); \
    puts(""); \
}

#define TEST_FLOGHEXLN(macro_fn) { \
    printf( \
        BLUE "Test `%s`%*c: " RESET, \
        #macro_fn, \
        28 - (int) strlen(#macro_fn), \
        ' ' \
    ); \
    fflush(stdout); \
    macro_fn(&hex, sizeof(hex)); \
    puts(""); \
}


#define LOG_FILENAME \
    strchr(__FILE__, '/') ? strrchr(__FILE__".log", '/') + 1 : __FILE__".log"

#define LINE_BUF_SIZE   1024

#define PRINT_FILE_LINE(fd, buf) { \
    bzero(buf, LINE_BUF_SIZE); \
    read(fd, buf, LINE_BUF_SIZE); \
    printf( \
        "LOG FILE '%s'%*c: %s", \
        LOG_FILENAME, \
        24 - (int) strlen(LOG_FILENAME), \
        ' ', \
        buf \
    ); \
    if (buf[strlen(buf) - 1] != '\n') \
        puts(""); \
}


