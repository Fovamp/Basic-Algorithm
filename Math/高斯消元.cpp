// a[N][N]是增广矩阵
// 算法步骤:
// 1.找到本列绝对值最大的这一行,然后交换到当前行
// 2.将改行第一个变成1,方程左右两边都乘
// 3.把下面所有行的当前列消为0(加减乘除第一行的每一列数)
#include <cmath>
using namespace std;
const int N = 1010, eps = 1e-5;
int a[N][N];
int n;
int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;                  // 记录当前计算到哪一行
        for (int i = r; i < n; i++) // 找到绝对值最大的行
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps)
            continue;

        for (int i = c; i <= n; i++)
            swap(a[t][i], a[r][i]); // 将绝对值最大的行换到最顶端
        for (int i = n; i >= c; i--)
            a[r][i] /= a[r][c];         // 将当前行的首位变成1,最后更新第一个数
        for (int i = r + 1; i < n; i++) // 用当前行将下面所有的列消成0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j--)
                    a[i][j] -= a[r][j] * a[i][c];

        r++;
    }

    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps)
                return 2; // 无解
        return 1;         // 有无穷多组解
    }

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // 有唯一解
}