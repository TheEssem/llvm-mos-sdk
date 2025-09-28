.text

;
; void fds_Delayms (void);
;
.global fds_Delayms
fds_Delayms:
  tay
  jsr __DELAY_MS
  rts
