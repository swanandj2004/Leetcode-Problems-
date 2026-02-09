#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int RepeatedNTimes(vector<int>&nums) {
    int n=floor(nums.size()/2);
    int result;
    for(int i=0; i<nums.size(); i=i+1) {
        int f=0;
        for(int j=0; j<nums.size(); j=j+1) {
            if(nums.at(i)==nums.at(j)) {
                f++;
            }
        }
        if(f==n) {
            result=nums.at(i);
            break;
        }
    }
    return result;
}

int main() {
    vector<int>nums={5,1,5,2,5,3,5,4};

    cout << RepeatedNTimes(nums);
    return 0;
}