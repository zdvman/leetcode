#include <stdio.h>

// Explanation:
// Reverse the entire array.
void reverse1(int *nums, int numsSize)
{
	int tmp = 0;
	int end = numsSize - 1;
	int i = 0;
	while (i < numsSize / 2)
	{
		tmp = nums[i];
		nums[i] = nums[end];
		nums[end] = tmp;
		end--;
		i++;
	}
}

// Reverse the first k elements.
void reverse2(int *nums, int k)
{
	int tmp = 0;
	int end = k - 1;
	int i = 0;
	while (i < k / 2)
	{
		tmp = nums[i];
		nums[i] = nums[end];
		nums[end] = tmp;
		end--;
		i++;
	}
}

// Reverse the remaining elements.
void reverse3(int *nums, int numsSize, int k)
{
	int tmp = 0;
	int end = numsSize - 1;
	int i = k;
	while (i < k + (numsSize - k) / 2)
	{
		tmp = nums[i];
		nums[i] = nums[end];
		nums[end] = tmp;
		end--;
		i++;
	}
}

void rotate(int* nums, int numsSize, int k) {
	if (!k || !(k % numsSize))
		return ;
	k = k % numsSize;
	reverse1(nums, numsSize);
	reverse2(nums, k);
	reverse3(nums, numsSize, k);
	// Explanation commented code below:
	// The code below is a brute-force solution that uses an extra array to store the rotated elements.
	// The code above is a more efficient solution that rotates the elements in place.
	// int *tmp = malloc(sizeof(int) * numsSize);
	// for (int i = 0; i < numsSize; i++)
	// {
	//     int j = i + k;
	//     if (j >= numsSize)
	//         tmp[j - numsSize] = nums[i];
	//     else
	//         tmp[j] = nums[i];
	// }
	// for (int i = 0; i < numsSize; i++)
	// {
	//     nums[i] = tmp[i];
	// }
	// free(tmp);
}

int main()
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++)
	{
		printf("nums[%d]: %d\n", i, nums[i]);
	}
	return 0;
}
