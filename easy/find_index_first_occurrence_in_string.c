#include <stdio.h>

int	strStr(char* haystack, char* needle) {

	int i = 0;
	int j = 0;
	int tmp = 0;
	int index = -1;
	int len = strlen(needle);
	int len2 = strlen(haystack);
	if (len2 < len)
		return index;
	if (len == 0)
		return 0;

	while(haystack[i])
	{
		if (needle[j] == haystack[i]
			&& needle[j]
			&& haystack[i])
		{
			printf("i = %d, j = %d\n", i, j);
			if (index == -1)
				index = i;
			j++;
			i++;
			if (j == len)
				return index;
		}
		else
		{
			if (index != -1)
			{
				i = index + 1;
				index = -1;
				j = 0;
			}
			else
			{
				i++;
			}
		}
	}
	return -1;
}

int main()
{
	char haystack[] = "hello";
	char needle[] = "ll";
	int result = strStr(haystack, needle);
	printf("Result: %d\n", result);
	return 0;
}
