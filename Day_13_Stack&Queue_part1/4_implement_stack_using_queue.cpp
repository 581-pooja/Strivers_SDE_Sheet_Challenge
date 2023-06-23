// brute force:
#include <bits/stdc++.h> 
class Stack {
    queue <int> q1;
    queue <int> q2;
    int size;

   public:
    Stack() {
        size = 0;
    }


    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        // Push current ele in q2
        q2.push(element);
        // q2 -> q1
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
        if(q1.empty()) return -1;
        int p = q1.front();
        q1.pop();
        return p;
    }

    int top() {
        if(q1.empty()) return -1;
        return q1.front();
    }
};

// TC: O(N) | SC: O(2*N) (2 queues) 

// Optimal approach:
#include <bits/stdc++.h> 
class Stack {
    queue <int> q;
    int size;

   public:
    Stack() {
        size = 0;
    }


    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }

    void push(int element) {
        int s = q.size();
        q.push(element);
        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(q.empty()) return -1;
        int ele = q.front();
        q.pop();
        return ele;
    }

    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
};
// Tc: O(N) | SC: O(N)