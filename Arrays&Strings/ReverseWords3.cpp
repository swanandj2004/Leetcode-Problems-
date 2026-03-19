#include <string>
#include <stack>
#include <iostream>
using namespace std;

string reverseWords(string &s) {
    for(int i=0; i<s.length(); i=i+1) {
        int start=i;
        stack<char>st;
        while(i<s.length()) {
            if(s[i]==' ') {
                break;
            }
            st.push(s[i]);
            i=i+1;
        }
        for(int j=start; j<i; j=j+1) {
            s[j]=st.top();
            st.pop();
        }
    }

    return s;
}

int main() {
    string s="Let's take LeetCode contest";

    s=reverseWords(s);
    cout << s << endl;

    return 0;
}