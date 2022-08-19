// acwing 797. 差分
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];
int n, m;

void insert(int l, int r, int c) //差分函数
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(i, i, a[i]); //在i,j处插入a[i]
    }

    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1]; //前缀和
        cout << b[i] << ' ';
    }
    return 0;
}