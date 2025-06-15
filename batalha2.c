#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para verificar se há sobreposição
int temSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return tabuleiro[linha][coluna] != AGUA;
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa tudo com 0 (água)
    int i;

    // ---------------------------
    // Navio 1 - Horizontal (linha 1, colunas 2 a 4)
    int linha1 = 1;
    int col1 = 2;

    if (col1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (temSobreposicao(tabuleiro, linha1, col1 + i)) {
                printf("Erro: sobreposição detectada no navio 1.\n");
                return 1;
            }
            tabuleiro[linha1][col1 + i] = NAVIO;
        }
    } else {
        printf("Erro: navio 1 fora dos limites.\n");
        return 1;
    }

    // ---------------------------
    // Navio 2 - Vertical (coluna 6, linhas 3 a 5)
    int linha2 = 3;
    int col2 = 6;

    if (linha2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (temSobreposicao(tabuleiro, linha2 + i, col2)) {
                printf("Erro: sobreposição detectada no navio 2.\n");
                return 1;
            }
            tabuleiro[linha2 + i][col2] = NAVIO;
        }
    } else {
        printf("Erro: navio 2 fora dos limites.\n");
        return 1;
    }

    // ---------------------------
    // Navio 3 - Diagonal principal (↘) - linhas e colunas: 0,1,2
    int linha3 = 0;
    int col3 = 0;

    if (linha3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && col3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (temSobreposicao(tabuleiro, linha3 + i, col3 + i)) {
                printf("Erro: sobreposição detectada no navio 3.\n");
                return 1;
            }
            tabuleiro[linha3 + i][col3 + i] = NAVIO;
        }
    } else {
        printf("Erro: navio 3 fora dos limites.\n");
        return 1;
    }

    // ---------------------------
    // Navio 4 - Diagonal secundária (↙) - linhas: 4,5,6 colunas: 9,8,7
    int linha4 = 4;
    int col4 = 9;

    if (linha4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && col4 - (TAMANHO_NAVIO - 1) >= 0) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (temSobreposicao(tabuleiro, linha4 + i, col4 - i)) {
                printf("Erro: sobreposição detectada no navio 4.\n");
                return 1;
            }
            tabuleiro[linha4 + i][col4 - i] = NAVIO;
        }
    } else {
        printf("Erro: navio 4 fora dos limites.\n");
        return 1;
    }

    // ---------------------------
    // Exibir o tabuleiro
    printf("\nTabuleiro 10x10 - 0 = Água, 3 = Navio\n\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
