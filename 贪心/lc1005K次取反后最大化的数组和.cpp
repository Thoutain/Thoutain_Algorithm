/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

示例 1：
输入：nums = [4,2,3], k = 1
输出：5
解释：选择下标 1 ，nums 变为 [4,-2,3] 。

示例 2：
输入：nums = [3,-1,0,2], k = 3
输出：6
解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。

示例 3：
输入：nums = [2,-3,-1,5,-4], k = 2
输出：13
解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
*/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = 0;
        while (index < nums.size()) {
            if (nums[index] < 0) index ++;
            else break;
        }

        int res = 0;
        for (int v : nums) res += v;
        if (index == 0) {
            return k % 2 == 0 ? res : res - 2 * nums[index];
        }

        for (int i = 0; i < index; i ++) {
            res -= 2 * nums[i];
            k --;
            if (k == 0) return res;
        }
        if (nums[index] == 0) return res;
        if (k % 2 == 0) return res;
        int r1 = res + 2 * nums[index - 1];
        if (index == nums.size()) return r1;
        int r2 = res - 2 * nums[index];

        return r1 > r2 ? r1 : r2;
    }
};