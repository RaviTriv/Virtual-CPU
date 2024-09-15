#include <iostream>
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

void CPU::load1(const vector<byte> &program)
{
  register1 = program[PC];
  PC++;
}

void CPU::load2(const vector<byte> &program)
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

void CPU::store1(vector<byte> &program)
{
  program[PC] = register1;
  PC++;
}

void CPU::runCPU()
{
  resetCPU();
  while (PC < MAX)
  {
    switch (IR)
    {
      if (1)
      {
      }
    }
  }
}