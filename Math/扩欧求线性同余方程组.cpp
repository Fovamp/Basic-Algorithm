// 也叫中国剩余定理
// m1, m2, m3,....mk 两两互质,但是没说全是质数,所以要用扩欧求逆元
// Mk = m1 * m2 * m3 *...* mk
// Mi = Mk / mi
// x ≡ a1(mod m1)
// x ≡ a2(mod m2)
// x ≡ a3(mod m3)
// |
// |
// x ≡ ak(mod mk)
// x = a1 * M1 * M1^-1 + a2 * M2 * M2^-1 + ... + ak * Mk * Mk^-1 // 公式解
//     M1 * M1^-1 mod m1 = 1, 后面M中都含有m1可以整除,余数都为0,所以公式解成立
// M1^ -1 为M1的逆元用扩欧求逆元 M1 和 m1互质 gcd(M1,m1) = 1;
// M1 * x + m1 * y = 1  x 就是M1的逆元 即M1^-1

// AcWing 204 表达整数的奇怪方式
// 因为中国剩余定理要求a1,a2,…,ana1,a2,…,an两两互质，而此题并无该条件，故而只能自己推导求解方法
// 扩展中国剩余定理
// 补充：
// 两个数的乘积除以他们的最大公约数是最小公倍数
// 最大公约数就两个数的所有相同质数相乘，最小公倍数就是扣除一次所有相同的质数全部相乘，补过来刚好，所以两个数的乘积除以他们的最大公约数是最小公倍数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y) // 扩欧
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
LL inline mod(LL a, LL b) // 取模,inline节约栈空间,重复调用速度快
{
    return ((a % b) + b) % b;
}
int main() // 方法是,每次将两个同余方程合并为一个方程
{
    int n;
    cin >> n;
    LL a1, m1;
    cin >> a1 >> m1;
    for (int i = 1; i < n; i++)
    {
        LL a2, m2, k1 = 0, k2 = 0;
        cin >> a2 >> m2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d)
        {
            puts("-1");
            return 0;
        }
        k1 *= (m2 - m1) / d; // m2 - m1是d的倍数,方程左右两边都乘以倍数
        LL t = a2 / d;       // 上面得到的k1只是方程的其中一个解,k的通解为:k1 = k1 + k * a2 / d详情见扩欧最后
        k1 = mod(k1, t);     // mod a2 / d之后,k1就是最小的解了
        m1 = k1 * a1 + m1;
        a1 = a1 / d * a2;
    }
    cout << (m1 % a1 + a1) % a1 << endl;
    return 0;
}
//将k1的通解带入x = k1 * a1 + m1;
// x = k1 * a1 + m1 + k * [a1, a2] // [a1, a2] 为 a1, a2的最小公倍数即 a1 * a2 / d;
// 形同x = k1 * a1 + m1;
// k1 == k, a1 == [a1, a2], m1 == k1 * a1 + m1;
// 后面所有的方程,都必须是在第一个的基础上改变
