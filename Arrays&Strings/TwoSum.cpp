#include <vector>
#include <iostream>
using namespace std;

void twosum(vector<int>nums, vector<int>& index, int target) {
  for(int i=0; i<nums.size(); i++) {
    for(int j=i+1; j<nums.size(); j++) {
      if(nums.at(i)+nums.at(j)==target) {
        index.push_back(i);
        index.push_back(j);
        break;
      }
    }
  }
}

int main() {
  vector<int>nums;
  vector<int>index;
  int target=9;
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(15);
  twosum(nums, index, target);
  for(int i=0; i<index.size(); i++) {
    cout << index.at(i) << " ";
  }

  return 0;
}
