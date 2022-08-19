// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
//求模式串的Next数组：
#include <iostream>
using namespace std;
const int N = 1010;
char s[N], p[N];
int ne[N]; // ne[i] 等于 p[i]之前与p[i]相同的前缀的位置
int n, m;
int main()
{
    //求next数组的目的在于减少重复操作,记忆模式串中的每一位的最长前缀和,
    for (int i = 2, j = 0; i <= m; i++) // i规定模式串的子模式串(逐渐增长至原模式串长度),然后找出其中最长的子序列
    {                                   // i遍历p,i从2开始,因为要用到ne[1]时,只能重新开始遍历,即ne[1] == 0
        while (j && p[i] != p[j + 1])   //如果不匹配,就回溯,从ne[j]重新开始匹配
            j = ne[j];
        if (p[i] == p[j + 1]) //匹配
            j++;
        ne[i] = j; //记录最长前缀和
    }

    // KMP匹配
    for (int i = 1, j = 0; i <= n; i++) // i用于遍历s,j用于遍历p
    {
        while (j && s[i] != p[j + 1]) //如果j不在p的开头并且i和j+1未匹配成功就利用最长前缀和回溯j
            j = ne[j];
        if (s[i] == p[j + 1]) //匹配成功就j++延长p字串匹配长度
            j++;
        if (j == m) //匹配成功就输出
        {
            j = ne[j];
            // 匹配成功后的逻辑
        }
    }
    return 0;
}