extern void __DIS_PF(void) __attribute__((leaf));

void fds_DisPF(void) { __DIS_PF(); }
