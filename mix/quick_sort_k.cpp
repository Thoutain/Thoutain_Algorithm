#include <iostream>

using namespace std;

const int N = 100010;
int q[N];
void quick_sort(int q[],int  l,int r)
{
    if(l >= r)
        return ;
    int i = l - 1;
    int j = r + 1;
    int temp = q[i + j >> 1];
    while(i < j)
    {
        //int temp = q[i + j >> 1];Œª÷√¥Ì¡À
        
        do i++; while(q[i] < temp);
        do j--; while(q[j] > temp);
        if(i < j)
            swap(q[i], q[j]);
        quick_sort(q, l, j);
        quick_sort(q, j + 1, r);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++)
        cin >> q[i];
    quick_sort(q, 0, n - 1);
    cout << q[k - 1];
    
}