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
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        auto comp = [&matrix](pair<int,int>& a, pair<int,int>& b){return matrix[a.first][a.second] > matrix[b.first][b.second];};
        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(comp) > minHeap(comp);

        int n = matrix.size();
        int i = 0, j = 0;
        for(int i = 0; i < min(n,k); i++){
          minHeap.push(make_pair(0,i));
        }
        int count = k;
        while(count > 1){
          auto temp = minHeap.top();
          minHeap.pop();
          if(temp.first+1<n){
            minHeap.push(make_pair(temp.first+1,temp.second));
          }
          count--;

        }
        auto temp = minHeap.top();
        return matrix[temp.first][temp.second];

    }
};

int main(){

  vector<vector<int> > nums;
  nums = {{1,5,9},{10,11,13},{12,13,15}};
  int k = 6;
  Solution solution;
  int result = solution.kthSmallest(nums, k);

  cout << result << endl;


    
  return 0;
}