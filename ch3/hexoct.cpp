#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  using namespace std;
  int chest = 42;
  int waist = 0x42; // 十六进制
  int inseam = 042; // 八进制

  // cout 默认十进制输出
  cout << "Monsieur cuts a striking figure!" << endl;
  cout << "chest = " << chest << " (42 in decimal)" << endl;
  cout << "waist = " << waist << " (0x42 in hex)" << endl;
  cout << "inseam = " << inseam << " (042 in octal)" << endl;
  return 0;
}