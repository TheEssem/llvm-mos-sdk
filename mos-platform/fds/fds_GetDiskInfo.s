.text

__fds_GetDiskInfo:
  jsr __GET_DISK_INFO
  .word $ADDE
  rts

;
; char fds_GetDiskInfo (struct fds_disk_id *disk_id);
;
.global fds_GetDiskInfo
fds_GetDiskInfo:
  lda __rc2
  sta [__fds_GetDiskInfo+3]
  lda __rc3
  sta [__fds_GetDiskInfo+4]
  jsr __fds_GetDiskInfo
  rts
