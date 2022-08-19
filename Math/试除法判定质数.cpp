bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++) // x / i * i = x-----i < x / i找出因数i如果在x / i中找不到,说明x为质数
        if (x % i == 0)
            return false;
    return true;
}