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

ListNode *oddEvenList(ListNode *head) {
    if(head==NULL) {
        return NULL;
    }

    ListNode *firstNode=head;
    ListNode *oddNode=head;
    ListNode *evenNode=head->next;
    ListNode *secondNode=head->next;

    while(evenNode && evenNode->next) {
        oddNode->next=evenNode->next;
        oddNode=oddNode->next;
        evenNode->next=oddNode->next;
        evenNode=evenNode->next;
    }

    oddNode->next=secondNode;

    return head;
}

int main() {
    ListNode *head=new ListNode(2);
    head->next=new ListNode(1);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(5);
    head->next->next->next->next=new ListNode(6);
    head->next->next->next->next->next=new ListNode(7);

    head=oddEvenList(head);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}