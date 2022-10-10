#include <stdio.h>
#include <string.h>

int value(char s[4])
{
    int sum = 0;
    int i=0;
    while (s[i])
    {
        if ((s[i]>='0') && (s[i])<='9')
        {
            sum = sum*8 + s[i]-'0';
            s++;
        }
        
    }
    return sum;
}

int main()
{
    int sum;
    char s[4] = "27";
    sum = value(s);
    printf("%d", sum);
    getchar();
    return 0;
}