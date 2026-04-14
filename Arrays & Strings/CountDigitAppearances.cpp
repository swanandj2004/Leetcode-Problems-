#include <vector>
#include <iostream>
using namespace std;

int countAppearances(vector<int>&nums, int digit) {
    int count=0;

    for(int i=0; i<nums.size(); i=i+1) {
        int n=nums.at(i);
        while(n!=0) {
            int rem=n%10;
            if(rem==digit) {
                count=count+1;
            }
            n=n/10;
        }
    }

    return count;
}

int main() {
    vector<int>nums={12,54,32,22};

    cout << countAppearances(nums, 2);
    return 0;
}