/*
���� N �������� [ai,bi]�����㽫��Щ����ֳ������飬ʹ��ÿ���ڲ�����������֮�䣨�����˵㣩û�н�������ʹ������������С��

�����С������

�����ʽ
��һ�а������� N����ʾ��������

������ N �У�ÿ�а����������� ai,bi����ʾһ������������˵㡣

�����ʽ
���һ����������ʾ��С������
*/

// ���������䰴��˵��С��������
// ��ǰ������ÿ������
    // �ж��ܷ���ŵ�ĳ�����е�����

// �ɲ����Զ���һ��vector������ÿ�������Ҷ˵�ֵ 

/*
   ��ʱ����������������������  ͨ�� 7/11
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
����Ԥ��
�״�...
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





