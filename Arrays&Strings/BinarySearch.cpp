#include <vector>
#include <iostream>
using namespace std;

int BinarySearch(vector<int>&nums, int target) {
    if(nums.size()==0) {
        return -1;
    }
    int start=0, end=nums.size()-1;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(nums.at(mid)==target) {
            return mid;
        } else if(target>nums.at(mid)) {
            start=mid+1;
        } else if(target<nums.at(mid)) {
            end=mid-1;
        }
    }
    return -1;
}

int main() {
    vector<int>nums={-1,0,3,5,9,12};

    cout << BinarySearch(nums, 9);
    return 0;
}