#include <algorithm>

using namespace std;
const int N = 1010;
int q[N];
void quick_sort(int q[], int l, int r) //时间复杂度O(nlogn)
{
    if (l >= r)
        return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1]; //以中点为分界点;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]); //交换使得一侧大于,一侧小于;
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r); //递归处理分开的小区间
}