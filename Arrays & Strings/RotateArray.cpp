#include <vector>
#include <iostream>
using namespace std;

vector<int>rotateArray(vector<int>&nums, int k) {
    if(nums.size()==1) {
        return nums;
    }

    k=k%nums.size();

    vector<int>temp(nums.size());
    for(int i=0; i<nums.size(); i=i+1) {
        temp.at((i+k)%nums.size())=nums.at(i);
    }

    return temp;
}

int main() {
    vector<int>nums={1,2,3,4,5,6,7};

    nums=rotateArray(nums, 3);
    for(int i=0; i<nums.size(); i=i+1) {
        cout << nums.at(i) << " ";
    }

    return 0;
}