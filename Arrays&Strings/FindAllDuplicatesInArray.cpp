#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<int>findDuplicates(vector<int>&nums) {
    vector<int>duplicates;
    unordered_set<int>set;

    sort(nums.begin(),nums.end());
    
    for(int i=0; i<nums.size()-1; i=i+1) {
        if(nums.at(i)==nums.at(i+1)) {
            set.insert(nums.at(i));
        }
    }

    for(int element : set) {
        duplicates.push_back(element);
    }

    return duplicates;
}

int main() {
    vector<int>nums={4,3,2,7,8,2,3,1};

    vector<int>duplicates=findDuplicates(nums);
    for(int i=0; i<duplicates.size(); i=i+1) {
        cout << duplicates.at(i) << " ";
    }

    return 0;
}