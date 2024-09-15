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
}

CPU::CPU()
{
  resetCPU();
}

CPU::~CPU() {}

void CPU::error()
{
  printf("ERROR\n");
  exit(0);
}

void CPU::load1(const vector<BYTE> &program)
{
  register1 = program[PC];
  PC++;
}

void CPU::load2(const vector<BYTE> &program)
{
  register2 = program[PC];
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
  printf("RESULT: %c", register3);
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

void CPU::store1(vector<BYTE> &program)
{
  program[PC] = register1;
  PC++;
}

void CPU::store2(vector<BYTE> &program)
{
  program[PC] = register2;
  PC++;
}

void CPU::runCPU(vector<BYTE> &program)
{
  resetCPU();
  while (PC < MAX)
  {
    IR = program[PC];
    PC++;
    switch (IR)
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
      error();
      break;
    }
  }
}