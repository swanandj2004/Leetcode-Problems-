#include <stack>
#include <string>
#include <iostream>
using namespace std;

string removeStars(string &s) {
    if(s.length()==0) {
        return "";
    }

    stack<char>st;
    stack<char>temp;
    string t;

    for(int i=0; i<s.length()-1; i=i+1) {
        if(s[i]!='*') {
            st.push(s[i]);
        }
        if(s[i+1]=='*') {
            if(!st.empty()) {
                st.pop();
            }
        }
    }

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()) {
        t.push_back(temp.top());
        temp.pop();
    }
    if(s[s.length()-1]!='*') {
        t.push_back(s[s.length()-1]);
    }

    return t;
}

int main() {
    string s="leet**cod*e";

    s=removeStars(s);
    cout << s << endl;

    return 0;
}