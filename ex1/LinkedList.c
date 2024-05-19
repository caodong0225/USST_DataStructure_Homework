#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct Node {
    int data;
    struct Node* next;
};

// 初始化链表
struct Node* initList() {
    return NULL;
}

// 向链表中插入元素
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// 打印链表
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// 将链表B的元素按顺序插入到链表A中
void mergeLists(struct Node** headA, struct Node* headB) {
    struct Node* currentA = *headA;
    struct Node* currentB = headB;
    struct Node* prevA = NULL;

    // 如果链表A为空，则直接将链表B接到链表A的末尾
    if (*headA == NULL) {
        *headA = headB;
        return;
    }

    // 找到链表A中第一个比链表B首节点大的节点的前一个节点
    while (currentA != NULL && currentB != NULL) {
        if (currentB->data < currentA->data) {
            if (prevA == NULL) {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    printf("Memory allocation failed.\n");
                    exit(1);
                }
                newNode->data = currentB->data;
                newNode->next = currentA;
                *headA = newNode;
                prevA = newNode;
            } else {
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                    printf("Memory allocation failed.\n");
                    exit(1);
                }
                newNode->data = currentB->data;
                newNode->next = currentA;
                prevA->next = newNode;
                prevA = newNode;
            }
            currentB = currentB->next;
        } else if (currentB->data > currentA->data) {
            prevA = currentA;
            currentA = currentA->next;
        }
        else {
            prevA = currentA;
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }

    // 如果链表B还有剩余节点，则将剩余节点直接连接到链表A的末尾
    if (currentB != NULL) {
        prevA->next = currentB;
    }
}



int main() {
    struct Node* headA = initList();
    struct Node* headB = initList();

    headA = insertNode(headA, 1);
    headA = insertNode(headA, 5);
    headA = insertNode(headA, 8);
    headA = insertNode(headA, 14);
    headA = insertNode(headA, 23);

    headB = insertNode(headB, 2);
    headB = insertNode(headB, 6);
    headB = insertNode(headB, 10);
    headB = insertNode(headB, 14);

    printf("Linked ListA: ");
    printList(headA);
    
    printf("\nLinked ListB: ");
    printList(headB);

    mergeLists(&headA, headB); // 注意传递headA的地址

    printf("\nMerged Linked List: ");
    printList(headA);

    return 0;
}
