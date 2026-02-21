#include <iostream>
#include <string.h>

using namespace std;

void change(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main(){
    int a, b; //criação de variável p/ inteiros
    int *ptr; //variável que armazena endereço da memória do tipo inteiro
    // definir valores para as nossas variáveis
    a=10; // atribuiu o valor inteiro
    b=50; // atribuiu o valor inteiro
    cout<<"Endereco variável a: "<<&a<<endl;
    cout<<"Endereco variável b: "<<&b<<endl;

    ptr=&a; // armazena o endereço de a ao 'ptr'
    cout<<"Endereco armazenado pelo ptr: "<<ptr<<endl;
    cout<<"Valor armazenado pelo ptr: "<<*ptr<<endl;

    //modificar o ponteiro
    *ptr=80;
    cout<<"Novo valor da variável a: "<<a<<endl;


    //Questão proposta
    //  mostra valores antes da troca
    cout << "-------------------" << endl;
    cout << "Valores antes da troca:" << endl;
    cout << "a: "<< a << endl;
    cout << "b: "<< b << endl;
    cout << "-------------------" << endl;
    
    change(&a, &b);//Realiza a troca de valores

    //Mostra valores depois da troca
    cout << "-------------------" << endl;
    cout << "Valores apos a troca:" << endl;
    cout << "a: "<< a << endl;
    cout << "b: "<< b << endl;
    cout << "-------------------" << endl;
    return 0;
}