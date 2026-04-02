#include <string>
#include <vector>
#include <iostream>
using namespace std;

string kthDistinct(vector<string>&arr, int k) {
    vector<string>unique;
    for(int i=0; i<arr.size(); i=i+1) {
        int count=0;
        for(int j=0; j<arr.size(); j=j+1) {
            if(arr.at(i)==arr.at(j)) {
                count++;
            }
        }
        if(count==1) {
            unique.push_back(arr.at(i));
        }
    }
    if(unique.size()>=k) {
        return unique.at(k-1);
    }
    return "";
}

int main() {
    vector<string>arr={"d","b","c","b","c","a"};

    cout << kthDistinct(arr, 2);
    return 0;
}