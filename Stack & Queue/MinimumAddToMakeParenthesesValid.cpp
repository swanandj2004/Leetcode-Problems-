#include <stack>
#include <string>
#include <iostream>
using namespace std;

int minAdd(string s) {
    stack<char>st;
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]=='(') {
            st.push('(');
        }
        else if(s[i]==')') {
            if(!st.empty() && st.top()=='(') {
                st.pop();
            } else {
                st.push(')');
            }
        }
    }

    return st.size();
}

int main() {
    string s = "())";

    cout << minAdd(s);
    return 0;
}