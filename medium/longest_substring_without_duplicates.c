#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {

	int n = strlen(s);

	if (!s)
		return (0);
	if (n == 1)
		return (1);
	int max_len = 0;
	int start = 0;
	int char_index[128]; // ASCII
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
