#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;


int funcao0(int n) {
	int ct = 0;
	for(int i=0;i<10000;i++)	
		ct += n ;

	return ct;
}

//Numero de vezes que a soma eh executada: n
int funcao1(int n) {
	int ct = 0;
	for(int i=0;i<n;i++)	
		ct += i ;

	return ct;
}

//Numero de vezes que a soma eh executada: n^2
int funcao2(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)	
			ct += i;

	return ct;
}

//Numero de vezes que a soma eh executada: 2n^2
int funcao3(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) 
		for(int j=0;j<n;j++)	
			ct += i +j;

	return ct;
}

//Numero de vezes que a soma eh executada: 4n^2 + n
int funcao4(int n) {
	int ct = 0;
	for(int i=0;i<n;i++) {
		ct += i;
		for(int j=0;j<n;j++)	
			ct += i + j + 10 + ct;
	}

	return ct;
}

int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n = atoi(argv[1]);


	int soma = 0;

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000;i++) {
		soma += funcao0(n);
	}	
	auto tempo0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	t0 = std::chrono::system_clock::now();
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
	cout << "Funcao0:                           " << setw(10) << setprecision(7) << fixed << tempo0.count()/1000000.0 << "\n";
	cout << "Funcao que executa n somas:        " << setw(10) << setprecision(7) << fixed << tempo1.count()/1000000.0 << "\n";
	cout << "Funcao que executa n^2 somas:      " << setw(10) << setprecision(7) << fixed <<  tempo2.count()/1000000.0 << "\n";
	cout << "Funcao que executa 2n^2 somas:     " << setw(10) << setprecision(7) << fixed <<  tempo3.count()/1000000.0 << "\n";
	cout << "Funcao que executa 4n^2 + n somas: " << setw(10) << setprecision(7) << fixed <<  tempo4.count()/1000000.0 << "\n";
	cout << "soma: " << soma << "\n"; //vamos imprimir isso para evitar que o otimizador do compilador retire a chamada da funcao

	return 0;
}