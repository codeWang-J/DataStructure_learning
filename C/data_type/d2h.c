#include <stdio.h>
#define N 8

char myNum2Char(int num)
{
    char result;
    if (num>=0 && num<=9)
    {
        result = num+'0';
    }
    else
    {
        switch(num)
        {
            case 10:
                result = 'A';
                break;

            case 11:
                result = 'B';
                break;

            case 12:
                result = 'C';
                break;

            case 13:
                result = 'D';
                break;  

            case 14:
                result = 'E';
                break;
            
            case 15:
                result = 'F';
                break;

        }

    }
    return result;
    
}

int main()
{
    int dec, temp, yushu, len = 0, i;    // 输入的十进制数、 中间变量、 余数、 循环变量
    scanf("%d",&dec);
    char hex[N];   //存放结果
    temp = dec;
    while (temp!=0 && temp!=1)
    {
        yushu = temp % 16;
        hex[len++] = myNum2Char(yushu);
        temp = temp / 16;
    }

    if (temp == 1)   // 如果第一位是零则省略不加入到结果中
        hex[len++] = myNum2Char(temp);
    
    for ( i = len; i >= 0; i--)
        printf("%c",hex[i]);

    return 0;
}