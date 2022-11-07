#include <iostream>
#include <string>
#include "MyVecNewIterator.h"
//#include "MyStack.h"
//#include "MyQueue.h"
#include "MyPriorityQueue.h"
#include "Mediana.h"

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"
template <class T>
class node{
public:
    node(const T& elem):
        _data(elem), _next(NULL){}
    ~node(){}
    T _data;
    node<T>* _next;
};

template <class T>
class my_stack{
public:
    my_stack(){this->create();}
    ~my_stack(){this->destroy();}
    void clear(){
        this->create();
        this->destroy();
        return;
    }
    void push(const T& el){
        node<T>* ptr = new node<T>(el);
        ptr->_next = this->_stack_top;
        this->_stack_top = ptr;
        return;
    }
    const T top() const{return this->_stack_top->_data;}
    void pop(){
        if(this->_stack_top != NULL){
            node<T>* ptr = this->_stack_top;
            this->_stack_top = this->_stack_top->_next;
            delete ptr;
        }
        return;
    }
    const bool empty(){
        if(this->size() == 0)
            return true;
        return false;
    }
    const int size(){
        int size = 0;
        node<T>* ptr = this->_stack_top;
        while(ptr != NULL){
            size++;
            ptr = ptr->_next;
        }
        return size;
    }
    void print() const{
        cout << "top-> ";
        node<T>* ptr = this->_stack_top;
        while(ptr != NULL){
            cout << ptr->_data << " ";
            ptr = ptr->_next;
        }
        cout << endl;
        return;
    }
private:
    node<T>* _stack_top;
    void create(){
        this->_stack_top = NULL;
        return;
    }
    void destroy(){
        if(this->_stack_top != NULL){
            node<T>* ptr = this->_stack_top->_next;
            while(ptr != NULL){
                delete this->_stack_top;
                this->_stack_top = ptr;
                ptr = ptr->_next;
            }
            delete this->_stack_top;
            return;
        }
    }
};

template <class T>
class my_queue{
public:
    my_queue(){this->create();}
    ~my_queue(){this->destroy();}
    void clear(){
        this->create();
        this->destroy();
        return;
    }
    void push(const T& el){
        if(this->_queue_begin == NULL){
            this->_queue_begin = this->_queue_end = new node<T>(el);
            return;
        }
        node<T>* ptr = new node<T>(el);
        this->_queue_end->_next = ptr;
        this->_queue_end = ptr;
        return;
    }
    const T front() const{return this->_queue_begin->_data;}
    void pop(){
        if(this->_queue_begin != NULL){
            node<T>* ptr = this->_queue_begin;
            this->_queue_begin = ptr->_next;
            delete ptr;
        }
        return;
    }
    const bool empty(){
        if(this->size() == 0)
            return true;
        return false;
    }
    const int size(){
        int size = 0;
        node<T>* ptr = this->_queue_begin;
        while(ptr != NULL){
            size++;
            ptr = ptr->_next;
        }
        return size;
    }
private:
    node<T> *_queue_begin, *_queue_end;
    void create(){
        this->_queue_end = this->_queue_begin = NULL;
        return;
    }
    void destroy(){
        if(this->_queue_begin != NULL){
            node<T>* ptr = this->_queue_begin->_next;
            while(ptr != NULL){
                delete this->_queue_begin;
                this->_queue_begin = ptr;
                ptr = ptr->_next;
            }
            delete this->_queue_begin;
            return;
        }
    }
};

void prova(my_stack<int>& stack){
    if(stack.empty())
        return;
    my_stack<int> aux;
    int size = 0;
    while(stack.empty() == false){
        aux.push(stack.top());
        size++;
        stack.pop();
    }
    if(size < 2)
        return;
    while(aux.empty() == false){
        stack.push(aux.top());
        aux.pop();
    }
    while(size > 1){
        int menor, i = 0, j = 0;
        menor = stack.top();
        stack.pop();
        while(i < size - 1){
            if(stack.top() < menor){
                aux.push(menor);
                menor = stack.top();
                stack.pop();
            }else{
                aux.push(stack.top());
                stack.pop();
            }
            i++;
        }
        while(j < size - 1){
            stack.push(aux.top());
            aux.pop();
            j++;
        }
        aux.push(menor);
        size--;
    }
    while(aux.empty() == false){
        stack.push(aux.top());
        aux.pop();
    }
    return;
}

void etapa1(){
    my_stack<int> stack;
    my_queue<int> queue;
    int aux;
    for(int i = 0; i < 6; i++){
        cin >> aux;
        stack.push(aux);
        queue.push(aux);
    }
    while(stack.empty() == false){
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    while(queue.empty() == false){
        cout << queue.front() << " ";
        queue.pop();
    }
    cout << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
    my_stack<char> stack;
    stack.push('=');
    string entrada;
    //cin >> entrada;
    cin.ignore();
    std::getline(std::cin,entrada);
    //cout << entrada << endl;
    bool consistencia = true;
    unsigned long int i = 0;
    while(consistencia){
        if(i >= entrada.size())
            break;
        else if(entrada[i] != '(' && entrada[i] != ')' && entrada[i] != '[' && entrada[i] != ']' && entrada[i] != '{' && entrada[i] != '}'){
            i++;
            continue;
        }
        else if(entrada[i] == '(' || entrada[i] == '[' || entrada[i] == '{'){
            stack.push(entrada[i]);
            i++;
            continue;
        }
        else if(entrada[i] == ')'){
            if(stack.top() == '('){
                stack.pop();
                i++;
                continue;
            }else{
                consistencia = false;
                break;
            }
        }
        else if(entrada[i] == ']'){
            if(stack.top() == '['){
                stack.pop();
                i++;
                continue;
            }else{
                consistencia = false;
                break;
            }
        }
        else if(entrada[i] == '}'){
            if(stack.top() == '{'){
                stack.pop();
                i++;
                continue;
            }else{
                consistencia = false;
                break;
            }
        }
    }
    if(stack.size() > 1)
      consistencia = false;
    if(consistencia)
        cout << "Consistente";
    else
        cout << "Inconsistente";
    cout << endl;
    return;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
//#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
    Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
    cout << endl;
}

//---------------------------------------

void etapa4(){
    int a;
    my_stack<int> stack;
    while(cin >> a)
        stack.push(a);
    stack.print();
    prova(stack);
    stack.print();
    return;
}

int main(int argc, char **argv) {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
        case 4:
            cout << "Etapa 4" << endl;
            etapa4();
            break;
    }
    return 0;
}
