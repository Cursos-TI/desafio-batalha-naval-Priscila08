#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Matriz do tabuleiro: inicializa com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas de início para cada navio (definidas diretamente no código)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    int i;

    // Posicionar o navio horizontal (verifica limites)
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica sobreposição
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != AGUA) {
                printf("Erro: Sobreposição detectada no navio horizontal.\n");
                return 1;
            }
            tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Posicionar o navio vertical (verifica limites)
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica sobreposição
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != AGUA) {
                printf("Erro: Sobreposição detectada no navio vertical.\n");
                return 1;
            }
            tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = NAVIO;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Exibir o tabuleiro
    printf("\nTabuleiro (0 = Água, 3 = Navio):\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
