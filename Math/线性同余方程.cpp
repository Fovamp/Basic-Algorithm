// 因为 a∗x≡b(mod m) 等价于 a∗x−b 是m的倍数，因此线性同余方程等价为 a∗x+m∗y=b  y = -y
// 根据 Bezout 定理，上述等式有解当且仅当 gcd(a,m)|b
// 因此先用扩展欧几里得算法求出一组整数 x0,y0 使得 a∗x0+m∗y0=gcd(a,m)
// 然后 x=x0∗b/gcd(a,m)%m 即是所求。
#include <iostream>
using namespace std;
int n, x, y;
typedef long long LL;
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y);
    int z = x;
    x = y;
    y = z - a / b * y;
    return d;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int a, b, m;
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y); // 求出最大公约数
        if (b % d)                 // b 不是 d 的倍数,一定无解
            puts("impossible");
        else
        {
            x = (LL)x * b / d % m; // 直接将x扩大b/d倍,然后MOD到m内
            cout << x << endl;
        }
    }
    return 0;
}