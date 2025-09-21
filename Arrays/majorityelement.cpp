#include <vector>
#include <iostream>
using namespace std;

int majorityElement(vector<int>&nums) {
    for(int i=0; i<nums.size(); i++) {
        int current=nums.at(i), count=0;
        for(int j=0; j<nums.size(); j++) {
            if(nums.at(j)==current) {
                count++;
            }
        }
        if(count>(nums.size()/2)) {
            return current;
        }
    }
}

int main() {
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);  
    
    cout << majorityElement(nums);

    return 0;
}