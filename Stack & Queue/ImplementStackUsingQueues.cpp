#include <queue>
#include <iostream>
using namespace std;

class Mystack {
    public:
    queue<int>q;

    Mystack() {

    }

    void push(int x) {
        q.push(x);
        int size=q.size();
        for(int i=0; i<size; i=i+1) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    Mystack *obj=new Mystack();
    for(int i=1; i<6; i=i+1) {
        obj->push(i);
    }
    cout << obj->pop() << endl;
    cout << obj->isEmpty() << endl;

    return 0;
}