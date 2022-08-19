// 也叫辗转相除法
// gcd(a,b) 和 gcd(b,a % b)相同
// 证明:
//     a = b * c + y   // y 为余数, d 为最大公约数
//     a / d = b / d * c + y / d
//     整数     整数   那么y / d也是整数
// 所以得证gcd(a,b) == gcd(b,a%b);
#include <iostream>

using namespace std;

int gcd(int a, int b) // 返回a和b的最大公约数
{
    return b ? gcd(b, a % b) : a;
}