.text

__fds_AppendFile:
  jsr __APPEND_FILE
  .word $ADDE
  .word $EFBE
  rts

;
; char fds_AppendFile (struct fds_disk_id *disk_id, struct fds_file_header *file_header);
;
.global fds_AppendFile
fds_AppendFile:
  lda __rc2
  sta [__fds_AppendFile+3]
  lda __rc3
  sta [__fds_AppendFile+4]
  lda __rc4
  sta [__fds_AppendFile+5]
  lda __rc5
  sta [__fds_AppendFile+6]
  jsr __fds_AppendFile
  rts
