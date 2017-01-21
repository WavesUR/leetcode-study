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

//Time: O(n^2)
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int> >& points) {
        unordered_map<int,int> my_map;
        int num = 0;
        for(int i = 0; i < points.size(); i++){
          for(int j = 0; j < points.size();j++){
            if(i == j){
              continue;
            }
            int distance = pow((points[i].first - points[j].first),2) + pow((points[i].second - points[j].second),2);
            if(my_map.find(distance) == my_map.end()){
              my_map[distance] = 1;
            }else{
              my_map[distance]++;
            }
          }
          for(auto my_map_i : my_map){
              // cout << my_map_i.second<< " ";
                num = num + my_map_i.second * (my_map_i.second - 1);
            }
            my_map.clear(); 
        }

        return num;
    }
};

int main(){

  vector<pair<int, int> > nums;
  nums = {{0,0},{1,0},{2,0}};
  Solution solution;
  int result = solution.numberOfBoomerangs(nums);
  // for(int i = 0; i< nums.size();i++){
  //   cout << nums[i] << endl;
  // }
  cout << result << endl;


    
  return 0;
}