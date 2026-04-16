#include <queue>
#include <iostream>
using namespace std;

int findWinner(int n, int k) {
    queue<int>q;

    for(int i=1; i<n+1; i=i+1) {
        q.push(i);
    }

    while(q.size()>1) {
        for(int j=0; j<k-1; j=j+1) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    return q.front();
}

int main() {
    int n=5, k=2;

    cout << findWinner(n, k);

    return 0;
}