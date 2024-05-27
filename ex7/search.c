#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 200
//二分查找，返回元素下标
int BinarySearch(int a[],int size,int key)
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int main()
{
    //定义一个数组
    int a[MAX_VERTEX_NUM];
    //从键盘输入数组元素
    int size;
    printf("Please input the size of the array:\n");
    int res = scanf("%d",&size);
    if(res != 1 || size <= 0 || size > MAX_VERTEX_NUM)
    {
        printf("Invalid input.\n");
        return 0;
    }
    int i;
    for(i=0;i<size;i++)
    {
        int res = scanf("%d",&a[i]);
        if(res != 1)
        {
            printf("Invalid input.\n");
            return 0;
        }
    }
    //从键盘输入要查找的元素
    int key;
    printf("Please input the key:\n");
    scanf("%d",&key);
    //调用二分查找函数
    int index=BinarySearch(a,size,key);
    //输出结果
    if(index==-1)
        printf("The key is not found.\n");
    else
        printf("The key is found at index %d.\n",index);
}