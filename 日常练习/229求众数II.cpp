// 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        unordered_map<int, int> t;

        for (int v : nums) t[v] ++;
        for (auto v : t)
            if (v.second > len / 3)
                res.push_back(v.first);
        return res;
    }
};

// 摩尔投票