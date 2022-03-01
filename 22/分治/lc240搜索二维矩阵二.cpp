#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> matrix, int target) {
    if (matrix.empty()) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    int c = 0;
    int r = row - 1;

    while (c < col && r >= 0) {
        if (matrix[r][c] > target) {
            r --;
        } else if (matrix[r][c] < target) {
            c ++;
        } else return true;
    }

    return false;
}

int main() {
    vector<vector<int>> vec;
    vec.push_back({1, 2, 3});

    cout << vec.size() << endl;
    cout << vec[0].size() << endl;

    return 0;
}

/* ???
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row=matrix.size();
        int col=matrix[0].size();
        int r=row-1;
        int c=0;
        while(c<col && r>=0)
        {
            if(matrix[r][c]<target)
            {
                c++;
                continue;
            }
            if(matrix[r][c]==target)
                return true;
            if(matrix[r][c]>target)
                r--;
        }
        return false;
    }
};