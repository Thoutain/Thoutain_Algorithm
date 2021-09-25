#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)
            return -1;
        if (len == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0;
        int r = len - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] >= nums[0])
                l = mid;
            else
                r = mid - 1;
        }
        if (target >= nums[0])
            l = 0;
        else {
            l = l + 1;
            r = len - 1;
        }
        /*
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] <= target)
                l = mid;
            else 
                r = mid - 1;
        }
        return nums[l] == target ? l : -1;
        */
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return nums[r] == target ? r : -1;
    }
};

int main() {
    vector<int> vec = {1, 3};
    int n = 0;
    Solution s;
    cout << s.search(vec, n);
    return 0;
}