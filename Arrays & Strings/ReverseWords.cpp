#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string reverseWords(string &s) {
    stack<string>st;
    vector<string>v;
    string str;
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]==' ') {
            continue;
        } 
        else {
            string temp;
            int j=i;
            while(s[j]!=' ' && j<s.length()) {
                temp.push_back(s[j]);
                j++;
            }
            st.push(temp);
            i=j-1;
        }
    } 
    while(!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }
    for(int i=0; i<v.size(); i=i+1) {
        string temp=v.at(i);
        for(int j=0; j<temp.size(); j=j+1) {
            str.push_back(temp[j]);
        } 
        str.push_back(' ');
    }
    str.pop_back();
    return str;
}

int main() {
    string s="the sky is blue";
    
    string newstring=reverseWords(s);
    for(int i=0; i<newstring.length(); i=i+1) {
        cout << newstring[i];
    }
    return 0;
}