.text

;
; void fds_MemFill (char value, char start, char end);
;
.global fds_MemFill
fds_MemFill:
  ldy __rc2
  jsr __MEM_FILL
  rts
