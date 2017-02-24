#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;


class MinStack {
public:
    stack<int> s;
    vector<pair<int,int> > min_val;
    /** initialize your data structure here. */
    MinStack() {
        while(!s.empty()){
            s.pop();
        }
        min_val = {};
    }
    
    void push(int x) {

        if(s.empty() || x < min_val.back().first){
            min_val.push_back(make_pair(x,s.size()+1));
        }
        s.push(x);        
    }
    
    void pop() {
        s.pop();
        if(s.size() < min_val.back().second){
            min_val.pop_back();
        }
        
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
       return min_val.back().first; 
    }
};

int main(){

 int x = 9;
 MinStack obj;

 obj.push(x);
// obj.pop();
 // int param_3 = obj.top();
 // int param_4 = obj.getMin();
 
}