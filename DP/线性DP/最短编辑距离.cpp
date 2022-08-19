// 状态表示: f[i][j]是A前i个字符组成的子串最少经过多少次操作可以变成B的前j个字符组成的子串
// 根据对A AA的末尾进行的最后一次操作类型来分类
// 集合计算:
//        1.删除 f[i][j] = f[i - 1][j] + 1;将A的长i − 1前缀变成B的前j个字符，再加上删除B这个操作
//        2.添加 f[i][j] = f[i][j - 1] + 1;将A的长i前缀变成B的前j − 1个字符，再在A的末尾加上b[j]的操作
//        3.修改 f[i][j] = f[i - 1][j - 1] + 1;将A的长i - 1前缀变成B的前j - 1个字符,再加上将A的末尾修改成B的末尾的操作
#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
string a, b;
int f[N][N];

int main()
{
    cin >> n >> a;
    cin >> m >> b;

    for (int i = 0; i <= m; i++)
        f[0][i] = i;
    for (int i = 0; i <= n; i++)
        f[i][0] = i;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i - 1] == b[j - 1])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    cout << f[n][m] << endl;

    return 0;
}