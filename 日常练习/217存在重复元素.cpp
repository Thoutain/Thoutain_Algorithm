class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> t;
        for (int val : nums) {
            t[val] ++;
            if (t[val] > 1) return true;
        }
        return false;
    }
};