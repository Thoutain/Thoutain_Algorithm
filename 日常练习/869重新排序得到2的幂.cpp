// 不能有前导零
// 暴力 枚举
class Solution {
public:
    bool check(int a, int b) {
        unordered_multiset<char> s1, s2;
        for (auto c : to_string(a)) s1.insert(c);
        for (auto c : to_string(b)) s2.insert(c);
        return s1 == s2; 
    }

    bool reorderedPowerOf2(int n) {
        for (int i = 1; i < 1e9; i *= 2)
            if (check(i, n)) return true;
        return false;
    }
};

// 字符串
class Solution {
public:
    bool check(int a, int b) {
        string s1, s2;
        s1 = to_string(a);
        s2 = to_string(b);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2; 
    }

    bool reorderedPowerOf2(int n) {
        for (int i = 1; i < 1e9; i *= 2)
            if (check(i, n)) return true;
        return false;
    }
};