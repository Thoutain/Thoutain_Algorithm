#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 125;
    long base = 5;
        int  res = 0;
        while (n > base) { // 取等
            cout << base << endl;
            res += (n / base);
            base *= 5;
        }
    cout << res << endl;
}