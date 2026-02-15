#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>&nums) {
    int result=0; 
    for(int i=0; i<nums.size(); i=i+1) {
        result=result^nums.at(i);
    }
    return result;
}

int main() {
    vector<int>nums={ 4, 1, 2, 1, 2 };

    cout << singleNumber(nums);
    return 0;
}