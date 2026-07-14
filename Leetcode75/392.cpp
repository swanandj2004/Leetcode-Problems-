#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    if(s=="") {
        return true;
    }
    stack<char>st;
    for(int i=0; i<s.length(); i=i+1) {
        st.push(s[i]);
    }
    for(int j=t.length()-1; j>-1; j=j-1) {
        if(st.size()>0) {
            if(st.top()==t[j]) {
                st.pop();
            }
        }
    }
    if(st.size()==0) {
        return true;
    }
    return false;
}

int main() {
    string s="abc";
    string t="ahbgdc";

    cout << isSubsequence(s,t);

    return 0;
}