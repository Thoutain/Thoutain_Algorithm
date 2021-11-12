/*
给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。

注意：

整数除法的结果应当截去（truncate）其小数部分，例如：
    truncate(8.345) = 8以及 truncate(-2.7335) = -2
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231−1]。
本题中，如果除法结果溢出，则返回 231 − 1
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN) return -dividend;
            else return INT_MAX;
        }

        long a = dividend;
        long b = divisor;
        int flag = 1;
        if (a < 0 && b > 0 || a > 0 && b < 0) flag = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        int res = div(a, b);
        return res * flag;
    }
    
    int div(long a, long b) {
        if (a < b) return 0; // a < b结果为0
        long count = 1; // a > b说明至少为1
        long t = b; // 中间变量
        while (t + t <= a) {  // 二进制的来
            count *= 2;
            t *= 2;
        }
        return count + div(a - t, b); 递归
    }
};