#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int kthLargestElement(vector<int>&nums, int k) {
    sort(nums.begin(),nums.end());

    return nums.at(nums.size()-k);
}

int main() {
    vector<int>nums={3,2,3,1,2,4,5,5,6};

    cout << kthLargestElement(nums, 4);

    return 0;
}