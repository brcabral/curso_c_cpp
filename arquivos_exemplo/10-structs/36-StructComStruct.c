#include <stdio.h>

//typedef cria "um alias" para o struct. O alias é determinado após fechamento das chaves
typedef struct Data {
    int dia;
    int mes;
    int ano;
}Data;

struct Aluno {
    int id;
    Data nascimento;
};

int main() {

    //Criar um struct do tipo palavra
    struct Aluno aluno;

    //Modificando os campos do struct
    aluno.id = 1;
    aluno.nascimento.ano = 2018;
    aluno.nascimento.mes = 05;
    aluno.nascimento.dia = 29;

    //Imprimir os valores do struct
    printf("Nascido em: %d/%d/%d", aluno.nascimento.dia, aluno.nascimento.mes, aluno.nascimento.ano);

    getchar();
    return 0;
}
