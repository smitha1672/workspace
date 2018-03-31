#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _LEETCODE_LINK "LEETCODE LINKED: https://leetcode.com/problems/merge-sorted-array/description/\n"
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

void merge(int* nums1, int m, int* nums2, int n)
{
  int *numsTemp = (int*)malloc(sizeof(int)*(m+n));
  int i = 0, j = 0, k = 0;

  for (; (i < m) && (j < n); k++)
    numsTemp[k] = ((nums1[i] <= nums2[j])? nums1[i++]:nums2[j++]);
  for(; i < m; )
    numsTemp[k++] = nums1[i++];
  for (; j < n; )
    numsTemp[k++] = nums2[j++];
  memcpy(nums1, numsTemp, (sizeof(int)*(m+n)));
  free(numsTemp);
}

void main(void)
{
  int *nums1 = NULL, *nums2 = NULL;
  const int nums1Size = 3, nums2Size = 5;
  int initial = 0;

  _SHOW_LEETCODE_LINK;

  nums1 = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
  nums2 = (int*)malloc(sizeof(int)*nums2Size);

  initial = 2;
  for (int i = 0; i < nums1Size; i++)
    nums1[i] = (initial*=2);

  initial = 3;
  for (int i = 0; i < nums2Size; i++)
    nums2[i] = (initial*=3);

  printArray(nums1, nums1Size, 100);
  printArray(nums2, nums2Size, 101);
  merge(nums1, nums1Size, nums2, nums2Size);

  free(nums1);
  free(nums2);
}
