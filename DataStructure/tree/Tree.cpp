#include <stdio.h>
#include <stdlib.h>
#define Maxsize 100
struct Elemtype
{
    int value;
};


// 二叉树的顺序存储
struct SqTreeNode
{
    Elemtype data;
    bool isEmpty;
};

struct TreeForSq
{
    SqTreeNode t[Maxsize];
};

// 定义一个长度为Maxsize的数组t，按照从上至下、从左至右的顺序依次存储完全二叉树的各个节点
// 初始化操作 --> 将数组里的所有节点标记为空

bool InitTreeForSq(TreeForSq &T){
    for (int i = 0; i < Maxsize; i++)
        T.t[i].isEmpty = true;
}

// 二叉树的链式存储
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


// // 初始换一棵空树
// bool InitBiTree(BiTNode *root){
//     root = (BiTNode)malloc(sizeof(BiTNode));
//     root->data = {1};
//     root->lchild = NULL;
//     root->lchild = NULL;
// }

//
void visit(BiTNode *t){
    printf("%d",t->data.value);
}

// 先序遍历
void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 中序遍历
void InOrder(BiTree T){
    if(T != NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T){
    if(T != NULL){
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

// 二叉树的中序线索化

// 求树的深度
int treeDepth(BiTree T){
    if(T == NULL){
        return 0;
    }
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);
        return l>r ? l+1 : r+1;
    }
}


