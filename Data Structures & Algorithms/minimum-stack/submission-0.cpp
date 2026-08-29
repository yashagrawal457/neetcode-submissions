class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()){
            st.push({val,val});
        }else{
            int tp = st.top().second;
            st.push({val, min(tp,val)});
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();   
        }
        
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
