// 1~n中,每个欧拉函数之和,就用筛法求欧拉函数
// 在欧拉筛法框架内
// phi[n] = n * (1 - p1) * (1 - p2) *...*(1 - pi)
#include <iostream>

using namespace std;
const int N = 1010;
int primes[N], cnt; // primes[]存储所有素数
int euler[N];       // 存储每个数的欧拉函数
bool st[N];         // st[x]存储x是否被筛掉

void get_eulers(int n)
{
    euler[1] = 1; // 1与1互质
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i; // 加入质数数组
            euler[i] = i - 1;  // 质数的互质数有n - 1个
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            int t = primes[j] * i; // 以最小质数筛掉合数
            st[t] = true;
            if (i % primes[j] == 0) // primes[j]能整除i就退出
            {
                euler[t] = euler[i] * primes[j];   // 因为primes[j]能整除i,说明i和i * primes[j]的质因子都相同,欧拉函数与质因子个数无关
                break;                             // phi[i] = i * (1 - p1) * (1 - p2) *...*(1 - pk);
            }                                      // phi[i * pj] = pj * i * (1 - p1) * (1 - p2) *...*(1 - pk);
            euler[t] = euler[i] * (primes[j] - 1); // 如果primes[j]不能整除i
        }                                          // phi[i] = i * (1 - p1) * (1 - p2) *...*(1 - pk);
    }                                              // phi[i * pj] = pj * i * (1 - p1) * (1 - p2) *...*(1 - pk) * (1 - pj);
}