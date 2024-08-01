#include "check/check.h"

#include "platform/platform.h"

void check(bool cond)
{
    if (!cond)
    {
        halt(1);
    }
}