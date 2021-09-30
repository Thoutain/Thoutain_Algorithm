/*
给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出 ?1。

输入格式
第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。

第二行包含整数 N，表示给定区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。

如果无解，则输出 ?1。
*/

/*
    将左端点从小到大排序

    从前往后依次枚举每个空间,在所有能够覆盖start的区间中,选择右端点最大的区间,然后将start更新成右端点的最大值

    
*/

#include <iostream>
#include <algorithm>

using namespace std;


typedef pair<int, int> PII;

const int N = 100010;

int n;
int l, r;
PII q[N];

int main()
{
    int i;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;

    sort(q, q + n);

    for (i = 0; i < n; i ++)
        if (q[i].first <= l && q[i].second >= r)
            break;
    if (i == n)
        return -1;
    int tmp = i;
    for (int j = i; j < n; j++)
    {
        if (q[i+1].first > l)
            break;
    }
    if (i == n)
        return -1;
    
}


