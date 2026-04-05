#include <stack>
#include <iostream>
using namespace std;

class Mycustomstack {
    public:
    stack<int>st;
    int size;

    Mycustomstack(int maxSize) {
        size=maxSize;
    }

    void push(int x) {
        if(st.size()<size) {
            st.push(x);
        }
    }

    int pop() {
        if(!st.empty()) {
            int t=st.top();
            st.pop();
            return t;
        }
        return -1;
    }

    void increament(int k, int val) {
        if(!st.empty()) {
            if(st.size()>=k) {
                stack<int>temp;
                while(!st.empty()) {
                    temp.push(st.top());
                    st.pop();
                }
                for(int i=0; i<k; i=i+1) {
                    st.push(temp.top()+val);
                    temp.pop();
                }
                while(!temp.empty()) {
                    st.push(temp.top());
                    temp.pop();
                }
            }
            else if(st.size()<k) {
                stack<int>temp;
                while(!st.empty()) {
                    temp.push(st.top());
                    st.pop();
                }
                while(!temp.empty()) {
                    st.push(temp.top()+val);
                    temp.pop();
                }
            }
        }
    }
};

int main() {
    Mycustomstack *obj=new Mycustomstack(5);
    
    return 0;
}