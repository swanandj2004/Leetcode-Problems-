#include <string>
#include <iostream>
using namespace std;

int firstMatch(string &s) {
    long long i=0, j=s.length()-1;
    while(i<=j) {
        if(s[i]==s[j]) {
            return i;
        }
        i=i+1;
        j=j-1;
    }

    return -1;
}

int main() {
    string s="abcacbd";

    cout << firstMatch(s);
    return 0;
}