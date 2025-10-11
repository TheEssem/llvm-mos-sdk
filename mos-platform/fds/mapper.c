#include "mapper.h"
#include <peekpoke.h>

#define FDS_IO 0x4023

#define FDS_WRITE 0x4024

#define FDS_CTRL 0x4025
#define FDS_CTRL_MIRROR 0xFA

#define FDS_EXT 0x4026
#define FDS_EXT_MIRROR 0xF9

#define DISK_IO 0x01
#define SOUND_IO 0x02

__attribute__((section(".zp.bss"))) volatile char _IO_ENABLED;

__attribute__((leaf)) void set_disk_io(bool value) {
  char old = _IO_ENABLED;
  _IO_ENABLED = (old & (~DISK_IO)) | (value ? DISK_IO : 0);
  POKE(FDS_IO, _IO_ENABLED);
}

__attribute__((leaf)) void set_sound_io(bool value) {
  char old = _IO_ENABLED;
  _IO_ENABLED = (old & (~SOUND_IO)) | (value ? SOUND_IO : 0);
  POKE(FDS_IO, _IO_ENABLED);
}

__attribute__((leaf)) void write_disk_data(char value) {
  POKE(FDS_WRITE, value);
}

__attribute__((leaf)) void set_fds_ctrl(char value) {
  POKE(FDS_CTRL_MIRROR, value);
  POKE(FDS_CTRL, value);
}

__attribute__((leaf)) void write_ext_data(char value) {
  POKE(FDS_EXT_MIRROR, value);
  POKE(FDS_EXT, value);
}
