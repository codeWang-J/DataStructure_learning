#include <stdio.h>
#include <stdlib.h>
#define Elemtype char
#define Maxsize 10

typedef struct {
    Elemtype data[Maxsize];
    int top;
}SqlStack;

//栈的初始化
void InitStack(SqlStack &S){
    S.top = -1;    //初始化栈顶指针
}

//判空操作
bool IsEmpty(SqlStack S){
    if(S.top == -1) {
        return true;
    }
    else return false;
}

//新元素入栈
bool Push(SqlStack &S, Elemtype e){
    if (S.top == Maxsize-1) 
        return false;  //栈是满的，报错
    S.top = S.top + 1;
    S.data[S.top] = e;
    return true;
}

//出栈操作
bool Pop(SqlStack &S, Elemtype &e){
    if(S.top == -1)
        return false;
    e = S.data[S.top];
    S.top--;
    return true;    
}

//读取栈顶元素
bool GetTop(SqlStack S, Elemtype &e){
    if(S.top == -1) return false;
    e = S.data[S.top];
    return true;
}

// 栈的应用-->括号匹配
bool bracketChack(char str[], int length){
    SqlStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);

        else{
            if (IsEmpty(S)) 
                return false;

            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;            
            if (str[i] == '}' && topElem != '{')
                return false;        
            }
    }
    return IsEmpty(S);   
}

int main(){
    char str[9] ="(((())))";
    bool a;
    a = bracketChack(str, 8);
    if(a) printf("匹配成功！");
    return 0;
}
