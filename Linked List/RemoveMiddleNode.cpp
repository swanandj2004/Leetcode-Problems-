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

ListNode *removeMiddleNode(ListNode *first) {
    int l=0, track=0;
    ListNode *head=first;
    while(head!=NULL) {
        l++;
        head=head->next;
    }
    if(l==1)
        return NULL;
    head=first;
    while(head!=NULL) {
        track++;
        if(track==l/2) {
            ListNode *previous=head;
            head=head->next;
            ListNode *nextNode=head->next;
            head->next=NULL;
            previous->next=NULL;
            previous->next=nextNode;
            break;
        }
        head=head->next;
    }
    head=first;
    return head;
}

int main() {
    ListNode *first=new ListNode(1);
    first->next=new ListNode(3);
    first->next->next=new ListNode(4);
    first->next->next->next=new ListNode(7);
    first->next->next->next->next=new ListNode(1);
    first->next->next->next->next->next=new ListNode(2);
    first->next->next->next->next->next->next=new ListNode(6);

    ListNode *newhead=removeMiddleNode(first);
    while(newhead!=NULL) {
        cout << newhead->val << " ";
        newhead=newhead->next;
    }
    return 0;
}