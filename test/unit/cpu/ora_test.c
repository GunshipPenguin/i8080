#include "unit/attounit.h"
#include "cpu.h"
#include "memory.h"
#include "cpu_test_helpers.h"

TEST_SUITE(instruction_ora);
BEFORE_EACH() {
  setup_cpu_test_env();
}
AFTER_EACH() {}

// Individual opcode tests
TEST_CASE(ora_b) {
  write_byte(0, 0xB0);
  cpu->B = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_c) {
  write_byte(0, 0xB1);
  cpu->C = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_d) {
  write_byte(0, 0xB2);
  cpu->D = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_e) {
  write_byte(0, 0xB3);
  cpu->E = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_h) {
  write_byte(0, 0xB4);
  cpu->H = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_l) {
  write_byte(0, 0xB5);
  cpu->L = 6; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_m) {
  write_byte(0, 0xB6);
  write_byte(8, 6);
  cpu->L = 0x08; cpu->H = 0x00; cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 14);
  ASSERT_EQUAL(cpu->PC, 1);
}

TEST_CASE(ora_a) {
  write_byte(0, 0xB7);
  cpu->A = 10;

  step_cpu();

  ASSERT_EQUAL(cpu->A, 10);
  ASSERT_EQUAL(cpu->PC, 1);
}

// Flag bit tests
TEST_CASE(ora_resets_c_flag) {
  write_byte(0, 0xB0); // ORA B
  cpu->A = 0xF0; cpu->B = 0x00;
  set_flag(FLAG_C, 1);

  step_cpu();

  ASSERT_FALSE(get_flag(FLAG_C));
}

TEST_CASE(ora_sets_z_flag) {
  write_byte(0, 0xB0); // ORA B
  cpu->A = 0x00; cpu->B = 0x00;
  set_flag(FLAG_Z, 0);

  step_cpu();

  ASSERT_TRUE(get_flag(FLAG_Z));
}

TEST_CASE(ora_sets_s_flag) {
  write_byte(0, 0xB0); // ORA B
  cpu->A = 0x00; cpu->B = 0xFF;
  set_flag(FLAG_S, 0);

  step_cpu();

  ASSERT_TRUE(get_flag(FLAG_S));
}

TEST_CASE(ora_sets_p_flag) {
  write_byte(0, 0xB0); // ORA B
  cpu->A = 0x00; cpu->B = 0x03;
  set_flag(FLAG_P, 0);

  step_cpu();

  ASSERT_TRUE(get_flag(FLAG_P));
}