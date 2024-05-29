#include <stdio.h>
// 用循环数组实现队列
// 队列的基本操作
// 1. 初始化队列
// 2. 入队
// 3. 出队
// 4. 判断队列是否为空
// 5. 判断队列是否已满
// 6. 获取队头元素
// 7. 获取队尾元素

#define MAX_SIZE 6

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue *q, int value)
{
    if ((q->rear + 1) % MAX_SIZE == q->front)
    {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int dequeue(Queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return value;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

int getFront(Queue *q)
{
    return q->data[q->front];
}

int getRear(Queue *q)
{
    return q->data[(q->rear - 1 + MAX_SIZE) % MAX_SIZE];
}

int main()
{
    // 从键盘读取数据，入队，出队，打印队列
    Queue q;
    initQueue(&q);
    printf("Please input operation: ");
    char op;
    while (1)
    {
        op = getchar();
        if ('0' <= op && op <= '9')
        {
            if (isFull(&q))
            {
                printf("Queue is full\n");
            }
            else
            {
                enqueue(&q, op - '0');
                printf("Enqueue: %d\n", op - '0');
            }
        }
        else if ('a' <= op && op <= 'z')
        {
            if (isEmpty(&q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Dequeue: %d\n", dequeue(&q));
            }
        }
        else
        {
            break;
        }
    }
    printf("Queue: ");
    for (int i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", q.data[i]);
    }
}
