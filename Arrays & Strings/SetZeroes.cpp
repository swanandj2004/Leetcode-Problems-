#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>>setZeroes(vector<vector<int>>&matrix) {
    vector<vector<int>>position;
    for(int i=0; i<matrix.size(); i=i+1) {
        for(int j=0; j<matrix.at(i).size(); j=j+1) {
            if(matrix.at(i).at(j)==0) {
                position.push_back({i,j});
            }
        }
    }
    for(int i=0; i<position.size(); i=i+1) {
        int row=position.at(i).at(0);
        for(int j=0; j<matrix.at(row).size(); j=j+1) {
            matrix.at(row).at(j)=0;
        }
    }
    for(int i=0; i<position.size(); i=i+1) {
        int col=position.at(i).at(1);
        for(int j=0; j<matrix.size(); j=j+1) {
            matrix.at(j).at(col)=0;
        }
    }
    return matrix;
}

int main() {
    vector<vector<int>>matrix={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    matrix=setZeroes(matrix);
    for(int i=0; i<matrix.size(); i=i+1) {
        for(int j=0; j<matrix.at(i).size(); j=j+1) {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}