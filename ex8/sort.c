#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 200
// 选择排序
void SelectSort(int a[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}
// 插入排序
void InsertSort(int a[], int size)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}
// 堆排序
void HeapAdjust(int a[], int s, int m)
{
    int temp, j;
    temp = a[s];
    for (j = 2 * s + 1; j <= m; j = 2 * j + 1)
    {
        if (j < m && a[j] < a[j + 1])
            j++;
        if (temp >= a[j])
            break;
        a[s] = a[j];
        s = j;
    }
    a[s] = temp;
}
// 打印数组
void PrintArray(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// 拷贝数组
void CopyArray(int a[], int b[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        b[i] = a[i];
    }
}
int main()
{
    // 定义一个数组
    int a[MAX_VERTEX_NUM], b[MAX_VERTEX_NUM], c[MAX_VERTEX_NUM], d[MAX_VERTEX_NUM];
    // 从键盘输入数组元素
    int size;
    printf("Please input the size of the array:\n");
    int res = scanf("%d", &size);
    if (res != 1 || size > MAX_VERTEX_NUM || size <= 0)
    {
        printf("Input error!\n");
        return 0;
    }

    int i;
    for (i = 0; i < size; i++)
    {
        int res = scanf("%d", &a[i]);
        if (res != 1)
        {
            printf("Input error!\n");
            return 0;
        }
    }
    // 拷贝数组
    CopyArray(a, b, size);
    CopyArray(a, c, size);
    CopyArray(a, d, size);
    // 选择排序
    SelectSort(b, size);
    printf("The result of SelectSort:\n");
    PrintArray(b, size);
    // 插入排序
    InsertSort(c, size);
    printf("The result of InsertSort:\n");
    PrintArray(c, size);
    // 堆排序
    int k = size / 2 - 1;
    for (i = k; i >= 0; i--)
        HeapAdjust(d, i, size - 1);

    for (i = size - 1; i >= 1; i--)
    {
        int temp = d[0];
        d[0] = d[i];
        d[i] = temp;
        HeapAdjust(d, 0, i - 1);
    }
    printf("The result of HeapSort:\n");
    PrintArray(d, size);
}