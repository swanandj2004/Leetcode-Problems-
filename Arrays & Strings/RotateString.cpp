#include <string>
#include <vector>
#include <iostream>
using namespace std;

string modifyS(string &s) {
    string temp;
    for(int i=1; i<s.length(); i=i+1) {
        temp.push_back(s[i]);
    }
    temp.push_back(s[0]);
    s=temp;

    return s;
}

bool rotateString(string &s, string &goal) {
    if(s.length()==1 && goal.length()==1 && s[0]==goal[0]) {
        return true;
    } else if(s==goal) {
        return true;
    } else if(s.length()!=goal.length()) {
        return false;
    }

    int k=goal.length();
    for(int i=0; i<k; i=i+1) {
        s=modifyS(s);
        if(s==goal) {
            return true;
        }
    }

    return false;
}

int main() {
    string s="abcde";
    string goal="cdeab";

    cout << rotateString(s, goal);

    return 0;
}