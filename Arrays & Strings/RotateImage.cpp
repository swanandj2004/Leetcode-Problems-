#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>>rotateMatrix(vector<vector<int>>&matrix) {
    for(int i=0; i<matrix.size(); i=i+1) {
        for(int j=i+1; j<matrix.size(); j=j+1) {
            swap(matrix.at(i).at(j),matrix.at(j).at(i));
        }
    }

    for(int i=0; i<matrix.size(); i=i+1) {
        reverse(matrix.at(i).begin(),matrix.at(i).end());
    }

    return matrix;
}

int main() {
    vector<vector<int>>matrix={
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };

    matrix=rotateMatrix(matrix);
    for(int i=0; i<matrix.size(); i=i+1) {
        for(int j=0; j<matrix.at(i).size(); j=j+1) {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}