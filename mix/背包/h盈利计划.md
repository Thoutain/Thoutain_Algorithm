集团里有 n 名员工，他们可以完成各种各样的工作创造利润。

第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。

工作的任何至少产生 minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。

有多少种计划可以选择？因为答案很大，所以 返回结果模 10^9 + 7 的值。

```C++
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int mod = 1e9 + 7;
        int size = group.size();
        int dp[n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= size; ++i) {
            int cur_group = group[i - 1], cur_profit = profit[i - 1];
            for (int j = n; j >= cur_group; --j) {
                for (int k = minProfit; k >= 0; --k) {
                    dp[j][k] += dp[j - cur_group][max(k - cur_profit, 0)];
                    dp[j][k] %= mod;
                }
            }
        }
        return dp[n][minProfit];
    }
};
```