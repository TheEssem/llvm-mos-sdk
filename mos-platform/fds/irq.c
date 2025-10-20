#include <peekpoke.h>

void set_nmi_action(char action) {
  POKE(0x100, action);
}

void set_irq_action(char action) {
  POKE(0x101, action);
}

void set_reset_type(char type) {
  POKE(0x103, type);
}
