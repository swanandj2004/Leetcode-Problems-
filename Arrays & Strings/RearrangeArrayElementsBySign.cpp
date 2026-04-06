#include <vector>
#include <iostream>
using namespace std;

vector<int>rearrangeArray(vector<int>&nums) {
    vector<int>positive;
    vector<int>negative;
    vector<int>result;

    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)>0) {
            positive.push_back(nums.at(i));
        } else if(nums.at(i)<0) {
            negative.push_back(nums.at(i));
        }
    }

    for(int j=0; j<positive.size(); j=j+1) {
        result.push_back(positive.at(j));
        result.push_back(negative.at(j));
    }

    nums=result;
    return nums;
}

int main() {
    vector<int>nums={3,1,-2,-5,2,-4};

    nums=rearrangeArray(nums);
    for(int i=0; i<nums.size(); i=i+1) {
        cout << nums.at(i) << " ";
    }

    return 0;
}