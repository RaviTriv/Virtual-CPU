#include "../include/cpu.h"

void CPU::resetCPU()
{
  PC = 0;
  IR = 0;
  register1 = 0;
  register2 = 0;
  register3 = 0;
  overflow = false;
  underflow = false;
  halt = false;
}
CPU::CPU(Memory *p)
{
  resetCPU();
  program = p;
}

CPU::~CPU() {}

void CPU::error()
{
  printf("ERROR\n");
  exit(0);
}

void CPU::load1(Memory* program)
{
  register1 = program->read(PC);
  PC++;
}

void CPU::load2(Memory *program)
{
  register2 = program->read(PC);
  PC++;
}

void CPU::add()
{
  register3 = register1 + register2;
  if (register3 > MAX)
  {
    overflow = true;
    register3 = MAX;
  }
  printf("RESULT: %d\n", register3);
  register1 = register3;
}

void CPU::sub()
{
  register3 = register2 - register1;
  if (register3 < 0)
  {
    underflow = true;
    register3 = 0;
  }
  register1 = register3;
}

void CPU::store1(Memory* program)
{
  program->write(PC, register1);
  PC++;
}

void CPU::store2(Memory *program)
{
  program->write(PC, register2);
  PC++;
}

const CPU::BYTE &CPU::fetch()
{
  IR = program->read(PC);
  PC++;
  return IR;
}

void CPU::decode(const BYTE opcode)
{
  switch (opcode)
  {
  case 1:
    load1(program);
    break;
  case 2:
    load2(program);
    break;
  case 3:
    add();
    break;
  case 4:
    sub();
    break;
  case 5:
    store1(program);
    break;
  case 6:
    store2(program);
    break;
  default:
    halt = true;
    error();
    break;
  }
}

void CPU::runCPU()
{
  resetCPU();
  while (!halt)
  {
    decode(fetch());
  }
}