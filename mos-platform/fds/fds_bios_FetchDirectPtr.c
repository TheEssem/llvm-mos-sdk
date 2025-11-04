#include <peekpoke.h>

extern void __FETCH_DIRECT_PTR(void) __attribute__((leaf));

void *fds_bios_FetchDirectPtr(void) {
  __FETCH_DIRECT_PTR();
  return (void *)PEEKW(0x00);
}
