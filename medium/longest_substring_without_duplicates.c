#include <stdio.h>
#include <string.h>

// Explanation:
// The function lengthOfLongestSubstring finds the length of the longest substring without repeating characters.
// The function uses a sliding window approach to find the longest substring.
// The function uses an array to store the index of the last occurrence of each character.
// The function returns the length of the longest substring.
// The function handles edge cases where the input string is NULL or empty.

int lengthOfLongestSubstring(char* s) {

	int n = strlen(s);

	if (!s)
		return (0);
	if (n == 1)
		return (1);
	int max_len = 0;
	int start = 0;
	int char_index[128]; // ASCII characters - 128 characters from 0 to 127, including special characters.
	int end = 0;
	memset(char_index, -1, sizeof(char_index));
	while (end < n)
	{
		if (char_index[s[end]] != -1)
		{
			start = (char_index[s[end]] + 1 > start) ? char_index[s[end]] + 1 : start;
		}
		char_index[s[end]] = end;
		max_len = (end - start + 1 > max_len) ? end - start + 1 : max_len;
		end++;
	}
	return max_len;
}

int main()
{
	char s[] = "pwwkew";
	int result = lengthOfLongestSubstring(s);
	printf("Result: %d\n", result);
	return 0;
}
