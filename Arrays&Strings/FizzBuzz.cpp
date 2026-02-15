#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<string>FizzBuzz(int n) {
    stack<string>st;
    vector<string>v;
    while(n!=0) {
        if(n%3==0 && n%5!=0) {
            st.push("Fizz");
        } else if(n%3!=0 && n%5==0) {
            st.push("Buzz");
        } else if(n%3==0 && n%5==0) {
            st.push("FizzBuzz");
        } else {
            string s=to_string(n);
            st.push(s);
        }
        n--;
    }
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    return v;
}

int main() {
    int n=15;

    vector<string>v=FizzBuzz(n);
    for(int i=0; i<v.size(); i=i+1) {
        cout << v.at(i) << " ";
    }

    return 0;
}