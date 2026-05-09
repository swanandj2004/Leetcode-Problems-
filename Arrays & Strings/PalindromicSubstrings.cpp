#include <string>
#include <iostream>
using namespace std;

bool isPalindrome(string &t) {
    int left=0;
    int right=t.length()-1;
    while(left<right) {
        if(t[left]!=t[right]) {
            return false;
        }
        left=left+1;
        right=right-1;
    }

    return true;
}

int countSubstrings(string &s) {
    int count=s.length();
    for(int i=0; i<s.length()-1; i=i+1) {
        string t;
        t.push_back(s[i]);
        for(int j=i+1; j<s.length(); j=j+1) {
            t.push_back(s[j]);
            if(isPalindrome(t)) {
                count=count+1;
            }
        }
    }

    return count;
}

int main() {
    string s ="aaa";

    cout << countSubstrings(s) << endl;
    return 0;
}