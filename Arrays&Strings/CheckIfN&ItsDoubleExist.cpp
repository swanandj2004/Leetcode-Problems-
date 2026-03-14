#include <vector>
#include <iostream>
using namespace std;

bool checkIfExist(vector<int>&arr) {
    for(int i=0; i<arr.size(); i=i+1) {
        for(int j=0; j<arr.size(); j=j+1) {
            if(i==j) {
                continue;
            } if(arr.at(i)==2*arr.at(j)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int>arr={10,2,5,3};

    cout << checkIfExist(arr);

    return 0;
}