#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
using namespace std;

// Time: O(n^2)
// Space: O(n)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map_AB;
        int cout = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                map_AB[A[i]+B[j]]++;
            }
        }

        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                int temp = map_AB[-(C[i]+D[j])];
                if(temp){
                    cout = cout + temp;
                }
            }
        }

        return cout;

    }
};


int main(){


    vector<int> A = {1,2}, B = {-2,-1}, C = {-1, 2}, D = {0, 2};

    Solution solution;
    int result = solution.fourSumCount(A,B,C,D);
    cout << result << endl;
    
  

    
    return 0;
}