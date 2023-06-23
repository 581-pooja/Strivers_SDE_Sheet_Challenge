#include <bits/stdc++.h> 
class Queue {
private:
queue <int> q;

public:
    Queue() {
        size=10001;
        arr=new int[size];
        qtop=0;
        rear=0;  
    }

    
    bool isEmpty() {
        if(qtop == rear) return true;
        return false;  
    }

    void enqueue(int data) {
        int s = q.size();
        q.push(data);
        for(int i=0; i<s; i++){
            q.push(q.top());
            q.pop();
        }
    }

    int dequeue() {
        int ele = q.top();
        q.pop();
        return ele;
    }

    int front() {
        return q.top();
    }
};

// Tc: O(N) | SC: O(N)