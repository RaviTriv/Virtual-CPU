#include <vector>
#include <iostream>

using namespace std;

class CPU
{
  typedef unsigned char byte;

public:
  static const byte MAX = 255;
  CPU();
  void runCPU(vector<byte> &program);
  void resetCPU();

private:
  byte PC;
  byte IR;
  byte register1;
  byte register2;
  byte register3;
  bool overflow;
  bool underflow;
  void error();
  void load1(const vector<byte> &program);
  void load2(const vector<byte> &program);
  void add();
  void sub();
  void store1(vector<byte> &program);
  void store2(vector<byte> &program);
};