#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII; // first存储区间开头,second存储区间结尾
const int INF = 1e9;
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end()); //根据start排序

    int st = -INF, ed = -INF;
    for (auto seg : segs) //遍历
    {
        if (ed < seg.first) //比较两个区间是否有交集
        {
            if (ed != -INF)
                res.push_back({st, ed});     //把区间加入res
            st = seg.first, ed = seg.second; //更新开头和结尾
        }
        else
            ed = max(ed, seg.second); //有交集就只更新ed
    }

    if (st != -INF) //防止输入数组为空,将最后一个区间加入数组res
        res.push_back({st, ed});

    segs = res;
}