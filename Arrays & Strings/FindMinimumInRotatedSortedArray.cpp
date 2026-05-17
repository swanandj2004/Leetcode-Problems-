#include <vector>
#include <iostream>
using namespace std;

int findMinimum(vector<int>&nums) {
    int left=0, right=nums.size()-1;
    while(left<right) {
        int mid=left+(right-left)/2;
        if(nums.at(mid)>nums.at(right)) {
            left=mid+1;
        }
        else if(nums.at(mid)<nums.at(right)) {
            right=mid;
        }
        else {
            right=right-1;
        }
    }
    return nums.at(left);
}

int main() {
    vector<int>nums={3,4,5,1,2};

    cout << findMinimum(nums) << endl;
    return  0;
}