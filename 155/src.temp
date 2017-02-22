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
        stack<int> stack1;
        stack<int> stack2;       
    void push(int x) {
        stack1.push(x);
        int temp = stack2.top();
        if(x < temp || stack2.empty()){
            stack2.push(x);
        }else{
            stack2.push(temp);
        }
    }
    
    void pop() {
        if(stack1.top() == stack2.top()){
           stack2.pop(); 
        }
        stack1.pop();
        
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return stack2.top();
    }
};

int main(){

 int x = 9;
 MinStack obj = new MinStack();
 obj.push(x);
 obj.pop();
 int param_3 = obj.top();
 int param_4 = obj.getMin();
 
}