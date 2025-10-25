#include <iostream>
#include <vector>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
    ListNode(int v) {
        val=v;
        next=nullptr;
    }
};

ListNode *findCyclicNode(ListNode *head) {
    vector<ListNode*>v;
    while(head!=nullptr) {
        for(int i=0; i<v.size(); i=i+1) {
            if(v.at(i)==head)
                return v.at(i);
        }
        v.push_back(head);
        head=head->next;
    }
    return nullptr;
}

int main() {
    ListNode *first=new ListNode(1);
    first->next=new ListNode(2);
    first->next->next=new ListNode(3);
    first->next->next->next=new ListNode(4);
    first->next->next->next->next=first->next;
    ListNode *head=first;

    ListNode *cyclicnode=findCyclicNode(head);
    if(cyclicnode!=nullptr) {
        cout << "Cycle Starts at " << cyclicnode->val;
    } else {
        cout << "No Cycle Exists";
    }
    return 0;
}