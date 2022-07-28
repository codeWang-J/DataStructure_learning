### 串
##### 串的定义：
    串，即字符串是由零个或多个字符组成的有限序列。一般记为S = "a1a2a3a4a5"
##### 串的基本操作
    StrAssign(&T, cahrs): 赋值操作。把串T赋值为chars
    StrCopy(&T,S):复制操作。由串s复制到串T。 
    strEmpty(S): 判空操作
    Strlength(S): 返回长度
    ClearString(&S): 清空操作
    DestroyString(&S): 销毁串
    Concat(&T, S1,S2): 串连接
    SubString(&Sub, SSting, int pos, int len): 求子串