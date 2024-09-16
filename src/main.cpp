#include "../include/cpu.h"
#include "../include/memory.h"

typedef unsigned char BYTE;

int main()
{
  CPU cpu;
  vector<BYTE> program;
  program.push_back(1);
  program.push_back(21);
  program.push_back(2);
  program.push_back(21);
  program.push_back(3);
  cpu.runCPU(program);

  return 0;
}