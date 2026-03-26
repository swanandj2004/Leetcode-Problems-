#include <stack>
#include <iostream>
using namespace std;

class Myqueue {
    public:
    stack<int>in;
    stack<int>out;

    Myqueue() {

    }

    void push(int x) {
        in.push(x);
    }

    int pop() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            int val=out.top();
            out.pop();
            return val;
        }
        int val=out.top();
        out.pop();
        return val;
    }

    int peek() {
        if(out.empty()) {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool isEmpty() {
        return in.empty() && out.empty();
    }
 };

int main() {
    Myqueue *obj=new Myqueue();
    for(int i=1; i<6; i=i+1) {
        obj->push(i);
    }
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    cout << obj->isEmpty() << endl;

    return 0;
}