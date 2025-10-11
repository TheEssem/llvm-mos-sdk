.text

;
; void fds_UploadObject (struct fds_object *obj);
;
.global fds_UploadObject
fds_UploadObject:
  lda __rc2
  sta $00
  lda __rc3
  sta $01
  jsr __UPLOAD_OBJECT
  rts
