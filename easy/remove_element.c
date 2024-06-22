#include <stdio.h>

// This function removes all instances of a specified value from an array.
// It uses two pointers to iterate through the array.
// The first pointer i is used to keep track of the position where the next non-target element should be placed.
// The second pointer j is used to iterate through the array.
// If the element at j is not equal to the target value, it is copied to the position after i.
// The function returns i, which is the length of the modified array.
// This function modifies the array in place.
// The time complexity is O(n) because each element is visited at most once.
// The space complexity is O(1) because the function operates directly on the input array.

int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;
	int j = 0;

	while (j < numsSize)
	{
		if (nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
		j++;
	}
	return i;
}

int main()
{
	int nums[] = {3, 2, 2, 3};
	int numsSize = 4;
	int val = 3;
	int result = removeElement(nums, numsSize, val);
	printf("Result: %d\n", result);
	return 0;
}
