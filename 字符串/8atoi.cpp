class Solution {
public:
    int myAtoi(string s) {
        int k = 0;
        while (k < s.size() && s[k] == ' ')
            k ++;
        if (k == s.size())
            return 0;
        
        bool flag = true;
        if (s[k] == '-') {
            flag = false;
            k ++;
        } else if (s[k] == '+')
            k ++;

        long long res = 0;
        while (k < s.size() && s[k] >= '0' && s[k] <= '9') {
            res = res * 10 + s[k] - '0';
            k ++;
            if (res > INT_MAX)
                break;
        }

        if (flag == false)
            res *= -1;
        if (res > INT_MAX)
            res = INT_MAX;
        if (res < INT_MIN)
            res = INT_MIN;
        
        return res;
    }
};