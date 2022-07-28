#include <stdio.h>
#include <stdlib.h>
#define Elemtype int

typedef struct LNode{
    Elemtype data;  //数据域
    struct LNode *Next; // 指针域
}LNode, *LinkList;

//初始化一个单链表
bool Init_LinkLinst(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = NULL;   
    return true;
}

//初始化一个循环单链表
bool InitCLinkList(LinkList &L){
    L = (LinkList)malloc(sizeof(LNode));
    L->Next = L;
    return true;
}

//在第i个位置插入元素e(带头结点)
bool ListInsert(LinkList &L, int i, Elemtype e){
    if (i<1) return false;
    LNode *p;  
    int j=0;   //表示当前p指向的是第几个节点
    p = L;
    while (p!=NULL && j<i-1)    //这个循环很牛逼，当i值大于length的时候也是OK的，值得好好研究！
    {
        p=p->Next;
        j++;
    }
    if (p==NULL)  return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->Next = p->Next;
    p->Next = s;
    s->data = e;
    return true;
}

// 由于后插太简单了就不写了，下面写前插操作(在不给头结点的情况下)
bool InsertPriorNode(LNode *p, Elemtype e){   //虽然给定的节点p找不到其前驱节点但我们可以换里面的数据
    if(p==NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->Next = p->Next;
    p->Next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按位查找
LNode * GetElem1(LinkList L, int i){
    if(i<0) return NULL;
    LNode *p = L;
    int j = 0;
    while (p!=NULL && j<i)
    {
        p = p->Next;
        j++;
    }
    return p;  
}

//按位删除操作
bool ListDelete(LinkList &L, int i, Elemtype e){
    if(i<1) return false;
    // LNode *p;
    // int j=0;
    // while (p!=NULL && j<i-1)
    // {
    //     p = p->Next;
    //     j++;
    // }
    LNode *p = GetElem1(L,i-1);
    if(p==NULL || p->Next == NULL) return false; // p==NULL:i值不合法(i值>=length) p->next == NULL:第i-个节点后面没有其他的节点
    LNode *q = p->Next;
    e = q->data;
    p->Next = q->Next;
    free(q);
    return true; 
}

//按值查找
LNode * GetElem(LinkList L, Elemtype e){
    LNode *p = L->Next;
    while (p!=NULL && p->data!=e)
    {
        p = p->Next; 
    }
    return p;
}

// 头插法建立单链表
LinkList List_HeadInsert(LinkList &L){
    LNode *s; int x;
    L = (LinkList)malloc(sizeof(LNode));
    return NULL;

}

//尾插法建立单链表
LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LNode*)malloc(sizeof(LNode));
    LNode *s = L;
    LNode *r = L;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s ->data = x;
        r ->Next = s;
        r = s;
        scanf("%d",&x);
    }
    r->Next= NULL;
    return L;
}

//Test!
int main()
{
    LinkList L;
    List_TailInsert(L);
    LNode *p = L;
    while (p!=NULL)
    {
        printf("%d", p->data);
        p = p->Next;
    }
    
    return 0;
}

