
#include "test.h"
#include "test-clog-colors.h"
#include "test-constants.h"
#include "test-fprint.h"
#include "test-cfprint.h"
#include "test-print.h"
#include "test-cprint.h"
#include "test-clog.h"
#include "test-cclog.h"
#include "test-flog.h"
#include "test-log.h"
#include "test-config-1.h"
#include "test-config-2.h"
#include "test-config-3.h"
#include "test-config-4.h"
#include "test-config-5.h"
#include "test-config-6.h"
#include "test-config-7.h"
#include "test-config-8.h"
#include "test-config-9.h"
#include "test-config-10.h"
#include "test-config-11.h"
#include "test-config-12.h"
#include "test-config-13.h"
#include "test-config-14.h"
#include "test-config-15.h"
#include "test-config-16.h"
#include "test-config-17.h"


/**
 * @brief   Main function to initiate tests.
 *
 * @return  Return 0 if tests pass; otherwise return 1.
 */
int main() {

    int ret = true;
    struct unit* units = NULL;

    // Register assert action.
    sigaction(SIGABRT, &sa, NULL);

    // Test units.
    UNIT_HEADER("STARTING TESTS");
    ADD_UNIT(units, unit_clog_colors());
    ADD_UNIT(units, unit_constants());
    ADD_UNIT(units, unit_fprint());
    ADD_UNIT(units, unit_cfprint());
    ADD_UNIT(units, unit_print());
    ADD_UNIT(units, unit_cprint());
    ADD_UNIT(units, unit_clog());
    ADD_UNIT(units, unit_cclog());
    ADD_UNIT(units, unit_flog());
    ADD_UNIT(units, unit_log());
    ADD_UNIT(units, unit_config_1());
    ADD_UNIT(units, unit_config_2());
    ADD_UNIT(units, unit_config_3());
    ADD_UNIT(units, unit_config_4());
    ADD_UNIT(units, unit_config_5());
    ADD_UNIT(units, unit_config_6());
    ADD_UNIT(units, unit_config_7());
    ADD_UNIT(units, unit_config_8());
    ADD_UNIT(units, unit_config_9());
    ADD_UNIT(units, unit_config_10());
    ADD_UNIT(units, unit_config_11());
    ADD_UNIT(units, unit_config_12());
    ADD_UNIT(units, unit_config_13());
    ADD_UNIT(units, unit_config_14());
    ADD_UNIT(units, unit_config_15());
    ADD_UNIT(units, unit_config_16());
    ADD_UNIT(units, unit_config_17());

    // Print summary. Don't need to free everything as exit is next.
    DID_UNITS_PASS(units, ret);
    REVERSE_LIST(units);
    PRINT_UNITS_RESULTS(units);

    return !ret;
}


