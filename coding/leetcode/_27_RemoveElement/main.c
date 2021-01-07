#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEETCODE_LINK "leetcode.27: https://leetcode.com/problems/remove-element/description/\n"

void xorSwap (int *x, int *y) {
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

void printElement(int *nums, int numsSize, int idx)
{
  for (int i = 0; i < numsSize; i++)
    printf("%d: nums[%d] = %d\n", idx, i, *(nums+i));
  printf("end \n\n");
}

int removeElement(int* nums, int numsSize, int val)
{
  int i = 0;
  for (int j = 0; j < numsSize; j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}

void main (void)
{
  int nums[] = {3, 2, 2, 3};
  int i = 0;
  int length = 0;

  printf(LEETCODE_LINK);
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_org[%d] = %d\n",
           i, nums[i]);

  length = removeElement(nums, sizeof(nums)/sizeof(int), 2);
  if (length)
    printf("length = %d\n", length);

  printf("\n\n");
  for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    printf("nums_new[%d] = %d\n",
           i, nums[i]);
}
