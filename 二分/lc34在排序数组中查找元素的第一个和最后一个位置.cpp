class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int t = nums[mid];
            if (t >= target)
                r = mid;
            else if (t < target)
                l = mid + 1;
        }
        // 注意r下标指向的是第一次出现的位置
        if (nums[r] != target)
            return {-1, -1};
        int tmp = r;
        // 这里用了一个局部遍历 适合元素重复量不大的情况
        while ((tmp < nums.size() - 1) && (nums[tmp] == nums[tmp + 1])) // 是这里判断的问题
            tmp ++;
        return {r, tmp};
    }
};

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return {-1, -1};
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int t = nums[mid];
            if (t >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[r] != target) return {-1, -1};

        int tmp = r;
        while ((tmp < len - 1) && (nums[tmp] == nums[tmp + 1])) ++tmp;
        return {r, tmp};
    }
};

// 两次二分找左右边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return {-1, -1};
        int l = 0, r = len - 1;
        int ll = 0, rr = len - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int t = nums[mid];
            if (t >= target) r = mid;
            else l = mid + 1;
        }
        while (ll < rr) {
            int mid = (ll + rr + 1) >> 1;
            int t = nums[mid];
            if (t <= target) ll = mid;
            else rr = mid - 1;
        }
        
        if (nums[r] != target) return {-1, -1};
        return {r, ll};
    }
};