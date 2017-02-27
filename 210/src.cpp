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

class Solution {
public:
	bool dfs(int numCourses, vector<int>& res, vector<vector<int> >& adj_mtx, vector<bool> & onStack, vector<bool> & marked, int cur){
		onStack[cur] = true;
		marked[cur] = true;

		for(int i = 0; i < adj_mtx[cur].size();i++){
			if(onStack[adj_mtx[cur][i]]){
				return false;
			}			
			if(!marked[adj_mtx[cur][i]]){
				if(!dfs(numCourses,res,adj_mtx,onStack,marked,adj_mtx[cur][i])){
					return false;
				}
			}
		}
		res.push_back(cur);
		onStack[cur] = false;
		return true;
	}
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> res;
        vector<vector<int> > adj_mtx(numCourses,vector<int>(0));
        vector<bool> onStack(numCourses,false);
        vector<bool> marked(numCourses,false);
        for(int i = 0; i < prerequisites.size(); i++){
        	adj_mtx[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for(int i = 0; i < numCourses; i++){
        	if(!marked[i]){
        		if(!dfs(numCourses,res,adj_mtx,onStack,marked,i)){
        		return {};
        		}
        	}

        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

  int num1 = 2;
  vector<pair<int, int> > num2 = {make_pair(1,0)};
  Solution solution;
  vector<int> result = solution.findOrder(num1,num2);

  for(auto r: result){
  	cout << r << endl;
  }


    
  return 0;
}