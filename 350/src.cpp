#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Hash Table
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int> map;
//         vector<int> res;
//         for(int i = 0; i < nums1.size(); i++){
//                 map[nums1[i]]++;
//         }
//         for(int i = 0; i < nums2.size(); i++){
//             if(map[nums2[i]] > 0){
//                 res.push_back(nums2[i]);
//                 map[nums2[i]]--;
//             }
//         }
//         return res;
//     }
// };

// sort and two pointers
// Time: O(max(nlogn,mlogm))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;       
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());  
        int cur1 = 0, cur2 = 0;
        while(cur1 < nums1.size() && cur2 < nums2.size()){
            if(nums1[cur1] == nums2[cur2]){
                res.push_back(nums1[cur1]);
                cur1++;
                cur2++;
            }else if(nums1[cur1] > nums2[cur2]){
                cur2++;
            }else{
                cur1++;
            }
        }
        return res;
    }
};
int main(){

    
    vector<int> nums1= {3,1,2};
    vector<int> nums2= {1};

    vector<int> result;
    Solution solution;  


    result = solution.intersect(nums1,nums2);    

    vector<int>::iterator iter;
    for(iter=result.begin(); iter < result.end(); iter++){
        cout << *iter <<" ";
    }
    cout << endl;

    
    return 0;
}