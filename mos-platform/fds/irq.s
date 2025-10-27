.text

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

.section .nmi_user_1_begin,"axG",@progbits,nmi_user_1
.weak nmi_user_1
.global __default_nmi_user_1
nmi_user_1:
__default_nmi_user_1:
		pha
		txa
		pha
		tya
		pha

.section .nmi_user_1_end,"axG",@progbits,nmi_user_1
		pla
		tay
		pla
		tax
		pla
		rti

.section .nmi_user_2_begin,"axG",@progbits,nmi_user_2
.weak nmi_user_2
.global __default_nmi_user_2
nmi_user_2:
__default_nmi_user_2:
	pha
	txa
	pha
	tya
	pha

.section .nmi_user_2_end,"axG",@progbits,nmi_user_2
	pla
	tay
	pla
	tax
	pla
	rti

.section .nmi_user_3_begin,"axG",@progbits,nmi_user_3
.weak nmi_user_3
.global __default_nmi_user_3
nmi_user_3:
__default_nmi_user_3:
	pha
	txa
	pha
	tya
	pha

.section .nmi_user_3_end,"axG",@progbits,nmi_user_3
	pla
	tay
	pla
	tax
	pla
	rti
