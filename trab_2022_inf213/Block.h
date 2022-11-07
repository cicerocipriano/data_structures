#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include "SHA256.h" // header que calcula hashes

/*classe que armazena as informacoes do bloco
  e uma lista encadeada de transacoes
  funciona como um nodo de lista duplamente
  encadeada (que tem uma lista encadeada dentro)*/
class Block{
public:
    // construtores
    Block();
    Block(const int, const int, const int);
    Block(const int, const int, const int, const int);
    Block(const Block&); // construtor de copia
    // destrutor
    ~Block();
    // operadores
    Block& operator=(const Block&);
    // metodos get
    const int get_pos() const;
    const int get_prevHash() const;
    const int get_criador() const;
    Transaction* get_first() const;
    Transaction* get_last() const;
    Block* get_prev() const;
    Block* get_next() const;
    const int get_proofWork() const;
    // metodos set
    void set_first(Transaction*);
    void set_last(Transaction*);
    void set_prev(Block*);
    void set_next(Block*);
    void set_proofWork(const int);
    // outros metodos
    void addTransaction(const int, const int, const int, const int);
    void mineBlock();
    const int getHash() const;
    const bool validate_block() const;
    const int transactions_size() const;
private:
    // atributos
    int _pos, _prevHash, _criador;
    Transaction *_first, *_last;
    Block *_prev, *_next;
    int _proofWork;
    // metodos private
    void create();
    void destroy_transactions();
    void clear();
};

#endif // BLOCK_H
