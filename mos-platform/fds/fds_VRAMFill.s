.text

;
; void fds_VRAMFill (char tile_row, char value, char rows_attr);
;
.global fds_VRAMFill
fds_MemFill:
  ldy __rc2
  jsr __VRAM_FILL
  rts
