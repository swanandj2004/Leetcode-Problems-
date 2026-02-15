#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>&nums, int target) {
  for(int i=0; i<nums.size(); i++) {
    if(nums.at(i)==target) {
      return true;
    }
  }
  return false;
}

int insert(vector<int>&nums, int target) {
  int l=nums.size();
  if(target<nums.at(l-1 && target>nums.at(l-2))) {
    return (l-1);
  }
  else if(target>nums.at(l-1)) {
    return (l);
  }
  else {
    for(int i=0; i<l-1; i++) {
      if(target<nums.at(i)) {
        return i;
      }
    }
  }
}

int main() {
  vector<int>nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);
  int target=2;
  bool find=search(nums, target);
  if(find==false) {
    cout << insert(nums, target);
  }
  return 0;
}