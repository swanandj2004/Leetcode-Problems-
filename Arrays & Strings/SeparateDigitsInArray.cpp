#include <stack>
#include <vector>
#include <iostream>
using namespace std;

void separate(int n, vector<int>&digits) {
    stack<int>st;
    while(n!=0) {
        st.push(n%10);
        n=n/10;
    }
    while(!st.empty()) {
        digits.push_back(st.top());
        st.pop();
    }
}

vector<int>separateDigits(vector<int>&nums) {
    vector<int>digits;
    for(int i=0; i<nums.size(); i=i+1) {
        separate(nums.at(i),digits);
    }

    return digits;
}

int main() {
    vector<int>nums={13,25,83,77};

    vector<int>digits=separateDigits(nums);
    for(int i=0; i<digits.size(); i=i+1) {
        cout << digits.at(i) << " ";
    }

    return 0;
}