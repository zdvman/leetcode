#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int tenpow(int n)
{
    if (n == 0)
        return (1);
    else if (n == 1)
        return (10);
    else
        return (10 * tenpow(n - 1));
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    else if (x < 10)
        return true;
    else if (x % 10 == 0)
        return false;
    else if (x < -2147483648)
        return false;
    else if (x > 2147483647)
    return false;
    else
    {
        int nums = 0;
        int tmp = x;
        while (tmp > 0)
        {
            tmp /= 10;
            nums++;
        }
        tmp = x;
        int tmp2 = 0;
        int i = 1;
        while (i <= nums)
        {
            tmp2 += (tmp % 10) * tenpow(nums - i);
            tmp /= 10;
            i++;
        }
        if (tmp2 == x)
            return true;
        else
            return false;
    }   
    return false;
}

int main() {
    printf("%d\n", isPalindrome(1221));

    return 0;
}
