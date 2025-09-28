extern void __EN_PF(void) __attribute__((leaf));

void fds_EnPF(void) { __EN_PF(); }
