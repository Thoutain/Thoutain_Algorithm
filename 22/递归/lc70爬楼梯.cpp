#include <iostream>

using namespace std;

int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs2(int n) { // 快一些
    int p = 0;
    int q = 1;
    while (n --) {
        int t = p + q;
        p = q;
        q = t;
    }

    return q;
}

int main() {
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    cout << climbStairs2(n) << endl;

    return 0;
}