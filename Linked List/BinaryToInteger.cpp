#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int v) {
        val=v;
        next=NULL;
    }
};

int getDecimalValue(ListNode *first) {
    vector<int>bits;
    ListNode *head=first;
    while(head!=NULL) {
        bits.push_back(head->val);
        head=head->next;
    }
    int position=0, num=0;
    for(int i=bits.size()-1; i>-1; i=i-1) {
        num=num+(pow(2,position)*bits.at(i));
        position++;
    }
    return num;
}

int main() {
    ListNode *first=new ListNode(1);
    first->next=new ListNode(0);
    first->next->next=new ListNode(1);

    cout << getDecimalValue(first);

    return 0;
}