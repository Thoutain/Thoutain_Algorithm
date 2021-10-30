#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cout << (((7 >> 3) & 1) == 1) << endl;
    cout << (((8 >> 3) & 1) == 1) << endl;
    cout << (((17 >> 3) & 1) == 1) << endl;
}