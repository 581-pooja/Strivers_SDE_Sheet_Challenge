#include <bits/stdc++.h> 
// Stack class.
class Stack {
    private:
    int max_size;
    int *arr;
    int tail;

    public:
    
    Stack(int capacity) {
        tail = -1;
        arr = new int[capacity];
        max_size = capacity;
    }

    void push(int num) {
        if(tail != max_size){
            tail++;
            arr[tail] = num;
        }
    }

    int pop() {
        if(tail != -1){
            int ele = arr[tail];
            tail--;
            return ele;
        }
        return -1;
    }
    
    int top() {
        return (tail != -1)? (arr[tail]) : -1;
    }
    
    int isEmpty() {
        return (tail == -1);
    }
    
    int isFull() {
        return (tail == max_size);
    }
    
};