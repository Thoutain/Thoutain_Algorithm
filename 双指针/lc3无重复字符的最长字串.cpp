#include <iostream>
#include <vector>

using namespace std;

// method 1
// 用数组在每一次遍历的时候存储每个字符出现的次数
// 效率不是很高

int lengthOfLongestSubstring(string s)
{
    int len = s.size();
    if (len == 0)
        return 0;
    int res = 1;
    for (int i = 0; i < len - 1; i++)
    {
        vector<int> vec(127, 0);
        int t = 0;
        for (int j = i; j < len; j++)
        {
            vec[int(s[j])]++;
            if (vec[int(s[j])] > 1)
                break;
            t++;
            if (t > res)
                res = t;
        }
    }

    return res;
}

int main()
{
    cout << lengthOfLongestSubstring("abcdabc") << endl;
    return 0;
}