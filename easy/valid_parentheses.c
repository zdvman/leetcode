#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int is_bracket(char c)
{
	if (c == '('
		|| c == ')'
		|| c == '{'
		|| c == '}'
		|| c == '['
		|| c == ']')
		return c;
	else
		return 0;
}

bool isValid(char* s) {
	char stack[10000];
	int top = -1;

	if (!s || !*s)
		return false;
	int i = 0;
	if (strlen(s) % 2)
		return false;
	while (*s)
	{
		if (!is_bracket(*s))
			return false;
		if (*s == '(' || *s == '{' || *s == '[')
		{
			stack[++top] = *s;
		}
		else
		{
			if (top == -1)
				return false;
			char last_bracket = stack[top--];
			if ((*s == ')' && last_bracket != '(')
				|| (*s == '}' && last_bracket != '{')
				|| (*s == ']' && last_bracket != '['))
				return false;
		}
		s++;
	}
	return (top == -1);
}

int main()
{
	char s[] = "()";
	bool result = isValid(s);
	printf("Result: %d\n", result);
	return 0;
}
