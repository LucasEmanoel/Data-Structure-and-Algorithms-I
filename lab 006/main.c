#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lib.c"

int main()
{
  clock_t timeBubbleSort, timeSelection;
  int numberArray[10000];
  int i;

  FILE *numbers;
  numbers = fopen("random_numbers.txt", "r");
  if (numbers == NULL)
  {
    printf("Error.\n");
    return 1;
  }

  while (!feof(numbers) && i<10000){
    fscanf(numbers, "%d,", &numberArray[i]);
    i++;
  }

  timeBubbleSort = clock();
  bubbleSort(numberArray, 10000);
  //just for check the result 
  //listNumbers(numberArray, 10000);
  printf("\nBubbleSort:\t\t%f seconds\n",(clock() - timeBubbleSort) / (double)CLOCKS_PER_SEC);

  timeSelection = clock();
  selectionSort(numberArray, 10000);
  //just for check the result 
  //listNumbers(numberArray, 10000);
  printf("\nSelection Sort:\t\t%f seconds\n",(clock() - timeSelection) / (double)CLOCKS_PER_SEC);

  fclose(numbers);
  return 0;
}

