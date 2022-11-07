#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Vamos usar variaveis globais nesse caso...
//Isso nao é uma boa pratica, mas vai facilitar no seu entendimento/implementacao da busca binaria
int taxaVideo,taxaDownload,tamanho;

//Essa funcao devera retornar true sse for possível 
//assistir a um vídeo de "tamanho" segundos, que gasta taxaVideo bytes por segundo para ser assistido
//supondo que sua internet consegue baixar taxaDownload bytes por segundo.
//tempoCarregamento indica quanto tempo voce irá aguardar para começar assistir ao vídeo
//Implemente esta funcao
bool consigoAssistirSemPausas(int tempoCarregamento){
    int B = taxaVideo, V = taxaDownload, T = tamanho, carregado = 0, consumido = 0, total = B * T;
    for(int i = tempoCarregamento; i > 0; i--)
        carregado += V;

    for(int i = 1; i <= T; i++){
        consumido = i * B;
        carregado += V;
        if(consumido > carregado)
            return false;
    }

    return true;
}



int main() {
	cin >> taxaVideo >> taxaDownload >> tamanho;
	for(int i=0;i<20;i++) {
		bool result = consigoAssistirSemPausas(i);
		cout << i << ": " << result << "\n";		
	}
}
