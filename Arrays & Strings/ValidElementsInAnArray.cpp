#include <vector>
#include <iostream>
using namespace std;

bool checkLeftElements(vector<int>nums, int index){
    for(int j=0; j<index; j=j+1) {
        if(nums.at(index)<=nums.at(j)) {
            return false;
        }
    }

    return true;
}

bool checkRightElements(vector<int>nums, int index) {
    for(int j=index+1; j<nums.size(); j=j+1) {
        if(nums.at(index)<=nums.at(j)) {
            return false;
        }
    }

    return true;
}

vector<int>validElements(vector<int>&nums) {
    vector<int>valid_elements;

    if(nums.size()<=2) {
        for(int i=0; i<nums.size(); i=i+1) {
            valid_elements.push_back(nums.at(i));
        }
        return valid_elements;
    }

    int n=nums.size();
    valid_elements.push_back(nums.at(0));
    for(int i=1; i<n-1; i=i+1) {
        if(checkLeftElements(nums,i) || checkRightElements(nums,i)) {
            valid_elements.push_back(nums.at(i));
        }
    }
    valid_elements.push_back(nums.at(n-1));

    return valid_elements;
}

int main() {
    vector<int>nums={1,2,4,2,3,2};

    vector<int>valid_elements=validElements(nums);
    for(int i=0; i<valid_elements.size(); i=i+1) {
        cout << valid_elements.at(i) << " ";
    }

    return 0;
}