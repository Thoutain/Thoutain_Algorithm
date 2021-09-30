/*
���� N �������� [ai,bi]��������������ѡ�����ٵĵ㣬ʹ��ÿ�����������ٰ���һ��ѡ���ĵ㡣

���ѡ��ĵ����С������

λ������˵��ϵĵ�Ҳ���������ڡ�
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


