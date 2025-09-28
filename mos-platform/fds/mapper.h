#ifndef _MAPPER_H_
#define _MAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

// Set all 8 bits of the $4025 FDS Control register.
__attribute__((leaf)) void set_fds_ctrl(char value);

#define MIRROR_VERTICAL 0
#define MIRROR_HORIZONTAL 1

// Set the current mirroring mode. Your options are
// MIRROR_HORIZONTAL, and MIRROR_VERTICAL.
__attribute__((leaf)) void set_mirroring(char mirroring);

#ifdef __cplusplus
}
#endif

#endif
