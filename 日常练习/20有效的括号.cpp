// 用栈解决
class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (char c : s) {
            if (res.empty()) {
                res.push(c);
            } else if (res.top() == '(' && c == ')') {
                res.pop();
            } else if (res.top() == '[' && c == ']') {
                res.pop();
            } else if (res.top() == '{' && c == '}') {
                res.pop();
            } else {
                res.push(c);
            }
        }
        return res.empty();
    }
};

// 对单一类型括号
// 在任意一个位置上，左括号数量>=右括号数量
// 在最后一位位置上，左括号数量==右括号数量
// 程序中只需要记录左括号数量和右括号数量即可
// wrong version  解决不了那种杂着的  比如"([)]"
// 思想：
    // +1可以等价为进，-1可以等价为出
    // 一对括号可以等价为一个完整的事件
    // (())可以看作事件与事件之间的完全包含关系
class Solution {
public:
    bool isValid(string s) {
        int aNum = 0;
        int bNum = 0;
        int cNum = 0;
        for (int i = 0; i < s.size(); i ++) {
            switch(s[i]) {
                case '(' : aNum ++; break;
                case ')' : aNum --; break;
                case '[' : bNum ++; break;
                case ']' : bNum --; break;
                case '{' : cNum ++; break;
                case '}' : cNum --; break;
                default : return false;
            }
            if (aNum < 0 || bNum < 0 || cNum < 0) return false;
        }
        return (aNum == 0 && bNum == 0 && cNum == 0);
    }
};
