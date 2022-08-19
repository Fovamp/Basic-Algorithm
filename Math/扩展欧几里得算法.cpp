// m 为质数就用快速幂求逆元,如果m不是质数就用扩欧求逆元
// 推导：

// a 有逆元的充要条件是 a与p互质，所以 gcd(a, p) = 1

// 假设 a 的逆元为 x ，那么有 a * x ≡ 1 (mod p)

// 等价于 ax + py = 1，

// 因此后续的工作就相当于用扩展欧几里得算法求解上方的线性同余方程，并输出系数 x 即可
// 费马小定理(Fermat's little theorem)是数论中的一个重要定理，在1636年提出。如果p是一个质数，而整数a不是p的倍数，则有a^（p-1）≡1（mod p）

// 裴蜀定理:
// 有任意正整数a, b, 那么一定存在整数x, y,使得ax + by = gcd(a, b)
// ax + by = d, d一定是gcd(a,b)的倍数(d是a和b凑出来的任意数)
// 充要条件 d 必须要整除gcd(a,b)才会有解
// 求x, y，使得ax + by = gcd(a, b)
// ax + by = gcd(a, b)
// by + (a % b)x = gcd(a,b)---a % b == a - [a / b] * b(下取整)
// 整理得: ax + b(y - [a / b]x) = gcd(a,b)
int exgcd(int a, int b, int &x, int &y) // 引用直接改变x,y的值 ax + by  // x, y的初始值为0
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x); // by + (a % b)x == ax + b(y - [a / b]x) // y 和 x 交换位置 y2能直接赋值给x1
    y -= (a / b) * x;
    return d;
}
// x2 = y, y2 = x; exgcd里面交换了

// ax1 + by1 = gcd(a,b)
// ay2 + b(x2 - [a / b]y2) = gcd(a,b) = gcd(b, a % b)
// 因此 x1 = y2, y1 = x2 - a / b * y2

// ax + by 中 x 和 y 不唯一
// a(x - b / d) + b(y + a / d) = gcd(a, b);展开后结果一样
// 通解:
// x = x + b / d * k
// |
// y = y + a / d * k