#include <vector>
using namespace std;

class CPU
{
  typedef unsigned char byte;

public:
  static const byte MAX = 255;
  CPU();
  void runCPU();
  void resetCPU();

private:
  byte PC;
  byte IR;
  byte register1;
  byte register2;
  byte register3;
  bool overflow;
  bool underflow;
  void load1(const vector<byte> &program);
  void load2(const vector<byte> &program);
  void add();
  void sub();
  void store1(vector<byte> &program);
};