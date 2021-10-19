class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> vec = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> s = {"M", "CM", "D", "CD", "C", "XC", "L", "XL","X", "IX", "V", "IV", "I"};
        int i = 0;
        while (i < 13) {
            int t = num / vec[i];

            int tmp = t * vec[i];
            num -= tmp;
            while (t) {
                res += s[i];
                t --;
            }
            i ++;
        }
        return res;
    }
};

// hash
