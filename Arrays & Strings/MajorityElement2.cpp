#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int>majorityElement(vector<int>&nums) {
    unordered_map<int,int>map;
    unordered_set<int>set;
    vector<int>v;
    for(int i=0; i<nums.size(); i=i+1) {
        map[nums.at(i)]=map[nums.at(i)]+1;
    }
    for(int j=0; j<nums.size(); j=j+1) {
        if(map[nums.at(j)]>nums.size()/3) {
            set.insert(nums.at(j));
        }
    }
    for(int element : set) {
        v.push_back(element);
    }
    return v;
}

int main() {
    vector<int>nums={3,2,3};    

    vector<int>v=majorityElement(nums);
    for(int i=0; i<v.size(); i=i+1) {
        cout << v.at(i) << " ";
    }
    return 0;
}