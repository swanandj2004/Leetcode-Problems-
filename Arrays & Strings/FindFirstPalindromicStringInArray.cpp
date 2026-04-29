#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    stack<char>st;
    for(int i=0; i<s.length(); i=i+1) {
        st.push(s[i]);
    }
    int j=0;
    while(!st.empty()) {
        if(st.top()!=s[j]) {
            return false;
        }
        st.pop();
        j=j+1;
    }
    return true;
}

string firstPalindrome(vector<string>&words) {
    for(int i=0; i<words.size(); i=i+1) {
        if(isPalindrome(words.at(i))) {
            return words.at(i);
        }
    }

    return " ";
}

int main() {
    vector<string>words = {"abc","car","ada","racecar","cool"};

    cout << firstPalindrome(words);
    return 0;
}