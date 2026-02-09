#include <string>
#include <stack>
#include <iostream>
using namespace std;

bool isValidPalindrome(string &s) {
    stack<char>st1;
    stack<char>st2;
    for(int i=0; i<s.length(); i=i+1) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A'); 
        }
    }
    for(int i=s.length()-1; i>-1; i=i-1) {
        if(isalnum(s[i])) {
            st1.push(s[i]);
        }
    }
    for(int i=0; i<s.length(); i=i+1) {
        if(isalnum(s[i])) {
            st2.push(s[i]);
        }
    }
    while(!st1.empty() && !st2.empty()) {
        if(st1.top()!=st2.top()) {
            return false;
        }
        st1.pop();
        st2.pop();
    }
    return true;
}

int main() {
    string s="A man, a plan, a canal: Panama";
    
    cout << isValidPalindrome(s);
    return 0;
}