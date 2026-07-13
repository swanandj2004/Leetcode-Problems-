#include <iostream>
#include <string>
#include <vector>
using namespace std;

string mergeAlternatively(string word1, string word2) {
    string result;
    if(word1.length()>word2.length()) {
        for(int i=0; i<word2.length(); i=i+1) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        for(int j=word2.length(); j<word1.length(); j=j+1) {
            result.push_back(word1[j]);
        }
    }
    else if(word1.length()<word2.length()) {
        for(int i=0; i<word1.length(); i=i+1) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        for(int j=word1.length(); j<word2.length(); j=j+1) {
            result.push_back(word2[j]);
        }
    }
    else {
        for(int i=0; i<word1.length(); i=i+1) {
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
    }

    return result;
}

int main() {
    string word1 = "abcd";
    string word2 = "pq";

    cout << mergeAlternatively(word1, word2) << endl;

    return 0;
}
