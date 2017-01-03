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


class Stack {
    queue<int> myqueue;
public:
    // Push element x onto stack.
    void push(int x) {
        myqueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int n = myqueue.size();
        while(n > 1){
            myqueue.push(myqueue.front());
            myqueue.pop();
            n--;
        }
        myqueue.pop();     
    }

    // Get the top element.
    int top() {
        int n = myqueue.size();
        int result;
        while(n > 0){
            result = myqueue.front();
            myqueue.push(result);
            myqueue.pop();
            n--;
        }
        return result;
    }

    // Return whether the stack is empty.
    bool empty() {
       return myqueue.size() == 0 ? true : false; 
    }
};

int main(){

Stack mys;
mys.push(1);
mys.push(2);
cout << mys.top() << endl;
mys.pop();
cout << mys.top() << endl;


    
	return 0;
}