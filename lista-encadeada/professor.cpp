#include <iostream>
#include <stdlib.h> // trabalhar com malloc/free

using namespace std;

struct address {
    int chave;
    char nome[30];
    char rua[30];
    char email[80];
    struct address *prox;
};

typedef struct address no;

typedef struct {
    no *inicio;  
    int tam;    
} LISTA;

void init(LISTA *l) {
    l->inicio = NULL;
    l->tam = 0;
}

// CORREÇÃO: Adicionado o l->inicio = novo;
void insere_ini(LISTA *l, int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return; // Verificação de memória

    novo->chave = valor;
    novo->prox = l->inicio;
    l->inicio = novo; // O início agora é o novo nó
    l->tam++;
}

void insere_fim(LISTA *l, int valor) {
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL) return;
    
    no *atual;
    novo->chave = valor;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo; 
    } else {
        atual = l->inicio;
        while(atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    l->tam++;
}

void remove(LISTA *l, int valor){
    //Cria dois ponteiros, um atual e outro anterior
    no *atual = (no*) malloc(sizeof(no));
    no *anterior = (no*) malloc(sizeof(no));

    //coloca o atual no inicio e o anterior como nulo
    atual = l->inicio;
    anterior = NULL;

    //Percorre a lista ate achar o valor procurado
    //Enquanto for != NULL e != valor
    while (atual->chave != valor && atual->prox != NULL)
    {
        anterior = atual;
        atual = atual->prox;
    }//Chegou no valor encontrado ou nao encontrou o valor

    //Caso não encontrou o valor
    if(atual == NULL){
        cout << "Valor nao encontrado!";
        return;
    }
    
    //Caso tenha encontrado ha 2 casos
    //Se no inicio
    //Se no meio ou fim (caem da na mesma)
    if (anterior == NULL)//anterior nao foi preenchido significa que o atual nao se moveu
    {
        l->inicio = atual->prox;
    }else{//Caso seja um elemento no meio ou o elemento final
        //proximo pula o elemento atual
        anterior->prox = atual->prox;
    }
    //libera a memoria do atual
    free(atual);
    //atualiza a quantidade de elementos
    l->tam--;
}

void imprime(LISTA *l) {
    no *atual = l->inicio;
    cout << "\n--- EXIBINDO LISTA ---" << endl;
    cout << "Tamanho atual: " << l->tam << endl;
    
    if (l->inicio == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    while (atual != NULL) {
        cout << "[" << atual->chave << "] -> ";
        atual = atual->prox;
    }
    cout << "NULL" << endl;
}

// Implementando a main para testar
int main() {
    LISTA minhaLista;
    
    // 1. Inicializar
    init(&minhaLista);

    // 2. Inserir elementos
    cout << "Inserindo 10 e 20 no inicio..." << endl;
    insere_ini(&minhaLista, 10);
    insere_ini(&minhaLista, 20);

    cout << "Inserindo 30 e 40 no fim..." << endl;
    insere_fim(&minhaLista, 30);
    insere_fim(&minhaLista, 40);

    // 3. Imprimir resultados
    imprime(&minhaLista);


    remove(&minhaLista, 30);

    imprime(&minhaLista);
    return 0;
}

