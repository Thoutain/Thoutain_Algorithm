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

// right version
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        int l = 1;
        int r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i ++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            l = i + 1;
            r = nums.size() - 1;
            
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (nums[i] == -sum) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l ++;
                    while (l < r && nums[l] == nums[l - 1])
                        l ++;
                }
                else if (nums[i] > -sum)
                    r --;
                else if (nums[i] < -sum)
                    l ++;
            }
        }
        return res;
    }
};
int main() {


    return 0;
}