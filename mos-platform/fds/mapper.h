#ifndef _MAPPER_H_
#define _MAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Set all 8 bits of the $4025 FDS Control register.
__attribute__((leaf)) void set_fds_ctrl(char value);

// Write 7-bit data to the rear expansion port ($4026).
__attribute__((leaf)) void write_ext_data(char value);

struct __fds_read {
    unsigned char disk_status;
    unsigned char data;
    unsigned char drive_status;
    unsigned char ext_data;
};

#define FDS_READ (*(volatile struct __fds_read*)0x4030)

#define MIRROR_VERTICAL 0
#define MIRROR_HORIZONTAL 1

// Set the current mirroring mode. Your options are
// MIRROR_HORIZONTAL, and MIRROR_VERTICAL.
__attribute__((leaf)) void set_mirroring(char mirroring);

#ifdef __cplusplus
}
#endif

#endif
