#include "attounit.h"
#include "cpu.h"
#include "memory.h"

TEST_SUITE(instruction_lxi);
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
    write_byte(i, 0);
  }
}
AFTER_EACH() {}

TEST_CASE(lxi_b_d16) {
  write_byte(0, 0x01); // LXI B
  write_word(1, 0xABCD); // d16
  cpu->B = 0x00; cpu->C = 0x00;

  step_cpu();

  ASSERT_EQUAL(cpu->B, 0xAB);
  ASSERT_EQUAL(cpu->C, 0xCD);
  ASSERT_EQUAL(cpu->PC, 3);
}

TEST_CASE(lxi_d_d16) {
  write_byte(0, 0x11); // LXI D
  write_word(1, 0xABCD); // d16
  cpu->D = 0x00; cpu->E = 0x00;

  step_cpu();

  ASSERT_EQUAL(cpu->D, 0xAB);
  ASSERT_EQUAL(cpu->E, 0xCD);
  ASSERT_EQUAL(cpu->PC, 3);
}

TEST_CASE(lxi_h_d16) {
  write_byte(0, 0x21); // LXI H
  write_word(1, 0xABCD); // d16
  cpu->H = 0x00; cpu->L = 0x00;

  step_cpu();

  ASSERT_EQUAL(cpu->H, 0xAB);
  ASSERT_EQUAL(cpu->L, 0xCD);
  ASSERT_EQUAL(cpu->PC, 3);
}

TEST_CASE(lxi_sp_d16) {
  write_byte(0, 0x31); // LXI B
  write_word(1, 0xABCD); // d16
  cpu->SP = 0x0000;

  step_cpu();

  ASSERT_EQUAL(cpu->SP, 0xABCD);
  ASSERT_EQUAL(cpu->PC, 3);
}
