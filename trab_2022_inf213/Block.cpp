#include "Block.h"

/* classe Block */
// construtores
Block::Block(){this->create();}

Block::Block(const int pos, const int prevHash, const int criador):
    _pos(pos), _prevHash(prevHash), _criador(criador),
    _first(NULL), _last(NULL), _prev(NULL), _next(NULL),
    _proofWork(0){
    assert(this->_pos >= 0 && this->_criador >= 0); // _pos e _criador devem ser maiores que -1
}

Block::Block(const int pos, const int prevHash, const int criador, const int proofWork):
    _pos(pos), _prevHash(prevHash), _criador(criador),
    _first(NULL), _last(NULL), _prev(NULL), _next(NULL),
    _proofWork(proofWork){
    assert(this->_pos >= 0 && this->_criador >= 0 && this->_proofWork >= 0); // _pos, _criador e _proofwork devem ser maiores que -1
}

Block::Block(const Block& other){ // construtor de copia
    this->create();
    *this = other;
}

// destrutor
Block::~Block(){this->destroy_transactions();} // deleta as transacoes alocadas dinamicamente

// operadores
Block& Block::operator=(const Block& other){
    if(this == &other)
        return *this;
    this->clear();
    if(other._first != NULL){
        Transaction* ptr = other._first;
        while(ptr != NULL){
            this->addTransaction(ptr->get_de(), ptr->get_para(), ptr->get_valor(), ptr->get_taxa());
            ptr = ptr->get_next();
        }
    }
    this->_pos = other.get_pos();
    this->_prevHash = other.get_prevHash();
    this->_criador = other.get_criador();
    this->_prev = this->_next = NULL;
    this->_proofWork = other.get_proofWork();
    return *this;
}

// metodos get
const int Block::get_pos() const{return this->_pos;}

const int Block::get_prevHash() const{return this->_prevHash;}

const int Block::get_criador() const{return this->_criador;}

Transaction* Block::get_first() const{return this->_first;}

Transaction* Block::get_last() const{return this->_last;}

Block* Block::get_prev() const{return this->_prev;}

Block* Block::get_next() const{return this->_next;}

const int Block::get_proofWork() const{return this->_proofWork;}

// metodos set
void Block::set_first(Transaction* first){
    this->_first = first;
    return;
}

void Block::set_last(Transaction* last){
    this->_last = last;
    return;
}

void Block::set_prev(Block* prev){
    this->_prev = prev;
    return;
}

void Block::set_next(Block* next){
    this->_next = next;
    return;
}

void Block::set_proofWork(const int proofWork){
    this->_proofWork = proofWork;
    assert(this->_proofWork >= 0); // valor deve ser maior que -1
    return;
}

// outros metodos
void Block::addTransaction(const int de, const int para, const int valor, const int taxa){ // funciona como um push_back() de lista simplesmente encadeada
    Transaction* ptr = new Transaction(de, para, valor, taxa, NULL);
    if(this->_first == NULL){
        this->_first = this->_last = ptr;
        return;
    }
    this->_last->set_next(ptr);
    this->_last = ptr;
    return;
}

void Block::mineBlock(){ // calcula a hash que tem os primeiros 10 digitos binarios iguais a 0
    this->_proofWork = 0;
    bool validez = this->validate_block();
    while(validez == false){
        this->_proofWork++;
        validez = this->validate_block();
    }
    return;
}

const int Block::getHash() const{ // calcula a hash do bloco
    int *ptr = new int[4 + 4 * this->transactions_size()], i = 3;
    ptr[0] = this->_pos;
    ptr[1] = this->_prevHash;
    ptr[2] = this->_criador;
    for(Transaction* aux = this->_first; aux != NULL; aux = aux->get_next()){
        ptr[i++] = aux->get_de();
        ptr[i++] = aux->get_para();
        ptr[i++] = aux->get_valor();
        ptr[i++] = aux->get_taxa();
    }
    ptr[i] = this->_proofWork;
    SHA256 sh;
    const int hash = sh.calcula(ptr, i + 1);
    delete[] ptr;
    return hash;
}

const bool Block::validate_block() const{ // checa se a hash tem os primeiros 10 digitos binarios iguais a 0
    const int teste = this->getHash() & 1023;
    if(teste == 0)
        return true;
    return false;
}

const int Block::transactions_size() const{ // calcula a quantidade de transacoes no bloco
    int size = 0;
    for(Transaction* ptr = this->_first; ptr != NULL; size++, ptr = ptr->get_next());
    return size;
}

// metodos private
void Block::create(){ // cria um bloco vazio
    this->_pos = this->_prevHash = this->_criador = this->_proofWork = 0;
    this->_first = this->_last = NULL;
    this->_prev = this->_next = NULL;
    return;
}

void Block::destroy_transactions(){ // funciona como um destrutor de lista simplesmente encadeada
    if(this->_first == NULL)
        return;
    Transaction *ptr = this->_first, *aux = this->_first->get_next();
    while(aux != NULL){
        delete ptr;
        ptr = aux;
        aux = aux->get_next();
    }
    delete ptr;
    return;
}

void Block::clear(){
    this->destroy_transactions();
    this->create();
    return;
}
