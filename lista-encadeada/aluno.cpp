#include <iostream>

using namespace std;

//Que será inserido na lista encadeada
struct dado{
    //dados internos
    int id;
    //dados de exposicao
    char nome[30];
    char rua[30];
    char email[80];
    dado *prox = NULL;

    void show(){
        //cout << endl;
        cout << "id: " << id; /* << ", ";
        cout << "nome: " << nome << ", ";
        cout << "rua: " << rua << ", ";
        cout << "email: " << email;*/
    }
};

typedef dado no;

typedef struct chain_list 
{
private:
    //Inicio da lista
    no *start;
    //tamanho da lista encadeada
    int tam;
public:
    //Constructor
    chain_list(){
        this->tam = 0; //tamanho 0 da lista
        this->start = NULL; //lista vazia aponta pro nada, o inicio e o fim da lista
    }

    //metodo para inserir no inicio
    void insert_ini(dado d){
        no *novo = new no; //que sera inserido
        *novo = d; //recebe o valor do dado
        
        //o novo no aponta para o antigo primeiro
        novo->prox = this->start;

        //Atualiza o inicio da lista
        this->start = novo;
        this->tam++;
    };
    //metodo para inserir no final
    void insert_end(dado d){
        no *atual = start;
        no *novo = new no;
        *novo = d;
        novo->prox = NULL; //aponta pro final (NULL)


        //SE ESTIVER COM VALORES
        if(start != NULL)
        {
            //percorre a lista encadeada para colocar no final
            while (atual->prox != NULL)
            {
                //PROXIMO!!! ("caixa gritando")
                atual = atual->prox;
            }
            //chega no elemento final e insere o novo
            atual->prox = novo;
        }else{
            //O final e o inicio
            start = novo;
        }
        //aumenta o tamanho da lista
        tam++;
    }
    //metodo para mostrar a lista
    void show(){
        //caso lista vazia
        if(start == NULL){
            cout << "Lista vazia!!";
            return;
        }
        no *atual = this->start;
        while (atual != NULL)
        {
            atual->show();
            cout << " ";
            atual = atual->prox;
        }
    }
    //metodo para remover valor (lista duplamente encadeada)

};


int main(){
    //VARIAVEIS
    chain_list l; //lista encadeada
    dado temp; //valor que sera inserido na lista
    temp.prox = NULL;
    int *id = &temp.id;//acesso mais rapido ao id de temp

    //INTERACOES
    cout << "Inserindo 3 na lista" << endl;
    temp.id = 3;
    l.insert_ini(temp);

    cout << "Inserindo 2 na lista" << endl;
    temp.id = 2;
    l.insert_ini(temp);

    cout << "Inserindo 14 na lista" << endl;
    temp.id = 14;
    l.insert_ini(temp);

    cout << "Lista encadeada: ";
    l.show();
    cout << endl;

    cout << "Inserindo 7 no fim da lista" << endl;
    *id = 7;
    l.insert_end(temp);
    cout << "Inserindo 99 no fim da lista" << endl;
    *id = 99;
    l.insert_end(temp);
    cout << "Inserindo 1 no fim da lista" << endl;    
    *id = 1;
    l.insert_end(temp);

    cout << "Lista encadeada: ";
    l.show();

    return 0;
}