#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string print(int n)
{
    if (n == 1)
        return "1";
    return print(n - 1) + to_string(n) + print(n - 1);
}

int main()
{
    cout << "enter a num" << endl;
    int num;
    cin >> num;
    cout << print(num) << endl;
    return 0;
}