#include "gc.h"

// Vetor dinâmico para armazenar as referências
Referencia *referencias = NULL;
int capacidade = 0;  
int tamanho = 0;   

// Função para aumentar a capacidade do vetor de referências
void expandir_vetor() {
    capacidade = capacidade == 0 ? 2 : capacidade * 2;  
    referencias = realloc(referencias, capacidade * sizeof(Referencia));
    if (!referencias) {
        fprintf(stderr, "Erro ao expandir o vetor de referencias\n");
        exit(1);
    }
}

// Função malloc2 que aloca memória e registra a contagem de referências
void* malloc2(int tamanho_memoria) {

    void *novo_endereco = malloc(tamanho_memoria);
    if (!novo_endereco) {
        fprintf(stderr, "Erro na alocacao de memoria\n");
        exit(1);
    }
    
    if (tamanho == capacidade) {
        expandir_vetor();
    }
    
    referencias[tamanho].endereco = novo_endereco;
    referencias[tamanho].contagem = 1; 
    tamanho++;
    
    return novo_endereco;
}

// Função atrib2 que realiza a atribuição de ponteiros e gerencia as contagens de referências
void atrib2(void *endereco, void *endereco2) {
    // Encontra o índice do bloco de memória associado a 'endereco'
    for (int i = 0; i < tamanho; i++) {
        if (referencias[i].endereco == endereco) {
            referencias[i].contagem--;
            if (referencias[i].contagem == 0) {
                free(referencias[i].endereco);
                referencias[i] = referencias[tamanho - 1];
                tamanho--;
            }
            break;
        }
    }

    // Se endereco2 não for NULL, incrementa a contagem de referência
    if (endereco2 != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (referencias[i].endereco == endereco2) {
                referencias[i].contagem++;
                break;
            }
        }
    }
}

// Função dump que imprime o estado atual das referências e coleta o lixo
void dump() {
    printf("Estado das referencias:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Endereco: %p, Contagem: %d\n", referencias[i].endereco, referencias[i].contagem);
    }
    
    // Coleta o lixo (libera a memória de blocos com contagem de referência 0)
    for (int i = 0; i < tamanho;) {
        if (referencias[i].contagem == 0) {
            free(referencias[i].endereco);
            referencias[i] = referencias[tamanho - 1];
            tamanho--;
        } else {
            i++;
        }
    }
}
