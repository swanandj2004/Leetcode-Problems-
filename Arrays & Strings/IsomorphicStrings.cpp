#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool isIsomorphic(string s, string t) {
    if(s.length()!=t.length()) {
        return false;
    }

    unordered_map<char,char>map1;
    unordered_map<char,char>map2;

    for(int i=0; i<s.length(); i=i+1) {
        if(map1.count(s[i])) {
            if(map1[s[i]]!=t[i]) {
                return false;
            }
        } else {
            map1[s[i]]=t[i];
        }
    }
    for(int j=0; j<t.length(); j=j+1) {
        if(map2.count(t[j])) {
            if(map2[t[j]]!=s[j]) {
                return false;
            }
        } else {
            map2[t[j]]=s[j];
        }
    }

    return true;
}

int main() {
    string s="paper";
    string t="title";

    cout << isIsomorphic(s,t);
    return 0;
}