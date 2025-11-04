.text

;
; char fds_bios_ReadKeyboard(struct fds_bios_keyboard_data *data);
;
.global fds_bios_ReadKeyboard
fds_bios_ReadKeyboard:
  jsr __READ_KEYBOARD
  pha
  ldx #0
  ldy #0
1:
  lda $0,x
  sta (__rc2),y
  inx
  iny
  cpx #9
  bne 1b
  pla
  rts
