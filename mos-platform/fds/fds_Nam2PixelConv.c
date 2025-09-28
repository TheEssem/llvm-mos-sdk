#include <peekpoke.h>

extern void __NAM_TO_PIXEL_CONV(void) __attribute__((leaf));

/* ?? */ /*unsigned char fds_Nam2PixelConv(unsigned addr) {
  POKEW(0x00, addr);
  __NAM_TO_PIXEL_CONV();
  PEEK(0x02);
  PEEK(0x03);
  }*/
