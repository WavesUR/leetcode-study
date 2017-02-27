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
    void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string> > >& map, vector<string>& res, string cur){    
          while(!map[cur].empty()){
              string t = map[cur].top();
              map[cur].pop();            
              dfs(map,res,t);
        
        }

        res.push_back(cur);

    }
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string> > > map;
        for(int i = 0; i < tickets.size(); i++){
            map[tickets[i].first].push(tickets[i].second);        
        }
        vector<string> res;
        string cur = "JFK";
        if(map.find(cur) == map.end()){
          return res;
        }
        dfs(map,res,cur);
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){

  vector<pair<string, string> > tickets = {make_pair("JFK", "KUL"),make_pair("JFK", "NUT"),make_pair("NRT", "JFK")}; //
  Solution solution;
  vector<string> result = solution.findItinerary(tickets);

  for(auto r: result){
  	cout << r << endl;
  }


    
  return 0;
}