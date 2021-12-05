/*
为了不在赎金信中暴露字迹，从杂志上搜索各个需要的字母，组成单词来表达意思。

给你一个赎金信 (ransomNote) 字符串和一个杂志(magazine)字符串，判断 ransomNote 能不能由 magazines 里面的字符构成。

如果可以构成，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> input(26);
        for (char c : ransomNote) input[c - 'a'] ++;
        vector<int> vec(26);
        for (char c : magazine) vec[c - 'a'] ++;

        for (int i = 0; i < 26; i ++)
            if (input[i] > vec[i]) return false;
        return true;
    }
};

// 用到了哈希的思想 key-value