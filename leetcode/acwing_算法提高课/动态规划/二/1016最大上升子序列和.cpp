/*
һ���������� bi���� b1<b2<��<bS ��ʱ�����ǳ���������������ġ�

���ڸ�����һ������(a1,a2,��,aN)�����ǿ��Եõ�һЩ������������(ai1,ai2,��,aiK)������1��i1<i2<��<iK��N��

���磬��������(1,7,3,5,9,4,8)��������һЩ���������У���(1,7),(3,4,8)�ȵȡ�

��Щ�������к����Ϊ18��Ϊ������(1,3,5,9)�ĺ͡�

������񣬾��Ƕ��ڸ��������У����������������к͡�

ע�⣬������������еĺͲ�һ�������ģ���������(100,1,2,3)��������������к�Ϊ100���������������Ϊ(1,2,3)��

�����ʽ
����ĵ�һ�������еĳ���N��

�ڶ��и��������е�N����������Щ������ȡֵ��Χ����0��10000(�����ظ�)��

�����ʽ
���һ����������ʾ������������к͡�

���ݷ�Χ
1��N��1000
����������
7
1 7 3 5 9 4 8
���������
18
*/

// ���

#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int N = 1010;
int q[N], f[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++)
        cin >> q[i];
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        f[i] = q[i];
        for (int j = 0; j < i; j ++)
        {
            if (q[i] > q[j])
                f[i] = max(f[i], f[j] + q[i]); 
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
}


#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int q[N], f[N];
int n;

int main(){
    
    for (int i = 0; i < n; i++)
        cin >> q[i];
    
    int res = 0;
    for (int i = 0; i < n; i ++){
        f[i] = q[i];
        for (int j = 0; j < i; j ++){
            if (q[i] > q[j])
                f[i] = max(f[i], q[i] + f[j]);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
}