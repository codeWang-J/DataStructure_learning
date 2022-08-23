#include <stdio.h>
#include <stdlib.h>
#define Elemtype int

typedef struct LNode   //队列节点
{
    Elemtype data;
    struct LNode *next;
}LNode;

typedef struct       // 链式队列
{
    LNode *rear, *front;  // 链式队列的头节点和尾节点
}LinkQueue;


bool InitLinkQueue(LinkQueue &Q){
    Q.front = Q.rear = (LNode*)malloc(sizeof(LNode));
    Q.front = NULL;
}

// 链式队列的入队操作
bool EnQueue(LinkQueue &Q, Elemtype e){
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

// 链式队列的删除操作
bool DeQueue(LinkQueue &Q, Elemtype &e){
    if(Q.front  == Q.rear) 
        return false;    // 队列为空
    LNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (p == Q.rear)      // 判断队列是否就一个节点
        Q.front = Q.rear;
    free(p);
    return true;
}


