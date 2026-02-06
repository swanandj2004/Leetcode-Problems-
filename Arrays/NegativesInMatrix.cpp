#include <vector>
#include <iostream>
using namespace std;

int countNegatives(vector<vector<int>>&grid) {  
    int n=0;
    for(int i=0; i<grid.size(); i=i+1) {
        for(int j=0; j<grid.at(i).size(); j=j+1) {
            if(grid.at(i).at(j)<0) {
                n++;
            }
        }
    }
    return n;
}

int main() {
    vector<vector<int>>grid={
        {4,3,2,-1},
        {3,2,1,-1},
        {1,1,-1,-2},
        {-1,-1,-2,-3}
    };

    cout << countNegatives(grid);
    return 0;
}