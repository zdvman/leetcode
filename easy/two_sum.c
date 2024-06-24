#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	
	int *res = malloc(sizeof(int) * 2);

	printf("returnSize %i", *returnSize);

	int i = 0;
	int j = 0;
	while (i < numsSize)
	{
		j = i + 1;
		while (j < numsSize)
		{
			if (target == nums[i] + nums[j])
			{
				res[0] = i;
				res[1] = j;
				returnSize = res;
				return res;
			}
			j++;
		}
		i++;
	}
	returnSize = res;
	return res;
}

int main()
{
	int nums[] = {2, 7, 11, 15};
	int numsSize = 4;
	int target = 9;
	int returnSize = 2;
	int *result = twoSum(nums, numsSize, target, &returnSize);
	printf("Result: %d, %d\n", result[0], result[1]);
	return 0;
}
