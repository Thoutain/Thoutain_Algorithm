//O(2^n)  ���ִ���40֮����������ܶ���
#include <iostream>
using namespace std;

int fib(int n)
{
    if (n < 3)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << "please enter a number" << endl;
    int num;
    cin >> num;
    cout << "fib(" << num << ")" << " is " << fib(num) << endl;
    return 0;
}
