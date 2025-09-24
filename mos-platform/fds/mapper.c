#include <peekpoke.h>

#define FDS_CTRL 0x8000

__attribute__((weak)) void set_fds_ctrl(char value) {
  POKE(FDS_CTRL, value);
}