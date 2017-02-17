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

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int> > v;
//         int len = nums.size();
//         if(len<3){
//           return v;
//         }
//         sort(nums.begin(),nums.end());
//         // {cur,left,right}
//         for(int cur = 0; cur < len - 2 && nums[cur] <= 0; cur++){
//           if(cur != 0 && (nums[cur] == nums[cur-1])){
//             continue;
//           }
//           int left = cur + 1;
//           int right = len - 1;

//           while(left < right){
//             int result = nums[cur] + nums[left] + nums[right];
//             if(result == 0){
//               v.push_back({nums[cur],nums[left],nums[right]});
//               do{
//                 left++;
//               }while(nums[left] == nums[left-1] && left + 1 < right);
//               do{
//                 right--;
//               }while(nums[right] == nums[right+1] && right - 1 > left);
//             }else if(result < 0){
//               do{
//                 left++;
//               }while(nums[left] == nums[left-1] && left + 1 < right);
//             }else{
//               do{
//                 right--;
//               }while(nums[right] == nums[right+1] && right - 1 > left);
//             } 
//           }
//         }
       
//         return v;
//     }
// };

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        int len = nums.size();
        if(len < 3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i = 0; i < len - 2 && nums[i] <= 0; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int start = i + 1; 
            int end = len - 1;
            if(nums[i] + nums[start] + nums[start+1] > 0){
                break;
            }
            if(nums[i] + nums[end -1 ] + nums[end] < 0){
                continue;
            }

            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum > 0){
                    do{
                        end--;
                    }while(start < end-1 && nums[end] == nums[end + 1]);
                }else if(sum < 0){
                    do{
                        start++;
                    }while(start+1 < end && nums[start] == nums[start - 1]);
                }else{
                    res.push_back({nums[i],nums[start],nums[end]});
                    do{
                        end--;
                    }while(start < end-1 && nums[end] == nums[end + 1]);
                    do{
                        start++;
                    }while(start+1 < end && nums[start] == nums[start - 1]);
                }
            }
        }
        return res;
    }
};


int main(){
  vector<int> nums;
  nums = {-4,-7,11,15};
  Solution solution;

  vector<vector<int> > result = solution.threeSum(nums);
  for(int i = 0; i< result.size();i++){
    for(int j = 0; j < result[0].size(); j++){
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
 // cout << result << endl;
  // cout << result << endl;


    
  return 0;
}