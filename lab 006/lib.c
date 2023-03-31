#include <stdio.h>

void listNumbers(int * vetor, int size){
   int i = 0;
   for (i = 0; i < size; i++) {
      printf("%d - ", vetor[i]);
   } 
}

void bubbleSort(int *vetor, int n){
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

void selectionSort(int *vetor, int n){
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


void insertionSort(int *vetor, int n){
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
}

void merge(int *vetor, int ini, int mid, int end){
	int i, j, k;
	int n1 = mid - ini + 1; 
	int n2 = end - mid;

	//Create and copy values - half vetor to L and R.
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
	{
		L[i] = vetor[ini + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = vetor[mid + 1 + j]; //se chama no merge sort com mid + 1 e j igual a zero diferente do pseudo cod
	}

	i = 1;
	j = 1;
	//k = ini;
	//essa parte devo pegar o inicio dos elementos e fim percorrer ate o fim(size segundo vetor)
	for (k = ini; k < n2; k++)
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
	}
}

void mergeSort(int *vetor, int ini, int end){
	if(ini < end){
		int mid = (ini + end) / 2; //mid equals mid element

		mergeSort(vetor, ini, mid); //repeat for ini array
		mergeSort(vetor, mid + 1 , end); //repeat for end array
		//merge current block of numbers 
		merge(vetor, ini, mid, end);
	}
}

int partition(int *vetor, int p, int r){
    int x = vetor[r];
    int i = p - 1;
    int j, aux;
    
    for(j = p;j < r - 1; j++){
        if(vetor[j] <= x){
            i = i + 1;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
		vetor[i + 1] = vetor[r];
		vetor[r] = aux;

    return i + 1;
}

void quickSort(int *vetor, int p, int r){
    int q;
    if(p < r) {
        q = partition(vetor, p, r);
        quickSort(vetor, p, q - 1);
        quickSort(vetor, q + 1, r);
    }
}