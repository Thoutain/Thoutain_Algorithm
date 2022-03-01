#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int find(vector<int> nums) {
    int len = nums.size();
    unordered_map<int, int> cnt;
    for (int v : nums) {
        cnt[v] ++;
        if (cnt[v] > len / 2) return v;
    }
    return 0;
}

int main() {
    int n, tmp;
    vector<int> vec;
    while (n --) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    cout << find(vec) << endl;
    return 0;
}