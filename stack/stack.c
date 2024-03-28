#define STACK_INIT_SIZE 100
#include<stdio.h>
//定义一个栈的结构体
typedef struct
{
    int *base;
    int *top;
    int stacksize;
} SqStack;
//初始化栈
void InitStack(SqStack S)
{
    S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.base)
        exit(0);//存储分配失败
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}
int main()
{

}