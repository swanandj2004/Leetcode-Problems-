#include <vector>
#include <iostream>
using namespace std;

int scoreDifference(vector<int>&nums) {
    int player1=0;
    int player2=0;

    bool active=true; // Is player1 active ?
    for(int i=0; i<nums.size(); i=i+1) {

        if(nums.at(i)%2!=0 && (i+1)%6!=0) {
            if(active==true) {
                active=false;
            } 
            else if(active==false) {
                active=true;
            }
            if(active==true) {
                player1=player1+nums.at(i);
            } 
            else if(active==false) {
                player2=player2+nums.at(i);
            }
        }

        else if(nums.at(i)%2!=0 && (i+1)%6==0) {
            if(active==true) {
                active=true;
            } else if(active==false) {
                active=false;
            }
            if(active==true) {
                player1=player1+nums.at(i);
            }
            else if(active==false) {
                player2=player2+nums.at(i);
            }
        }

        else if(nums.at(i)%2==0 && (i+1)%6==0) {
            if(active==true) {
                active=false;
            }
            else if(active==false) {
                active=true;
            }
            if(active==true) {
                player1=player1+nums.at(i);
            }
            else if(active==false) {
                player2=player2+nums.at(i);
            }
        }

        else if(nums.at(i)%2==0 && (i+1)%6!=0) {
            if(active==true) {
                player1=player1+nums.at(i);
            } 
            else if(active==false) {
                player2=player2+nums.at(i);
            }
        }
    }

    return player1-player2;
}

int main() {
    vector<int>nums={2,4,2,1,2,1};

    cout << scoreDifference(nums);

    return 0;
}