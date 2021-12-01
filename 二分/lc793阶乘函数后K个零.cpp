/*
f(x) 是 x! 末尾是 0 的数量。（回想一下 x! = 1 * 2 * 3 * ... * x，且 0! = 1 ）

例如， f(3) = 0 ，因为 3! = 6 的末尾没有 0 ；而 f(11) = 2 ，因为 11!= 39916800 末端有 2 个 0 。给定 K，找出多少个非负整数 x ，能满足 f(x) = K 。

示例 1：
输入：K = 0
输出：5
解释：0!, 1!, 2!, 3!, and 4! 均符合 K = 0 的条件。

示例 2：
输入：K = 5
输出：0
解释：没有匹配到这样的 x!，符合 K = 5 的条件。
*/

// 错误版本

class Solution {
public:
    int preimageSizeFZF(int k) {
        return (b2(k) - b1(k) + 1);
    }
    int b1(int k) {
        long l = 1;
        long r = LONG_MAX;
        while (l < r) {
            long mid =  l + (r - l) / 2;
            if (f(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int b2(int k) {
        long l = 1;
        long r = LONG_MAX;
        while (l < r) {
            long mid = l + (r - l + 1) / 2;
            if (f(mid) <= k)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }

    int f(int k) {
        int res = 0;
        int base = 5;
        while (k >= base) {
            res += k / base;
            base *= 5;
        }
        return res;
    }
};
