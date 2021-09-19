#include <iostream>
#include <vector>

using namespace std;

// wrong version
// [2,3,4,5,18,17,6] 过不去  正确答案17 输出16
int maxArea(vector<int> &height)
{
    int len = height.size();
    int l = 0;
    int r = len - 1;
    int res = 0;

    while (l < r)
    {
        int t = (r - l) * (height[l] < height[r] ? height[l] : height[r]);
        res = res > t ? res : t;
        // 出错的是这里 判断的不是下标 而是下标对应的值
        if (l < r)
            l++;
        else
            r--;
    }

    return res;
}

// right version
int maxArea2(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;

        while (l < r) {
            int t = (r - l) * (height[l] < height[r] ? height[l] : height[r]);
            if (t > res)
                res = t;
            if (height[l] < height[r])
                l ++;
            else 
                r --;
        }

        return res;
    }    
int main() {
    int n, t;
    vector<int> vec;

    cin >> n;
    while (n --) {
        cin >> t;
        vec.push_back(t);
    }

    cout << maxArea(vec) << endl;
    cout << maxArea2(vec) << endl;

    return 0;
}