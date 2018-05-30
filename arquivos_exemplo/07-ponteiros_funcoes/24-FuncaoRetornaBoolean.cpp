#include <stdio.h>
#include <stdbool.h>

//Função que retorno um boolean
bool retornaBoolean() {
 return true;
}

int main() {

    bool a;

    a = retornaBoolean();

    if (a) {
        printf("É verdadeiro!!");
    } else {
        printf("É falso!!");
    }

    getchar();
    return 0;
}
