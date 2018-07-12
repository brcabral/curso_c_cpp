#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

void limparTela() {
    system("clear");
}

void criarTabuleiro(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    for (int linha = 0; linha < 3; linha++) {
        for (int coluna = 0; coluna < 3; coluna++) {
            cout << " " << tabuleiro[linha][coluna];
        }
        cout << "\n";
    }
}

int verificarVencedor (char tabuleiro[3][3]) {
    //Verificar linhas
    for (int linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
            return 1;
        } else if (tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
            return 2;
        }
    }

    //Verificar colunas
    for (int coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == 'X' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
            return 1;
        } else if (tabuleiro[0][coluna] == 'O' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
            return 2;
        }
    }

    //Verificar a diagonal principal
    if (tabuleiro[1][1] == 'X' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    } else if (tabuleiro[1][1] == 'O' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 2;
    }

    //Verificar a diagonal invertida
    if (tabuleiro[1][1] == 'X' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return true;
    } else if (tabuleiro[1][1] == 'O' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return true;
    }

    return 0;
}

void exibirInstrucoes() {
    cout << "\n" << "Mapa das posições" << "\n";
    cout << "7 | 8 | 9" << "\n";
    cout << "4 | 5 | 6" << "\n";
    cout << "1 | 2 | 3" << "\n";
}

void jogar(string nomeJogadorUm, string nomeJogadorDois, int pontosJogadorUm, int pontosJogadorDois) {
    char tabuleiro[3][3];
    int linhaJogada, colunaJogada, posicaoJogada;
    int turnoJogador = 1;     //1 = X; 2 = O
    int rodada = 0;
    bool fimJogo = false;
    bool posicionouJogada;     //Verificar se o jogador posicionou um marcador no tabuleiro
    string mensagem, jogadorAtual;

    criarTabuleiro(tabuleiro);

    while ((rodada < 9) && !fimJogo) {
        limparTela();
        exibirTabuleiro(tabuleiro);

        //Exibir o mapa do tabuleiro (qual número corresponde a qual posição)
        exibirInstrucoes();

        cout << "\n" << "Rodada: " << rodada << "\n";

        if (turnoJogador == 1) {
            jogadorAtual = nomeJogadorUm;
        } else {
            jogadorAtual = nomeJogadorDois;
        }

        posicionouJogada = false;
        int posicoesMapeada[9][2] = { {2,0}, {2,1}, {2,2}, {1,0}, {1,1}, {1,2}, {0,0}, {0,1}, {0,2} };

        while (!posicionouJogada) {
            posicaoJogada = 0;

            while (posicaoJogada < 1 || posicaoJogada > 9) {
                cout << jogadorAtual << " digite uma posição (conforme o mapa): ";
                cin >> posicaoJogada;
            }

            linhaJogada = posicoesMapeada[posicaoJogada - 1][0];
            colunaJogada = posicoesMapeada[posicaoJogada - 1][1];

            if (tabuleiro[linhaJogada][colunaJogada] == '-') {
                posicionouJogada = true;
                //Verificar o turno e posiciona o simbolo conforme posição indicada
                //Alternar o turno dos jogadores
                if (turnoJogador == 1) {
                    tabuleiro[linhaJogada][colunaJogada] = 'X';
                    turnoJogador = 2;
                } else {
                    tabuleiro[linhaJogada][colunaJogada] = 'O';
                    turnoJogador = 1;
                }
            }
        }

        //Verificar se algum jogador ganhou
        if (verificarVencedor(tabuleiro) == 1) {
            mensagem = nomeJogadorUm + " venceu!";
            pontosJogadorUm++;
            fimJogo = true;
        } else if (verificarVencedor(tabuleiro) == 2) {
            mensagem = nomeJogadorDois + " venceu!";
            pontosJogadorDois++;
            fimJogo = true;
        }

        verificarVencedor(tabuleiro);
        rodada++;
    }

    limparTela();
    exibirTabuleiro(tabuleiro);
    cout << "\n" << mensagem << "\n";
    cout << nomeJogadorUm << " " << pontosJogadorUm << " x " << pontosJogadorDois << " " << nomeJogadorDois << "\n";


    int opcaoDesejada;
    cout << "\n" << "Fim do jogo!!" << "\n";
    cout << "Deseja jogar novamente?" << "\n";
    cout << "1 - Sim" << "\n";
    cout << "2 - Não" << "\n";
    cin >> opcaoDesejada;

    if (opcaoDesejada == 1) {
        jogar(nomeJogadorUm, nomeJogadorDois, pontosJogadorUm, pontosJogadorDois);
    }
}

void menuInicial() {
    int opcaoDesejada = 0;
    string nomeJogadorUm, nomeJogadorDois;

    while (opcaoDesejada < 1 || opcaoDesejada > 3) {
        limparTela();

        cout << "Bem vindo ao jogo da Velha" << "\n";
        cout << "1 - Jogar" << "\n";
        cout << "2 - Sobre" << "\n";
        cout << "3 - Sair" << "\n";
        cout << "\n" << "Escolha uma opção e pressione ENTER: ";
        cin >> opcaoDesejada;

        switch (opcaoDesejada) {
            case 1:
                cout << "Digite o nome do jogador 1: ";
                cin >> nomeJogadorUm;

                cout << "Digite o nome do jogador 2: ";
                cin >> nomeJogadorDois;

                jogar(nomeJogadorUm, nomeJogadorDois, 0, 0);
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
