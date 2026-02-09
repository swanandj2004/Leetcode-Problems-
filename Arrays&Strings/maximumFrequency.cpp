#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int>nums={ 1, 2, 2, 3, 1, 4 };
    vector<int>frequency;
    for(int i=0; i<nums.size(); i++) {
        int current=nums.at(i), count=0;
        for(int j=0; j<nums.size(); j++) {
            if(current==nums.at(j)) {
                count++;
            }
        }
        frequency.push_back(count);
    }
    int maximum=frequency.at(0), frequency_of_maximum=0;
    for(int i=0; i<frequency.size(); i++) {
        if(maximum<frequency.at(i)) {
            maximum=frequency.at(i);
        }
    }
    for(int i=0; i<frequency.size(); i++) {
        if(maximum==frequency.at(i)) {
            frequency_of_maximum++;
        }
    }
    cout << frequency_of_maximum << endl;
    return 0;
}