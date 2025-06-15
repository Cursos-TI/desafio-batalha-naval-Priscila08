#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para exibir o tabuleiro com legenda
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para aplicar matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                // Calcula posição no tabuleiro
                int linhaTab = origemLinha - TAM_HAB / 2 + i;
                int colTab = origemColuna - TAM_HAB / 2 + j;

                // Verifica limites
                if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM) {
                    // Marca posição como área de habilidade
                    if (tabuleiro[linhaTab][colTab] != NAVIO) {
                        tabuleiro[linhaTab][colTab] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Gera matriz Cone (triângulo para baixo)
void gerarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
            if (i >= j - TAM_HAB / 2 && i >= TAM_HAB / 2 - j) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Gera matriz Cruz
void gerarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Gera matriz Octaedro (losango)
void gerarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                matriz[i][j] = 1;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // --- Posiciona Navios (como no nível anterior) ---

    // Navio horizontal
    for (int i = 0; i < 3; i++) tabuleiro[2][i + 2] = NAVIO;

    // Navio vertical
    for (int i = 0; i < 3; i++) tabuleiro[i + 4][5] = NAVIO;

    // Navio diagonal ↘
    for (int i = 0; i < 3; i++) tabuleiro[i + 1][i + 1] = NAVIO;

    // Navio diagonal ↙
    for (int i = 0; i < 3; i++) tabuleiro[i + 5][8 - i] = NAVIO;

    // --- Habilidade: Cone ---
    int cone[TAM_HAB][TAM_HAB];
    gerarMatrizCone(cone);
    aplicarHabilidade(tabuleiro, cone, 6, 2); // origem no centro da habilidade

    // --- Habilidade: Cruz ---
    int cruz[TAM_HAB][TAM_HAB];
    gerarMatrizCruz(cruz);
    aplicarHabilidade(tabuleiro, cruz, 4, 7);

    // --- Habilidade: Octaedro ---
    int octaedro[TAM_HAB][TAM_HAB];
    gerarMatrizOctaedro(octaedro);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // --- Exibe o tabuleiro final ---
    exibirTabuleiro(tabuleiro);

    return 0;
}
