#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
// Time: O(nlogn)
class Solution {
public:
	int binary_search(vector<pair<Interval,int> >& v, int target){
		int left = 0;
		int right = v.size() - 1;
		while(left < right){
			int mid = left + (right - left) / 2;
			if(v[mid].first.start < target){
				left = mid + 1;
			}else{
				right = mid;
			}
		}
		return v[right].first.start >= target ? v[right].second : -1;
	}
    vector<int> findRightInterval(vector<Interval>& intervals) {
    	vector<pair<Interval,int> > v(intervals.size());
        for(int i =0 ; i < intervals.size(); i++){
        	v[i]=make_pair(intervals[i],i);
        }
        sort(v.begin(),v.end(),[](pair<Interval,int>& a, pair<Interval,int>& b){
        	if(a.first.start != b.first.start){
        		return a.first.start < b.first.start;
        	}else{
        		return a.second < b.second;
        	}
        });

        // for(auto vv : v){
        // 	cout << vv.first.start << " " << vv.first.end << " " << vv.second << endl;
        // }
        vector<int> res(intervals.size());        
        for(int i = 0; i < v.size(); i++){
        	res[i] = binary_search(v,intervals[i].end);
        }
        return res;
    }
};

int main(){

vector<Interval> intervals = {Interval(3,4),Interval(2,3),Interval(1,2)};


Solution solution;
vector<int> res = solution.findRightInterval(intervals);

for(int i = 0; i < res.size(); i++){
  cout << res[i] << " ";
}
cout << endl;

    
    return 0;
}