#include <stdio.h>
#include <stdlib.h>
#include "mergeSort.h"
#include "radix.h"

int main() {
   int n;
   printf("Enter the number of elements: ");
   scanf("%d", &n);
   int *arr=(int*)(malloc(n*sizeof(int)));
   printf("what is your favorite sorting algorithm? <3 for RadixSort, :( for MergeSort");
   char choice[2];
   scanf(" %c", &choice);
   if (choice[0] == '<') {
      radix(n, arr);
      
   } else if (choice[0] == ':') {
      mergeSort(arr, 0, n - 1);
   } else {
      printf("outdated emoji");
   }
   for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
   }
   printf("Sorted elements: ");
   for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
   }
   free(arr);
   return 0;
}