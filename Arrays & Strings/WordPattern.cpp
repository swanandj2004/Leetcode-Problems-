#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool wordPattern(string pattern, string s) {
    vector<string>words;
    
    for(int i=0; i<s.length(); i=i+1) { 
        if(s[i]==' ') {
            continue;
        }
        int j=i;
        string t;
        while(j<s.length()) {
            if(s[j]==' ') {
                break;
            }
            t.push_back(s[j]);
            j=j+1;
        }
        words.push_back(t);
        i=j;
    }

    if(words.size()!=pattern.length()) {
        return false;
    }

    unordered_map<char,string>map1;
    unordered_map<string,char>map2;
    for(int i=0; i<pattern.length(); i=i+1) {
        if(map1.count(pattern[i])) {
            if(map1[pattern[i]]!=words[i]) {
                return false;
            }
        } else {
            map1[pattern[i]]=words[i];
        }
    }
    for(int j=0; j<words.size(); j=j+1) {
        if(map2.count(words[j])) {
            if(map2[words[j]]!=pattern[j]) {
                return false;
            }
        } else {
            map2[words[j]]=pattern[j];
        }
    }

    return true;
}

int main() {
    string s="dog cat cat dog";
    string pattern="abba";

    cout << wordPattern(pattern, s);

    return 0;
}