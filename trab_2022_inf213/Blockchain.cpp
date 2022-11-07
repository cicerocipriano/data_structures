#include "Blockchain.h"

/* classe Blockchain */
// construtores
Blockchain::Blockchain(){this->create();}

Blockchain::Blockchain(const Blockchain& other){ // construtor de copia
    this->create();
    *this = other;
}

// destrutores
Blockchain::~Blockchain(){this->destroy_blocks();} // deleta os blocos alocados dinamicamente

// operadores
Blockchain& Blockchain::operator=(const Blockchain& other){
    if(this == &other)
        return *this;
    this->clear();
    if(other._first != NULL){
        const int size = other.blockchain_size();
        Block *ptr = other._first, *aux, *temp;
        for(int i = 0; i < size; i++){
            aux = new Block(*ptr);
            if(i == 0){
                this->_first = aux;
            }else{
                if(i == size - 1)
                    this->_last = aux;
                aux->set_prev(temp);
                temp->set_next(aux);
            }
            temp = aux;
        }
    }
    return *this;
}

// metodos get
Block* Blockchain::get_first() const{return this->_first;}

Block* Blockchain::get_last() const{return this->_last;}

// metodos set
void Blockchain::set_first(Block* first){
    this->_first = first;
    return;
}

void Blockchain::set_last(Block* last){
    this->_last = last;
    return;
}

// outros metodos
void Blockchain::create_block(int* inf_block, inf_transacoes* inf_trans){ // funciona como um push_back() de lista duplamente encadeada
    Block* ptr;
    if(this->_first == NULL){
        ptr = new Block(1, 0, inf_block[2]);
        this->_first = this->_last = ptr;
    }else{
        ptr = new Block(this->_last->get_pos() + 1, this->_last->getHash(), inf_block[2]);
        if(inf_trans != NULL){
            this->merge_sort(inf_trans, inf_block[0]);
            const int min = this->min(inf_block[0], inf_block[1]);
            for(int i = 0; i < min; i++)
                ptr->addTransaction(inf_trans[inf_block[0] - 1 - i].de, inf_trans[inf_block[0] - 1 - i].para, inf_trans[inf_block[0] - 1 - i].valor, inf_trans[inf_block[0] - 1 - i].taxa);
        }
        this->_last->set_next(ptr);
        ptr->set_prev(this->_last);
        this->_last = ptr;
    }
    this->_last->mineBlock();
    return;
}

void Blockchain::print_blockchain() const{
    std::cout << "=====================" << std::endl;
    if(this->_first != NULL){
        Block* ptr = this->_first;
        while(ptr != NULL){
            if(ptr != this->_first)
                std::cout << "          ^" << std::endl << "          |" << std::endl << "          v" << std::endl;
            std::cout << "---------------------" << std::endl << "Pos: " << ptr->get_pos() << std::endl << "Prev hash: " << ptr->get_prevHash() << std::endl;
            std::cout << "Criador: " << ptr->get_criador() << std::endl << "Transacoes:" << std::endl;
            if(ptr->get_first() != NULL){
                Transaction* aux = ptr->get_first();
                while(aux != NULL){
                    std::cout << aux->get_de() << " -> " << aux->get_para() << " (valor: " << aux->get_valor() << " , taxa: " << aux->get_taxa() << ")" << std::endl;
                    aux = aux->get_next();
                }
            }
            std::cout << "Proof of work: " << ptr->get_proofWork() << std::endl << "Hash: " << ptr->getHash() << std::endl << "---------------------" << std::endl;
            ptr = ptr->get_next();
        }
    }
    std::cout << std::endl << "=====================" << std::endl;
    return;
}

void Blockchain::print_balances(const int last_block) const{
    int curr = 1, prize = 512, num = this->num_users(last_block), balances[num];
    for(int i = 0; i < num; i++)
        balances[i] = 0;
    Block* ptr = this->_first;
    while(curr <= last_block && ptr != NULL){
        prize /= 2;
        balances[ptr->get_criador()] += prize;
        Transaction* aux = ptr->get_first();
        while(aux != NULL){
            balances[aux->get_de()] -= (aux->get_valor() + aux->get_taxa());
            assert(aux->get_de() >= 0);
            balances[aux->get_para()] += aux->get_valor();
            balances[ptr->get_criador()] += aux->get_taxa();
            aux = aux->get_next();
        }
        ptr = ptr->get_next();
        curr++;
    }
    std::cout << "=====================" << std::endl << "Saldo apos bloco " << last_block << std::endl;
    for(int i = 0; i < num; i++)
        std::cout << i << " : " << balances[i] << std::endl;
    std::cout << "=====================" << std::endl;
    return;
}

void Blockchain::modify_transaction(const int* inf){
    Block* ptr = this->_first;
    int T = inf[1];
    while(ptr != NULL){
        if(inf[0] == ptr->get_pos())
            break;
        ptr = ptr->get_next();
    }
    if(ptr == NULL)
        return;
    Transaction* aux = ptr->get_first();
    while(aux != NULL && T > 1){
        aux = aux->get_next();
        T--;
    }
    aux->set_de(inf[2]);
    aux->set_para(inf[3]);
    aux->set_valor(inf[4]);
    aux->set_taxa(inf[5]);
    ptr->mineBlock();
    return;
}

const int Blockchain::blockchain_size() const{ // calcula a quantidade de blocos na blockchain
    int size = 0;
    for(Block* ptr = this->_first; ptr != NULL; size++, ptr = ptr->get_next());
    return size;
}

const int Blockchain::num_users(const int last_block) const{ // calcula o numero de usuarios ate um determinado bloco
    Block* ptr = this->_first;
    int curr = 1, num = -1;
    while(curr <= last_block && ptr != NULL){
        if(ptr->get_criador() > num)
            num = ptr->get_criador();
        Transaction* aux = ptr->get_first();
        while(aux != NULL){
            if(aux->get_de() > num)
                num = aux->get_de();
            if(aux->get_para() > num)
                num = aux->get_para();
            aux = aux->get_next();
        }
        ptr = ptr->get_next();
        curr++;
    }
    return num + 1;
}

// iterador
TIterator Blockchain::transactionBegin() const{ // retorna um iterador para a primeira transacao resgistrada na blockchain
    Block* ptr = this->get_first();
    while(ptr != NULL){
        if(ptr->get_first() != NULL)
            break;
        ptr = ptr->get_next();
    }
    if(ptr == NULL)
        return TransactionIterator(NULL, NULL);
    Transaction* aux = ptr->get_first();
    //aux->imprime();
    return TransactionIterator(ptr, aux);
}

TIterator Blockchain::transactionEnd() const{return TransactionIterator(NULL, NULL);} // retorna um iterador pro final da blockchain

// metodos private
void Blockchain::create(){ // cria uma blockchain vazia
    this->_first = this->_last = NULL;
    return;
}

void Blockchain::destroy_blocks(){ // funciona como um destrutor de lista dupamente encadeada
    if(this->_first == NULL)
        return;
    Block *ptr = this->_first, *aux = this->_first->get_next();
    while(aux != NULL){
        delete ptr;
        ptr = aux;
        aux = aux->get_next();
    }
    delete ptr;
    return;
}

void Blockchain::clear(){
    this->destroy_blocks();
    this->create();
    return;
}

const int Blockchain::min(const int a, const int b) const{
    if(a > b)
        return b;
    return a;
}

void Blockchain::merge(inf_transacoes* v, inf_transacoes* aux, const int p, const int q, const int r) const{
    int tam = r - p, i = p, j = q, k = 0;
    while(i < q && j < r){
        if(v[i].taxa < v[j].taxa)
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p + k] = aux[k];
    return;
}

void Blockchain::merge_sort(inf_transacoes* v, const int size) const{ // esse merge_sort ordena a lista com "estabilidade invertida"
    inf_transacoes* aux = new inf_transacoes[size];
    if(size < 2){
        delete[] aux;
        return;
    }
    for(int tam = 2; tam <= size * 2; tam *= 2){
        for(int i = 0; i < size; i += tam){
            if(size - i < tam) // ao usar "<" em vez de "<=", uma lista (5,a)(2,b)(2,c)(2,d)(1,e) ficaria (1,e)(2,d)(2,c)(2,b)(5,a)
                this->merge(v, aux, i, this->min(i + tam / 2, size), size);
            else
                this->merge(v, aux, i, (2 * i + tam) / 2, i + tam);
        }
    }
    delete[] aux;
    return;
} /* essa funcao eh muito util, porque na funcao de criar bloco eu so preciso ordenar as transacaoes e pegar as MX ultimas na lista para adicionar a blockchain*/

/* classe TIterator */
// construtores
TIterator::TIterator():
    _block_ptr(NULL), _transaction_ptr(NULL){}

TIterator::TIterator(Block* block_ptr, Transaction* transaction_ptr):
    _block_ptr(block_ptr), _transaction_ptr(transaction_ptr){}

// destrutor
TIterator::~TIterator(){}

// operadores
Transaction& TIterator::operator*(){return *(this->_transaction_ptr);}

const Transaction& TIterator::operator*() const{return *(this->_transaction_ptr);}

const bool TIterator::operator==(const TIterator& other) const{return ((this->_block_ptr == other._block_ptr) && (this->_transaction_ptr == other._transaction_ptr));}

const bool TIterator::operator!=(const TIterator& other) const{return ((this->_block_ptr != other._block_ptr) || (this->_transaction_ptr != other._transaction_ptr));}

TIterator TIterator::operator++(){
    if(this->_block_ptr == NULL)
        assert(this->_block_ptr != NULL); // incrementou apos o final da blockchain
    this->_transaction_ptr = this->_transaction_ptr->get_next();
    if(this->_transaction_ptr == NULL){ // chegou no final de um bloco
        this->_block_ptr = this->_block_ptr->get_next();
        while(this->_block_ptr != NULL){
            if(this->_block_ptr->get_first() != NULL)
                break;
            this->_block_ptr = this->_block_ptr->get_next();
        }
        if(this->_block_ptr == NULL)
            return *this;
        this->_transaction_ptr = this->_block_ptr->get_first();
        return *this;
    }
    return *this;
}

TIterator TIterator::operator++(int){
    TIterator old = *this;
    if(this->_block_ptr == NULL)
        assert(this->_block_ptr != NULL); // incrementou apos o final da blockchain
    this->_transaction_ptr = this->_transaction_ptr->get_next();
    if(this->_transaction_ptr == NULL){ // chegou no final de um bloco
        this->_block_ptr = this->_block_ptr->get_next();
        while(this->_block_ptr != NULL){
            if(this->_block_ptr->get_first() != NULL)
                break;
            this->_block_ptr = this->_block_ptr->get_next();
        }
        if(this->_block_ptr == NULL)
            return old;
        this->_transaction_ptr = this->_block_ptr->get_first();
        return old;
    }
    return old;
}
