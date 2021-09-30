```C++
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

class Solution{
private:
    int length ;
public:
    int min_step(string& s , string& t , int i){
        length = s.size() ;
        return min_step(s , t , i , 0) ;
    }
    int min_step(string& s , string& t , int i ,int cur_index){
        if(cur_index == t.size())
            return 0 ; 
        else{
            if(s[i] == t[cur_index]){
                int left_min = min_step(s , t , (i-1 + length) % length , cur_index + 1) + 1 ; 
                int right_min = min_step(s ,t , (i+1 + length) % length , cur_index + 1) + 1 ;
                int min_s = min(left_min , right_min) ;
                return min_s ; 
            }
            else{//s[i] != t[cur_index]
                int left_min = min_step(s , t , (i-1 + length) % length , cur_index ) + 1 ; 
                int right_min = min_step(s ,t , (i+1 + length) % length , cur_index ) + 1 ;
                int min_s = min(left_min , right_min) ;
                return min_s ; 
            }
        }
    }
};

int main(){
    string s  ; 
    string t ; 
    int i ; 
    // cin>>s;
    // cin>>t;
    // cin>>i;
    s = "aemoyn" ;
    t = "ae" ;
    i = 0 ;
    cout<<Solution().min_step(s , t , i)<<endl ;
    return 0;
}
```