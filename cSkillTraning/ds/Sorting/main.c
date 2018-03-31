#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void printArray(int *array, int arraySize, int idx)
{
  int i = 0;

  printf("%d:", idx);
  for (i = 0; i < arraySize; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

void insertSort(int *nums, int numsSzie)
{
  int i = 0;
  int j = 0;
  int up = 0;

  for (i = 1; i < numsSzie; i++) {
    up = nums[i];
    j = i;
    while ((j > 0) && (nums[j-1] > up)) {
      nums[j] = nums[j-1];
      j --;
    }
    nums[j] = up;
    printArray(nums, numsSzie, i);
  }
}

void main(void)
{
  int nums[] = {34, 8, 64, 51, 32, 21};

  insertSort(nums, sizeof(nums)/sizeof(int));
}


