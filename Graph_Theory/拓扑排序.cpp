// 时间复杂度O(n+m)
// 每个顶点出现且只出现一次。
// 若存在一条从顶点 A 到顶点 B 的路径，那么在序列中顶点 A 出现在顶点 B 的前面。
// 每次取出入度为0的点,并且删除这个点和与其相连的边,如果最后所有点都取完,就说明有拓扑序
#include <iostream>
using namespace std;
const int N = 1010;
int d[N], q[N];             // d用来存储每个点的入度,q则是队列存储拓扑序
int h[N], e[N], ne[N], idx; // 邻接表
int n;
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q[++tt] = i;

    while (hh <= tt)
    {
        int t = q[hh++];

        for (int i = h[t]; i != -1; i = ne[i]) // 寻找相邻的点
        {
            int j = e[i];
            if (--d[j] == 0) // 如果减一之后入度为0就把他加入队列
                q[++tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}