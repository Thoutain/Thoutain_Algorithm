class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 2) return -1;
        int n = nums.size();
        for (int i = 1; i < n; i ++)
            nums[i] += nums[i - 1];
        int res = -1;
        for (int i = 1; i < n - 1; i ++) {
            if (nums[i - 1] == ((nums[n - 1] - nums[i]) / 2)) {
                res = i;
                break;
            }
        }
        cout << nums[n - 1] << endl;
        cout << nums[2] << endl;
        return res;
    }
};

//???