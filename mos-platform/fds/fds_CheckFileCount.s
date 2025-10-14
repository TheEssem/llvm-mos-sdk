.text

__fds_CheckFileCount:
  jsr __CHECK_FILE_COUNT
  .word $ADDE
  rts

;
; char fds_CheckFileCount (struct fds_disk_id *disk_id, char count);
;
.global fds_CheckFileCount
fds_CheckFileCount:
  ldx __rc2
  stx [__fds_CheckFileCount+3]
  ldx __rc3
  stx [__fds_CheckFileCount+4]
  jsr __fds_CheckFileCount
  rts
