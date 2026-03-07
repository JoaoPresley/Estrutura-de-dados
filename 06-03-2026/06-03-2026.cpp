#include <iostream>
using namespace std;
//Fila estática -> tamanho não altera
//Fila dinâmica -> fila altera

#define MAX 50

// Definir um "apelido" para o tipo int
// Se no futuro quiser alterar o tipo da chave, para long ou string basta altera-lo
typedef int TIPOCHAVE;

//Criei uma estrutura e defini um apeldio para ela
typedef struct {
    TIPOCHAVE chave;
}CADASTRO;

typedef struct{
    CADASTRO A[MAX];
}LSITA;


struct REGISTRO
{
    int chave;
};
//1. Passagem por valor não surge efeito na main
void alteraPorValor(REGISTRO reg){
    //Atribuição de valor
    reg.chave = 10;
    cout << "Na funcao por valor: " << reg.chave;
}
//2. Passagem por ponteiro (End. da memoria)
void alterarPorPonteiro(REGISTRO *reg){
    //Atribuição de valor
    reg -> chave = 20;
    cout << "Na funcao por ponteiro: " << reg->chave;
}
//3. Passagem por referência
void alteraPorReferencia(REGISTRO &reg){
    //Atribuição de valor
    reg.chave = 30;
    cout << "Na funcao por referencia: " << reg.chave;
}

int main(){
    //Declara a estrutura
    REGISTRO meureg;
    //Atribuição de valor
    meureg.chave = 0;

    //Chama função que altera por valor
    alteraPorValor(meureg);
    cout << "\nNa main: " << meureg.chave << endl;
    //Chama a função que altera por ponteiro
    alterarPorPonteiro(&meureg);
    cout << "\nNa main: " << meureg.chave << endl;
    //Chama a função que altera por referência
    alteraPorReferencia(meureg);
    cout << "\nNa main: " << meureg.chave;

    return 0;
}