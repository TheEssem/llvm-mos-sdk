#include <peekpoke.h>

extern void __SKIP_FILES(void) __attribute__((leaf));

void fds_SkipFiles(unsigned char num) {
  POKE(0x06, num);
  __SKIP_FILES();
}
