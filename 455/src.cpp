#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
using namespace std;


//Space: O(1)
// Time: O(n)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int len_g = g.size() - 1;
        int len_s = s.size() - 1;
        while(len_s >= 0 && len_g >= 0){
            if(s[len_s] >= g[len_g]){
                res++;
                len_s--;
                len_g--;
                continue;
            }
            len_g--;
        }
        return res;
    }
};

int main(){


    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    
    int result;
    Solution solution;  
 
    result = solution.findContentChildren(g,s); 
    cout << result << endl;


    
    return 0;
}