#include "../include/cpu.h"

void CPU::resetCPU()
{
  reservedAddress = 0;
  jumpAddress = 1;
  baseAddress = 2;
  addressLimit = MAX - 2;
  PC = baseAddress;
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
  halt = true;
  printf("ERROR\n");
  exit(0);
}

void CPU::load1()
{
  register1 = program->read(PC);
  PC++;
}

void CPU::load2()
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
  register1 = register3;
}

void CPU::addi1()
{
  register1 = register1 + 1;
}

void CPU::addi2()
{
  register2 = register2 + 1;
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

void CPU::subi1()
{
  register1 = register1 - 1;
  printf("SUBTRACTING\n");
}

void CPU::subi2()
{
  register2 = register2 - 1;
}

void CPU::store()
{
  register2 = program->read(PC);
  PC++;
  program->write(register2, register1);
}

void CPU::store0()
{
  program->write(0, register1);
  PC++;
}

void CPU::store1()
{
  program->write(PC, register1);
  PC++;
}

void CPU::store2()
{
  program->write(PC, register2);
  PC++;
}

void CPU::printSomething()
{
  printf("PRINTED SOMETHING\n");
}

void CPU::jump()
{
  program->write(jumpAddress, program->read(PC));
  PC = program->read(jumpAddress);
}

void CPU::jumpEqual()
{
  if (register1 == register2)
  {
    jump();
  }
  else
  {
    PC++;
  }
}

void CPU::jumpNotEqual()
{
  if (register1 != register2)
  {
    jump();
  }
  else
  {
    PC++;
  }
}

const CPU::BYTE &CPU::fetch()
{
  IR = program->read(PC);
  PC++;
  if (PC > addressLimit)
  {
    halt = true;
  }
  return IR;
}

void CPU::decode(const BYTE opcode)
{
  if (halt)
  {
    return;
  }
  switch (opcode)
  {
  case 1:
    load1();
    break;
  case 2:
    load2();
    break;
  case 3:
    add();
    break;
  case 4:
    sub();
    break;
  case 5:
    store1();
    break;
  case 6:
    store2();
    break;
  case 7:
    jump();
    break;
  case 8:
    jumpEqual();
    break;
  case 9:
    printSomething();
    break;
  case 10:
    store0();
    break;
  case 11:
    jumpNotEqual();
    break;
  case 12:
    subi1();
    break;
  default:
    error();
    break;
  }
}

void CPU::runCPU()
{
  resetCPU();
  while (!halt)
  {
    program->write(reservedAddress, fetch());
    decode(program->read(reservedAddress));
  }
}