#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.c"

int * readFile(FILE * file){
  int * list;
  list = (int*) malloc( sizeof(int) * 10000);
  
  if (file == NULL)
  {
    printf("Error.\n");
    return NULL;
  }

  int i = 0;
  while (!feof(file) && i<10000){
    fscanf(file, "%d,", &list[i]);
    i++;
  }

  return list;
}

int main()
{
  FILE *numbers;
  numbers = fopen("random_numbers.txt", "r");

  clock_t timeBubbleSort, timeSelection, timeInsertion, timeMerge, timeQuick;
  
  int * arrayNumbers, * arr;

  arrayNumbers = readFile(numbers);
  arr = (int*) malloc(sizeof(int) * 10000);

  memcpy(arr, arrayNumbers, sizeof(int) * 10000);
  timeBubbleSort = clock();
  bubbleSort(arrayNumbers, 10000);
  printf("\nBubbleSort:\t\t%f seconds\n",(clock() - timeBubbleSort) / (double)CLOCKS_PER_SEC);

  memcpy(arrayNumbers, arr, sizeof(int) * 10000);
  timeSelection = clock();
  selectionSort(arrayNumbers, 10000);
  printf("\nSelection Sort:\t\t%f seconds\n",(clock() - timeSelection) / (double)CLOCKS_PER_SEC);

  memcpy(arrayNumbers, arr, sizeof(int) * 10000);
  timeInsertion = clock();
  insertionSort(arrayNumbers, 10000);
  printf("\nInsertion Sort:\t\t%f seconds\n",(clock() - timeInsertion) / (double)CLOCKS_PER_SEC);

  memcpy(arrayNumbers, arr, sizeof(int) * 10000);
  timeMerge = clock();
  merge(arrayNumbers, 0, 10000, 10000);
  printf("\nMerge Sort:\t\t%f seconds\n",(clock() - timeMerge) / (double)CLOCKS_PER_SEC);

  memcpy(arrayNumbers, arr, sizeof(int) * 10000);
  timeQuick = clock();
  //listNumbers(arrayNumbers, 10000);
  quickSort(arrayNumbers, 0, 10000);
  //printf("\n ordenado \n");
  //listNumbers(arrayNumbers, 10000);
  printf("\nQuick Sort:\t\t%f seconds\n",(clock() - timeQuick) / (double)CLOCKS_PER_SEC);

  fclose(numbers);
  free(arr);
  free(arrayNumbers);
  return 0;
}

