#include <vector>
#include <iostream>
using namespace std;

void calScoreForEven(vector<int>nums, int index, vector<int>&score) {
    int count=0;
    for(int j=index+1; j<nums.size(); j=j+1) {
        if(nums.at(j)%2!=0) {
            count=count+1;
        }
    }
    score.push_back(count);
}

void calScoreForOdd(vector<int>nums, int index, vector<int>&score) {
    int count=0;
    for(int j=index+1; j<nums.size(); j=j+1) {
        if(nums.at(j)%2==0) {
            count=count+1;
        }
    }
    score.push_back(count);
}

vector<int> countIndices(vector<int>nums) {
    vector<int>score;

    for(int i=0; i<nums.size(); i=i+1) {
        if(nums.at(i)%2==0) {
            calScoreForEven(nums, i, score);
        } else if(nums.at(i)%2!=0) {
            calScoreForOdd(nums, i, score);
        }
    }
}

int main() {
    vector<int>nums={1,2,3,4};

    vector<int>score=countIndices(nums);
    for(int i=0; i<score.size(); i=i+1) {
        cout << score.at(i) << " ";
    }

    return 0;
}