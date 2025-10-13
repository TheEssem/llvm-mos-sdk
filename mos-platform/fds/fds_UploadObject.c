#include <peekpoke.h>

extern void __UPLOAD_OBJECT(void) __attribute__((leaf));

void fds_UploadObject(struct fds_object *obj) {
  POKEW(0x00, (unsigned int)obj);
  __UPLOAD_OBJECT();
}
