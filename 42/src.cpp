#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	int left = 0;
    	int right = height.size() - 1;
    	int area = 0;
        while(left < right){
        	int minh = min(height[left],height[right]);
        	if(height[left] == minh){
	        	left++;
	        	while(height[left] < minh && left < right){
	        		area = area + minh - height[left];
	        		left++;
	        	}        		
        	}else{
        		right--;
        		while(height[right] < minh && left < right){
        			area = area + minh - height[right];
        			right--;
        		}
        	}
        }
        return area;
    }
};


int main(){

vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
Solution solution;
int result = solution.trap(height);
cout << result << endl;
    
return 0;
  
}