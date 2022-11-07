#ifndef MEDIANA_H
#define MEDIANA_H

#include "MyPriorityQueue.h"

using namespace std;

class Mediana{
public:
    Mediana();
    ~Mediana();
    void insere(int);
    const int getMediana() const;
    MyPriorityQueue<int> _maiores, _menores;
};

#endif // MEDIANA_H
