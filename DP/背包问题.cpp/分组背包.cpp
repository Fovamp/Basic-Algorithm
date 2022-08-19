#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], f[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) // n组物体
    {
        int s;
        cin >> s;
        for (int i = 0; i < s; i++)
            cin >> v[i] >> w[i];
        for (int j = m; j >= 0; j--)    // 一维背包
            for (int k = 0; k < s; k++) // 和01背包问题一模一样,不过在10里面还有进行s次决策
                if (j >= v[k])
                    f[j] = max(f[j], f[j - v[k]] + w[k]);
    }
    cout << f[m] << endl;
    return 0;
}