#include <iostream>
using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N]; //状态, f[i][j]表示选取i种物品, 总重量不超过j的最大价值是多少

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // 暴力三重循环
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * v[i] <= j; k++) //枚举第i个物品选1~K个的情况
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    //在k循环中, f[i, j]等于这些项中的最大值:
    //          即f[i, j] = max(f[i-1, j], f[i-1, j - v] + w, f[i-1, j - 2v] + 2w, ...) ①
    //          而f[i, j-v] = max(         f[i-1, j - v],     f[i-1, j - 2v] + 1w, ...) ②
    //将②式代入①式, 则得, f[i, j] = max(f[i-1, j], f[i, j - v] + w);
    //所以f[i, j]的值与k循环无关, 可优化为二重循环

    //替代版二重循环
    /*  for(int i = 1; i <= n; i ++)
            for(int j = 0; j <= m; j ++)
            {
                f[i][j] = f[i - 1][j];
                if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
    */

    cout << f[n][m] << endl;

    // 模仿01背包进行一维变形,不过此时不用担心前面的计算状态被污染
    // 因为每个物品是无限拿,没有01的次数限制,而且二维的时候用的就是同一层的数据
    /*
        //一维数组
        for(int i = 1; i <= n; i ++)
            for(int j = v[i]; j <= m; j ++)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        cout << f[m] << endl;
    */

    return 0;
}