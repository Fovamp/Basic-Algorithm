// 为什么可行?
// 2 和 3 试过之后会筛掉所有自身的倍数,比如2因子已经找完去除,那么之后的4和6就不会整除x了
#include <iostream>
using namespace std;
void divide(int x)
{
    for (int i = 2; i < x / i; i++)
        if (x % i == 0) // 找出因子
        {
            int s = 0;
            while (x % i == 0) // 在x里面一个一个除去因子i,并且记录数量s
                x /= i, s++;
            cout << i << ' ' << s << endl;
        }
    if (x > 1)
        cout << x << ' ' << 1 << endl;
    cout << endl;
}