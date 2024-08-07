#include <stdio.h>

#include "platform/platform.h"

int printf(const char *fmt, ...)
{
    halt(1);
    return 0;
}

int vsprintf(char *out, const char *fmt, va_list ap)
{
    halt(1);
    return 0;
}

int sprintf(char *out, const char *fmt, ...)
{
    halt(1);
    return 0;
}

int snprintf(char *out, size_t n, const char *fmt, ...)
{
    halt(1);
    return 0;
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap)
{
    halt(1);
    return 0;
}