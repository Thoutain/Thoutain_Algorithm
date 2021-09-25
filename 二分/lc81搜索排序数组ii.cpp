class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (r > l && nums[r] == nums[0])
            r --;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else 
                r = mid - 1;
        }
        if (target >= nums[0])
            l = 0;
        else {
            ++ l;
            r = nums.size() - 1;
        }
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }
        return nums[r] == target;
    }
};