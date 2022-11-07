#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;



//dado um array de numeros contendo todos os valores de 0 até n-1, marca em posicoes[i] a posicao (em numeros[])
//onde o numero i se encontra.
//Exemplo de entrada: se numeros[] = {1,3,0,2}
//Exemplo de saida: apos a execucao da funcao, posicoes sera = {2,0,3,1} 
//Nesse exemplo, posicoes[3]=1 --> o numero 3 se encontra na posicao 1 de numeros[])
void encontraPosicoes(const int numeros[],int posicoes[], int n) {
	for(int i=0;i<n;i++)   //para cada numero i, descobre em qual posicao de numeros[] ele se encontra
		for(int j=0;j<n;j++) //varre o array procurando a posicao onde i se encontra
			if(numeros[j]==i) 
				posicoes[i]= j; //o numero i se encontra na posicao j do array...
}


/*
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
ATENCAO: nao altere nada daqui para baixo!!!!
*/


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
int main() {
	//sem srand, para sempre usarmos a mesma semente...
	int n;
	cin >> n;

	int *numeros = new int[n];
	int *posicoes = new int[n];

	//le a permutacao de numeros.
	for(int i=0;i<n;i++) cin >> numeros[i];

	auto t0 = std::chrono::system_clock::now();
	for(int i=0;i<1000000;i++) { //Vamos medir o tempo de 1000 chamadas ! NAO altere isso!!!
		encontraPosicoes(numeros,posicoes,n);
	}	
	auto tempo1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);

	cerr << "Tempo para executar 1000000 vezes a funcao (segundos): " << setw(10) << setprecision(7) << fixed << tempo1.count()/1000000.0 << "\n";

	for(int i=0;i<n;i++) cout << posicoes[i] << " ";
	cout << "\n";



	delete []numeros;
	delete []posicoes;
	return 0;
}