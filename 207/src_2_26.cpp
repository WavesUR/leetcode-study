#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool dfs(vector<pair<int, int> >& prerequisites, int cur, vector<bool>& marked,vector<bool>& onstack, vector<vector<int> >& map){
         marked[cur] = true;
         onstack[cur] = true;
         for(int k : map[cur]){
          if(onstack[k]){
            return false;
          }
          if(!dfs(prerequisites,k,marked,onstack,map)){
            return false;
          }
         }
        onstack[cur] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<bool> marked(numCourses,false);
        vector<vector<int> > map(numCourses,vector<int>(0));
        for(int i = 0; i < prerequisites.size(); i++){
          map[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        for(int i = 0; i < numCourses; i++){
          if(!marked[i]){
            vector<bool> onstack(numCourses,false);
            if(!dfs(prerequisites,i,marked,onstack,map)){
              return false;
            }
          }
        }
        return true;;
    }
};

int main(){

int numCourses = 2;
vector<pair<int, int> > prerequisites = {make_pair(1,0)};
Solution solution;
bool res = solution.canFinish(numCourses,prerequisites);

cout << res << endl;

    
	return 0;
}