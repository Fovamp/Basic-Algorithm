//(1) 拉链法
#include <iostream>
using namespace std;
const int N = 1010;

int h[N], e[N], ne[N], idx;

// 向哈希表中插入一个数
void insert(int x) //数值过大就取余,余数相同就用头插法,把相同的数接到一起
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

// 在哈希表中查询某个数是否存在
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) //单链表遍历一遍
        if (e[i] == x)
            return true;

    return false;
}

//(2) 开放寻址法
int h[N];

// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find_2(int x) //第二种哈希,默认取余不会有重复,如果有重复(即空位被占了)就往后寻找空的位置
{
    int t = (x % N + N) % N;
    while (h[t] != 0 && h[t] != x)
    {
        t++;
        if (t == N)
            t = 0;
    }
    return t;
}