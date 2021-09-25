class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid  = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }
        return nums[r] >= target ? r : r + 1;
        }
};

// 遍历
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (nums[i] >= target)
                return i;
        }
        return len;
    }
};