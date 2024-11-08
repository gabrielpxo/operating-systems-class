#include <stdio.h>
#include <stdlib.h>

void FIFO_Bombado(int pages[], int n, int capacidade) {
    int *quadros = (int *)malloc(capacidade * sizeof(int));
    int *freq_uso = (int *)malloc(capacidade * sizeof(int));
    int faltasDePagina = 0;

    // InicializaÃ§Ã£o dos quadros e frequências
    for (int i = 0; i < capacidade; i++) {
        quadros[i] = -1;
        freq_uso[i] = 0;
    }

    printf("Paginas: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\nSequencia de Referencias\tQuadros\t\tFrequencia de Uso\n");

    // Cada página é um elemento do array pages
    // A var achou é setada como false (não encontrada)
    for (int i = 0; i < n; i++) {
        int pagina = pages[i];
        int achou = 0;

        // Verifica se a página foi encontrada
        for (int j = 0; j < capacidade; j++) {
            // Se a achou nos quadros, incrementa a contagem da frequência na mesma posição do quadro referenciado, dentro do seu próprio vetor
            if (quadros[j] == pagina) {
                achou = 1;
                freq_uso[j]++;
                break;
            }
        }

        // Se não achou, ocorre page miss
        if (!achou) {
            // A posição de troca é inicializada em 0, pelo padrão do algoritmo (first in, first out)
            int posicao_troca = 0;
            // Passa pelas outras posições além do 0 para verificar se alguma delas tem frequência menor que a dessa posição
            for (int j = 1; j < capacidade; j++) {
                if (freq_uso[j] < freq_uso[posicao_troca]) {
                   // Se há menor, atualiza a posição de troca
                    posicao_troca = j;
                }
            }

            // Substitui a página na posição de menor frequência de uso
            quadros[posicao_troca] = pagina;
            // Atualiza a frequência de uso da página substituída para 1, já que ela acabou de ser alocada
            freq_uso[posicao_troca] = 1;
            faltasDePagina++;
        }

        // Imprime o estado atual dos quadros e a frequência de uso
        printf("\t%d\t\t\t", pagina);
        for (int j = 0; j < capacidade; j++) {
            if (quadros[j] != -1)
                printf("%d ", quadros[j]);
            else
                printf("- ");
        }
        printf("\t\t");
        for (int j = 0; j < capacidade; j++) {
            if (quadros[j] != -1)
                printf("%d ", freq_uso[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal de faltas de pagina: %d\n", faltasDePagina);
    printf("------------------------------------\n\n");

    free(quadros);
    free(freq_uso);
}

int main() {
    int capacidade1 = 4; // Capacidade dos quadros
    int capacidade2 = 4;
    int capacidade3 = 5;
    int capacidade4 = 6;
    int capacidade5 = 2;
    int capacidade6 = 1;

    // Teste 1
    int pages_um[] = {1, 2, 3, 4, 5, 6, 7}; // Todos os elementos são diferentes
    int n = sizeof(pages_um) / sizeof(pages_um[0]);
    printf("Teste 1:\n");
    FIFO_Bombado(pages_um, n, capacidade1);

    // Teste 2
    int pages_dois[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // O dobro de elementos, todos diferentes
    int o = sizeof(pages_dois) / sizeof(pages_dois[0]);
    printf("Teste 2:\n");
    FIFO_Bombado(pages_dois, o, capacidade2);

    // Teste 3
    int pages_tres[] = {1, 1, 2, 3, 4, 5, 6}; // 2 elementos são iguais
    int p = sizeof(pages_tres) / sizeof(pages_tres[0]);
    printf("Teste 3:\n");
    FIFO_Bombado(pages_tres, p, capacidade3);

    // Teste 4
    int pages_quatro[] = {1, 1, 2, 3, 4, 1, 1}; // 4 elementos iguais intercalados
    int q = sizeof(pages_quatro) / sizeof(pages_quatro[0]);
    printf("Teste 4:\n");
    FIFO_Bombado(pages_quatro, q, capacidade4);

    // Teste 5
    int pages_cinco[] = {1, 1, 1, 1, 2, 3, 4}; // 4 elementos iguais em sequência
    int r = sizeof(pages_cinco) / sizeof(pages_cinco[0]);
    printf("Teste 5:\n");
    FIFO_Bombado(pages_cinco, r, capacidade5);

    // Teste 6
    int pages_seis[] = {2, 3, 2, 4, 2, 5, 2}; // 4 elementos iguais intercaladamente
    int s = sizeof(pages_seis) / sizeof(pages_seis[0]);
    printf("Teste 6:\n");
    FIFO_Bombado(pages_seis, s, capacidade6);

    return 0;
}
