class MinStack {   //https://leetcode.com/problems/min-stack/
    stack<long long> st;
    long long mn;
public:
    MinStack() {
        while(st.size()) st.pop();
        mn = -1;
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            mn = val;
        }
        else
        {
            if(val >= mn)
            {
                st.push(val);
            }
            else
            {
                st.push(2ll*val*1ll-mn);
                mn = val;
            }
        }
    }
    
    void pop() {
        if(st.top()<mn){
            mn = 2ll*mn - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mn){
            return mn;
        }
        return st.top();
        
    }
    
    int getMin() {
        return mn;
        
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
