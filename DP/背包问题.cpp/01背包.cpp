#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N]; // f[i][j]表示选取i件物品, 总重量不超过j的最大价值是多少

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    //枚举物品个数i和装的重量j
    //当枚举到i时, 有两种选择, A:i不放进背包, 即f[i][j] = f[i- 1][j]; B:i放进背包, 此时要判断是否放得下
    // i 等于0时即不放一件物品,价值默认为0
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j]; // 不放第i件物品
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            // B情况中, 如果此时枚举的j可放入第i个物品, 则判断不放i和放i的价值谁更大
        }

    cout << f[n][m] << endl;

    //一维优化版
    /*  for(int i = 1; i <= n; i ++)
            for(int j = m; j >= v[i]; j --)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        cout << f[m] << endl;
    */
    return 0;
}
// 二维的背包只会用到上一层的数据,所以可以用一维滚动数组来维护数据
// 为什么一维情况下枚举背包容量需要逆序？
// 在二维情况下，状态f[i][j]是由上一轮i - 1的状态得来的，f[i][j]与f[i - 1][j]是独立的。
// 而优化到一维后，如果我们还是正序，则有f[较小体积]更新到f[较大体积]，则有可能本应该用第i-1轮的状态却用的是第i轮的状态。
// 一维情况正序更新状态f[j]需要用到前面计算的状态已经被「污染」，逆序则不会有这样的问题。