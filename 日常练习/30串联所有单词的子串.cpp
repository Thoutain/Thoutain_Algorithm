/*
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。

示例 1：

输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2：

输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
示例 3：

输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
*/

// 字符串哈希--O(n)？？？
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();        // 字符串长度
        int m = words.size();    // 单词数量
        if (m == 0) return res;
        int w = words[0].size(); // 单词长度
        unordered_map<string, int> total; //存的总共单词数量
        for (auto& word : words) total[word] ++; // 枚举每个单词出现的次数

        for (int i = 0; i < w; i ++) {
            unordered_map<string, int> wd; // 记录每一组里面的哈希表
            int cnt = 0;
            for (int j = i; j + w <= n; j += w) { // 遍历这组里面所有的元素 终点是j+w
                if (j >= i + m * w) { // 把前面的删掉
                    auto word = s.substr(j - m * w, w);
                    wd[word] --;
                    if (wd[word] < total[word]) cnt --; // 减到的是一个有效单词
                }
                auto word = s.substr(j, w);
                wd[word] ++;
                if (wd[word] <= total[word]) cnt ++;
                if (cnt == m) res.push_back(j - (m - 1) * w); // 找到了一个方案
            }
        }
        return res;
    }
};