class TopVotedCandidate {
public:
    vector<int> win;
    vector<int> time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        win.resize(n);
        time = times;
        vector<int> sum(n + 1);

        int maxc = 0, maxp;
        for (int i = 0; i < n; i ++) {
            int p = persons[i];
            if (++ sum[p] >= maxc) {
                maxc = sum[p];
                maxp = p;
            }
            win[i] = maxp;
        }
    }
    
    int q(int t) {
        // 二分出来严格大于当前数的最小数
        // 前一个数就是小于等于t的最大数
        int k = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;
        return win[k];
    }
};
