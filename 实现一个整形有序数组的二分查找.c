#include <stdio.h>

int binary_search(int arr[], int k, int len)
{
    // �������Ҷ˵�
    int left = 0;
    int right = len - 1;

again:
    ;
    // �����е�
    int mid = (left + right)/2;

    // �Ƚ�����ֵ���е�Ĵ�С
    if (arr[mid] == k)
        return mid;

    // ��С������Χ
    else if(arr[mid] < k)
        left = mid + 1;
    else if(arr[mid] > k)
        right = mid - 1;

    //�ٴμ����е㣬���бȽϲ���С��Χ��ֱ���ѳ����Ѳ���
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
