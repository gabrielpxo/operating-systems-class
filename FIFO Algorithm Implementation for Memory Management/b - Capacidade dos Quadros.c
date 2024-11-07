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
    
    printf("paginas: ");
    for(int k=0; k<n; k++){
    	printf("%d ", pages[k]);
	}
    printf("\nSequencia de referencias \t Quadros\n");
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
            printf("\t%d\t\t\t", pagina);
            for (int j = 0; j < capacidade; j++) {
                if (quadros[j] != -1)
                    printf("%d ", quadros[j]);
                else
                    printf("- ");
            }
            printf("\n");
        }
    }

    printf("\nTotal de faltas de pagina: %d\n", faltasDePagina);
    printf("------------------------------------\n\n");
    free(quadros);
}

int main() {
	
	int capacidade1 = 4; // Capacidade dos quadros
	int capacidade2 = 4;
	int capacidade3 = 5;
	int capacidade4 = 6;
	int capacidade5 = 2;
	int capacidade6 = 1;
	
	//teste 1
    int pages_um[] = {1, 2, 3, 4, 5, 6, 7}; // Todos os elementos são diferentes
    int n = sizeof(pages_um) / sizeof(pages_um[0]);
	printf("Teste 1:\n");
    FIFO(pages_um, n, capacidade1);
    
    //teste 2
	int pages_dois[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}; // Há o dobro de elementos e são todos diferentes
	int o = sizeof(pages_dois) / sizeof(pages_dois[0]);
	printf("Teste 2:\n");
	FIFO(pages_dois, o, capacidade2);
	
	//teste 3
	int pages_tres[] = {1, 1, 2, 3, 4, 5, 6}; // 2 elementos são iguais
	int p = sizeof(pages_tres) / sizeof(pages_tres[0]);
	printf("Teste 3:\n");
	FIFO(pages_tres, p, capacidade3);
	
	//teste 4
	int pages_quatro[] = {1, 1, 2, 3, 4, 1, 1}; // 4 elementos são iguais, mas são intercalados pela quantidade de quadros em elementos distintos
	int q = sizeof(pages_quatro) / sizeof(pages_quatro[0]);
	printf("Teste 4:\n");
	FIFO(pages_quatro, q, capacidade4);
	
	//teste 5
	int pages_cinco[] = {1, 1, 1, 1, 2, 3, 4}; // 4 elementos são iguais em sequência
	int r = sizeof(pages_cinco) / sizeof(pages_cinco[0]);
	printf("Teste 5:\n");
	FIFO(pages_cinco, r, capacidade5);
	
	//teste 6
	int pages_seis[] = {2, 3, 2, 4, 2, 5, 2}; // 4 elementos são iguais intercaladamente
	int s = sizeof(pages_seis) / sizeof(pages_seis[0]);
	printf("Teste 6:\n");
	FIFO(pages_seis, s, capacidade6);

    return 0;
}
