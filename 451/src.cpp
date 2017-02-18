#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     void sink(string& s, int cur, int N, unordered_map<char,int>& my_map){
//         while(cur*2+1 < N){
//             int j = cur*2+1;
//             if(j < N - 1 && (my_map[s[j]] > my_map[s[j+1]] || (my_map[s[j]] == my_map[s[j+1]] && s[j] > s[j+1]) )){
//                 j++;
//             }
//             if(my_map[s[cur]] < my_map[s[j]]){
//                 break;
//             }else if(my_map[s[cur]] == my_map[s[j]] && s[cur] - s[j] <= 0){
//                 break;
//             }
//             swap(s[cur],s[j]);
//             cur = j;
//         }
//     }
//     string frequencySort(string s) {
//         int len = s.length();
//         if(len < 3){
//           return s;
//         }
//         unordered_map<char,int> my_map;
//         for(int i = 0; i < len; i++){
//           my_map[s[i]]++;
//         }
//         for(int k = (len-1)/2; k >= 0; k--){
//             sink(s,k,len,my_map);
//         }
//         while(len-1>0){
//             swap(s[0],s[len-1]);
//             len--;
//             sink(s,0,len,my_map);
//         }
//         return s;
        
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        int len = s.length();
        if(len < 3){
          return s;
        }
        unordered_map<char,int> my_map;
        for(int i = 0; i < len; i++){
          my_map[s[i]]++;
        }
        string res = "";
        priority_queue<pair<int,char> > q1;
        for(auto it = my_map.begin(); it != my_map.end();it++){
            q1.push(make_pair(it->second,it->first));
        }
        while(q1.size()){
            auto temp = q1.top();
            res.append(q1.top().first,q1.top().second);
            q1.pop();
        }
        return res;
    }
};

int main(){

string s = "cccaaa";

Solution solution;
string result = solution.frequencySort(s);

cout << result << endl;

    
    return 0;
}