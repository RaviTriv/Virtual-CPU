#include <vector>
#include <iostream>

using namespace std;

class CPU
{
  typedef unsigned char BYTE;

public:
  static const BYTE MAX = 255;
  CPU();
  void runCPU(vector<BYTE> &program);
  void resetCPU();

private:
  BYTE PC;
  BYTE IR;
  BYTE register1;
  BYTE register2;
  BYTE register3;
  bool overflow;
  bool underflow;
  void error();
  void load1(const vector<BYTE> &program);
  void load2(const vector<BYTE> &program);
  void add();
  void sub();
  void store1(vector<BYTE> &program);
  void store2(vector<BYTE> &program);
};