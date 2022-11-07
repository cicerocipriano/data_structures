#include "Blockchain.h"

//sua main devera ter esse include e usar a funcao imprimeTransacoes
//para imprimir...
//o arquivo imprimeTransacoes.h nao precisa ser enviado (o submitty ja tem uma copia dele, para garantir
//que ninguem vai modificar a funcao de impressao)
//O include abaixo pode ser mantido comentado quando voce for enviar a primeira parte do trabalho 
//e tambem enquanto voce nao termina a implementacao dos iteradores (caso contrario seu programa nao compilara)
#include "imprimeTransacoes.h"

void imprime_binario(const int a){
    for(int i = 31; i >= 0; i--)
        std::cout << ((a >> i) & 1);
    std::cout << std::endl;
    return;
}

void validar_bloco(){
    int inf[5]; // informacoes sobre o bloco e quantidade de transacoes
    for(int i = 0; i < 5; i++)
        std::cin >> inf[i];
    Block teste(inf[0], inf[1], inf[2], inf[3]);
    if(inf[4] > 0){
        int val[inf[4] * 4];
        for(int i = 0; i < inf[4] * 4; i++)
            std::cin >> val[i];
        for(int i = 3; i < inf[4] * 4; i+=4)
            teste.addTransaction(val[i - 3], val[i - 2], val[i - 1], val[i]);
    }
    std::cout << teste.getHash() << std::endl;
    imprime_binario(teste.getHash());
    if(teste.validate_block())
        std::cout << "OK" << std::endl;
    else
        std::cout << "Nao minerado" << std::endl;
    return;
}

void minerar_bloco(){
    std::string modo;
    std::cin >> modo; // quiet ou verbose
    int inf[4];
    for(int i = 0; i < 4; i++)
        std::cin >> inf[i]; // informacoes sobre o bloco (exceto o proof of work) e quantidade de transacoes
    Block teste(inf[0], inf[1], inf[2]);
    if(inf[3] > 0){
        int val[inf[3] * 4];
        for(int i = 0; i < inf[3] * 4; i++)
            std::cin >> val[i];
        for(int i = 3; i < inf[3] * 4; i+=4)
            teste.addTransaction(val[i - 3], val[i - 2], val[i - 1], val[i]);
    }
    teste.mineBlock();
    if(modo == "verbose"){
        int *ptr = new int[4 + 4 * teste.transactions_size()], i = 3, pf = teste.get_proofWork();
        ptr[0] = teste.get_pos();
        ptr[1] = teste.get_prevHash();
        ptr[2] = teste.get_criador();
        for(Transaction* aux = teste.get_first(); aux != NULL; aux = aux->get_next()){
            ptr[i++] = aux->get_de();
            ptr[i++] = aux->get_para();
            ptr[i++] = aux->get_valor();
            ptr[i++] = aux->get_taxa();
        }
        for(int j = 0; j <= pf; j++){
            ptr[i] = j;
            for(int k = 0; k < 4 + 4 * teste.transactions_size(); k++)
                std::cout << ptr[k] << " ";
            std::cout << std::endl;
            teste.set_proofWork(ptr[i]);
            imprime_binario(teste.getHash());
            std::cout << std::endl;
        }
        delete[] ptr;
    }
    std::cout << teste.get_proofWork() << std::endl << teste.getHash() << std::endl;
    imprime_binario(teste.getHash());
    return;
}

void metodo_criarbloco(Blockchain& teste){
    int inf[3]; // quantidade de transacoes, quantidade que pode ser registrada e id do criador
    std::cin >> inf[0] >> inf[1] >> inf[2];
    inf_transacoes *ptr = NULL;
    if(inf[0] > 0 && inf[1] > 0){
        ptr = new inf_transacoes[inf[0]];
        for(int i = 0; i < inf[0]; i++)
            std::cin >> ptr[i].de >> ptr[i].para >> ptr[i].valor >> ptr[i].taxa;
    }
    teste.create_block(inf,ptr);
    delete[] ptr;
    return;
}

void metodo_imprimirsaldo(Blockchain& teste){
    int block;
    std::cin >> block;
    if(block < 1 || block > teste.blockchain_size())
        return;
    teste.print_balances(block);
    return;
}

void metodo_alteratransacao(Blockchain& teste){
    int inf[6]; // posicao na blockchain e novas informacoes sobre a transacao
    for(int i = 0; i < 6; i++)
        std::cin >> inf[i];
    assert(inf[0] > 0 && inf[2] > 0); // valor nao pode ser menor que 1
    teste.modify_transaction(inf);
    return;
}

void operacoes(){
    Blockchain teste;
    std::string metodo;
    while(std::cin >> metodo){
        if(metodo == "criarBloco")
            metodo_criarbloco(teste);
        else if(metodo == "imprimeBlockchain")
            teste.print_blockchain();
        else if(metodo == "imprimeSaldo")
            metodo_imprimirsaldo(teste);
        else if(metodo == "imprimeTransacoes")
            imprimeTransacoes(teste);
        else if(metodo == "alteraTransacao")
            metodo_alteratransacao(teste);
    }
    return;
}

int main(int argc, char **argv){
    std::string funcao;
    std::cin >> funcao;
    if(funcao == "validarBloco")
        validar_bloco();
    else if(funcao == "minerarBloco")
        minerar_bloco();
    else if(funcao == "operacoes")
        operacoes();
    return 0;
}
