#include <string>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;

int findPermutationDifference(string s, string t) {
    int result=0;
    unordered_map<char,int>map1;
    unordered_map<char,int>map2;
    for(int i=0; i<s.length(); i=i+1) {
        map1[s[i]]=i;
    }
    for(int j=0; j<t.length(); j=j+1) {
        map2[t[j]]=j;
    }
    for(auto &p:map1) {
        if(map1[p.first]!=map2[p.first]) {
            result=result+abs(map1[p.first]-map2[p.first]);
        }
    }
    return result;
}

int main() {
    string s="abcde";
    string t="edbac";

    cout << findPermutationDifference(s,t) << endl;
    return 0;
}