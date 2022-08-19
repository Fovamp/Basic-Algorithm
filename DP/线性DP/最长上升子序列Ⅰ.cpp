// acwing 最长上升子序列
// 时间复杂度 O(n^2)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;
int n;
int a[N], f[N], g[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (f[i] < f[j] + 1 && a[i] > a[j]) // 找到比a[i]大的a[j]并且经过j - 1次筛选, 得到最大的f[j] + 1
            {
                f[i] = f[j] + 1;
                g[i] = j; // 额外记录从最长序列是从哪来的
            }
    }
    int k = 1;
    for (int i = 1; i <= n; i++)
        if (f[k] < f[i]) // 找到最长序列的最后一个数的位置,并用k记录
            k = i;
    cout << f[k] << endl;
    for (int i = 0, len = f[k]; i < len; i++) // 这样输出的是逆序
    {
        cout << a[k] << endl;
        k = g[k];
    }
    return 0;
}