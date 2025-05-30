
#include "clog.h"


static void static_function1() {
    LOGLN_INFO("Static function in different object test.");
}


void function2() {
    LOGLN_INFO("Function 2 in a different object test.");
    static_function1();
}


