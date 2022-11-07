#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <cassert>

/*struct que armazena as informacoes sobre a transacao
  como a classe blockchain vai usar esse struct,
  ele nao foi criado na main*/
struct inf_transacoes{
    // construtores
    inf_transacoes();
    inf_transacoes(const int, const int, const int, const int);
    // destrutor
    ~inf_transacoes();
    // atributos
    int de, para, valor, taxa;
};

/*classe que armazena uma transacao, funciona
  como nodo de lista simplesmente encadeada*/
class Transaction{
public:
    // construtores
    Transaction();
    Transaction(int de, int para, int valor, int taxa, Transaction* next);
    // destrutor
    ~Transaction();
    // metodos get
    const int get_de() const;
    const int get_para() const;
    const int get_valor() const;
    const int get_taxa() const;
    Transaction* get_next() const;
    // metodos set
    void set_next(Transaction* next);
    void set_de(const int);
    void set_para(const int);
    void set_valor(const int);
    void set_taxa(const int);
    // outros metodos
    void imprime() const;
private:
    // atributos
    int _de, _para, _valor, _taxa;
    Transaction* _next;
};

#endif // TRANSACTION_H
