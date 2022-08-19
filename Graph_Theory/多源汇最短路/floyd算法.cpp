// 时间复杂度 o(n^3)
// 可以存在负权边，但不能存在负权回路
// 基于动态规划
#include <iostream>

using namespace std;

const int N = 1010, INF = 1e9 + 10;
int d[N][N];
int n;
// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k++) // k 作为 i 和 j 的中间点
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int main()
{
    //初始化：
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
    floyd();
    return 0;
}