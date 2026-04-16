#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool isSubsequence(string &s, string &t) {
    if(s=="") {
        return true;
    }

    stack<char>st;

    for(int i=s.length()-1; i>-1; i=i-1) {
        st.push(s[i]);
    }

    for(int j=0; j<t.length(); j=j+1) {
        if(!st.empty() && t[j]==st.top()) {
            st.pop();
        }
    }

    if(st.empty()) {
        return true;
    }
    return false;
}

int main() {
    string s="abc";
    string t="ahbgdc";

    cout << isSubsequence(s, t);

    return 0;
}