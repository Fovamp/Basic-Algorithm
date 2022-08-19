// 核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
// 小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果
// 不能把某一个字符映射成0,不然会有不同的字符串有相同的映射值,如A和AA
// 可以用来判断一个字符串中,两个子字符串是否相同
#include <iostream>
using namespace std;
const int N = 1010;
typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64
char str[N];
int P = 13331, n;
// 初始化
int main()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    return 0;
}
// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r) //左边是高位,右边是低位
{
    return h[r] - h[l - 1] * p[r - l + 1]; //相当于123456 - 123 * 1000 = 456
}