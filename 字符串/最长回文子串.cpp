// dp
class Solution {
public:
    string longestPalindrome(string s) {
       int n = s.size();
       if (n < 2)
            return s;
        vector<vector<int>> dp(n, vector<int>(n));
       for (int i = 0; i < n; i ++)
            dp[i][i] = true;
        int max = 1;
        int left = 0;
        for (int l = 2; l <= n; l ++) {
            for (int i = 0; i < n; i ++) {
                int j = i + l - 1;
                if (j >= n)
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else 
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && (j - i + 1) > max) {
                    left = i;
                    max = j - i + 1;
                }
                    
            }
        }
        return s.substr(left, max);
    }
};

// 二分+哈希？？？  acwing139

//中心法
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i ++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l --;
                r ++;
            }
            if (res.size() < r - l - 1)
                res = s.substr(l + 1, r - l - 1);
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l --;
                r ++;
            }
            if (res.size() < r - l - 1)
                res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};

// substr的用法！！！