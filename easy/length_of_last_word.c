#include <stdio.h>
#include <string.h>

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int lengthOfLastWord(char* s) {

	if (!s)
		return 0;
	int i = strlen(s) - 1;
	int count = 0;
	while (i >= 0)
	{
		if(ft_isspace(s[i]))
		{
			if (count)
				break ;
			i--;
			continue ;
		}
		count++;
		i--;
	}
	return count;
}

int main()
{
	char s[] = "a";
	int result = lengthOfLastWord(s);
	printf("Result: %d\n", result);
	return 0;
}
