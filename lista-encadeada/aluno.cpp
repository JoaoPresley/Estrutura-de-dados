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
    dado *prox;

};

typedef dado no;

typedef struct 
{
private:
    //Lista interna (simplesmente encadeada)
    struct lista{
        int tam; //tamanho da minha lista encadeada
        no *start;
    };
    //Cria a lista interna a lista interna
    lista l;

    //Constructor da lista encadeada
    void chain_list(){
        //apontado pro nada
        l.start = NULL;
        //tamanho 0
        l.tam = 0;
    }
public:
    //metodo para inserir no inicio
    void insert_ini(dado d){
        
    };
    //metodo para inserir no final
    //metodo para mostrar a lista
    //metodo para remover valor (lista duplamente encadeada)

}chain_list;


int main(){
    cout << "Hello wordl";
    return 0;
}