#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int>topKFrequent(vector<int>&nums, int k) {
    unordered_map<int,int>map;
    vector<pair<int,int>>v;
    vector<int>frequent;
    for(int i=0; i<nums.size(); i=i+1) {
        map[nums.at(i)]=map[nums.at(i)]+1;
    }
    for(auto &p : map) {
        v.push_back(p);
    }
    for(int i=0; i<v.size(); i=i+1) {
        for(int j=0; j<v.size()-1; j=j+1) {
            if(v.at(j).second<v.at(j+1).second) {
                swap(v.at(j),v.at(j+1));
            }
        }
    }
    for(int i=0; i<k; i=i+1) {
        frequent.push_back(v.at(i).first);
    }
    return frequent;
}

int main() {
    vector<int>nums={1,2,1,2,1,2,3,1,3,2};

    vector<int>frequent=topKFrequent(nums, 2); 
    for(int i=0; i<frequent.size(); i=i+1) {
        cout << frequent.at(i) << " ";
    }

    return 0;
}