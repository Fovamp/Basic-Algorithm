// 1 <= a, b <= 2000
#include <iostream>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int c[N][N];
int main()
{
    // c[a][b] 表示从a个苹果中选b个的方案数
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod; // 包含j或者不包含j
                                                                 // 选j为从i - 1中选j - 1个c[i - 1][j - 1]
                                                                 // 不选j为从i - 1中选j个c[i - 1][j]
    return 0;
}