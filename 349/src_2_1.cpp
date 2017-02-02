#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Hash Table
// Time: O(m+n)
// Space: O(m)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> map;
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            if(map.find(nums1[i]) == map.end()){
                map[nums1[i]] = true;
            }
        }

        for(int i = 0; i < nums2.size(); i++){
            if(map[nums2[i]] == true){
                res.push_back(nums2[i]);
                map[nums2[i]] = false;
            }
        }      
        return res;
    }
};

int main(){

	
    vector<int> nums1= {5,1,1,2,2};
    vector<int> nums2= {1,1,2,2};

    vector<int> result;
	Solution solution;	


	result = solution.intersection(nums1,nums2);	

    vector<int>::iterator iter;
    for(iter=result.begin(); iter < result.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl;

    
	return 0;
}