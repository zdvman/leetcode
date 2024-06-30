#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Explanation:
// The function findMedianSortedArrays finds the median of two sorted arrays.
// Mdeian is the middle element of a sorted array. If the array has an odd number of elements,
// the median is the middle element.
// If the array has an even number of elements, the median is the average of the two middle elements.

// The function merges the two arrays into a single sorted array.
// If the total length of the merged array is odd, the median is the middle element.
// If the total length of the merged array is even, the median is the average of the two middle elements.
// The function returns the median as a double.
// The function uses dynamic memory allocation to store the merged array.
// The function frees the allocated memory before returning the result.
// The function handles edge cases where one or both arrays are empty.

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	double	res;
	int		*m;
	int		i, j, k;
	int		len;


	k = j = i = 0;
	len =  nums1Size + nums2Size;
	m = (int *)malloc(sizeof(int) * len);
	if (m == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}
	while (i < nums1Size && j < nums2Size)
	{
		if (nums1[i] < nums2[j])
			m[k++] = nums1[i++];
			else
			m[k++] = nums2[j++];
	}
	while (i < nums1Size)
	{
		m[k++] = nums1[i++];
	}
	while (j < nums2Size)
	{
		m[k++] = nums2[j++];
	}
	if (len & 1)
		res = m[len / 2];
	else
		res = (m[len / 2] + m[len / 2 - 1]) / 2.0;
	free(m);
	return (res);
}
int main()
{
	int nums1[] = {1, 3};
	int nums2[] = {2};
	int nums1Size = 2;
	int nums2Size = 1;
	double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
	printf("Result: %f\n", result);
	return 0;
}
