#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100

struct Elemtype
{
    int value;
};


typedef struct BiTNode
{
    Elemtype data;
    struct BiTNode *lchild, *rchild;
}*BiTree,BiTNode;

// 线索二叉树结点
typedef struct ThreadNode
{
    Elemtype data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;   // 左右线索标志 tag为0表示指向孩子 tag为1表示指向线索
}ThreadNode, *Threadtree;
