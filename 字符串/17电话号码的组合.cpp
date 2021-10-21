// 回溯
// 主要就是一个递归
// 递归过程中要注意的就是得出结果后需要还原现场
// 递归终止条件就是递归深度==字符串.size()
// 每层递归先取电话号码当前位的数字，通过这个数字得出其对应的字符集
    // 然后以字符集大小为循环条件遍历，对每种结果进行处理
    // 在处理得到的结果之上进行下一轮递归
    // 该次递归结束后需要还原现场
class Solution {
public:
    vector<string> letterMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string s;
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        res.clear();
        s.clear();
        if (len == 0)
            return res;
        dfs(digits, 0);
        return res;
    }
    void dfs(string digits, int index) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size(); i ++) {
            s.push_back(letters[i]);
            dfs(digits, index + 1);
            s.pop_back();
        }
    }
};