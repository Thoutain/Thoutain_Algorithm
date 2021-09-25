class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        string str;
        for (int i = 0; i < 12; i ++)
            for (int j = 0; j < 60; j ++) {
                int t = __builtin_popcount(i) + __builtin_popcount(j);
                if (t == turnedOn) {
                    string tmp = "";
                    tmp += to_string(i);
                    tmp += ":";
                    if (j < 10) // 细节
                        tmp += "0";
                    tmp += to_string(j);
                    res.push_back(tmp);
                }
            }

        return res;
    }
};