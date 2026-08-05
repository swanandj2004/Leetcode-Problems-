#include <string>
#include <vector>
#include <iostream>
using namespace std;

int compress(vector<char>&chars) {
    vector<char>result;
    for(int i=0; i<chars.size(); i=i+1) {
        char current=chars.at(i);
        int count=0, j=i;
        while(j<chars.size()) {
            if(chars.at(j)!=current) {
                break;
            }
            count=count+1;
            j=j+1;
        }
        result.push_back(current);
        if(count>1) {
            string temp=to_string(count);
            for(char c:temp) {
                result.push_back(c);
            }
        }
        i=j-1;
    }
    chars=result;
    return chars.size();
}

int main() {
    vector<char>chars={'a','a','b','b','c','c','c'};
    cout << compress(chars) << endl;

    return 0;
}