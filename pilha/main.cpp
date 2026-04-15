#include <iostream>

using namespace std;

#define MAX 10 //Quantidade maxima de valores na lista

struct Pilha
{
private:
    int array[MAX]; //lista interna que quarda os valores da pilha
    int pos = 0; //posição que está o ultimo valor da pilha

public:
    //pull -> inserir algum valor na pilha
    void push(int v){
        if(pos < MAX){
            array[pos] = v;
            pos++;
        }else{
            throw runtime_error("ERRO: Tamanho maximo da pilha atingido");
        }
    }
    //push -> devolve o valor da pilha
    int pop(){
        int r = array[pos-1];
        pos--;
        return r;
    }
    //show -> mostra os valores na pilha
    void show(){
        if(pos > 0){
            cout << endl;
            for (int i = 0; i < pos; i++)
            {
                cout << array[i] << " " ;
            }
            cout << endl;
            for (int i = 0; i < pos-1; i++)
            {
                cout << "  ";
            }
            cout << "^";
        }else{
            cout << "Pilha vazia";
        }
    }
    //Vizualiza o ultimo valor sem retira-lo
    int peek(){
        if(pos>0){
            return array[pos-1];
        }else{
            throw runtime_error("ERRO: Pilha está vazia");
        }
    }
    //Retorna o tamanho da pilha
    int size(){
        return pos;
    }
    //Limpa a pilha
    void clean(){
        pos = 0; //apenas colocar o ponteiro da lista no inicio 0
    }
    //Busca o valor na pilha e retorna o indice
    int search(int v){
        for (int i=0; i<pos; i++){
            if(array[i] == v){
                return i;
            }
        }
        return -1; //caso não encontre o valor procurado
    }

};


int main() {
    Pilha p;
    //Insere algum valor na pilha
    p.push(3);
    p.push(1);
    p.push(8);

    cout << "Olhada no topo: " << p.peek();
    //Mostra a pilha
    p.show();
    cout << endl;

    cout << "Removido valor: " << p.pop() << endl;
    p.show();
}