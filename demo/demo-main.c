
#include "demo.h"
#include "demo-1.h"
#include "demo-2.h"


#define RESET       "\x1b[0m"
#define BOLD        "\x1b[1m"
#define YELLOW      "\x1b[93m"

#define HEADER(str) \
    printf( \
        BOLD YELLOW "%.*s %s %.*s%s" RESET "\n\n", \
        (int)(80 - strlen(str)- 2)/2, \
        "========================================================", \
        str, \
        (int)(80 - strlen(str)- 2)/2, \
        "========================================================", \
        strlen(str) % 2 ? "=" : "" \
    )


/**
 * @brief   Main function to initiate tests.
 *
 * @return  Return 0 if tests pass; otherwise return 1.
 */
int main() {

    HEADER("RUNNING DEMO");
    demo();
    demo_1();
    demo_2();

    return 0;
}


