// 朴素筛法求素数中,一个数可能会被多个素数筛掉,比如6被2和3两个素数筛掉两次
// 保证每个合数只会被它的最小质因数筛去，因此每个数只会被标记一次，所以时间复杂度是O(n)
// 也叫欧拉筛法
#include <iostream>
using namespace std;
const int N = 1010;

int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]) // 没有被标记就是素数,就加入数组
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) // 遍历所有乘以i小于n的素数primes[j] * i <= n
        {
            st[primes[j] * i] = true; // 每个合数可以用--最小素数 * 一个合数--来表示
            if (i % primes[j] == 0)   // 每个合数只能被primes[j]筛去,如果primes[j]能整除i,
                                      //那么到下一个数(primes[j + 1] * i)应该被primes[j]筛去,而不是被primes[j + 1]
                break;
        }
    }
}