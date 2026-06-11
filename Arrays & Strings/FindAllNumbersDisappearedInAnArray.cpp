#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int>findDisappearedNumbers(vector<int>&nums) {
    vector<int>missing={ };
    unordered_map<int,int>map;
    for(int i=0; i<nums.size(); i=i+1) {
        map[nums.at(i)]=map[nums.at(i)]+1;
    }
    for(int j=1; j<nums.size()+1; j=j+1) {
        if(!map.count(j)) {
            missing.push_back(j);
        }
    }

    return missing;
}

int main() {
    vector<int>nums={4,3,2,7,8,2,3,1};

    vector<int>missing=findDisappearedNumbers(nums);
    for(int i=0; i<missing.size(); i=i+1) {
        cout << missing.at(i) << " ";
    }

    return 0;
}