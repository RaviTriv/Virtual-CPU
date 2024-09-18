#include "../include/cpu.h"

typedef unsigned char BYTE;

int main()
{
  Memory program;

  // Load 15 to register 1
  program.write(2, 1);
  program.write(3, 15);

  // Load 1 to register 2
  program.write(4, 2);
  program.write(5, 1);

  // Loop while register 1 and 2 not are equal
  program.write(6, 11);
  // Jump to instruction, -> subtract 1 from register 1
  program.write(7, 12);
  program.write(12, 12);
  
  // Jump back to the start of loop
  program.write(13, 7);
  program.write(14, 6);
 // program.write(9, 7);

  // Print once finished the loop
  program.write(10, 9);

  Memory *p = &program;
  CPU cpu(p);
  cpu.runCPU();

  return 0;
}