// 也叫埃式筛法
#include <iostream>
using namespace std;
const int N = 1010;
int primes[N], cnt; // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n) // 每次筛掉当前素数的倍数
{
    for (int i = 2; i <= n; i++)
    {
        if (st[i]) // 如果已经被筛就跳过
            continue;
        primes[cnt++] = i;                  // 加入素数数组
        for (int j = i + i; j <= n; j += i) // 每次向后加i
            st[j] = true;
    }
}