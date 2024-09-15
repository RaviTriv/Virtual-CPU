
class CPU
{
  typedef unsigned char byte;

public:
  static const byte MAX = 255;
  CPU();
  void resetCPU();

private:
  byte PC;
  byte IR;
  byte register1;
  byte register2;
  bool overflow;
  bool underflow;
};