class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = 1;
        int r = area;
        vector<int> res;
        while (l <= r) {
            if (l * r < area) l ++;
            else if (l * r > area) r --;
            else {
                res = {r, l};
                l ++;
                r --;
            }
        }
        return res;
    }
};