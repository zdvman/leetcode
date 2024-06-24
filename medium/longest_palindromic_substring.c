#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse_str(char *s)
{
	if (!s)
		return NULL;
	int len = strlen(s);
	char *res = malloc(len + 1);
	if (!res)
		return NULL;
	res[len] = '\0';
	for (int i = 0; i < len; i++) {
		res[i] = s[len - 1 - i];
	}
	return res;
}

int is_alpha(char c)
{
	return ((c >= '0' && c <= '9')
			|| (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

char* longestPalindrome(char* s) {
	int i = 0;
	char *res = NULL;

	if (!s || !*s)
		return NULL;
	while (s[i])
	{
		if (!is_alpha(s[i]))
			return NULL;
		i++;
	}
	char *s2 = reverse_str(s);
	if (!s2)
		return NULL;

	int len = strlen(s);
	int **dp = malloc(sizeof(int *) * (len + 1));
	if (!dp) {
		free(s2);
		return NULL;
	}
	for (i = 0; i <= len; i++)
	{
		dp[i] = malloc(sizeof(int) * (len + 1));
		if (!dp[i]) {
			for (int k = 0; k < i; k++) {
				free(dp[k]);
			}
			free(dp);
			free(s2);
			return NULL;
		}
		memset(dp[i], 0, sizeof(int) * (len + 1));
	}

	int max = 0;
	int start = 0;
	for (i = 1; i <= len; i++)
	{
		for (int j = 1; j <= len; j++)
		{
			if (s[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max)
				{
					// Ensure the palindrome is not just a suffix
					if (i - dp[i][j] == (len - j))
					{
						max = dp[i][j];
						start = i - max;
					}
				}
			}
		}
	}
	
	res = malloc(max + 1);
	if (!res) {
		for (i = 0; i <= len; i++) {
			free(dp[i]);
		}
		free(dp);
		free(s2);
		return NULL;
	}
	res[max] = '\0';
	for (i = 0; i < max; i++)
	{
		res[i] = s[start + i];
	}

	for (i = 0; i <= len; i++)
	{
		free(dp[i]);
	}
	free(dp);
	free(s2);
	return res;    
}

int main()
{
	char s[] = "babad";
	char *result = longestPalindrome(s);
	printf("Result: %s\n", result);
	free(result);
	return 0;
}
