#include <vector>
#include <iostream>
using namespace std;

vector<int> twoSum_2(vector<int>&numbers, int target) {
    int left=0;
    int right=numbers.size()-1;
    while(left<right) {
        int sum=numbers.at(left)+numbers.at(right);
        if(sum==target) {
            return {left+1, right+1};
        }
        else if(sum<target) {
            left=left+1;
        }
        else {
            right=right-1;
        }
    }

    return { };
}

int main() {
    vector<int>numbers={2,7,11,15};

    vector<int>v=twoSum_2(numbers, 9);
    for(int i=0; i<v.size(); i=i+1) {
        cout << v.at(i) << " ";
    }

    return 0;
}