class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if (n <= 0) return false; // 4^k一定大于0  n一定大于零

        int r = sqrt(n);
        if (r * r != n) return false; // 4^k == 2^(2k) == n  平方数

        if ((1 << 30) % n != 0) return false; // 2的幂
        return true;
    }
};


