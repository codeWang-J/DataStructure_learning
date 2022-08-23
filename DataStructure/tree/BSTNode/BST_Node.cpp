#include <stdio.h>
#include <stdlib.h>

// 二叉排序树结点
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
}BSTNode,*BSTree;

//二叉排序树的查找
BSTNode *BST_Search(BSTree T, int key){
    while (T != NULL && key != T->key)
    {
        if (T->key > key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
    
}

//而成排序树的插入
int BST_Insert(BSTree &T, int key){
    if (T == NULL)
    {
        T = (BSTree)malloc(sizeof(BSTNode));// 树为空树，新插入的节点为根节点
        T->key = key;
        T->lchild = NULL;
        T->rchild = NULL;
        return 1;
    }

    else if (T->key == key)  // 书中存在相同的结点插入失败
        return 0;
    
    else if (T->key > key)
        return BST_Insert(T->lchild, key);

    else
        return BST_Insert(T->rchild, key);
}

//按照str[]中的关键字建立二叉排序树
int CreatBSTree(BSTree &T, int str[], int n){// n为数组的长度
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
    
    return 1;
}