#include "../include/cpu.h"

typedef unsigned char BYTE;

int main()
{
  Memory program;
  program.write(1, 1);
  program.write(2, 21);
  program.write(3, 2);
  program.write(4, 21);
  program.write(5, 3);

  Memory *p = &program;
  CPU cpu(p);
  cpu.runCPU();

  return 0;
}