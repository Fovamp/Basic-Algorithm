#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
分情况讨论：
abc d efg 中 x 出现的次数
1 最高位取 001 - abc - 1 时, d = x, 000 - 999
2.最高位取 abc
    2.1 d < x  无解：0
    2.2 d = x  000 - efg  总共 efg + 1种
    2.3 d > x  000 - 999  总共 1000   种
*/

int get(vector<int> num, int l, int r)
{
    int res = 0;
    // n = 1234  num 4 3 2 1
    // 注意因为 num 是倒序存储的各位数字，所以相当于是从后往前加
    for (int i = l; i >= r; i--)
        res = res * 10 + num[i];
    return res;
}

// 计算出 10 ^ x
int power10(int x)
{
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

int count(int n, int x)
{
    if (!n)
        return 0;
    // 用 vector 来倒序存储 n 例如 1423 存储的顺序是 3 2 4 1
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    // n 用来表示位数
    n = num.size();

    int res = 0;
    // 从最高位 n - 1 开始判断，但是如果要判断的数是 0 的话，因为没有前导零，所以从第二位开始判断
    for (int i = n - 1 - !x; i >= 0; i--)
    {
        //判断当前位之前的情况，所以前置条件是当前判断位不能是最高位
        if (i < n - 1)
        {
            // 第 1 种情况
            res += get(num, n - 1, i + 1) * power10(i);
            // 特殊情况当 x = 0 时，不能有连续前导0，所以要去除 000 的情况
            if (!x)
                res -= power10(i);
        }
        // 2.1 种情况无解已经省略
        // 2.2 d == x
        if (num[i] == x)
            res += get(num, i - 1, 0) + 1;
        // 2.3 d > x
        else if (num[i] > x)
            res += power10(i);
    }

    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        if (a > b)
            swap(a, b);

        for (int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }

    return 0;
}