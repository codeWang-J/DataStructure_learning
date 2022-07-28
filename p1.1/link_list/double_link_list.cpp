#include <stdio.h>
#include <stdlib.h>
#define Elemtype int

//双链表节点定义
typedef struct DNode
{
    struct DNode *prior, *next;
    Elemtype data;
}DNode, *DLinkList;

//初始化一个双链表
bool InitDLinkList(DLinkList &L){
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL) return false;
    L->next = NULL;
    L->prior = NULL;
    return true;
}

//双链表的插入操作
bool InsertNextDNode(DNode *p, DNode *s){
    s->next = p->next;
    if(p->next != NULL)
        p->next->prior = s;
    p->next = s;
    s->prior = p;
    return true; 
}

//双链表的删除操作
bool DeleteNextDNode(DNode *p){
    if(p == NULL || p->next == NULL) return false;
    DNode *q = p->next;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
