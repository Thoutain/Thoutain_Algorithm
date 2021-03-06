class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1])
            pos --;
        reverse(nums.begin() + pos, nums.end());
        if (pos > 0) {
            int start = pos;
            for (; start < nums.size(); start ++) {
                if (nums[start] > nums[pos - 1]) {
                    swap(nums[start], nums[pos - 1]);
                    break;
                }    
            }
        }
    }
};