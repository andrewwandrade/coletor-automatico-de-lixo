#include "gc.h"

//Atenção, siga o passo a passo: 
//1 - Abra um terminal no mesmo diretório dos arquivos e insira os códigos abaixo para compilação manual
//2 - Compile o arquivo com o comando: gcc main.c gc.c -o agoravai
//3 - Execute o programa com o comando: ./agoravai

int main() {
    // Alocando e inicializando inteiros
    int *x = malloc2(sizeof(int));
    *x = 5;

    int *y = malloc2(sizeof(int));
    *y = 10;

    dump();  // Mostra o estado atual das referências

    // Atribuindo valores
    atrib2(x, y);
    dump();  // Mostra o estado após a atribuição

    // Alocando um novo inteiro e alterando seu valor
    int *z = malloc2(sizeof(int));
    *z = 15;
    dump();  // Mostra após a nova alocação e inicialização

    // Testando a atribuição para NULL
    atrib2(y, NULL);
    dump();  // Mostra após a atribuição de NULL

    // Finalizando a alocação de memória
    atrib2(z, NULL);
    dump();  // Mostra após liberar o ponteiro z

    return 0;
}
