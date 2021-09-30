```C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int flag = -1;
        int n = haystack.size();
        int m = needle.size();
        if (m == n && m == 0)
            return 0;
        if (m == 0)
            return 0;
        for (int i = 0; i < n - m + 1; i++)
        {
            int j = 0;
            int temp = i;    //attention!
            while (haystack[temp] == needle[j])
            {
                temp ++;
                j ++;
                if (j == m)
                {
                    flag = temp - j;
                    return flag;
                }
            }
        }
        return flag;
    }
};
```