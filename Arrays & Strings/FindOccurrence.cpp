#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool makeString(int index, string &haystack, string &needle) {
    string s;
    for(int i=index; i<haystack.length(); i=i+1) {
        s.push_back(haystack[i]);
        if(s==needle) {
            return true;
        }
    }
    return false;
}

int findOccurrence(string &haystack, string &needle) {
    for(int i=0; i<haystack.length(); i=i+1) {
        bool find=makeString(i, haystack, needle);
        if(find==true) {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack="sadbutsad";
    string needle="sad";

    cout << findOccurrence(haystack, needle);
    return 0;
}