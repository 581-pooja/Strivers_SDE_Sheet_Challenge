// Brute Force:
#include <bits/stdc++.h>
class Queue {
    stack <int> s1;
    stack <int> s2;
    int size;
    
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        // s1 -> s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        // Push ele in s2
        s1.push(val);
        // s2 -> s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if(s1.empty()) return -1;
        int ele = s1.top();
        s1.pop();
        return ele;
    }

    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }
};
// TC: O(N) | SC: O(2N) (using 2 stacks)

// Optimal Approach:
#include <bits/stdc++.h>
class Queue {
    stack <int> s1;
    stack <int> s2;
    int size;
    
    public:
    Queue() {
        
    }

    void enQueue(int val) {
        s1.push(val);
    }

    int deQueue() {
        int ele;
        if(s1.empty() && s2.empty()) return -1;
        if(!s2.empty()){
            ele = s2.top();
            s2.pop();
        } 
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            ele = s2.top();
            s2.pop();
        }
        return ele;
    }

    int peek() {
        if(s1.empty() && s2.empty()) return -1;
        if(!s2.empty()) return s2.top();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool isEmpty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};
// TC: O(1) (Amortized) | SC: O(2N) (2 stacks)