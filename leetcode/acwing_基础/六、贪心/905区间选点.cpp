/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。

输出选择的点的最小数量。

位于区间端点上的点也算作区间内。
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 10010;

int cmp(PII a, PII b)
{
    return a.second < b.second;
}
PII p[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p, p + n, cmp);

    cout << "--------------------" << endl;

    //for (int i = 0; i < n; i++)
        //cout << p[i].first << " " << p[i].second << endl;

    int cnt = 1;
    int tmp = p[0].second;

    for (int i = 1; i < n; i++)
    {
        if (p[i].second >= tmp && p[i].first <= tmp)
            continue;
        cnt ++;
        tmp = p[i].second;
    }

    cout << cnt << endl;

    return 0;
}


