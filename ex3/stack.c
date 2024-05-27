#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// 栈的结构
typedef struct
{
    char data[MAX];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *stack)
{
    stack->top = -1;
}

// 检查栈是否为空
int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

// 检查栈是否满
int isFull(Stack *stack)
{
    return stack->top == MAX - 1;
}

// 入栈
void push(Stack *stack, char value)
{
    if (!isFull(stack))
    {
        stack->data[++stack->top] = value;
    }
}

// 出栈
char pop(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top--];
    }
    return '\0'; // 返回空字符表示栈为空
}

// 获取栈顶元素
char peek(Stack *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data[stack->top];
    }
    return '\0';
}

// 检查是否可以通过合法的栈操作生成目标字符串
int canGenerateSequence(char *input, char *target)
{
    Stack stack;
    initStack(&stack);

    int inputLen = strlen(input);
    int targetLen = strlen(target);
    int i = 0, j = 0;

    while (i < inputLen)
    {
        push(&stack, input[i]);
        printf("Push: %c\n", input[i]);
        i++;

        while (!isEmpty(&stack) && peek(&stack) == target[j])
        {
            char popped = pop(&stack);
            printf("Pop: %c\n", popped);
            j++;
        }
    }

    return isEmpty(&stack) && j == targetLen;
}

int main()
{
    char input[] = "abcde";
    char target[MAX];
    printf("Enter the target sequence: ");
    scanf("%s", target);
    if (canGenerateSequence(input, target))
    {
        printf("The sequence %s can be generated from %s by the given stack operations.\n", target, input);
    }
    else
    {
        printf("The sequence %s cannot be generated from %s by the given stack operations.\n", target, input);
    }

    return 0;
}