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

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right){
          int area = (right - left) * min(height[right],height[left]);
          maxarea = maxarea >= area ? maxarea : area;
          if(height[right] > height[left]){
            left++;
          }else if(height[right] < height[left]){
            right--;
          }else{
            left++;
            right--;
          }
        }
        return maxarea;
    }
};

int main(){

  vector<int> nums;
  nums = {2,3,4,1,2,3};
  Solution solution;
  int result = solution.maxArea(nums);

  cout << result << endl;


    
  return 0;
}