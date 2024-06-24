#include <stdio.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	int i = 1;
	int j = 0;
	int res_len = 200;
	int len = 0;
	char *res = malloc(201);

	if (strsSize == 0)
		return "";
	if (strsSize == 1)
		return strs[0];
	while (i < strsSize)
	{
		while (strs[0][j] == strs[i][j] && strs[0][j] != '\0' && strs[i][j] != '\0')
		{
			j++;
		}
		if (res_len > j)
			res_len = j;
		j = 0;
		i++;
	}
	i = 0;
	res[res_len] = '\0';
	while (i < res_len)
	{
		res[i] = strs[0][i];
		i++;
	}
	return res;
}

int main()
{
	char *strs[] = {"flower", "flow", "flight"};
	int strsSize = 3;
	char *result = longestCommonPrefix(strs, strsSize);
	printf("Result: %s\n", result);
	return 0;
}
