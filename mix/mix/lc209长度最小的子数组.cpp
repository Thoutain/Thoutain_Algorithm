/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for (int i = 1; i < nums.size(); i ++)
            nums[i] += nums[i - 1];

        int res = nums.size() + 1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] >= target) {
                res = min(i + 1, res);
            }
            for (int j = i - 1; j >= 0; j --) {
                if (nums[i] - nums[j] >= target) {
                    res = min(res, i - j);
                    break;
                }
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};