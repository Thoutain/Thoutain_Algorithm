class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1;
        int start = 0;
        int res = nums[0] + nums[1] + nums[end];
        for (int i = 1; i < end; i ++) {
            int l = start;
            int r = end;
            while (l < i && i < r) {
                int t = nums[i] + nums[l] + nums[r];
                if (abs(t - target) < abs(res - target)) {
                    res = t;
                }
                if (t > target)
                    r --;
                else if (t < target)
                    l ++;
                else if (t == target)
                    return t;
            }
        }

        return res;
    }
};