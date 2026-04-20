#include <iostream>

using namespace std;
#define MAX 6

// Fila circular (alocação estática)
// se precisar modificar o tipo da variável
typedef int TIPOCHAVE;

// cria a estrutura
typedef struct{
    TIPOCHAVE chave;
    //nome
    //cpf
    //idade
}REGISTRO;

// cria a fila
typedef struct{
    REGISTRO A[MAX];
    // variáveis de controle
    // marcar a posição inicial
    int ini;
    // quantidade de elemtentos
    int qtd;
}FILA;

// Funções necessárias
//1 - Inicializar
//2 - retornar a quantidade de elemtentos
//3 - imprimir a fila
//4 - inserir um elemento na fila (no final)
//5 - remover um elemento na fila (início)
//6 - reiniciar a fila

// 1. passa por referência
void init(FILA *f);
// 2. retornar qtd
int qtdElem(FILA *f);
// 3. impressão
void imprimir(FILA *f);
// 4. insere
bool insereFila(FILA *f, REGISTRO reg);
// 5. remover
bool removeFila(FILA *f);


int main()
{
    REGISTRO aux; // auxiliar para inserir
    bool r; // resposta dos métodos

    FILA f; // criação da nossa fila

    // iniciar a manipulação
    init(&f);

    //inserir elementos
    aux.chave=10;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso??
    aux.chave=20;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso??
    aux.chave=30;
    r = insereFila(&f, aux);
    // verificar se inseriu com sucesso??
    aux.chave=40;
    r = insereFila(&f, aux);
    imprimir(&f);

    removeFila(&f);
    imprimir(&f);

    aux.chave=50;
    r = insereFila(&f, aux);

    imprimir(&f);
   
    //implementar um menu
    // validações de inserção e remoção
}

// 1. passa por referência
void init(FILA *f){
    // inicializa a nossa fila
    f->ini = 0; // inicio na posição 0
    f->qtd = 0; // possui 0 elementos
}
// 2. retornar qtd
int qtdElem(FILA *f){
    // retorno quantos elementos a fila possui
    return f->qtd;
}
// 3. impressão
void imprimir(FILA *f){
    // preciso de um for para percorrer o vetor
    //(quantidade de elementos)
    // e precisamos saber a ordem de impressão

    // pegar a posição inicial
    int i = f->ini; // controla o inicio
    int j;
    for(j=0; j < f->qtd; j++){
        cout << f->A[i].chave << " ";
        // pulo do gato
        i = (i + 1) % MAX;
    }
    cout<<endl;
}
// 4. insere
bool insereFila(FILA *f, REGISTRO reg){
    // REGRAS ANTES DE INSERIR
    // - se estiver cheia
    // - atualiza a quantidade de elementos
    if (f->qtd >= MAX)
        return false;
    // calcula a posição para inserir
    int pos = (f->ini + f->qtd) % MAX;
    // insere o elemento
    f->A[pos] = reg;
    // atualiza a quantidade de elementos
    f->qtd++;
    return true;
}
// 5. remover
bool removeFila(FILA *f){
    // preciso verificar para remover??
    // - exclui os primeiros elementos
    // - se existem elementos??
    // ----- removeu:
    // - atualizar a quantidade de elementos
    // - atualiza qual é o início

    if (f->qtd == 0) // a fila é vazia??
        return false;

    // calcular o início
    f->ini = (f->ini + 1) % MAX;
    f->qtd--;
    return true;
}