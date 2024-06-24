#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
