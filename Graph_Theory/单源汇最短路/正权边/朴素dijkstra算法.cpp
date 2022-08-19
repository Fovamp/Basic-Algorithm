// 时间复杂度O(n2+m)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int g[N][N];
bool st[N];
int dist[N];
int n;

int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化距离所有点距离为正无穷

    dist[1] = 0; // 距离第一个点距离为0

    for (int i = 0; i < n - 1; i++) // 每次循环都加入一个距离最近的点
    {
        int t = -1;                                       // 用于第一个点的标记
        for (int j = 1; j <= n; j++)                      // 循环所有点找出距离最短的点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) // 如果是第一个点或者比现有点距离更小,并且没有被加入距离最小的点
                t = j;                                    // t记录距离最小的点

        st[t] = true; // 进行标记

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]); // 用t更新其他点的距离
    }
    return dist[n];
}