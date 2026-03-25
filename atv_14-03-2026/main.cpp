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
    bool remove(REGISTRO value){
        int i = busca(value); //Item encontrado
        //Valida condições antes da remoção
        if (i<0){
            cout << "Item nao pertence a lista" << endl;
            return false;
        }else if(n_registros < 1){
            cout << "Lista vazia" << endl;
        }

        //Remove o item preenchendo com os valores seguintes
        for (size_t j = i; j < n_registros-1; j++)
        {
            A[j] = A[j+1]; //Arrasta a lista
        }
        n_registros--;
        cout << "Lista atualizada, n_registros: " << n_registros << " \n";
    }
}LISTA;

int main() {
    //Criação das variaveis
    LISTA l; //lista que será manipulada
    REGISTRO aux; //registro que será inserido na lista
    int encontrado; //posição do item que foi encontrado
    bool resp; //resposta da inserção


    //----------------INSERINDO ITENS NA LISTA---------------
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
    cout << endl << endl;

    //--------------------POVOANDO O RESTANTE DA LISTA ---------------------
    for (size_t i = 0; i < 10; i++)
    {
        aux.chave = i*3;
        l.inserir(aux, l.n_registros);
    }
    //--------------BUSCANDO UM ITEM NA LISTA--------------
    //Com um valor que não existe
    aux.chave = 7; //esse será o valor buscado na lista
    cout << "-----2 ETAPA - BUSCA DE VALORES-------"<<endl;
    cout << "Buscando valor " << aux.chave << " na lista l" << endl;
    encontrado = l.busca(aux);
    if (encontrado >= 0) cout << "Valor encontrado na posição " << encontrado << " da lista";
    else cout << "Valor nao encontrado";
    cout << endl << endl;

    //Com um valor que existe
    aux.chave = 15; //esse será o valor buscado na lista
    cout << "Buscando valor " << aux.chave << " na lista l" << endl;
    encontrado = l.busca(aux);
    if (encontrado >= 0) cout << "Valor encontrado na posicao " << encontrado << " da lista (" << l.A[encontrado].chave << ")";
    else cout << "Valor nao encontrado";
    cout << endl << endl;

    //--------------REMOVENDO UM ITEM NA LISTA--------------
    //Com um valor que não existe
    aux.chave = 7; //esse será o valor buscado na lista
    cout << "-----3 ETAPA - REMOCAO DE VALORES-------"<<endl;
    resp = l.remove(aux);
    if (resp){
        cout << "Item removido da lista!!";
    }else{
        cout << "Nao foi possivel remover item da lista";
    }
    cout << endl << endl;

    //Com um valor que existe
    aux.chave = 18;
    cout << "Item no fim da lista: " << l.A[l.n_registros-1].chave << endl;
    resp = l.remove(aux);
    if (resp){
        cout << "Item removido da lista!!";
    }else{
        cout << "Nao foi possivel remover item da lista";
    }
    cout << "Item no fim da lista: " << l.A[l.n_registros-1].chave << endl;
    
    return 0;
}