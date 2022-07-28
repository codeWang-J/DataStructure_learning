#include <stdio.h>
#include <stdlib.h>
#define InitSize 100
//#define Maxsize 50
#define ElemType int
//静态分配内存的方式来实现顺序表
// typedef struct 
// {
//     /* data */
//     ElemType data[Maxsize];
//     int length;
// }SqList;

//动态分配内存的方式来实现顺序表
typedef struct SqList
{
    /* data */
    ElemType *data;
    int length, Maxsize;
}SqList;


//初始化一个顺序表
void InitList(SqList &L){
    L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
    L.length = 0;
    L.Maxsize = InitSize;

}

//动态增加数组长度
void IncreaseSize(SqList &L, int len){
    ElemType *p = L.data;
    L.data = (ElemType *)malloc(sizeof(ElemType)*(L.Maxsize+len));
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        L.data[i] = p[i];
    }
    free(p);
}

// 插入元素
bool ListInsert(SqList &L, int i, ElemType e){
    if (i<1 || i>L.length+1)
        return false;

    if (i>=L.Maxsize)
        return false;

    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j-1];

    L.data[i-1] = e;
    L.length ++;
    return true;      
}

// 删除元素
bool ListDelete(SqList &L, int i, ElemType &e){
    if (i<1 || i>L.length+1)
    {
        return false;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length --;
    return true;    
}
//查找表中的元素，并返回其位序
int LocateElem(ElemType e, SqList L){  
    int i = 0;
    for ( i = 0; i < L.length; i++)
    {
        /* code */
        if (L.data[i] == e)
        {
            /* code */
            return i+1;
        }
    }
    return 0;
    
}

bool Dle_Min(SqList &L, ElemType value){
    if (L.length == 0)
    {
        return false;
    }

    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        /* code */
        if (L.data[i] < value)
        {
            value =L.data[i];
            pos = i;
        } 
    }
    L.data[pos] = L.data[L.length-1];
    L.length --;
    return true;
   
}

// void InitList(SqList &L){   //静态分配
//     for (int i = 0; i < InitSize; i++)
//     {
//         /* code */
//         L.data[i] = 0;
//         L.length = 0;
//     }
    
// }

int main(){
    SqList L; 
    int a,e;
    InitList(L);
    ListInsert(L,1,1);
    a = LocateElem(1,L);
    printf("查找的值为:%d \n",a);
    printf("线性表的长度为:%d\n",L.length);
    printf("***********************\n");
    ListDelete(L,1,e);
    printf("删除操作完成后了\n");
    printf("删除后线性表的长度为:%d",L.length);
}