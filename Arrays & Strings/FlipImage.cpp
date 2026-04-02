#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int>reverse(vector<int>v) {
    stack<int>st;

    for(int i=0; i<v.size(); i=i+1) {
        st.push(v.at(i));
    }

    int j=0;
    while(!st.empty()) {
        v.at(j)=st.top();
        st.pop();
        j=j+1;
    }

    return v;
}

vector<vector<int>>flipImage(vector<vector<int>>&image) {
    for(int i=0; i<image.size(); i=i+1) {
        image.at(i)=reverse(image.at(i));
    }

    for(int i=0; i<image.size(); i=i+1) {
        for(int j=0; j<image.at(i).size(); j=j+1) {
            if(image.at(i).at(j)==1) {
                image.at(i).at(j)=0;
            } else if(image.at(i).at(j)==0) {
                image.at(i).at(j)=1;
            }
        }
    }

    return image;
}

int main() {
    vector<vector<int>>image={
        {1,1,0,0},
        {1,0,0,1},
        {0,1,1,1},
        {1,0,1,0}
    };

    image=flipImage(image);
    for(int i=0; i<image.size(); i=i+1) {
        for(int j=0; j<image.at(i).size(); j=j+1) {
            cout << image.at(i).at(j) << " ";
        }
        cout << endl;
    }

    return 0;
}