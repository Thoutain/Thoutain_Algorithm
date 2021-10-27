class Solution {
public:

    int oneCount(int x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt ++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i ++)
            res.push_back(oneCount(i));
        return res;
    }
};


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        for (int i = 0; i <= n; i ++) 
            f[i] = f[i >> 1] + (i & 1);
        return f;
    }
};

