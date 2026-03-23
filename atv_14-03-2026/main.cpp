/*
Utilizando o código desenvolvido em aula. Criar as seguintes funções:
1) Buscar um elemento na lista. RESPOSTA
2) Remover um elemento da lista (Não é permitido "buracos" na lista")
*/

#include <iostream>

using namespace std;

#define MAX 50 //quantidade maxima de registros na lista

//TIPO DE REGISTRO QUE MINHA LISTA RECEBERÁ
typedef int item; //item é o tipo que vou colocar no registro
typedef struct
{
    item chave;
}REGISTRO;

//LISTA QUE RECEBERÁ OS REGISTROS
typedef struct
{
    REGISTRO A[MAX]; //array da minha variavel lista
    int n_registros; //numero de registros que tem na lista

    //método para inserir na lista
    bool inserir(REGISTRO value, int pos){
        //valida inserção
        if (pos > n_registros || //Se o valor for maior que a quantidade de registros dará erro
            pos < 0 || //Se a posição passada for negativa
            n_registros >= MAX //Se o tamanho da lista chegou no tamanho maximo
        )
        {
            //para a inserção e retorna falso
            return false;
        }
        //quando inserir um valor no meio do vetor, desloca os outros e depois insere
        for(int j=n_registros; j>pos; j--){
            A[j] = A[j-1];
        }
        //Coloca o valor na posição desejada
        A[pos] = value;
        n_registros++;//aumenta a quantidade de registros
        return true;
    }
    //método para buscar um elemento na lista
    //retorna o indice que ele está
    int busca(REGISTRO value){
        int pos = n_registros-1;
        while (pos >= 0)
        {
            REGISTRO comparador;
            if (A[pos].chave == value.chave)
            {
                break;
            }else
            {
                pos--;
            }
        }
        
        return pos;
    }
}LISTA;

int main() {
    cout << "Hello World" << endl;
    return 0;
}