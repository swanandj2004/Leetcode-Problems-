#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

int firstUniqueCharacter(string s) {
    unordered_map<char,int>map;
    for(int i=0; i<s.length(); i=i+1) {
        map[s[i]]=map[s[i]]+1;
    }
    for(int j=0; j<s.length(); j=j+1) {
        if(map[s[j]]==1) {
            return j;
        }
    }
    return -1;
}

int main() {
    string s="loveleetcode";

    cout << firstUniqueCharacter(s);
    return 0;
}