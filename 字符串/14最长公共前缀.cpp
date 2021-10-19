class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        int len = strs[0].size();
        int len2 = strs[strs.size() - 1].size();
        string res = "";
        int i = 0;
        for (; i < len && i < len2; i ++) {
            if (strs[0][i] != strs[strs.size() - 1][i])
                break;
        }
        res += strs[0].substr(0, i);
        return res;

    }
};
// 注意遍历时的下标