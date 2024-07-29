int main();

// no inline
__attribute__((noinline)) void nemu_trap(int code) {
#ifdef ISA_RISC_V
  asm volatile("mv a0, %0\n"
               "ebreak"
               :
               : "r"(code)
               : "a0");
#endif // ISA_RISC_V
}

__attribute__((noinline)) void halt(int code) {
  nemu_trap(code);

  // should not reach here
  for (;;)
    ;
}

void _trm_init() {
  int ret = main();
  halt(ret);
}
