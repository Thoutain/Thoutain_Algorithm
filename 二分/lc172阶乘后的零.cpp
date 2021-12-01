/*
给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1
*/
class Solution {
public:
    int trailingZeroes(int n) {
        long base = 5;
        int  res = 0;
        while (n >= base) {
            cout << base << endl;
            res += (n / base);
            base *= 5;
        }
        return res;
    }
};
