#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>

using namespace std;

int funcao1(int n){
  int ct = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; i++)
      ct += i + j;
  }

  return ct;
}

int funcao2(int n){
  int ct = 0;
  for(int i = 0; i < n; i++)
    ct += funcao2(i);

  return ct;
}

int main(int argc, char** argv){
  int n = atoi(argv[1]);
  int soma = 0;

  auto t0 = std::chrono::system_clock::now();
  for(int i = 0; i < 1000; i++){
    soma += funcao1(n);
  }
  auto tempo1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

  t0 = std::chrono::system_clock::now();
  for(int i = 0; i < 1000; i++){
    soma += funcao2(n);
  }
  auto tempo2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

  cout << "Tempo para executar 1000 vezes cada uma das funcoes (segundos): " << endl;
  cout << "funcao1: " << setw(10) << setprecision(7) << fixed << tempo1.count()/1000000.0 << endl;
  cout << "funcao2: " << setw(10) << setprecision(7) << fixed << tempo2.count()/1000000.0 << endl;
  cout << "soma: " << soma << endl;
  
  return 0;
}
