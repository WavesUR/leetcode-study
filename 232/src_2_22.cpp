#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;


class MyQueue {
public:
    stack<int> stack_push;
    stack<int> stack_pop;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack_push.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = peek();
        stack_pop.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(stack_pop.empty()){
            while(!stack_push.empty()){
                stack_pop.push(stack_push.top());
                stack_push.pop();
            } 
        }
        return stack_pop.top();        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_push.empty() && stack_pop.empty();
    }
};

int main(){

MyQueue myq;
myq.push(1);
myq.push(2);
cout << myq.peek() << endl;
myq.pop();
cout << myq.peek() << endl;


    
	return 0;
}