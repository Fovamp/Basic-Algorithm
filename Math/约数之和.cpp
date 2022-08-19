// N = p1^c1 * p2^c2 * ... *pk^ck, p1为质数
// 如24 = 2^3 * 3^1
// 约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int main()
{

    unordered_map<int, int> primes;
    int x;
    cin >> x;

    for (int i = 2; i <= x / i; i++)
        while (x % i == 0) // 试除法分解质因数
        {
            x /= i;
            primes[i]++; // 记录质数个数
        }

    if (x > 1)
        primes[x]++; // x大于1说明x本身是质数

    LL res = 1;
    for (auto prime : primes) // 计算约数之和
    {
        int p = prime.first, a = prime.second; // p为质数,a为质数个数
        LL t = 1;
        while (a--)
            t = (t * p + 1) % MOD;
        res = (res * t) % MOD;
    }

    cout << res << endl;

    return 0;
}