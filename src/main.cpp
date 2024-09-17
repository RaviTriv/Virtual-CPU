#include "../include/cpu.h"
//#include "../include/memory.h"

typedef unsigned char BYTE;

int main()
{
  Memory program;
  program.write(0, 1);
  program.write(1, 21);
  program.write(2, 2);
  program.write(3, 21);
  program.write(4, 3);

  Memory* p = &program;
  CPU cpu(p);
  cpu.runCPU();

  return 0;
}