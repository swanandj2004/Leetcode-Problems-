#include <string>
#include <iostream>
using namespace std;

int jewelsAndStones(string &jewels, string &stones) {
    int count=0;

    for(int i=0; i<stones.length(); i=i+1) {
        for(int j=0; j<jewels.length(); j=j+1) {
            if(stones.at(i)==jewels.at(j)) {
                count=count+1;
            }
        }
    }

    return count;
}

int main() {
    string jewels="aA";
    string stones="aAAbbbb";

    cout << jewelsAndStones(jewels, stones);
    return 0;
}