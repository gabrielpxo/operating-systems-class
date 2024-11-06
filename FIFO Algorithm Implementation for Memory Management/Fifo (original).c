#include <stdio.h>
#include <stdlib.h>

// Função para implementar o algoritmo FIFO
void FIFO(int pages[], int n, int capacidade) {
    int *quadros = (int *)malloc(capacidade * sizeof(int));
    int indice = 0, faltasDePagina = 0;

    // Inicialização dos quadros com -1 (indicando que estão vazios)
    for (int i = 0; i < capacidade; i++) {
        quadros[i] = -1;
    }

    printf("Sequência de referências \t Quadros\n");
    for (int i = 0; i < n; i++) {
        int pagina = pages[i];
        int encontrada = 0;

        // Verifica se a página já está carregada em um dos quadros
        for (int j = 0; j < capacidade; j++) {
            if (quadros[j] == pagina) {
                encontrada = 1;
                break;
            }
        }

        // Página não encontrada nos quadros (caso de falta de página)
        if (!encontrada) {
            quadros[indice] = pagina;
            indice = (indice + 1) % capacidade; // Atualiza o índice ciclicamente
            faltasDePagina++;

            // Exibe o estado atual dos quadros
            printf("\t%d\t\t", pagina);
            for (int j = 0; j < capacidade; j++) {
                if (quadros[j] != -1)
                    printf("%d ", quadros[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("\nTotal de faltas de página: %d\n", faltasDePagina);
    free(quadros);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3}; // Sequência de páginas referenciadas
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacidade = 3; // Capacidade dos quadros

    FIFO(pages, n, capacidade);

    return 0;
}
