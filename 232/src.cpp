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


class Queue {
    stack<int> stackNewest, stackOldest;
public:
    // Queue(){
    //     stackOldest = new stack<int>();
    //     stackNewest = new stack<int>();
    // }
    // Push element x to the back of queue.
    void push(int x) {
        stackNewest.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
         if(!stackOldest.size()){
            while(stackNewest.size()){
                stackOldest.push(stackNewest.top());
                stackNewest.pop();
            }
        }

        stackOldest.pop();       
    }

    // Get the front element.
    int peek(void) {
        if(!stackOldest.size()){
            while(stackNewest.size()){
                stackOldest.push(stackNewest.top());
                stackNewest.pop();
            }
        }

        return stackOldest.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stackOldest.size()+stackNewest.size() == 0 ? true : false;
    }
};

int main(){

Queue myq;
myq.push(1);
myq.push(2);
cout << myq.peek() << endl;
myq.pop();
cout << myq.peek() << endl;


    
	return 0;
}