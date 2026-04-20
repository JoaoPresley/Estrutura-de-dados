//CRIANDO UMA FILA CIRCULAR
#include <iostream>
#include <vector> // para trabalhar com arrays

using namespace std;

#define MAX 5 //Valor maximo da fila circular

struct Fila_circular
{
private:
    int array[MAX]; //lista interna que quarda os valores da fila
    int first = 0; //indice que controla o inicio da fila
    int qnt = 0; //quantidade de elementos na fila

    //Calcula de proximo na fila circular
    void calc_next(int &i){
        i = (i+1) % MAX;
    }
    int get_end(){
        return (first + qnt) % MAX;
    }

public:
    //push -> inserir algum valor na fila
    void push(int v){
        if(qnt < MAX){
            array[get_end()] = v;
            qnt++;
        }else{
            throw runtime_error("ERRO: Tamanho maximo da fila atingido");
        }
    }
    //pop -> devolve o valor da fila
    int pop(){
        //FIFO -> first in first out
        if (qnt > 0)
        {
            //caso a lista tenha algum valor, o valor a ser retirado é o primeiro da fila
            int r = array[first];
            calc_next(first);
            qnt--;
            return r;
        }else
        {
            //caso a lista esteja vazia não tem o que retirar
            throw runtime_error("ERRO: Fila vazia");
        }
    }
    //show -> mostra os valores na filaz
    void show(){
        if(qnt > 0){
            cout << endl;
            int temp = first; //variavel temporaria para percorrer a fila sem alterar o indice do primeiro
            for(int i=0; i<qnt; i++)
            {
                cout << array[temp] << " " ;
                calc_next(temp);
            }
            cout << endl;
        }else{
            cout << "Fila vazia";
        }
    }
    //size -> retorna o tamanho da fila
    int size(){
        return qnt;
    }

};


int main() {
    Fila_circular f; // criando a fila circular
    int opcao, valor;

    do {
        cout << "\n--- MENU FILA CIRCULAR (Capacidade: " << MAX << ") ---" << endl;
        cout << "1. Inserir (Push)" << endl;
        cout << "2. Remover (Pop)" << endl;
        cout << "3. Mostrar Fila (Show)" << endl;
        cout << "4. Ver Tamanho (Size)" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor para inserir: ";
                cin >> valor;
                try {
                    f.push(valor);
                    cout << "Valor " << valor << " inserido com sucesso!" << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl; // Exibe o erro de fila cheia
                }
                break;

            case 2:
                try {
                    valor = f.pop();
                    cout << "Valor removido: " << valor << endl;
                } catch (const runtime_error& e) {
                    cout << e.what() << endl; // Exibe o erro de fila vazia
                }
                break;

            case 3:
                cout << "Conteudo da fila:";
                f.show();
                break;

            case 4:
                cout << "Quantidade de elementos atual: " << f.size() << endl;
                break;

            case 0:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}