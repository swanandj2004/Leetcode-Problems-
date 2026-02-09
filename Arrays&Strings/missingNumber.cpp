#include <vector>
#include <iostream>
using namespace std;

int missingNumber(vector<int>&nums) {
    int expectedSum=0, actualSum=0;
    for(int i=0; i<nums.size()+1; i=i+1) {
        expectedSum+=i;
    }
    for(int i=0; i<nums.size(); i=i+1) {
        actualSum+=nums.at(i);
    }
    return (expectedSum-actualSum);
}

int main() {
    vector<int>nums={ 9, 6, 4, 2, 3, 5, 7, 0, 1 };

    cout << missingNumber(nums);
    return 0;
}