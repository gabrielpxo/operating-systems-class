//Testar o algoritmo com diferentes sequências de testes e, de diferentes tamanhos e analisar os resultados

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
	
	int capacidade = 3; // Capacidade dos quadros
	
	//teste 1
    int pages_um[] = {1, 3, 0, 3, 5, 6, 3}; // Sequência de páginas referenciadas
    int n = sizeof(pages_um) / sizeof(pages_um[0]);
    FIFO(pages_um, n, capacidade);
    
    //teste 2
	int pages_dois[] = {2, 5, 1, 4, 3, 2, 6}; // Sequência de páginas referenciadas
	int o = sizeof(pages_dois) / sizeof(pages_dois[0]);
	FIFO(pages_dois, o, capacidade);
	
	//teste 3
	int pages_tres[] = {1, 3, 5}; // Sequência de páginas referenciadas
	int p = sizeof(pages_tres) / sizeof(pages_tres[0]);
	FIFO(pages_tres, p, capacidade);
	
	//teste 4
	int pages_quatro[] = {1, 3, 0, 3, 5, 6, 3, 2, 1, 4, 8}; // Sequência de páginas referenciadas
	int q = sizeof(pages_quatro) / sizeof(pages_quatro[0]);
	FIFO(pages_quatro, q, capacidade);
	
	//teste 5
	int pages_cinco[] = {-1, 3, 0, -3, 5, -6, 3}; // Sequência de páginas referenciadas
	int r = sizeof(pages_cinco) / sizeof(pages_cinco[0]);
	FIFO(pages_cinco, r, capacidade);
	
	//teste 6
	int pages_seis[] = {1000, 3000, 500, 2000, 1500, 6000, 3500}; // Sequência de páginas referenciadas
	int s = sizeof(pages_seis) / sizeof(pages_seis[0]);
	FIFO(pages_seis, s, capacidade);

    return 0;
}
