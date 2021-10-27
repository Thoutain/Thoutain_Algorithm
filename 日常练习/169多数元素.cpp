class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[len / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> cnt;
        for (int v : nums) {
            cnt[v] ++;
            if (cnt[v] > (len / 2))
                return v;
        }
        return 0;
    }
};