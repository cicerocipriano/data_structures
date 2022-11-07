#include <iostream>

using namespace std;

int main(int argc, char **argv){
  unsigned int a = 256, b =0;
  while(a > 0){
    b += a;
    a /= 2;
  }
  cout << b << endl;
  return 0;
}
