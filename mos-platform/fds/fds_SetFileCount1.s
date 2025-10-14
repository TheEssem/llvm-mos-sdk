.text

__fds_SetFileCount1:
  jsr __SET_FILE_COUNT_1
  .word $ADDE
  rts

;
; char fds_SetFileCount1 (struct fds_disk_id *disk_id, char count);
;
.global fds_SetFileCount1
fds_SetFileCount1:
  ldx __rc2
  stx [__fds_SetFileCount1+3]
  ldx __rc3
  stx [__fds_SetFileCount1+4]
  jsr __fds_SetFileCount1
  rts
