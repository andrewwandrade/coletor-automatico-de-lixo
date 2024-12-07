#ifndef GC_H
#define GC_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Referencia {
    void *endereco;
    int contagem;
} Referencia;

void* malloc2(int tamanho_memoria);
void atrib2(void *endereco, void *endereco2);
void dump();

#endif
