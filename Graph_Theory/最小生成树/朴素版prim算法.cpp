// 时间复杂度 O(n2+m)O(n2+m)
// 用来解决连接村庄,需要最小路径
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010, INF = 1e9 + 10;

int n;       // n表示点数
int g[N][N]; // 邻接矩阵，存储所有边
int dist[N]; // 存储其他点到当前最小生成树的距离
bool st[N];  // 存储每个点是否已经在生成树中

// 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++) // 和朴素版Dijkstra差不多
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // 找到距离集合最近的点
                t = j;

        if (i && dist[t] == INF) // 如果有点不能加入树中就返回无穷
            return INF;

        if (i)
            res += dist[t]; //将点加入树中
        st[t] = true;

        for (int j = 1; j <= n; j++) // 更新其他点
            dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}