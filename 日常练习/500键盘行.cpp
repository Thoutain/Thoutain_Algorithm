// set
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line[3] = {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };
        unordered_map<char, int> hash;
        for (int i = 0; i < 3; i ++)
            for (auto& c : line[i])
                hash[c] = i;
        
        vector<string> res;
        for (auto& word : words) {
            set<int> s;
            for (auto c : word) s.insert(hash[tolower(c)]);
            if (s.size() == 1) res.push_back(word);
        }
        return res;
    }
};