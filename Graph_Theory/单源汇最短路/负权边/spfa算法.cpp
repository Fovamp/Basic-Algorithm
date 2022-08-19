// 时间复杂度 平均情况下 O(m)O(m)，最坏情况下 O(nm)
// 因为每次弹出都要false的操作,让一个点的dist可以反复更新,但是Dijkstra一旦标记true就不可改变
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1010;

int dist[N];
int h[N], w[N], e[N], ne[N], idx; // 邻接表存储所有边
bool st[N];                       // 判断是否在队列中
int n;
int spfa() // 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
{
    memset(dist, 0x3f, sizeof dist);
    memset(h, -1, sizeof h);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;                         // 出队就将st变为false,意味着之后还可以访问,与Dijkstra不同的关键
        for (int i = h[t]; i != -1; i = ne[i]) // 遍历临边
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j]) // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n];
}