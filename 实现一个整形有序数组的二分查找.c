#include <stdio.h>

int binary_search(int arr[], int k, int len)
{
    // 创建左、右端点
    int left = 0;
    int right = len - 1;

again:
    ;
    // 计算中点
    int mid = (left + right)/2;

    // 比较所求值与中点的大小
    if (arr[mid] == k)
        return mid;

    // 缩小搜索范围
    else if(arr[mid] < k)
        left = mid + 1;
    else if(arr[mid] > k)
        right = mid - 1;

    //再次计算中点，进行比较并缩小范围，直至搜出或搜不到
    if (left <= right)
        goto again;
    return -1;
}

int main()
{
    int arr[] = {1,3,4,5,6,8,9,11,12,14,15};
    int len = sizeof(arr)/sizeof(arr[0]);
    int m = binary_search(arr,3,len);
    printf("%d",m);
    return 0;
}
