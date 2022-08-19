// 状态表示:f[i][j]表示a[1~i]和b[1~j]的最长公共子序列的最大长度
// 状态计算:
// 根据最后两个字母是否相同来分类:
// a[i] == b[j]  f[i][j] = f[i - 1][j - 1] + 1;
// a[i] != b[i]  f[i][j] = max(f[i - 1][j], f[i][j - 1]);
#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
char a[N], b[N];
int f[N][N];

int main()
{
    cin >> n >> m >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}