#include "tree.h"

BiTNode *p;          // 指向当前的结点
BiTNode *pre = NULL; // 指向当前访问节点的前驱
BiTNode *final = NULL; // 用于记录最终结果

void visit(BiTNode *q){
    if (p == q)
        final = pre;
    else
        pre = q;
}

void FindPre(BiTree T){
    if (T != NULL){
        FindPre(T->lchild);
        visit(T);
        FindPre(T->rchild);
    }
}