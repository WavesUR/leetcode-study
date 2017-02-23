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


class MyStack {
public:
    queue<int> interqueue;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        interqueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = interqueue.size();
        while(len > 1){
            interqueue.push(interqueue.front());
            interqueue.pop();
            len--;
        }
        int res = interqueue.front();
        interqueue.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res = pop();
        interqueue.push(res);
        return res;        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return interqueue.empty();
    }
};

int main(){

MyStack mys;
mys.push(1);
mys.push(2);
cout << mys.top() << endl;
mys.pop();
cout << mys.top() << endl;


    
	return 0;
}