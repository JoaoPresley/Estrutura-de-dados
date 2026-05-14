#include <iostream>

using namespace std;

// Nó da lista encadeada
struct no {
    int valor;
    no *prox;
    no *ant;

    no() {
        this->prox = NULL;
        this->ant = NULL;
    }
};

struct Lista {
private:
    no *inicio; // aponta pro inicio da lista
    no *fim;    // aponta pro fim da lista
public:
    int tam;

    // Constructor
    Lista() {
        this->tam = 0;
        this->fim = NULL;
        this->inicio = NULL;
    }

    void insere_fim(int v) {
        no *novo = new no;
        novo->valor = v;

        if (this->inicio == nullptr) {
            this->inicio = novo;
            this->fim = novo;
        } else {
            novo->ant = this->fim;
            this->fim->prox = novo;
            this->fim = novo;
        }
        this->tam++;
    }

    // Func para mostrar lista do início ao fim
    void show_inicio() {
        if (inicio == NULL) {
            cout << "Lista vazia!" << endl;
            return;
        }
        no *atual = this->inicio;
        while (atual != NULL) {
            if (atual->prox != NULL) {
                cout << atual->valor << " <-> ";
            } else {
                cout << atual->valor << endl;
            }
            atual = atual->prox;
        }
    }

    // Func para mostrar lista do fim ao início
    void show_fim() {
        if (fim == NULL) {
            cout << "Lista vazia!" << endl;
            return;
        }
        no *atual = this->fim;
        while (atual != NULL) {
            if (atual->ant != NULL) {
                cout << atual->valor << " <-> ";
            } else {
                cout << atual->valor << endl;
            }
            atual = atual->ant;
        }
    }
};

// Função de Menu
int menu() {
    int opcao;
    cout << "\n--- MENU DE OPCOES ---" << endl;
    cout << "1. Inserir elemento no fim" << endl;
    cout << "2. Mostrar do inicio ao fim" << endl;
    cout << "3. Mostrar do fim ao inicio" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha: ";
    cin >> opcao;
    cout << "\033[2J\033[1;1H";
    return opcao;
}

int main() {
    Lista minhaLista;
    int opcao, valor;

    do {
        opcao = menu();
        
        

        switch (opcao) {
            case 1:
                cout << "Digite o valor para inserir: ";
                cin >> valor;
                minhaLista.insere_fim(valor);
                cout << "Valor inserido com sucesso!" << endl;
                break;
            case 2:
                cout << "Lista (Inicio -> Fim): ";
                minhaLista.show_inicio();
                break;
            case 3:
                cout << "Lista (Fim -> Inicio): ";
                minhaLista.show_fim();
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}