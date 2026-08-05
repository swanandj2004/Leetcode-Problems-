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

ListNode *removeElements(ListNode *head, int val) {
    if(head==NULL) {
        return NULL;
    }
    ListNode *current=NULL;
    ListNode *newHead=NULL;
    ListNode *first=head;
    while(head) {
        if(head->val!=val) {
            ListNode *newNode = new ListNode(head->val);
            if(newHead==NULL) {
                newHead=newNode;
            }
            if(current) {
                current->next=newNode;
            }
            current=newNode;
        }
        head=head->next;
    }
    return newHead;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(6);
    head->next->next->next=new ListNode(3);
    head->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next->next=new ListNode(6);

    head=removeElements(head, 6);
    return 0;
}