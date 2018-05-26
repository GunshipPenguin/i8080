#include "attounit.h"
#include "i8080.h"
#include "memory.h"
#include "cpu_test_helpers.h"

TEST_SUITE(data_transfer_instructions);

struct i8080 *cpu;

BEFORE_EACH() {
  cpu = setup_cpu_test_env();
}
AFTER_EACH() {
  teardown_cpu_test_env(cpu);
}

TEST_CASE(mov_b_b) {
  write_byte(cpu, 0, 0x40);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_c) {
  write_byte(cpu, 0, 0x41);
  cpu->B = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_d) {
  write_byte(cpu, 0, 0x42);
  cpu->B = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_e) {
  write_byte(cpu, 0, 0x43);
  cpu->B = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_h) {
  write_byte(cpu, 0, 0x44);
  cpu->B = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_l) {
  write_byte(cpu, 0, 0x45);
  cpu->B = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_b_m) {
  write_byte(cpu, 0, 0x46);
  write_byte(cpu, 8, 1);
  cpu->B = 0; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_b_a) {
  write_byte(cpu, 0, 0x47);
  cpu->B = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->B, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_b) {
  write_byte(cpu, 0, 0x48);
  cpu->C = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_c) {
  write_byte(cpu, 0, 0x49);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_d) {
  write_byte(cpu, 0, 0x4A);
  cpu->C = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_e) {
  write_byte(cpu, 0, 0x4B);
  cpu->C = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_h) {
  write_byte(cpu, 0, 0x4C);
  cpu->C = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_l) {
  write_byte(cpu, 0, 0x4D);
  cpu->C = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_c_m) {
  write_byte(cpu, 0, 0x4E);
  write_byte(cpu, 8, 1);
  cpu->C = 0; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_c_a) {
  write_byte(cpu, 0, 0x4F);
  cpu->C = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->C, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_b) {
  write_byte(cpu, 0, 0x50);
  cpu->D = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_c) {
  write_byte(cpu, 0, 0x51);
  cpu->D = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_d) {
  write_byte(cpu, 0, 0x52);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_e) {
  write_byte(cpu, 0, 0x53);
  cpu->D = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_h) {
  write_byte(cpu, 0, 0x54);
  cpu->D = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_l) {
  write_byte(cpu, 0, 0x55);
  cpu->D = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_d_m) {
  write_byte(cpu, 0, 0x56);
  write_byte(cpu, 8, 1);
  cpu->D = 0; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_d_a) {
  write_byte(cpu, 0, 0x57);
  cpu->D = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->D, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_b) {
  write_byte(cpu, 0, 0x58);
  cpu->E = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_c) {
  write_byte(cpu, 0, 0x59);
  cpu->E = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_d) {
  write_byte(cpu, 0, 0x5A);
  cpu->E = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_e) {
  write_byte(cpu, 0, 0x5B);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_h) {
  write_byte(cpu, 0, 0x5C);
  cpu->E = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_l) {
  write_byte(cpu, 0, 0x5D);
  cpu->E = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_e_m) {
  write_byte(cpu, 0, 0x5E);
  write_byte(cpu, 8, 1);
  cpu->E = 0; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_e_a) {
  write_byte(cpu, 0, 0x5F);
  cpu->D = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->E, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_b) {
  write_byte(cpu, 0, 0x60);
  cpu->H = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_c) {
  write_byte(cpu, 0, 0x61);
  cpu->H = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_d) {
  write_byte(cpu, 0, 0x62);
  cpu->H = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_e) {
  write_byte(cpu, 0, 0x63);
  cpu->H = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_h) {
  write_byte(cpu, 0, 0x64);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_l) {
  write_byte(cpu, 0, 0x65);
  cpu->H = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_h_m) {
  write_byte(cpu, 0, 0x66);
  write_byte(cpu, 8, 1);
  cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_h_a) {
  write_byte(cpu, 0, 0x67);
  cpu->H = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->H, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_b) {
  write_byte(cpu, 0, 0x68);
  cpu->L = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_c) {
  write_byte(cpu, 0, 0x69);
  cpu->L = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_d) {
  write_byte(cpu, 0, 0x6A);
  cpu->L = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_e) {
  write_byte(cpu, 0, 0x6B);
  cpu->L = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_h) {
  write_byte(cpu, 0, 0x6C);
  cpu->L = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_l) {
  write_byte(cpu, 0, 0x6D);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_l_m) {
  write_byte(cpu, 0, 0x6E);
  write_byte(cpu, 8, 1);
  cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_l_a) {
  write_byte(cpu, 0, 0x6F);
  cpu->L = 0; cpu->A = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->L, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_m_b) {
  write_byte(cpu, 0, 0x70);
  cpu->B = 1; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_c) {
  write_byte(cpu, 0, 0x71);
  cpu->C = 1; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_d) {
  write_byte(cpu, 0, 0x72);
  cpu->D = 1; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_e) {
  write_byte(cpu, 0, 0x73);
  cpu->E = 1; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_h) {
  write_byte(cpu, 0, 0x74);
  // Write a nonzero value to address 8 so we can check something was overwritten
  write_byte(cpu, 8, 5);

  cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 0);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_l) {
  write_byte(cpu, 0, 0x75);
  cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 8);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_m_a) {
  write_byte(cpu, 0, 0x77);
  cpu->A = 1; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 8), 1);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_a_b) {
  write_byte(cpu, 0, 0x78);
  cpu->A = 0; cpu->B = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_c) {
  write_byte(cpu, 0, 0x79);
  cpu->A = 0; cpu->C = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_d) {
  write_byte(cpu, 0, 0x7A);
  cpu->A = 0; cpu->D = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_e) {
  write_byte(cpu, 0, 0x7B);
  cpu->A = 0; cpu->E = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_h) {
  write_byte(cpu, 0, 0x7C);
  cpu->A = 0; cpu->H = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_l) {
  write_byte(cpu, 0, 0x7D);
  cpu->A = 0; cpu->L = 1;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(mov_a_m) {
  write_byte(cpu, 0, 0x7E);
  write_byte(cpu, 8, 1);
  cpu->A = 0; cpu->L = 0x08; cpu->H = 0x00;
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->A, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(mov_a_a) {
  write_byte(cpu, 0, 0x7F);
  step_cpu(cpu);

  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 5);
}

TEST_CASE(stax_b) {
  write_byte(cpu, 0, 0x02); // STAX B
  cpu->A = 0x01; cpu->B = 0x00; cpu->C = 0x05;

  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 5), 0x01);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}


TEST_CASE(stax_d) {
  write_byte(cpu, 0, 0x12); // STAX D
  cpu->A = 0x01; cpu->D = 0x00; cpu->E = 0x05;

  step_cpu(cpu);

  ASSERT_EQUAL(read_byte(cpu, 5), 0x01);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}

TEST_CASE(ldax_b) {
  write_byte(cpu, 0, 0x0A); // LDAX B
  write_byte(cpu, 5, 0x01);
  cpu->A = 0x00; cpu->B = 0x00; cpu->C = 0x05;

  step_cpu(cpu);

  ASSERT_EQUAL(cpu->A, 0x01);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}


TEST_CASE(ldax_d) {
  write_byte(cpu, 0, 0x1A); // LDAX D
  write_byte(cpu, 5, 0x01);
  cpu->A = 0x00; cpu->D = 0x00; cpu->E = 0x05;

  step_cpu(cpu);

  ASSERT_EQUAL(cpu->A, 0x01);
  ASSERT_EQUAL(cpu->PC, 1);
  ASSERT_EQUAL(cpu->cyc, 7);
}