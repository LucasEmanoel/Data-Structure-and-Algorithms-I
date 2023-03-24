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

  clock_t timeBubbleSort, timeSelection, timeInsertion;
  
  int * rawList, *sortByBubble, *sortBySelection, *sortByInsertion;
  rawList = (int*) malloc( sizeof(int) * 10000);
  rawList = readFile(numbers);

  sortByBubble = (int*) malloc( sizeof(int) * 10000);
  sortBySelection = (int*) malloc( sizeof(int) * 10000);
  sortByInsertion = (int*) malloc( sizeof(int) * 10000);
  

  timeBubbleSort = clock();
  sortByBubble = bubbleSort(rawList, 10000);
  //just for check the result 
  //listNumbers(sortByBubble, 10000);
  printf("\nBubbleSort:\t\t%f seconds\n",(clock() - timeBubbleSort) / (double)CLOCKS_PER_SEC);

  timeSelection = clock();
  sortBySelection = selectionSort(rawList, 10000);
  //just for check the result 
  //listNumbers(sortBySelection, 10000);
  printf("\nSelection Sort:\t\t%f seconds\n",(clock() - timeSelection) / (double)CLOCKS_PER_SEC);

  timeInsertion = clock();
  sortByInsertion = insertionSort(rawList, 10000);
  //just for check the result 
  //listNumbers(sortByInsertion, 10000);
  printf("\nInsertion Sort:\t\t%f seconds\n",(clock() - timeInsertion) / (double)CLOCKS_PER_SEC);

  fclose(numbers);
  return 0;
}

