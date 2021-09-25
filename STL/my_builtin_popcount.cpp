// 计算数字对应二进制中1的个数
#include <iostream>
#include <bitset>

using namespace std;

int bcount(int n) {
    bitset<32> bit(n);
    return bit.count();
}

int bcount2(int n) {
    int count = 0;
    while (n) {
        count ++;
        n = n & (n - 1);
    }
    return count;
}

// lowbit
int bcount3(int n) {
    int res = 0;
    while (n) {
        res ++;
        n -= n & (-n);
    }
    return res;
}
int main() {
    int num;
    cin >> num;
    cout << bcount(num) << endl;
    cout << bcount2(num) << endl;
    cout << bcount3(num) << endl;

    return 0;
}