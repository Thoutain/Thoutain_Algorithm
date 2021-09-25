class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size()  - 1;
        int l = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[r])
                r = mid;
            else
                l = mid + 1;
        }
        return nums[l];
    }
};

// 这个比上面快
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i ++)
            if (nums[i] > nums[i + 1])
                return nums[i + 1];
        return nums[0];
    }   
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = len - 1;
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
            l = l + 1; // 这里有时候 l和r都在右边界的时候会越界
            r = len - 1;
        }
        /*
        会有越界的情况存在
        while (l < r) {  
            int mid = (l + r) >> 1;
            if (nums[mid] <= target)
                l = mid;
            else 
                r = mid - 1;
        }
        return nums[l] == target ? l : -1;
        */
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r] == target ? r : -1;
    }
};