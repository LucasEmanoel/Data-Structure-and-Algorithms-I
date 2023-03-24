#include <stdio.h>

void listNumbers(int * vetor, int size){
   int i = 0;
   for (i = 0; i < size; i++) {
      printf("%d - ", vetor[i]);
   } 
}

int * bubbleSort(int *vetor, int n){
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
   return vetor;
}

int * selectionSort(int *vetor, int n){
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
   return vetor;
}


int * insertionSort(int *vetor, int n){
	int aux, i, j;
	for(j=1; j < n; j++){
		aux = vetor[j];
		
		i = j - 1;
		while(i > -1 && vetor[i] > aux){
			vetor[i + 1] = vetor[i];
			i = i - 1;
		}
		vetor[i + 1] = aux;
	}
  return vetor;
}

