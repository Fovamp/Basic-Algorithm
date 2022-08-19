#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;                 // 用来存答案所有约数
    for (int i = 1; i <= x / i; i++) // 约数是成对的,所以只需要最大找到i * i <= n的i就行
    {
        if (x % i == 0) // 如果i能整除x
        {
            res.push_back(i); // 就把i加入答案中
            if (i != x / i)   // 如果x不是i的平方,就把另一个约数加入答案中
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}