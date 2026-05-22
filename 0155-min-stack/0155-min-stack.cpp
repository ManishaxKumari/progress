class MinStack {
private:
typedef long long ll;
    stack<ll>st;
    ll mini; // this store minimum value 
public:
    MinStack() { //empty constructor
        
    }
    
    void push(int val) {
        ll x=val;
        if(st.empty()){
            mini=x; // this new value is minimum
            st.push(x); //push as it is
            return;//job is done just return
        }
        if(x>=mini){ //dont need to do any modification just push it
            st.push(x);
        }
        else{ //we found new minimum 
             // modify the value; 
            st.push(2LL*x-mini); // push modify value;
            mini=x; // change mini into original minimum value;
        }
    }
    
    void pop() {
        if(st.empty()) return; //noting to pop out
        ll x=st.top(); //get the top value;
        st.pop();
        if(x<mini){
            mini=2LL*mini-x; // 2*(original val) - (value that pop out)
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        ll x=st.top();
        if(x>=mini) return x;
        return mini;
    }
    
    int getMin() {
        return mini;
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