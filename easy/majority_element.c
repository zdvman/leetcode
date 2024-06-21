#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>

// Majority Element in the Problem Statement

// According to the problem statement, the majority element
// is defined as the element that appears more than ⌊n / 2⌋
// times in the array. This is a specific definition and means
// that the element must appear more than half of the time
// in the array.

// General Understanding

// In general, people might consider the majority element
// to be the one that appears more than any other element
// in the array. However, this does not necessarily meet
// the ⌊n / 2⌋ criterion unless explicitly stated.
// Correct Definition for This Problem

// Given the constraints and guarantees of the problem,
// the Boyer-Moore Voting Algorithm is appropriate.
// This algorithm finds the element that appears more
// than ⌊n / 2⌋ times efficiently in O(n) time and O(1) space.
// Boyer-Moore Voting Algorithm in C

int majorityElement(int* nums, int numsSize)
{
	int count = 0;
	int candidate = 0;

	// Phase 1: Find a candidate
	for (int i = 0; i < numsSize; i++) {
		if (count == 0) {
			candidate = nums[i];
		}
		count += (nums[i] == candidate) ? 1 : -1;
	}

	// Phase 2: Verify the candidate
	count = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] == candidate) {
			count++;
		}
	}

	// Since the problem statement guarantees that a majority element always exists,
	// we do not need to check if count > numsSize / 2
	// if (count > numsSize / 2) {
	//     return candidate;
	// } else {
	//     // This case should not happen as per problem guarantee
	//     // If it does, it means the input doesn't meet the problem constraints
	//     return -1; // Indicate an error or invalid input
	// }

	return candidate;
}

int main()
{
	int arr[] = {3, 2, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", majorityElement(arr, size));
	return 0;
}

// The term for the element that occurs more frequently
// than any other element in an array is typically called
// the mode. In statistics and probability theory,
// the mode of a set of data values is the value that appears
// most frequently. However, it's important to note
// that the mode does not necessarily have to appear more than
// half the times in the array, as required by the definition
// of a "majority element."

// Example

// Let's consider the array:
// int nums[] = {3, 3, 3, 3, 2, 2, 2, 1, 1, 1};

//     Mode: The mode of this array is 3, as it appears more frequently
//     than any other number.

//     Majority Element: There is no majority element in this array
//     because no element appears more than ⌊n / 2⌋ = 5 times.
