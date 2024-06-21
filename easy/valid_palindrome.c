#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>

int is_alpha(char c)
{
	return ((c <= '9' && c >='0')
		|| (c <= 'z' && c >= 'a')
		|| (c <= 'Z' && c >= 'A')); 
}

char ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}


bool reverse_str(char *str)
{
	int last = 0;
	int i = -1;
	char *res = malloc(strlen(str) + 1);
	while (++i < strlen(str))
	{
		if (is_alpha(str[i]))
		{
			res[i] = ft_tolower(str[i]);
			printf("str[%d] %c\n", i, str[i]);
			printf("res[%d] %c\n", i, res[i]);
			last++;
		}
	}
	printf("last %d\n", last);
	res[last] = '\0';
	printf("res %s\n", res);
	char *fin = malloc(last + 1);
	fin[last] = '\0';
	i = 0;
	while (last > 0)
	{
		fin[i] = res[--last];
		i++;
	}
	printf("fin %s\n", fin);
	i = 0;
	while (i < strlen(res))
	{
		if (res[i] != fin[i])
			return false;
		i++;
	}
	
	free(res);
	free(fin);
	return true;
}

bool isPalindrome(char* s) {
	return (reverse_str(s));
}

// Example usage
int main() {
	char *s = "A man, a plan, a canal: Panama";
	printf("%d\n", isPalindrome(s));
	return 0;
}
