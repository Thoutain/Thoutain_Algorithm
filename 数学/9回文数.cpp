class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long t = x;
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res == t)
            return true;
        return false;
    }
};
// 注意反转的时候结果可能超出int可以表示的范围