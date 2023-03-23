//#include <seuOutroArquivo.h> chamar assim na main
#include <stdio.h>

void bubbleSort(int vetor[], int n){
   int aux, j, i;
   for (i = 0; i < n; i++) { 
       for (j = 0; j < n - i - 1; j++) {   
            if (vetor[j] > vetor[j + 1]) { 
               aux = vetor[j];
               vetor[j] = vetor[j + 1];
               vetor[j + 1] = aux;
           }
       }
   }
}

void selectionSort(int vetor[], int n){
   int min, aux, j, i = 0;
	
	for(i = 0; i <= n-2; i++){
		min = i;
		for(j = i+1; j<=n-1; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}

		aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
	}
}
