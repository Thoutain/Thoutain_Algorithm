/*
N  λͬѧվ��һ�ţ�������ʦҪ�����е� (N?K) λͬѧ���У�ʹ��ʣ�µ� K λͬѧ�ųɺϳ����Ρ�?????

�ϳ�������ָ������һ�ֶ��Σ��� K λͬѧ���������α��Ϊ 1��2����K�����ǵ���߷ֱ�Ϊ T1��T2������TK��??�����ǵ�������� T1<��<Ti>Ti+1>��>TK(1��i��K)��?????

��������ǣ���֪���� N λͬѧ����ߣ�����������Ҫ��λͬѧ���У�����ʹ��ʣ�µ�ͬѧ�ųɺϳ����Ρ�

�����ʽ
����ĵ�һ����һ������ N����ʾͬѧ��������

�ڶ����� N ���������ÿո�ָ����� i ������ Ti �ǵ� i λͬѧ�����(����)��

�����ʽ
�������һ�У���һ��ֻ����һ������������������Ҫ��λͬѧ���С�

���ݷ�Χ
2��N��100,
130��Ti��230
����������
8
186 186 150 200 160 130 197 220
���������
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

ULL get(int l, int r)  // �����Ӵ� str[l ~ r] �Ĺ�ϣֵ
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
��Ŀ����
��������Ϊ N ������ a �������� a[i] Ϊ���ֵ����ߵ������ұߵݼ������������У�����Ҫɾȥ���ĸ�������Сֵ

����
�����Ѿ��ǳ������˰�
����Ҫ��һ�����������½������У���ôת�۵��ǹؼ�
���Է��֣�ת�۵�ǰ������Ҫ��������ת�۵������У�������ſ���ҲҪ������
��ô���� = ������ - ������������

����ֱ��ö��ת�۵㣬���������� LIS ������������
����
#include<bits/stdc++.h>
using namespace std;

const int N=110;

int n,ans=N;
int a[N],f[N],l[N],r[N];
//l[i] ��ʾ�� i Ϊת�۵� 0~i ���Ϻϳ����� ��ɾ������������ r ���ơ� 

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
        //i ����������point ���������� 
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