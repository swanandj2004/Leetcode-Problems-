#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

string reverseVowels(string &s) {   
    stack<char>st;
    vector<int>index;
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]=='a' || s[i]=='A') {
            st.push(s[i]);
        }
        else if(s[i]=='e' || s[i]=='E') {
            st.push(s[i]);
        }
        else if(s[i]=='i' || s[i]=='I') {
            st.push(s[i]);
        }
        else if(s[i]=='o' || s[i]=='O') {
            st.push(s[i]);
        }
        else if(s[i]=='u' || s[i]=='U') {
            st.push(s[i]);
        }
    }
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]=='a' || s[i]=='A') {
            index.push_back(i);
        }
        else if(s[i]=='e' || s[i]=='E') {
            index.push_back(i);
        }
        else if(s[i]=='i' || s[i]=='I') {
            index.push_back(i);
        }
        else if(s[i]=='o' || s[i]=='O') {
            index.push_back(i);
        }
        else if(s[i]=='u' || s[i]=='U') {
            index.push_back(i);
        }
    }
    for(int i=0; i<index.size(); i=i+1) {
        int position=index.at(i);
        s[position]=st.top();
        st.pop();
    }
    return s;
}

int main() {
    string s="IceCreAm";

    s=reverseVowels(s);
    cout << s;
    return 0;
}