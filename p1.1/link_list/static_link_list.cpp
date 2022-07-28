#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
#define ELemtype int

struct Node
{
    ELemtype data;
    int next;    //下一个元素的数组下标
};

typedef struct    //另一种定义方式
{
    ELemtype data;
    int next;
}SLinkList[Maxsize];

void testSlinkList(){
    SLinkList a;   //这个a其实是一个长度为MaxSize，类型为Node的一个数组
}

void test(){      //上一个函数等价于这个
    struct Node a[Maxsize];
}


