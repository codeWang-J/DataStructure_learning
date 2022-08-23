#include <stdio.h>
#include <stdlib.h>
#define Elemtype int

typedef struct   //查找表的数据结构
{
    Elemtype *elem; // 动态数组的起始地址
    int TableLen; // 表的长度
}SSTable;

//顺序查找

int Search_Seq(SSTable ST, Elemtype key){
    int i;
    for ( i = 0; i < ST.TableLen && ST.elem[i] != key; i++)
    // 查找成功则返回1，失败则返回-1
    return i == ST.TableLen? -1 : 1;
    
}