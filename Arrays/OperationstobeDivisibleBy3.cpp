#include <vector>
#include <iostream>
using namespace std;

int minimumOperations(vector<int>&nums) {
    int divisible=0;
    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)%3==0) {
            divisible++;
        }
    }
    if(divisible==nums.size())
        return 0;
    
    int ops=0; 
    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)%3==0){
            continue;
        } else {
            if((nums.at(i)-1)%3==0) {
                ops++;
            } else if((nums.at(i)+1)%3==0){
                ops++;
            }
        }
    }
    return ops;
}

int main() {
    vector<int>nums={1, 2, 3, 4};
    
    cout << minimumOperations(nums);
    return 0;
}