#include <iostream>
using namespace std;

const int N =1010;

int q[N];

void quick_sort(int q[], int l, int r) {
    if (l >= r) return;
    int i = l - 1;
    int j = r + 1;
    int t = q[(l + r) >> 1];
    while (i < j) {
        do i ++; while(t > q[i]);
        do j --; while(t < q[j]);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l , j);
    quick_sort(q, j + 1, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i ++) {
        i && cout << " ";
        cout << q[i]; 
    }
    return 0;
}
