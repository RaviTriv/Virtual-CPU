# Virtual-CPU

A simple virtual CPU.

![Diagram](/images/registers.png)

## Instruction Set Architecture

### Opcodes

A few important `opcodes` are listed in the table below

| OpCode       | Description                                            |
| ------------ | ------------------------------------------------------ |
| load1        | Load Register 1 with immediate value                   |
| load2        | Load Register 2 with immediate value                   |
| add          | Add register 1 and register 2 to register 3            |
| addi1        | Add 1 to register 1                                    |
| addi2        | Add 1 to register 2                                    |
| sub          | Subtract register 1 from register 2 to register 3      |
| subi1        | Subtract 1 from register 1                             |
| subi2        | Subtract 1 from register 2                             |
| store0       | Write value of register 1 to memory address 0          |
| store1       | Write value of register 1 to current PC memory address |
| store2       | Write value of register 2 to current PC memory address |
| jump         | Unconditional jump to immediate value                  |
| jumpEqual    | Jump if register 1 and register 2 are equal            |
| jumpNotEqual | Jump if register 1 and register 2 are not equal        |

## Sample Program

This sample program runs a loop and prints once the loop is completed.
```c++
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
  program.write(8, 9);

  Memory *p = &program;
  CPU cpu(p);
  cpu.runCPU();
```
