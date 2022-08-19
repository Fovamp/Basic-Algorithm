// 时间复杂度 O(n+m)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010, M = 1010;
int n;                      // n表示点数
int h[N], e[M], ne[M], idx; // 邻接表存储图
int color[N];               // 表示每个点的颜色，-1表示未染色，0表示白色，1表示黑色

// 参数：u表示当前节点，c表示当前点的颜色
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) // 遍历所有边
    {
        int j = e[i];
        if (color[j] == -1) // 如果没有被染过颜色,就染色之后继续往下染色
        {
            if (!dfs(j, !c))
                return false;
        }
        else if (color[j] == c) // 如果出现颜色相同就返回false
            return false;
    }

    return true; // dfs结束也没有冲突就正常退出
}

bool check()
{
    memset(color, -1, sizeof color);
    bool flag = true;
    for (int i = 1; i <= n; i++) // 遍历所有的点,即所有的连通块
        if (color[i] == -1)
            if (!dfs(i, 0)) // 判断是否构成二分图,是否能正常染色
            {
                flag = false;
                break;
            }
    return flag;
}