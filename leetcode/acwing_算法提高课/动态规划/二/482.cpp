/*
N  位同学站成一排，音乐老师要请其中的 (N?K) 位同学出列，使得剩下的 K 位同学排成合唱队形。?????

合唱队形是指这样的一种队形：设 K 位同学从左到右依次编号为 1，2…，K，他们的身高分别为 T1，T2，…，TK，??则他们的身高满足 T1<…<Ti>Ti+1>…>TK(1≤i≤K)。?????

你的任务是，已知所有 N 位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

输入格式
输入的第一行是一个整数 N，表示同学的总数。

第二行有 N 个整数，用空格分隔，第 i 个整数 Ti 是第 i 位同学的身高(厘米)。

输出格式
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

数据范围
2≤N≤100,
130≤Ti≤230
输入样例：
8
186 186 150 200 160 130 197 220
输出样例：
4
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;

const int N = 100010, M = 110, P = 131;

int n, m;
ULL h[N], p[N];
int width[M];
ULL g[M];
bool st[M];
int ans[M];

ULL get(int l, int r)  // 计算子串 str[l ~ r] 的哈希值
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool dfs(int u, int end)
{
    if (end == n) return true;

    for (int i = 1; i <= m; i ++ )
        if (!st[i] && g[i] == get(end, end + width[i] - 1))
        {
            st[i] = true;
            ans[u] = i;
            if (dfs(u + 1, end + width[i] - 1)) return true;
            st[i] = false;
        }
    return false;
}

int main()
{
    scanf("%d", &n);
    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + x + 1;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ )
    {
        scanf("%d", &width[i]);
        for (int j = 0; j < width[i]; j ++ )
        {
            int x;
            scanf("%d", &x);
            g[i] = g[i] * P + x + 1;
        }
    }

    dfs(1, 1);
    for (int i = 1; i <= m; i ++ )
    {
        printf("%d", ans[i]);
        if (i != m) printf(" ");
    }

    return 0;
}

/*
题目大意
给定长度为 N 的序列 a ，求构造以 a[i] 为最大值，左边递增，右边递减，这样的序列，所需要删去数的个数的最小值

分析
题意已经非常明显了吧
我们要求一个先上升后下降的序列，那么转折点是关键
可以发现，转折点前的序列要求上升，转折点后的序列（如果反着看）也要求上升
那么所求 = 总人数 - 上升序列人数

所以直接枚举转折点，正反跑两遍 LIS 不就完事了吗
代码
#include<bits/stdc++.h>
using namespace std;

const int N=110;

int n,ans=N;
int a[N],f[N],l[N],r[N];
//l[i] 表示以 i 为转折点 0~i 符合合唱队形 所删的最少人数。 r 类似。 

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;++i) scanf("%d",&a[i]); 

    f[1]=a[1];
    int point=1;

    for(int i=2;i<=n;++i)
    {
        if(a[i]>f[point]) f[++point]=a[i];
        else
        {
            int x=lower_bound(f+1,f+point+1,a[i])-f;
            f[x]=a[i];
        }
        l[i]=i-point;
        //i 是总人数，point 是升序人数 
    }

    memset(f,0,sizeof(f));
    f[1]=a[n];
    point=1;

    for(int i=n-1;i>=1;--i)
    {
        if(a[i]>f[point]) f[++point]=a[i];
        else
        {
            int x=lower_bound(f+1,f+point+1,a[i])-f;
            f[x]=a[i];
        }
        r[i]=n-i+1-point;
    }

    for(int i=1;i<=n;i++) ans=min(ans,l[i]+r[i]);

    printf("%d",ans);

    return 0;
}
*/