// 其中恰好有两个元素只出现一次，其余所有元素均出现两次。
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> ans;
        for (int v : nums)
            ans[v] ++;
        for (auto t : ans)
            if (t.second == 1)
                res.push_back(t.first);
        return res;
    }
};

// 异或
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> vec = {0, 0};
        int sum = 0;
        for (int v : nums) sum ^= v;
        int k = -1;
        // 找一个不一样的位
        // 异或的结果  目标位&1如果为1说明异或前对应位不一样
        for (int i = 31; i >= 0 && k == -1; i --) {
            if (((sum >> i) & 1) == 1) k = i;
        }
        for (int v : nums) {
            if (((v >> k) & 1) == 1) vec[1] ^= v;
            else vec[0] ^= v;
        }
        return vec;
    }
};