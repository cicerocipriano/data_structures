#include "Mediana.h"

using namespace std;

Mediana::Mediana(){}

Mediana::~Mediana(){}

void Mediana::insere(int x){
    if(_menores.size() == _maiores.size() && _maiores.size() == 0)
        _menores.push(x);
    else if(_menores.size() == _maiores.size() && _maiores.size() > 0){
        if(x <= _menores.top())
            _menores.push(x);
        else
            _maiores.push_inv(x);
    }
    else if(_menores.size() - 1 == _maiores.size()){
        if(x < _menores.top()){
            int aux = _menores.top();
            _menores.pop();
            _menores.push(x);
            _maiores.push_inv(aux);
        }else
            _maiores.push_inv(x);
    }
    else if(_maiores.size() - 1 == _menores.size()){
        if(x > _maiores.top()){
            int aux = _maiores.top();
            _maiores.pop_inv();
            _maiores.push_inv(x);
            _menores.push(aux);
        }else
            _menores.push(x);
    }
    return;
}

const int Mediana::getMediana() const{
    int med;
    if(_maiores.size() > _menores.size())
        med = _maiores.top();
    else if(_maiores.size() < _menores.size())
        med = _menores.top();
    else
        med = (_menores.top() + _maiores.top()) / 2;
    return med;
}
