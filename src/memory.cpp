#include "../include/memory.h"

Memory::Memory()
{
  clear();
}

Memory::~Memory()
{
  if (memorySpace != 0)
  {
    delete[] memorySpace;
    memorySpace = 0;
  }
}

void Memory::clear()
{
  for (BYTE i = 0; i < maxAddress; i++)
  {
    memorySpace[i] = 0;
  }
}

const Memory::BYTE &Memory::read(const Memory::BYTE &address)
{
  return memorySpace[address];
}

void Memory::write(const BYTE &address, const BYTE &value)
{
  memorySpace[address] = value;
}