#include <iostream>
#include <vector>

using namespace std;

/* wrong version
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        for (int i = l + 1; i < r; i ++) {
            tmp.clear();
            while (l < r - 1) {
                int t = nums[l] + nums[r];
                if (t + nums[i] == 0) {
                    tmp.push_back(nums[l]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[r]);
                    l ++;
                    r --;
                }
                else if (t + nums[i] > 0)
                    r --;
                else l ++;
            }
            if (tmp.size() != 0)
                res.push_back(tmp);
        }
        return res;
    }
};
*/

int main() {


    return 0;
}