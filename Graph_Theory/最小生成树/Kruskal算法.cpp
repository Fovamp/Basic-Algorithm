// 时间复杂度 O(mlogm)
// 处理无向图,有向图有重边感觉不行,但是也没必要有重边
// 将所有边排序,然后用并查集从小到大将所有边连到一起
// 自环,负权边都可以用
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010, M = 100, INF = 1e8 + 10;
int n, m; // n是点数，m是边数
int p[N]; // 并查集的父节点数组

struct Edge // 存储边
{
    int a, b, w;

    bool operator<(const Edge &W) const // 重载
    {
        return w < W.w;
    }
} edges[M];

int find(int x) // 并查集核心操作
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m); // 将所有边的权重按从小到大排序

    for (int i = 1; i <= n; i++)
        p[i] = i; // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b) // 如果两个连通块不连通，则将这两个连通块合并
        {
            p[a] = b;
            res += w;
            cnt++; // 记录加了多少条边
        }
    }

    if (cnt < n - 1) // 如果边数小于点数就说有还有点不在树中,就返回无穷
        return INF;
    return res;
}