#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>

using namespace std;

void limparTela() {
    system("clear");
}

string selecionaPalavra() {
    //Palavras disponíveis para o jogo
    string palavras[5] = {"abacaxi", "banana", "laranja", "manga", "morango"};

    //Função para gerar números aleatórios
    srand((unsigned)time(NULL));

    //Valor aleatório gerado entre 0 e 4
    int indiceAleatorio = rand() % 5;

    //cout << "Palavra selecionada: " << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];
}

string criarMascaraPalavra(int tamanhoPalavra) {
    string mascaraPalavra;

    for (int i = 0; i < tamanhoPalavra; i++) {
        mascaraPalavra += "_";
        //mascaraPalavra += "_ ";
    }

    return mascaraPalavra;
}

void exibeStatus(string mascaraParaPalavra, int tamanhoPalavra, int tentativasRestantes, string letrasTentadas, string mensagem) {
    if (mensagem != "") {
        cout << mensagem << "\n";
    }
    cout << "Palavra: " << mascaraParaPalavra << ". Tamanho da palavra: " << tamanhoPalavra << " letras." << "\n";
    cout << "Tentativas restantes: " << tentativasRestantes << "\n";
    cout << "Letras tentadas: " << letrasTentadas << "\n";
}

int jogar(int qtdJogadores) {
    string palavra, palavraDigitada;

    //Se for apenas 1 jogador retornar palavras pre definidas
    //Se for dois jogadores, um jogador irá digitar a palavra
    if (qtdJogadores == 1) {
        palavra = selecionaPalavra();
    } else {
        cout << "Digite uma palavra: ";
        cin >> palavraDigitada;

        for (int i = 0; i < palavraDigitada.size(); i++) {
            palavra += tolower(palavraDigitada[i]);
        }
    }

    int tamanhoPalavra = palavra.size();
    int tentativas = 0;
    int maximoTentativas = 7;
    int opcaoDesejada;
    char letra;
    string letrasTentadas, mensagem;
    string mascaraParaPalavra = criarMascaraPalavra(tamanhoPalavra);
    bool letraJaDigitada = false;

    while (((maximoTentativas - tentativas) > 0) && (palavra != mascaraParaPalavra)) {
        limparTela();
        exibeStatus(mascaraParaPalavra, tamanhoPalavra, (maximoTentativas - tentativas), letrasTentadas, mensagem);
        mensagem = "";

        cout << "Digite uma letra: ";
        cin >> letra;

        for (int i = 0; i < letrasTentadas.size(); i++) {
            if (letrasTentadas[i] == tolower(letra)) {
                mensagem = "Letra já digitada.";
                letraJaDigitada = true;
            }
        }

        if (letraJaDigitada == false) {
            letra = tolower(letra);
            letrasTentadas = letrasTentadas + letra + ", ";

            //Verifica se a letra digitada contém na palavra selecionada.
            for (int i = 0; i < tamanhoPalavra; i++) {
                if (palavra[i] == tolower(letra)) {
                    mascaraParaPalavra[i] = tolower(letra);
                }
            }
            tentativas++;
        }

        letraJaDigitada = false;
    }

    limparTela();

    if (palavra == mascaraParaPalavra) {
        cout << "Parabéns!! Você venceu." << "\n";
    } else {
        cout << "Você perdeu." << "\n";
    }

    cout << "Deseja reiniciar o jogo?" << "\n";
    cout << "1 - Sim" << "\n";
    cout << "2 - Não" << "\n";
    cin >> opcaoDesejada;
    return opcaoDesejada;
}

void menuInicial() {
    int opcaoDesejada = 0;

    while (opcaoDesejada < 1 || opcaoDesejada > 4) {
        limparTela();

        cout << "Bem vindo ao jogo da Forca" << "\n";
        cout << "1 - Jogar" << "\n";
        cout << "2 - Jogar em dupla" << "\n";
        cout << "3 - Sobre" << "\n";
        cout << "4 - Sair" << "\n";
        cout << "\n" << "Escolha uma opção e pressione ENTER: ";
        cin >> opcaoDesejada;

        switch (opcaoDesejada) {
            case 1:
                cout << "Jogar" << "\n";

                if (jogar(1) == 1) {
                    menuInicial();
                }

                break;
            case 2:
                cout << "Jogar em dupla" << "\n";

                if (jogar(2) == 1) {
                    menuInicial();
                }

                break;
            case 3:
                cout << "Sobre" << "\n";
                limparTela();

                cout << "Jogo desenvolvido por Breno em julho de 2018" << "\n";
                cout << "1 - Voltar" << "\n";
                cout << "2 - Sair" << "\n";
                cin >> opcaoDesejada;

                if (opcaoDesejada == 1) {
                    menuInicial();
                }

                break;
            case 4:
                cout << "Até mais" << "\n";
                break;
        }
    }
}

int main() {
    menuInicial();

    return 0;
}
