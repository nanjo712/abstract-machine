#include <stddef.h>
#include <string.h>

#include "platform/platform.h"

void *memset(void *s, int c, size_t n)
{
    // simple implementation
    // assert(s != NULL);
    for (size_t i = 0; i < n; i++)
    {
        ((char *)s)[i] = c;
    }
    return NULL;
}

void *memcpy(void *dst, const void *src, size_t n)
{
    // simple implementation
    // assert(dst != NULL);
    // assert(src != NULL);
    for (size_t i = 0; i < n; i++)
    {
        ((char *)dst)[i] = ((char *)src)[i];
    }
    return NULL;
}

void *memmove(void *dst, const void *src, size_t n)
{
    // simple implementation
    // assert(dst != NULL);
    // assert(src != NULL);
    if (dst < src)
    {
        for (size_t i = 0; i < n; i++)
        {
            ((char *)dst)[i] = ((char *)src)[i];
        }
    }
    else
    {
        for (size_t i = n; i > 0; i--)
        {
            ((char *)dst)[i - 1] = ((char *)src)[i - 1];
        }
    }
    return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    halt(1);
    return 0;
}

size_t strlen(const char *s)
{
    halt(1);
    return 0;
}

char *strcat(char *dst, const char *src)
{
    halt(1);
    return NULL;
}

char *strcpy(char *dst, const char *src)
{
    halt(1);
    return NULL;
}

char *strncpy(char *dst, const char *src, size_t n)
{
    halt(1);
    return NULL;
}

int strcmp(const char *s1, const char *s2)
{
    halt(1);
    return 0;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
    halt(1);
    return 0;
}