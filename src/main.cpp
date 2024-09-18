#include "../include/cpu.h"

typedef unsigned char BYTE;

int main()
{
  Memory program;

  program.write(2, 1);
  program.write(3, 1);

  program.write(4, 2);
  program.write(5, 1);

  //program.write()

  program.write(6, 8);

  program.write(7, 2);
  //program.write(15, 9);
  // program.write(4, 1);

  Memory *p = &program;
  CPU cpu(p);
  cpu.runCPU();

  return 0;
}