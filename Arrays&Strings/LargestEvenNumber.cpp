#include <string>
#include <vector>
#include <iostream>
using namespace std;

string largestEven(string &s) {
    if(s.length()-1=='2') {
        return s;
    }
    for(int i=s.length()-1; i>-1; i=i-1) {
        if(s[i]=='1') {
            s.pop_back();
        } else if(s[i]=='2') {
            break;
        }
    }
    return s;
}

int main() {
    string s="221";

    cout << largestEven(s);
    return 0;
}