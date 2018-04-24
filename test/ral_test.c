#include "attounit.h"
#include "cpu.h"
#include "memory.h"

TEST_SUITE(instruction_ral);
BEFORE_EACH() {
  if (cpu == NULL) {
    create_cpu();
  }

  reset_cpu();
  cpu->PC = 0;

  if (memory == NULL) {
    create_memory(16);
  }

  // Zero out memory
  for (int i=0;i<16;i++) {
    write8(i, 0);
  }
}
AFTER_EACH() {}

TEST_CASE(ral_high_bit_one_carry_zero) {
  write8(0, 0x17); // RAL
  cpu->A = 0xFF;
  set_flag(FLAG_C, 0);

  step_cpu();

  ASSERT_EQUAL(cpu->A, 0xFE);
  ASSERT_EQUAL(get_flag(FLAG_C), 1);
}

TEST_CASE(ral_high_bit_zero_carry_zero) {
  write8(0, 0x17); // RAL
  cpu->A = 0x7F;
  set_flag(FLAG_C, 0);

  step_cpu();

  ASSERT_EQUAL(cpu->A, 0xFE);
  ASSERT_EQUAL(get_flag(FLAG_C), 0);
}

TEST_CASE(ral_high_bit_one_carry_one) {
  write8(0, 0x17); // RAL
  cpu->A = 0xFF;
  set_flag(FLAG_C, 1);

  step_cpu();

  ASSERT_EQUAL(cpu->A, 0xFF);
  ASSERT_EQUAL(get_flag(FLAG_C), 1);
}