#include <stdio.h>

// This function removes duplicates from a sorted array
// and returns the length of the new array.
// The function uses two pointers to iterate through the array.
// The first pointer i is used to keep track of the last unique element.
// The second pointer j is used to iterate through the array.
// If the element at j is different from the element at i, then the element at j is unique.
// The element at j is then copied to the next position after i.
// The function returns i + 1, which is the length of the new array.

int removeDuplicates(int* nums, int numsSize) {

	int i = 0;
	int j = 0;
	
	while (j < numsSize)
	{
			if (nums[j] != nums[i])
			{
				i++;
				nums[i] = nums[j];
			}
			j++;
	}
	return i + 1;
}

int main()
{
	int nums[] = {0,0,1,1,1,2,2,3,3,4};
	int numsSize = 10;
	int result = removeDuplicates(nums, numsSize);
	printf("Result: %d\n", result);
	return 0;
}
