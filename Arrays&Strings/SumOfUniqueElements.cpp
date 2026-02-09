#include <vector>
#include <iostream>
using namespace std;

int sumOfUnique(vector<int>&nums) {
    vector<int>unique;
    for(int i=0; i<nums.size(); i=i+1) {
        int count=0;
        for(int j=0; j<nums.size(); j=j+1) {
            if(nums.at(i)==nums.at(j)) {
                count++;
            }
        }
        if(count==1) {
            unique.push_back(nums.at(i));
        }
    }
    int sum=0;
    for(int i=0; i<unique.size(); i=i+1) {
        sum=sum+unique.at(i);
    }
    return sum;
}

int main() {
    vector<int>nums={1,2,3,2};

    cout << sumOfUnique(nums);
    return 0;
}