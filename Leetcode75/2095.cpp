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

ListNode *deleteMiddleNode(ListNode *head) {
    if(head->next==NULL) {
        return NULL;
    }
    int len=0, track=0;
    ListNode *firstNode=head;
    ListNode *previousNode=NULL;
    ListNode *nextNode=NULL;
    ListNode *middleNode=NULL;
    while(head) {
        len=len+1;
        head=head->next;
    }
    head=firstNode;
    while(head) {
        track=track+1;
        if(track==len/2 + 1) {
            middleNode=head;
        }
        head=head->next;
    }
    head=firstNode;
    while(head) {
        if(head->next==middleNode) {
            previousNode=head;
        }
        head=head->next;
    }
    nextNode=middleNode->next;
    if(previousNode) {
        previousNode->next=nextNode;
    }
    head=firstNode;
    return head;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
    head->next->next->next=new ListNode(7);
    head->next->next->next->next=new ListNode(1);
    head->next->next->next->next->next=new ListNode(2);
    head->next->next->next->next->next->next=new ListNode(6);

    head=deleteMiddleNode(head);

    return 0;
}