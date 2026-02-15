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

ListNode *findIntersection(ListNode *head1, ListNode *head2) {
    if(!head1 && head2) {
        return NULL;
    } else if(!head2 && head1) {
        return NULL;
    } else if(!head1 && !head2) {
        return NULL;
    }
    
    ListNode *firstNode=head1;
    ListNode *secondNode=head2;
    int len1=0, len2=0;
    int dif;
    
    while(head1) {
        len1++;
        head1=head1->next;
    }
    while(head2) {
        len2++;
        head2=head2->next;
    }

    head1=firstNode;
    head2=secondNode;


    if(len1>len2) {
        dif=len1-len2;
    } else {
        dif=len2-len1;
    }

    if(len1>len2) {
        while(dif!=0) {
            head1=head1->next;
            dif--;
        }
    } else {
        while(dif!=0) {
            head2=head2->next;
            dif--;
        }
    }

    while(head1 && head2) {
        if(head1==head2) {
            return head1;
        } 
        head1=head1->next;
        head2=head2->next;
    }

    return NULL;
}

int main() {
    ListNode *head1=new ListNode(4);
    head1->next=new ListNode(1);
    head1->next->next=new ListNode(8);
    head1->next->next->next=new ListNode(4);
    head1->next->next->next->next=new ListNode(5);

    ListNode *head2=new ListNode(5);
    head2->next=new ListNode(6);
    head2->next->next=new ListNode(1);
    head2->next->next->next=head1->next->next;

    ListNode *intersectionNode=findIntersection(head1, head2);
    cout << intersectionNode->val << endl;

    return 0;
}