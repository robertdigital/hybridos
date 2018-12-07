#include "cbplus.h"

#include <cstdlib>

#include <hfcl/hfcl.h>
#include <hfcl/common.h>
#include <hfcl/activity.h>
#include <hfcl/view.h>
#include <hfcl/drawable.h>
#include <hfcl/resource.h>

#include "bootupactivity.h"
#include "sys-res.h"

int main (int argc, const char** argv)
{
    InitHFCL (argc, argv);

    // register system resource
    FRRegister_sys_resource();

    if (!SetResourceLanguage (R_LANG_zh_CN)) {
        _ERR_PRINTF ("cbplus: Failed when calling SetResourceLanguage with %d\n",
                R_LANG_zh_CN);
        return 1;
    }

    REGISTER_ACTIVITY("bootup", BootupActivity);

    ActivityManager* act_mgr = ActivityManager::getInstance();

    int boot_type = 0;
    if (argc > 1) {
        boot_type = atoi (argv [1]);
    }

    Intent intent(boot_type, 0, 0);
    act_mgr->startActivity ("bootup", &intent);
    act_mgr->run();

    return 0;
}

