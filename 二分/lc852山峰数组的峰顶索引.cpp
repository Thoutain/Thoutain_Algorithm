class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 1; // 0也OK
        int r = n -1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid - 1] < arr[mid])
                l = mid;
            else
                r = mid - 1;
        }
        // return l;  也OK
        return r;
    }
};