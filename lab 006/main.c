#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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

  fclose(numbers);
  return 0;
}

