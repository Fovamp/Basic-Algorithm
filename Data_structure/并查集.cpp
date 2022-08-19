#include <iostream>
using namespace std;
const int N = 1010;
int p[N], sz[N];
int n, a, b;
// p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

// 返回x的祖宗节点
int find(int x)
{
    if (p[x] != x) //采用了路径压缩
    {
        p[x] = find(p[x]); //需要维护到祖宗节点距离的就将这个拆开,加入记录距离的数组
    }
    return p[x];
}

int main()
{
    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }

    // 合并a和b所在的两个集合：
    sz[find(b)] += sz[find(a)];
    p[find(a)] = find(b);
    return 0;
}