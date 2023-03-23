#include <stdio.h>

int binarySearch (int *vetor, int start, int end, int val);

int main ()
{
  int result = 0;
  int vetor[] =
    { 1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
    71};

  result = binarySearch(vetor, 1, 19, 3);
  printf("Posicao = %d", result);
  return 0;
}

int binarySearch (int *vetor, int start, int end, int val)
{
  int mid_term = (start + end) / 2;
 
  if(val == vetor[mid_term]){
    return mid_term;
  }
  
  if(vetor[mid_term] > val){
    binarySearch(vetor, start, mid_term-1, val);
  } else {
    binarySearch(vetor, mid_term+1, end, val);
  } 
}