#include <string>
#include <iostream>
using namespace std;

string toLowerCase(string &s) {
    for(int i=0; i<s.length(); i=i+1) {
        if(s[i]>='A' && s[i]<='Z') {
            s[i]=s[i]+32;
        }
    }
    return s;
}

int main() {
    string s= "HelLo WorLd";

    cout << toLowerCase(s);
    return 0;
}