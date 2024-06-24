#include <stdio.h>

int s_is_valid(char c)
{
	return ((c >= '0' && c <= '9')
	|| (c >= 'a' && c <= 'z')
	|| (c >= 'A' && c <= 'Z')
	|| c == ','
	|| c == '.');
}

char* convert(char* s, int numRows) {

	if (!s || !*s)
		return NULL;
	int i = 0;
	while (s[i])
	{
		if (!s_is_valid(s[i]))
			return NULL;
		i++;
	}
	int s_len = strlen(s);
	if (numRows == 1 || numRows >= s_len)
		return s;
	
	char **arr_of_str = (char **)malloc(sizeof(char *) * numRows);
	for (i = 0; i < numRows; i++)
	{
		arr_of_str[i] = (char *)malloc(s_len + 1);
		arr_of_str[i][0] = '\0';
	}
	int currRow = 0;
	int goingDown = 0;

	for (int i = 0; i < s_len; i++)
	{
		char temp[2] = { s[i], '\0' };
		strcat(arr_of_str[currRow], temp);

		if (currRow == 0 || currRow == numRows - 1) {
			goingDown = !goingDown;
		}

		currRow += goingDown ? 1 : -1;
	}

	char* result = (char*)malloc((s_len + 1) * sizeof(char));
	result[0] = '\0';

	for (int i = 0; i < numRows; i++) {
		strcat(result, arr_of_str[i]);
		free(arr_of_str[i]);
	}
	free(arr_of_str);

	return result;
	
}

int main()
{
	char s[] = "PAYPALISHIRING";
	int numRows = 3;
	char *result = convert(s, numRows);
	printf("Result: %s\n", result);
	return 0;
}
