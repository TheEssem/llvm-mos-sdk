#include <peekpoke.h>

#define FDS_CTRL 0x4025
#define FDS_CTRL_MIRROR 0xFA

#define FDS_EXT 0x4026
#define FDS_EXT_MIRROR 0xF9

__attribute__((leaf)) void set_fds_ctrl(char value) {
  POKE(FDS_CTRL_MIRROR, value);
  POKE(FDS_CTRL, value);
}

__attribute__((leaf)) void write_ext_data(char value) {
  POKE(FDS_EXT_MIRROR, value);
  POKE(FDS_EXT, value);
}
