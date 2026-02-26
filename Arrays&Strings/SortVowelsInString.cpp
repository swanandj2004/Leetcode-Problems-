#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string sortVowels(string &s) {
    vector<int>index;
        vector<char>vowels;

        for(int i=0; i<s.length(); i=i+1) {
            if(s[i]=='a' || s[i]=='A') {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
            else if(s[i]=='e' || s[i]=='E') {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
            else if(s[i]=='i' || s[i]=='I') {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
            else if(s[i]=='o' || s[i]=='O') {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
            else if(s[i]=='u' || s[i]=='U') {
                index.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        
        for(int j=0; j<index.size(); j=j+1) {
            int i=index.at(j);
            s[i]=vowels.at(j);
        }

        return s;
}

int main() {
    string s="lEetcOde";

    s=sortVowels(s);
    cout << s << endl;

    return 0;
}