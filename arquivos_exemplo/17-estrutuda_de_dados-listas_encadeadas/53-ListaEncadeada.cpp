#include <stdlib.h>
#include <new>
#include <string>
#include <iostream>

using namespace std;

struct Pessoa {
    int rg;
    string nome;
    struct Pessoa *proximo;
};

void limparTela() {
    system("clear");
}

int retornaTamanhoLista(Pessoa *ponteiroEncadeado) {
    int tamanho = 0;
    Pessoa *p = ponteiroEncadeado;


    if (p->nome != "") {
        while (p != NULL) {
            //O cursor recebe a posição de memória do próximo valor
            p = p->proximo;
            tamanho ++;
        }
    }
    return tamanho;
}

void imprimirLista(Pessoa *ponteiroEncadeado) {
    Pessoa *p = ponteiroEncadeado;

    if (retornaTamanhoLista(p)) {
        while (p != NULL) {
            cout << "RG: " << p->rg << ", nome: " << p->nome << "\n";

            //O cursor recebe a posição de memória do próximo valor
            p = p->proximo;
        }
    } else {
        cout << "Lista vazia!" << "\n";
    }
    cout << "\n";
}

void addElementoInicio(int rg, string nome, Pessoa *&ponteiroEncadeado) {
    //Criar uma nova estrutura de Pessoa
    Pessoa *novaListaEncadeada = new Pessoa;
    novaListaEncadeada->rg = rg;
    novaListaEncadeada->nome = nome;

    //Verifica se a lista está vazia
    if (ponteiroEncadeado-> nome == "") {
        novaListaEncadeada->proximo = NULL;
    } else {
        novaListaEncadeada->proximo = ponteiroEncadeado;
    }

    //Atribuir o novo ponteiro para a lista encadeada
    ponteiroEncadeado = novaListaEncadeada;
}

void addElementoFim(int rg, string nome, Pessoa *&ponteiroEncadeado) {
    //Criar uma nova estrutura de Pessoa
    Pessoa *novaListaEncadeada = new Pessoa;
    novaListaEncadeada->rg = rg;
    novaListaEncadeada->nome = nome;
    novaListaEncadeada->proximo = NULL;

    if (retornaTamanhoLista(ponteiroEncadeado) == 0) {
        ponteiroEncadeado = novaListaEncadeada;
    } else {
        Pessoa *p = ponteiroEncadeado;

        while (p != NULL) {
            if (p->proximo == NULL) {
                p->proximo = novaListaEncadeada;
                return;
            }
            p = p->proximo;
        }
    }
}

void addElementoPosicaoIndicada(int rg, string nome, Pessoa *&ponteiroEncadeado, int posicao) {
    //Criar uma nova estrutura de Pessoa
    Pessoa *novaListaEncadeada = new Pessoa;
    novaListaEncadeada->rg = rg;
    novaListaEncadeada->nome = nome;
    novaListaEncadeada->proximo = NULL;

    int i = 0;
    Pessoa *p = ponteiroEncadeado;

    while (i <= posicao) {
        if (i == (posicao - 1)) {
            Pessoa *pessoaAux = new Pessoa;

            //Armazena o próximo valor
            pessoaAux->proximo = p->proximo;

            //Atribui o novo valor como próximo elemento da lista
            p->proximo = novaListaEncadeada;

            //O novo valor recebe o próximo valor, que estava armazenado na variável pessoaAux.
            novaListaEncadeada->proximo = pessoaAux->proximo;

            free(pessoaAux);
        }
        p = p->proximo;
        i++;
    }
}

void delElementoInicio(Pessoa *&ponteiroEncadeado) {
    if (ponteiroEncadeado->proximo == NULL) {
        Pessoa *novaListaEncadeada = new Pessoa;
        novaListaEncadeada->rg = 0;
        novaListaEncadeada->nome = "";
        novaListaEncadeada->proximo = NULL;

        ponteiroEncadeado = novaListaEncadeada;
    } else {
        //O ponteiro principal irá apontar para o próximo valor
        ponteiroEncadeado = ponteiroEncadeado->proximo;
    }
}

//  >>>> Melhorar o código do delElementoFim <<<<
void delElementoFim(Pessoa *&ponteiroEncadeado) {
    Pessoa *p = ponteiroEncadeado;
    Pessoa *pessoaAux = new Pessoa;

    while (p->proximo != NULL) {
        pessoaAux = p;
        p = p->proximo;
    }

    //Faz com que o penúltimo elemento da lista passe a ser o último
    pessoaAux->proximo = NULL;
}

void delElementoPosicaoIndicada(Pessoa *&ponteiroEncadeado, int posicao) {
    int i = 0;
    Pessoa *p = ponteiroEncadeado;

    while (i <= posicao) {
        if (i == (posicao - 1)) {
            Pessoa *pessoaAux = new Pessoa;

            //Armazena o próximo valor
            pessoaAux = p->proximo;

            //Atribui o novo valor como próximo elemento da lista
            p->proximo = pessoaAux->proximo;

            //O novo valor recebe o próximo valor, que estava armazenado na variável pessoaAux.
            //novaListaEncadeada->proximo = pessoaAux->proximo;

            free(pessoaAux);
        }
        p = p->proximo;
        i++;
    }
}

string pesquisaNomeByRg(Pessoa *&ponteiroEncadeado, int rg) {
    Pessoa *p = ponteiroEncadeado;
    string nome = "Não encontrado";

    while (p != NULL) {
        if (rg == p->rg) {
            nome = p->nome;
            break;
        }
        p = p->proximo;
    }
    return nome;
}

int main() {
    int funcaoDesejada = 1;

    //Criar uma nova lista encadeada
    Pessoa *ponteiroEncadeado = new Pessoa;
    ponteiroEncadeado->rg = 0;
    ponteiroEncadeado->nome = "";
    ponteiroEncadeado->proximo = NULL;


    //Criar uma nova estrutura de Pessoa para a primeira posição
    Pessoa *primeiraPessoa = new Pessoa;
    primeiraPessoa->rg = 1002;
    primeiraPessoa->nome = "Uni";
    primeiraPessoa->proximo = NULL;

    //Atribuir o ponteiro da primeiraPessoa para a lista encadeada (ponteiroEncadeado)
    ponteiroEncadeado = primeiraPessoa;

    //Criar uma nova estrutura de Pessoa para a segunda posição
    Pessoa *segundaPessoa = new Pessoa;
    segundaPessoa->rg = 110;
    segundaPessoa->nome = "Gracinha";
    segundaPessoa->proximo = NULL;

    //Indicar que o elemento seguinte da primeiraPessoa é a segundaPessoa
    primeiraPessoa->proximo = segundaPessoa;

    Pessoa *terceiraPessoa = new Pessoa;
    terceiraPessoa->rg = 406;
    terceiraPessoa->nome = "Breno";
    terceiraPessoa->proximo = NULL;

    segundaPessoa->proximo = terceiraPessoa;


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

        int rg, posicao;
        string nome;

        switch (funcaoDesejada) {
            case 1:
                cout << "Inserir uma pessoa no inicio da lista" << "\n";

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "\n";

                addElementoInicio(rg, nome, ponteiroEncadeado);

                break;
            case 2:
                cout << "Inserir uma pessoa no fim da lista" << "\n";

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "\n";

                addElementoFim(rg, nome, ponteiroEncadeado);

                break;
            case 3:
                cout << "Inserir uma pessoa na posição indicada da lista" << "\n";

                cout << "Digite a posição onde a pessoa será adicionada: ";
                cin >> posicao;

                cout << "Digite o RG: ";
                cin >> rg;

                cout << "Digite o nome: ";
                cin >> nome;

                cout << "\n";

                if (posicao == 0) {
                    addElementoInicio(rg, nome, ponteiroEncadeado);
                } else if (posicao >= retornaTamanhoLista(ponteiroEncadeado)) {
                    addElementoFim(rg, nome, ponteiroEncadeado);
                } else {
                    addElementoPosicaoIndicada(rg, nome, ponteiroEncadeado, posicao);
                }

                break;
            case 4:
                //cout << "Retirar uma pessoa do inicio da lista" << "\n";

                delElementoInicio(ponteiroEncadeado);

                break;
            case 5:
                //cout << "Retirar uma pessoa no fim da lista" << "\n";
                if (retornaTamanhoLista(ponteiroEncadeado) == 1) {
                    delElementoInicio(ponteiroEncadeado);
                } else {
                    //  >>>> Melhorar o código do delElementoFim <<<<
                    delElementoFim(ponteiroEncadeado);
                }

                break;
            case 6:
                cout << "Retirar uma pessoa na posição indicada da lista" << "\n";

                cout << "Digite a posição da pessoa que será removida da lista: ";
                cin >> posicao;

                if (posicao == 0) {
                    delElementoInicio(ponteiroEncadeado);
                } else if (posicao >= retornaTamanhoLista(ponteiroEncadeado - 1)) {
                    delElementoFim(ponteiroEncadeado);
                } else {
                    delElementoPosicaoIndicada(ponteiroEncadeado, posicao);
                }

                cout << "\n";

                break;
            case 7:
                cout << "Procurar o nome atraves do RG" << "\n";

                if (retornaTamanhoLista(ponteiroEncadeado) > 0) {
                    cout << "Digite o RG que deseja pesquisar: ";
                    cin >> rg;

                    cout << "\n";

                    string nome = pesquisaNomeByRg(ponteiroEncadeado, rg);

                    if (nome == "Não encontrado") {
                        cout << "Pessoa não encontrada." << "\n";
                    } else {
                        cout << "O RG " << rg << " pertence à: " << nome << "\n";
                    }
                } else {
                    cout << "Lista vazia!" << "\n";
                }

                cout << "\n";

                break;
            case 8:
                //cout << "Funcao escolhida: 8" << "\n";

                cout << "Tamanho atual da lista: " << retornaTamanhoLista(ponteiroEncadeado) << "\n\n";
                imprimirLista(ponteiroEncadeado);

                break;
            case 9:
                cout << "Sair do sistema" << "\n";
                break;
        }
    }

    return 0;
}
