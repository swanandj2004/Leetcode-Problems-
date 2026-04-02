#include <string>
#include <vector>
#include <iostream>
using namespace std;

char smallestLetter(vector<char>&letters, char target) {
    vector<char>v;

    for(int i=0; i<letters.size(); i=i+1) {
        if(letters.at(i)>target) {
            v.push_back(letters.at(i));
        }
    }

    if(v.size()==0) {
        return letters.at(0);
    }

    char min=v.at(0);
    for(int j=0; j<v.size(); j=j+1) {
        if(min>v.at(j)) {
            min=v.at(j);
        }
    }

    return min;
}

int main() {
    vector<char>letters={'c','f','j'};

    cout << smallestLetter(letters, 'c') << endl;
    return 0;
}