// Trie树,快速存储和查询数组
#include <iostream>
using namespace std;
const int N = 1010;
int son[N][26], cnt[N], idx; // idx为当前最长节点
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) //如果当前节点不存在(即未有字符串走过),就idx++创建出来
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++; //以p结点结尾的字符串数+1
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u]) //没有字符串走过就肯定匹配不成功,直接return
            return 0;
        p = son[p][u]; //存在就继续向里寻找
    }
    return cnt[p];
}