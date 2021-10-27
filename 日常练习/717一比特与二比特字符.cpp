class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 1) return true;
        for (int i = n - 2; i >= 0; ) {
            if (bits[i] == 0) return true;
            else {
                if (i - 1 >= 0 && bits[i - 1] == 1)
                    i -= 2;
                else    
                    return false;
            }
        }
        return bits[0] == 0 || n % 2 == 1;
    }
};