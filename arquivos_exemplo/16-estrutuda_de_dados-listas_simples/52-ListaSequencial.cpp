#include <stdlib.h>
#include <new>
#include <string>
#include <iostream>

using namespace std;

struct Pessoa {
    int rg;
    string nome;
};

void limparTela() {
    system("clear");
}

void imprimirLista(Pessoa *ponteiroSequencial, int tamanhoLista) {
    if (tamanhoLista > 0) {
        cout << "..:: LISTA DE PESSOAS ::.." << "\n";
        for(int i = 0; i < tamanhoLista; i++) {
            cout << i << " -> " << "RG: " << ponteiroSequencial[i].rg << ", nome: " << ponteiroSequencial[i].nome << "\n";
        }
        cout << "\n";
    }
}

void addElementoInicio(int *tamanhoDaLista, int rg, string nome, Pessoa *&ponteiroSequencial) {
    /* O *& significa que o parâmetro é um ponteiro com escopo global
       Ou seja, toda alteração que for realizado nele dentro da função,
       será refletida no na lista principal */

    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista + 1];

    //Adicionar uma nova pessoa na lista
    novaListaSequencial[0].rg = rg;
    novaListaSequencial[0].nome = nome;

    if (*tamanhoDaLista > 0) {
        //Atribuir os valores da antiga lista para a nova
        for (int i = 0; i < *tamanhoDaLista; i++) {
            novaListaSequencial[i + 1].rg = ponteiroSequencial[i].rg;
            novaListaSequencial[i + 1].nome = ponteiroSequencial[i].nome;
        }
    }

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void addElementoFim(int *tamanhoDaLista, int rg, string nome, Pessoa *&ponteiroSequencial) {
    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista + 1];

    //Atribuir os valores da antiga lista para a nova
    for (int i = 0; i < *tamanhoDaLista; i++) {
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
    }

    //Adicionar uma nova pessoa na lista
    novaListaSequencial[*tamanhoDaLista].rg = rg;
    novaListaSequencial[*tamanhoDaLista].nome = nome;

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void addElementoPosicaoIndicada(int *tamanhoDaLista, int rg, string nome, Pessoa *&ponteiroSequencial, int posicao) {
    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista + 1];

    //Atribuir os valores da antiga lista para a nova até a posição indicada
    for (int i = 0; i < posicao; i++) {
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
    }

    //Adicionar uma nova pessoa na lista
    novaListaSequencial[posicao].rg = rg;
    novaListaSequencial[posicao].nome = nome;

    //Atribuir os valores da antiga lista para a nova a partir da posição indicada
    for (int i = posicao + 1; i < *tamanhoDaLista + 1; i++) {
        novaListaSequencial[i].rg = ponteiroSequencial[i - 1].rg;
        novaListaSequencial[i].nome = ponteiroSequencial[i - 1].nome;
    }

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void delElementoInicio(int *tamanhoDaLista, Pessoa *&ponteiroSequencial) {
    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista - 1];

    //Atribuir os valores da antiga lista para a nova
    for (int i = 1; i < *tamanhoDaLista; i++) {
        novaListaSequencial[i - 1].rg = ponteiroSequencial[i].rg;
        novaListaSequencial[i - 1].nome = ponteiroSequencial[i].nome;
    }

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void delElementoFim(int *tamanhoDaLista, Pessoa *&ponteiroSequencial) {
    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista - 1];

    //Atribuir os valores da antiga lista para a nova
    for (int i = 0; i < *tamanhoDaLista - 1; i++) {
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
    }

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void delElementoPosicaoIndicada(int *tamanhoDaLista, Pessoa *&ponteiroSequencial, int posicao) {
    Pessoa *novaListaSequencial = new Pessoa[*tamanhoDaLista - 1];

    //Atribuir os valores da antiga lista para a nova
    for (int i = 0; i < *tamanhoDaLista - 1; i++) {

        //
        if (i < posicao) {
            //Se o elemento atual é menor que a posição indicada, atribui o valor normalmente
            novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
            novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
        } else {
            //Se o elemento atual é maior que a posição indicada, atribui o próximo valor da lista
            novaListaSequencial[i].rg = ponteiroSequencial[i + 1].rg;
            novaListaSequencial[i].nome = ponteiroSequencial[i + 1].nome;
        }
    }

    //Atualizar a lista principal
    ponteiroSequencial = novaListaSequencial;

    //Incrementar o tamanho da lista
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

string pesquisaNomeByRg(int tamanhoDaLista, Pessoa *&ponteiroSequencial, int rg) {
    string nome = "Não encontrado";

    for (int i = 0; i < tamanhoDaLista; i++) {
        if (rg == ponteiroSequencial[i].rg) {
            nome = ponteiroSequencial[i].nome;
            break;
        }
    }
    return nome;
}

int main() {
    int funcaoDesejada = 1;

    //Tamanho da lista
    int tamanhoDaLista = 0;

    //Lista sequencial inicial
    Pessoa *ponteiroSequencial;

    while (funcaoDesejada > 0 && funcaoDesejada < 9) {
        cout << "OPERACOES" << "\n";
        cout << "1 - Inserir uma pessoa no inicio da lista." << "\n";
        cout << "2 - Inserir uma pessoa no fim da lista." << "\n";
        cout << "3 - Inserir uma pessoa na posição indicada da lista." << "\n";
        cout << "4 - Retirar uma pessoa do inicio da lista." << "\n";
        cout << "5 - Retirar uma pessoa no fim da lista." << "\n";
        cout << "6 - Retirar uma pessoa na posição indicada da lista." << "\n";
        cout << "7 - Procurar o nome atraves do RG." << "\n";
        cout << "8 - Imprimir a lista." << "\n";
        cout << "9 - Sair do sistema." << "\n";
        cout << "\n" << "Escolha um numero e pressione ENTER: ";
        cin >> funcaoDesejada;

        limparTela();

        int rg;
        string nome;

        switch (funcaoDesejada) {
            case 1:
                cout << "Inserir uma pessoa no inicio da lista" << "\n";

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "\n";

                addElementoInicio(&tamanhoDaLista, rg, nome, ponteiroSequencial);

                break;
            case 2:
                cout << "Inserir uma pessoa no fim da lista" << "\n";

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "\n";

                addElementoFim(&tamanhoDaLista, rg, nome, ponteiroSequencial);

                break;
            case 3:
                cout << "Inserir uma pessoa na posição indicada da lista" << "\n";

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                int posicao;
                cout << "Digite a posição onde a pessoa será adicionada: ";
                cin >> posicao;

                cout << "\n";

                //Se a posição indicada for maior do que a lista, insere no fim da lista.
                if (posicao >= tamanhoDaLista) {
                    addElementoFim(&tamanhoDaLista, rg, nome, ponteiroSequencial);
                } else {
                    addElementoPosicaoIndicada(&tamanhoDaLista, rg, nome, ponteiroSequencial, posicao);
                }

                break;
            case 4:
                //cout << "Retirar uma pessoa do inicio da lista" << "\n";

                if (tamanhoDaLista > 0) {
                    delElementoInicio(&tamanhoDaLista, ponteiroSequencial);
                } else {
                    cout << "Lista vazia!" << "\n";
                }

                break;
            case 5:
                //cout << "Retirar uma pessoa no fim da lista" << "\n";

                if (tamanhoDaLista > 0) {
                    delElementoFim(&tamanhoDaLista, ponteiroSequencial);
                } else {
                    cout << "Lista vazia!" << "\n";
                }

                break;
            case 6:
                cout << "Retirar uma pessoa na posição indicada da lista" << "\n";

                if (tamanhoDaLista > 0) {
                    int posicao;
                    cout << "Digite a posição da pessoa que será removida da lista: ";
                    cin >> posicao;

                    cout << "\n";

                    delElementoPosicaoIndicada(&tamanhoDaLista, ponteiroSequencial, posicao);
                } else {
                    cout << "Lista vazia!" << "\n";
                }

                break;
            case 7:
                cout << "Procurar o nome atraves do RG" << "\n";

                if (tamanhoDaLista > 0) {
                    cout << "Digite o RG que deseja pesquisar: ";
                    cin >> rg;

                    cout << "\n";

                    string nome = pesquisaNomeByRg(tamanhoDaLista, ponteiroSequencial, rg);

                    if (nome == "Não encontrado") {
                        cout << "Pessoa não encontrada." << "\n";
                    } else {
                        cout << "O RG " << rg << " pertence à: " << nome << "\n";
                    }
                } else {
                    cout << "Lista vazia!" << "\n";
                }

                break;
            case 8:
                //cout << "Funcao escolhida: 8" << "\n";

                imprimirLista(ponteiroSequencial, tamanhoDaLista);

                break;
            case 9:
                cout << "Sair do sistema" << "\n";
                break;
        }
    }

    return 0;
}
