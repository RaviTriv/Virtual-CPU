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
  void load1(Memory *program);
  void load2(Memory *program);
  void add();
  void sub();
  void store();
  void store1(Memory *program);
  void store2(Memory *program);
};