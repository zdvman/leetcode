#include <stdio.h>

int val(char c)
{
	int val = 0;
	switch (c)
	{
		case ('I'):
		val = 1;
		break;
		case ('V'):
		val = 5;
		break;
		case ('X'):
		val = 10;
		break;
		case ('L'):
		val = 50;
		break;
		case ('C'):
		val = 100;
		break;
		case ('D'):
		val = 500;
		break;
		case ('M'):
		val = 1000;
		break;
	}
	return val;
}

int sp_case(char *s)
{
	int i = 0;
	int res = 0;
	while (s[i])
	{
		if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
		{
			i++;
			res += val(s[i]) - 1;
			// printf("res = %d\n", res);
		}
		else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
		{
			i++;
			res += val(s[i]) - 10;
			// printf("res = %d\n", res);
		}
		else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
		{
			i++;
			res += val(s[i]) - 100;
			// printf("res = %d\n", res);
		}
		else
		{
			res += val(s[i]);
			// printf("res = %d\n", res);
		}
		i++;
	}
	return res;
}

int romanToInt(char* s) {
	return (sp_case(s));
}
