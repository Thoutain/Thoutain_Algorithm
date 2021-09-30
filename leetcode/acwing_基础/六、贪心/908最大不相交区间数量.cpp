/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。

输出可选取区间的最大数量。
*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

PII q[N];

int cmp(PII a, PII b)
{
    return a.second < b.second;
}
int main()
{
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;

    sort(q, q + n, cmp);

    int tmp = q[0].second;
    for (int i = 1; i < n; i++)
    {
        // if (tmp < q[i].first)
        // {
        //     cnt ++;
        // }
        // tmp = q[i].second;
        if (q[i].second >= tmp && q[i].first <= tmp)
            continue;
        cnt ++;
        tmp = q[i].second;
    }
    
    cout << cnt << endl;

    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l, r;
    bool operator< (const Range &W)const
    {
        return r < W.r;
    }
}range[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n);

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i ++ )
        if (range[i].l > ed)
        {
            res ++ ;
            ed = range[i].r;
        }

    printf("%d\n", res);

    return 0;
}
*/