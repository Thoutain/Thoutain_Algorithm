超时
```C++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for (int i : stones)
            sum += i;
        int t = sum/2;
        vector<vector<int>> f(n + 1, vector<int>(t + 1));
        for (int i = 0; i <= n; i++){
            int x = stones[i - 1];
            for (int j = 0; j <= t; j++){
                f[i][j] = f[i - 1][j];
                if (j >= x)
                    f[i][j] = max(f[i][j], f[i - 1][j - x] + x);
            }

        }
        return abs(sum - f[n][t] - f[n][t]);
    }
};
```

**正确版**
```C++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size(), sum = 0;
        for(auto w : stones) sum += w;
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1)); //背包容量上限为石头总重量的一半
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=sum/2; j++)
            {
                if(stones[i-1] <= j)  //当能把这块石头放进背包时，比较放或不放，选择最大值
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]]+stones[i-1]);
                }
                else dp[i][j] = dp[i-1][j];  //这块石头放不进背包时，只能跳过
            }
        }
        return sum - 2*dp[n][sum/2];
    }
};
```
```C++
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        auto sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(sum / 2 + 1);
        for (const auto& stone : stones) {
            for (auto j = sum / 2; j >= stone; j--) {
                dp[j] = max(dp[j], dp[j - stone] + stone);
            }
        }
        return sum - dp[sum / 2] * 2;
    }
};
```

