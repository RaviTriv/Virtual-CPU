
class Memory
{
  typedef unsigned char BYTE;

public:
  const BYTE maxAddress = 255;
  Memory();
  ~Memory();
  void clear();
  const BYTE &read(const BYTE &address);
  void write(const BYTE &address, const BYTE &value);

private:
  BYTE *memorySpace = new BYTE[maxAddress];
};