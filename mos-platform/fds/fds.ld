/* Provide imaginary (zero page) registers in the BIOS area. */
__rc0 = 0x10;
INCLUDE imag-regs.ld
ASSERT(__rc31 == 0x2f, "Inconsistent zero page map.")

ASSERT(__prg_ram_size == 0 ||
       __prg_ram_size == 1 << LOG2CEIL(__prg_ram_size),
       "Nonempty PRG-RAM must be a power of 2.")

MEMORY {
  /* The FDS BIOS uses 16 bytes at the beginning and 15 bytes at the end - 31 bytes total - of the zero page. */
  zp : ORIGIN = __rc31 + 1, LENGTH = 0xE1 - (__rc31 + 1)

  /* CPU address space. */
  ram : ORIGIN = 0x0200, LENGTH = 0x0600

  vectors : ORIGIN = 0xdff6, LENGTH = 6
}

SECTIONS {
  .text : {
       INCLUDE text-sections.ld
       KEEP(*(.nmi_begin))
       KEEP(*(SORT_BY_INIT_PRIORITY(.nmi.* .nmi)))
       KEEP(*(.nmi_end))
  } >c_readonly
  INCLUDE rodata.ld
  /* A naturally page-aligned place (0x200) to place noinit buffers with high
   * alignment requirement (e.g. OAM) */
  .aligned (NOLOAD) : { *(.aligned .aligned.*) } >ram
  INCLUDE data.ld
  INCLUDE zp.ld
  INCLUDE bss.ld
  INCLUDE noinit.ld

  .ram (NOLOAD) : { *(.ram .ram.*) } > ram

  .vectors : { KEEP(*(.vectors)) } >vectors
}
