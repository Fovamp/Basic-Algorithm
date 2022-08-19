// 求 m^k mod p，时间复杂度 O(logk)
#include <iostream>
using namespace std;

const int MOD = 1e9 + 10;
int qmi(int a, int b)
{
    int res = 1 % MOD;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}