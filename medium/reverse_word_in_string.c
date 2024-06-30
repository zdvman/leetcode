
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Explanation:
// The function reverseWords reverses the words in a string while preserving the order of the words.
// The function uses a helper function ft_isspace to skip leading spaces and to add a single space between words.
// The function reverse reverses the characters in a string between the start and end indices.
// The function reverseWords allocates memory for the result string and reverses the entire string.
// It then reverses each word in the string to obtain the final result.
// The function returns the reversed string.

// If c is a space character, return 1. Otherwise, return 0.
int ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

// Reverse the characters in a string between the start and end indices.
void reverse(char *s, int start, int end)
{
	char tmp;
	while (start < end)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++;
		end--;
	}
}

// Reverse the words in a string.
char* reverseWords(char* s) {
	int i = 0;
	int j = 0;
	if (!s)
		return (NULL);
	if (!*s)
		return (s);
	char *res = malloc(sizeof(char) * strlen(s) + 1);
	if (!res)
		return (NULL);
	while (ft_isspace(s[i]))
		i++;
	while(i < strlen(s))
	{
		if(ft_isspace(s[i]))
		{
			while (ft_isspace(s[i]))
				i++;
			if (i < strlen(s))
				res[j++] = ' ';
		}
		else
			res[j++] = s[i++];
	}
	res[j] = '\0';
	reverse(res, 0, strlen(res) - 1);
	printf("%s len = %ld\n", res, strlen(res));
	int start = 0;
	i = 0;
	while (res[i])
	{
		if (res[i] == ' ' || res[i] == '\0')
		{
			reverse(res, start, i - 1);
			start = i + 1;
		}
		i++;
	}
	return res;
}

int main()
{
	char *s = "the sky is blue";
	char *res =	reverseWords(s);
	printf("Result: %s\n", res);
	free(res);
	return 0;
}
