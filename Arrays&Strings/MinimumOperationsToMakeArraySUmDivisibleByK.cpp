#include <iostream>
#include <vector>
using namespace std;

int minOperations(vector<int>&nums, int k) {
    int sum=0;

    for(int i=0; i<nums.size(); i=i+1) {
        sum=sum+nums.at(i);
    }
    if(sum%k==0) {
        return 0;
    }

    int ops=0;
    while(sum%k==0) {
        ops=ops+1;
        sum=sum-1;
    }

    return ops;
}

int main() {
    vector<int>nums={3,9,7};

    cout << minOperations(nums, 5) << endl;

    return 0;
}