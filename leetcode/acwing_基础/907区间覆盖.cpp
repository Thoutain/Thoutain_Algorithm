/*
���� N �������� [ai,bi] �Լ�һ���߶����� [s,t]������ѡ�����ٵ����䣬��ָ���߶�������ȫ���ǡ�

�������������������޷���ȫ��������� ?1��

�����ʽ
��һ�а����������� s �� t����ʾ�����߶�����������˵㡣

�ڶ��а������� N����ʾ������������

������ N �У�ÿ�а����������� ai,bi����ʾһ������������˵㡣

�����ʽ
���һ����������ʾ����������������

����޽⣬����� ?1��
*/

/*
    ����˵��С��������

    ��ǰ��������ö��ÿ���ռ�,�������ܹ�����start��������,ѡ���Ҷ˵���������,Ȼ��start���³��Ҷ˵�����ֵ

    
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


