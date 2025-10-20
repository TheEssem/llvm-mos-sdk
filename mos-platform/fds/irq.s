.text

.section .init.010,"ax",@progbits
; Write the vectors to the necessary parts of RAM
  lda #<nmi
  sta $DFF6
  lda #>nmi
  sta $DFF7
  lda #<nmi_2
  sta $DFF8
  lda #>nmi_2
  sta $DFF9
  lda #<nmi_3
  sta $DFFA
  lda #>nmi_3
  sta $DFFB
  lda #<_start
  sta $DFFC
  lda #>_start
  sta $DFFD
  lda #<irq
  sta $DFFE
  lda #>irq
  sta $DFFF

.section .irq_begin,"axG",@progbits,irq
.weak irq
.global __default_irq
irq:
__default_irq:
	pha
	txa
	pha
	tya
	pha

.section .irq_end,"axG",@progbits,irq
;; ack irq
	lda $4030

	pla
	tay
	pla
	tax
	pla
	rti

.section .nmi_2_begin,"axG",@progbits,nmi_2
.weak nmi_2
.global __default_nmi_2
nmi_2:
__default_nmi_2:
	pha
	txa
	pha
	tya
	pha

.section .nmi_2_end,"axG",@progbits,nmi_2
	pla
	tay
	pla
	tax
	pla
	rti

.section .nmi_3_begin,"axG",@progbits,nmi_3
.weak nmi_3
.global __default_nmi_3
nmi_3:
__default_nmi_3:
	pha
	txa
	pha
	tya
	pha

.section .nmi_3_end,"axG",@progbits,nmi_3
	pla
	tay
	pla
	tax
	pla
	rti
