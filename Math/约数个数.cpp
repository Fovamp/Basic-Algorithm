// N = p1^c1 * p2^c2 * ... *pk^ck, p1为质数
// 如24 = 2^3 * 3^1
// 约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;

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

    ll res = 1;
    for (auto prime : primes)                 // 计算约数之和
        res = res * (prime.second + 1) % MOD; // sum过大每次mod一个数

    cout << res << endl;

    return 0;
}