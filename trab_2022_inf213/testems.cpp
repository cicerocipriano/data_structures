#include <iostream>

using namespace std;

struct A{
    A():
        a(0), b(0){}
    int a;
    char b;
};

int min(const int a, const int b){
    if(a > b)
        return b;
    return a;
}

void merge(A *v, int p, int q, int r, A *aux) {
    int tam = r-p;
    int i = p; //cursor 1
    int j = q; //cursor 2
    int k = 0; //cursor para aux
    while(i < q && j < r) {
      if (v[i].a < v[j].a)
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while(i < q)
        aux[k++] = v[i++];
    while(j < r)
        aux[k++] = v[j++];
    for(k = 0; k < tam; k++)
        v[p+k] = aux[k];
}

/* Ordena o vetor v entre as posicoes p e r-1 */
void mergeSort(A *v, int size){
    A* aux = new A[size];
    if(size < 2)
        return;
    for(int tam = 2; tam <= size * 2; tam *= 2){
        for(int i = 0; i < size; i += tam){
            if(size - i < tam)
                merge(v,i,min(i + tam / 2, size),size,aux);
            else
                merge(v, i, (2 * i + tam) / 2, i + tam,aux);
        }
    }
    delete[] aux;
}

int main(int argc, char **argv){
    int a;
    cin >> a;
    A* b = new A[a];
    for(int i = 0; i < a; i++){
        b[i].a = a - i;
        b[i].b = 65 + i;
    }
    mergeSort(b,a);
    for(int i = 0; i < a; i++){
        cout << b[i].a << b[i].b << endl;
    }
    delete[] b;
    return 0;
}
