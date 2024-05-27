#include <stdio.h>
#include <stdlib.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))
// 定义一个带头节点的单链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
// 初始化链表
LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}
// 向单链表加入一个元素
void InsertList(LinkList L, int x)
{
    LinkList p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = NULL;
    p->next = s;
    return;
}
// 打印单链表
void PrintList(LinkList L)
{
    LinkList p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// 计算链表中所有值为奇数的节点，并从原链表中删除这些节点
LinkList FindOdd(LinkList L)
{
    LinkList p = L->next;
    LinkList prev = L;
    LinkList newHead = InitList(); // 新链表的头节点
    LinkList tail = newHead;       // 新链表的尾节点

    while (p != NULL)
    {
        if (ABS(p->data) % 2 == 1)
        {
            // 创建一个新的节点
            LinkList newNode = (LinkList)malloc(sizeof(LNode));
            if (!newNode)
            {
                printf("Memory allocation error\n");
                exit(1);
            }
            newNode->data = p->data;
            newNode->next = NULL;

            // 将新节点添加到新链表的尾部
            tail->next = newNode;
            tail = newNode;

            // 从原链表中删除该节点
            prev->next = p->next;
            free(p);
            p = prev->next;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    return newHead;
}
int main()
{
    LinkList L = InitList();
    printf("please input the number of the list:");
    int x, y;
    scanf("%d", &x);
    printf("please input the list:\n");
    while (x--)
    {
        if (scanf("%d", &y) != 1)
        {
            printf("input error!\n");
            // 退出程序
            exit(-1);
        }
        InsertList(L, y);
    }
    printf("The original list is:\n");
    PrintList(L);
    LinkList q = FindOdd(L);
    printf("The list of even numbers is:\n");
    PrintList(q);
    printf("The list after removing the even numbers is:\n");
    PrintList(L);
    return 0;
}