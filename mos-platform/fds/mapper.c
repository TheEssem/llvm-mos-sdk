#include <peekpoke.h>

#define FDS_CTRL 0x4025
#define FDS_CTRL_MIRROR 0xFA

__attribute__((weak)) void set_fds_ctrl(char value) {
  POKE(FDS_CTRL_MIRROR, value);
  POKE(FDS_CTRL, value);
}
