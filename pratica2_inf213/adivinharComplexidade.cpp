#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;




void dfjkhbjknbjkcjfhui(int numeros[], int n) {
	do {
	} while(next_permutation(numeros, numeros+n));
}




/*
O arquivo de entrada sera composto de duas linhas: a primeira temos um numero N
Na segunda linha temos uma permutacao dos numeros : 0 1 2 ... n-1
(cada numero separado por um espaco)
A saida sera a posicao onde cada numero se encontra. (ou seja, o primeiro numnero
da saida representa a posicao onde o numero 0 se encontra, o segundo a posicao onde 
1 se encontra e assim por diante)

Exemplo de entrada:
4
1 3 0 2

Saida esperada:
2 0 3 1
*/
int main(int argc, char**argv) {
	//sem srand, para sempre usarmos a mesma semente...
	int n = atoi(argv[1]);

	int *numeros = new int[n];

	//le a permutacao de numeros.
	for(int i=0;i<n;i++) numeros[i] = i;

	auto t0 = std::chrono::system_clock::now();
	
	dfjkhbjknbjkcjfhui(numeros,n);
	
	auto tempo1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	cerr << "Tempo para executar a funcao (segundos): " << setw(10) << setprecision(7) << fixed << tempo1.count()/1000000.0 << "\n";

	for(int i=0;i<n;i++) cout << numeros[i] << " ";
	cout << "\n";



	delete []numeros;
	return 0;
}