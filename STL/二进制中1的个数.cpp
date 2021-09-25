// __builtin_popcount()返回一个数的二进制位数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};