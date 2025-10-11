extern void __READ_DOWN_VERIFY_PADS(void) __attribute__((leaf));

struct fds_trans_pads *fds_ReadDownVerifyPads(void) {
  __READ_DOWN_VERIFY_PADS();
  return (struct fds_trans_pads *)0xF5;
}
