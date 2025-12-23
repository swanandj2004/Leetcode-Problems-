#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool backspaceCompare(string &s, string &t) {
    stack<char>st;
    string s2, t2;
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]!='#') {
            st.push(s[i]);
        } else if(s[i]=='#') {
            if(!st.empty()) {
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        s2.push_back(st.top());
        st.pop();
    }
    for(int i=0; i<t.length(); i=i+1) {
        if(t[i]!='#') {
            st.push(t[i]);
        } else if(t[i]=='#') {
            if(!st.empty()) {
                st.pop();
            }
        }
    }
    while(!st.empty()) {
        t2.push_back(st.top());
        st.pop();
    }
    if(s2==t2) {
        return true;
    }
    return false;
}

int main() {
    string s="ab#c";
    string t="ad#c";

    cout << backspaceCompare(s,t);
    return 0;
}