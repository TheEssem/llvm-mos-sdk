.text

;
; void fds_VRAMFill (char tile_row, char value, char rows_attr);
;
.global fds_VRAMFill
fds_VRAMFill:
  ldy __rc2
  jsr __VRAM_FILL
  rts
