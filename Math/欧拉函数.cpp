// 1~n中与n互质的数的个数被称为欧拉函数
// 利用容斥原理
// phi[n] = n * (1 - p1) * (1 - p2) *...*(1 - pi)
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++) // 分解质因数
        if (x % i == 0)
        {
            res = res / i * (i - 1); // 不能有小数,所以就先除后乘
            while (x % i == 0)
                x /= i;
        }
    if (x > 1) // 大于1,说明x本身为质数
        res = res / x * (x - 1);

    return res;
}