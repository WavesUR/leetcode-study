#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        stack<int> bar;
        heights.push_back(0);
        int len = heights.size();
        int i = 0;
        while(i <= len){
          while(!bar.empty() && heights[i] < heights[bar.top()]){
              int temp = heights[bar.top()];
              bar.pop();             
              largest = max(largest,temp*(bar.empty() ? i : i - bar.top() - 1 ));

            }
          bar.push(i);
          i++;
          
        }
        return largest;
    }
};

int main(){

  vector<int> heights;
  heights = {2,1,5,6,2,3};
  Solution solution;
  int result = solution.largestRectangleArea(heights);

  cout << result << endl;


    
  return 0;
}