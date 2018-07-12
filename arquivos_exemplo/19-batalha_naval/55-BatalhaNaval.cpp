#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

#define TAM_TABULEIRO 10

using namespace std;

void limparTela() {
    system("clear");
}

void criarTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], char mascaraTabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 'A';
            mascaraTabuleiro[linha][coluna] = '*';
        }
    }
}

void exibirMapaColunas() {
    for(int i = 0; i < 10; i++){
        if(i == 0){
            cout << "     ";
        }
        cout << i << " ";
    }
    cout << "\n";

    for(int i = 0; i < 10; i++){
        if(i == 0){
            cout << "     ";
        }
        cout << "| ";
    }

    cout << "\n";
}

void exibirTabuleiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], char mascaraTabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], bool exibirGabarito) {

    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };

    //Mapa indicador das colunas
    exibirMapaColunas();
    for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
        cout << linha << " - ";
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {

            switch (mascaraTabuleiro[linha][coluna]) {
                case 'A':
                    cout << blue << " " << mascaraTabuleiro[linha][coluna];
                    break;
                case 'P':
                    cout << green << " " << mascaraTabuleiro[linha][coluna];
                    break;
                default:
                    cout << normal << " " << mascaraTabuleiro[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }

    if (exibirGabarito) {
        cout << "\n";
        for (int linha = 0; linha < TAM_TABULEIRO; linha++) {
            for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
                cout << " " << tabuleiro[linha][coluna];
            }
            cout << "\n";
        }
    }
}

void posicionarBarcos(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    //Função para gerar números aleatórios
    srand((unsigned)time(NULL));

    int qtdBarcos = 10;
    int qtdPosicionada = 0;

    while (qtdPosicionada < qtdBarcos) {
        //Gerar um número aleatório entre 0 e 10
        int linhaBarco = rand() % TAM_TABULEIRO;
        int colunaBarco = rand() % TAM_TABULEIRO;

        if (tabuleiro[linhaBarco][colunaBarco] == 'A') {
            //Posicionar barco
            tabuleiro[linhaBarco][colunaBarco] = 'P';

            //Incrimentar a quantidade de barcos posicionados
            qtdPosicionada++;
        }
    }
}

void verificarTiro(char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linhaJogada, int colunaJogada, int *pontos, string *mensagem) {
    switch (tabuleiro[linhaJogada][colunaJogada]) {
        case 'P':
            *pontos = *pontos + 10;
            *mensagem = "Você acertou um barco pequeno! (10 pts)";
            break;
        case 'A':
            *mensagem = "Você não acertou nenhum barco!";
            break;
    }
}

void jogar(string nomeJogador) {

    char tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    char mascaraTabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int linhaJogada, colunaJogada;
    int pontos = 0;
    int tentativas = 0;
    int maximoTentativas = 5;
    string mensagem = "Bem vindo ao jogo Batalha Naval";

    criarTabuleiro(tabuleiro, mascaraTabuleiro);
    posicionarBarcos(tabuleiro);

    while (tentativas < maximoTentativas) {

        limparTela();
        exibirTabuleiro(tabuleiro, mascaraTabuleiro, false);

        cout << "\n" << "Pontos: " << pontos << "\n";
        cout << "\n" << "Tentativas restantes: " << (maximoTentativas - tentativas) << "\n";
        cout << mensagem << "\n";

        //Verificar se o valor digitado para linha e coluna são válidos
        linhaJogada = -1;
        colunaJogada = -1;

        while ((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)) {
            cout << nomeJogador << " digite uma linha: ";
            cin >> linhaJogada;

            cout << nomeJogador << " digite uma coluna: ";
            cin >> colunaJogada;

            if ((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)) {
                cout << "O número da linha e/ou coluna inválido(s). Digite novamente!!"  << "\n";
            }
        }

        //Revelar o item do tabuleiro
        mascaraTabuleiro[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];

        //Verificar se o tiro acertou algum barco
        verificarTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);

        tentativas++;
    }
    limparTela();
    exibirTabuleiro(tabuleiro, mascaraTabuleiro, true);

    int opcaoDesejada;
    cout << "\n" << "Fim do jogo!!" << "\n";
    cout << "Deseja jogar novamente?" << "\n";
    cout << "1 - Sim" << "\n";
    cout << "2 - Não" << "\n";
    cin >> opcaoDesejada;

    if (opcaoDesejada == 1) {
        jogar(nomeJogador);
    }
}

void menuInicial() {
    int opcaoDesejada = 0;
    string nomeJogador;

    while (opcaoDesejada < 1 || opcaoDesejada > 3) {
        limparTela();

        cout << nomeJogador << " bem vindo ao jogo Batalha Naval" << "\n";
        cout << "1 - Jogar" << "\n";
        cout << "2 - Sobre" << "\n";
        cout << "3 - Sair" << "\n";
        cout << "\n" << "Escolha uma opção e pressione ENTER: ";
        cin >> opcaoDesejada;

        switch (opcaoDesejada) {
            case 1:
                cout << "Digite o nome do jogador: ";
                cin >> nomeJogador;

                jogar(nomeJogador);
                break;
            case 2:
                limparTela();

                cout << "Jogo desenvolvido por Breno em julho de 2018" << "\n";
                cout << "1 - Voltar" << "\n";
                cout << "2 - Sair" << "\n";
                cin >> opcaoDesejada;

                if (opcaoDesejada == 1) {
                    menuInicial();
                }

                break;
            case 3:
                cout << "Até mais" << "\n";
                break;
        }
    }
}

int main() {
    menuInicial();

    return 0;
}
