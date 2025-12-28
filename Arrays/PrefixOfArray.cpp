#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isEqual(string s, string t) {
    if(s==t) {
        return true;
    }
    return false;
}

bool isPrefix(string &s, vector<string>&words) {
    if(words.at(0)==s) {
        return true;
    }
    else if(words.at(0)!=s && words.size()==1) {
        return false;
    }
    string t=words.at(0);
    for(int i=1; i<words.size(); i=i+1) {
        t.append(words.at(i));
        bool prefix=isEqual(s, t);
        if(prefix==true) {
            return true;
        }
    }
    return false;
}

int main() {
    string s="iloveleetcode";
    vector<string>words={"i", "love", "leetcode", "apples"};

    cout << isPrefix(s, words);
    return 0;
}