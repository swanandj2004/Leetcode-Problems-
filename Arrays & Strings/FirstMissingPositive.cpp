#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int firstMissingPositive(vector<int>&nums) {
    unordered_map<int,int>map;
    for(int i=0; i<nums.size(); i=i+1) {
        map[nums.at(i)]=map[nums.at(i)]+1;
    }
    for(int j=1; j<nums.size()+1; j=j+1) {
        if(!map.count(j)) {
            return j;
        }
    }
    return nums.size()+1;
}

int main() {
    vector<int>nums={};

    cout << firstMissingPositive(nums);
    return 0;
}