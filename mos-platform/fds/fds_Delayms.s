.text

;
; void fds_Delayms (char delay);
;
.global fds_Delayms
fds_Delayms:
  tay
  jsr __DELAY_MS
  rts
