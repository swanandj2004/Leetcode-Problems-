#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>&nums, int val) {
    vector<int>temp;
    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)!=val) {
            temp.push_back(nums.at(i));
        }
    }

    nums=temp;
    return temp.size();
}

int main() {
    vector<int>nums={0,1,2,2,3,0,4,2};

    cout << removeElement(nums,2);
    return 0;
}