#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

bool checkIfPangram(string sentence) {
    unordered_map<char,int>map;
    for(int i=0; i<sentence.length(); i=i+1) {
        map[sentence[i]]=map[sentence[i]]+1;
    }
    for(char ch='a'; ch<='z'; ch=ch+1) {
        if(!map.count(ch)) {
            return false;
        }
    }

    return true;
}

int main() {
    string sentence = "thequickbrownfoxjumpsoverthelazydog";

    cout << checkIfPangram(sentence) << endl;
    return 0;
}