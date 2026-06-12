#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

vector<string>topKFrequent(vector<string>&words, int k) {
    unordered_map<string,int>map;
    vector<pair<string,int>>v;
    vector<string>result;
    for(int i=0; i<words.size(); i=i+1) {
        map[words.at(i)]=map[words.at(i)]+1;
    }
    for(auto &p : map) {
        v.push_back(p);
    }
    for(int i=0; i<v.size(); i=i+1) {
        for(int j=0; j<v.size()-1; j=j+1) {
            if(v.at(j).second<v.at(j+1).second || (v.at(j).second==v.at(j+1).second && v.at(j).first>v.at(j+1).first)) {
                swap(v.at(j),v.at(j+1));
            }
        }
    }
    for(int i=0; i<k; i=i+1) {
        result.push_back(v.at(i).first);
    }

    return result;
}

int main() {
    vector<string>words={"i","love","leetcode","i","love","coding"}; 

    vector<string>result=topKFrequent(words, 2);
    for(int i=0; i<result.size(); i=i+1) {
        cout << result.at(i) << " ";
    }
    
    return 0;
}