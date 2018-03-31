#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEETCODE_LINK "leetcode.448: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/\n"

void xorSwap (int *x, int *y) {
  if (x != y) {
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
  }
}

void printElement(int *array, int arraySize, int idx)
{
  int i = 0;

  printf("%d:", idx);
  for (i = 0; i < arraySize; i++) {
    printf(" %d", array[i]);
  }
  printf("\n");
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
  //get the hash
  int hashIndex = 0;
  int key = 1;
  int size = 0;

  /*get the hash*/
  hashIndex = key % numsSize;

  //move in array until an empty
  while (1) {
    if (nums[hashIndex] == key) {
      printf("key[%d] is in data[%d] = %d\n",
             key, hashIndex, nums[hashIndex]);
      hashIndex = (++key) % numsSize;
    }

    //go to next cell
    if ((++hashIndex) > (numsSize-1)) {
      *returnSize = size;
      return nums;
   } else {
      nums[size++] = key;

      printf("key:%d cannot be found, hashIndex: %d\n", key, hashIndex);
      hashIndex = (++key) % numsSize;
      continue;
    }
    hashIndex %= numsSize;
  }
  return NULL;
}

void main (void)
{
  int nums[] = {4,3,2,7,8,2,3,1};
  int i = 0;
  int length = 0;
  int *disappearNums = NULL;
  int returnSize = 0;

  printf(LEETCODE_LINK);
  printElement(nums, sizeof(nums)/sizeof(int), 100);

  disappearNums = findDisappearedNumbers(nums,
                                       (sizeof(nums)/sizeof(int)),
                                       &returnSize);
  printElement(nums, sizeof(nums)/sizeof(int), 101);

}
