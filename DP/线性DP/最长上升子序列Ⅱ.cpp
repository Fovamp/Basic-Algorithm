#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int n, len;     // len表示b数组的长度
int find(int x) //二分查找
{
    int l = 0, r = len, mid;
    while (l <= r)
    {
        mid = (r + l) / 2;
        if (b[mid] >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b[0] = a[0];
    for (int i = 1; i < n; i++) //依次遍历a数组
    {
        if (b[len] < a[i]) //如果b最后的元素小于a元素就将a元素添加到b
        {
            b[++len] = a[i];
        }
        else //如果b最后元素大于等于a元素就找到b第一个小于a的位置然后进行替换
        {
            int j = find(a[i]);
            b[j] = a[i];
        }
    }

    cout << len + 1 << endl;
    return 0;
}