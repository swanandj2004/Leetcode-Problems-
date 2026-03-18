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

int calSum(ListNode *&head) {
    int sum=0;
    while(head->val!=0) {
        sum=sum+head->val;
        head=head->next;
    }
    if(head->next!=NULL) {
        head=head->next;
    }

    return sum;
}

ListNode *mergeNodes(ListNode *head) {
    if(head==NULL) {
        return NULL;
    } if(head->next==NULL) {
        return head;
    }

    ListNode *firstNode=head;
    int count=0;
    while(head) {
        if(head->val==0) {
            count=count+1;
        }
        head=head->next;
    }

    head=firstNode;
    head=head->next;

    ListNode *startNode=NULL;
    ListNode *current=NULL;

    for(int i=0; i<count-1; i=i+1) {
        if(head==NULL || head->next==NULL) {
            break;
        }
        int sum=calSum(head);
        ListNode *newNode=new ListNode(sum);
        if(i==0) {
            startNode=newNode;
        }
        if(current!=NULL) {
            current->next=newNode;
        }
        current=newNode;
    }

    return startNode;
}

int main() {
    ListNode *head=new ListNode(0);
    head->next=new ListNode(3);
    head->next->next=new ListNode(1);
    head->next->next->next=new ListNode(0);
    head->next->next->next->next=new ListNode(4);
    head->next->next->next->next->next=new ListNode(5);
    head->next->next->next->next->next->next=new ListNode(2);
    head->next->next->next->next->next->next->next=new ListNode(0);

    head=mergeNodes(head);
    while(head) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}