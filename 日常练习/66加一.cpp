class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt = 1;
        for (int i = digits.size() - 1; i >= 0; i --) {
            digits[i] += cnt;
            if (digits[i] == 10) {
                cnt = 1;
                digits[i] = 0;
            } else {
                cnt = 0;
                break;
            }
        }
        if (cnt == 1)
            digits.insert(digits.begin(), 1);
        return digits;
        
    }
};