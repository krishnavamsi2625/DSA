#include <bits/stdc++.h>
using namespace std;

struct Stack {
    int *arr;
    int capacity;
    int top;
    Stack(int cap) {
        capacity = cap;
        arr = new int [capacity];
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {cout << "Full Stack" << endl; return;}
        top++;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) {cout << "Empty Stack" << endl; return INT_MIN;}
        int temp = arr[top];
        top--;
        return temp;
    }

    int peek() {
        if (top == -1) {cout << "Empty Stack" << endl; return INT_MIN;}
        return arr[top];
    }

    int size() {
        return (top + 1);
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        int i = 0;
        for (i = top ; i >= 0 ; i--) printf("%d ", arr[i]);
    }

};

int main()
{
    Stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
    cout << s.isFull() << endl;
    s.display();

    return 0;
}