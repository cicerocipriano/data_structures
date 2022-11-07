#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;


int funcao1(int n) {
	int ct = 0;
	for(int i=0;i<n;i++)	
		ct += i ;

	return ct;
}

int funcao2(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)	
			ct += i +j;

	return ct;
}

int funcao3(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++)	
			ct += i +j;
		ct += funcao2(i);
	}

	return ct;
}

int funcao4(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		ct += i*sin(n)*cos(i);
		ct += n+100*i-547+10/(i+1.0+sqrt(n));
		ct += i*sin(i)*cos(n) +n+100*i-547+10/(i+1.0+sqrt(n));
		ct += n*sin(n)*cos(i) +n+100*i-547+10/(i+1.0+sqrt(n));
		ct += n*sin(n)*cos(n) +n+100*i-547+10/(i+1.0+sqrt(n));
		ct -= rand();
		for(int j=0;j<10;j++) 		
			ct += i*sin(j)*cos(i) +j+100*i-547+10/(i+1.0+sqrt(j));		
		int k = 0;
		ct += k++;
		ct += sin(k);		
		ct -= funcao1(n-i)+500;
		ct -= funcao1(n-i/2)+500;
	}

	return ct;
}

int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n = atoi(argv[1]);

	int soma = 0;


	auto t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += funcao1(n);
	}	
	auto tempo1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += funcao2(n);
	}	
	auto tempo2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += funcao3(n);
	}	
	auto tempo3 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += funcao4(n);
	}	
	auto tempo4 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	cout << "Tempo para executar 1000 vezes cada uma das funcoes (segundos): " << "\n";
	cout << "Funcao1: " << setw(10) << setprecision(7) << fixed << tempo1.count()/1000000.0 << "\n";
	cout << "Funcao2: " << setw(10) << setprecision(7) << fixed <<  tempo2.count()/1000000.0 << "\n";
	cout << "Funcao3: " << setw(10) << setprecision(7) << fixed <<  tempo3.count()/1000000.0 << "\n";
	cout << "Funcao4: " << setw(10) << setprecision(7) << fixed <<  tempo4.count()/1000000.0 << "\n";
	cout << "soma: " << soma << "\n"; //vamos imprimir isso para evitar que o otimizador do compilador retire a chamada da funcao



	return 0;
}