#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool presentInNums1(int j, vector<int>nums1) {
    for(int i=0; i<nums1.size(); i=i+1) {
        if(nums1.at(i)==j) {
            return true;
        }
    }
    return false;
}

bool presentInNums2(int j, vector<int>nums2) {
    for(int i=0; i<nums2.size(); i=i+1) {
        if(nums2.at(i)==j) {
            return true;
        }
    }
    return false;
}

vector<vector<int>>findDifference(vector<int>&nums1, vector<int>&nums2) {
    unordered_set<int>set1;
    unordered_set<int>set2;
    vector<int>result1;
    vector<int>result2;
    for(int i=0; i<nums1.size(); i=i+1) {
        set1.insert(nums1.at(i));
    }
    for(int i=0; i<nums2.size(); i=i+1) {
        set2.insert(nums2.at(i));
    }
    for(int j : set1) {
        if(!presentInNums2(j,nums2)) {
            result1.push_back(j);
        }
    }
    for(int j : set2) {
        if(!presentInNums1(j,nums1)) {
            result2.push_back(j);
        }
    }
    return {result1,result2};
}

int main() {
    vector<int>nums1={1,2,3};
    vector<int>nums2={2,4,6};

    vector<vector<int>>result=findDifference(nums1,nums2);

    return 0;
}
