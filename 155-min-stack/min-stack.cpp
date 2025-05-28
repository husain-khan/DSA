class MinStack {
    stack<int> st;
   
    stack<int> minstack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
    st.push(val);  
     if (minstack.empty() || val <= minstack.top()) {
            minstack.push(val);
        }
      
    }
    
    void pop() {
        if(st.empty()) return;
       int element=st.top();
       if(!minstack.empty() && element==minstack.top()){
        minstack.pop();
       }
       st.pop();
        
    }
    
    int top() {
        if (st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if (minstack.empty()) return -1;  // Or throw exception
        return minstack.top();
    }
    
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */