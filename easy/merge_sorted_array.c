#include <stdio.h>
#include <stdlib.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	// Start from the end of nums1 and nums2
	int i = m - 1;
	int j = n - 1;
	int k = nums1Size - 1;

	// Merge nums1 and nums2 from the end
	while (i >= 0 && j >= 0) {
		if (nums1[i] > nums2[j]) {
			nums1[k--] = nums1[i--];
		} else {
			nums1[k--] = nums2[j--];
		}
	}

	// If there are remaining elements in nums2, copy them
	while (j >= 0) {
		nums1[k--] = nums2[j--];
	}
}

// void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
// 	int i = 0;
//     int j = 0;
// 	int k = 0;
// 	int *tmp = malloc(sizeof(int) * 400);

// 	while (i < m && j < n && k < nums1Size)
// 	{
// 		if (nums1[i] < nums2[j])
// 		{
// 			tmp[k] = nums1[i];
// 			printf("tmp[%d]: %d\n", i, tmp[i]);
// 			i++;
// 			k++;
// 		}
// 		else if (nums1[i] > nums2[j])
// 		{
// 			tmp[k] = nums2[j];
// 			printf("tmp[%d]: %d\n", k, tmp[k]);
// 			j++;
// 			k++;
// 		}
// 		else
// 		{
// 			tmp[k] = nums1[i];
// 			printf("tmp[%d]: %d\n", k, tmp[k]);
// 			tmp[++k] = nums2[j];
// 			printf("tmp[%d]: %d\n", k, tmp[k]);
// 			i++;
// 			j++;
// 			k++;
// 		}
// 	}
// 	while (j < n)
// 	{
// 		tmp[k] = nums2[j];
// 		k++;
// 		j++;
// 	}
// 	while (i < m)
// 	{
// 		tmp[k] = nums1[i];
// 		i++;
// 		k++;
// 	}
// 	for (int k = 0; k < nums1Size; k++)
// 	{
// 		nums1[k] = tmp[k];
// 	}
// 	free(tmp);
// }

int main()
{
	int nums1[] = {1, 2, 3, 0, 0, 0};
	int nums1Size = 6;
	int m = 3;
	int nums2[] = {2, 5, 6};
	int nums2Size = 3;
	int n = 3;
	merge(nums1, nums1Size, m, nums2, nums2Size, n);
	for (int i = 0; i < nums1Size; i++)
	{
		printf("nums1[%d]: %d\n", i, nums1[i]);
	}
	return 0;
}
