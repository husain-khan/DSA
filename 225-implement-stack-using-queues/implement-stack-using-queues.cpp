#include<bits/stdc++.h>
class MyStack {
    queue<int> queue;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        queue.push(x);
        for(int i=1;i<queue.size();i++){
            queue.push(queue.front());
            queue.pop();
        }

    }
    
    int pop() {
        int data=queue.front();
        queue.pop();

        return data;
    }
    
    int top() {
        return queue.front();
    }
    
    bool empty() {
        if(queue.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */