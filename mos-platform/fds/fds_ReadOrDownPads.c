extern void __READ_OR_DOWN_PADS(void) __attribute__((leaf));

struct fds_trans_pads *fds_ReadOrDownPads(void) {
  __READ_OR_DOWN_PADS();
  return (struct fds_trans_pads *)0xF5;
}
