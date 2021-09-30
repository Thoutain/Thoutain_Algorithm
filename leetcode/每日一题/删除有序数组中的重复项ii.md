# 删除有序数组中的重复项Ⅱ
双指针
```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len < 3)
            return len;
        int l = 2;
        int r = 2;
        while(r < len)
        {
            if (nums[l - 2] != nums[r])
            {
                nums[l] = nums[r];
                l++;
            }
            r ++;
        }
        return l;
    }
};
```