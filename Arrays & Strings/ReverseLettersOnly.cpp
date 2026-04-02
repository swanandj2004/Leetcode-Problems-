#include <stack>
#include <string>
#include <iostream>
using namespace std;

string reverseOnlyLetters(string &s) {
    stack<char>st;

    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]>='a' && s[i]<='z') {
            st.push(s[i]);
        } if(s[i]>='A' && s[i]<='Z') {
            st.push(s[i]);
        }
    } 

    for(int j=0; j<s.length(); j=j+1) {
        if(s[j]>='a' && s[j]<='z') {
            s[j]=st.top();
            st.pop();
        } if(s[j]>='A' && s[j]<='Z') {
            s[j]=st.top();
            st.pop();
        }
    }

    return s;
}

int main() {
    string s ="Test1ng-Leet=code-Q!";

    cout << reverseOnlyLetters(s);

    return 0;
}