#include <stdio.h>
#include <stdlib.h>
#define Elemtype int
#define Maxsize 10

//使用静态数组存放队列元素
typedef struct
{
    Elemtype data[Maxsize];
    int front, rear;
}SqQueue;

//队列的初始化
bool InitQueue(SqQueue &Q){
    Q.front = Q.rear;
    return false;
}

//队列的判空操作
bool IsEmpty(SqQueue Q){
    if(Q.front == Q.rear)
        return true;
    return false;
}

//入队操作
bool EnQueue(SqQueue &Q, Elemtype e){
    if (Q.rear + 1 == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1) % Maxsize;
    return true;
}

//出队操作
bool DeQueue(SqQueue &Q, Elemtype &e){
    if(IsEmpty(Q)) return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}

