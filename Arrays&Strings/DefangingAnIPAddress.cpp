#include <string>
#include <vector>
#include <iostream>
using namespace std;

string defangIP(string address) {
    string s;

    for(int i=0; i<address.size(); i=i+1) {
        if(address.at(i)=='.') {
            s.push_back('[');
            s.push_back(address.at(i));
            s.push_back(']');
        } else if(address.at(i)!='.') {
            s.push_back(address.at(i));
        }
    }

    address=s;

    return address;
}

int main() {
    string address="255.100.50.0";

    cout << defangIP(address) << endl;
    return 0;
}