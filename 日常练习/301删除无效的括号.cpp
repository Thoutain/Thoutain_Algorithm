// 删除最少数量的左括号和右括号
// ①左右括号数量相同
// ②任意一个前缀中 左括号数量大于右括号数量
// 从左往右扫面  两个变量记录（其实也可以一个变量记录，0为界点）
class Solution {
public:
    vector<string> ans;

    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0; // l表示当前左括号数量减去右括号数量 r表示需要删除的括号
        for (auto x : s) 
            if (x == '(') l ++;
            else if (x == ')') {
                if (l == 0) r ++;
                else  l --;
            }

        dfs(s, 0, "", 0, l, r);
        return ans;
    }

    void dfs(string &s, int u, string path, int cnt, int l, int r) {
        if (u == s.size()) {
            if (!cnt) ans.push_back(path);
            return;
        }

        if (s[u] != '(' && s[u] != ')') dfs(s, u + 1, path + s[u], cnt, l, r);
        else if (s[u] == '(') {
            int k = u;
            while (k < s.size() && s[k] == '(') k ++;
            l -= k - u;
            for (int i = k - u; i >= 0; i --) {
                if (l >= 0) dfs(s, k, path, cnt, l, r);
                path += '(';
                cnt ++;
                l ++;
            }
        } else if (s[u] == ')') {
            int k = u;
            while (k < s.size() && s[k] == ')') k ++;
            r -= k - u;
            for (int i = k - u; i >= 0; i --) {
                if (cnt >= 0 && r >= 0) dfs(s, k, path, cnt, l, r);
                path += ')';
                cnt --;
                r ++;
            } 
        }
    }
};