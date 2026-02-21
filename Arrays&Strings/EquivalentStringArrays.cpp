#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool arrayStringsAreEqual(vector<string>&word1, vector<string>&word2) { 
    string s1, s2;

    for(int i=0; i<word1.size(); i=i+1) {
        s1.append(word1.at(i));
    }

    for(int j=0; j<word2.size(); j=j+1) {
        s2.append(word2.at(j));
    }

    if(s1==s2) {
        return true;
    }
    return false;
}

int main() {
    vector<string>word1={"ab", "c"};    
    vector<string>word2={"a", "bc"};

    cout << arrayStringsAreEqual(word1, word2);

    return 0;
}