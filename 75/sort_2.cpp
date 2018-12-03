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

// Time: O(nlogK)
class Solution {
public:
    void rainbow_sort(vector<int> & colors, int start, int end, int start_color, int end_color){
        if(start_color == end_color || start == end){
            return;
        }
        int mid_color = start_color + (end_color - start_color)/2;
        int l = start, r = end;
        while(l <= r){
            while(l <= r && colors[l] <= mid_color){
                l++;
            }
            while(l <= r && colors[r] > mid_color){
                r--;
            }
            if(l <= r){
                swap(colors[l], colors[r]);
                l++;
                r--;
            }
        }
        rainbow_sort(colors, start, r, start_color, mid_color);
        rainbow_sort(colors, l, end, mid_color+1, end_color);
    }
        
    void sortColors2(vector<int> &colors, int k) {
        rainbow_sort(colors, 0, colors.size()-1, 1, k);
    }
};
int main(){

  vector<int>  nums(2);
  nums = {2,1,1,2,2};
  int k = 2;
  Solution solution;
  solution.sortColors2(nums, k);
  for(int i = 0; i< nums.size();i++){
    cout << nums[i] << endl;
  }


    
  return 0;
}