#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int timeRequiredtoBuy(vector<int>&tickets, int k) {
    queue<int>q;
    queue<int>index;
    int time=0;
    for(int i=0; i<tickets.size(); i=i+1) {
        q.push(tickets.at(i));
        index.push(i);
    }
    while(!q.empty()) {
        time++;
        if(index.front()==k) {
            if(q.front()==1) {
                q.pop();
                break; 
            } else if(q.front()>1) {
                q.push(q.front()-1);
                index.push(index.front());
                q.pop();
                index.pop();
            }
        } else if(index.front()!=k) {
            if(q.front()==1) {
                q.pop();
                index.pop();
            } else if(q.front()>1) {
                q.push(q.front()-1);
                index.push(index.front());
                q.pop();
                index.pop();
            }
        }
    }
    return time;
}

int main() {
    vector<int>tickets={5,1,1,1};
    int k=0;
    
    cout << timeRequiredtoBuy(tickets,k);
    return 0;
}