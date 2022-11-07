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
    long long int carregado = taxaDownload * tempoCarregamento;

    for(int i = 1; i <= tamanho; i++){
        carregado += taxaDownload - taxaVideo;
        if(carregado < 0)
            return false;
    }

    return true;
}

int buscaBin(int begin, int end){
    if(begin > end)
        return -1;
    int meio = (end - begin) / 2 + begin;
    if(consigoAssistirSemPausas(meio) == true && meio == 0)
        return meio;
    if(consigoAssistirSemPausas(meio) == true){
        if(consigoAssistirSemPausas(meio-1) == true)
            return buscaBin(begin,meio-1);
        return meio;
    }
    return buscaBin(meio+1, end);
}

int main(int argc, char **argv) {
    //cerr << "binaraias funcoes" << endl;
    cin >> taxaVideo >> taxaDownload >> tamanho;
    cout << buscaBin(0,taxaVideo*tamanho/taxaDownload) << endl;
    /*for(int i=0;i<20;i++) {
        bool result = consigoAssistirSemPausas(i);
        cout << i << ": " << result << "\n";
    }*/
}
