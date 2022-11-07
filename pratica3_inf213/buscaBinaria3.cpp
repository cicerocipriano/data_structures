#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;



//Busca binaria
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Atualmente retorna -1 se elemento nao esta no array
//Nesse exercicio, voce devera modificar essa funcao para que ela retorne o mesmo que a busca sequencial abaixo retorna
//no caso do elemento nao estar no array
//Modifique apenas a funcao buscaBin!!!
int buscaBin(int *array,int begin, int end, int chave){
    if(begin > end)
        return -1;
    int meio = (end - begin) / 2 + begin;
    if(array[meio] >= chave && meio == 0)
        return meio;
    if(array[meio] >= chave){
        if(array[meio-1] >= chave)
            return buscaBin(array,begin,meio-1,chave);
        return meio;
    }
    return buscaBin(array,meio+1, end, chave);
}

//Busca sequencial
//Pesquisa pelo elemento "chave" entre as posicoes begin e end (inclusive) do array 
//Se o elemento nao se encontra no array, retorna a posição do primeiro elemento maior que ele (ou -1 se nao ha elementos maiores que ele)
int buscaSeq(int *array,int begin,int end, int chave) {
	for(int i=begin;i<=end;i++)
		if (array[i] >= chave)
			return i;		

	return -1;
}



/*
O arquivo de entrada tera um numero n e um numero numConsultas.
A seguir, teremos n numeros (esses numeros irao compor o array com os dados e estarao ordenados!)
Depois, numConsultas numeros (queremos procurar cada um desses numeros no array)

Exemplo de entrada:
5 4
1 6 7 9 10
6 10 9 5

Saida esperada da versao atual:

Respostas da busca sequencial
Respostas da busca sequencial:
1
4
3
1
Respostas da busca binaria:
1
4
3
-1

*/

int main(int argc, char**argv) {
    cerr << "busca binaria 3" << endl;
    int n,numConsultas;
    cin >> n >> numConsultas;
	int *v = new int[n];
	int *respostas = new int[numConsultas];
	int *consultas =  new int[numConsultas];

    for(int i=0;i<n;i++) {
		cin >> v[i];
	}
	for(int i=0;i<numConsultas;i++) {
		cin >> consultas[i];
    }

	int soma = 0;

	//Para cada um dos numeros em consultas, vamos procurar esse numero usando a busca sequencial e a binaria
	//Para ver melhor as diferencas de tempo, vamos buscar cada um dos numeros 1000 vezes!

	//Mede o tempo de 10000 execucoes em microsegundos
	auto t0 = std::chrono::system_clock::now();
	for(int j=0;j<numConsultas;j++) {
		for(int i=0;i<1000;i++) {
			respostas[j] = buscaSeq(v,0,n-1, consultas[j] );
		}
	}
	auto tempoSeq = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cout << "Respostas da busca sequencial:\n";
	for(int i=0;i<numConsultas;i++) cout << respostas[i] << "\n"; 


	t0 = std::chrono::system_clock::now();
	for(int j=0;j<numConsultas;j++) {
		for(int i=0;i<1000;i++) {
			respostas[j] = buscaBin(v,0,n-1,consultas[j] );
		}	
	}
	auto tempoBin = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - t0);
	cout << "Respostas da busca binaria:\n";
	for(int i=0;i<numConsultas;i++) cout << respostas[i] << "\n"; 


	cerr << "Tempo da busca sequencial (repetidas 10000x):        " << setw(10)<< tempoSeq.count() << "\n";
	cerr << "Tempo da binaria (repetidas 10000x):           " << setw(10)<< tempoBin.count() << "\n";
	soma = 0;


	delete []v;
	delete []consultas;
	delete []respostas;
	return 0;
}
