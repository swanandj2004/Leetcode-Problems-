#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

bool uniqueOccurrences(vector<int>&arr) {
    unordered_map<int,int>map;
    unordered_set<int>set;
    for(int i=0; i<arr.size(); i=i+1) {
        map[arr.at(i)]=map[arr.at(i)]+1;
    }
    for(auto &p : map) {
        set.insert(p.second);
    }
    if(map.size()==set.size()) {
        return true;
    }
    return false;
}

int main() {
    vector<int>arr={-3,0,1,-3,1,1,1,-3,10,0};

    cout << uniqueOccurrences(arr);
    return 0;
}