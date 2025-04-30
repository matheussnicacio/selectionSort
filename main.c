#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10000
// Prototipo de Função
void geraNumero(int *vet, int op);
void selectionSort(int *vet);
void imprimirVetor(int *vet);

// Variáveis Globais
int qtd_comparacoes, qtd_trocas;

int main(void) {
 printf("----- SELECTION  SORT -----");
 // Variáveis
 int vet1[TAMANHO];
 float tempo_inicial, tempo_final;
 printf("\nOrdenado:\n");
 geraNumero(vet1,1);
 tempo_inicial = clock();
 selectionSort(vet1);
 tempo_final = clock() - tempo_inicial;
 printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    //imprimirVetor(vet1);

 printf("\nInvertido:\n");
 geraNumero(vet1,2);
 tempo_inicial = clock();
 selectionSort(vet1);
 tempo_final = clock() - tempo_inicial;
 printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    //imprimirVetor(vet1);

 printf("\nAleatorio:\n");
 geraNumero(vet1,3);
 tempo_inicial = clock();
 selectionSort(vet1);
 tempo_final = clock() - tempo_inicial;
 printf("\nQuantidade de comparacoes: %i\n",qtd_comparacoes);
    printf("Quantidade de trocas: %i\n",qtd_trocas);
    printf("Tempo de execucao do algoritmo: %.3f\n",tempo_final/1000);
    //imprimirVetor(vet1);
 return 0;
}

// Função geração de números
void geraNumero(int *vet, int op) {
    int i, j;

    switch (op) {
        case 1: // Ordenados
            for (i = 0; i < TAMANHO; i++) {
                vet[i] = i + 1;
            }
            break;
        case 2: //Invertidos
            for (i = 0; i < TAMANHO; i++) {
               vet[i] = TAMANHO-i;
            }
   break;
        case 3: // Aleatórios sem repetição
      for (i = 0; i < TAMANHO; i++) {
          int novo;
          int duplicado;
          do {
              duplicado = 0;
              novo = (rand() % TAMANHO)+1;

              // Verifica se o número já existe no array
              for (int j = 0; j < i; j++) {
                  if (vet[j] == novo) {
                      duplicado = 1;
                      break;
                  }
              }
          } while (duplicado);

          vet[i] = novo;
      }
      break;
    }

}
// Função ordenação selection sort
void selectionSort(int *vet) {
    int i, j, minIndex, temp;
    qtd_trocas = 0;
    qtd_comparacoes = 0;
    for (i = 0; i < TAMANHO - 1; i++) {
        qtd_trocas++;
        minIndex = i;
        // Encontra o menor elemento no restante do array
        for (j = i + 1; j < TAMANHO; j++) {
            qtd_comparacoes++;
            if (vet[j] < vet[minIndex]) {
                minIndex = j;
            }
        }
        // Se o menor elemento não for o elemento atual, troca
        if (minIndex != i) {
            qtd_trocas++;
            temp = vet[i];
            vet[i] = vet[minIndex];
            vet[minIndex] = temp;
        }
    }
}
// Função impressão do vetor
void imprimirVetor(int *vet){
 int i;
 for(i=0;i<TAMANHO;i++){
  printf("%i, ",vet[i]);
  if ((i+1)%10 == 0){
   printf("\n");
  }
 }
}