#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEETCODE_LINK "leetcode.283 https://leetcode.com/problems/move-zeroes/description/\n"

void moveZeroes(int* nums, int numsSize)
{
  int i  = 0;
  int *new_nums = (int*)malloc(numsSize*sizeof(int));
  int *ptrNewNums = NULL;
  int front = 0, end = (numsSize - 1);

  if (new_nums)
    ptrNewNums = new_nums;

  for (i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      *(ptrNewNums + (front++)) = nums[i];
    } else if (nums[i] == 0) {
      *(ptrNewNums + (end--)) = 0;
    }
  }

  memcpy(nums, new_nums, (numsSize*sizeof(int)));
  free(new_nums);
}

void main (void)
{
  int nums[] = {0, 2, 3, 0, 5, 0, 7, 8, 0};
  int i = 0;

  printf(LEETCODE_LINK);
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_org[%d] = %d\n",
           i, nums[i]);

  moveZeroes(nums, (sizeof(nums)/sizeof(int)));

  printf("\n\n");
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_new[%d] = %d\n",
           i, nums[i]);
}
