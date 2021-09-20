class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        for (int i = 1; i < nums.size(); i ++) {
            for (int j = i - 1; j >= 0; j --)
                if (nums[i] == nums[j]) {
                    nums.erase(nums.begin() + i);
                    -- i;
                    break;
                }       
        }
        return nums.size();
    }
};