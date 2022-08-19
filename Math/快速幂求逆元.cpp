// 乘法逆元的定义
// 若整数b，m互质，并且对于任意的整数 a，如果满足b|a，则存在一个整数x，使得a/b≡a∗x(mod m)，则称x为b的模m乘法逆元，记为b^−1(mod m)。
// b存在乘法逆元的充要条件是b与模数m互质。当模数m为质数时，b^m−2即为b的乘法逆元。
// a / b ≡ a * x(mod m) ==  b * a / b ≡ a * b * x (mod m) ==  a ≡ a * b * x(mod m)
// 即 b * x ≡ 1 (mod m)
// 由费马小定理可得 x = b ^ m - 2 (b 和 m 互质)
// 费马小定理 b 和 m 互质 那么 b ^ m-1 ≡ 1 (mod m)(m >= 2)
// b 和 m 不互质一定无解
// m 为质数就用快速幂求逆元,如果m不是质数就用扩欧求逆元
// 费马小定理(Fermat's little theorem)是数论中的一个重要定理，在1636年提出。如果p是一个质数，而整数a不是p的倍数，则有a^（p-1）≡1（mod p）
#include <iostream>
using namespace std;

const int MOD = 1e9 + 10;
int qmi(int a, int b) // 和快速幂代码一样
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