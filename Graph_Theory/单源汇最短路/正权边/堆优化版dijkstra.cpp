// 时间复杂度O(mlogn)
// 朴素版Dijkstra每次都要把每个点都遍历一遍,但是只有改变值得需要遍历,所以我们可以用优先队列来优化
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
const int N = 1010;

typedef pair<int, int> PII;

int h[N], w[N], e[N], ne[N], idx; // 邻接表
bool st[N];
int dist[N];
int n;

int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(h, -1, sizeof h);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap; //最小堆,前两个参数,数据类型,底层容器类型
    heap.push({0, 1});                                   //把源点放入
    while (heap.size())
    {
        auto t = heap.top(); // 取出队头
        heap.pop();

        int ver = t.y, distance = t.x; // 点的下标和距离

        if (st[ver]) // 有标记就跳过
            continue;
        st[ver] = true; // 找到最小距离就标记

        for (int i = h[ver]; i != -1; i = ne[i]) // 遍历所有临边,并且更新距离
        {
            int j = e[i];
            if (dist[j] > distance + w[i]) // 如果可以改变值就改变并且入队
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n];
}