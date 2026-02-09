#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

bool containsDuplicate(vector<int>nums) {
    unordered_set<int>set;
    for(int i=0; i<nums.size(); i=i+1) {
        set.insert(nums.at(i));
    }
    if(nums.size()==set.size()) {
        return false;
    }
    return true;
}

int main() {
    vector<int>nums={1,2,3,1};

    cout << containsDuplicate(nums);
    return 0;
}