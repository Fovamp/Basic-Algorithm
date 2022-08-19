//高精度就是模拟竖式运算
//以下的vector全部都是倒序,且均未翻转
//高精度加法
#include <vector>
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t)
        C.push_back(t);
    return C;
}
//高精度减法
vector<int> sub(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return sub(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
//高精度乘低精度
vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}
//高精度除低精度
vector<int> div(vector<int> &A, int B)
{
    vector<int> C;
    int t = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        t = t * 10 + A[i];
        C.push_back(t / B);
        t %= B;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}