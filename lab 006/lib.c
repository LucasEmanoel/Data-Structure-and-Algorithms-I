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

void merge(int *vetor, int left, int m, int right){
	int i, j, k;
	int n1 = m - left + 1; 
	int n2 = right - m;

	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i] = vetor[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = vetor[m + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			vetor[k] = L[i];
			i++;
		}
		else
		{
			vetor[k] = R[j];
			j++;
		}
		k++;
	}
	//caso nao seja vetor par sobra alguns elementos

	while (i < n1)
	{
		vetor[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2)
	{
		vetor[k] = R[j];
		j++;
		k++;
	}
	
}
//first element and last
void mergeSort(int *vetor, int left, int right){
	if(left < right){
		int m = left + (right - left) / 2; //m equals mid element

		mergeSort(vetor, left, m); //repeat for left array
		mergeSort(vetor, m+1, right); //repeat for right array
		//merge current block of numbers 
		merge(vetor, left, m, right);
	}
}

