#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string frequencySort(string s) {
    unordered_map<char,int>map;
    string t;

    for(int i=0; i<s.length(); i=i+1) {
        map[s[i]]=map[s[i]]+1;
    }

    vector<pair<char,int>>v;

    for(auto &p : map) {
        v.push_back(p);
    }

    for(int i=0; i<v.size(); i=i+1) {
        for(int j=0; j<v.size()-1; j=j+1) {
            if(v.at(j).second < v.at(j+1).second) {
                swap(v.at(j),v.at(j+1));
            }
        }
    }

    for(int i=0; i<v.size(); i=i+1) {
        int freq=v.at(i).second;
        int ch=v.at(i).first;

        for(int j=0; j<freq; j=j+1) {
            t.push_back(ch);
        }
    }

    s=t;
    return s;
}

int main() {
    string s="tree";

    s=frequencySort(s);
    cout << s << endl;

    return 0;
}