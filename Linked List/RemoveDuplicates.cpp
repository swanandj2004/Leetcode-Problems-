#include <iostream>
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

ListNode *removeDuplicates(ListNode *head, ListNode *first) {
    while(head!=nullptr && head->next!=nullptr) {
        if(head->val==head->next->val) {
            head->next=head->next->next;
        } else {
            head=head->next;
        }
    }
    head=first;
    return head;
}

int main() {
    ListNode *first=new ListNode(1);
    first->next=new ListNode(1);
    first->next->next=new ListNode(2);
    first->next->next->next=new ListNode(3);
    first->next->next->next->next=new ListNode(3);
    ListNode *head=first;

    ListNode *newhead=removeDuplicates(head, first);
    while(newhead!=nullptr) {
        cout << newhead->val << " ";
        newhead=newhead->next;
    }
    return 0;
}