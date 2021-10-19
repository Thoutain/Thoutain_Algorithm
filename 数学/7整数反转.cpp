// wrong version
// 错误主要是在循环内部对sum进行判断
// 最后一次计算的结果是没有进行判断的
class Solution {
public:
    int reverse(int x) {
        long sum=0;
        while(x!=0)
        {
            if(sum>=long(INT_MAX)) return 0;
            if(sum<=long(INT_MIN)) return 0;
            sum*=10;
            sum+=x%10;
            x/=10;
        }
        return int(sum);
    }
};

// right version
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        if (res > INT_MAX)
            return 0;
        if (res < INT_MIN)
            return 0;
        return res;

    }
};
// C++取模的特殊
// -1024 % 10 == -4

// 字符串
class Solution {
public:
    int reverse(int x) {
        bool flag = x > 0;
        x = abs(x);
        string s = to_string(x);
        ::reverse(s.begin(), s.end());
        while (s[0] == '0')
            s.erase(0, 1);
        x = atoi(s.c_str());
        if (s == to_string(x)) {
            if (!flag)
                x = -x;
            return x;
        } else {
            return 0;
        }
        return 0;
    }
};

// wrong version
// 1027/1032
class Solution {
public:
    int reverse(int x) {
        bool flag = x > 0;
        x = abs(x);
        string s = to_string(x);
        ::reverse(s.begin(), s.end());
        while (s[0] == '0')
            s.erase(0, 1);
        long long res = atoi(s.c_str()); // 这里atoi涉及了int
        if (!flag)
            res = -res;
        if (res > INT_MAX || res < INT_MIN)
            return 0; 
        return res;
    }
};
// 修正后
class Solution {
public:
    int reverse(int x) {
        bool flag = x > 0;
        x = abs(x);
        string s = to_string(x);
        ::reverse(s.begin(), s.end());
        while (s[0] == '0')
            s.erase(0, 1);
        long long res = atoll(s.c_str());
        if (!flag)
            res = -res;
        if (res > INT_MAX || res < INT_MIN)
            return 0; 
        return res;
    }
};