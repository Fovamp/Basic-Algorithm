// acwing 154. 滑动窗口
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N], q[N];
int main()
{
    int n, k;
    cin >> n >> k;
    int hh = 0, tt = -1; //队头队尾
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        if (i - k + 1 > q[hh]) //判断队头是否已经出了窗口,如果是就hh ++
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) //元素没有出队并且队尾元素大于即将入队的元素
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    cout << endl;
    hh = 0, tt = -1; //同上
    for (int i = 0; i < n; i++)
    {
        if (i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << ' ';
    }
    return 0;
}