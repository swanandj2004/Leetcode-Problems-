#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int majorityElement(vector<int>&nums) {
    sort(nums.begin(), nums.end());
    return nums.at(nums.size()/2);
}

int main() {
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);  
    
    cout << majorityElement(nums);

    return 0;
}