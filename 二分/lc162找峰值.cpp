class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size() - 1; i ++)
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        if ((nums.size() == 2) && (nums[1] > nums[0]))
            return 1;
        if ((nums.size() > 2) && nums[nums.size() - 1] > nums[nums.size() - 2])
            return nums.size() - 1;
        return 0;
    }
};

// 注意题目条件，在题目描述中出现了 nums[-1] = nums[n] = -∞，这就代表着 只要数组中存在一个元素比相邻元素大，那么沿着它一定可以找到一个峰值
/*
中点所在地方，可能是某座山的山峰，山的下坡处，山的上坡处，如果是山峰，最后会二分终止也会找到，
关键是我们的二分方向，并不知道山峰在我们左边还是右边，送你两个字你就明白了，爬山（没错，就是带你去爬山），
如果你往下坡方向走，也许可能遇到新的山峰，但是也许是一个一直下降的坡，最后到边界。但是如果你往上坡方向走，
就算最后一直上的边界，由于最边界是负无穷，所以就一定能找到山峰，总的一句话，往递增的方向上，二分，一定能找到，
往递减的方向只是可能找到，也许没有。
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[mid + 1]) // 爬坡
                r = mid;
            else    
                l = mid + 1;
        }
        return l;
    }
};