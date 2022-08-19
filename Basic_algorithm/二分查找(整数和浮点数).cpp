//整数二分
bool check()
{
    //根据题目给的单调性质写出check函数
}
int bsearch_1(int l, int r) //[l, r]区间分为[l, mid]&[mid + 1, r]
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check())
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int bsearch_2(int l, int r) //[l, r]区间分为[l, mid - 1]&[mid, r]
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check())
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}

//浮点数二分
bool check(double x)
{
    //题目给出的某种性质
}

double bsearch_3(double l, double r)
{
    const double eps = 1e-6; // eps 表示精度，一般都是小数点后6位
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}