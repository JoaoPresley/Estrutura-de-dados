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
    int n_registros = 0; //numero de registros que tem na lista

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
        //Começa a busca no fim do vetor
        int pos = n_registros-1;
        //vai varrendo todo o vetor até chegar ao final
        while (pos >= 0)
        {
            if (A[pos].chave == value.chave)//achou o registro? para e retorna a posição
            {
                break;
            }else//não achou? continua decrementando até achar
            {
                pos--;
            }
        }
        //se retornar -1 é pq não encontrou
        return pos;
    }
}LISTA;

int main() {
    //Criação das variaveis
    LISTA l; //lista que será manipulada
    REGISTRO aux; //registro que será inserido na lista
    int encontrado; //posição do item que foi encontrado
    bool resp; //resposta da inserção

    //INSERINDO ITENS NA LISTA
    cout << "-----1 ETAPA - INSERCAO DE VALORES-------"<<endl;
    aux.chave = 1;
    resp = l.inserir(aux, 0); //insere na posição correta
    cout << "Inserido valor " << aux.chave << "na lista l: ";
    if(resp){
        cout << "INSERIDO COM SUCESSO!";
    }else{
        cout << "FALHA AO INSERIR!";
    }
    cout << "\n\n";

    aux.chave = 2;
    resp = l.inserir(aux, 1); //insere na posição correta
    cout << "Inserido valor " << aux.chave << "na lista l: ";
    if(resp){
        cout << "INSERIDO COM SUCESSO!";
    }else{
        cout << "FALHA AO INSERIR!";
    }
    cout << "\n\n";

    aux.chave = 60;
    resp = l.inserir(aux, 5); //insere na posição incorreta
    cout << "Inserido valor " << aux.chave << " na lista l: ";
    if(resp){
        cout << "INSERIDO COM SUCESSO!";
    }else{
        cout << "FALHA AO INSERIR!";
    }

    return 0;
}