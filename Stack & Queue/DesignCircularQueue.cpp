#include <queue>
#include <iostream>
using namespace std;

class Mycircularqueue {
    public:
    queue<int>q;
    int capacity;

    Mycircularqueue(int k) {
        capacity=k;
    }

    bool enQueue(int val) {
        if(q.size()==capacity) {
            return false;
        }
        q.push(val);
        return true;
    }

    bool deQueue() {
        if(q.empty()) {
            return false;
        }
        q.pop();
        return true;
    }

    int front() {
        if(!q.empty()) {
            return q.front();
        }
        return -1;
    }

    int rear() {
        if(!q.empty()) {
            return q.back();
        }
        return -1;
    }

    bool isEmpty() {
        if(q.empty()) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if(q.size()==capacity) {
            return true;
        }
        return false;
    }
};

int main() {
    Mycircularqueue *queue=new Mycircularqueue(5);

    return 0;
}