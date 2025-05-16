
// Includes.

#include <byteswap.h>

#include "clog-config.h"
#include "clog.h"

#include "clog-obj-1.h"
#include "clog-obj-2.h"


// Function declarations.

int test_fprint();
int test_cfprint();
int test_print();
int test_cprint();
int test_clog();
int test_flog();
int test_log();
int test_log_custom();


// Functions.

/**
 * @brief   Main function to initiate tests.
 *
 * @return  Return 0.
 */
int main() {

    // Variables.
    char* header = "Testing clog header file";
    char* padding = "========================================================";
    unsigned long header_len = strlen(header);


    function1();
    function2();

    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );


    header = "Testing fprint functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_fprint();


    header = "Testing cfprint functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_cfprint();


    header = "Testing print functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_print();
    

    header = "Testing cprint functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_cprint();


    header = "Testing clog functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_clog();


    header = "Testing flog functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_flog();


    header = "Testing log functions";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_log();

    header = "Testing log customizations";
    printf(
        "%.*s %s %.*s\n\n", 
        (int)(80 - header_len - 2)/2, 
        padding, 
        header, 
        (int)(80 - header_len - 2)/2, 
        padding
    );

    test_log_custom();

    return 0;
}


/**
 * @brief   Test the "fprint" series of function by printing to console for 
 *          review.
 *
 * @return  Return 0.
 */
int test_fprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'fprint' functions...\n\n");

    FPRINT(stdout, "FPRINT test.");
    printf("\n");

    FPRINTLN(stdout, "FPRINTLN test.");

    FPRINTF(stdout, "FPRINTF test integer: %d.", integer);
    printf("\n");

    FPRINTFLN(stdout, "FPRINTFLN test integer: %d.", integer);
    printf("\n");


    FPRINTF(stdout, "FPRINT_HEX test hex: %llu: ", hex);
    FPRINT_HEX(stdout, &hex, sizeof(hex));
    printf("\n");

    FPRINTF(stdout, "FPRINTLN_HEX test hex: %llu: ", hex);
    FPRINTLN_HEX(stdout, &hex, sizeof(hex));

    FPRINTF(stdout, "FPRINT_WIDE_HEX test wide hex: %llu: ", hex);
    FPRINT_WIDE_HEX(stdout, &hex, sizeof(hex));
    printf("\n");

    FPRINTF(stdout, "FPRINTLN_WIDE_HEX test wide hex: %llu: ", hex);
    FPRINTLN_WIDE_HEX(stdout, &hex, sizeof(hex));
    printf("\n");


    FPERROR(stdout, "FPERROR test");
    errno = ENOENT;
    FPERROR(stdout, "FPERROR test");
    errno = 0;

    FPERRORF(stdout, "FPERRORF test integer: %d", integer);
    errno = ENOENT;
    FPERRORF(stdout, "FPERRORF test integer: %d", integer);
    errno = 0;
    printf("\n");


    printf("[*] Testing in loop without brackets...\n\n");

    for (int i = 0; i < 4; ++i)
        FPRINT(stdout, "FPRINT loop test.");

    printf("\n");
    printf("\n");


    for (int i = 0; i < 4; ++i)
        FPRINTLN(stdout, "FPRINTLN loop test.");

    printf("\n");


    for (int i = 0; i < 4; ++i)
        FPRINTF(stdout, "FPRINTF loop test: %d.", integer);

    printf("\n");
    printf("\n");


    for (int i = 0; i < 4; ++i)
        FPRINTFLN(stdout, "FPRINTFLN loop test: %d.", integer);

    printf("\n");


    FPRINTF(stdout, "FPRINT_HEX loop test hex: %llu: ", hex);

    for (int i = 0; i < 4; ++i)
        FPRINT_HEX(stdout, &hex, sizeof(hex));

    printf("\n");
    printf("\n");


    FPRINTF(stdout, "FPRINTLN_HEX loop test hex: %llu: ", hex);

    for (int i = 0; i < 4; ++i)
        FPRINTLN_HEX(stdout, &hex, sizeof(hex));

    printf("\n");


    FPRINTF(stdout, "FPRINT_WIDE_HEX loop test wide hex: %llu: ", hex);

    for (int i = 0; i < 4; ++i)
        FPRINT_WIDE_HEX(stdout, &hex, sizeof(hex));

    printf("\n");
    printf("\n");


    FPRINTF(stdout, "FPRINTLN_WIDE_HEX loop test wide hex: %llu: ", hex);

    for (int i = 0; i < 4; ++i)
        FPRINTLN_WIDE_HEX(stdout, &hex, sizeof(hex));

    printf("\n");


    for (int i = 0; i < 4; ++i)
        FPERROR(stdout, "FPERROR loop test");

    printf("\n");

    for (int i = 0; i < 4; ++i)
        FPERRORF(stdout, "FPERRORF loop test integer: %d", integer);

    printf("\n");

    return 0;
} 


/**
 * @brief   Test the "cfprint" series of function by printing to console for 
 *          review.
 *
 * @return  Return 0.
 */
int test_cfprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'cfprint' functions...\n\n");

    CFPRINT(C_RED, stdout, "CFPRINT test.");
    printf("\n");

    CFPRINTLN(C_RED, stdout, "CFPRINTLN test.");

    CFPRINTF(C_RED, stdout, "CFPRINTF test integer: %d.", integer);
    printf("\n");

    CFPRINTFLN(C_RED, stdout, "CFPRINTFLN test integer: %d.", integer);
    printf("\n");


    CFPRINTF(C_RED, stdout, "CFPRINT_HEX test hex: %llu: ", hex);
    CFPRINT_HEX(C_RED, stdout, &hex, sizeof(hex));
    printf("\n");

    CFPRINTF(C_RED, stdout, "CFPRINTLN_HEX test hex: %llu: ", hex);
    CFPRINTLN_HEX(C_RED, stdout, &hex, sizeof(hex));

    CFPRINTF(C_RED, stdout, "CFPRINT_WIDE_HEX test wide hex: %llu: ", hex);
    CFPRINT_WIDE_HEX(C_RED, stdout, &hex, sizeof(hex));
    printf("\n");

    CFPRINTF(C_RED, stdout, "CFPRINTLN_WIDE_HEX test wide hex: %llu: ", hex);
    CFPRINTLN_WIDE_HEX(C_RED, stdout, &hex, sizeof(hex));
    printf("\n");


    CFPERROR(C_RED, stdout, "CFPERROR test");
    errno = ENOENT;
    CFPERROR(C_RED, stdout, "CFPERROR test");
    errno = 0;

    CFPERRORF(C_RED, stdout, "CFPERRORF test integer: %d", integer);
    errno = ENOENT;
    CFPERRORF(C_RED, stdout, "CFPERRORF test integer: %d", integer);
    errno = 0;
    printf("\n");


    printf("[*] Testing standard colors...\n\n");

    CFPRINTLN(C_BLACK, stdout, "CFPRINTLN C_BLACK test.");
    CFPRINTLN(C_RED, stdout, "CFPRINTLN C_RED test.");
    CFPRINTLN(C_GREEN, stdout, "CFPRINTLN C_GREEN test.");
    CFPRINTLN(C_YELLOW, stdout, "CFPRINTLN C_YELLOW test.");
    CFPRINTLN(C_BLUE, stdout, "CFPRINTLN C_BLUE test.");
    CFPRINTLN(C_MAGENTA, stdout, "CFPRINTLN C_MAGENTA test.");
    CFPRINTLN(C_CYAN, stdout, "CFPRINTLN C_CYAN test.");
    CFPRINTLN(C_WHITE, stdout, "CFPRINTLN C_WHITE test.");
    printf("\n");


    printf("[*] Testing bright standard colors...\n\n");

    CFPRINTLN(C_BR_BLACK, stdout, "CFPRINTLN C_BR_BLACK test.");
    CFPRINTLN(C_BR_RED, stdout, "CFPRINTLN C_BR_RED test.");
    CFPRINTLN(C_BR_GREEN, stdout, "CFPRINTLN C_BR_GREEN test.");
    CFPRINTLN(C_BR_YELLOW, stdout, "CFPRINTLN C_BR_YELLOW test.");
    CFPRINTLN(C_BR_BLUE, stdout, "CFPRINTLN C_BR_BLUE test.");
    CFPRINTLN(C_BR_MAGENTA, stdout, "CFPRINTLN C_BR_MAGENTA test.");
    CFPRINTLN(C_BR_CYAN, stdout, "CFPRINTLN C_BR_CYAN test.");
    CFPRINTLN(C_BR_WHITE, stdout, "CFPRINTLN C_BR_WHITE test.");
    printf("\n");


    printf("[*] Testing standard background colors...\n\n");

    CFPRINTLN(C_B_BLACK, stdout, "CFPRINTLN C_B_BLACK test.");
    CFPRINTLN(C_B_RED, stdout, "CFPRINTLN C_B_RED test.");
    CFPRINTLN(C_B_GREEN, stdout, "CFPRINTLN C_B_GREEN test.");
    CFPRINTLN(C_B_YELLOW, stdout, "CFPRINTLN C_B_YELLOW test.");
    CFPRINTLN(C_B_BLUE, stdout, "CFPRINTLN C_B_BLUE test.");
    CFPRINTLN(C_B_MAGENTA, stdout, "CFPRINTLN C_B_MAGENTA test.");
    CFPRINTLN(C_B_CYAN, stdout, "CFPRINTLN C_B_CYAN test.");
    CFPRINTLN(C_B_WHITE, stdout, "CFPRINTLN C_B_WHITE test.");
    printf("\n");


    printf("[*] Testing bright standard background colors...\n\n");

    CFPRINTLN(C_B_BR_BLACK, stdout, "CFPRINTLN C_B_BR_BLACK test.");
    CFPRINTLN(C_B_BR_RED, stdout, "CFPRINTLN C_B_BR_RED test.");
    CFPRINTLN(C_B_BR_GREEN, stdout, "CFPRINTLN C_B_BR_GREEN test.");
    CFPRINTLN(C_B_BR_YELLOW, stdout, "CFPRINTLN C_B_BR_YELLOW test.");
    CFPRINTLN(C_B_BR_BLUE, stdout, "CFPRINTLN C_B_BR_BLUE test.");
    CFPRINTLN(C_B_BR_MAGENTA, stdout, "CFPRINTLN C_B_BR_MAGENTA test.");
    CFPRINTLN(C_B_BR_CYAN, stdout, "CFPRINTLN C_B_BR_CYAN test.");
    CFPRINTLN(C_B_BR_WHITE, stdout, "CFPRINTLN C_B_BR_WHITE test.");
    printf("\n");


    printf("[*] Testing default colors...\n\n");

    CFPRINTLN(C_BLACK, stdout, "CFPRINTLN C_BLACK test.");
    CFPRINTLN(C_RED, stdout, "CFPRINTLN C_RED test.");
    CFPRINTLN(C_GREEN, stdout, "CFPRINTLN C_GREEN test.");
    CFPRINTLN(C_YELLOW, stdout, "CFPRINTLN C_YELLOW test.");
    CFPRINTLN(C_BLUE, stdout, "CFPRINTLN C_BLUE test.");
    CFPRINTLN(C_MAGENTA, stdout, "CFPRINTLN C_MAGENTA test.");
    CFPRINTLN(C_CYAN, stdout, "CFPRINTLN C_CYAN test.");
    CFPRINTLN(C_WHITE, stdout, "CFPRINTLN C_WHITE test.");
    printf("\n");


    printf("[*] Testing default background colors...\n\n");

    CFPRINTLN(C_B_BLACK, stdout, "CFPRINTLN C_B_BLACK test.");
    CFPRINTLN(C_B_RED, stdout, "CFPRINTLN C_B_RED test.");
    CFPRINTLN(C_B_GREEN, stdout, "CFPRINTLN C_B_GREEN test.");
    CFPRINTLN(C_B_YELLOW, stdout, "CFPRINTLN C_B_YELLOW test.");
    CFPRINTLN(C_B_BLUE, stdout, "CFPRINTLN C_B_BLUE test.");
    CFPRINTLN(C_B_MAGENTA, stdout, "CFPRINTLN C_B_MAGENTA test.");
    CFPRINTLN(C_B_CYAN, stdout, "CFPRINTLN C_B_CYAN test.");
    CFPRINTLN(C_B_WHITE, stdout, "CFPRINTLN C_B_WHITE test.");
    printf("\n");


    printf("[*] Testing 8-bit colors...\n\n");

    CFPRINTLN(C_8BIT(0), stdout, "CFPRINTLN C_8BIT(0) test.");
    CFPRINTLN(C_8BIT(1), stdout, "CFPRINTLN C_8BIT(1) test.");
    CFPRINTLN(C_8BIT(2), stdout, "CFPRINTLN C_8BIT(2) test.");
    CFPRINTLN(C_8BIT(3), stdout, "CFPRINTLN C_8BIT(3) test.");
    CFPRINTLN(C_8BIT(4), stdout, "CFPRINTLN C_8BIT(4) test.");
    CFPRINTLN(C_8BIT(5), stdout, "CFPRINTLN C_8BIT(5) test.");
    CFPRINTLN(C_8BIT(6), stdout, "CFPRINTLN C_8BIT(6) test.");
    CFPRINTLN(C_8BIT(7), stdout, "CFPRINTLN C_8BIT(7) test.");
    CFPRINTLN(C_8BIT(8), stdout, "CFPRINTLN C_8BIT(8) test.");
    CFPRINTLN(C_8BIT(9), stdout, "CFPRINTLN C_8BIT(9) test.");
    CFPRINTLN(C_8BIT(10), stdout, "CFPRINTLN C_8BIT(10) test.");
    CFPRINTLN(C_8BIT(11), stdout, "CFPRINTLN C_8BIT(11) test.");
    CFPRINTLN(C_8BIT(12), stdout, "CFPRINTLN C_8BIT(12) test.");
    CFPRINTLN(C_8BIT(13), stdout, "CFPRINTLN C_8BIT(13) test.");
    CFPRINTLN(C_8BIT(14), stdout, "CFPRINTLN C_8BIT(14) test.");
    CFPRINTLN(C_8BIT(15), stdout, "CFPRINTLN C_8BIT(15) test.");
    CFPRINTLN(C_8BIT(16), stdout, "CFPRINTLN C_8BIT(16) test.");
    CFPRINTLN(C_8BIT(17), stdout, "CFPRINTLN C_8BIT(17) test.");
    CFPRINTLN(C_8BIT(18), stdout, "CFPRINTLN C_8BIT(18) test.");
    CFPRINTLN(C_8BIT(19), stdout, "CFPRINTLN C_8BIT(19) test.");
    CFPRINTLN(C_8BIT(20), stdout, "CFPRINTLN C_8BIT(20) test.");
    CFPRINTLN(C_8BIT(21), stdout, "CFPRINTLN C_8BIT(21) test.");
    CFPRINTLN(C_8BIT(22), stdout, "CFPRINTLN C_8BIT(22) test.");
    CFPRINTLN(C_8BIT(23), stdout, "CFPRINTLN C_8BIT(23) test.");
    CFPRINTLN(C_8BIT(24), stdout, "CFPRINTLN C_8BIT(24) test.");
    CFPRINTLN(C_8BIT(25), stdout, "CFPRINTLN C_8BIT(25) test.");
    CFPRINTLN(C_8BIT(26), stdout, "CFPRINTLN C_8BIT(26) test.");
    CFPRINTLN(C_8BIT(27), stdout, "CFPRINTLN C_8BIT(27) test.");
    CFPRINTLN(C_8BIT(28), stdout, "CFPRINTLN C_8BIT(28) test.");
    CFPRINTLN(C_8BIT(29), stdout, "CFPRINTLN C_8BIT(29) test.");
    CFPRINTLN(C_8BIT(30), stdout, "CFPRINTLN C_8BIT(30) test.");
    CFPRINTLN(C_8BIT(31), stdout, "CFPRINTLN C_8BIT(31) test.");
    CFPRINTLN(C_8BIT(32), stdout, "CFPRINTLN C_8BIT(32) test.");
    CFPRINTLN(C_8BIT(33), stdout, "CFPRINTLN C_8BIT(33) test.");
    CFPRINTLN(C_8BIT(34), stdout, "CFPRINTLN C_8BIT(34) test.");
    CFPRINTLN(C_8BIT(35), stdout, "CFPRINTLN C_8BIT(35) test.");
    CFPRINTLN(C_8BIT(36), stdout, "CFPRINTLN C_8BIT(36) test.");
    CFPRINTLN(C_8BIT(37), stdout, "CFPRINTLN C_8BIT(37) test.");
    CFPRINTLN(C_8BIT(38), stdout, "CFPRINTLN C_8BIT(38) test.");
    CFPRINTLN(C_8BIT(39), stdout, "CFPRINTLN C_8BIT(39) test.");
    CFPRINTLN(C_8BIT(40), stdout, "CFPRINTLN C_8BIT(40) test.");
    CFPRINTLN(C_8BIT(41), stdout, "CFPRINTLN C_8BIT(41) test.");
    CFPRINTLN(C_8BIT(42), stdout, "CFPRINTLN C_8BIT(42) test.");
    CFPRINTLN(C_8BIT(43), stdout, "CFPRINTLN C_8BIT(43) test.");
    CFPRINTLN(C_8BIT(44), stdout, "CFPRINTLN C_8BIT(44) test.");
    CFPRINTLN(C_8BIT(45), stdout, "CFPRINTLN C_8BIT(45) test.");
    CFPRINTLN(C_8BIT(46), stdout, "CFPRINTLN C_8BIT(46) test.");
    CFPRINTLN(C_8BIT(47), stdout, "CFPRINTLN C_8BIT(47) test.");
    CFPRINTLN(C_8BIT(48), stdout, "CFPRINTLN C_8BIT(48) test.");
    CFPRINTLN(C_8BIT(49), stdout, "CFPRINTLN C_8BIT(49) test.");
    CFPRINTLN(C_8BIT(50), stdout, "CFPRINTLN C_8BIT(50) test.");
    CFPRINTLN(C_8BIT(51), stdout, "CFPRINTLN C_8BIT(51) test.");
    CFPRINTLN(C_8BIT(52), stdout, "CFPRINTLN C_8BIT(52) test.");
    CFPRINTLN(C_8BIT(53), stdout, "CFPRINTLN C_8BIT(53) test.");
    CFPRINTLN(C_8BIT(54), stdout, "CFPRINTLN C_8BIT(54) test.");
    CFPRINTLN(C_8BIT(55), stdout, "CFPRINTLN C_8BIT(55) test.");
    CFPRINTLN(C_8BIT(56), stdout, "CFPRINTLN C_8BIT(56) test.");
    CFPRINTLN(C_8BIT(57), stdout, "CFPRINTLN C_8BIT(57) test.");
    CFPRINTLN(C_8BIT(58), stdout, "CFPRINTLN C_8BIT(58) test.");
    CFPRINTLN(C_8BIT(59), stdout, "CFPRINTLN C_8BIT(59) test.");
    CFPRINTLN(C_8BIT(60), stdout, "CFPRINTLN C_8BIT(60) test.");
    CFPRINTLN(C_8BIT(61), stdout, "CFPRINTLN C_8BIT(61) test.");
    CFPRINTLN(C_8BIT(62), stdout, "CFPRINTLN C_8BIT(62) test.");
    CFPRINTLN(C_8BIT(63), stdout, "CFPRINTLN C_8BIT(63) test.");
    CFPRINTLN(C_8BIT(64), stdout, "CFPRINTLN C_8BIT(64) test.");
    CFPRINTLN(C_8BIT(65), stdout, "CFPRINTLN C_8BIT(65) test.");
    CFPRINTLN(C_8BIT(66), stdout, "CFPRINTLN C_8BIT(66) test.");
    CFPRINTLN(C_8BIT(67), stdout, "CFPRINTLN C_8BIT(67) test.");
    CFPRINTLN(C_8BIT(68), stdout, "CFPRINTLN C_8BIT(68) test.");
    CFPRINTLN(C_8BIT(69), stdout, "CFPRINTLN C_8BIT(69) test.");
    CFPRINTLN(C_8BIT(70), stdout, "CFPRINTLN C_8BIT(70) test.");
    CFPRINTLN(C_8BIT(71), stdout, "CFPRINTLN C_8BIT(71) test.");
    CFPRINTLN(C_8BIT(72), stdout, "CFPRINTLN C_8BIT(72) test.");
    CFPRINTLN(C_8BIT(73), stdout, "CFPRINTLN C_8BIT(73) test.");
    CFPRINTLN(C_8BIT(74), stdout, "CFPRINTLN C_8BIT(74) test.");
    CFPRINTLN(C_8BIT(75), stdout, "CFPRINTLN C_8BIT(75) test.");
    CFPRINTLN(C_8BIT(76), stdout, "CFPRINTLN C_8BIT(76) test.");
    CFPRINTLN(C_8BIT(77), stdout, "CFPRINTLN C_8BIT(77) test.");
    CFPRINTLN(C_8BIT(78), stdout, "CFPRINTLN C_8BIT(78) test.");
    CFPRINTLN(C_8BIT(79), stdout, "CFPRINTLN C_8BIT(79) test.");
    CFPRINTLN(C_8BIT(80), stdout, "CFPRINTLN C_8BIT(80) test.");
    CFPRINTLN(C_8BIT(81), stdout, "CFPRINTLN C_8BIT(81) test.");
    CFPRINTLN(C_8BIT(82), stdout, "CFPRINTLN C_8BIT(82) test.");
    CFPRINTLN(C_8BIT(83), stdout, "CFPRINTLN C_8BIT(83) test.");
    CFPRINTLN(C_8BIT(84), stdout, "CFPRINTLN C_8BIT(84) test.");
    CFPRINTLN(C_8BIT(85), stdout, "CFPRINTLN C_8BIT(85) test.");
    CFPRINTLN(C_8BIT(86), stdout, "CFPRINTLN C_8BIT(86) test.");
    CFPRINTLN(C_8BIT(87), stdout, "CFPRINTLN C_8BIT(87) test.");
    CFPRINTLN(C_8BIT(88), stdout, "CFPRINTLN C_8BIT(88) test.");
    CFPRINTLN(C_8BIT(89), stdout, "CFPRINTLN C_8BIT(89) test.");
    CFPRINTLN(C_8BIT(90), stdout, "CFPRINTLN C_8BIT(90) test.");
    CFPRINTLN(C_8BIT(91), stdout, "CFPRINTLN C_8BIT(91) test.");
    CFPRINTLN(C_8BIT(92), stdout, "CFPRINTLN C_8BIT(92) test.");
    CFPRINTLN(C_8BIT(93), stdout, "CFPRINTLN C_8BIT(93) test.");
    CFPRINTLN(C_8BIT(94), stdout, "CFPRINTLN C_8BIT(94) test.");
    CFPRINTLN(C_8BIT(95), stdout, "CFPRINTLN C_8BIT(95) test.");
    CFPRINTLN(C_8BIT(96), stdout, "CFPRINTLN C_8BIT(96) test.");
    CFPRINTLN(C_8BIT(97), stdout, "CFPRINTLN C_8BIT(97) test.");
    CFPRINTLN(C_8BIT(98), stdout, "CFPRINTLN C_8BIT(98) test.");
    CFPRINTLN(C_8BIT(99), stdout, "CFPRINTLN C_8BIT(99) test.");
    CFPRINTLN(C_8BIT(100), stdout, "CFPRINTLN C_8BIT(100) test.");
    CFPRINTLN(C_8BIT(101), stdout, "CFPRINTLN C_8BIT(101) test.");
    CFPRINTLN(C_8BIT(102), stdout, "CFPRINTLN C_8BIT(102) test.");
    CFPRINTLN(C_8BIT(103), stdout, "CFPRINTLN C_8BIT(103) test.");
    CFPRINTLN(C_8BIT(104), stdout, "CFPRINTLN C_8BIT(104) test.");
    CFPRINTLN(C_8BIT(105), stdout, "CFPRINTLN C_8BIT(105) test.");
    CFPRINTLN(C_8BIT(106), stdout, "CFPRINTLN C_8BIT(106) test.");
    CFPRINTLN(C_8BIT(107), stdout, "CFPRINTLN C_8BIT(107) test.");
    CFPRINTLN(C_8BIT(108), stdout, "CFPRINTLN C_8BIT(108) test.");
    CFPRINTLN(C_8BIT(109), stdout, "CFPRINTLN C_8BIT(109) test.");
    CFPRINTLN(C_8BIT(110), stdout, "CFPRINTLN C_8BIT(110) test.");
    CFPRINTLN(C_8BIT(111), stdout, "CFPRINTLN C_8BIT(111) test.");
    CFPRINTLN(C_8BIT(112), stdout, "CFPRINTLN C_8BIT(112) test.");
    CFPRINTLN(C_8BIT(113), stdout, "CFPRINTLN C_8BIT(113) test.");
    CFPRINTLN(C_8BIT(114), stdout, "CFPRINTLN C_8BIT(114) test.");
    CFPRINTLN(C_8BIT(115), stdout, "CFPRINTLN C_8BIT(115) test.");
    CFPRINTLN(C_8BIT(116), stdout, "CFPRINTLN C_8BIT(116) test.");
    CFPRINTLN(C_8BIT(117), stdout, "CFPRINTLN C_8BIT(117) test.");
    CFPRINTLN(C_8BIT(118), stdout, "CFPRINTLN C_8BIT(118) test.");
    CFPRINTLN(C_8BIT(119), stdout, "CFPRINTLN C_8BIT(119) test.");
    CFPRINTLN(C_8BIT(120), stdout, "CFPRINTLN C_8BIT(120) test.");
    CFPRINTLN(C_8BIT(121), stdout, "CFPRINTLN C_8BIT(121) test.");
    CFPRINTLN(C_8BIT(122), stdout, "CFPRINTLN C_8BIT(122) test.");
    CFPRINTLN(C_8BIT(123), stdout, "CFPRINTLN C_8BIT(123) test.");
    CFPRINTLN(C_8BIT(124), stdout, "CFPRINTLN C_8BIT(124) test.");
    CFPRINTLN(C_8BIT(125), stdout, "CFPRINTLN C_8BIT(125) test.");
    CFPRINTLN(C_8BIT(126), stdout, "CFPRINTLN C_8BIT(126) test.");
    CFPRINTLN(C_8BIT(127), stdout, "CFPRINTLN C_8BIT(127) test.");
    CFPRINTLN(C_8BIT(128), stdout, "CFPRINTLN C_8BIT(128) test.");
    CFPRINTLN(C_8BIT(129), stdout, "CFPRINTLN C_8BIT(129) test.");
    CFPRINTLN(C_8BIT(130), stdout, "CFPRINTLN C_8BIT(130) test.");
    CFPRINTLN(C_8BIT(131), stdout, "CFPRINTLN C_8BIT(131) test.");
    CFPRINTLN(C_8BIT(132), stdout, "CFPRINTLN C_8BIT(132) test.");
    CFPRINTLN(C_8BIT(133), stdout, "CFPRINTLN C_8BIT(133) test.");
    CFPRINTLN(C_8BIT(134), stdout, "CFPRINTLN C_8BIT(134) test.");
    CFPRINTLN(C_8BIT(135), stdout, "CFPRINTLN C_8BIT(135) test.");
    CFPRINTLN(C_8BIT(136), stdout, "CFPRINTLN C_8BIT(136) test.");
    CFPRINTLN(C_8BIT(137), stdout, "CFPRINTLN C_8BIT(137) test.");
    CFPRINTLN(C_8BIT(138), stdout, "CFPRINTLN C_8BIT(138) test.");
    CFPRINTLN(C_8BIT(139), stdout, "CFPRINTLN C_8BIT(139) test.");
    CFPRINTLN(C_8BIT(140), stdout, "CFPRINTLN C_8BIT(140) test.");
    CFPRINTLN(C_8BIT(141), stdout, "CFPRINTLN C_8BIT(141) test.");
    CFPRINTLN(C_8BIT(142), stdout, "CFPRINTLN C_8BIT(142) test.");
    CFPRINTLN(C_8BIT(143), stdout, "CFPRINTLN C_8BIT(143) test.");
    CFPRINTLN(C_8BIT(144), stdout, "CFPRINTLN C_8BIT(144) test.");
    CFPRINTLN(C_8BIT(145), stdout, "CFPRINTLN C_8BIT(145) test.");
    CFPRINTLN(C_8BIT(146), stdout, "CFPRINTLN C_8BIT(146) test.");
    CFPRINTLN(C_8BIT(147), stdout, "CFPRINTLN C_8BIT(147) test.");
    CFPRINTLN(C_8BIT(148), stdout, "CFPRINTLN C_8BIT(148) test.");
    CFPRINTLN(C_8BIT(149), stdout, "CFPRINTLN C_8BIT(149) test.");
    CFPRINTLN(C_8BIT(150), stdout, "CFPRINTLN C_8BIT(150) test.");
    CFPRINTLN(C_8BIT(151), stdout, "CFPRINTLN C_8BIT(151) test.");
    CFPRINTLN(C_8BIT(152), stdout, "CFPRINTLN C_8BIT(152) test.");
    CFPRINTLN(C_8BIT(153), stdout, "CFPRINTLN C_8BIT(153) test.");
    CFPRINTLN(C_8BIT(154), stdout, "CFPRINTLN C_8BIT(154) test.");
    CFPRINTLN(C_8BIT(155), stdout, "CFPRINTLN C_8BIT(155) test.");
    CFPRINTLN(C_8BIT(156), stdout, "CFPRINTLN C_8BIT(156) test.");
    CFPRINTLN(C_8BIT(157), stdout, "CFPRINTLN C_8BIT(157) test.");
    CFPRINTLN(C_8BIT(158), stdout, "CFPRINTLN C_8BIT(158) test.");
    CFPRINTLN(C_8BIT(159), stdout, "CFPRINTLN C_8BIT(159) test.");
    CFPRINTLN(C_8BIT(160), stdout, "CFPRINTLN C_8BIT(160) test.");
    CFPRINTLN(C_8BIT(161), stdout, "CFPRINTLN C_8BIT(161) test.");
    CFPRINTLN(C_8BIT(162), stdout, "CFPRINTLN C_8BIT(162) test.");
    CFPRINTLN(C_8BIT(163), stdout, "CFPRINTLN C_8BIT(163) test.");
    CFPRINTLN(C_8BIT(164), stdout, "CFPRINTLN C_8BIT(164) test.");
    CFPRINTLN(C_8BIT(165), stdout, "CFPRINTLN C_8BIT(165) test.");
    CFPRINTLN(C_8BIT(166), stdout, "CFPRINTLN C_8BIT(166) test.");
    CFPRINTLN(C_8BIT(167), stdout, "CFPRINTLN C_8BIT(167) test.");
    CFPRINTLN(C_8BIT(168), stdout, "CFPRINTLN C_8BIT(168) test.");
    CFPRINTLN(C_8BIT(169), stdout, "CFPRINTLN C_8BIT(169) test.");
    CFPRINTLN(C_8BIT(170), stdout, "CFPRINTLN C_8BIT(170) test.");
    CFPRINTLN(C_8BIT(171), stdout, "CFPRINTLN C_8BIT(171) test.");
    CFPRINTLN(C_8BIT(172), stdout, "CFPRINTLN C_8BIT(172) test.");
    CFPRINTLN(C_8BIT(173), stdout, "CFPRINTLN C_8BIT(173) test.");
    CFPRINTLN(C_8BIT(174), stdout, "CFPRINTLN C_8BIT(174) test.");
    CFPRINTLN(C_8BIT(175), stdout, "CFPRINTLN C_8BIT(175) test.");
    CFPRINTLN(C_8BIT(176), stdout, "CFPRINTLN C_8BIT(176) test.");
    CFPRINTLN(C_8BIT(177), stdout, "CFPRINTLN C_8BIT(177) test.");
    CFPRINTLN(C_8BIT(178), stdout, "CFPRINTLN C_8BIT(178) test.");
    CFPRINTLN(C_8BIT(179), stdout, "CFPRINTLN C_8BIT(179) test.");
    CFPRINTLN(C_8BIT(180), stdout, "CFPRINTLN C_8BIT(180) test.");
    CFPRINTLN(C_8BIT(181), stdout, "CFPRINTLN C_8BIT(181) test.");
    CFPRINTLN(C_8BIT(182), stdout, "CFPRINTLN C_8BIT(182) test.");
    CFPRINTLN(C_8BIT(183), stdout, "CFPRINTLN C_8BIT(183) test.");
    CFPRINTLN(C_8BIT(184), stdout, "CFPRINTLN C_8BIT(184) test.");
    CFPRINTLN(C_8BIT(185), stdout, "CFPRINTLN C_8BIT(185) test.");
    CFPRINTLN(C_8BIT(186), stdout, "CFPRINTLN C_8BIT(186) test.");
    CFPRINTLN(C_8BIT(187), stdout, "CFPRINTLN C_8BIT(187) test.");
    CFPRINTLN(C_8BIT(188), stdout, "CFPRINTLN C_8BIT(188) test.");
    CFPRINTLN(C_8BIT(189), stdout, "CFPRINTLN C_8BIT(189) test.");
    CFPRINTLN(C_8BIT(190), stdout, "CFPRINTLN C_8BIT(190) test.");
    CFPRINTLN(C_8BIT(191), stdout, "CFPRINTLN C_8BIT(191) test.");
    CFPRINTLN(C_8BIT(192), stdout, "CFPRINTLN C_8BIT(192) test.");
    CFPRINTLN(C_8BIT(193), stdout, "CFPRINTLN C_8BIT(193) test.");
    CFPRINTLN(C_8BIT(194), stdout, "CFPRINTLN C_8BIT(194) test.");
    CFPRINTLN(C_8BIT(195), stdout, "CFPRINTLN C_8BIT(195) test.");
    CFPRINTLN(C_8BIT(196), stdout, "CFPRINTLN C_8BIT(196) test.");
    CFPRINTLN(C_8BIT(197), stdout, "CFPRINTLN C_8BIT(197) test.");
    CFPRINTLN(C_8BIT(198), stdout, "CFPRINTLN C_8BIT(198) test.");
    CFPRINTLN(C_8BIT(199), stdout, "CFPRINTLN C_8BIT(199) test.");
    CFPRINTLN(C_8BIT(200), stdout, "CFPRINTLN C_8BIT(200) test.");
    CFPRINTLN(C_8BIT(201), stdout, "CFPRINTLN C_8BIT(201) test.");
    CFPRINTLN(C_8BIT(202), stdout, "CFPRINTLN C_8BIT(202) test.");
    CFPRINTLN(C_8BIT(203), stdout, "CFPRINTLN C_8BIT(203) test.");
    CFPRINTLN(C_8BIT(204), stdout, "CFPRINTLN C_8BIT(204) test.");
    CFPRINTLN(C_8BIT(205), stdout, "CFPRINTLN C_8BIT(205) test.");
    CFPRINTLN(C_8BIT(206), stdout, "CFPRINTLN C_8BIT(206) test.");
    CFPRINTLN(C_8BIT(207), stdout, "CFPRINTLN C_8BIT(207) test.");
    CFPRINTLN(C_8BIT(208), stdout, "CFPRINTLN C_8BIT(208) test.");
    CFPRINTLN(C_8BIT(209), stdout, "CFPRINTLN C_8BIT(209) test.");
    CFPRINTLN(C_8BIT(210), stdout, "CFPRINTLN C_8BIT(210) test.");
    CFPRINTLN(C_8BIT(211), stdout, "CFPRINTLN C_8BIT(211) test.");
    CFPRINTLN(C_8BIT(212), stdout, "CFPRINTLN C_8BIT(212) test.");
    CFPRINTLN(C_8BIT(213), stdout, "CFPRINTLN C_8BIT(213) test.");
    CFPRINTLN(C_8BIT(214), stdout, "CFPRINTLN C_8BIT(214) test.");
    CFPRINTLN(C_8BIT(215), stdout, "CFPRINTLN C_8BIT(215) test.");
    CFPRINTLN(C_8BIT(216), stdout, "CFPRINTLN C_8BIT(216) test.");
    CFPRINTLN(C_8BIT(217), stdout, "CFPRINTLN C_8BIT(217) test.");
    CFPRINTLN(C_8BIT(218), stdout, "CFPRINTLN C_8BIT(218) test.");
    CFPRINTLN(C_8BIT(219), stdout, "CFPRINTLN C_8BIT(219) test.");
    CFPRINTLN(C_8BIT(220), stdout, "CFPRINTLN C_8BIT(220) test.");
    CFPRINTLN(C_8BIT(221), stdout, "CFPRINTLN C_8BIT(221) test.");
    CFPRINTLN(C_8BIT(222), stdout, "CFPRINTLN C_8BIT(222) test.");
    CFPRINTLN(C_8BIT(223), stdout, "CFPRINTLN C_8BIT(223) test.");
    CFPRINTLN(C_8BIT(224), stdout, "CFPRINTLN C_8BIT(224) test.");
    CFPRINTLN(C_8BIT(225), stdout, "CFPRINTLN C_8BIT(225) test.");
    CFPRINTLN(C_8BIT(226), stdout, "CFPRINTLN C_8BIT(226) test.");
    CFPRINTLN(C_8BIT(227), stdout, "CFPRINTLN C_8BIT(227) test.");
    CFPRINTLN(C_8BIT(228), stdout, "CFPRINTLN C_8BIT(228) test.");
    CFPRINTLN(C_8BIT(229), stdout, "CFPRINTLN C_8BIT(229) test.");
    CFPRINTLN(C_8BIT(230), stdout, "CFPRINTLN C_8BIT(230) test.");
    CFPRINTLN(C_8BIT(231), stdout, "CFPRINTLN C_8BIT(231) test.");
    CFPRINTLN(C_8BIT(232), stdout, "CFPRINTLN C_8BIT(232) test.");
    CFPRINTLN(C_8BIT(233), stdout, "CFPRINTLN C_8BIT(233) test.");
    CFPRINTLN(C_8BIT(234), stdout, "CFPRINTLN C_8BIT(234) test.");
    CFPRINTLN(C_8BIT(235), stdout, "CFPRINTLN C_8BIT(235) test.");
    CFPRINTLN(C_8BIT(236), stdout, "CFPRINTLN C_8BIT(236) test.");
    CFPRINTLN(C_8BIT(237), stdout, "CFPRINTLN C_8BIT(237) test.");
    CFPRINTLN(C_8BIT(238), stdout, "CFPRINTLN C_8BIT(238) test.");
    CFPRINTLN(C_8BIT(239), stdout, "CFPRINTLN C_8BIT(239) test.");
    CFPRINTLN(C_8BIT(240), stdout, "CFPRINTLN C_8BIT(240) test.");
    CFPRINTLN(C_8BIT(241), stdout, "CFPRINTLN C_8BIT(241) test.");
    CFPRINTLN(C_8BIT(242), stdout, "CFPRINTLN C_8BIT(242) test.");
    CFPRINTLN(C_8BIT(243), stdout, "CFPRINTLN C_8BIT(243) test.");
    CFPRINTLN(C_8BIT(244), stdout, "CFPRINTLN C_8BIT(244) test.");
    CFPRINTLN(C_8BIT(245), stdout, "CFPRINTLN C_8BIT(245) test.");
    CFPRINTLN(C_8BIT(246), stdout, "CFPRINTLN C_8BIT(246) test.");
    CFPRINTLN(C_8BIT(247), stdout, "CFPRINTLN C_8BIT(247) test.");
    CFPRINTLN(C_8BIT(248), stdout, "CFPRINTLN C_8BIT(248) test.");
    CFPRINTLN(C_8BIT(249), stdout, "CFPRINTLN C_8BIT(249) test.");
    CFPRINTLN(C_8BIT(250), stdout, "CFPRINTLN C_8BIT(250) test.");
    CFPRINTLN(C_8BIT(251), stdout, "CFPRINTLN C_8BIT(251) test.");
    CFPRINTLN(C_8BIT(252), stdout, "CFPRINTLN C_8BIT(252) test.");
    CFPRINTLN(C_8BIT(253), stdout, "CFPRINTLN C_8BIT(253) test.");
    CFPRINTLN(C_8BIT(254), stdout, "CFPRINTLN C_8BIT(254) test.");
    CFPRINTLN(C_8BIT(255), stdout, "CFPRINTLN C_8BIT(255) test.");
    printf("\n");


    printf("[*] Testing 8-bit background colors...\n\n");

    CFPRINTLN(C_B_8BIT(0), stdout, "CFPRINTLN C_B_8BIT(0) test.");
    CFPRINTLN(C_B_8BIT(1), stdout, "CFPRINTLN C_B_8BIT(1) test.");
    CFPRINTLN(C_B_8BIT(2), stdout, "CFPRINTLN C_B_8BIT(2) test.");
    CFPRINTLN(C_B_8BIT(3), stdout, "CFPRINTLN C_B_8BIT(3) test.");
    CFPRINTLN(C_B_8BIT(4), stdout, "CFPRINTLN C_B_8BIT(4) test.");
    CFPRINTLN(C_B_8BIT(5), stdout, "CFPRINTLN C_B_8BIT(5) test.");
    CFPRINTLN(C_B_8BIT(6), stdout, "CFPRINTLN C_B_8BIT(6) test.");
    CFPRINTLN(C_B_8BIT(7), stdout, "CFPRINTLN C_B_8BIT(7) test.");
    CFPRINTLN(C_B_8BIT(8), stdout, "CFPRINTLN C_B_8BIT(8) test.");
    CFPRINTLN(C_B_8BIT(9), stdout, "CFPRINTLN C_B_8BIT(9) test.");
    CFPRINTLN(C_B_8BIT(10), stdout, "CFPRINTLN C_B_8BIT(10) test.");
    CFPRINTLN(C_B_8BIT(11), stdout, "CFPRINTLN C_B_8BIT(11) test.");
    CFPRINTLN(C_B_8BIT(12), stdout, "CFPRINTLN C_B_8BIT(12) test.");
    CFPRINTLN(C_B_8BIT(13), stdout, "CFPRINTLN C_B_8BIT(13) test.");
    CFPRINTLN(C_B_8BIT(14), stdout, "CFPRINTLN C_B_8BIT(14) test.");
    CFPRINTLN(C_B_8BIT(15), stdout, "CFPRINTLN C_B_8BIT(15) test.");
    CFPRINTLN(C_B_8BIT(16), stdout, "CFPRINTLN C_B_8BIT(16) test.");
    CFPRINTLN(C_B_8BIT(17), stdout, "CFPRINTLN C_B_8BIT(17) test.");
    CFPRINTLN(C_B_8BIT(18), stdout, "CFPRINTLN C_B_8BIT(18) test.");
    CFPRINTLN(C_B_8BIT(19), stdout, "CFPRINTLN C_B_8BIT(19) test.");
    CFPRINTLN(C_B_8BIT(20), stdout, "CFPRINTLN C_B_8BIT(20) test.");
    CFPRINTLN(C_B_8BIT(21), stdout, "CFPRINTLN C_B_8BIT(21) test.");
    CFPRINTLN(C_B_8BIT(22), stdout, "CFPRINTLN C_B_8BIT(22) test.");
    CFPRINTLN(C_B_8BIT(23), stdout, "CFPRINTLN C_B_8BIT(23) test.");
    CFPRINTLN(C_B_8BIT(24), stdout, "CFPRINTLN C_B_8BIT(24) test.");
    CFPRINTLN(C_B_8BIT(25), stdout, "CFPRINTLN C_B_8BIT(25) test.");
    CFPRINTLN(C_B_8BIT(26), stdout, "CFPRINTLN C_B_8BIT(26) test.");
    CFPRINTLN(C_B_8BIT(27), stdout, "CFPRINTLN C_B_8BIT(27) test.");
    CFPRINTLN(C_B_8BIT(28), stdout, "CFPRINTLN C_B_8BIT(28) test.");
    CFPRINTLN(C_B_8BIT(29), stdout, "CFPRINTLN C_B_8BIT(29) test.");
    CFPRINTLN(C_B_8BIT(30), stdout, "CFPRINTLN C_B_8BIT(30) test.");
    CFPRINTLN(C_B_8BIT(31), stdout, "CFPRINTLN C_B_8BIT(31) test.");
    CFPRINTLN(C_B_8BIT(32), stdout, "CFPRINTLN C_B_8BIT(32) test.");
    CFPRINTLN(C_B_8BIT(33), stdout, "CFPRINTLN C_B_8BIT(33) test.");
    CFPRINTLN(C_B_8BIT(34), stdout, "CFPRINTLN C_B_8BIT(34) test.");
    CFPRINTLN(C_B_8BIT(35), stdout, "CFPRINTLN C_B_8BIT(35) test.");
    CFPRINTLN(C_B_8BIT(36), stdout, "CFPRINTLN C_B_8BIT(36) test.");
    CFPRINTLN(C_B_8BIT(37), stdout, "CFPRINTLN C_B_8BIT(37) test.");
    CFPRINTLN(C_B_8BIT(38), stdout, "CFPRINTLN C_B_8BIT(38) test.");
    CFPRINTLN(C_B_8BIT(39), stdout, "CFPRINTLN C_B_8BIT(39) test.");
    CFPRINTLN(C_B_8BIT(40), stdout, "CFPRINTLN C_B_8BIT(40) test.");
    CFPRINTLN(C_B_8BIT(41), stdout, "CFPRINTLN C_B_8BIT(41) test.");
    CFPRINTLN(C_B_8BIT(42), stdout, "CFPRINTLN C_B_8BIT(42) test.");
    CFPRINTLN(C_B_8BIT(43), stdout, "CFPRINTLN C_B_8BIT(43) test.");
    CFPRINTLN(C_B_8BIT(44), stdout, "CFPRINTLN C_B_8BIT(44) test.");
    CFPRINTLN(C_B_8BIT(45), stdout, "CFPRINTLN C_B_8BIT(45) test.");
    CFPRINTLN(C_B_8BIT(46), stdout, "CFPRINTLN C_B_8BIT(46) test.");
    CFPRINTLN(C_B_8BIT(47), stdout, "CFPRINTLN C_B_8BIT(47) test.");
    CFPRINTLN(C_B_8BIT(48), stdout, "CFPRINTLN C_B_8BIT(48) test.");
    CFPRINTLN(C_B_8BIT(49), stdout, "CFPRINTLN C_B_8BIT(49) test.");
    CFPRINTLN(C_B_8BIT(50), stdout, "CFPRINTLN C_B_8BIT(50) test.");
    CFPRINTLN(C_B_8BIT(51), stdout, "CFPRINTLN C_B_8BIT(51) test.");
    CFPRINTLN(C_B_8BIT(52), stdout, "CFPRINTLN C_B_8BIT(52) test.");
    CFPRINTLN(C_B_8BIT(53), stdout, "CFPRINTLN C_B_8BIT(53) test.");
    CFPRINTLN(C_B_8BIT(54), stdout, "CFPRINTLN C_B_8BIT(54) test.");
    CFPRINTLN(C_B_8BIT(55), stdout, "CFPRINTLN C_B_8BIT(55) test.");
    CFPRINTLN(C_B_8BIT(56), stdout, "CFPRINTLN C_B_8BIT(56) test.");
    CFPRINTLN(C_B_8BIT(57), stdout, "CFPRINTLN C_B_8BIT(57) test.");
    CFPRINTLN(C_B_8BIT(58), stdout, "CFPRINTLN C_B_8BIT(58) test.");
    CFPRINTLN(C_B_8BIT(59), stdout, "CFPRINTLN C_B_8BIT(59) test.");
    CFPRINTLN(C_B_8BIT(60), stdout, "CFPRINTLN C_B_8BIT(60) test.");
    CFPRINTLN(C_B_8BIT(61), stdout, "CFPRINTLN C_B_8BIT(61) test.");
    CFPRINTLN(C_B_8BIT(62), stdout, "CFPRINTLN C_B_8BIT(62) test.");
    CFPRINTLN(C_B_8BIT(63), stdout, "CFPRINTLN C_B_8BIT(63) test.");
    CFPRINTLN(C_B_8BIT(64), stdout, "CFPRINTLN C_B_8BIT(64) test.");
    CFPRINTLN(C_B_8BIT(65), stdout, "CFPRINTLN C_B_8BIT(65) test.");
    CFPRINTLN(C_B_8BIT(66), stdout, "CFPRINTLN C_B_8BIT(66) test.");
    CFPRINTLN(C_B_8BIT(67), stdout, "CFPRINTLN C_B_8BIT(67) test.");
    CFPRINTLN(C_B_8BIT(68), stdout, "CFPRINTLN C_B_8BIT(68) test.");
    CFPRINTLN(C_B_8BIT(69), stdout, "CFPRINTLN C_B_8BIT(69) test.");
    CFPRINTLN(C_B_8BIT(70), stdout, "CFPRINTLN C_B_8BIT(70) test.");
    CFPRINTLN(C_B_8BIT(71), stdout, "CFPRINTLN C_B_8BIT(71) test.");
    CFPRINTLN(C_B_8BIT(72), stdout, "CFPRINTLN C_B_8BIT(72) test.");
    CFPRINTLN(C_B_8BIT(73), stdout, "CFPRINTLN C_B_8BIT(73) test.");
    CFPRINTLN(C_B_8BIT(74), stdout, "CFPRINTLN C_B_8BIT(74) test.");
    CFPRINTLN(C_B_8BIT(75), stdout, "CFPRINTLN C_B_8BIT(75) test.");
    CFPRINTLN(C_B_8BIT(76), stdout, "CFPRINTLN C_B_8BIT(76) test.");
    CFPRINTLN(C_B_8BIT(77), stdout, "CFPRINTLN C_B_8BIT(77) test.");
    CFPRINTLN(C_B_8BIT(78), stdout, "CFPRINTLN C_B_8BIT(78) test.");
    CFPRINTLN(C_B_8BIT(79), stdout, "CFPRINTLN C_B_8BIT(79) test.");
    CFPRINTLN(C_B_8BIT(80), stdout, "CFPRINTLN C_B_8BIT(80) test.");
    CFPRINTLN(C_B_8BIT(81), stdout, "CFPRINTLN C_B_8BIT(81) test.");
    CFPRINTLN(C_B_8BIT(82), stdout, "CFPRINTLN C_B_8BIT(82) test.");
    CFPRINTLN(C_B_8BIT(83), stdout, "CFPRINTLN C_B_8BIT(83) test.");
    CFPRINTLN(C_B_8BIT(84), stdout, "CFPRINTLN C_B_8BIT(84) test.");
    CFPRINTLN(C_B_8BIT(85), stdout, "CFPRINTLN C_B_8BIT(85) test.");
    CFPRINTLN(C_B_8BIT(86), stdout, "CFPRINTLN C_B_8BIT(86) test.");
    CFPRINTLN(C_B_8BIT(87), stdout, "CFPRINTLN C_B_8BIT(87) test.");
    CFPRINTLN(C_B_8BIT(88), stdout, "CFPRINTLN C_B_8BIT(88) test.");
    CFPRINTLN(C_B_8BIT(89), stdout, "CFPRINTLN C_B_8BIT(89) test.");
    CFPRINTLN(C_B_8BIT(90), stdout, "CFPRINTLN C_B_8BIT(90) test.");
    CFPRINTLN(C_B_8BIT(91), stdout, "CFPRINTLN C_B_8BIT(91) test.");
    CFPRINTLN(C_B_8BIT(92), stdout, "CFPRINTLN C_B_8BIT(92) test.");
    CFPRINTLN(C_B_8BIT(93), stdout, "CFPRINTLN C_B_8BIT(93) test.");
    CFPRINTLN(C_B_8BIT(94), stdout, "CFPRINTLN C_B_8BIT(94) test.");
    CFPRINTLN(C_B_8BIT(95), stdout, "CFPRINTLN C_B_8BIT(95) test.");
    CFPRINTLN(C_B_8BIT(96), stdout, "CFPRINTLN C_B_8BIT(96) test.");
    CFPRINTLN(C_B_8BIT(97), stdout, "CFPRINTLN C_B_8BIT(97) test.");
    CFPRINTLN(C_B_8BIT(98), stdout, "CFPRINTLN C_B_8BIT(98) test.");
    CFPRINTLN(C_B_8BIT(99), stdout, "CFPRINTLN C_B_8BIT(99) test.");
    CFPRINTLN(C_B_8BIT(100), stdout, "CFPRINTLN C_B_8BIT(100) test.");
    CFPRINTLN(C_B_8BIT(101), stdout, "CFPRINTLN C_B_8BIT(101) test.");
    CFPRINTLN(C_B_8BIT(102), stdout, "CFPRINTLN C_B_8BIT(102) test.");
    CFPRINTLN(C_B_8BIT(103), stdout, "CFPRINTLN C_B_8BIT(103) test.");
    CFPRINTLN(C_B_8BIT(104), stdout, "CFPRINTLN C_B_8BIT(104) test.");
    CFPRINTLN(C_B_8BIT(105), stdout, "CFPRINTLN C_B_8BIT(105) test.");
    CFPRINTLN(C_B_8BIT(106), stdout, "CFPRINTLN C_B_8BIT(106) test.");
    CFPRINTLN(C_B_8BIT(107), stdout, "CFPRINTLN C_B_8BIT(107) test.");
    CFPRINTLN(C_B_8BIT(108), stdout, "CFPRINTLN C_B_8BIT(108) test.");
    CFPRINTLN(C_B_8BIT(109), stdout, "CFPRINTLN C_B_8BIT(109) test.");
    CFPRINTLN(C_B_8BIT(110), stdout, "CFPRINTLN C_B_8BIT(110) test.");
    CFPRINTLN(C_B_8BIT(111), stdout, "CFPRINTLN C_B_8BIT(111) test.");
    CFPRINTLN(C_B_8BIT(112), stdout, "CFPRINTLN C_B_8BIT(112) test.");
    CFPRINTLN(C_B_8BIT(113), stdout, "CFPRINTLN C_B_8BIT(113) test.");
    CFPRINTLN(C_B_8BIT(114), stdout, "CFPRINTLN C_B_8BIT(114) test.");
    CFPRINTLN(C_B_8BIT(115), stdout, "CFPRINTLN C_B_8BIT(115) test.");
    CFPRINTLN(C_B_8BIT(116), stdout, "CFPRINTLN C_B_8BIT(116) test.");
    CFPRINTLN(C_B_8BIT(117), stdout, "CFPRINTLN C_B_8BIT(117) test.");
    CFPRINTLN(C_B_8BIT(118), stdout, "CFPRINTLN C_B_8BIT(118) test.");
    CFPRINTLN(C_B_8BIT(119), stdout, "CFPRINTLN C_B_8BIT(119) test.");
    CFPRINTLN(C_B_8BIT(120), stdout, "CFPRINTLN C_B_8BIT(120) test.");
    CFPRINTLN(C_B_8BIT(121), stdout, "CFPRINTLN C_B_8BIT(121) test.");
    CFPRINTLN(C_B_8BIT(122), stdout, "CFPRINTLN C_B_8BIT(122) test.");
    CFPRINTLN(C_B_8BIT(123), stdout, "CFPRINTLN C_B_8BIT(123) test.");
    CFPRINTLN(C_B_8BIT(124), stdout, "CFPRINTLN C_B_8BIT(124) test.");
    CFPRINTLN(C_B_8BIT(125), stdout, "CFPRINTLN C_B_8BIT(125) test.");
    CFPRINTLN(C_B_8BIT(126), stdout, "CFPRINTLN C_B_8BIT(126) test.");
    CFPRINTLN(C_B_8BIT(127), stdout, "CFPRINTLN C_B_8BIT(127) test.");
    CFPRINTLN(C_B_8BIT(128), stdout, "CFPRINTLN C_B_8BIT(128) test.");
    CFPRINTLN(C_B_8BIT(129), stdout, "CFPRINTLN C_B_8BIT(129) test.");
    CFPRINTLN(C_B_8BIT(130), stdout, "CFPRINTLN C_B_8BIT(130) test.");
    CFPRINTLN(C_B_8BIT(131), stdout, "CFPRINTLN C_B_8BIT(131) test.");
    CFPRINTLN(C_B_8BIT(132), stdout, "CFPRINTLN C_B_8BIT(132) test.");
    CFPRINTLN(C_B_8BIT(133), stdout, "CFPRINTLN C_B_8BIT(133) test.");
    CFPRINTLN(C_B_8BIT(134), stdout, "CFPRINTLN C_B_8BIT(134) test.");
    CFPRINTLN(C_B_8BIT(135), stdout, "CFPRINTLN C_B_8BIT(135) test.");
    CFPRINTLN(C_B_8BIT(136), stdout, "CFPRINTLN C_B_8BIT(136) test.");
    CFPRINTLN(C_B_8BIT(137), stdout, "CFPRINTLN C_B_8BIT(137) test.");
    CFPRINTLN(C_B_8BIT(138), stdout, "CFPRINTLN C_B_8BIT(138) test.");
    CFPRINTLN(C_B_8BIT(139), stdout, "CFPRINTLN C_B_8BIT(139) test.");
    CFPRINTLN(C_B_8BIT(140), stdout, "CFPRINTLN C_B_8BIT(140) test.");
    CFPRINTLN(C_B_8BIT(141), stdout, "CFPRINTLN C_B_8BIT(141) test.");
    CFPRINTLN(C_B_8BIT(142), stdout, "CFPRINTLN C_B_8BIT(142) test.");
    CFPRINTLN(C_B_8BIT(143), stdout, "CFPRINTLN C_B_8BIT(143) test.");
    CFPRINTLN(C_B_8BIT(144), stdout, "CFPRINTLN C_B_8BIT(144) test.");
    CFPRINTLN(C_B_8BIT(145), stdout, "CFPRINTLN C_B_8BIT(145) test.");
    CFPRINTLN(C_B_8BIT(146), stdout, "CFPRINTLN C_B_8BIT(146) test.");
    CFPRINTLN(C_B_8BIT(147), stdout, "CFPRINTLN C_B_8BIT(147) test.");
    CFPRINTLN(C_B_8BIT(148), stdout, "CFPRINTLN C_B_8BIT(148) test.");
    CFPRINTLN(C_B_8BIT(149), stdout, "CFPRINTLN C_B_8BIT(149) test.");
    CFPRINTLN(C_B_8BIT(150), stdout, "CFPRINTLN C_B_8BIT(150) test.");
    CFPRINTLN(C_B_8BIT(151), stdout, "CFPRINTLN C_B_8BIT(151) test.");
    CFPRINTLN(C_B_8BIT(152), stdout, "CFPRINTLN C_B_8BIT(152) test.");
    CFPRINTLN(C_B_8BIT(153), stdout, "CFPRINTLN C_B_8BIT(153) test.");
    CFPRINTLN(C_B_8BIT(154), stdout, "CFPRINTLN C_B_8BIT(154) test.");
    CFPRINTLN(C_B_8BIT(155), stdout, "CFPRINTLN C_B_8BIT(155) test.");
    CFPRINTLN(C_B_8BIT(156), stdout, "CFPRINTLN C_B_8BIT(156) test.");
    CFPRINTLN(C_B_8BIT(157), stdout, "CFPRINTLN C_B_8BIT(157) test.");
    CFPRINTLN(C_B_8BIT(158), stdout, "CFPRINTLN C_B_8BIT(158) test.");
    CFPRINTLN(C_B_8BIT(159), stdout, "CFPRINTLN C_B_8BIT(159) test.");
    CFPRINTLN(C_B_8BIT(160), stdout, "CFPRINTLN C_B_8BIT(160) test.");
    CFPRINTLN(C_B_8BIT(161), stdout, "CFPRINTLN C_B_8BIT(161) test.");
    CFPRINTLN(C_B_8BIT(162), stdout, "CFPRINTLN C_B_8BIT(162) test.");
    CFPRINTLN(C_B_8BIT(163), stdout, "CFPRINTLN C_B_8BIT(163) test.");
    CFPRINTLN(C_B_8BIT(164), stdout, "CFPRINTLN C_B_8BIT(164) test.");
    CFPRINTLN(C_B_8BIT(165), stdout, "CFPRINTLN C_B_8BIT(165) test.");
    CFPRINTLN(C_B_8BIT(166), stdout, "CFPRINTLN C_B_8BIT(166) test.");
    CFPRINTLN(C_B_8BIT(167), stdout, "CFPRINTLN C_B_8BIT(167) test.");
    CFPRINTLN(C_B_8BIT(168), stdout, "CFPRINTLN C_B_8BIT(168) test.");
    CFPRINTLN(C_B_8BIT(169), stdout, "CFPRINTLN C_B_8BIT(169) test.");
    CFPRINTLN(C_B_8BIT(170), stdout, "CFPRINTLN C_B_8BIT(170) test.");
    CFPRINTLN(C_B_8BIT(171), stdout, "CFPRINTLN C_B_8BIT(171) test.");
    CFPRINTLN(C_B_8BIT(172), stdout, "CFPRINTLN C_B_8BIT(172) test.");
    CFPRINTLN(C_B_8BIT(173), stdout, "CFPRINTLN C_B_8BIT(173) test.");
    CFPRINTLN(C_B_8BIT(174), stdout, "CFPRINTLN C_B_8BIT(174) test.");
    CFPRINTLN(C_B_8BIT(175), stdout, "CFPRINTLN C_B_8BIT(175) test.");
    CFPRINTLN(C_B_8BIT(176), stdout, "CFPRINTLN C_B_8BIT(176) test.");
    CFPRINTLN(C_B_8BIT(177), stdout, "CFPRINTLN C_B_8BIT(177) test.");
    CFPRINTLN(C_B_8BIT(178), stdout, "CFPRINTLN C_B_8BIT(178) test.");
    CFPRINTLN(C_B_8BIT(179), stdout, "CFPRINTLN C_B_8BIT(179) test.");
    CFPRINTLN(C_B_8BIT(180), stdout, "CFPRINTLN C_B_8BIT(180) test.");
    CFPRINTLN(C_B_8BIT(181), stdout, "CFPRINTLN C_B_8BIT(181) test.");
    CFPRINTLN(C_B_8BIT(182), stdout, "CFPRINTLN C_B_8BIT(182) test.");
    CFPRINTLN(C_B_8BIT(183), stdout, "CFPRINTLN C_B_8BIT(183) test.");
    CFPRINTLN(C_B_8BIT(184), stdout, "CFPRINTLN C_B_8BIT(184) test.");
    CFPRINTLN(C_B_8BIT(185), stdout, "CFPRINTLN C_B_8BIT(185) test.");
    CFPRINTLN(C_B_8BIT(186), stdout, "CFPRINTLN C_B_8BIT(186) test.");
    CFPRINTLN(C_B_8BIT(187), stdout, "CFPRINTLN C_B_8BIT(187) test.");
    CFPRINTLN(C_B_8BIT(188), stdout, "CFPRINTLN C_B_8BIT(188) test.");
    CFPRINTLN(C_B_8BIT(189), stdout, "CFPRINTLN C_B_8BIT(189) test.");
    CFPRINTLN(C_B_8BIT(190), stdout, "CFPRINTLN C_B_8BIT(190) test.");
    CFPRINTLN(C_B_8BIT(191), stdout, "CFPRINTLN C_B_8BIT(191) test.");
    CFPRINTLN(C_B_8BIT(192), stdout, "CFPRINTLN C_B_8BIT(192) test.");
    CFPRINTLN(C_B_8BIT(193), stdout, "CFPRINTLN C_B_8BIT(193) test.");
    CFPRINTLN(C_B_8BIT(194), stdout, "CFPRINTLN C_B_8BIT(194) test.");
    CFPRINTLN(C_B_8BIT(195), stdout, "CFPRINTLN C_B_8BIT(195) test.");
    CFPRINTLN(C_B_8BIT(196), stdout, "CFPRINTLN C_B_8BIT(196) test.");
    CFPRINTLN(C_B_8BIT(197), stdout, "CFPRINTLN C_B_8BIT(197) test.");
    CFPRINTLN(C_B_8BIT(198), stdout, "CFPRINTLN C_B_8BIT(198) test.");
    CFPRINTLN(C_B_8BIT(199), stdout, "CFPRINTLN C_B_8BIT(199) test.");
    CFPRINTLN(C_B_8BIT(200), stdout, "CFPRINTLN C_B_8BIT(200) test.");
    CFPRINTLN(C_B_8BIT(201), stdout, "CFPRINTLN C_B_8BIT(201) test.");
    CFPRINTLN(C_B_8BIT(202), stdout, "CFPRINTLN C_B_8BIT(202) test.");
    CFPRINTLN(C_B_8BIT(203), stdout, "CFPRINTLN C_B_8BIT(203) test.");
    CFPRINTLN(C_B_8BIT(204), stdout, "CFPRINTLN C_B_8BIT(204) test.");
    CFPRINTLN(C_B_8BIT(205), stdout, "CFPRINTLN C_B_8BIT(205) test.");
    CFPRINTLN(C_B_8BIT(206), stdout, "CFPRINTLN C_B_8BIT(206) test.");
    CFPRINTLN(C_B_8BIT(207), stdout, "CFPRINTLN C_B_8BIT(207) test.");
    CFPRINTLN(C_B_8BIT(208), stdout, "CFPRINTLN C_B_8BIT(208) test.");
    CFPRINTLN(C_B_8BIT(209), stdout, "CFPRINTLN C_B_8BIT(209) test.");
    CFPRINTLN(C_B_8BIT(210), stdout, "CFPRINTLN C_B_8BIT(210) test.");
    CFPRINTLN(C_B_8BIT(211), stdout, "CFPRINTLN C_B_8BIT(211) test.");
    CFPRINTLN(C_B_8BIT(212), stdout, "CFPRINTLN C_B_8BIT(212) test.");
    CFPRINTLN(C_B_8BIT(213), stdout, "CFPRINTLN C_B_8BIT(213) test.");
    CFPRINTLN(C_B_8BIT(214), stdout, "CFPRINTLN C_B_8BIT(214) test.");
    CFPRINTLN(C_B_8BIT(215), stdout, "CFPRINTLN C_B_8BIT(215) test.");
    CFPRINTLN(C_B_8BIT(216), stdout, "CFPRINTLN C_B_8BIT(216) test.");
    CFPRINTLN(C_B_8BIT(217), stdout, "CFPRINTLN C_B_8BIT(217) test.");
    CFPRINTLN(C_B_8BIT(218), stdout, "CFPRINTLN C_B_8BIT(218) test.");
    CFPRINTLN(C_B_8BIT(219), stdout, "CFPRINTLN C_B_8BIT(219) test.");
    CFPRINTLN(C_B_8BIT(220), stdout, "CFPRINTLN C_B_8BIT(220) test.");
    CFPRINTLN(C_B_8BIT(221), stdout, "CFPRINTLN C_B_8BIT(221) test.");
    CFPRINTLN(C_B_8BIT(222), stdout, "CFPRINTLN C_B_8BIT(222) test.");
    CFPRINTLN(C_B_8BIT(223), stdout, "CFPRINTLN C_B_8BIT(223) test.");
    CFPRINTLN(C_B_8BIT(224), stdout, "CFPRINTLN C_B_8BIT(224) test.");
    CFPRINTLN(C_B_8BIT(225), stdout, "CFPRINTLN C_B_8BIT(225) test.");
    CFPRINTLN(C_B_8BIT(226), stdout, "CFPRINTLN C_B_8BIT(226) test.");
    CFPRINTLN(C_B_8BIT(227), stdout, "CFPRINTLN C_B_8BIT(227) test.");
    CFPRINTLN(C_B_8BIT(228), stdout, "CFPRINTLN C_B_8BIT(228) test.");
    CFPRINTLN(C_B_8BIT(229), stdout, "CFPRINTLN C_B_8BIT(229) test.");
    CFPRINTLN(C_B_8BIT(230), stdout, "CFPRINTLN C_B_8BIT(230) test.");
    CFPRINTLN(C_B_8BIT(231), stdout, "CFPRINTLN C_B_8BIT(231) test.");
    CFPRINTLN(C_B_8BIT(232), stdout, "CFPRINTLN C_B_8BIT(232) test.");
    CFPRINTLN(C_B_8BIT(233), stdout, "CFPRINTLN C_B_8BIT(233) test.");
    CFPRINTLN(C_B_8BIT(234), stdout, "CFPRINTLN C_B_8BIT(234) test.");
    CFPRINTLN(C_B_8BIT(235), stdout, "CFPRINTLN C_B_8BIT(235) test.");
    CFPRINTLN(C_B_8BIT(236), stdout, "CFPRINTLN C_B_8BIT(236) test.");
    CFPRINTLN(C_B_8BIT(237), stdout, "CFPRINTLN C_B_8BIT(237) test.");
    CFPRINTLN(C_B_8BIT(238), stdout, "CFPRINTLN C_B_8BIT(238) test.");
    CFPRINTLN(C_B_8BIT(239), stdout, "CFPRINTLN C_B_8BIT(239) test.");
    CFPRINTLN(C_B_8BIT(240), stdout, "CFPRINTLN C_B_8BIT(240) test.");
    CFPRINTLN(C_B_8BIT(241), stdout, "CFPRINTLN C_B_8BIT(241) test.");
    CFPRINTLN(C_B_8BIT(242), stdout, "CFPRINTLN C_B_8BIT(242) test.");
    CFPRINTLN(C_B_8BIT(243), stdout, "CFPRINTLN C_B_8BIT(243) test.");
    CFPRINTLN(C_B_8BIT(244), stdout, "CFPRINTLN C_B_8BIT(244) test.");
    CFPRINTLN(C_B_8BIT(245), stdout, "CFPRINTLN C_B_8BIT(245) test.");
    CFPRINTLN(C_B_8BIT(246), stdout, "CFPRINTLN C_B_8BIT(246) test.");
    CFPRINTLN(C_B_8BIT(247), stdout, "CFPRINTLN C_B_8BIT(247) test.");
    CFPRINTLN(C_B_8BIT(248), stdout, "CFPRINTLN C_B_8BIT(248) test.");
    CFPRINTLN(C_B_8BIT(249), stdout, "CFPRINTLN C_B_8BIT(249) test.");
    CFPRINTLN(C_B_8BIT(250), stdout, "CFPRINTLN C_B_8BIT(250) test.");
    CFPRINTLN(C_B_8BIT(251), stdout, "CFPRINTLN C_B_8BIT(251) test.");
    CFPRINTLN(C_B_8BIT(252), stdout, "CFPRINTLN C_B_8BIT(252) test.");
    CFPRINTLN(C_B_8BIT(253), stdout, "CFPRINTLN C_B_8BIT(253) test.");
    CFPRINTLN(C_B_8BIT(254), stdout, "CFPRINTLN C_B_8BIT(254) test.");
    CFPRINTLN(C_B_8BIT(255), stdout, "CFPRINTLN C_B_8BIT(255) test.");
    printf("\n");


    printf("[*] Testing a couple of 24-bit colors...\n\n");

    CFPRINTLN(C_RGB(255, 0, 0), stdout, "CFPRINTLN C_RGB(255, 0, 0) test.");
    CFPRINTLN(C_RGB(120, 204, 62), stdout, "CFPRINTLN C_RGB(120, 204, 62) test.");
    CFPRINTLN(C_RGB(66, 99, 123), stdout, "CFPRINTLN C_RGB(66, 99, 123) test.");
    CFPRINTLN(C_RGB(204, 128, 224), stdout, "CFPRINTLN C_RGB(204, 128, 224) test.");

    // Currently does not work.
    //CFPRINTLN(C_RGB(0xff, 0x0, 0xa0), stdout, "CFPRINTLN C_RGB(0xff, 0x0, 0xa0) test.");
    printf("\n");


    printf("[*] Testing a couple of 24-bit background colors...\n\n");

    CFPRINTLN(C_B_RGB(255, 0, 0), stdout, "CFPRINTLN C_B_RGB(255, 0, 0) test.");
    CFPRINTLN(C_B_RGB(120, 204, 62), stdout, "CFPRINTLN C_B_RGB(120, 204, 62) test.");
    CFPRINTLN(C_B_RGB(66, 99, 123), stdout, "CFPRINTLN C_B_RGB(66, 99, 123) test.");
    CFPRINTLN(C_B_RGB(204, 128, 224), stdout, "CFPRINTLN C_B_RGB(204, 128, 224) test.");
    printf("\n");


    printf("[*] Testing extra colors...\n\n");

    CFPRINTLN(C_ORANGE, stdout, "CFPRINTLN C_ORANGE test.");
    printf("\n");


    printf("[*] Testing in loop without brackets...\n\n");

    for (int i = 0; i < 4; ++i)
        CFPRINTLN(C_ORANGE, stdout, "CFPRINTLN C_ORANGE test.");

    printf("\n");

    return 0;
}


/**
 * @brief   Test the "print" series of function by printing to console for 
 *          review.
 *
 * @return  Return 0.
 */
int test_print() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'print' functions...\n\n");

    PRINT("PRINT test.");
    printf("\n");

    PRINTLN("PRINTLN test.");

    PRINTF("PRINTF test integer: %d.", integer);
    printf("\n");

    PRINTFLN("PRINTFLN test integer: %d.", integer);
    printf("\n");


    PRINTF("PRINT_HEX test hex: %llu: ", hex);
    PRINT_HEX(&hex, sizeof(hex));
    printf("\n");

    PRINTF("PRINTLN_HEX test hex: %llu: ", hex);
    PRINTLN_HEX(&hex, sizeof(hex));

    PRINTF("PRINT_WIDE_HEX test wide hex: %llu: ", hex);
    PRINT_WIDE_HEX(&hex, sizeof(hex));
    printf("\n");

    PRINTF("PRINTLN_WIDE_HEX test wide hex: %llu: ", hex);
    PRINTLN_WIDE_HEX(&hex, sizeof(hex));
    printf("\n");


    PERROR("PERROR test");
    PERRORF("PERRORF test: %d", integer);
    printf("\n");


    printf("[*] Testing 'print_<level>' functions...\n\n");

    PRINT_TRACE("PRINT_TRACE test.");
    printf("\n");
    PRINTLN_TRACE("PRINTLN_TRACE test.");
    PRINTF_TRACE("PRINTF_TRACE test integer: %d.", integer);
    printf("\n");
    PRINTFLN_TRACE("PRINTFLN_TRACE test integer: %d.", integer);
    printf("\n");


    PRINT_DEBUG("PRINT_DEBUG test.");
    printf("\n");
    PRINTLN_DEBUG("PRINTLN_DEBUG test.");
    PRINTF_DEBUG("PRINTF_DEBUG test integer: %d.", integer);
    printf("\n");
    PRINTFLN_DEBUG("PRINTFLN_DEBUG test integer: %d.", integer);
    printf("\n");


    PRINT_EXTRA("PRINT_EXTRA test.");
    printf("\n");
    PRINTLN_EXTRA("PRINTLN_EXTRA test.");
    PRINTF_EXTRA("PRINTF_EXTRA test integer: %d.", integer);
    printf("\n");
    PRINTFLN_EXTRA("PRINTFLN_EXTRA test integer: %d.", integer);
    printf("\n");


    PRINT_INFO("PRINT_INFO test.");
    printf("\n");
    PRINTLN_INFO("PRINTLN_INFO test.");
    PRINTF_INFO("PRINTF_INFO test integer: %d.", integer);
    printf("\n");
    PRINTFLN_INFO("PRINTFLN_INFO test integer: %d.", integer);
    printf("\n");


    PRINT_HEADER("PRINT_HEADER test.");
    printf("\n");
    PRINTLN_HEADER("PRINTLN_HEADER test.");
    PRINTF_HEADER("PRINTF_HEADER test integer: %d.", integer);
    printf("\n");
    PRINTFLN_HEADER("PRINTFLN_HEADER test integer: %d.", integer);
    printf("\n");


    PRINT_SUCCESS("PRINT_SUCCESS test.");
    printf("\n");
    PRINTLN_SUCCESS("PRINTLN_SUCCESS test.");
    PRINTF_SUCCESS("PRINTF_SUCCESS test integer: %d.", integer);
    printf("\n");
    PRINTFLN_SUCCESS("PRINTFLN_SUCCESS test integer: %d.", integer);
    printf("\n");


    PRINT_INPUT("PRINT_INPUT test.");
    printf("\n");
    PRINTLN_INPUT("PRINTLN_INPUT test.");
    PRINTF_INPUT("PRINTF_INPUT test integer: %d.", integer);
    printf("\n");
    PRINTFLN_INPUT("PRINTFLN_INPUT test integer: %d.", integer);
    printf("\n");


    PRINT_WARNING("PRINT_WARNING test.");
    printf("\n");
    PRINTLN_WARNING("PRINTLN_WARNING test.");
    PRINTF_WARNING("PRINTF_WARNING test integer: %d.", integer);
    printf("\n");
    PRINTFLN_WARNING("PRINTFLN_WARNING test integer: %d.", integer);
    printf("\n");


    PRINT_ERROR("PRINT_ERROR test.");
    printf("\n");
    PRINTLN_ERROR("PRINTLN_ERROR test.");
    PRINTF_ERROR("PRINTF_ERROR test integer: %d.", integer);
    printf("\n");
    PRINTFLN_ERROR("PRINTFLN_ERROR test integer: %d.", integer);
    printf("\n");

    PERROR_ERROR("PERROR_ERROR test");
    PERRORF_ERROR("PERRORF_ERROR test: %d", integer);
    printf("\n");


    PRINT_FATAL("PRINT_FATAL test.");
    printf("\n");
    PRINTLN_FATAL("PRINTLN_FATAL test.");
    PRINTF_FATAL("PRINTF_FATAL test integer: %d.", integer);
    printf("\n");
    PRINTFLN_FATAL("PRINTFLN_FATAL test integer: %d.", integer);
    printf("\n");

    PERROR_FATAL("PERROR_FATAL test");
    PERRORF_FATAL("PERRORF_FATAL test: %d", integer);
    printf("\n");

    return 0;
}


/**
 * @brief   Test the "cprint" series of functions by printing to console for 
 *          review.
 *
 * @return  Return 0.
 */
int test_cprint() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'cprint' functions...\n\n");

    CPRINT(C_RED, "CPRINT test.");
    printf("\n");
    CPRINTLN(C_RED, "CPRINTLN test.");
    CPRINTF(C_RED, "CPRINTF test integer: %d.", integer);
    printf("\n");
    CPRINTFLN(C_RED, "CPRINTFLN test integer: %d.", integer);
    printf("\n");


    CPRINTF(C_RED, "CPRINT_HEX test hex: %llu: ", hex);
    CPRINT_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");

    CPRINTF(C_RED, "CPRINTLN_HEX test hex: %llu: ", hex);
    CPRINTLN_HEX(C_RED, &hex, sizeof(hex));

    CPRINTF(C_RED, "CPRINT_WIDE_HEX test wide hex: %llu: ", hex);
    CPRINT_WIDE_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");

    CPRINTF(C_RED, "CPRINTLN_WIDE_HEX test wide hex: %llu: ", hex);
    CPRINTLN_WIDE_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");


    CPERROR(C_RED, "CPERROR test");
    CPERRORF(C_RED, "CPERRORF test: %d", integer);
    printf("\n");


    printf("[*] Testing 'cprint_level' functions...\n\n");

    CPRINT_TRACE(C_RED, "CPRINT_TRACE test.");
    printf("\n");
    CPRINTLN_TRACE(C_RED, "CPRINTLN_TRACE test.");
    CPRINTF_TRACE(C_RED, "CPRINTF_TRACE test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_TRACE(C_RED, "CPRINTFLN_TRACE test integer: %d.", integer);
    printf("\n");


    CPRINT_DEBUG(C_RED, "CPRINT_DEBUG test.");
    printf("\n");
    CPRINTLN_DEBUG(C_RED, "CPRINTLN_DEBUG test.");
    CPRINTF_DEBUG(C_RED, "CPRINTF_DEBUG test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_DEBUG(C_RED, "CPRINTFLN_DEBUG test integer: %d.", integer);
    printf("\n");


    CPRINT_EXTRA(C_RED, "CPRINT_EXTRA test.");
    printf("\n");
    CPRINTLN_EXTRA(C_RED, "CPRINTLN_EXTRA test.");
    CPRINTF_EXTRA(C_RED, "CPRINTF_EXTRA test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_EXTRA(C_RED, "CPRINTFLN_EXTRA test integer: %d.", integer);
    printf("\n");


    CPRINT_INFO(C_RED, "CPRINT_INFO test.");
    printf("\n");
    CPRINTLN_INFO(C_RED, "CPRINTLN_INFO test.");
    CPRINTF_INFO(C_RED, "CPRINTF_INFO test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_INFO(C_RED, "CPRINTFLN_INFO test integer: %d.", integer);
    printf("\n");


    CPRINT_HEADER(C_RED, "CPRINT_HEADER test.");
    printf("\n");
    CPRINTLN_HEADER(C_RED, "CPRINTLN_HEADER test.");
    CPRINTF_HEADER(C_RED, "CPRINTF_HEADER test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_HEADER(C_RED, "CPRINTFLN_HEADER test integer: %d.", integer);
    printf("\n");


    CPRINT_SUCCESS(C_RED, "CPRINT_SUCCESS test.");
    printf("\n");
    CPRINTLN_SUCCESS(C_RED, "CPRINTLN_SUCCESS test.");
    CPRINTF_SUCCESS(C_RED, "CPRINTF_SUCCESS test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_SUCCESS(C_RED, "CPRINTFLN_SUCCESS test integer: %d.", integer);
    printf("\n");


    CPRINT_INPUT(C_RED, "CPRINT_INPUT test.");
    printf("\n");
    CPRINTLN_INPUT(C_RED, "CPRINTLN_INPUT test.");
    CPRINTF_INPUT(C_RED, "CPRINTF_INPUT test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_INPUT(C_RED, "CPRINTFLN_INPUT test integer: %d.", integer);
    printf("\n");


    CPRINT_WARNING(C_RED, "CPRINT_WARNING test.");
    printf("\n");
    CPRINTLN_WARNING(C_RED, "CPRINTLN_WARNING test.");
    CPRINTF_WARNING(C_RED, "CPRINTF_WARNING test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_WARNING(C_RED, "CPRINTFLN_WARNING test integer: %d.", integer);
    printf("\n");


    CPRINT_ERROR(C_RED, "CPRINT_ERROR test.");
    printf("\n");
    CPRINTLN_ERROR(C_RED, "CPRINTLN_ERROR test.");
    CPRINTF_ERROR(C_RED, "CPRINTF_ERROR test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_ERROR(C_RED, "CPRINTFLN_ERROR test integer: %d.", integer);
    printf("\n");

    CPERROR_ERROR(C_RED, "PERROR_ERROR test");
    CPERRORF_ERROR(C_RED, "PERRORF_ERROR test: %d", integer);
    printf("\n");


    CPRINT_FATAL(C_RED, "CPRINT_FATAL test.");
    printf("\n");
    CPRINTLN_FATAL(C_RED, "CPRINTLN_FATAL test.");
    CPRINTF_FATAL(C_RED, "CPRINTF_FATAL test integer: %d.", integer);
    printf("\n");
    CPRINTFLN_FATAL(C_RED, "CPRINTFLN_FATAL test integer: %d.", integer);
    printf("\n");

    CPERROR_FATAL(C_RED, "CPERROR_FATAL test");
    CPERRORF_FATAL(C_RED, "CPERRORF_FATAL test: %d", integer);
    printf("\n");

    return 0;
}


/**
 * @brief   Test the "clog" series of functions by logging to console for 
 *          review.
 *
 * @return  Return 0.
 */
int test_clog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'clog' functions...\n\n");

    CLOG("CLOG test.");
    printf("\n");
    CLOGLN("CLOGLN test.");
    CLOGF("CLOGF test: %d", integer);
    printf("\n");
    CLOGFLN("CLOGFLN test: %d", integer);
    printf("\n");

    CLOG("CLOG_STREAM test: ");
    CLOG_STREAM("stream test.");
    printf("\n");
    CLOG("CLOGLN_STREAM test: ");
    CLOGLN_STREAM("stream test.");
    CLOG("CLOGF_STREAM test: ");
    CLOGF_STREAM("integer: %d", integer);
    printf("\n");
    CLOG("CLOGFLN_STREAM test: ");
    CLOGFLN_STREAM("integer: %d", integer);
    printf("\n");

    CLOG("CLOG_STREAM_HEX test: ");
    CLOG_STREAM_HEX(&hex, sizeof(hex));
    printf("\n");
    CLOG("CLOGLN_STREAM_HEX test: ");
    CLOGLN_STREAM_HEX(&hex, sizeof(hex));
    CLOG("CLOG_STREAM_WIDE_HEX test: ");
    CLOG_STREAM_WIDE_HEX(&hex, sizeof(hex));
    printf("\n");
    CLOG("CLOGLN_STREAM_WIDE_HEX test: ");
    CLOGLN_STREAM_WIDE_HEX(&hex, sizeof(hex));
    printf("\n");

    CLOG_PERROR("CLOG_PERROR test");
    CLOG_PERRORF("CLOG_PERRORF test: %d", integer);
    printf("\n");

    CLOG_T("CLOG_T test.");
    printf("\n");
    CLOGLN_T("CLOGLN_T test.");
    CLOGF_T("CLOGF_T test: %d.", integer);
    printf("\n");
    CLOGFLN_T("CLOGFLN_T test: %d.", integer);
    printf("\n");

    CLOG_PERROR_T("CLOG_PERROR_T test");
    CLOG_PERRORF_T("CLOG_PERRORF_T test: %d", integer);
    printf("\n");


    printf("[*] Testing 'cclog' functions...\n\n");

    CCLOG(C_RED, "CLOG test.");
    printf("\n");
    CCLOGLN(C_RED, "CLOGLN test.");
    CCLOGF(C_RED, "CLOGF test: %d", integer);
    printf("\n");
    CCLOGFLN(C_RED, "CLOGFLN test: %d", integer);
    printf("\n");

    CLOG("CLOG_STREAM test: ");
    CCLOG_STREAM(C_RED, "stream test.");
    printf("\n");
    CLOG("CLOGLN_STREAM test: ");
    CCLOGLN_STREAM(C_RED, "stream test.");
    CLOG("CLOGF_STREAM test: ");
    CCLOGF_STREAM(C_RED, "integer: %d", integer);
    printf("\n");
    CLOG("CLOGFLN_STREAM test: ");
    CCLOGFLN_STREAM(C_RED, "integer: %d", integer);
    printf("\n");

    CLOG("CLOG_STREAM_HEX test: ");
    CCLOG_STREAM_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");
    CLOG("CLOGLN_STREAM_HEX test: ");
    CCLOGLN_STREAM_HEX(C_RED, &hex, sizeof(hex));
    CLOG("CLOG_STREAM_WIDE_HEX test: ");
    CCLOG_STREAM_WIDE_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");
    CLOG("CLOGLN_STREAM_WIDE_HEX test: ");
    CCLOGLN_STREAM_WIDE_HEX(C_RED, &hex, sizeof(hex));
    printf("\n");

    CCLOG_PERROR(C_RED, "CLOG_PERROR test");
    CCLOG_PERRORF(C_RED, "CLOG_PERRORF test: %d", integer);
    printf("\n");

    CCLOG_T(C_RED, "CLOG_T test.");
    printf("\n");
    CCLOGLN_T(C_RED, "CLOGLN_T test.");
    CCLOGF_T(C_RED, "CLOGF_T test: %d.", integer);
    printf("\n");
    CCLOGFLN_T(C_RED, "CLOGFLN_T test: %d.", integer);
    printf("\n");

    CCLOG_PERROR_T(C_RED, "CLOG_PERROR_T test");
    CCLOG_PERRORF_T(C_RED, "CLOG_PERRORF_T test: %d", integer);
    printf("\n");


    printf("[*] Testing 'clog_<level>' functions...\n\n");

    CLOG_TRACE("CLOG_TRACE test.");
    printf("\n");
    CLOGLN_TRACE("CLOGLN_TRACE test.");
    CLOGF_TRACE("CLOGF_TRACE test integer: %d.", integer);
    printf("\n");
    CLOGFLN_TRACE("CLOGFLN_TRACE test integer: %d.", integer);
    printf("\n");


    CLOG_DEBUG("CLOG_DEBUG test.");
    printf("\n");
    CLOGLN_DEBUG("CLOGLN_DEBUG test.");
    CLOGF_DEBUG("CLOGF_DEBUG test integer: %d.", integer);
    printf("\n");
    CLOGFLN_DEBUG("CLOGFLN_DEBUG test integer: %d.", integer);
    printf("\n");


    CLOG_EXTRA("CLOG_EXTRA test.");
    printf("\n");
    CLOGLN_EXTRA("CLOGLN_EXTRA test.");
    CLOGF_EXTRA("CLOGF_EXTRA test integer: %d.", integer);
    printf("\n");
    CLOGFLN_EXTRA("CLOGFLN_EXTRA test integer: %d.", integer);
    printf("\n");


    CLOG_INFO("CLOG_INFO test.");
    printf("\n");
    CLOGLN_INFO("CLOGLN_INFO test.");
    CLOGF_INFO("CLOGF_INFO test integer: %d.", integer);
    printf("\n");
    CLOGFLN_INFO("CLOGFLN_INFO test integer: %d.", integer);
    printf("\n");


    CLOG_HEADER("CLOG_HEADER test.");
    printf("\n");
    CLOGLN_HEADER("CLOGLN_HEADER test.");
    CLOGF_HEADER("CLOGF_HEADER test integer: %d.", integer);
    printf("\n");
    CLOGFLN_HEADER("CLOGFLN_HEADER test integer: %d.", integer);
    printf("\n");


    CLOG_SUCCESS("CLOG_SUCCESS test.");
    printf("\n");
    CLOGLN_SUCCESS("CLOGLN_SUCCESS test.");
    CLOGF_SUCCESS("CLOGF_SUCCESS test integer: %d.", integer);
    printf("\n");
    CLOGFLN_SUCCESS("CLOGFLN_SUCCESS test integer: %d.", integer);
    printf("\n");


    CLOG_INPUT("CLOG_INPUT test.");
    printf("\n");
    CLOGLN_INPUT("CLOGLN_INPUT test.");
    CLOGF_INPUT("CLOGF_INPUT test integer: %d.", integer);
    printf("\n");
    CLOGFLN_INPUT("CLOGFLN_INPUT test integer: %d.", integer);
    printf("\n");


    CLOG_WARNING("CLOG_WARNING test.");
    printf("\n");
    CLOGLN_WARNING("CLOGLN_WARNING test.");
    CLOGF_WARNING("CLOGF_WARNING test integer: %d.", integer);
    printf("\n");
    CLOGFLN_WARNING("CLOGFLN_WARNING test integer: %d.", integer);
    printf("\n");

    CLOG_PERROR_WARNING("CLOG_PERROR_ERROR test");
    CLOG_PERRORF_WARNING("CLOG_PERRORF_ERROR test: %d", integer);
    printf("\n");


    CLOG_ERROR("CLOG_ERROR test.");
    printf("\n");
    CLOGLN_ERROR("CLOGLN_ERROR test.");
    CLOGF_ERROR("CLOGF_ERROR test integer: %d.", integer);
    printf("\n");
    CLOGFLN_ERROR("CLOGFLN_ERROR test integer: %d.", integer);
    printf("\n");

    CLOG_PERROR_ERROR("CLOG_PERROR_ERROR test");
    CLOG_PERRORF_ERROR("CLOG_PERRORF_ERROR test: %d", integer);
    printf("\n");


    CLOG_FATAL("CLOG_FATAL test.");
    printf("\n");
    CLOGLN_FATAL("CLOGLN_FATAL test.");
    CLOGF_FATAL("CLOGF_FATAL test integer: %d.", integer);
    printf("\n");
    CLOGFLN_FATAL("CLOGFLN_FATAL test integer: %d.", integer);
    printf("\n");

    CLOG_PERROR_FATAL("CLOG_PERROR_FATAL test");
    CLOG_PERRORF_FATAL("CLOG_PERRORF_FATAL test: %d", integer);
    printf("\n");

    return 0;
}


/**
 * @brief   Test the "flog" series of functions by logging to file for 
 *          review.
 *
 * @return  Return 0.
 */
int test_flog() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'flog' functions...\n\n");

    FLOG("FLOG test.");
    FLOGLN_STREAM(" ");
    FLOGLN("FLOGLN test.");
    FLOGF("FLOGF test: %d", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN("FLOGFLN test: %d", integer);

    FLOG("FLOG_STREAM test: ");
    FLOG_STREAM("stream test.");
    FLOGLN_STREAM(" ");
    FLOG("FLOGLN_STREAM test: ");
    FLOGLN_STREAM("stream test.");
    FLOG("FLOGF_STREAM test: ");
    FLOGF_STREAM("integer: %d", integer);
    FLOGLN_STREAM(" ");
    FLOG("FLOGFLN_STREAM test: ");
    FLOGFLN_STREAM("integer: %d", integer);

    FLOG("FLOG_STREAM_HEX test: ");
    FLOG_STREAM_HEX(&hex, sizeof(hex));
    FLOGLN_STREAM(" ");
    FLOG("FLOGLN_STREAM_HEX test: ");
    FLOGLN_STREAM_HEX(&hex, sizeof(hex));
    FLOG("FLOG_STREAM_WIDE_HEX test: ");
    FLOG_STREAM_WIDE_HEX(&hex, sizeof(hex));
    FLOGLN_STREAM(" ");
    FLOG("FLOGLN_STREAM_WIDE_HEX test: ");
    FLOGLN_STREAM_WIDE_HEX(&hex, sizeof(hex));

    FLOG_PERROR("FLOG_PERROR test");
    FLOG_PERRORF("FLOG_PERRORF test: %d", integer);

    FLOG_T("FLOG_T test.");
    FLOGLN_STREAM(" ");
    FLOGLN_T("FLOGLN_T test.");
    FLOGF_T("FLOGF_T test: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_T("FLOGFLN_T test: %d.", integer);

    FLOG_PERROR_T("FLOG_PERROR_T test");
    FLOG_PERRORF_T("FLOG_PERRORF_T test: %d", integer);


    printf("[*] Testing 'flog_<level>' functions...\n\n");

    FLOG_TRACE("FLOG_TRACE test.");
    FLOGLN_STREAM(" ");
    FLOGLN_TRACE("FLOGLN_TRACE test.");
    FLOGF_TRACE("FLOGF_TRACE test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_TRACE("FLOGFLN_TRACE test integer: %d.", integer);


    FLOG_DEBUG("FLOG_DEBUG test.");
    FLOGLN_STREAM(" ");
    FLOGLN_DEBUG("FLOGLN_DEBUG test.");
    FLOGF_DEBUG("FLOGF_DEBUG test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_DEBUG("FLOGFLN_DEBUG test integer: %d.", integer);


    FLOG_EXTRA("FLOG_EXTRA test.");
    FLOGLN_STREAM(" ");
    FLOGLN_EXTRA("FLOGLN_EXTRA test.");
    FLOGF_EXTRA("FLOGF_EXTRA test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_EXTRA("FLOGFLN_EXTRA test integer: %d.", integer);


    FLOG_INFO("FLOG_INFO test.");
    FLOGLN_STREAM(" ");
    FLOGLN_INFO("FLOGLN_INFO test.");
    FLOGF_INFO("FLOGF_INFO test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_INFO("FLOGFLN_INFO test integer: %d.", integer);


    FLOG_HEADER("FLOG_HEADER test.");
    FLOGLN_STREAM(" ");
    FLOGLN_HEADER("FLOGLN_HEADER test.");
    FLOGF_HEADER("FLOGF_HEADER test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_HEADER("FLOGFLN_HEADER test integer: %d.", integer);


    FLOG_SUCCESS("FLOG_SUCCESS test.");
    FLOGLN_STREAM(" ");
    FLOGLN_SUCCESS("FLOGLN_SUCCESS test.");
    FLOGF_SUCCESS("FLOGF_SUCCESS test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_SUCCESS("FLOGFLN_SUCCESS test integer: %d.", integer);


    FLOG_INPUT("FLOG_INPUT test.");
    FLOGLN_STREAM(" ");
    FLOGLN_INPUT("FLOGLN_INPUT test.");
    FLOGF_INPUT("FLOGF_INPUT test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_INPUT("FLOGFLN_INPUT test integer: %d.", integer);


    FLOG_WARNING("FLOG_WARNING test.");
    FLOGLN_STREAM(" ");
    FLOGLN_WARNING("FLOGLN_WARNING test.");
    FLOGF_WARNING("FLOGF_WARNING test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_WARNING("FLOGFLN_WARNING test integer: %d.", integer);

    FLOG_PERROR_WARNING("FLOG_PERROR_WARNING test");
    FLOG_PERRORF_WARNING("FLOG_PERRORF_WARNING test: %d", integer);


    FLOG_ERROR("FLOG_ERROR test.");
    FLOGLN_STREAM(" ");
    FLOGLN_ERROR("FLOGLN_ERROR test.");
    FLOGF_ERROR("FLOGF_ERROR test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_ERROR("FLOGFLN_ERROR test integer: %d.", integer);

    FLOG_PERROR_ERROR("FLOG_PERROR_ERROR test");
    FLOG_PERRORF_ERROR("FLOG_PERRORF_ERROR test: %d", integer);


    FLOG_FATAL("FLOG_FATAL test.");
    FLOGLN_STREAM(" ");
    FLOGLN_FATAL("FLOGLN_FATAL test.");
    FLOGF_FATAL("FLOGF_FATAL test integer: %d.", integer);
    FLOGLN_STREAM(" ");
    FLOGFLN_FATAL("FLOGFLN_FATAL test integer: %d.", integer);

    FLOG_PERROR_FATAL("FLOG_PERROR_FATAL test");
    FLOG_PERRORF_FATAL("FLOG_PERRORF_FATAL test: %d", integer);

    return 0;
}


/**
 * @brief   Test the "log" series of functions by logging to console and a 
 *          file for review.
 *
 * @return  Return 0.
 */
int test_log() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing 'log' functions...\n\n");

    LOG("LOG test.");
    LOGLN_STREAM(" ");
    LOGLN("LOGLN test.");
    LOGF("LOGF test: %d", integer);
    LOGLN_STREAM(" ");
    LOGFLN("LOGFLN test: %d", integer);
    printf("\n");

    LOG("LOG_STREAM test: ");
    LOG_STREAM("stream test.");
    LOGLN_STREAM(" ");
    LOG("LOGLN_STREAM test: ");
    LOGLN_STREAM("stream test.");
    LOG("LOGF_STREAM test: ");
    LOGF_STREAM("integer: %d", integer);
    LOGLN_STREAM(" ");
    LOG("LOGFLN_STREAM test: ");
    LOGFLN_STREAM("integer: %d", integer);
    printf("\n");

    LOG("LOG_STREAM_HEX test: ");
    LOG_STREAM_HEX(&hex, sizeof(hex));
    LOGLN_STREAM(" ");
    LOG("LOGLN_STREAM_HEX test: ");
    LOGLN_STREAM_HEX(&hex, sizeof(hex));
    LOG("LOG_STREAM_WIDE_HEX test: ");
    LOG_STREAM_WIDE_HEX(&hex, sizeof(hex));
    LOGLN_STREAM(" ");
    LOG("LOGLN_STREAM_WIDE_HEX test: ");
    LOGLN_STREAM_WIDE_HEX(&hex, sizeof(hex));
    printf("\n");

    LOG_PERROR("LOG_PERROR test");
    LOG_PERRORF("LOG_PERRORF test: %d", integer);
    printf("\n");

    LOG_T("LOG_T test.");
    LOGLN_STREAM(" ");
    LOGLN_T("LOGLN_T test.");
    LOGF_T("LOGF_T test: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_T("LOGFLN_T test: %d.", integer);
    printf("\n");

    LOG_PERROR_T("LOG_PERROR_T test");
    LOG_PERRORF_T("LOG_PERRORF_T test: %d", integer);
    printf("\n");


    printf("[*] Testing 'log_<level>' functions...\n\n");

    LOG_TRACE("LOG_TRACE test.");
    LOGLN_STREAM(" ");
    LOGLN_TRACE("LOGLN_TRACE test.");
    LOGF_TRACE("LOGF_TRACE test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_TRACE("LOGFLN_TRACE test integer: %d.", integer);
    printf("\n");


    LOG_DEBUG("LOG_DEBUG test.");
    LOGLN_STREAM(" ");
    LOGLN_DEBUG("LOGLN_DEBUG test.");
    LOGF_DEBUG("LOGF_DEBUG test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_DEBUG("LOGFLN_DEBUG test integer: %d.", integer);
    printf("\n");


    LOG_EXTRA("LOG_EXTRA test.");
    LOGLN_STREAM(" ");
    LOGLN_EXTRA("LOGLN_EXTRA test.");
    LOGF_EXTRA("LOGF_EXTRA test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_EXTRA("LOGFLN_EXTRA test integer: %d.", integer);
    printf("\n");


    LOG_INFO("LOG_INFO test.");
    LOGLN_STREAM(" ");
    LOGLN_INFO("LOGLN_INFO test.");
    LOGF_INFO("LOGF_INFO test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_INFO("LOGFLN_INFO test integer: %d.", integer);
    printf("\n");


    LOG_HEADER("LOG_HEADER test.");
    LOGLN_STREAM(" ");
    LOGLN_HEADER("LOGLN_HEADER test.");
    LOGF_HEADER("LOGF_HEADER test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_HEADER("LOGFLN_HEADER test integer: %d.", integer);
    printf("\n");


    LOG_SUCCESS("LOG_SUCCESS test.");
    LOGLN_STREAM(" ");
    LOGLN_SUCCESS("LOGLN_SUCCESS test.");
    LOGF_SUCCESS("LOGF_SUCCESS test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_SUCCESS("LOGFLN_SUCCESS test integer: %d.", integer);
    printf("\n");


    LOG_INPUT("LOG_INPUT test.");
    LOGLN_STREAM(" ");
    LOGLN_INPUT("LOGLN_INPUT test.");
    LOGF_INPUT("LOGF_INPUT test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_INPUT("LOGFLN_INPUT test integer: %d.", integer);
    printf("\n");


    LOG_WARNING("LOG_WARNING test.");
    LOGLN_STREAM(" ");
    LOGLN_WARNING("LOGLN_WARNING test.");
    LOGF_WARNING("LOGF_WARNING test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_WARNING("LOGFLN_WARNING test integer: %d.", integer);
    printf("\n");

    LOG_PERROR_WARNING("LOG_PERROR_WARNING test");
    LOG_PERRORF_WARNING("LOG_PERRORF_WARNING test: %d", integer);
    printf("\n");


    LOG_ERROR("LOG_ERROR test.");
    LOGLN_STREAM(" ");
    LOGLN_ERROR("LOGLN_ERROR test.");
    LOGF_ERROR("LOGF_ERROR test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_ERROR("LOGFLN_ERROR test integer: %d.", integer);
    printf("\n");

    LOG_PERROR_ERROR("LOG_PERROR_ERROR test");
    LOG_PERRORF_ERROR("LOG_PERRORF_ERROR test: %d", integer);
    printf("\n");


    LOG_FATAL("LOG_FATAL test.");
    LOGLN_STREAM(" ");
    LOGLN_FATAL("LOGLN_FATAL test.");
    LOGF_FATAL("LOGF_FATAL test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_FATAL("LOGFLN_FATAL test integer: %d.", integer);
    printf("\n");

    LOG_PERROR_FATAL("LOG_PERROR_FATAL test");
    LOG_PERRORF_FATAL("LOG_PERRORF_FATAL test: %d", integer);
    printf("\n");

    return 0;
}


/**
 * @brief   Test the log level switches.
 *
 * @return  Return 0.
 */
int test_log_custom() {

    int integer = 1234567890;
    unsigned long long hex = __bswap_constant_64(0xcafebabebaddecaf);

    printf("[*] Testing log levels...\n\n");

    #undef CSYM_TRACE
    #define CSYM_TRACE "🍄 "

    #undef C_TRACE
    #define C_TRACE C_YELLOW

    #undef CSYM_DEBUG
    #define CSYM_DEBUG "<x> "

    #undef C_DEBUG
    #define C_DEBUG C_ORANGE

    LOG_TRACE("LOG_TRACE test.");
    LOGLN_STREAM(" ");
    LOGLN_TRACE("LOGLN_TRACE test.");
    LOGF_TRACE("LOGF_TRACE test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_TRACE("LOGFLN_TRACE test integer: %d.", integer);
    printf("\n");


    LOG_DEBUG("LOG_DEBUG test.");
    LOGLN_STREAM(" ");
    LOGLN_DEBUG("LOGLN_DEBUG test.");
    LOGF_DEBUG("LOGF_DEBUG test integer: %d.", integer);
    LOGLN_STREAM(" ");
    LOGFLN_DEBUG("LOGFLN_DEBUG test integer: %d.", integer);
    printf("\n");

    return 0;
}


