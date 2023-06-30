// Brute Force
#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack <pair<int,int>> st; // <val, min>
	
	public:
		
		// Constructor
		minStack() 
		{}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			int mini;
			if(st.empty()){
				mini = num;
			}
			else{
				mini = min(st.top().second, num);
			}
			st.push({num, mini});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;
			int p = st.top().first;
			st.pop();
			return p;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;
			return st.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			return st.top().second;
		}
};

// Optimal Approach:
class MinStack {
    stack <long long>st;  // everywhere long long is used to avoid integer overflow 
    long long mini;
public:
    MinStack() {
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val<mini){
                st.push(2*val*1LL - mini);
                mini = val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el = st.top();
        st.pop();
        if(el < mini){
            mini = 2*mini - el; // changing mini
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        if(el < mini) return mini;
        return el;
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