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

ListNode *swapNodes(ListNode *head, int k) {
    if(head==NULL) {
        return NULL;
    } else if(head->next==NULL) {
        return head;
    }

    ListNode *firstNode=head;
    ListNode *startNode=NULL;
    ListNode *endNode=NULL;

    int len=0, track=0;
    while(head) {
        len=len+1;
        head=head->next;
    }

    head=firstNode;
    
    while(head) {
        track=track+1;
        if(track==k) {
            startNode=head;
        } else if(track==(len-k)+1) {
            endNode=head;
        }
        head=head->next;
    }

    head=firstNode;
    int temp=startNode->val;
    startNode->val=endNode->val;
    endNode->val=temp;

    return head;
}

int main() {
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);

    head=swapNodes(head, 2);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}