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

ListNode *mergeInBetween(ListNode *list1, ListNode *list2, int a, int b) {
    ListNode *head=list1;
    for(int i=0; i<a; i=i+1) {
        head=head->next;
    }
    ListNode *NodeAt_A=head;
    for(int i=a; i<b; i=i+1) {
        head=head->next;
    }
    ListNode *NodeAt_B=head;
    head=list1;
    while(head->next!=NodeAt_A) {
        head=head->next;
    }
    ListNode *startNode=head;
    while(head!=NodeAt_B) {
        head=head->next;
    }
    ListNode *nextNode=head->next;
    head=startNode;
    while(list2!=NULL) {
        head->next=list2;
        head=head->next;
        list2=list2->next;
    }
    head->next=nextNode;
    head=list1;
    return head;
}

int main() {
    ListNode *list1=new ListNode(0);
    list1->next=new ListNode(1);
    list1->next->next=new ListNode(2);
    list1->next->next->next=new ListNode(3);
    list1->next->next->next->next=new ListNode(4);
    list1->next->next->next->next->next=new ListNode(5);
    list1->next->next->next->next->next->next=new ListNode(6);
    
    ListNode *list2=new ListNode(1001);
    list2->next=new ListNode(1002);
    list2->next->next=new ListNode(1003);
    list2->next->next->next=new ListNode(1004);
    list2->next->next->next->next=new ListNode(1005);

    ListNode *head=mergeInBetween(list1, list2, 2, 5);
    while(head!=NULL) {
        cout << head->val << " ";
        head=head->next;
    }

    return 0;
}