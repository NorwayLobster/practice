#include<iostream>
using namespace std;

/*
 *    基数排序 时间复杂度O(n) 空间复杂度O(r)
 *    当exp=1表示按照个位对数组a进行排序
 *    ...
 */
void radixSort(int a[], int n, int exp)
{
    int output[n];             // 存储被排序数据的临时数组
    int i, buckets[10] = {0};

    // 将数据出现的次数存储在buckets[]中
    for (i = 0; i < n; i++)
        buckets[(a[i] / exp) % 10]++;

    // 使更改后的buckets[i]的值对应该数据在output[]中的位置
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];

    // 将数据存储到临时数组output[]中
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[(a[i] / exp) % 10] - 1] = a[i];
        buckets[(a[i] / exp) % 10]--;
    }

    // 将排序好的数据赋值给a[]
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int i;
    int K[] = {0, 1, 0, 4, 8, 2};
    int len = (sizeof(K)) / (sizeof(K[0]));// a的长度

    radixSort(K, len, 1);// 基数排序

    cout << "After Sort:" << endl;
    for (i = 0; i < len; i++)
        cout << K[i] << " ";
    cout << endl;

    return 0;
}
