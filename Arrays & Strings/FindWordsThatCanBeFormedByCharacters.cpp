#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isGoodString(string s, string chars) {
    for(int i=0; i<s.length(); i=i+1) {
        bool found=false;
        for(int j=0; j<chars.length(); j=j+1) {
            if(s[i]==chars[j]) {
                found=true;
                chars.erase(j,1);
                break;
            }
        }
        if(found==false) {
            return false;
        }
    }
    return true;
}

int countCharacters(vector<string>&words, string &chars) {
    int len=0;

    for(int i=0; i<words.size(); i=i+1) {
        string s=words.at(i);
        if(isGoodString(s,chars)) {
            len=len+s.length();
        }
    }

    return len;
}

int main() {
    vector<string>words={"hello","world","leetcode"};
    string chars="welldonehoneyr";

    cout << countCharacters(words,chars);

    return 0;
}