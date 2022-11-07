#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

class TIterator;

/* classe que armazena uma lista duplamente encadeada de Blocks */
class Blockchain{
    friend class TIterator;
public:
    // construtores
    Blockchain();
    Blockchain(const Blockchain&); // construtor de copia
    // destrutor
    ~Blockchain();
    // operadores
    Blockchain& operator=(const Blockchain&);
    // metodos get
    Block* get_first() const;
    Block* get_last() const;
    // metodos set
    void set_first(Block*);
    void set_last(Block*);
    // outros metodos
    void create_block(int*, inf_transacoes*);
    void print_blockchain() const;
    void print_balances(const int) const;
    void modify_transaction(const int*);
    const int blockchain_size() const;
    const int num_users(const int) const;
    // iterador
    typedef TIterator TransactionIterator;
    TransactionIterator transactionBegin() const;
    TransactionIterator transactionEnd() const;
private:
    // atributos
    Block *_first, *_last;
    // metodos private
    void create();
    void destroy_blocks();
    void clear();
    const int min(const int, const int) const;
    void merge(inf_transacoes*, inf_transacoes*, const int, const int, const int) const;
    void merge_sort(inf_transacoes*, const int) const;
};

/* classe que funciona como um iterador de transacoes, percorrendo a blockchain*/
class TIterator{
    friend class Blockchain;
public:
    // construtores
    TIterator();
    TIterator(Block*, Transaction*);
    // destrutor
    ~TIterator();
    // operadores
    Transaction& operator*();
    const Transaction& operator*() const;
    const bool operator==(const TIterator&) const;
    const bool operator!=(const TIterator&) const;
    TIterator operator++();
    TIterator operator++(int);
private:
    // atributos
    Block* _block_ptr;
    Transaction* _transaction_ptr;
};

#endif // BLOCKCHAIN_H
