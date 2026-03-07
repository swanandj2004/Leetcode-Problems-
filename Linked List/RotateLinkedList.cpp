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

ListNode *rotateLinkedList(ListNode *head, int k) {
    if(head==NULL) {
        return NULL;
    } else if(head->next==NULL) {
        return head;
    }

    int len=0;
    ListNode *firstNode=head;
    ListNode *lastNode=NULL;
    while(head) {
        len=len+1;
        if(head->next==NULL) {
            lastNode=head;
        }
        head=head->next;
    }

    k=k%len;
    head=firstNode;

    for(int i=0; i<k; i=i+1) {
        ListNode *previousOfLast=NULL;
        while(head) {
            if(head->next==lastNode) {
                previousOfLast=head;
            }
            head=head->next;
        }
        
        previousOfLast->next=NULL;
        lastNode->next=firstNode;
        firstNode=lastNode;
        lastNode=previousOfLast;
        head=firstNode;
    }

    return head;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head=rotateLinkedList(head, 2);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}