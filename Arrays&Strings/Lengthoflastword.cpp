#include <string>
#include <iostream>
using namespace std;

int lastWord(string &s) {
    int count=0, startindex;
    for(int i=s.length()-1; i>=0; i=i-1) {
        if(s[i]!=' ') {
            startindex=i;
            break;
        }
    }
    for(int i=startindex; i>=0; i=i-1) {
        if(s[i]==' ') {
            break;
        }
        count++;
    }
    return count;
}

int main() {
    string s=" Fly me to the  moon  ";

    int length=lastWord(s);
    cout << length << endl;
    return 0;
}