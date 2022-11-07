#include "Transaction.h"

/* struct inf_transacoes */
// construtores
inf_transacoes::inf_transacoes():
    de(0), para(0), valor(0), taxa(0){}

inf_transacoes::inf_transacoes(const int d, const int p, const int v, const int t):
    de(d), para(p), valor(v), taxa(t){}

// destrutor
inf_transacoes::~inf_transacoes(){}

/* classe Transaction */
// construtores
Transaction::Transaction():
    _de(0), _para(0), _valor(0), _taxa(0), _next(NULL){}

Transaction::Transaction(int de, int para, int valor, int taxa, Transaction* next):
    _de(de), _para(para), _valor(valor), _taxa(taxa), _next(next){
    assert(this->_de >= 0 && this->_para >= 0 && this->_valor >= 0 && this->_taxa >= 0); // os atributos devem ser maiores do que -1
}

// destrutor
Transaction::~Transaction(){}

// metodos get
const int Transaction::get_de() const{return this->_de;}

const int Transaction::get_para() const{return this->_para;}

const int Transaction::get_valor() const{return this->_valor;}

const int Transaction::get_taxa() const{return this->_taxa;}

Transaction* Transaction::get_next() const{return this->_next;}

// metodos set
void Transaction::set_de(const int de){
    assert(de >= 0); // valor nao pode ser negativo
    this->_de = de;
    return;
}

void Transaction::set_para(const int para){
    assert(para >= 0); // valor nao pode ser negativo
    this->_para = para;
    return;
}

void Transaction::set_valor(const int valor){
    assert(valor >= 0); // valor nao pode ser negativo
    this->_valor = valor;
    return;
}

void Transaction::set_taxa(const int taxa){
    assert(taxa >= 0); // valor nao pode ser negativo
    this->_taxa = taxa;
    return;
}

void Transaction::set_next(Transaction* next){
    this->_next = next;
    return;
}

// outros metodos
void Transaction::imprime() const{
    std::cout << this->_de << " -> " << this->_para << " (valor: " << this->_valor << " , taxa: " << this->_taxa << ")" << std::endl;
    return;
}
