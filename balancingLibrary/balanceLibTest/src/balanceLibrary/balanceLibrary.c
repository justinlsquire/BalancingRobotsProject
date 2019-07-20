#include "balanceLibrary.h"


// functions for doing controller update

void updateController(struct robot * rbt)
{
    // update euler angle estimates
    if (rbt->estimatorType == ESTIMATOR_COMPLEMENTARY)
    {
        if (rbt->hasAccel)
        {
            // get arctan function output for angle
        } // update

        rbt->ex = 2; // test
    }
 
} // end of updateController
