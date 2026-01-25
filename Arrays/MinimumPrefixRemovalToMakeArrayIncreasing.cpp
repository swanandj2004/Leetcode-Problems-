#include <vector>
#include <iostream>
using namespace std;

int minimumPrefixRemoval(vector<int>&nums) {
    if(nums.size()==1) {
        return 0;
    }
    int i=nums.size()-1;
    while(i>0 && nums.at(i)>nums.at(i-1)) {
        i--;
    }
    return i;
}

int main() {
    vector<int>nums={1,-1,2,3,3,4,5};

    cout << minimumPrefixRemoval(nums);
    return 0;
}