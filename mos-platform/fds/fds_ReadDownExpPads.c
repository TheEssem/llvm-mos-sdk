extern void __READ_DOWN_EXP_PADS(void) __attribute__((leaf));

struct fds_trans_exp_pads *fds_ReadDownExpPads(void) {
  __READ_DOWN_EXP_PADS();
  return (struct fds_trans_exp_pads *)0xF1;
}
