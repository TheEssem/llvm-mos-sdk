FDS_CTRL = $4025
FDS_CTRL_MIRROR = $FA ; Mirror of $4025

.section .text.set_mirroring,"ax",@progbits
.weak set_mirroring
set_mirroring:
	and #0b1
	asl A
	asl A
	asl A
	sta __rc2
	lda FDS_CTRL_MIRROR
	and #0b11110111
	ora __rc2
	sta FDS_CTRL_MIRROR
	sta FDS_CTRL
	rts
