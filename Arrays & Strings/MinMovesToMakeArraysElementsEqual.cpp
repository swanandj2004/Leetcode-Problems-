#include <vector>
#include <iostream>
using namespace std;

int minMoves(vector<int>&nums) {
    vector<int>diff;    
    int max=nums.at(0), moves=0;

    for(int i=0; i<nums.size(); i=i+1) {
        if(max<nums.at(i)) {
            max=nums.at(i);
        }
    }

    for(int j=0; j<nums.size(); j=j+1) {
        diff.push_back(max-nums.at(j));
    }

    for(int i=0; i<diff.size(); i=i+1) {
        moves=moves+diff.at(i);
    }

    return moves;
}

int main() {
    vector<int>nums={2, 3, 8, 4};

    cout << minMoves(nums);
    return 0;
}