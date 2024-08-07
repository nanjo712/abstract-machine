#ifndef ASSERT_H_
#define ASSERT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define assert(cond) \
    if (!(cond))     \
    {                \
        halt(1);     \
    }

#ifdef __cplusplus
}
#endif

#endif  // ASSERT_H_