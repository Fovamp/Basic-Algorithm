// 时间复杂度 O(nm)
// 可以用来求二分图的最大匹配数量
// y总的男女配对法
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010, M = 1010;
int n1, n2;                 // n1表示第一个集合中的点数，n2表示第二个集合中的点数
int h[N], e[M], ne[M], idx; // 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集合的边，所以这里只用存一个方向的边
int match[N];               // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
bool st[N];                 // 表示第二个集合中的每个点是否已经被遍历过

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;                        // 这里的标记是用于,如果两个n1的点抢一个n2的点,找下家的时候要跳过
            if (match[j] == 0 || find(match[j])) // 这个女生没有男友,或者男友有下家,那么现在的女友就和这个男生好了,而前男友和另一个女生好
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

// 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
int main()
{
    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st); // 每次要重置所有标记
        if (find(i))
            res++; // res为最大配对数
    }
    return 0;
}