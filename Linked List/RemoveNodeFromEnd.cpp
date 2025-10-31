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

ListNode *removeNode(ListNode *head, ListNode *first, int n) { 
    int track=1;
    ListNode *current=head->next;
    ListNode *previous=NULL;
    head->next=NULL;
    while(current!=NULL) {
        ListNode *nextNode=current->next;
        current->next=NULL;
        current->next=head;
        head=current;
        current=nextNode;
    }
    if(n==1) {
        ListNode *nextNode=head->next;
        head->next=NULL;
        head=nextNode;
    } else {
        ListNode *last=head;
        ListNode *previous=head;
        head=head->next;
        while(head!=NULL) {
            track++;
            if(track==n) {
                ListNode *nextNode=head->next;
                head->next=NULL;
                previous->next=NULL;
                previous->next=nextNode;
                break;
            }
            previous=head;
            head=head->next;
        }
        head=last;
    }
    if(head==NULL)
        return head;
    else 
        current=head->next;
        head->next=NULL;
        while(current!=NULL) {
            ListNode *nextNode=current->next;
            current->next=NULL;
            current->next=head;
            head=current;
            current=nextNode;
        }
    return head;
}

int main() {
    int n=2;
    ListNode *first=new ListNode(1);
    first->next=new ListNode(2);
    first->next->next=new ListNode(3);
    first->next->next->next=new ListNode(4);
    first->next->next->next->next=new ListNode(5);
    ListNode *head=first;
    
    ListNode *newhead=removeNode(head, first, n);
    while(newhead!=NULL) {
        cout << newhead->val << " ";
        newhead=newhead->next;
    }
    return 0;
}