#include <stdio.h>
#include <stdlib.h>
#define Elemtype char
#define MaxLength 255

typedef struct    // 静态数组实现串
{
    char ch[MaxLength];
    int length;
}SString;

typedef struct // 动态数组实现串
{
    char *ch;
    int length;
} HString;

bool SubSting(SString &Sub, SString S, int pos, int len){
    if (pos + len -1 > S.length)
        return false;
    
    for (int i = pos; i < pos+len; i++)
    {
        Sub.ch[i-pos+1] = S.ch[i]; 
    }
    Sub.length = len;
    return true;
}

// 比较操作  若S>T, 则返回值大于0, 相等则返回值等于0, 若S<T, 则返回值小于0.
int StrCompare(SString S, SString T){
    for (int i = 1; i<=S.length && i<=T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

// 定位操作。若主串S中存在与串T相同的子串，则返回它在主串中第一次出现的位置：否则函数值为0。
int Index(SString S, SString T){
    int i =1, n = S.length, m = T.length;
    SString sub;
    while (i<=n-m+1)
    {
        SubSting(sub, S, i, m);
        if (StrCompare(sub,T) != 0)
            ++i;
        else return i;
    }
    return 0;
}

// 朴素模式匹配算法
int PIndex(SString S, SString T){
    int k = 1;
    int i = k, j = 1;
    while (i <= S.length && j <= T.length)
    {
        if(S.ch[i] == T.ch[i]){
            ++i;
            ++j;
        }
        else{
            k++;
            i = k;
            j = 1;   // 将j重新指向子串的开头
        }
    }
    if(j > T.length)
        return k;
    else
        return 0;
}