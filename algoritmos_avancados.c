#include <stdio.h>
#include <stdlib.h>
typedef struct Sala {
    char* nome;
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;
// criarSala() – cria, de forma dinâmica, uma sala com nome.
Sala* criarSala(char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    nova->nome = nome;
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}
// explorarSalas() – permite a navegação do jogador pela árvore.
void explorarSalas(Sala* atual) {
    printf("Você está em: %s\n", atual->nome);
    
    while (atual->esquerda != NULL || atual->direita != NULL) {
        printf("Escolha: e (esquerda), d (direita), s (sair): ");
        char escolha;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
            printf("Você está em: %s\n", atual->nome);
        } else {
            printf("Escolha inválida ou caminho não existe. Tente novamente.\n");
        }
    }
    
    printf("Exploração terminada.\n");
}
// main() – monta o mapa inicial e dá início à exploração.
int main() {
    Sala* hall = criarSala("Hall de entrada");
    hall->esquerda = criarSala("Sala de estar");
    hall->direita = criarSala("Jardim");
    
    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Banheiro");
    
    hall->direita->esquerda = criarSala("Garagem");
    hall->direita->direita = criarSala("Escritório");
    
    explorarSalas(hall);
    
    return 0;
}