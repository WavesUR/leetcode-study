#include <cctype>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <cstdio>     
#include <cstdlib>
using namespace std;


class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        stack<int> mystack;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C"){
                int s = mystack.top();
                mystack.pop();
                res = res - s;
            }else if(ops[i] == "D"){
                int s = mystack.top() * 2;
                mystack.push(s);
                res = res + s;
            }else if(ops[i] == "+"){
                int s = mystack.top();
                mystack.pop();
                int r = mystack.top() + s;
                mystack.push(s);
                res = res + r;
                mystack.push(r);
            }else{
                int s = stoi(ops[i]);
                mystack.push(s);
                res = res + s;
            } 
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<string> ops = {"5","-2","4","C","D","9","+","+"};
    int ret = solution.calPoints(ops);
    cout << ret << endl;
    return 0;
}