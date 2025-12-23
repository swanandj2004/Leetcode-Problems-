#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

vector<int>intersection(vector<int>nums1, vector<int>nums2) {
    unordered_set<int>set;
    vector<int>v;
    for(int i=0; i<nums1.size(); i=i+1) {
        for(int j=0; j<nums2.size(); j=j+1) {
            if(nums1.at(i)==nums2.at(j)) {
                set.insert(nums1.at(i));
            }
        }
    }
    for(int element : set) {
        v.push_back(element);
    }
    return v;
}

int main() {
    vector<int>nums1={4,9,5};
    vector<int>nums2={9,4,9,8,4};

    vector<int>i=intersection(nums1,nums2);
    for(int j=0; j<i.size(); j=j+1) {
        cout << i.at(j) << " ";
    }

    return 0;
}