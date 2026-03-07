#include <iostream>
using namespace std;

struct REGISTRO
{
    int chave;
};
//1. Passagem por valor não surge efeito na main
void alteraPorValor(REGISTRO reg){
    reg.chave = 10;
    cout << "Na funcao: " << reg.chave;
}

int main(){
    //Declara a estrutura
    REGISTRO meureg;
    //Atribuição de valor
    meureg.chave = 0;
    //Chama função que altera por valor
    alteraPorValor(meureg);
    cout << "\nNa main: " << meureg.chave;

    return 0;
}