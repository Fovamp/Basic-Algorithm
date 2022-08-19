// 1 <= a, b <= 1e5 要选择预处理
//首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
//如果取模的数是质数，可以用费马小定理求逆元
// 求C(a,b) MOD 1e9+7
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1010, mod = 1e9 + 7;
int fact[N], infact[N];
// C(a, b) = b! / (a! * (b - a)!)
int qmi(int a, int k, int p) // 快速幂模板
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// 预处理阶乘的余数和阶乘逆元的余数
int main()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}