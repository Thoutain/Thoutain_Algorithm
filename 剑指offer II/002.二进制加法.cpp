class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        while (len1 < len2) {
            a = '0' + a;
            len1 ++;
        } 
        while (len2 < len1) {
            b = '0' + b;
            len2 ++;
        }
        for (int i = 0; i < len1; i ++)
            a[i] = a[i] + b[i] - '0'; // 重点
        for (int i = len1 - 1; i >= 1; i --)
            if (a[i] > '1') {
                a[i] -= 2;
                a[i - 1] += 1;
            } 
        if (a[0] > '1') {
            a[0] -= 2;
            a = '1' + a;
        }
        return a;
    }
};