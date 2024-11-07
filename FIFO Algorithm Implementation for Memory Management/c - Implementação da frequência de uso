void FIFO_Bombado(int pages[], int n, int capacidade) {
    int *quadros = (int *)malloc(capacidade * sizeof(int));
    int *freq_uso = (int *)malloc(capacidade * sizeof(int));
    int indice = 0, faltasDePagina = 0;

    // Inicialização dos quadros e frequências
    for (int i = 0; i < capacidade; i++) {
        quadros[i] = -1;
        freq_uso[i] = 0;
    }

  // Cada pagina é um elemento do array pages
  // A var achou é setada como false (não encontrada)
    for (int i = 0; i < n; i++) {
        int pagina = pages[i];
        int achou = 0;

        // Verifica se a página já está carregada
        for (int j = 0; j < capacidade; j++) {
          // Se a achou nos quadros, incrementa a contagem da frequência na mesma posição do quadro referenciado, dentro do seu próprio vetor
            if (quadros[j] == pagina) {
                achou = 1;
                freq_uso[j]++;
                break;
            }
        }

        // Se não achou a página, ocorre falta de página
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
    }

    printf("Total de faltas de página: %d\n", faltasDePagina);
    free(quadros);
    free(freq_uso);
}
