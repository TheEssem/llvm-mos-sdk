#include <peekpoke.h>

extern void __PIXEL_TO_NAM_CONV(void) __attribute__((leaf));

unsigned fds_Pixel2NamConv(unsigned char y, unsigned char x) {
  POKE(0x02, y);
  POKE(0x03, x);
  __PIXEL_TO_NAM_CONV();
  return PEEKW(0x00);
}
