#ifndef ISA_H_
#define ISA_H_

#include <stdint.h>
#ifdef RVE_EXTENSION
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

struct Context
{
    uint32_t mepc, mcause, mstatus;
    uint32_t regs[NR_REGS];
};

#endif