#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPalindrome(int x) {
	int tmp = x;
	int res = 0;

	if (x < 0)
		return false;
	else if (x < 10)
		return true;
	else if (x > INT_MAX || x < INT_MIN)
		return false;
	else if (x % 10 == 0)
		return false;
	else {
		while (tmp)
		{
			int pop = tmp % 10;
			if (res > (INT_MAX - pop) / 10)
				return false;
			res = res * 10 + pop;
			tmp /= 10;
		}
	}
	return (res == x);
}

int main()
{
	int x = 121;
	bool result = isPalindrome(x);
	printf("Result: %d\n", result);
	return 0;
}
