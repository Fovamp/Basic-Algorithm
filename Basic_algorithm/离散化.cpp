#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> alls; //存储所有待离散化的值

int find(int x) //找出第一个大于等于x的位置
{
    int l = 0, r = alls.size();
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= mid)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    int x;

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去重
    // unique 的作用是将重复元素放到末尾,并且返回end(),然后再用erase删除

    find(x);
}