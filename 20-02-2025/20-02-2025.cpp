#include <iostream>
using namespace std;
int main(){
    int a, b; //Variaveis int
    int *ptr; //Ponteiro int

    //Atribui valor as variaiveis inteiras
    a = 10;
    b = 50;

    //Apresentação dos endereços
    cout << "Endereco da variavel a: " << &a << endl;
    cout << "Endereco da variavel b: " << &b << endl;

    ptr = &a;//Atribui valor ao ponteiro, endereço de a

    //Apresenta o ponteiro
    cout << "Endereco que armazena a: " << ptr << endl;
    cout << endl; //Pula linha
    cout << "Valor armazenado pelo ponteiro: " << *ptr << endl;

    //Modificando valor do ponteiro
    *ptr = 80;
    cout << "Valor do endereco " << ptr << ", ocupado por a eh: " << a;

    cout << endl;
    return 0;
}