Eu li as regras
Cicero Cipriano Maciel - ES102021

Fontes:
* Descrição do trabalho (disponibilizada pelo professor)

* Aula da INF 112 sobre bits (os slides ainda estão disponíveis)

* conversor de binario para decimal (https://www.rapidtables.com/convert/number/binary-to-decimal.html)

* Aulas teóricas e práticas de INF 213 (principalmente a implementação de listas simplesmente e duplamente encadeadas, a implementação do algoritmo Merge Sort, a implementação de iteradores e boas práticas na implementação de classes que alocam memória fora do stack).

Respostas:
Pergunta 1: quantas Capicoins existirão no mundo (supondo que aceitamos apenas valores inteiros, o primeiro bloco recompensa 256 Capicoins e esse valor cai pela metade a cada novo bloco)?
R: Pode-se responder essa pergunta com esse algoritmo em C++:
         unsigned int a = 256, b = 0;
         	  while(a > 0){
                  	  b += a;
                  	  a /= 2;
                  }
     Após o final do laço, “b” (que representa o valor máximo de Capicoins no mundo) irá valer 511.


Pergunta 2: dadas duas blockchains válidas (onde cada bloco contém o hash correto do bloco anterior), é possível ver se as duas são iguais de forma muito eficiente: basta comparar o hash do último bloco das duas. Por que isso “garante” a igualdade?
R: Para calcular a hash de um bloco, a hash do bloco anterior é necessária (quando for o primeiro bloco, a hash será zero), ou seja, a hash de cada bloco na blockchain é usada no cálculo da hash desse bloco. Para que as duas blockchains sejam iguais, as hashes dos blocos "gêmeos" (blocos com mesmo pos, mas em blockchains diferentes) devem ser iguais.
