#include <vector>
#include <iostream>
#include "./memory.h"

using namespace std;

class CPU
{
  typedef unsigned char BYTE;
  Memory *program = 0;

public:
  static const BYTE MAX = 255;
  CPU(Memory *p);
  ~CPU();
  void runCPU();
  void resetCPU();

private:
  BYTE reservedAddress;
  BYTE baseAddress;
  BYTE addressLimit;
  BYTE jumpAddress;
  BYTE PC;
  BYTE IR;
  BYTE register1;
  BYTE register2;
  BYTE register3;
  bool overflow;
  bool underflow;
  bool halt;
  const BYTE &fetch();
  void decode(BYTE opcode);

  void error();

  void load1();
  void load2();

  void add();
  void addi1();
  void sub();
  void subi1();

  void store0();
  void store();
  void store1();
  void store2();
  void printSomething();

  // JUMP INSTRUCTIONS
  void jump();
  void jumpEqual();
  void jumpNotEqual();

};