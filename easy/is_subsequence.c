#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
	if (!s || !t)
		return false;
	int i = 0;
	int j = 0;
	while (s[i] && t[j])
	{
		if (s[i] != t[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	return (!s[i]);
}

int main()
{
	char s[] = "abc";
	char t[] = "ahbgdc";
	bool result = isSubsequence(s, t);
	printf("Result: %d\n", result);
	return 0;
}
