// 时间复杂度 O(nm)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010, M = 1010;

int n, m;
int dist[N];
int backup[N];
struct Edge //记录边的结构体数组
{
    int a, b, w;
} edges[M];

int Bellman_Ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i++)
    {
        memcpy(backup, dist, sizeof dist); // 为防止每次松弛所有边的时候发生串联,就用backup数组备份上一次的dist
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > backup[a] + w) //松弛操作
                dist[b] = backup[a] + w;
        }
    }
    return dist[n];
}