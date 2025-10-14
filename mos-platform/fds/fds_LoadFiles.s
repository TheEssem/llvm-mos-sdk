.text

__fds_LoadFiles:
  jsr __LOAD_FILES
  .word $ADDE
  .word $EFBE
  rts

;
; char fds_LoadFiles (struct fds_disk_id *disk_id, char *file_ids, char *loaded);
;
.global fds_LoadFiles
fds_LoadFiles:
  lda __rc2
  sta [__fds_LoadFiles+3]
  lda __rc3
  sta [__fds_LoadFiles+4]
  lda __rc4
  sta [__fds_LoadFiles+5]
  lda __rc5
  sta [__fds_LoadFiles+6]
  jsr __fds_LoadFiles
  bne 1f
  pha
  tya
  ldy #0
  sta (__rc6),y
  pla
1:
  rts
