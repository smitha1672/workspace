#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _LEETCODE_LINK "LEETCODE LINKED: https://leetcode.com/problems/rotate-array/description/\n"
#define _SHOW_LEETCODE_LINK printf(_LEETCODE_LINK)

void printArray(int *array, int arraySize, int idx)
{
  int i = 0;

  printf("%d:", idx);
  for (i = 0; i < arraySize; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

void rotate(int* nums, int numsSize, int k)
{
  int i = 0, j = k;
  int up = 0;

  for (j = 0; j < k; j++) {
    up = nums[numsSize-1];
    for (i = (numsSize-1); i > 0; i--) {
      nums[i] = nums[i-1];
    }
    nums[0] = up;
  }
}

void main(void)
{
  int nums[] = {1,2,3,4,5,6,7};
  int nums_size = sizeof(nums)/sizeof(int);

  _SHOW_LEETCODE_LINK;
  printArray(nums, nums_size, 100);
  rotate(nums, nums_size, 6);
  printArray(nums, nums_size, 101);
}
