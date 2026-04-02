#include <vector>
#include <iostream>
using namespace std;

int firstUniqueEven(vector<int>&nums) {
    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)%2!=0) {
            continue;
        }
        int count=0;
        for(int j=0; j<nums.size(); j=j+1) {
            if(nums.at(i)==nums.at(j)) {
                count=count+1;
            }
        }
        if(count==1) {
            return nums.at(i);
        }
    }

    return -1;
}

int main() {
    vector<int>nums={3,4,2,5,4,6};

    cout << firstUniqueEven(nums) << endl;

    return 0;
}