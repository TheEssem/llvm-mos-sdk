.text

__fds_AdjustFileCount:
  jsr __ADJUST_FILE_COUNT
  ; Some BIOS functions require pointers to be provided by specifying them
  ; right after the function call, inline with the rest of the routine.
  ; This means that pointers are typically provided statically;
  ; to make it dynamic and give these functions a more familiar C interface,
  ; a form of self-modifying code is used to alter the pointer argument during runtime.
  .word $ADDE
  rts

;
; char fds_AdjustFileCount (struct fds_disk_id *disk_id, char count);
;
.global fds_AdjustFileCount
fds_AdjustFileCount:
  ldx __rc2
  stx [__fds_AdjustFileCount+3]
  ldx __rc3
  stx [__fds_AdjustFileCount+4]
  jsr __fds_AdjustFileCount
  rts
