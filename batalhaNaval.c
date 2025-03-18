#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0

// inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// verificar se a posição está disponível
int podeColocarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
        int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));

        if (x >= TAMANHO || y >= TAMANHO || tabuleiro[x][y] != AGUA) {
            return 0; 
    }
    return 1; 
}

// posicionar um navio
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int diagonal) {
    int linha, coluna, direcao;
    int posicionado = 0;

    while (!posicionado) {
        linha = rand() % TAMANHO;
        coluna = rand() % TAMANHO;
        direcao = rand() % 2; // 0 = horizontal, 1 = vertical
        
        if (podeColocarNavio(tabuleiro, linha, coluna, direcao, diagonal)) {
            for (int i = 0; i < NAVIO; i++) {
                int x = linha + (diagonal ? i : (direcao == 1 ? i : 0));
                int y = coluna + (diagonal ? i : (direcao == 0 ? i : 0));
                tabuleiro[x][y] = NAVIO;
            }
            posicionado = 1;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    srand(time(NULL));
    
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona dois navios horizontais/verticais
    posicionarNavio(tabuleiro, 0);
    posicionarNavio(tabuleiro, 0);
    
    // Posiciona dois navios diagonais
    posicionarNavio(tabuleiro, 1);
    posicionarNavio(tabuleiro, 1);
    
    exibirTabuleiro(tabuleiro);
    
    return 0;