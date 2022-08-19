// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int h[N], size;
int n;

void down(int u) //传入的是下标
{
    int t = u;
    if (u * 2 <= ::size && h[u * 2] < h[t]) //域操作符是为了当存在具有相同名称的局部变量时,要访问全局变量
        t = u * 2;
    if (u * 2 + 1 <= ::size && h[u * 2 + 1] < h[t]) // t用来记录三个数中最小的的值的下标
        t = u * 2 + 1;
    if (u != t) //如果最小的不是本身就进行交换操作
    {
        swap(h[u], h[t]); //如果要进行其他标记和记录,就改变这里的函数,要记录第几个插入就是每次的堆大小size
        down(t);          //继续下沉,如果找到属于自己的位置,那么if就不会进入,函数自动停止
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2]) //如果这个结点比上面的结点小,则这个结点向上走
    {
        swap(h[u], h[u / 2]);
        u >>= 1;
    }
}

// O(n)建堆
int main()
{
    for (int i = n / 2; i; i--) //最后一行不需要操作
        down(i);
    return 0;
}