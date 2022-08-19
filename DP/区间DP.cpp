// acwing 石子合并
// 状态表示：f[i][j]f[i][j] 表示将 ii 到 jj 这一段石子合并成一堆的方案的集合，属性 Min
// 状态计算：
// （1） i<j 时，f[i][j]=min(f[i][k]+f[k+1][j]+s[j]−s[i−1])
// （2） i=j 时， f[i][i]=0 （合并一堆石子代价为 0）

// 问题答案： f[1][n]
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 310;
int n;
int s[N], f[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 1; i <= n; i++) // 前缀和
        s[i] += s[i - 1];

    for (int len = 2; len <= n; len++)         // 枚举所有区间长度
        for (int i = 1; i + len - 1 <= n; i++) // 所有区间起点
        {
            int l = i, r = i + len - 1;
            f[l][r] = 1e8;
            for (int k = l; k < r; k++) // 分割区间
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }

    cout << f[1][n] << endl;

    return 0;
}