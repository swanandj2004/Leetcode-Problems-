#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool isValid(string &s) {
    stack<char>st;
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            st.push(s[i]);
        }
        else {
            if(st.empty()) {
                return false;
            }
            if(s[i]==')' && st.top()!='(') {
                return false;
            }
            if(s[i]=='}' && st.top()!='{') {
                return false;
            }
            if(s[i]==']' && st.top()!='[') {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s="([])";

    cout << isValid(s);
    return 0;
}