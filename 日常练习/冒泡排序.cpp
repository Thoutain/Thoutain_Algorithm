#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    for (int i = 0; i < n; i ++) 
        for (int j = i + 1; j < n; j ++)
            if (vec[i] > vec[j])
                swap(vec[i], vec[j]);
    
    for (int i = 0; i < n; i ++)
        cout << vec[i] << " ";
    
    return 0;
    
}