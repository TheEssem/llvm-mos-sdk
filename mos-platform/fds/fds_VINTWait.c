extern void __VINT_WAIT(void) __attribute__((leaf));

void fds_VINTWait(void) { __VINT_WAIT(); }
