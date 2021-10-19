// 模拟
class Solution {
public:
    int romanToInt(string s) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        int len = s.size();
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < len && j < 13) {
            string tmp = s.substr(i,str[j].size());
            while (tmp == str[j] && i < len) {
                res += val[j];
                i += str[j].size();
                str[j] = s.substr(i, str[j].size());
            }
            j ++;
        }
        return res;
    }
};
