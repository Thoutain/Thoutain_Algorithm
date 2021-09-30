/*
给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。
*/

// 将所有区间按左端点从小到大排序
// 从前往后处理每个区间
    // 判断能否将其放到某个现有的组中

// 可不可以定义一个vector用来存每个组最右端的值 

/*
   超时？？？？？？？？？？？  通过 7/11
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

PII q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    
    sort(q, q + n);

    //for (int i = 0; i < n; i++)
      //  cout << q[i].first << "--" << q[i].second << endl;;

    vector<int> vec;
    vec.push_back(q[0].second);

    for (int i = 1; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < vec.size(); j++)
        {
            if (q[i].first > vec[j])
            {
                vec[j] = q[i].second;
                flag = 0;
                break;
            }
        }
        if (flag ==1)
            vec.push_back(q[i].second);
        
    }

    cout << vec.size() << endl;

    return 0;
}
畜栏预订
雷达...
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

PII q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].first >> q[i].second;
    }
}





