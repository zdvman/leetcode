#include <stdio.h>

// Explanation:
// Initialization and Setup: Start with i = 1 because we can safely place the second element at the second position.
// Count Duplicates: Use a count variable to track occurrences of the current number.
// Update Elements and Indices:
// If the current element nums[j] is the same as the previous element (nums[j-1]), increment the count.
// If it's a different element, reset count to 1.
// Only copy the current element to nums[i] if count <= 2. This ensures at most two duplicates.
// Increment i Appropriately: i is incremented only when an element is copied.
// Return the New Length: The final value of i represents the length of the modified array.
// By implementing these changes, the function will correctly modify the array in place to remove extra duplicates and return the new length.

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;

	int i = 1;  // Start from the second element
	int count = 1;  // Count the occurrence of the current number

	for (int j = 1; j < numsSize; j++)
	{
		if (nums[j] == nums[j - 1])
		{
			count++;
		}
		else
		{
			count = 1;
		}
		if (count <= 2)
		{
			nums[i] = nums[j];
			i++;
		}
	}

	return i;
}

int main()
{
	int nums[] = {0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 4};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int result = removeDuplicates(nums, numsSize);
	printf("Result: %d\n", result);
	for (int k = 0; k < result; k++)
		printf("nums[%d]: %d\n", k, nums[k]);
	return 0;
}
