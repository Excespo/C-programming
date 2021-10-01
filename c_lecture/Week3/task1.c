#include <stdio.h>

char * isPalindrome(int);

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    printf("%s\n", isPalindrome(x));
    return 0;
}

char * isPalindrome(int x)
{
    int origin = x;
    int last_digit = 0;
    int reverse = 0;
    while (x)
    {
        last_digit = x % 10;
        x = x / 10;
        reverse = 10 * reverse + last_digit;
    }
    if (origin>=0&&reverse==origin)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}