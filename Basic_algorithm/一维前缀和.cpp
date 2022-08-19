// acwing 795. 前缀和 一维前缀和
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int s[N], num[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];

        s[i] = s[i - 1] + num[i]; //前缀和
    }

    while (m--)
    {
        int l, r;

        cin >> l >> r;

        cout << s[r] - s[l - 1] << endl; //计算
    }
    return 0;
}
