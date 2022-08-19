//单调栈
// acwing 131. 直方图中最大的矩形
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int h[N], l[N], r[N];
int q[N];
int n;
int main()
{
    while (cin >> n, n) //逗号运算符,返回值是逗号后面的那个数
    {
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        h[0] = h[n + 1] = -1; //初始化0和n+1的位置为-1,防止模拟栈为空,导致越界

        q[0] = 0; //初始化栈顶
        int tt = 0;
        for (int i = 1; i <= n; i++)
        {
            while (h[q[tt]] >= h[i])
                tt--;
            l[i] = q[tt];
            q[++tt] = i;
        }

        tt = 0;       //重新覆盖之前的栈元素
        q[0] = n + 1; //初始化栈顶
        for (int i = n; i >= 1; i--)
        {
            while (h[q[tt]] >= h[i])
                tt--;
            r[i] = q[tt];
            q[++tt] = i;
        }
        LL res = 0;
        for (int i = 1; i <= n; i++)
            res = max(res, (LL)h[i] * (r[i] - l[i] - 1));
        cout << res << endl;
    }
    return 0;
}